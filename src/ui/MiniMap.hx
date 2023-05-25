package ui;

import openfl.Assets;
import openfl.display.Bitmap;
import map.Camera;
import network.NetworkHandler;
import haxe.ds.IntMap;
import map.GroundLibrary;
import map.Map;
import objects.GameObject;
import objects.Player;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.geom.ColorTransform;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import ui.IconButton;
import ui.menu.PlayerGroupMenu;
import ui.options.Options;
import ui.tooltip.PlayerGroupToolTip;
import util.AssetLibrary;
import util.Utils;
import util.PointUtil;
import util.Settings;

class MiniMap extends Sprite {
	public static inline var MOUSE_DIST_SQ = 5 * 5;
	public static inline var HUB_BUTTON = "HUB_BUTTON";
	public static inline var OPTIONS_BUTTON = "OPTIONS_BUTTON";
	private static var objectTypeColorDict: IntMap<Int> = new IntMap<Int>();

	public var map: Map;
	public var mapWidth = 0;
	public var mapHeight = 0;
	public var zoomIndex = 0;
	public var windowRect: Rectangle;
	public var maxWH: Point;
	public var miniMapData: BitmapData;
	public var zoomLevels: Array<Float>;
	public var blueArrow: BitmapData;
	public var groundLayer: Shape;
	public var characterLayer: Shape;

	private var optionsButton: IconButton;
	private var hubButton: IconButton;
	private var zoomButtons: MiniMapZoomButtons;
	private var decor: Bitmap;
	private var isMouseOver = false;
	private var tooltip: PlayerGroupToolTip = null;
	private var menu: PlayerGroupMenu = null;
	private var mapMatrix: Matrix;
	private var arrowMatrix: Matrix;
	private var players: Array<Player>;
	private var tempPoint: Point;

	public static function gameObjectToColor(go: GameObject) {
		var objectType = go.objectType;
		if (!(objectTypeColorDict.exists(objectType)))
			objectTypeColorDict.set(objectType, go.getColor());

		return objectTypeColorDict.get(objectType);
	}

	private static function areSamePlayers(players0: Array<Player>, players1: Array<Player>) {
		var count = players0.length;
		if (count != players1.length)
			return false;

		for (i in 0...count)
			if (players0[i] != players1[i])
				return false;

		return true;
	}

	public function new(width: Int, height: Int) {
		super();

		this.zoomLevels = new Array<Float>();
		this.mapMatrix = new Matrix();
		this.arrowMatrix = new Matrix();
		this.players = new Array<Player>();
		this.tempPoint = new Point();
		this.mapWidth = width;
		this.mapHeight = height;
		this.makeVisualLayers();
		this.addMouseListeners();
		this.update();
	}

	public function update() {
		this.map = Global.gameSprite.map;
		this.zoomLevels.resize(0);
		this.makeViewModel();
		this.createButton();
	}

	private static function onGotoHub() {
		NetworkHandler.escape();
	}

	private static function onGotoOptions() {
		Global.gameSprite.inputHandler.clearInput();
		var options = new Options(Global.gameSprite);
		options.x = (Main.stageWidth - 800) / 2;
		options.y = (Main.stageHeight - 600) / 2;
		Global.gameSprite.addChild(options);
	}

	public function onMiniMapZoom(direction: String) {
		if (direction == "in")
			this.zoomIn();
		else if (direction == "out")
			this.zoomOut();
	}

	private function onUpdateHUD(_: Player) {
		this.draw();
	}

	public function dispose() {
		if (this.miniMapData != null) {
			this.miniMapData.dispose();
			this.miniMapData = null;
		}

		if (this.blueArrow != null) {
			this.blueArrow.dispose();
			this.blueArrow = null;
		}

		if (this.decor != null) {
			this.decor.bitmapData?.dispose();
			this.decor = null;
		}

		if (this.tooltip != null) {
			if (this.tooltip.parent != null)
				this.tooltip.parent.removeChild(this.tooltip);
			this.tooltip = null;
		}

		if (this.menu != null) {
			if (this.menu.parent != null)
				this.menu.parent.removeChild(this.menu);
			this.menu = null;
		}

		if (this.zoomButtons != null)
			this.zoomButtons.zoom.off(this.onZoomChanged);
	}

