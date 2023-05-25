package mapeditor;

import map.RegionLibrary;
import objects.ObjectLibrary;
import map.GroundLibrary;
import util.AssetLibrary;
import openfl.Assets;
import haxe.ds.IntMap;
import openfl.geom.Point;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.MouseEvent;
import openfl.geom.Matrix;
import openfl.geom.Rectangle;
import openfl.ui.Keyboard;
import util.Utils;

class MEMap extends Sprite {
	public static inline var NUM_SQUARES = 512;
	public static inline var SQUARE_SIZE = 16;
	public static inline var WIDTH = 640;
	public static inline var HEIGHT = 640;
	public static inline var MIN_ZOOM = 0.125 * 0.5;
	public static inline var MAX_ZOOM = 16;

	public var tileDict: IntMap<METile>;
	public var fullMap: BigBitmapData;

	public var regionMap: BitmapData;
	public var map: BitmapData;
	public var overlay: Shape;
	public var posT: IntPoint;
	public var zoom: Float = 1;
	public var invisibleTexture: BitmapData;
	public var replaceTexture: BitmapData;

	private var mouseRectAnchorT: IntPoint = null;
	private var mouseMoveAnchorT: IntPoint = null;
	private var mouseDown = false;
	private var editScreen: EditingScreen;

	public function new(editScreen: EditingScreen) {
		this.editScreen = editScreen;
		this.tileDict = new IntMap<METile>();
		this.fullMap = new BigBitmapData(NUM_SQUARES * SQUARE_SIZE, NUM_SQUARES * SQUARE_SIZE, true, 0);
		this.regionMap = new BitmapData(NUM_SQUARES, NUM_SQUARES, true, 0);
		this.map = new BitmapData(WIDTH, HEIGHT, true, 0);
		this.overlay = new Shape();
		super();
		graphics.beginBitmapFill(Assets.getBitmapData("assets/sheets/TransBG.png"), null, true);
		graphics.drawRect(0, 0, WIDTH, HEIGHT);
		addChild(new Bitmap(this.map));
		addChild(this.overlay);
		this.posT = new IntPoint(Std.int(NUM_SQUARES / 2 - this.sizeInTiles() / 2), Std.int(NUM_SQUARES / 2 - this.sizeInTiles() / 2));
		this.invisibleTexture = AssetLibrary.getImageFromSet("invisible", 0);
		this.replaceTexture = AssetLibrary.getImageFromSet("lofiObj3", 255);
		this.draw();
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public inline function getType(x: Int, y: Int, layer: Int) {
		return this.getTile(x, y)?.types[layer] ?? (layer == Layer.REGION ? 255 : 65535);
	}

	public function getTile(x: Int, y: Int) {
		return this.tileDict.get(x + y * NUM_SQUARES);
	}

	public function modifyTile(x: Int, y: Int, layer: Int, type: Int) {
		var tile = this.getOrCreateTile(x, y);
		if (tile.types[layer] == type)
			return;

		tile.types[layer] = type;
		this.drawTile(x, y, tile);
	}

	public function getObjectName(x: Int, y: Int) {
		var tile = this.getTile(x, y);
		if (tile == null)
			return null;

		return tile.objName;
	}

	public function modifyObjectName(x: Int, y: Int, objName: String) {
		var tile = this.getOrCreateTile(x, y);
		tile.objName = objName;
	}

	public function getAllTiles() {
		var tiles = new Array<IntPoint>();
		for (index in this.tileDict.keys())
			tiles.push(new IntPoint(index % NUM_SQUARES, Std.int(index / NUM_SQUARES)));
		return tiles;
	}

	public function setTile(x: Int, y: Int, tile: METile) {
		tile = tile.clone();
		this.tileDict.set(x + y * NUM_SQUARES, tile);
		this.drawTile(x, y, tile);
	}

	public function eraseTile(x: Int, y: Int) {
		this.clearTile(x, y);
		this.drawTile(x, y, null);
	}

	public function clear() {
		for (index in this.tileDict.keys())
			this.eraseTile(index % NUM_SQUARES, Std.int(index / NUM_SQUARES));
	}

	public function getTileBounds() {
		var minX: Float = NUM_SQUARES, minY: Float = NUM_SQUARES;
		var maxX = 0.0, maxY = 0.0;
		for (index => tile in this.tileDict.keyValueIterator())
			if (!tile.isEmpty()) {
				var x = index % NUM_SQUARES;
				var y = index / NUM_SQUARES;
				if (x < minX)
					minX = x;

				if (y < minY)
					minY = y;

				if (x + 1 > maxX)
					maxX = x + 1;

				if (y + 1 > maxY)
					maxY = y + 1;
			}

		if (minX > maxX)
			return null;

		return new Rectangle(minX, minY, maxX - minX, maxY - minY);
	}

	private function sizeInTiles() {
		return Math.max(WIDTH, HEIGHT) / (SQUARE_SIZE * this.zoom);
	}

	private function modifyZoom(mult: Float) {
		if (mult > 1 && this.zoom >= MAX_ZOOM || mult < 1 && this.zoom <= MIN_ZOOM)
			return;

		var tempMousePosT: IntPoint = this.mousePosT();
		this.zoom = this.zoom * mult;
		var newMousePosT: IntPoint = this.mousePosT();
		this.movePosT(tempMousePosT.x - newMousePosT.x, tempMousePosT.y - newMousePosT.y);
	}

	private function canMove() {
		return this.mouseRectAnchorT == null && this.mouseMoveAnchorT == null;
	}

	private function increaseZoom() {
		if (!this.canMove())
			return;

		this.modifyZoom(2);
		this.draw();
	}

	private function decreaseZoom() {
		if (!this.canMove())
			return;

		this.modifyZoom(0.5);
		this.draw();
	}

	private function moveLeft() {
		if (!this.canMove())
			return;

		this.movePosT(-1, 0);
		this.draw();
	}

	private function moveRight() {
		if (!this.canMove())
			return;

		this.movePosT(1, 0);
		this.draw();
	}

	private function moveUp() {
		if (!this.canMove())
			return;

		this.movePosT(0, -1);
		this.draw();
	}

	private function moveDown() {
		if (!this.canMove())
			return;

		this.movePosT(0, 1);
		this.draw();
	}

	private function movePosT(dX: Int, dY: Int) {
		this.posT.x = Std.int(Math.max(0, Math.min(NUM_SQUARES - WIDTH / (SQUARE_SIZE * this.zoom), this.posT.x + dX)));
		this.posT.y = Std.int(Math.max(0, Math.min(NUM_SQUARES - HEIGHT / (SQUARE_SIZE * this.zoom), this.posT.y + dY)));
	}

	private function mousePosT() {
		var mX = Math.max(0, Math.min(WIDTH - 1, mouseX));
		var mY = Math.max(0, Math.min(HEIGHT - 1, mouseY));
		return new IntPoint(Std.int(this.posT.x + mX / (SQUARE_SIZE * this.zoom)), Std.int(this.posT.y + mY / (SQUARE_SIZE * this.zoom)));
	}

	public function mouseRectT() {
		var mpT = this.mousePosT();
		if (this.mouseRectAnchorT == null)
			return new Rectangle(mpT.x, mpT.y, 1, 1);

		return new Rectangle(Math.min(mpT.x, this.mouseRectAnchorT.x), Math.min(mpT.y, this.mouseRectAnchorT.y),
			Math.abs(mpT.x - this.mouseRectAnchorT.x) + 1, Math.abs(mpT.y - this.mouseRectAnchorT.y) + 1);
	}

	private function posTToPosP(pT: IntPoint) {
		return new IntPoint(Std.int((pT.x - this.posT.x) * SQUARE_SIZE * this.zoom), Std.int((pT.y - this.posT.y) * SQUARE_SIZE * this.zoom));
	}

	private function sizeTToSizeP(sizeT: Int) {
		return sizeT * this.zoom * SQUARE_SIZE;
	}

	private function mouseRectP() {
		var rect = this.mouseRectT();
		var xyP = this.posTToPosP(new IntPoint(Std.int(rect.x), Std.int(rect.y)));
		rect.x = xyP.x;
		rect.y = xyP.y;
		rect.width = this.sizeTToSizeP(Std.int(rect.width)) - 1;
		rect.height = this.sizeTToSizeP(Std.int(rect.height)) - 1;
		return rect;
	}

	private function onAddedToStage(_: Event) {
		addEventListener(MouseEvent.MOUSE_WHEEL, this.onMouseWheel);
		addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		addEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
		addEventListener(MouseEvent.MOUSE_MOVE, this.onMouseMove);
		addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		stage.addEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
		stage.addEventListener(KeyboardEvent.KEY_UP, this.onKeyUp);
	}

	private function onRemovedFromStage(_: Event) {
		removeEventListener(MouseEvent.MOUSE_WHEEL, this.onMouseWheel);
		removeEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		removeEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
		removeEventListener(MouseEvent.MOUSE_MOVE, this.onMouseMove);
		removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		stage.removeEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
		stage.removeEventListener(KeyboardEvent.KEY_UP, this.onKeyUp);
	}

	private function onKeyDown(event: KeyboardEvent) {
		switch (event.keyCode) {
			case Keyboard.SHIFT:
				if (this.mouseRectAnchorT != null) {
					this.draw();
					return;
				}

				this.mouseRectAnchorT = this.mousePosT();
			case Keyboard.CONTROL:
				if (this.mouseMoveAnchorT != null) {
					this.draw();
					return;
				}

				this.mouseMoveAnchorT = this.mousePosT();
			case Keyboard.LEFT:
				this.moveLeft();
			case Keyboard.RIGHT:
				this.moveRight();
			case Keyboard.UP:
				this.moveUp();
			case Keyboard.DOWN:
				this.moveDown();
			case KeyCode.Minus:
				this.decreaseZoom();
			case KeyCode.Equal:
				this.increaseZoom();
		}

		this.draw();
	}

	private function onKeyUp(event: KeyboardEvent) {
		switch (event.keyCode) {
			case Keyboard.SHIFT:
				this.mouseRectAnchorT = null;
			case Keyboard.CONTROL:
				this.mouseMoveAnchorT = null;
		}

		this.draw();
	}

	private function onMouseWheel(event: MouseEvent) {
		if (event.delta > 0)
			this.increaseZoom();
		else if (event.delta < 0)
			this.decreaseZoom();
	}

	private function onMouseDown(_: MouseEvent) {
		var rectT = this.mouseRectT();
		var tilesT = new Array<IntPoint>();
		for (xT in Std.int(rectT.x)...Std.int(rectT.right))
			for (yT in Std.int(rectT.y)...Std.int(rectT.bottom))
				tilesT.push(new IntPoint(xT, yT));

		this.mouseDown = true;
		this.editScreen.editTiles(tilesT);
	}

	private function onMouseUp(_: MouseEvent) {
		var rectT = this.mouseRectT();
		var tilesT = new Array<IntPoint>();
		for (xT in Std.int(rectT.x)...Std.int(rectT.right))
			for (yT in Std.int(rectT.y)...Std.int(rectT.bottom))
				tilesT.push(new IntPoint(xT, yT));

		this.mouseDown = false;
		this.editScreen.editTiles(tilesT);
	}

	private function onEnterFrame(_: Event) {
		if (this.mouseDown)
			this.editScreen.editTiles([this.mousePosT()]);
	}

	private function onMouseMove(event: MouseEvent) {
		var mpT: IntPoint = null;
		if (!event.shiftKey)
			this.mouseRectAnchorT = null;
		else if (this.mouseRectAnchorT == null)
			this.mouseRectAnchorT = this.mousePosT();

		if (!event.ctrlKey)
			this.mouseMoveAnchorT = null;
		else if (this.mouseMoveAnchorT == null)
			this.mouseMoveAnchorT = this.mousePosT();

		if (this.mouseMoveAnchorT != null) {
			mpT = this.mousePosT();
			this.movePosT(this.mouseMoveAnchorT.x - mpT.x, this.mouseMoveAnchorT.y - mpT.y);
			this.draw();
		} else
			this.drawOverlay();
	}

	private function getOrCreateTile(x: Int, y: Int): METile {
		var index = x + y * NUM_SQUARES;
		var tile = this.tileDict.get(index);
		if (tile != null)
			return tile;

		this.tileDict.set(index, tile = new METile());
		return tile;
	}

	private function clearTile(x: Int, y: Int) {
		this.tileDict.remove(x + y * NUM_SQUARES);
	}

	private function drawTile(x: Int, y: Int, tile: METile) {
		var goundBD: BitmapData = null;
		var objBD: BitmapData = null;
		var regionColor = 0;
		var rect = new Rectangle(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
		this.fullMap.erase(rect);
		this.regionMap.setPixel32(x, y, 0);
		if (tile == null)
			return;

		if (tile.types[Layer.GROUND] != 65535) {
			goundBD = GroundLibrary.getBitmapData(tile.types[Layer.GROUND]);
			this.fullMap.copyTo(goundBD, goundBD.rect, rect);
		}

		if (tile.types[Layer.OBJECT] != 65535) {
			objBD = ObjectLibrary.getTextureFromType(tile.types[Layer.OBJECT]);
			if (objBD == null || objBD == this.invisibleTexture)
				this.fullMap.copyTo(this.replaceTexture, this.replaceTexture.rect, rect);
			else
				this.fullMap.copyTo(objBD, objBD.rect, rect);
		}

		if (tile.types[Layer.REGION] != 255) {
			regionColor = RegionLibrary.getColor(tile.types[Layer.REGION]);
			this.regionMap.setPixel32(x, y, 1593835520 | regionColor);
		}
	}

	private function drawOverlay() {
		var mrP = this.mouseRectP();
		var g = this.overlay.graphics;
		g.clear();
		g.lineStyle(1, 16777215);
		g.beginFill(16777215, 0.1);
		g.drawRect(mrP.x, mrP.y, mrP.width, mrP.height);
		g.endFill();
		g.lineStyle();
	}

	public function draw() {
		var m: Matrix = null;
		var ss = 0.0;
		var temp: BitmapData = null;
		var s = Math.max(WIDTH, HEIGHT) / this.zoom;
		this.map.fillRect(this.map.rect, 0);
		this.fullMap.copyFrom(new Rectangle(this.posT.x * SQUARE_SIZE, this.posT.y * SQUARE_SIZE, s, s), this.map, this.map.rect);
		m = new Matrix();
		m.identity();
		ss = SQUARE_SIZE * this.zoom;
		if (this.zoom > 2) {
			temp = new BitmapData(Std.int(Math.max(WIDTH, HEIGHT) / ss), Std.int(Math.max(WIDTH, HEIGHT) / ss));
			temp.copyPixels(this.regionMap, new Rectangle(this.posT.x, this.posT.y, s, s), new Point(0, 0));
			m.scale(ss, ss);
			this.map.draw(temp, m);
		} else {
			m.translate(-this.posT.x, -this.posT.y);
			m.scale(ss, ss);
			this.map.draw(this.regionMap, m, null, null, this.map.rect);
		}

		this.drawOverlay();
	}
}