	public function setGroundTile(x: Int, y: Int, tileType: Int) {
		var color = GroundLibrary.getColor(tileType);
		this.miniMapData.setPixel(x, y, color);
	}

	public function setGameObjectTile(x: Int, y: Int, go: GameObject) {
		var color = gameObjectToColor(go);
		if (color != 0)
			this.miniMapData.setPixel(x, y, color);
	}

	public static function lineSegmentIntersectXY(rect: Rectangle, p1x: Float, p1y: Float, p2x: Float, p2y: Float, result: Point) {
		var slope: Float;
		var c: Float;
		var y: Float;
		var x: Float;
		if (p2x <= rect.x) {
			slope = (p2y - p1y) / (p2x - p1x);
			c = p1y - p1x * slope;
			y = slope * rect.x + c;
			if (y >= rect.y && y <= rect.y + rect.height) {
				result.x = rect.x;
				result.y = y;
				return true;
			}
		} else if (p2x >= rect.x + rect.width) {
			slope = (p2y - p1y) / (p2x - p1x);
			c = p1y - p1x * slope;
			y = slope * (rect.x + rect.width) + c;
			if (y >= rect.y && y <= rect.y + rect.height) {
				result.x = rect.x + rect.width;
				result.y = y;
				return true;
			}
		}
		if (p2y <= rect.y) {
			slope = (p2x - p1x) / (p2y - p1y);
			c = p1x - p1y * slope;
			x = slope * rect.y + c;
			if (x >= rect.x && x <= rect.x + rect.width) {
				result.x = x;
				result.y = rect.y;
				return true;
			}
		} else if (p2y >= rect.y + rect.height) {
			slope = (p2x - p1x) / (p2y - p1y);
			c = p1x - p1y * slope;
			x = slope * (rect.y + rect.height) + c;
			if (x >= rect.x && x <= rect.x + rect.width) {
				result.x = x;
				result.y = rect.y + rect.height;
				return true;
			}
		}
		return false;
	}

	public inline function draw() {
		var g: Graphics = null;
		var fillColor = 0;
		var mmx = 0.0;
		var mmy = 0.0;
		var dx = 0.0;
		var dy = 0.0;
		var distSq = 0.0;
		this.groundLayer.graphics.clear();
		this.characterLayer.graphics.clear();
		this.players.resize(0);
		var focus = Global.gameSprite.map.player;
		if (focus == null)
			return;

		var zoom = this.zoomLevels[this.zoomIndex];
		this.mapMatrix.identity();
		this.mapMatrix.translate(-focus.mapX, -focus.mapY);
		this.mapMatrix.scale(zoom, zoom);
		var upLeft = this.mapMatrix.transformPoint(new Point(0, 0));
		var bottomRight = this.mapMatrix.transformPoint(this.maxWH);
		var tx = 0.0;
		if (upLeft.x > this.windowRect.left)
			tx = this.windowRect.left - upLeft.x;
		else if (bottomRight.x < this.windowRect.right)
			tx = this.windowRect.right - bottomRight.x;

		var ty = 0.0;
		if (upLeft.y > this.windowRect.top)
			ty = this.windowRect.top - upLeft.y;
		else if (bottomRight.y < this.windowRect.bottom)
			ty = this.windowRect.bottom - bottomRight.y;

		this.mapMatrix.translate(tx, ty);
		g = this.groundLayer.graphics;
		g.beginBitmapFill(this.miniMapData, this.mapMatrix, false);
		g.drawRect(-188/2, -188/2, 188, 188);
		g.endFill();
		g = this.characterLayer.graphics;
		var mX = mouseX;
		var mY = mouseY;
		this.players.splice(this.players.length, 0);
		for (go in this.map.gameObjects) {
			if (go.props.isPlayer) {
				var player: Player = cast go;
				if (player != focus) {
					fillColor = player.isFellowGuild ? 0x00FF00 : 0xFFFF00;

					mmx = this.mapMatrix.a * player.mapX + this.mapMatrix.c * player.mapY + this.mapMatrix.tx;
					mmy = this.mapMatrix.b * player.mapX + this.mapMatrix.d * player.mapY + this.mapMatrix.ty;
					if (mmx <= -this.mapWidth / 2 || mmx >= this.mapWidth / 2 || mmy <= -this.mapHeight / 2 || mmy >= this.mapHeight / 2) {
						lineSegmentIntersectXY(this.windowRect, 0, 0, mmx, mmy, this.tempPoint);
						mmx = this.tempPoint.x;
						mmy = this.tempPoint.y;
					}

					if (this.isMouseOver && (this.menu == null || this.menu.parent == null)) {
						dx = mX - mmx;
						dy = mY - mmy;
						distSq = dx * dx + dy * dy;
						if (distSq < MOUSE_DIST_SQ)
							this.players.push(player);
					}

					g.beginFill(fillColor);
					g.drawRect(mmx - 2, mmy - 2, 4, 4);
					g.endFill();
				}
			} else if (!go.props.noMiniMap) {
				if (go.objClass == "Portal")
					fillColor = 0x0000FF;
				else if (go.props.isEnemy)
					fillColor = 0xFF0000;
				else
					continue;

				mmx = this.mapMatrix.a * go.mapX + this.mapMatrix.c * go.mapY + this.mapMatrix.tx;
				mmy = this.mapMatrix.b * go.mapX + this.mapMatrix.d * go.mapY + this.mapMatrix.ty;
				if (mmx <= -this.mapWidth / 2 || mmx >= this.mapWidth / 2 || mmy <= -this.mapHeight / 2 || mmy >= this.mapHeight / 2)
					continue;

				g.beginFill(fillColor);
				g.drawRect(mmx - 2, mmy - 2, 4, 4);
				g.endFill();
			}
		}

		if (this.players.length != 0) {
			if (this.tooltip == null) {
				this.tooltip = new PlayerGroupToolTip(this.players);
				stage.addChild(this.tooltip);
			} else if (!areSamePlayers(this.tooltip.players, this.players))
				this.tooltip.setPlayers(this.players);
		} else if (this.tooltip != null) {
			if (this.tooltip.parent != null)
				this.tooltip.parent.removeChild(this.tooltip);
			this.tooltip = null;
		}

		var px = focus.mapX, py = focus.mapY;
		var ppx = this.mapMatrix.a * px + this.mapMatrix.c * py + this.mapMatrix.tx,
			ppy = this.mapMatrix.b * px + this.mapMatrix.d * py + this.mapMatrix.ty;
		this.arrowMatrix.identity();
		this.arrowMatrix.translate(-4, -5);
		this.arrowMatrix.scale(8 / this.blueArrow.width, 32 / this.blueArrow.height);
		this.arrowMatrix.rotate(Camera.angleRad);
		this.arrowMatrix.translate(ppx, ppy);
		g.beginBitmapFill(this.blueArrow, this.arrowMatrix, false);
		g.drawRect(ppx - 16, ppy - 16, 32, 32);
		g.endFill();
	}

	public function zoomIn() {
		this.zoomIndex = this.zoomButtons.setZoomLevel(this.zoomIndex - 1);
	}

	public function zoomOut() {
		this.zoomIndex = this.zoomButtons.setZoomLevel(this.zoomIndex + 1);
	}

	private function createButton() {
		if (contains(this.optionsButton))
			removeChild(this.optionsButton);

		if (contains(this.hubButton))
			removeChild(this.hubButton);

		this.hubButton = new IconButton(AssetLibrary.getImageFromSet("misc16", 31), "Hub", "escapeToHub");
		this.hubButton.addEventListener(MouseEvent.CLICK, this.onHubClick);
		this.hubButton.x = -22;
		this.hubButton.y = 100;
		addChild(this.hubButton);

		this.optionsButton = new IconButton(AssetLibrary.getImageFromSet("misc16", 15), "Options", "options");
		this.optionsButton.addEventListener(MouseEvent.CLICK, this.onOptionsClick);
		this.optionsButton.x = 24;
		this.optionsButton.y = 100;
		addChild(this.optionsButton);
	}

	private function makeViewModel() {
		this.windowRect = new Rectangle(-this.mapWidth / 2, -this.mapHeight / 2, this.mapWidth, this.mapHeight);
		this.maxWH = new Point(this.map.mapWidth, this.map.mapHeight);
		this.miniMapData = new BitmapData(Std.int(this.maxWH.x), Std.int(this.maxWH.y), false, 0);
		var minZoom = Math.max(this.mapWidth / this.maxWH.x, this.mapHeight / this.maxWH.y);
		var z = 4.0;
		while (z > minZoom) {
			this.zoomLevels.push(z);
			z /= 2;
		}

		this.zoomLevels.push(minZoom);
		if (this.zoomButtons != null)
			this.zoomButtons.setZoomLevels(this.zoomLevels.length);
		this.zoomIndex = this.zoomButtons.setZoomLevel(Std.int(Math.min(this.zoomLevels.length, this.zoomIndex)));
	}

	private function makeVisualLayers() {
		this.blueArrow = AssetLibrary.getImageFromSet("misc", 26).clone();
		this.blueArrow.colorTransform(this.blueArrow.rect, new ColorTransform(0, 0, 1));
		
		this.groundLayer = new Shape();
		addChild(this.groundLayer);
		this.characterLayer = new Shape();
		addChild(this.characterLayer);

		this.decor = new Bitmap(Assets.getBitmapData("assets/ui/minimap.png"));
		this.decor.x = -188 / 2;
		this.decor.y = -188 / 2;
		addChild(this.decor);

		this.zoomButtons = new MiniMapZoomButtons();
		this.zoomButtons.x = 68;
		this.zoomButtons.y = -87;
		this.zoomButtons.zoom.on(this.onZoomChanged);
		this.zoomButtons.setZoomLevels(this.zoomLevels.length);
		addChild(this.zoomButtons);
	}

	private function addMouseListeners() {
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		addEventListener(MouseEvent.CLICK, this.onMapClick);
	}

	private function onZoomChanged(zoomLevel: Int) {
		this.zoomIndex = zoomLevel;
	}

	private function addMenu() {
		this.menu = new PlayerGroupMenu(this.map, this.tooltip.players);
		this.menu.x = this.tooltip.x + 12;
		this.menu.y = this.tooltip.y;
		stage.addChild(this.menu);
	}

	private function onHubClick(event: MouseEvent) {
		NetworkHandler.escape();
	}

	private function onOptionsClick(event: MouseEvent) {
		Global.gameSprite.inputHandler.clearInput();
		var options = new Options(Global.gameSprite);
		options.x = (Main.stageWidth - 800) / 2;
		options.y = (Main.stageHeight - 600) / 2;
		Global.gameSprite.addChild(options);
	}

	private function onMouseOver(event: MouseEvent) {
		this.isMouseOver = true;
	}

	private function onMouseOut(event: MouseEvent) {
		this.isMouseOver = false;
	}

	private function onMapClick(event: MouseEvent) {
		if (this.tooltip == null || this.tooltip.parent == null || this.tooltip.players == null || this.tooltip.players.length == 0)
			return;

		if (this.menu != null) {
			if (this.menu.parent != null)
				this.menu.parent.removeChild(this.menu);
			this.menu = null;
		}

		this.addMenu();

		if (this.tooltip != null) {
			if (this.tooltip.parent != null)
				this.tooltip.parent.removeChild(this.tooltip);
			this.tooltip = null;
		}
	}
}
