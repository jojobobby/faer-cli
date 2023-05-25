package map;

import objects.animation.Animations;
import engine.GLTextureData;
import util.Utils.KeyCodeUtil;
import util.Settings;
import openfl.filters.GlowFilter;
import openfl.geom.Point;
import openfl.geom.Matrix;
import openfl.display.BitmapData;
import ui.SimpleText;
import openfl.Assets;
import util.Utils.MathUtil;
import engine.TextureFactory;
import util.BinPacker.Rect;
import util.AnimatedChar;
import util.Utils.RenderUtils;
import objects.Player;
import cpp.Stdlib;
import lime.graphics.opengl.GL;
import lime.graphics.opengl.GLVertexArrayObject;
import cpp.RawPointer;
import lime.utils.Int32Array;
import util.ConditionEffect;
import objects.GameObject;
import util.NativeTypes;
import haxe.Exception;
import haxe.ds.IntMap;
import haxe.ds.Vector;
import lime.graphics.opengl.GLBuffer;
import lime.graphics.opengl.GLFramebuffer;
import lime.graphics.opengl.GLProgram;
import lime.graphics.opengl.GLTexture;
import lime.utils.Float32Array;
import lime.utils.Int16Array;
import objects.Projectile;
import openfl.display3D.Context3D;
import util.AssetLibrary;
import util.Utils.MathUtil;

using util.Utils.ArrayUtils;

@:structInit
class RenderDataSingle {
	public var texture: GLTexture;
	public var cosX: Float32;
	public var sinX: Float32;
	public var sinY: Float32;
	public var cosY: Float32;
	public var x: Float32;
	public var y: Float32;
	public var texelW: Float32;
	public var texelH: Float32;
	public var alpha: Float32 = 1.0;
}

@:unreflective
class Map {
	private static inline var TILE_UPDATE_MS = 100; // tick rate
	private static inline var BUFFER_UPDATE_MS = 500;
	private static inline var MAX_VISIBLE_SQUARES = 729;

	public static var emptyBarU: Float32 = 0.0;
	public static var emptyBarV: Float32 = 0.0;
	public static var emptyBarW: Float32 = 0.0;
	public static var emptyBarH: Float32 = 0.0;
	public static var hpBarU: Float32 = 0.0;
	public static var hpBarV: Float32 = 0.0;
	public static var hpBarW: Float32 = 0.0;
	public static var hpBarH: Float32 = 0.0;
	public static var mpBarU: Float32 = 0.0;
	public static var mpBarV: Float32 = 0.0;
	public static var mpBarW: Float32 = 0.0;
	public static var mpBarH: Float32 = 0.0;
	public static var oxygenBarU: Float32 = 0.0;
	public static var oxygenBarV: Float32 = 0.0;
	public static var oxygenBarW: Float32 = 0.0;
	public static var oxygenBarH: Float32 = 0.0;
	public static var shieldBarU: Float32 = 0.0;
	public static var shieldBarV: Float32 = 0.0;
	public static var shieldBarW: Float32 = 0.0;
	public static var shieldBarH: Float32 = 0.0;
	public static var leftMaskU: Float32 = 0.0;
	public static var leftMaskV: Float32 = 0.0;
	public static var topMaskU: Float32 = 0.0;
	public static var topMaskV: Float32 = 0.0;
	public static var rightMaskU: Float32 = 0.0;
	public static var rightMaskV: Float32 = 0.0;
	public static var bottomMaskU: Float32 = 0.0;
	public static var bottomMaskV: Float32 = 0.0;

	public var mapWidth: UInt16 = 0;
	public var mapHeight: UInt16 = 0;
	public var mapName = "";
	public var back = 0;
	public var allowPlayerTeleport = false;
	public var showDisplays = false;
	public var squares: Vector<Square>;
	public var gameObjectsLen: Int32 = 0;
	public var gameObjects: Array<GameObject>;
	public var rdSingle: Array<RenderDataSingle>;
	public var player: Player = null;
	public var quest: Quest = null;
	public var lastWidth: Int16 = -1;
	public var lastHeight: Int16 = -1;
	public var c3d: Context3D;
	public var lastTileUpdate: Int32 = -1;

	private var lastBufferUpdate: Int32 = -1;
	private var visSquares: Vector<Square>;
	private var visSquareLen: UInt16 = 0;

	public var defaultProgram: GLProgram;
	public var lowGlowProgram: GLProgram;
	public var medGlowProgram: GLProgram;
	public var highGlowProgram: GLProgram;
	public var veryHighGlowProgram: GLProgram;
	public var singleProgram: GLProgram;
	public var groundProgram: GLProgram;

	public var singleVBO: GLBuffer;
	public var singleIBO: GLBuffer;
	public var groundVAO: GLVertexArrayObject;
	public var groundVBO: GLBuffer;
	public var groundVBOLen: Int32 = 0;
	public var groundIBO: GLBuffer;
	public var groundIBOLen: Int32 = 0;
	public var objVAO: GLVertexArrayObject;
	public var objVBO: GLBuffer;
	public var objVBOLen: Int32 = 0;
	public var objIBO: GLBuffer;
	public var objIBOLen: Int32 = 0;

	private var i: Int32 = 0;
	private var vIdx: Int32 = 0;
	private var iIdx: Int32 = 0;

	private var backBuffer: GLFramebuffer;
	private var frontBuffer: GLFramebuffer;
	private var backBufferTexture: GLTexture;
	private var frontBufferTexture: GLTexture;

	public var speechBalloons: IntMap<SpeechBalloon>;
	public var statusTexts: Array<CharacterStatusText>;

	private var normalBalloonTex: BitmapData;
	private var tellBalloonTex: BitmapData;
	private var guildBalloonTex: BitmapData;
	private var enemyBalloonTex: BitmapData;
	private var partyBalloonTex: BitmapData;
	private var adminBalloonTex: BitmapData;

	public function new() {
		this.gameObjects = [];
		this.rdSingle = [];
		this.quest = new Quest(this);
		this.visSquares = new Vector<Square>(MAX_VISIBLE_SQUARES);
		this.speechBalloons = new IntMap<SpeechBalloon>();
		this.statusTexts = [];
	}

	@:nonVirtual public function addSpeechBalloon(sb: SpeechBalloon) {
		this.speechBalloons.set(sb.go.objectId, sb);
	}

	@:nonVirtual public function addStatusText(text: CharacterStatusText) {
		this.statusTexts.push(text);
	}

	@:nonVirtual public function setProps(width: Int, height: Int, name: String, back: Int, allowPlayerTeleport: Bool, showDisplays: Bool) {
		this.mapWidth = width;
		this.mapHeight = height;
		this.squares = new Vector<Square>(this.mapWidth * this.mapHeight);
		this.mapName = name;
		this.back = back;
		this.allowPlayerTeleport = allowPlayerTeleport;
		this.showDisplays = showDisplays;
	}

	@:nonVirtual public function initialize() {
		this.normalBalloonTex = AssetLibrary.getImageFromSet("speechBalloons", 0x0);
		this.tellBalloonTex = AssetLibrary.getImageFromSet("speechBalloons", 0x1);
		this.guildBalloonTex = AssetLibrary.getImageFromSet("speechBalloons", 0x2);
		this.enemyBalloonTex = AssetLibrary.getImageFromSet("speechBalloons", 0x3);
		this.partyBalloonTex = AssetLibrary.getImageFromSet("speechBalloons", 0x4);
		this.adminBalloonTex = AssetLibrary.getImageFromSet("speechBalloons", 0x5);

		var leftMaskRect = AssetLibrary.getRectFromSet("ground", 0x6b);
		leftMaskU = (leftMaskRect.x + Main.PADDING) / Main.ATLAS_WIDTH;
		leftMaskV = (leftMaskRect.y + Main.PADDING) / Main.ATLAS_HEIGHT;

		var topMaskRect = AssetLibrary.getRectFromSet("ground", 0x6c);
		topMaskU = (topMaskRect.x + Main.PADDING) / Main.ATLAS_WIDTH;
		topMaskV = (topMaskRect.y + Main.PADDING) / Main.ATLAS_HEIGHT;

		var rightMaskRect = AssetLibrary.getRectFromSet("ground", 0x6d);
		rightMaskU = (rightMaskRect.x + Main.PADDING) / Main.ATLAS_WIDTH;
		rightMaskV = (rightMaskRect.y + Main.PADDING) / Main.ATLAS_HEIGHT;

		var bottomMaskRect = AssetLibrary.getRectFromSet("ground", 0x6e);
		bottomMaskU = (bottomMaskRect.x + Main.PADDING) / Main.ATLAS_WIDTH;
		bottomMaskV = (bottomMaskRect.y + Main.PADDING) / Main.ATLAS_HEIGHT;

		var hpBarRect = AssetLibrary.getRectFromSet("bars", 0x0);
		hpBarU = hpBarRect.x / Main.ATLAS_WIDTH;
		hpBarV = hpBarRect.y / Main.ATLAS_HEIGHT;
		hpBarW = hpBarRect.width;
		hpBarH = hpBarRect.height;

		var mpBarRect = AssetLibrary.getRectFromSet("bars", 0x1);
		mpBarU = mpBarRect.x / Main.ATLAS_WIDTH;
		mpBarV = mpBarRect.y / Main.ATLAS_HEIGHT;
		mpBarW = mpBarRect.width;
		mpBarH = mpBarRect.height;

		var oxygenBarRect = AssetLibrary.getRectFromSet("bars", 0x2);
		oxygenBarU = oxygenBarRect.x / Main.ATLAS_WIDTH;
		oxygenBarV = oxygenBarRect.y / Main.ATLAS_HEIGHT;
		oxygenBarW = oxygenBarRect.width;
		oxygenBarH = oxygenBarRect.height;

		var shieldBarRect = AssetLibrary.getRectFromSet("bars", 0x3);
		shieldBarU = shieldBarRect.x / Main.ATLAS_WIDTH;
		shieldBarV = shieldBarRect.y / Main.ATLAS_HEIGHT;
		shieldBarW = hpBarRect.width;
		shieldBarH = hpBarRect.height;

		var emptyBarRect = AssetLibrary.getRectFromSet("bars", 0x4);
		emptyBarU = emptyBarRect.x / Main.ATLAS_WIDTH;
		emptyBarV = emptyBarRect.y / Main.ATLAS_HEIGHT;
		emptyBarW = hpBarRect.width;
		emptyBarH = hpBarRect.height;

		this.defaultProgram = RenderUtils.compileShaders(Assets.getText("assets/shaders/base.vert"), Assets.getText("assets/shaders/base.frag"));
		this.lowGlowProgram = RenderUtils.compileShaders(Assets.getText("assets/shaders/base.vert"), Assets.getText("assets/shaders/baseLowGlow.frag"));
		this.medGlowProgram = RenderUtils.compileShaders(Assets.getText("assets/shaders/base.vert"), Assets.getText("assets/shaders/baseMedGlow.frag"));
		this.highGlowProgram = RenderUtils.compileShaders(Assets.getText("assets/shaders/base.vert"), Assets.getText("assets/shaders/baseHighGlow.frag"));
		this.veryHighGlowProgram = RenderUtils.compileShaders(Assets.getText("assets/shaders/base.vert"), Assets.getText("assets/shaders/baseVHighGlow.frag"));
		this.singleProgram = RenderUtils.compileShaders(Assets.getText("assets/shaders/baseSingle.vert"), Assets.getText("assets/shaders/baseSingle.frag"));
		this.groundProgram = RenderUtils.compileShaders(Assets.getText("assets/shaders/ground.vert"), Assets.getText("assets/shaders/ground.frag"));

		this.singleVBO = RenderUtils.createVertexBuffer(new Float32Array([
			 0.5, -0.5, 0, 0,
			-0.5, -0.5, 1, 0,
			 0.5,  0.5, 0, 1,
			-0.5,  0.5, 1, 1
		]));
		this.singleIBO = RenderUtils.createIndexBuffer(new Int16Array([0, 1, 2, 2, 1, 3]));

		this.groundVAO = GL.createVertexArray();
		this.groundIBO = GL.createBuffer();
		this.groundVBO = GL.createBuffer();

		GL.bindBuffer(GL.ARRAY_BUFFER, this.groundVBO);
		GL.bufferData(GL.ARRAY_BUFFER, 0, new Float32Array([]), GL.DYNAMIC_DRAW);
		GL.enableVertexAttribArray(0);
		GL.vertexAttribPointer(0, 4, GL.FLOAT, false, 56, 0);
		GL.enableVertexAttribArray(1);
		GL.vertexAttribPointer(1, 2, GL.FLOAT, false, 56, 16);
		GL.enableVertexAttribArray(2);
		GL.vertexAttribPointer(2, 2, GL.FLOAT, false, 56, 24);
		GL.enableVertexAttribArray(3);
		GL.vertexAttribPointer(3, 2, GL.FLOAT, false, 56, 32);
		GL.enableVertexAttribArray(4);
		GL.vertexAttribPointer(4, 2, GL.FLOAT, false, 56, 40);
		GL.enableVertexAttribArray(5);
		GL.vertexAttribPointer(5, 2, GL.FLOAT, false, 56, 48);
		GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.groundIBO);
		GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, 0, new Int32Array([]), GL.DYNAMIC_DRAW);

		this.objVAO = GL.createVertexArray();
		this.objIBO = GL.createBuffer();
		this.objVBO = GL.createBuffer();

		GL.bindBuffer(GL.ARRAY_BUFFER, this.objVBO);
		GL.bufferData(GL.ARRAY_BUFFER, 0, new Float32Array([]), GL.DYNAMIC_DRAW);
		GL.enableVertexAttribArray(0);
		GL.vertexAttribPointer(0, 4, GL.FLOAT, false, 40, 0);
		GL.enableVertexAttribArray(1);
		GL.vertexAttribPointer(1, 2, GL.FLOAT, false, 40, 16);
		GL.enableVertexAttribArray(2);
		GL.vertexAttribPointer(2, 2, GL.FLOAT, false, 40, 24);
		GL.enableVertexAttribArray(3);
		GL.vertexAttribPointer(3, 1, GL.FLOAT, false, 40, 32);
		GL.enableVertexAttribArray(4);
		GL.vertexAttribPointer(4, 1, GL.FLOAT, false, 40, 36);
		GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.objIBO);
		GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, 0, new Int32Array([]), GL.DYNAMIC_DRAW);

		this.c3d = Main.primaryStage3D.context3D;
		this.c3d.configureBackBuffer(Main.stageWidth, Main.stageHeight, 0, true);

		this.lastWidth = Main.stageWidth;
		this.lastHeight = Main.stageHeight;
		RenderUtils.clipSpaceScaleX = 2 / Main.stageWidth;
		RenderUtils.clipSpaceScaleY = 2 / Main.stageHeight;
	}

	@:nonVirtual public function dispose() {
		this.squares = null;

		if (this.gameObjects != null)
			for (obj in this.gameObjects)
				obj.dispose();
		this.gameObjects = null;

		this.player = null;
		this.quest = null;
		TextureFactory.disposeTextures();
	}

	@:nonVirtual public function update(time: Int32, dt: Int16) {
		var i = 0;
		var goRemove = new Array<GameObject>();
		while (i < this.gameObjectsLen) {
			var go = this.gameObjects.unsafeGet(i);
			if (!go.update(time, dt))
				goRemove.push(go);
			i++;
		}
		
		i = 0;

		while (i < goRemove.length) {
			var go = goRemove[i];
			go.removeFromMap();
			this.gameObjects.remove(go);
			this.gameObjectsLen--;
			i++;
		}
	}

	@:nonVirtual private inline function validPos(x: UInt16, y: UInt16) {
		return !(x < 0 || x >= this.mapWidth || y < 0 || y >= this.mapHeight);
	}

	@:nonVirtual private inline function updateBlends(x: UInt16, y: UInt16, square: Square) {
		if (validPos(x - 1, y)) {
			var leftSq = this.squares[x - 1 + y * this.mapWidth];
			if (leftSq != null) {
				if (leftSq.props.blendPriority > square.props.blendPriority) {
					square.leftBlendU = leftSq.baseU;
					square.leftBlendV = leftSq.baseV;
				} else if (leftSq.props.blendPriority < square.props.blendPriority) {
					leftSq.rightBlendU = square.baseU;
					leftSq.rightBlendV = square.baseV;
				} else {
					square.leftBlendU = square.leftBlendV = -1.0;
					leftSq.rightBlendU = leftSq.rightBlendV = -1.0;
				}
			}
		}

		if (validPos(x, y - 1)) {
			var topSq = this.squares[x + (y - 1) * this.mapWidth];
			if (topSq != null) {
				if (topSq.props.blendPriority > square.props.blendPriority) {
					square.topBlendU = topSq.baseU;
					square.topBlendV = topSq.baseV;
				} else if (topSq.props.blendPriority < square.props.blendPriority) {
					topSq.bottomBlendU = square.baseU;
					topSq.bottomBlendV = square.baseV;
				} else {
					square.topBlendU = square.topBlendV = -1.0;
					topSq.bottomBlendU = topSq.bottomBlendV = -1.0;
				}
			}
		}

		if (validPos(x + 1, y)) {
			var rightSq = this.squares[x + 1 + y * this.mapWidth];
			if (rightSq != null) {
				if (rightSq.props.blendPriority > square.props.blendPriority) {
					square.rightBlendU = rightSq.baseU;
					square.rightBlendV = rightSq.baseV;
				} else if (rightSq.props.blendPriority < square.props.blendPriority) {
					rightSq.leftBlendU = square.baseU;
					rightSq.leftBlendV = square.baseV;
				} else {
					square.rightBlendU = square.rightBlendV = -1.0;
					rightSq.leftBlendU = rightSq.leftBlendV = -1.0;
				}
			}
		}

		if (validPos(x, y + 1)) {
			var bottomSq = this.squares[x + (y + 1) * this.mapWidth];
			if (bottomSq != null) {
				if (bottomSq.props.blendPriority > square.props.blendPriority) {
					square.bottomBlendU = bottomSq.baseU;
					square.bottomBlendV = bottomSq.baseV;
				} else if (bottomSq.props.blendPriority < square.props.blendPriority) {
					bottomSq.topBlendU = square.baseU;
					bottomSq.topBlendV = square.baseV;
				} else {
					square.bottomBlendU = square.bottomBlendV = -1.0;
					bottomSq.topBlendU = bottomSq.topBlendV = -1.0;
				}
			}
		}
	}

	@:nonVirtual public function setGroundTile(x: UInt16, y: UInt16, tileType: UInt16) {
		if (!validPos(x, y))
			return;

		var idx: Int32 = x + y * this.mapWidth;
		var square = this.squares[idx];
		if (square == null) {
			square = new Square(x + 0.5, y + 0.5);
			this.squares[idx] = square;
		}

		square.tileType = tileType;
		square.props = GroundLibrary.propsLibrary.get(tileType);
		var texData = GroundLibrary.typeToTextureData.get(tileType).getTextureData();
		square.baseU = texData.uValue;
		square.baseV = texData.vValue;
		var animationsData = GroundLibrary.typeToAnimationsData.get(tileType);
		if (animationsData != null)
			square.animations = new Animations(animationsData);
		square.sink = square.props != null && square.props.sink ? 0.6 : 0;

		updateBlends(x, y, square);
	}

	@:nonVirtual public function addGameObject(go: GameObject, posX: Float32, posY: Float32) {
		go.mapX = posX;
		go.mapY = posY;

		if (!go.addTo(this, go.mapX, go.mapY))
			return;

		this.gameObjects.push(go);
		this.gameObjectsLen++;
	}

	@:nonVirtual public function removeObj(objectId: Int32) {
		var i = 0;
		while (i < this.gameObjectsLen) {
			var go = this.gameObjects.unsafeGet(i);
			if (go.objectId == objectId) {
				go.removeFromMap();
				this.gameObjects.splice(i, 1);
				this.gameObjectsLen--;
				return;
			}
			i++;
		}
	}

	@:nonVirtual public function getGameObject(objectId: Int32) {
		var i = 0;
		while (i < this.gameObjectsLen) {
			var go = this.gameObjects.unsafeGet(i);
			if (go.objectId == objectId)
				return go;
			i++;
		}

		return null;
	}

	@:nonVirtual public function removeGameObject(objectId: Int32) {
		var i = 0;
		while (i < this.gameObjectsLen) {
			var go = this.gameObjects.unsafeGet(i);
			if (go.objectId == objectId) {
				go.removeFromMap();
				this.gameObjects.splice(i, 1);
				this.gameObjectsLen--;
				return;
			}
			i++;
		}
	}

	@:nonVirtual public function lookupSquare(x: UInt16, y: UInt16) {
		return x < 0
			|| x >= this.mapWidth
			|| y < 0
			|| y >= this.mapHeight
			|| player != null
			&& (player.mapX < 0 || player.mapY < 0) ? null : this.squares[x + y * this.mapWidth];
	}

	@:nonVirtual public function forceLookupSquare(x: UInt16, y: UInt16) {
		if (x < 0 || x >= this.mapWidth || y < 0 || y >= this.mapHeight || player != null && (player.mapX < 0 || player.mapY < 0))
			return null;

		var idx = x + y * this.mapWidth;
		var square = this.squares[idx];
		if (square == null) {
			square = new Square(x + 0.5, y + 0.5);
			this.squares[idx] = square;
		}

		return square;
	}

	@:nonVirtual private final #if !tracing inline #end function drawSquares(time: Int32) {
		final xScaledCos = Camera.xScaledCos;
		final yScaledCos = Camera.yScaledCos;
		final xScaledSin = Camera.xScaledSin;
		final yScaledSin = Camera.yScaledSin;

		while (this.i < this.visSquareLen) {
			final square = this.visSquares[this.i];

			if (square.animations != null) {
				var rect = square.animations.getTexture(time);
				if (rect != null) {
					square.baseU = (rect.x + 2) / Main.ATLAS_WIDTH;
					square.baseV = (rect.y + 2) / Main.ATLAS_WIDTH;
					updateBlends(square.x, square.y, square);
				}			
			}

			square.clipX = (square.middleX * Camera.cos + square.middleY * Camera.sin + Camera.csX) * RenderUtils.clipSpaceScaleX;
			square.clipY = (square.middleX * -Camera.sin + square.middleY * Camera.cos + Camera.csY) * RenderUtils.clipSpaceScaleY;

			setF32ValueAt(this.vIdx, -xScaledCos - xScaledSin + square.clipX);
			setF32ValueAt(this.vIdx + 1, yScaledSin - yScaledCos + square.clipY);
			setF32ValueAt(this.vIdx + 2, 0);
			setF32ValueAt(this.vIdx + 3, 0);

			setF32ValueAt(this.vIdx + 4, square.leftBlendU);
			setF32ValueAt(this.vIdx + 5, square.leftBlendV);
			setF32ValueAt(this.vIdx + 6, square.topBlendU);
			setF32ValueAt(this.vIdx + 7, square.topBlendV);

			setF32ValueAt(this.vIdx + 8, square.rightBlendU);
			setF32ValueAt(this.vIdx + 9, square.rightBlendV);
			setF32ValueAt(this.vIdx + 10, square.bottomBlendU);
			setF32ValueAt(this.vIdx + 11, square.bottomBlendV);

			setF32ValueAt(this.vIdx + 12, square.baseU);
			setF32ValueAt(this.vIdx + 13, square.baseV);

			setF32ValueAt(this.vIdx + 14, xScaledCos - xScaledSin + square.clipX);
			setF32ValueAt(this.vIdx + 15, -yScaledSin - yScaledCos + square.clipY);
			setF32ValueAt(this.vIdx + 16, 8 / Main.ATLAS_WIDTH);
			setF32ValueAt(this.vIdx + 17, 0);

			setF32ValueAt(this.vIdx + 18, square.leftBlendU);
			setF32ValueAt(this.vIdx + 19, square.leftBlendV);
			setF32ValueAt(this.vIdx + 20, square.topBlendU);
			setF32ValueAt(this.vIdx + 21, square.topBlendV);

			setF32ValueAt(this.vIdx + 22, square.rightBlendU);
			setF32ValueAt(this.vIdx + 23, square.rightBlendV);
			setF32ValueAt(this.vIdx + 24, square.bottomBlendU);
			setF32ValueAt(this.vIdx + 25, square.bottomBlendV);

			setF32ValueAt(this.vIdx + 26, square.baseU);
			setF32ValueAt(this.vIdx + 27, square.baseV);

			setF32ValueAt(this.vIdx + 28, -xScaledCos + xScaledSin + square.clipX);
			setF32ValueAt(this.vIdx + 29, yScaledSin + yScaledCos + square.clipY);
			setF32ValueAt(this.vIdx + 30, 0);
			setF32ValueAt(this.vIdx + 31, 8 / Main.ATLAS_WIDTH);

			setF32ValueAt(this.vIdx + 32, square.leftBlendU);
			setF32ValueAt(this.vIdx + 33, square.leftBlendV);
			setF32ValueAt(this.vIdx + 34, square.topBlendU);
			setF32ValueAt(this.vIdx + 35, square.topBlendV);

			setF32ValueAt(this.vIdx + 36, square.rightBlendU);
			setF32ValueAt(this.vIdx + 37, square.rightBlendV);
			setF32ValueAt(this.vIdx + 38, square.bottomBlendU);
			setF32ValueAt(this.vIdx + 39, square.bottomBlendV);

			setF32ValueAt(this.vIdx + 40, square.baseU);
			setF32ValueAt(this.vIdx + 41, square.baseV);

			setF32ValueAt(this.vIdx + 42, xScaledCos + xScaledSin + square.clipX);
			setF32ValueAt(this.vIdx + 43, -yScaledSin + yScaledCos + square.clipY);
			setF32ValueAt(this.vIdx + 44, 8 / Main.ATLAS_WIDTH);
			setF32ValueAt(this.vIdx + 45, 8 / Main.ATLAS_WIDTH);

			setF32ValueAt(this.vIdx + 46, square.leftBlendU);
			setF32ValueAt(this.vIdx + 47, square.leftBlendV);
			setF32ValueAt(this.vIdx + 48, square.topBlendU);
			setF32ValueAt(this.vIdx + 49, square.topBlendV);

			setF32ValueAt(this.vIdx + 50, square.rightBlendU);
			setF32ValueAt(this.vIdx + 51, square.rightBlendV);
			setF32ValueAt(this.vIdx + 52, square.bottomBlendU);
			setF32ValueAt(this.vIdx + 53, square.bottomBlendV);

			setF32ValueAt(this.vIdx + 54, square.baseU);
			setF32ValueAt(this.vIdx + 55, square.baseV);
			this.vIdx += 56;

			final i4: UInt32 = this.i * 4;
			setI32ValueAt(this.iIdx, i4);
			setI32ValueAt(this.iIdx + 1, 1 + i4);
			setI32ValueAt(this.iIdx + 2, 2 + i4);
			setI32ValueAt(this.iIdx + 3, 2 + i4);
			setI32ValueAt(this.iIdx + 4, 1 + i4);
			setI32ValueAt(this.iIdx + 5, 3 + i4);
			this.iIdx += 6;
			this.i++;
		}
	}

	@:nonVirtual private final #if !tracing inline #end function drawWall(time: Int32, obj: GameObject) {
		var texW = obj.width * Main.ATLAS_WIDTH,
			texH = obj.height * Main.ATLAS_HEIGHT;

		if (obj.animations != null) {
			var rect = obj.animations.getTexture(time);
			obj.uValue = rect.x / Main.ATLAS_WIDTH;
			obj.vValue = rect.y / Main.ATLAS_WIDTH;
			texW = rect.width;
			obj.width = texW / Main.ATLAS_WIDTH;
			texH = rect.height;
			obj.height = texH / Main.ATLAS_HEIGHT;
		}
		
		var size = 8 / Main.ATLAS_WIDTH;
		var objX = obj.mapX;
		var objY = obj.mapY;
		var xBaseTop = (objX * Camera.cos + objY * Camera.sin + Camera.csX) * RenderUtils.clipSpaceScaleX;
		var yBaseTop = (objX * -Camera.sin + objY * Camera.cos + Camera.csY - Camera.PX_PER_TILE) * RenderUtils.clipSpaceScaleY;
		var xBase = (objX * Camera.cos + objY * Camera.sin + Camera.csX) * RenderUtils.clipSpaceScaleX;
		var yBase = (objX * -Camera.sin + objY * Camera.cos + Camera.csY) * RenderUtils.clipSpaceScaleY;

		if (obj.props.isEnemy) {
			obj.hBase = size * Camera.SIZE_MULT;
			obj.screenX = xBaseTop;
			obj.screenYNoZ = yBaseTop;
		}
		
		var xScaledCos = Camera.xScaledCos;
		var yScaledCos = Camera.yScaledCos;
		var xScaledSin = Camera.xScaledSin;
		var yScaledSin = Camera.yScaledSin;

		var boundAngle = MathUtil.halfBound(Camera.angleRad);
		if (boundAngle >= MathUtil.PI_DIV_2 && boundAngle <= MathUtil.PI || boundAngle >= -MathUtil.PI && boundAngle <= -MathUtil.PI_DIV_2) {
			var topSquare = this.squares[(Math.floor(objY) - 1) * this.mapWidth + Math.floor(objX)];
			if (topSquare != null && (topSquare.obj == null || topSquare.obj.objClass != "Wall")) {
				setF32ValueAt(this.vIdx, -xScaledCos + xScaledSin + xBaseTop - xScaledSin * 2);
				setF32ValueAt(this.vIdx + 1, yScaledSin + yScaledCos + yBaseTop - yScaledCos * 2);
				setF32ValueAt(this.vIdx + 2, obj.uValue);
				setF32ValueAt(this.vIdx + 3, obj.vValue);

				setF32ValueAt(this.vIdx + 4, 0);
				setF32ValueAt(this.vIdx + 5, 0);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 1.0);
				setF32ValueAt(this.vIdx + 8, 0.25);
				setF32ValueAt(this.vIdx + 9, -1);

				setF32ValueAt(this.vIdx + 10, xScaledCos + xScaledSin + xBaseTop - xScaledSin * 2);
				setF32ValueAt(this.vIdx + 11, -yScaledSin + yScaledCos + yBaseTop - yScaledCos * 2);
				setF32ValueAt(this.vIdx + 12, obj.uValue + size);
				setF32ValueAt(this.vIdx + 13, obj.vValue);

				setF32ValueAt(this.vIdx + 14, 0);
				setF32ValueAt(this.vIdx + 15, 0);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 1.0);
				setF32ValueAt(this.vIdx + 18, 0.25);
				setF32ValueAt(this.vIdx + 19, -1);

				setF32ValueAt(this.vIdx + 20, -xScaledCos + xScaledSin + xBase - xScaledSin * 2);
				setF32ValueAt(this.vIdx + 21, yScaledSin + yScaledCos + yBase - yScaledCos * 2);
				setF32ValueAt(this.vIdx + 22, obj.uValue);
				setF32ValueAt(this.vIdx + 23, obj.vValue + size);

				setF32ValueAt(this.vIdx + 24, 0);
				setF32ValueAt(this.vIdx + 25, 0);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 1.0);
				setF32ValueAt(this.vIdx + 28, 0.25);
				setF32ValueAt(this.vIdx + 29, -1);

				setF32ValueAt(this.vIdx + 30, xScaledCos + xScaledSin + xBase - xScaledSin * 2);
				setF32ValueAt(this.vIdx + 31, -yScaledSin + yScaledCos + yBase - yScaledCos * 2);
				setF32ValueAt(this.vIdx + 32, obj.uValue + size);
				setF32ValueAt(this.vIdx + 33, obj.vValue + size);

				setF32ValueAt(this.vIdx + 34, 0);
				setF32ValueAt(this.vIdx + 35, 0);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 1.0);
				setF32ValueAt(this.vIdx + 38, 0.25);
				setF32ValueAt(this.vIdx + 39, -1);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;
			}
		}
		
		if (boundAngle <= MathUtil.PI_DIV_2 && boundAngle >= -MathUtil.PI_DIV_2) {
			var bottomSquare = this.squares[(Math.floor(objY) + 1) * this.mapWidth + Math.floor(objX)];
			if (bottomSquare != null && (bottomSquare.obj == null || bottomSquare.obj.objClass != "Wall")) { 
				setF32ValueAt(this.vIdx, -xScaledCos + xScaledSin + xBaseTop);
				setF32ValueAt(this.vIdx + 1, yScaledSin + yScaledCos + yBaseTop);
				setF32ValueAt(this.vIdx + 2, obj.uValue);
				setF32ValueAt(this.vIdx + 3, obj.vValue);

				setF32ValueAt(this.vIdx + 4, 0);
				setF32ValueAt(this.vIdx + 5, 0);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 1.0);
				setF32ValueAt(this.vIdx + 8, 0.25);
				setF32ValueAt(this.vIdx + 9, -1);

				setF32ValueAt(this.vIdx + 10, xScaledCos + xScaledSin + xBaseTop);
				setF32ValueAt(this.vIdx + 11, -yScaledSin + yScaledCos + yBaseTop);
				setF32ValueAt(this.vIdx + 12, obj.uValue + size);
				setF32ValueAt(this.vIdx + 13, obj.vValue);

				setF32ValueAt(this.vIdx + 14, 0);
				setF32ValueAt(this.vIdx + 15, 0);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 1.0);
				setF32ValueAt(this.vIdx + 18, 0.25);
				setF32ValueAt(this.vIdx + 19, -1);

				setF32ValueAt(this.vIdx + 20, -xScaledCos + xScaledSin + xBase);
				setF32ValueAt(this.vIdx + 21, yScaledSin + yScaledCos + yBase);
				setF32ValueAt(this.vIdx + 22, obj.uValue);
				setF32ValueAt(this.vIdx + 23, obj.vValue + size);

				setF32ValueAt(this.vIdx + 24, 0);
				setF32ValueAt(this.vIdx + 25, 0);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 1.0);
				setF32ValueAt(this.vIdx + 28, 0.25);
				setF32ValueAt(this.vIdx + 29, -1);

				setF32ValueAt(this.vIdx + 30, xScaledCos + xScaledSin + xBase);
				setF32ValueAt(this.vIdx + 31, -yScaledSin + yScaledCos + yBase);
				setF32ValueAt(this.vIdx + 32, obj.uValue + size);
				setF32ValueAt(this.vIdx + 33, obj.vValue + size);

				setF32ValueAt(this.vIdx + 34, 0);
				setF32ValueAt(this.vIdx + 35, 0);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 1.0);
				setF32ValueAt(this.vIdx + 38, 0.25);
				setF32ValueAt(this.vIdx + 39, -1);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;
			}
		}
		

		if (boundAngle >= 0 && boundAngle <= MathUtil.PI) {
			var leftSquare = this.squares[Math.floor(objY) * this.mapWidth + Math.floor(objX) - 1];
			if (leftSquare != null && (leftSquare.obj == null || leftSquare.obj.objClass != "Wall")) { 
				setF32ValueAt(this.vIdx, -xScaledCos - xScaledSin + xBaseTop);
				setF32ValueAt(this.vIdx + 1, yScaledSin - yScaledCos + yBaseTop);
				setF32ValueAt(this.vIdx + 2, obj.uValue);
				setF32ValueAt(this.vIdx + 3, obj.vValue);

				setF32ValueAt(this.vIdx + 4, 0);
				setF32ValueAt(this.vIdx + 5, 0);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 1.0);
				setF32ValueAt(this.vIdx + 8, 0.25);
				setF32ValueAt(this.vIdx + 9, -1);

				setF32ValueAt(this.vIdx + 10, -xScaledCos + xScaledSin + xBaseTop);
				setF32ValueAt(this.vIdx + 11, yScaledSin + yScaledCos + yBaseTop);
				setF32ValueAt(this.vIdx + 12, obj.uValue + size);
				setF32ValueAt(this.vIdx + 13, obj.vValue);

				setF32ValueAt(this.vIdx + 14, 0);
				setF32ValueAt(this.vIdx + 15, 0);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 1.0);
				setF32ValueAt(this.vIdx + 18, 0.25);
				setF32ValueAt(this.vIdx + 19, -1);

				setF32ValueAt(this.vIdx + 20, -xScaledCos + xScaledSin + xBase - xScaledSin * 2);
				setF32ValueAt(this.vIdx + 21, yScaledSin + yScaledCos + yBase - yScaledCos * 2);
				setF32ValueAt(this.vIdx + 22, obj.uValue);
				setF32ValueAt(this.vIdx + 23, obj.vValue + size);

				setF32ValueAt(this.vIdx + 24, 0);
				setF32ValueAt(this.vIdx + 25, 0);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 1.0);
				setF32ValueAt(this.vIdx + 28, 0.25);
				setF32ValueAt(this.vIdx + 29, -1);

				setF32ValueAt(this.vIdx + 30, -xScaledCos + xScaledSin + xBase);
				setF32ValueAt(this.vIdx + 31, yScaledSin + yScaledCos + yBase);
				setF32ValueAt(this.vIdx + 32, obj.uValue + size);
				setF32ValueAt(this.vIdx + 33, obj.vValue + size);

				setF32ValueAt(this.vIdx + 34, 0);
				setF32ValueAt(this.vIdx + 35, 0);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 1.0);
				setF32ValueAt(this.vIdx + 38, 0.25);
				setF32ValueAt(this.vIdx + 39, -1);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;
			}
		}
		
		if (boundAngle <= 0 && boundAngle >= -MathUtil.PI) {
			var rightSquare = this.squares[Math.floor(objY) * this.mapWidth + Math.floor(objX) + 1];
			if (rightSquare != null && (rightSquare.obj == null || rightSquare.obj.objClass != "Wall")) { 
				setF32ValueAt(this.vIdx, xScaledCos - xScaledSin + xBaseTop);
				setF32ValueAt(this.vIdx + 1, -yScaledSin - yScaledCos + yBaseTop);
				setF32ValueAt(this.vIdx + 2, obj.uValue);
				setF32ValueAt(this.vIdx + 3, obj.vValue);

				setF32ValueAt(this.vIdx + 4, 0);
				setF32ValueAt(this.vIdx + 5, 0);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 1.0);
				setF32ValueAt(this.vIdx + 8, 0.25);
				setF32ValueAt(this.vIdx + 9, -1);

				setF32ValueAt(this.vIdx + 10, xScaledCos + xScaledSin + xBaseTop);
				setF32ValueAt(this.vIdx + 11, -yScaledSin + yScaledCos + yBaseTop);
				setF32ValueAt(this.vIdx + 12, obj.uValue + size);
				setF32ValueAt(this.vIdx + 13, obj.vValue);

				setF32ValueAt(this.vIdx + 14, 0);
				setF32ValueAt(this.vIdx + 15, 0);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 1.0);
				setF32ValueAt(this.vIdx + 18, 0.25);
				setF32ValueAt(this.vIdx + 19, -1);

				setF32ValueAt(this.vIdx + 20, xScaledCos + xScaledSin + xBase - xScaledSin * 2);
				setF32ValueAt(this.vIdx + 21, -yScaledSin + yScaledCos + yBase - yScaledCos * 2);
				setF32ValueAt(this.vIdx + 22, obj.uValue);
				setF32ValueAt(this.vIdx + 23, obj.vValue + size);

				setF32ValueAt(this.vIdx + 24, 0);
				setF32ValueAt(this.vIdx + 25, 0);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 1.0);
				setF32ValueAt(this.vIdx + 28, 0.25);
				setF32ValueAt(this.vIdx + 29, -1);

				setF32ValueAt(this.vIdx + 30, xScaledCos + xScaledSin + xBase);
				setF32ValueAt(this.vIdx + 31, -yScaledSin + yScaledCos + yBase);
				setF32ValueAt(this.vIdx + 32, obj.uValue + size);
				setF32ValueAt(this.vIdx + 33, obj.vValue + size);

				setF32ValueAt(this.vIdx + 34, 0);
				setF32ValueAt(this.vIdx + 35, 0);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 1.0);
				setF32ValueAt(this.vIdx + 38, 0.25);
				setF32ValueAt(this.vIdx + 39, -1);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;
			}
		}

		setF32ValueAt(this.vIdx, -xScaledCos - xScaledSin + xBaseTop);
		setF32ValueAt(this.vIdx + 1, yScaledSin - yScaledCos + yBaseTop);
		setF32ValueAt(this.vIdx + 2, obj.topUValue);
		setF32ValueAt(this.vIdx + 3, obj.topVValue);

		setF32ValueAt(this.vIdx + 4, 0);
		setF32ValueAt(this.vIdx + 5, 0);
		setF32ValueAt(this.vIdx + 6, 0);
		setF32ValueAt(this.vIdx + 7, 0);
		setF32ValueAt(this.vIdx + 8, 0);
		setF32ValueAt(this.vIdx + 9, -1);

		setF32ValueAt(this.vIdx + 10, xScaledCos - xScaledSin + xBaseTop);
		setF32ValueAt(this.vIdx + 11, -yScaledSin - yScaledCos + yBaseTop);
		setF32ValueAt(this.vIdx + 12, obj.topUValue + size);
		setF32ValueAt(this.vIdx + 13, obj.topVValue);

		setF32ValueAt(this.vIdx + 14, 0);
		setF32ValueAt(this.vIdx + 15, 0);
		setF32ValueAt(this.vIdx + 16, 0);
		setF32ValueAt(this.vIdx + 17, 0);
		setF32ValueAt(this.vIdx + 18, 0);
		setF32ValueAt(this.vIdx + 19, -1);

		setF32ValueAt(this.vIdx + 20, -xScaledCos + xScaledSin + xBaseTop);
		setF32ValueAt(this.vIdx + 21, yScaledSin + yScaledCos + yBaseTop);
		setF32ValueAt(this.vIdx + 22, obj.topUValue);
		setF32ValueAt(this.vIdx + 23, obj.topVValue + size);

		setF32ValueAt(this.vIdx + 24, 0);
		setF32ValueAt(this.vIdx + 25, 0);
		setF32ValueAt(this.vIdx + 26, 0);
		setF32ValueAt(this.vIdx + 27, 0);
		setF32ValueAt(this.vIdx + 28, 0);
		setF32ValueAt(this.vIdx + 29, -1);

		setF32ValueAt(this.vIdx + 30, xScaledCos + xScaledSin + xBaseTop);
		setF32ValueAt(this.vIdx + 31, -yScaledSin + yScaledCos + yBaseTop);
		setF32ValueAt(this.vIdx + 32, obj.topUValue + size);
		setF32ValueAt(this.vIdx + 33, obj.topVValue + size);

		setF32ValueAt(this.vIdx + 34, 0);
		setF32ValueAt(this.vIdx + 35, 0);
		setF32ValueAt(this.vIdx + 36, 0);
		setF32ValueAt(this.vIdx + 37, 0);
		setF32ValueAt(this.vIdx + 38, 0);
		setF32ValueAt(this.vIdx + 39, -1);
		this.vIdx += 40;

		final i4 = this.i * 4;
		setI32ValueAt(this.iIdx, i4);
		setI32ValueAt(this.iIdx + 1, 1 + i4);
		setI32ValueAt(this.iIdx + 2, 2 + i4);
		setI32ValueAt(this.iIdx + 3, 2 + i4);
		setI32ValueAt(this.iIdx + 4, 1 + i4);
		setI32ValueAt(this.iIdx + 5, 3 + i4);
		this.iIdx += 6;
		this.i++;
	}

	@:nonVirtual private final #if !tracing inline #end function drawGameObject(time: Int32, obj: GameObject) {
		var screenX = obj.screenX = obj.mapX * Camera.cos + obj.mapY * Camera.sin + Camera.csX;
		var screenY = obj.screenYNoZ + obj.mapZ * -Camera.PX_PER_TILE;

		var texW = obj.width * Main.ATLAS_WIDTH,
			texH = obj.height * Main.ATLAS_HEIGHT;

		var size = Camera.SIZE_MULT * obj.size;
		var hBase = obj.hBase = size * texH;

		if (obj.props.drawOnGround && obj.curSquare != null) {
			final xScaledCos = Camera.xScaledCos;
			final yScaledCos = Camera.yScaledCos;
			final xScaledSin = Camera.xScaledSin;
			final yScaledSin = Camera.yScaledSin;
			final clipX = obj.curSquare.clipX;
			final clipY = obj.curSquare.clipY;

			setF32ValueAt(this.vIdx, -xScaledCos - xScaledSin + clipX);
			setF32ValueAt(this.vIdx + 1, yScaledSin - yScaledCos + clipY);
			setF32ValueAt(this.vIdx + 2, obj.uValue);
			setF32ValueAt(this.vIdx + 3, obj.vValue);

			setF32ValueAt(this.vIdx + 4, 0);
			setF32ValueAt(this.vIdx + 5, 0);
			setF32ValueAt(this.vIdx + 6, 0);
			setF32ValueAt(this.vIdx + 7, 0);
			setF32ValueAt(this.vIdx + 8, 0);
			setF32ValueAt(this.vIdx + 9, -1);

			setF32ValueAt(this.vIdx + 10, xScaledCos - xScaledSin + clipX);
			setF32ValueAt(this.vIdx + 11, -yScaledSin - yScaledCos + clipY);
			setF32ValueAt(this.vIdx + 12, obj.uValue + obj.width);
			setF32ValueAt(this.vIdx + 13, obj.vValue);

			setF32ValueAt(this.vIdx + 14, 0);
			setF32ValueAt(this.vIdx + 15, 0);
			setF32ValueAt(this.vIdx + 16, 0);
			setF32ValueAt(this.vIdx + 17, 0);
			setF32ValueAt(this.vIdx + 18, 0);
			setF32ValueAt(this.vIdx + 19, -1);

			setF32ValueAt(this.vIdx + 20, -xScaledCos + xScaledSin + clipX);
			setF32ValueAt(this.vIdx + 21, yScaledSin + yScaledCos + clipY);
			setF32ValueAt(this.vIdx + 22, obj.uValue);
			setF32ValueAt(this.vIdx + 23, obj.vValue + obj.height);

			setF32ValueAt(this.vIdx + 24, 0);
			setF32ValueAt(this.vIdx + 25, 0);
			setF32ValueAt(this.vIdx + 26, 0);
			setF32ValueAt(this.vIdx + 27, 0);
			setF32ValueAt(this.vIdx + 28, 0);
			setF32ValueAt(this.vIdx + 29, -1);

			setF32ValueAt(this.vIdx + 30, xScaledCos + xScaledSin + clipX);
			setF32ValueAt(this.vIdx + 31, -yScaledSin + yScaledCos + clipY);
			setF32ValueAt(this.vIdx + 32, obj.uValue + obj.width);
			setF32ValueAt(this.vIdx + 33, obj.vValue + obj.height);

			setF32ValueAt(this.vIdx + 34, 0);
			setF32ValueAt(this.vIdx + 35, 0);
			setF32ValueAt(this.vIdx + 36, 0);
			setF32ValueAt(this.vIdx + 37, 0);
			setF32ValueAt(this.vIdx + 38, 0);
			setF32ValueAt(this.vIdx + 39, -1);
			this.vIdx += 40;

			final i4: UInt32 = this.i * 4;
			setI32ValueAt(this.iIdx, i4);
			setI32ValueAt(this.iIdx + 1, 1 + i4);
			setI32ValueAt(this.iIdx + 2, 2 + i4);
			setI32ValueAt(this.iIdx + 3, 2 + i4);
			setI32ValueAt(this.iIdx + 4, 1 + i4);
			setI32ValueAt(this.iIdx + 5, 3 + i4);
			this.iIdx += 6;
			this.i++;

			var isPortal = obj.objClass == "Portal";
			if ((obj.props.showName || isPortal) && obj.name != null && obj.name != "") {
				if (obj.nameTex == null) {
					obj.nameText = new SimpleText(16, 0xFFFFFF);
					obj.nameText.setBold(true);
					obj.nameText.text = obj.name;
					obj.nameText.updateMetrics();

					obj.nameTex = new BitmapData(Std.int(obj.nameText.width + 20), 64, true, 0);
					obj.nameTex.draw(obj.nameText, new Matrix(1, 0, 0, 1, 12, 0));
					obj.nameTex.applyFilter(obj.nameTex, obj.nameTex.rect, new Point(0, 0), new GlowFilter(0, 1, 3, 3, 2, 1));
				}
				
				var textureData = TextureFactory.make(obj.nameTex);
				this.rdSingle.push({cosX: textureData.width * RenderUtils.clipSpaceScaleX, 
					sinX: 0, sinY: 0,
					cosY: textureData.height * RenderUtils.clipSpaceScaleY,
					x: (screenX - 3) * RenderUtils.clipSpaceScaleX, y: (screenY - hBase + 50) * RenderUtils.clipSpaceScaleY,
					texelW: 0, texelH: 0,
					texture: textureData.texture});

				if (isPortal && Global.currentInteractiveTarget == obj.objectId) {
					if (obj.enterTex == null) {
						var enterText = new SimpleText(16, 0xFFFFFF);
						enterText.setBold(true);
						enterText.text = "Enter";
						enterText.updateMetrics();

						obj.enterTex = new BitmapData(Std.int(enterText.width + 20), 64, true, 0);
						obj.enterTex.draw(enterText, new Matrix(1, 0, 0, 1, 12, 0));
						obj.enterTex.applyFilter(obj.enterTex, obj.enterTex.rect, new Point(0, 0), new GlowFilter(0, 1, 3, 3, 2, 1));
					}
					
					var textureData = TextureFactory.make(obj.enterTex);
					this.rdSingle.push({cosX: textureData.width * RenderUtils.clipSpaceScaleX, 
						sinX: 0, sinY: 0,
						cosY: textureData.height * RenderUtils.clipSpaceScaleY,
						x: (screenX + 8) * RenderUtils.clipSpaceScaleX, y: (screenY + 60) * RenderUtils.clipSpaceScaleY,
						texelW: 0, texelH: 0,
						texture: textureData.texture});

					if (obj.enterKeyTex == null)
						obj.enterKeyTex = AssetLibrary.getImageFromSet("keyIndicators", KeyCodeUtil.charCodeIconIndices[Settings.interact]);

					var textureData = TextureFactory.make(obj.enterKeyTex);
					this.rdSingle.push({cosX: (textureData.width >> 2) * RenderUtils.clipSpaceScaleX, 
						sinX: 0, sinY: 0,
						cosY: (textureData.height >> 2) * RenderUtils.clipSpaceScaleY,
						x: (screenX - 22) * RenderUtils.clipSpaceScaleX, y: (screenY + 39) * RenderUtils.clipSpaceScaleY,
						texelW: 0, texelH: 0,
						texture: textureData.texture});	
				}
			}

			return;
		}

		var rect: Rect = null;
		var action = AnimatedChar.STAND;
		var p: Float32 = 0.0;
		if (obj.animatedChar != null) {
			if (time < obj.attackStart + GameObject.ATTACK_PERIOD) {
				if (!obj.props.dontFaceAttacks)
					obj.facing = obj.attackAngle;

				p = (time - obj.attackStart) % GameObject.ATTACK_PERIOD / GameObject.ATTACK_PERIOD;
				action = AnimatedChar.ATTACK;
			} else if (obj.moveVec.x != 0 || obj.moveVec.y != 0) {
				var walkPer = Std.int(0.5 / obj.moveVec.length);
				walkPer += 400 - walkPer % 400;
				if (obj.moveVec.x > GameObject.ZERO_LIMIT
					|| obj.moveVec.x < GameObject.NEGATIVE_ZERO_LIMIT
					|| obj.moveVec.y > GameObject.ZERO_LIMIT
					|| obj.moveVec.y < GameObject.NEGATIVE_ZERO_LIMIT) {
					obj.facing = Math.atan2(obj.moveVec.y, obj.moveVec.x);
					action = AnimatedChar.WALK;
				} else
					action = AnimatedChar.STAND;

				p = time % walkPer / walkPer;
			}

			rect = obj.animatedChar.rectFromFacing(obj.facing, action, p);
		} else if (obj.animations != null)
			rect = obj.animations.getTexture(time);

		if (rect != null) {
			obj.uValue = rect.x / Main.ATLAS_WIDTH;
			obj.vValue = rect.y / Main.ATLAS_WIDTH;
			texW = rect.width;
			obj.width = texW / Main.ATLAS_WIDTH;
			texH = rect.height;
			obj.height = texH / Main.ATLAS_HEIGHT;
		}

		var sink: Float32 = 1.0;
		if (obj.curSquare != null && !(obj.flying || obj.curSquare.obj != null && obj.curSquare.obj.props.protectFromSink))
			sink += obj.curSquare.sink + obj.sinkLevel;

		var flashStrength: Float32 = 0.0;
		if (obj.flashPeriodMs > 0) {
			if (obj.flashRepeats != -1 && time > obj.flashStartTime + obj.flashPeriodMs * obj.flashRepeats)
				obj.flashRepeats = obj.flashStartTime = obj.flashPeriodMs = obj.flashColor = 0;
			else
				flashStrength = MathUtil.sin((time - obj.flashStartTime) % obj.flashPeriodMs / obj.flashPeriodMs * MathUtil.PI) * 0.5;
		}

		var w = size * texW * RenderUtils.clipSpaceScaleX * 0.5;
		var h = hBase * RenderUtils.clipSpaceScaleY * 0.5 / sink;
		var yBase = (screenY - (hBase / 2 - size * Main.PADDING)) * RenderUtils.clipSpaceScaleY;
		var xOffset: Float32 = 0.0;
		if (action == AnimatedChar.ATTACK && p >= 0.5) {
			var dir = player.animatedChar.facingToDir(player.facing);
			if (dir == AnimatedChar.LEFT)
				xOffset = -(texW + size);
			else
				xOffset = texW + size;
		}
		var xBase = (screenX + (action == AnimatedChar.ATTACK ? xOffset : 0)) * RenderUtils.clipSpaceScaleX;
		var texelW: Float32 = 2.0 / Main.ATLAS_WIDTH / size;
		var texelH: Float32 = 2.0 / Main.ATLAS_HEIGHT / size;

		setF32ValueAt(this.vIdx, -w + xBase);
		setF32ValueAt(this.vIdx + 1, -h + yBase);
		setF32ValueAt(this.vIdx + 2, obj.uValue);
		setF32ValueAt(this.vIdx + 3, obj.vValue);

		setF32ValueAt(this.vIdx + 4, texelW);
		setF32ValueAt(this.vIdx + 5, texelH);
		setF32ValueAt(this.vIdx + 6, obj.glowColor);
		setF32ValueAt(this.vIdx + 7, obj.flashColor);
		setF32ValueAt(this.vIdx + 8, flashStrength);
		setF32ValueAt(this.vIdx + 9, -1);

		setF32ValueAt(this.vIdx + 10, w + xBase);
		setF32ValueAt(this.vIdx + 11, -h + yBase);
		setF32ValueAt(this.vIdx + 12, obj.uValue + obj.width);
		setF32ValueAt(this.vIdx + 13, obj.vValue);

		setF32ValueAt(this.vIdx + 14, texelW);
		setF32ValueAt(this.vIdx + 15, texelH);
		setF32ValueAt(this.vIdx + 16, obj.glowColor);
		setF32ValueAt(this.vIdx + 17, obj.flashColor);
		setF32ValueAt(this.vIdx + 18, flashStrength);
		setF32ValueAt(this.vIdx + 19, -1);

		setF32ValueAt(this.vIdx + 20, -w + xBase);
		setF32ValueAt(this.vIdx + 21, h + yBase);
		setF32ValueAt(this.vIdx + 22, obj.uValue);
		setF32ValueAt(this.vIdx + 23, obj.vValue + obj.height / sink);

		setF32ValueAt(this.vIdx + 24, texelW);
		setF32ValueAt(this.vIdx + 25, texelH);
		setF32ValueAt(this.vIdx + 26, obj.glowColor);
		setF32ValueAt(this.vIdx + 27, obj.flashColor);
		setF32ValueAt(this.vIdx + 28, flashStrength);
		setF32ValueAt(this.vIdx + 29, -1);

		setF32ValueAt(this.vIdx + 30, w + xBase);
		setF32ValueAt(this.vIdx + 31, h + yBase);
		setF32ValueAt(this.vIdx + 32, obj.uValue + obj.width);
		setF32ValueAt(this.vIdx + 33, obj.vValue + obj.height / sink);

		setF32ValueAt(this.vIdx + 34, texelW);
		setF32ValueAt(this.vIdx + 35, texelH);
		setF32ValueAt(this.vIdx + 36, obj.glowColor);
		setF32ValueAt(this.vIdx + 37, obj.flashColor);
		setF32ValueAt(this.vIdx + 38, flashStrength);
		setF32ValueAt(this.vIdx + 39, -1);
		this.vIdx += 40;

		final i4 = this.i * 4;
		setI32ValueAt(this.iIdx, i4);
		setI32ValueAt(this.iIdx + 1, 1 + i4);
		setI32ValueAt(this.iIdx + 2, 2 + i4);
		setI32ValueAt(this.iIdx + 3, 2 + i4);
		setI32ValueAt(this.iIdx + 4, 1 + i4);
		setI32ValueAt(this.iIdx + 5, 3 + i4);
		this.iIdx += 6;
		this.i++;

		var yPos: Int32 = 15 + (sink != 0 ? 5 : 0);
		if (obj.props == null || !obj.props.noMiniMap) {
			xBase = screenX * RenderUtils.clipSpaceScaleX;

			if (obj.hp > obj.maxHP)
				obj.maxHP = obj.hp;

			var scaledEmptyBarW: Float32 = emptyBarW / Main.ATLAS_WIDTH;
			var scaledEmptyBarH: Float32 = emptyBarH / Main.ATLAS_HEIGHT;
			if (obj.hp >= 0 && obj.hp < obj.maxHP) {
				var scaledBarW: Float32 = hpBarW / Main.ATLAS_WIDTH;
				var scaledBarH: Float32 = hpBarH / Main.ATLAS_HEIGHT;
				var barThreshU: Float32 = hpBarU + scaledBarW;
				barThreshU *= (obj.hp / obj.maxHP) * (1 - 4/24) + (obj.hp / obj.maxHP) * (2/24); // account for decor
				w = hpBarW * RenderUtils.clipSpaceScaleX;
				h = hpBarH * RenderUtils.clipSpaceScaleY;
				yBase = (screenY + yPos - (hpBarH / 2 - Main.PADDING)) * RenderUtils.clipSpaceScaleY;
				texelW = 0.5 / Main.ATLAS_WIDTH;
				texelH = 0.5 / Main.ATLAS_HEIGHT;

				setF32ValueAt(this.vIdx, -w + xBase);
				setF32ValueAt(this.vIdx + 1, -h + yBase);
				setF32ValueAt(this.vIdx + 2, emptyBarU);
				setF32ValueAt(this.vIdx + 3, emptyBarV);

				setF32ValueAt(this.vIdx + 4, texelW);
				setF32ValueAt(this.vIdx + 5, texelH);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 0);
				setF32ValueAt(this.vIdx + 8, 0);
				setF32ValueAt(this.vIdx + 9, -1);

				setF32ValueAt(this.vIdx + 10, w + xBase);
				setF32ValueAt(this.vIdx + 11, -h + yBase);
				setF32ValueAt(this.vIdx + 12, emptyBarU + scaledEmptyBarW);
				setF32ValueAt(this.vIdx + 13, emptyBarV);

				setF32ValueAt(this.vIdx + 14, texelW);
				setF32ValueAt(this.vIdx + 15, texelH);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 0);
				setF32ValueAt(this.vIdx + 18, 0);
				setF32ValueAt(this.vIdx + 19, -1);

				setF32ValueAt(this.vIdx + 20, -w + xBase);
				setF32ValueAt(this.vIdx + 21, h + yBase);
				setF32ValueAt(this.vIdx + 22, emptyBarU);
				setF32ValueAt(this.vIdx + 23, emptyBarV + scaledEmptyBarH);

				setF32ValueAt(this.vIdx + 24, texelW);
				setF32ValueAt(this.vIdx + 25, texelH);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 0);
				setF32ValueAt(this.vIdx + 28, 0);
				setF32ValueAt(this.vIdx + 29, -1);

				setF32ValueAt(this.vIdx + 30, w + xBase);
				setF32ValueAt(this.vIdx + 31, h + yBase);
				setF32ValueAt(this.vIdx + 32, emptyBarU + scaledEmptyBarW);
				setF32ValueAt(this.vIdx + 33, emptyBarV + scaledEmptyBarH);

				setF32ValueAt(this.vIdx + 34, texelW);
				setF32ValueAt(this.vIdx + 35, texelH);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 0);
				setF32ValueAt(this.vIdx + 38, 0);
				setF32ValueAt(this.vIdx + 39, -1);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;

				setF32ValueAt(this.vIdx, -w + xBase);
				setF32ValueAt(this.vIdx + 1, -h + yBase);
				setF32ValueAt(this.vIdx + 2, hpBarU);
				setF32ValueAt(this.vIdx + 3, hpBarV);

				setF32ValueAt(this.vIdx + 4, texelW);
				setF32ValueAt(this.vIdx + 5, texelH);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 0);
				setF32ValueAt(this.vIdx + 8, 0);
				setF32ValueAt(this.vIdx + 9, barThreshU);

				setF32ValueAt(this.vIdx + 10, w + xBase);
				setF32ValueAt(this.vIdx + 11, -h + yBase);
				setF32ValueAt(this.vIdx + 12, hpBarU + scaledBarW);
				setF32ValueAt(this.vIdx + 13, hpBarV);

				setF32ValueAt(this.vIdx + 14, texelW);
				setF32ValueAt(this.vIdx + 15, texelH);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 0);
				setF32ValueAt(this.vIdx + 18, 0);
				setF32ValueAt(this.vIdx + 19, barThreshU);

				setF32ValueAt(this.vIdx + 20, -w + xBase);
				setF32ValueAt(this.vIdx + 21, h + yBase);
				setF32ValueAt(this.vIdx + 22, hpBarU);
				setF32ValueAt(this.vIdx + 23, hpBarV + scaledBarH);

				setF32ValueAt(this.vIdx + 24, texelW);
				setF32ValueAt(this.vIdx + 25, texelH);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 0);
				setF32ValueAt(this.vIdx + 28, 0);
				setF32ValueAt(this.vIdx + 29, barThreshU);

				setF32ValueAt(this.vIdx + 30, w + xBase);
				setF32ValueAt(this.vIdx + 31, h + yBase);
				setF32ValueAt(this.vIdx + 32, hpBarU + scaledBarW);
				setF32ValueAt(this.vIdx + 33, hpBarV + scaledBarH);

				setF32ValueAt(this.vIdx + 34, texelW);
				setF32ValueAt(this.vIdx + 35, texelH);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 0);
				setF32ValueAt(this.vIdx + 38, 0);
				setF32ValueAt(this.vIdx + 39, barThreshU);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;

				yPos += 20;
			}
		}

		if (obj.condition > 0) {
			var len = 0;
			for (i in 0...32)
				if (obj.condition & (1 << i) != 0)
					len++;

			len >>= 1;
			for (i in 0...32)
				if (obj.condition & (1 << i) != 0) {
					var rect = ConditionEffect.effectRects[i];
					if (rect == null)
						continue;

					var scaledW: Float32 = rect.width / Main.ATLAS_WIDTH;
					var scaledH: Float32 = rect.height / Main.ATLAS_HEIGHT;
					var scaledU: Float32 = rect.x / Main.ATLAS_WIDTH;
					var scaledV: Float32 = rect.y / Main.ATLAS_HEIGHT;
					w = rect.width * RenderUtils.clipSpaceScaleX;
					h = rect.height * RenderUtils.clipSpaceScaleY;
					xBase = (screenX - rect.width * len + i * rect.width) * RenderUtils.clipSpaceScaleX;
					yBase = (screenY + yPos - (rect.height / 2 - Main.PADDING)) * RenderUtils.clipSpaceScaleY;
					texelW = 0.5 / Main.ATLAS_WIDTH;
					texelH = 0.5 / Main.ATLAS_HEIGHT;

					setF32ValueAt(this.vIdx, -w + xBase);
					setF32ValueAt(this.vIdx + 1, -h + yBase);
					setF32ValueAt(this.vIdx + 2, scaledU);
					setF32ValueAt(this.vIdx + 3, scaledV);

					setF32ValueAt(this.vIdx + 4, texelW);
					setF32ValueAt(this.vIdx + 5, texelH);
					setF32ValueAt(this.vIdx + 6, 0);
					setF32ValueAt(this.vIdx + 7, 0);
					setF32ValueAt(this.vIdx + 8, 0);
					setF32ValueAt(this.vIdx + 9, -1);

					setF32ValueAt(this.vIdx + 10, w + xBase);
					setF32ValueAt(this.vIdx + 11, -h + yBase);
					setF32ValueAt(this.vIdx + 12, scaledU + scaledW);
					setF32ValueAt(this.vIdx + 13, scaledV);

					setF32ValueAt(this.vIdx + 14, texelW);
					setF32ValueAt(this.vIdx + 15, texelH);
					setF32ValueAt(this.vIdx + 16, 0);
					setF32ValueAt(this.vIdx + 17, 0);
					setF32ValueAt(this.vIdx + 18, 0);
					setF32ValueAt(this.vIdx + 19, -1);

					setF32ValueAt(this.vIdx + 20, -w + xBase);
					setF32ValueAt(this.vIdx + 21, h + yBase);
					setF32ValueAt(this.vIdx + 22, scaledU);
					setF32ValueAt(this.vIdx + 23, scaledV + scaledH);

					setF32ValueAt(this.vIdx + 24, texelW);
					setF32ValueAt(this.vIdx + 25, texelH);
					setF32ValueAt(this.vIdx + 26, 0);
					setF32ValueAt(this.vIdx + 27, 0);
					setF32ValueAt(this.vIdx + 28, 0);
					setF32ValueAt(this.vIdx + 29, -1);

					setF32ValueAt(this.vIdx + 30, w + xBase);
					setF32ValueAt(this.vIdx + 31, h + yBase);
					setF32ValueAt(this.vIdx + 32, scaledU + scaledW);
					setF32ValueAt(this.vIdx + 33, scaledV + scaledH);

					setF32ValueAt(this.vIdx + 34, texelW);
					setF32ValueAt(this.vIdx + 35, texelH);
					setF32ValueAt(this.vIdx + 36, 0);
					setF32ValueAt(this.vIdx + 37, 0);
					setF32ValueAt(this.vIdx + 38, 0);
					setF32ValueAt(this.vIdx + 39, -1);
					this.vIdx += 40;

					final i4 = this.i * 4;
					setI32ValueAt(this.iIdx, i4);
					setI32ValueAt(this.iIdx + 1, 1 + i4);
					setI32ValueAt(this.iIdx + 2, 2 + i4);
					setI32ValueAt(this.iIdx + 3, 2 + i4);
					setI32ValueAt(this.iIdx + 4, 1 + i4);
					setI32ValueAt(this.iIdx + 5, 3 + i4);
					this.iIdx += 6;
					this.i++;
				}
		}

		var isPortal = obj.objClass == "Portal";
		if ((obj.props.showName || isPortal) && obj.name != null && obj.name != "") {
			if (obj.nameTex == null) {
				obj.nameText = new SimpleText(16, 0xFFFFFF);
				obj.nameText.setBold(true);
				obj.nameText.text = obj.name;
				obj.nameText.updateMetrics();

				obj.nameTex = new BitmapData(Std.int(obj.nameText.width + 20), 64, true, 0);
				obj.nameTex.draw(obj.nameText, new Matrix(1, 0, 0, 1, 12, 0));
				obj.nameTex.applyFilter(obj.nameTex, obj.nameTex.rect, new Point(0, 0), new GlowFilter(0, 1, 3, 3, 2, 1));
			}
			
			var textureData = TextureFactory.make(obj.nameTex);
			this.rdSingle.push({cosX: textureData.width * RenderUtils.clipSpaceScaleX, 
				sinX: 0, sinY: 0,
				cosY: textureData.height * RenderUtils.clipSpaceScaleY,
				x: (screenX - 3) * RenderUtils.clipSpaceScaleX, y: (screenY - hBase + 30 + (sink - 1) * hBase / 3) * RenderUtils.clipSpaceScaleY,
				texelW: 0, texelH: 0,
				texture: textureData.texture});

			if (isPortal && Global.currentInteractiveTarget == obj.objectId) {
				if (obj.enterTex == null) {
					var enterText = new SimpleText(16, 0xFFFFFF);
					enterText.setBold(true);
					enterText.text = "Enter";
					enterText.updateMetrics();

					obj.enterTex = new BitmapData(Std.int(enterText.width + 20), 64, true, 0);
					obj.enterTex.draw(enterText, new Matrix(1, 0, 0, 1, 12, 0));
					obj.enterTex.applyFilter(obj.enterTex, obj.enterTex.rect, new Point(0, 0), new GlowFilter(0, 1, 3, 3, 2, 1));
				}
				
				var textureData = TextureFactory.make(obj.enterTex);
				this.rdSingle.push({cosX: textureData.width * RenderUtils.clipSpaceScaleX, 
					sinX: 0, sinY: 0,
					cosY: textureData.height * RenderUtils.clipSpaceScaleY,
					x: (screenX + 8) * RenderUtils.clipSpaceScaleX, y: (screenY + 40) * RenderUtils.clipSpaceScaleY,
					texelW: 0, texelH: 0,
					texture: textureData.texture});

				if (obj.enterKeyTex == null)
					obj.enterKeyTex = AssetLibrary.getImageFromSet("keyIndicators", KeyCodeUtil.charCodeIconIndices[Settings.interact]);

				var textureData = TextureFactory.make(obj.enterKeyTex);
				this.rdSingle.push({cosX: (textureData.width >> 2) * RenderUtils.clipSpaceScaleX, 
					sinX: 0, sinY: 0,
					cosY: (textureData.height >> 2) * RenderUtils.clipSpaceScaleY,
					x: (screenX - 22) * RenderUtils.clipSpaceScaleX, y: (screenY + 19) * RenderUtils.clipSpaceScaleY,
					texelW: 0, texelH: 0,
					texture: textureData.texture});	
			}
		}
	}

	@:nonVirtual private final #if !tracing inline #end function drawPlayer(time: Int32, player: Player) {
		var screenX = player.screenX = player.mapX * Camera.cos + player.mapY * Camera.sin + Camera.csX;
		var screenY = player.screenYNoZ + player.mapZ * -Camera.PX_PER_TILE;

		var texW = player.width * Main.ATLAS_WIDTH,
			texH = player.height * Main.ATLAS_HEIGHT;

		var action = AnimatedChar.STAND;
		var p: Float32 = 0.0;
		var rect: Rect = null;
		if (player.animatedChar != null) {
			if (time < player.attackStart + GameObject.ATTACK_PERIOD) {
				if (!player.props.dontFaceAttacks)
					player.facing = player.attackAngle;

				p = (time - player.attackStart) % GameObject.ATTACK_PERIOD / GameObject.ATTACK_PERIOD;
				action = AnimatedChar.ATTACK;
			} else if (player.moveVec.x != 0 || player.moveVec.y != 0) {
				var walkPer = Std.int(0.5 / player.moveVec.length);
				walkPer += 400 - walkPer % 400;
				if (player.moveVec.x > GameObject.ZERO_LIMIT
					|| player.moveVec.x < GameObject.NEGATIVE_ZERO_LIMIT
					|| player.moveVec.y > GameObject.ZERO_LIMIT
					|| player.moveVec.y < GameObject.NEGATIVE_ZERO_LIMIT) {
					player.facing = Math.atan2(player.moveVec.y, player.moveVec.x);
					action = AnimatedChar.WALK;
				} else
					action = AnimatedChar.STAND;

				p = time % walkPer / walkPer;
			}

			rect = player.animatedChar.rectFromFacing(player.facing, action, p);
		} else if (player.animations != null)
			rect = player.animations.getTexture(time);

		if (rect != null) {
			player.uValue = rect.x / Main.ATLAS_WIDTH;
			player.vValue = rect.y / Main.ATLAS_WIDTH;
			texW = rect.width;
			player.width = texW / Main.ATLAS_WIDTH;
			texH = rect.height;
			player.height = texH / Main.ATLAS_HEIGHT;
		}

		var sink: Float32 = 1.0;
		if (player.curSquare != null && !(player.flying || player.curSquare.obj != null && player.curSquare.obj.props.protectFromSink))
			sink += player.curSquare.sink + player.sinkLevel;

		var flashStrength: Float32 = 0.0;
		if (player.flashPeriodMs > 0) {
			if (player.flashRepeats != -1 && time > player.flashStartTime + player.flashPeriodMs * player.flashRepeats)
				player.flashRepeats = player.flashStartTime = player.flashPeriodMs = player.flashColor = 0;
			else
				flashStrength = MathUtil.sin((time - player.flashStartTime) % player.flashPeriodMs / player.flashPeriodMs * MathUtil.PI) * 0.5;
		}

		var size = Camera.SIZE_MULT * player.size;
		var w = size * texW * RenderUtils.clipSpaceScaleX * 0.5;
		var hBase = player.hBase = size * texH;
		var h = hBase * RenderUtils.clipSpaceScaleY * 0.5 / sink;
		var yBase = (screenY - (hBase / 2 - size * Main.PADDING)) * RenderUtils.clipSpaceScaleY;
		var xOffset: Float32 = 0.0;
		if (action == AnimatedChar.ATTACK && p >= 0.5) {
			var dir = player.animatedChar.facingToDir(player.facing);
			if (dir == AnimatedChar.LEFT)
				xOffset = -(texW + size);
			else
				xOffset = texW + size;
		}
		var xBase = (screenX + (action == AnimatedChar.ATTACK ? xOffset : 0)) * RenderUtils.clipSpaceScaleX;
		var texelW: Float32 = 2.0 / Main.ATLAS_WIDTH / size;
		var texelH: Float32 = 2.0 / Main.ATLAS_HEIGHT / size;

		setF32ValueAt(this.vIdx, -w + xBase);
		setF32ValueAt(this.vIdx + 1, -h + yBase);
		setF32ValueAt(this.vIdx + 2, player.uValue);
		setF32ValueAt(this.vIdx + 3, player.vValue);

		setF32ValueAt(this.vIdx + 4, texelW);
		setF32ValueAt(this.vIdx + 5, texelH);
		setF32ValueAt(this.vIdx + 6, player.glowColor);
		setF32ValueAt(this.vIdx + 7, player.flashColor);
		setF32ValueAt(this.vIdx + 8, flashStrength);
		setF32ValueAt(this.vIdx + 9, -1);

		setF32ValueAt(this.vIdx + 10, w + xBase);
		setF32ValueAt(this.vIdx + 11, -h + yBase);
		setF32ValueAt(this.vIdx + 12, player.uValue + player.width);
		setF32ValueAt(this.vIdx + 13, player.vValue);

		setF32ValueAt(this.vIdx + 14, texelW);
		setF32ValueAt(this.vIdx + 15, texelH);
		setF32ValueAt(this.vIdx + 16, player.glowColor);
		setF32ValueAt(this.vIdx + 17, player.flashColor);
		setF32ValueAt(this.vIdx + 18, flashStrength);
		setF32ValueAt(this.vIdx + 19, -1);

		setF32ValueAt(this.vIdx + 20, -w + xBase);
		setF32ValueAt(this.vIdx + 21, h + yBase);
		setF32ValueAt(this.vIdx + 22, player.uValue);
		setF32ValueAt(this.vIdx + 23, player.vValue + player.height / sink);

		setF32ValueAt(this.vIdx + 24, texelW);
		setF32ValueAt(this.vIdx + 25, texelH);
		setF32ValueAt(this.vIdx + 26, player.glowColor);
		setF32ValueAt(this.vIdx + 27, player.flashColor);
		setF32ValueAt(this.vIdx + 28, flashStrength);
		setF32ValueAt(this.vIdx + 29, -1);

		setF32ValueAt(this.vIdx + 30, w + xBase);
		setF32ValueAt(this.vIdx + 31, h + yBase);
		setF32ValueAt(this.vIdx + 32, player.uValue + player.width);
		setF32ValueAt(this.vIdx + 33, player.vValue + player.height / sink);

		setF32ValueAt(this.vIdx + 34, texelW);
		setF32ValueAt(this.vIdx + 35, texelH);
		setF32ValueAt(this.vIdx + 36, player.glowColor);
		setF32ValueAt(this.vIdx + 37, player.flashColor);
		setF32ValueAt(this.vIdx + 38, flashStrength);
		setF32ValueAt(this.vIdx + 39, -1);
		this.vIdx += 40;

		final i4 = this.i * 4;
		setI32ValueAt(this.iIdx, i4);
		setI32ValueAt(this.iIdx + 1, 1 + i4);
		setI32ValueAt(this.iIdx + 2, 2 + i4);
		setI32ValueAt(this.iIdx + 3, 2 + i4);
		setI32ValueAt(this.iIdx + 4, 1 + i4);
		setI32ValueAt(this.iIdx + 5, 3 + i4);
		this.iIdx += 6;
		this.i++;

		var yPos: Int32 = 15 + (sink != 0 ? 5 : 0);
		if (player.props == null || !player.props.noMiniMap) {
			xBase = screenX * RenderUtils.clipSpaceScaleX;

			if (player.hp > player.maxHP)
				player.maxHP = player.hp;

			if (player.mp > player.maxMP)
				player.maxMP = player.mp;

			var scaledEmptyBarW: Float32 = emptyBarW / Main.ATLAS_WIDTH;
			var scaledEmptyBarH: Float32 = emptyBarH / Main.ATLAS_HEIGHT;
			if (player.hp >= 0 && player.hp < player.maxHP) {
				var scaledBarW: Float32 = hpBarW / Main.ATLAS_WIDTH;
				var scaledBarH: Float32 = hpBarH / Main.ATLAS_HEIGHT;
				var barThreshU: Float32 = hpBarU + scaledBarW;
				barThreshU *= (player.hp / player.maxHP) * (1 - 4/24) + (player.hp / player.maxHP) * (2/24); // account for decor
				w = hpBarW * RenderUtils.clipSpaceScaleX;
				h = hpBarH * RenderUtils.clipSpaceScaleY;
				yBase = (screenY + yPos - (hpBarH / 2 - Main.PADDING)) * RenderUtils.clipSpaceScaleY;
				texelW = 0.5 / Main.ATLAS_WIDTH;
				texelH = 0.5 / Main.ATLAS_HEIGHT;

				setF32ValueAt(this.vIdx, -w + xBase);
				setF32ValueAt(this.vIdx + 1, -h + yBase);
				setF32ValueAt(this.vIdx + 2, emptyBarU);
				setF32ValueAt(this.vIdx + 3, emptyBarV);

				setF32ValueAt(this.vIdx + 4, texelW);
				setF32ValueAt(this.vIdx + 5, texelH);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 0);
				setF32ValueAt(this.vIdx + 8, 0);
				setF32ValueAt(this.vIdx + 9, -1);

				setF32ValueAt(this.vIdx + 10, w + xBase);
				setF32ValueAt(this.vIdx + 11, -h + yBase);
				setF32ValueAt(this.vIdx + 12, emptyBarU + scaledEmptyBarW);
				setF32ValueAt(this.vIdx + 13, emptyBarV);

				setF32ValueAt(this.vIdx + 14, texelW);
				setF32ValueAt(this.vIdx + 15, texelH);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 0);
				setF32ValueAt(this.vIdx + 18, 0);
				setF32ValueAt(this.vIdx + 19, -1);

				setF32ValueAt(this.vIdx + 20, -w + xBase);
				setF32ValueAt(this.vIdx + 21, h + yBase);
				setF32ValueAt(this.vIdx + 22, emptyBarU);
				setF32ValueAt(this.vIdx + 23, emptyBarV + scaledEmptyBarH);

				setF32ValueAt(this.vIdx + 24, texelW);
				setF32ValueAt(this.vIdx + 25, texelH);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 0);
				setF32ValueAt(this.vIdx + 28, 0);
				setF32ValueAt(this.vIdx + 29, -1);

				setF32ValueAt(this.vIdx + 30, w + xBase);
				setF32ValueAt(this.vIdx + 31, h + yBase);
				setF32ValueAt(this.vIdx + 32, emptyBarU + scaledEmptyBarW);
				setF32ValueAt(this.vIdx + 33, emptyBarV + scaledEmptyBarH);

				setF32ValueAt(this.vIdx + 34, texelW);
				setF32ValueAt(this.vIdx + 35, texelH);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 0);
				setF32ValueAt(this.vIdx + 38, 0);
				setF32ValueAt(this.vIdx + 39, -1);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;

				setF32ValueAt(this.vIdx, -w + xBase);
				setF32ValueAt(this.vIdx + 1, -h + yBase);
				setF32ValueAt(this.vIdx + 2, hpBarU);
				setF32ValueAt(this.vIdx + 3, hpBarV);

				setF32ValueAt(this.vIdx + 4, texelW);
				setF32ValueAt(this.vIdx + 5, texelH);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 0);
				setF32ValueAt(this.vIdx + 8, 0);
				setF32ValueAt(this.vIdx + 9, barThreshU);

				setF32ValueAt(this.vIdx + 10, w + xBase);
				setF32ValueAt(this.vIdx + 11, -h + yBase);
				setF32ValueAt(this.vIdx + 12, hpBarU + scaledBarW);
				setF32ValueAt(this.vIdx + 13, hpBarV);

				setF32ValueAt(this.vIdx + 14, texelW);
				setF32ValueAt(this.vIdx + 15, texelH);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 0);
				setF32ValueAt(this.vIdx + 18, 0);
				setF32ValueAt(this.vIdx + 19, barThreshU);

				setF32ValueAt(this.vIdx + 20, -w + xBase);
				setF32ValueAt(this.vIdx + 21, h + yBase);
				setF32ValueAt(this.vIdx + 22, hpBarU);
				setF32ValueAt(this.vIdx + 23, hpBarV + scaledBarH);

				setF32ValueAt(this.vIdx + 24, texelW);
				setF32ValueAt(this.vIdx + 25, texelH);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 0);
				setF32ValueAt(this.vIdx + 28, 0);
				setF32ValueAt(this.vIdx + 29, barThreshU);

				setF32ValueAt(this.vIdx + 30, w + xBase);
				setF32ValueAt(this.vIdx + 31, h + yBase);
				setF32ValueAt(this.vIdx + 32, hpBarU + scaledBarW);
				setF32ValueAt(this.vIdx + 33, hpBarV + scaledBarH);

				setF32ValueAt(this.vIdx + 34, texelW);
				setF32ValueAt(this.vIdx + 35, texelH);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 0);
				setF32ValueAt(this.vIdx + 38, 0);
				setF32ValueAt(this.vIdx + 39, barThreshU);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;

				yPos += 20;
			}

			if (player.mp >= 0 && player.mp < player.maxMP) {
				var scaledBarW: Float32 = mpBarW / Main.ATLAS_WIDTH;
				var scaledBarH: Float32 = mpBarH / Main.ATLAS_HEIGHT;
				var barThreshU: Float32 = mpBarU + scaledBarW;
				barThreshU *= (player.mp / player.maxMP) * (1 - 4/24) + (player.mp / player.maxMP) * (2/24); // account for decor
				w = mpBarW * RenderUtils.clipSpaceScaleX;
				h = mpBarH * RenderUtils.clipSpaceScaleY;
				yBase = (screenY + yPos - (mpBarH / 2 - Main.PADDING)) * RenderUtils.clipSpaceScaleY;
				texelW = 0.5 / Main.ATLAS_WIDTH;
				texelH = 0.5 / Main.ATLAS_HEIGHT;

				setF32ValueAt(this.vIdx, -w + xBase);
				setF32ValueAt(this.vIdx + 1, -h + yBase);
				setF32ValueAt(this.vIdx + 2, emptyBarU);
				setF32ValueAt(this.vIdx + 3, emptyBarV);

				setF32ValueAt(this.vIdx + 4, texelW);
				setF32ValueAt(this.vIdx + 5, texelH);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 0);
				setF32ValueAt(this.vIdx + 8, 0);
				setF32ValueAt(this.vIdx + 9, -1);

				setF32ValueAt(this.vIdx + 10, w + xBase);
				setF32ValueAt(this.vIdx + 11, -h + yBase);
				setF32ValueAt(this.vIdx + 12, emptyBarU + scaledEmptyBarW);
				setF32ValueAt(this.vIdx + 13, emptyBarV);

				setF32ValueAt(this.vIdx + 14, texelW);
				setF32ValueAt(this.vIdx + 15, texelH);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 0);
				setF32ValueAt(this.vIdx + 18, 0);
				setF32ValueAt(this.vIdx + 19, -1);

				setF32ValueAt(this.vIdx + 20, -w + xBase);
				setF32ValueAt(this.vIdx + 21, h + yBase);
				setF32ValueAt(this.vIdx + 22, emptyBarU);
				setF32ValueAt(this.vIdx + 23, emptyBarV + scaledEmptyBarH);

				setF32ValueAt(this.vIdx + 24, texelW);
				setF32ValueAt(this.vIdx + 25, texelH);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 0);
				setF32ValueAt(this.vIdx + 28, 0);
				setF32ValueAt(this.vIdx + 29, -1);

				setF32ValueAt(this.vIdx + 30, w + xBase);
				setF32ValueAt(this.vIdx + 31, h + yBase);
				setF32ValueAt(this.vIdx + 32, emptyBarU + scaledEmptyBarW);
				setF32ValueAt(this.vIdx + 33, emptyBarV + scaledEmptyBarH);

				setF32ValueAt(this.vIdx + 34, texelW);
				setF32ValueAt(this.vIdx + 35, texelH);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 0);
				setF32ValueAt(this.vIdx + 38, 0);
				setF32ValueAt(this.vIdx + 39, -1);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;

				setF32ValueAt(this.vIdx, -w + xBase);
				setF32ValueAt(this.vIdx + 1, -h + yBase);
				setF32ValueAt(this.vIdx + 2, mpBarU);
				setF32ValueAt(this.vIdx + 3, mpBarV);

				setF32ValueAt(this.vIdx + 4, texelW);
				setF32ValueAt(this.vIdx + 5, texelH);
				setF32ValueAt(this.vIdx + 6, 0);
				setF32ValueAt(this.vIdx + 7, 0);
				setF32ValueAt(this.vIdx + 8, 0);
				setF32ValueAt(this.vIdx + 9, barThreshU);

				setF32ValueAt(this.vIdx + 10, w + xBase);
				setF32ValueAt(this.vIdx + 11, -h + yBase);
				setF32ValueAt(this.vIdx + 12, mpBarU + scaledBarW);
				setF32ValueAt(this.vIdx + 13, mpBarV);

				setF32ValueAt(this.vIdx + 14, texelW);
				setF32ValueAt(this.vIdx + 15, texelH);
				setF32ValueAt(this.vIdx + 16, 0);
				setF32ValueAt(this.vIdx + 17, 0);
				setF32ValueAt(this.vIdx + 18, 0);
				setF32ValueAt(this.vIdx + 19, barThreshU);

				setF32ValueAt(this.vIdx + 20, -w + xBase);
				setF32ValueAt(this.vIdx + 21, h + yBase);
				setF32ValueAt(this.vIdx + 22, mpBarU);
				setF32ValueAt(this.vIdx + 23, mpBarV + scaledBarH);

				setF32ValueAt(this.vIdx + 24, texelW);
				setF32ValueAt(this.vIdx + 25, texelH);
				setF32ValueAt(this.vIdx + 26, 0);
				setF32ValueAt(this.vIdx + 27, 0);
				setF32ValueAt(this.vIdx + 28, 0);
				setF32ValueAt(this.vIdx + 29, barThreshU);

				setF32ValueAt(this.vIdx + 30, w + xBase);
				setF32ValueAt(this.vIdx + 31, h + yBase);
				setF32ValueAt(this.vIdx + 32, mpBarU + scaledBarW);
				setF32ValueAt(this.vIdx + 33, mpBarV + scaledBarH);

				setF32ValueAt(this.vIdx + 34, texelW);
				setF32ValueAt(this.vIdx + 35, texelH);
				setF32ValueAt(this.vIdx + 36, 0);
				setF32ValueAt(this.vIdx + 37, 0);
				setF32ValueAt(this.vIdx + 38, 0);
				setF32ValueAt(this.vIdx + 39, barThreshU);
				this.vIdx += 40;

				final i4 = this.i * 4;
				setI32ValueAt(this.iIdx, i4);
				setI32ValueAt(this.iIdx + 1, 1 + i4);
				setI32ValueAt(this.iIdx + 2, 2 + i4);
				setI32ValueAt(this.iIdx + 3, 2 + i4);
				setI32ValueAt(this.iIdx + 4, 1 + i4);
				setI32ValueAt(this.iIdx + 5, 3 + i4);
				this.iIdx += 6;
				this.i++;

				yPos += 20;
			}
		}

		if (player.condition > 0) {
			var len = 0;
			for (i in 0...32)
				if (player.condition & (1 << i) != 0)
					len++;

			len >>= 1;

			var idx = 0;
			for (i in 0...32)
				if (player.condition & (1 << i) != 0) {
					var rect = ConditionEffect.effectRects[i];
					if (rect == null)
						continue;

					var scaledW: Float32 = rect.width / Main.ATLAS_WIDTH;
					var scaledH: Float32 = rect.height / Main.ATLAS_HEIGHT;
					var scaledU: Float32 = rect.x / Main.ATLAS_WIDTH;
					var scaledV: Float32 = rect.y / Main.ATLAS_HEIGHT;
					w = rect.width * RenderUtils.clipSpaceScaleX * 0.5;
					h = rect.height * RenderUtils.clipSpaceScaleY * 0.5;
					xBase = (screenX - rect.width * len + idx * rect.width) * RenderUtils.clipSpaceScaleX;
					yBase = (screenY + yPos + 5 - (rect.height / 2 - Main.PADDING)) * RenderUtils.clipSpaceScaleY;
					texelW = 1 / Main.ATLAS_WIDTH;
					texelH = 1 / Main.ATLAS_HEIGHT;

					setF32ValueAt(this.vIdx, -w + xBase);
					setF32ValueAt(this.vIdx + 1, -h + yBase);
					setF32ValueAt(this.vIdx + 2, scaledU);
					setF32ValueAt(this.vIdx + 3, scaledV);

					setF32ValueAt(this.vIdx + 4, texelW);
					setF32ValueAt(this.vIdx + 5, texelH);
					setF32ValueAt(this.vIdx + 6, 0);
					setF32ValueAt(this.vIdx + 7, 0);
					setF32ValueAt(this.vIdx + 8, 0);
					setF32ValueAt(this.vIdx + 9, -1);

					setF32ValueAt(this.vIdx + 10, w + xBase);
					setF32ValueAt(this.vIdx + 11, -h + yBase);
					setF32ValueAt(this.vIdx + 12, scaledU + scaledW);
					setF32ValueAt(this.vIdx + 13, scaledV);

					setF32ValueAt(this.vIdx + 14, texelW);
					setF32ValueAt(this.vIdx + 15, texelH);
					setF32ValueAt(this.vIdx + 16, 0);
					setF32ValueAt(this.vIdx + 17, 0);
					setF32ValueAt(this.vIdx + 18, 0);
					setF32ValueAt(this.vIdx + 19, -1);

					setF32ValueAt(this.vIdx + 20, -w + xBase);
					setF32ValueAt(this.vIdx + 21, h + yBase);
					setF32ValueAt(this.vIdx + 22, scaledU);
					setF32ValueAt(this.vIdx + 23, scaledV + scaledH);

					setF32ValueAt(this.vIdx + 24, texelW);
					setF32ValueAt(this.vIdx + 25, texelH);
					setF32ValueAt(this.vIdx + 26, 0);
					setF32ValueAt(this.vIdx + 27, 0);
					setF32ValueAt(this.vIdx + 28, 0);
					setF32ValueAt(this.vIdx + 29, -1);

					setF32ValueAt(this.vIdx + 30, w + xBase);
					setF32ValueAt(this.vIdx + 31, h + yBase);
					setF32ValueAt(this.vIdx + 32, scaledU + scaledW);
					setF32ValueAt(this.vIdx + 33, scaledV + scaledH);

					setF32ValueAt(this.vIdx + 34, texelW);
					setF32ValueAt(this.vIdx + 35, texelH);
					setF32ValueAt(this.vIdx + 36, 0);
					setF32ValueAt(this.vIdx + 37, 0);
					setF32ValueAt(this.vIdx + 38, 0);
					setF32ValueAt(this.vIdx + 39, -1);
					this.vIdx += 40;

					final i4 = this.i * 4;
					setI32ValueAt(this.iIdx, i4);
					setI32ValueAt(this.iIdx + 1, 1 + i4);
					setI32ValueAt(this.iIdx + 2, 2 + i4);
					setI32ValueAt(this.iIdx + 3, 2 + i4);
					setI32ValueAt(this.iIdx + 4, 1 + i4);
					setI32ValueAt(this.iIdx + 5, 3 + i4);
					this.iIdx += 6;
					this.i++;
					idx++;
				}
		}

		if (player.name != null && player.name != "") {
			if (player.nameTex == null) {
				player.nameText = new SimpleText(16, player.isFellowGuild ? Settings.FELLOW_GUILD_COLOR : Settings.DEFAULT_COLOR);
				player.nameText.setBold(true);
				player.nameText.text = player.name;
				player.nameText.updateMetrics();

				player.nameTex = new BitmapData(Std.int(player.nameText.width + 20), 64, true, 0);
				player.nameTex.draw(player.nameText, new Matrix(1, 0, 0, 1, 12, 0));
				player.nameTex.applyFilter(player.nameTex, player.nameTex.rect, new Point(0, 0), new GlowFilter(0, 1, 3, 3, 2, 1));
			}
			
			var textureData = TextureFactory.make(player.nameTex);
			this.rdSingle.push({cosX: textureData.width * RenderUtils.clipSpaceScaleX, 
				sinX: 0, sinY: 0,
				cosY: textureData.height * RenderUtils.clipSpaceScaleY,
				x: screenX * RenderUtils.clipSpaceScaleX, y: (screenY - hBase + 30 + (sink - 1) * hBase / 3) * RenderUtils.clipSpaceScaleY,
				texelW: 0, texelH: 0,
				texture: textureData.texture});
		}
	}

	@:nonVirtual private final #if !tracing inline #end function drawProjectile(time: Int32, proj: Projectile) {
		var screenX = proj.mapX * Camera.cos + proj.mapY * Camera.sin + Camera.csX;
		var screenY = proj.mapX * -Camera.sin + proj.mapY * Camera.cos + Camera.csY;

		var texW = proj.width * Main.ATLAS_WIDTH,
			texH = proj.height * Main.ATLAS_HEIGHT;

		final size = Camera.SIZE_MULT * proj.size;
		final w = size * texW;
		final h = size * texH;
		final yBase = (screenY - (h / 2 - size * Main.PADDING)) * RenderUtils.clipSpaceScaleY;
		final xBase = screenX * RenderUtils.clipSpaceScaleX;
		final texelW = 2 / Main.ATLAS_WIDTH / size;
		final texelH = 2 / Main.ATLAS_HEIGHT / size;
		final rotation = proj.props.rotation;
		final angle = proj.getDirectionAngle(time) + proj.props.angleCorrection + (rotation == 0 ? 0 : time / rotation) - Camera.angleRad;
		final cosAngle = MathUtil.cos(angle);
		final sinAngle = MathUtil.sin(angle);
		final xScaledCos = cosAngle * w * RenderUtils.clipSpaceScaleX * 0.5;
		final xScaledSin = sinAngle * h * RenderUtils.clipSpaceScaleX * 0.5;
		final yScaledCos = cosAngle * w * RenderUtils.clipSpaceScaleY * 0.5;
		final yScaledSinInv = -sinAngle * h * RenderUtils.clipSpaceScaleY * 0.5;

		setF32ValueAt(this.vIdx, -xScaledCos + xScaledSin + xBase);
		setF32ValueAt(this.vIdx + 1, yScaledSinInv + -yScaledCos + yBase);
		setF32ValueAt(this.vIdx + 2, proj.uValue);
		setF32ValueAt(this.vIdx + 3, proj.vValue);

		setF32ValueAt(this.vIdx + 4, texelW);
		setF32ValueAt(this.vIdx + 5, texelH);
		setF32ValueAt(this.vIdx + 6, 0);
		setF32ValueAt(this.vIdx + 7, 0);
		setF32ValueAt(this.vIdx + 8, 0);
		setF32ValueAt(this.vIdx + 9, -1);

		setF32ValueAt(this.vIdx + 10, xScaledCos + xScaledSin + xBase);
		setF32ValueAt(this.vIdx + 11, -(yScaledSinInv + yScaledCos) + yBase);
		setF32ValueAt(this.vIdx + 12, proj.uValue + proj.width);
		setF32ValueAt(this.vIdx + 13, proj.vValue);

		setF32ValueAt(this.vIdx + 14, texelW);
		setF32ValueAt(this.vIdx + 15, texelH);
		setF32ValueAt(this.vIdx + 16, 0);
		setF32ValueAt(this.vIdx + 17, 0);
		setF32ValueAt(this.vIdx + 18, 0);
		setF32ValueAt(this.vIdx + 19, -1);

		setF32ValueAt(this.vIdx + 20, -(xScaledCos + xScaledSin) + xBase);
		setF32ValueAt(this.vIdx + 21, yScaledSinInv + yScaledCos + yBase);
		setF32ValueAt(this.vIdx + 22, proj.uValue);
		setF32ValueAt(this.vIdx + 23, proj.vValue + proj.height);

		setF32ValueAt(this.vIdx + 24, texelW);
		setF32ValueAt(this.vIdx + 25, texelH);
		setF32ValueAt(this.vIdx + 26, 0);
		setF32ValueAt(this.vIdx + 27, 0);
		setF32ValueAt(this.vIdx + 28, 0);
		setF32ValueAt(this.vIdx + 29, -1);

		setF32ValueAt(this.vIdx + 30, xScaledCos + -xScaledSin + xBase);
		setF32ValueAt(this.vIdx + 31, -yScaledSinInv + yScaledCos + yBase);
		setF32ValueAt(this.vIdx + 32, proj.uValue + proj.width);
		setF32ValueAt(this.vIdx + 33, proj.vValue + proj.height);

		setF32ValueAt(this.vIdx + 34, texelW);
		setF32ValueAt(this.vIdx + 35, texelH);
		setF32ValueAt(this.vIdx + 36, 0);
		setF32ValueAt(this.vIdx + 37, 0);
		setF32ValueAt(this.vIdx + 38, 0);
		setF32ValueAt(this.vIdx + 39, -1);
		this.vIdx += 40;

		final i4 = this.i * 4;
		setI32ValueAt(this.iIdx, i4);
		setI32ValueAt(this.iIdx + 1, 1 + i4);
		setI32ValueAt(this.iIdx + 2, 2 + i4);
		setI32ValueAt(this.iIdx + 3, 2 + i4);
		setI32ValueAt(this.iIdx + 4, 1 + i4);
		setI32ValueAt(this.iIdx + 5, 3 + i4);
		this.iIdx += 6;
		this.i++;
	}

	@:nonVirtual private inline function setF32ValueAt(index: Int32, value: Float32): Void {
		return untyped __cpp__('_f32Arr_[{0}] = {1}', index, value);
	}

	@:nonVirtual private inline function setI32ValueAt(index: Int32, value: Int32): Void {
		return untyped __cpp__('_i32Arr_[{0}] = {1}', index, value);
	}

	@:nonVirtual private inline function getF32Pointer() {
		return untyped __cpp__('(uintptr_t)_f32Arr_');
	}

	@:nonVirtual private inline function getI32Pointer() {
		return untyped __cpp__('(uintptr_t)_i32Arr_');
	}

	@:nonVirtual public final function draw(time: Int32) {
		var camX = Camera.mapX, camY = Camera.mapY;
		if (time - this.lastTileUpdate > TILE_UPDATE_MS && camX >= 0 && camY >= 0) {
			var xMin = Std.int(Math.max(0, camX - Camera.maxDist)),
				xMax = Std.int(Math.min(this.mapWidth, camX + Camera.maxDist));
			var yMin = Std.int(Math.max(0, camY - Camera.maxDist)),
				yMax = Std.int(Math.min(this.mapHeight, camY + Camera.maxDist));

			var visIdx: UInt16 = 0;
			for (x in xMin...xMax)
				for (y in yMin...yMax) {
					var dx: Float32 = camX - x - 0.5;
					var dy: Float32 = camY - y - 0.5;
					if (dx * dx + dy * dy > Camera.maxDistSq)
						continue;

					var square = this.squares[x + y * mapWidth];
					if (square == null)
						continue;

					this.visSquares[visIdx++] = square;
					#if debug
					if (visIdx > MAX_VISIBLE_SQUARES)
						throw new Exception("Client sees more tiles than it should");
					#end
					square.lastVisible = time + TILE_UPDATE_MS;
				}

			this.visSquareLen = visIdx;
			this.lastTileUpdate = time;
		}

		if (time - this.lastBufferUpdate > BUFFER_UPDATE_MS) {
			if (Main.stageWidth != this.lastWidth || Main.stageHeight != this.lastHeight) {
				this.c3d.configureBackBuffer(Main.stageWidth, Main.stageHeight, 0, false);

				this.lastWidth = Main.stageWidth;
				this.lastHeight = Main.stageHeight;
				RenderUtils.clipSpaceScaleX = 2 / Main.stageWidth;
				RenderUtils.clipSpaceScaleY = 2 / Main.stageHeight;
			}

			this.lastBufferUpdate = time;
		}

		this.c3d.clear();
		this.rdSingle.resize(0);

		//GL.disable(GL.BLEND);
		GL.disable(GL.DEPTH_TEST);
		GL.disable(GL.SCISSOR_TEST);
		GL.disable(GL.STENCIL_TEST);

		GL.activeTexture(GL.TEXTURE0);
		GL.bindTexture(GL.TEXTURE_2D, Main.atlas.texture);

		// this will break at 13k+ objects because of stack size... todo break into multiple batches
		var vSize = Std.int(Math.max(this.visSquareLen * 56, this.gameObjectsLen * 40));
		var iSize = Std.int(Math.max(this.visSquareLen * 6, this.gameObjectsLen * 6));
		untyped __cpp__('float _f32Arr_[{0}]', vSize);
		untyped __cpp__('int _i32Arr_[{0}]', iSize);

		this.i = this.vIdx = this.iIdx = 0;
		drawSquares(time);

		GL.useProgram(this.groundProgram);
		GL.uniform2f(cast 0, leftMaskU, leftMaskV);
		GL.uniform2f(cast 1, topMaskU, topMaskV);
		GL.uniform2f(cast 2, rightMaskU, rightMaskV);
		GL.uniform2f(cast 3, bottomMaskU, bottomMaskV);
		GL.bindVertexArray(this.groundVAO);

		GL.bindBuffer(GL.ARRAY_BUFFER, this.groundVBO);
		// think about 2x scaling factor... todo
		if (this.vIdx > this.groundVBOLen) {
			GL.bufferData(GL.ARRAY_BUFFER, this.vIdx * 4, getF32Pointer(), GL.DYNAMIC_DRAW);
			this.groundVBOLen = this.vIdx;
		} else
			GL.bufferSubData(GL.ARRAY_BUFFER, 0, this.vIdx * 4, getF32Pointer());

		GL.enableVertexAttribArray(0);
		GL.vertexAttribPointer(0, 4, GL.FLOAT, false, 56, 0);
		GL.enableVertexAttribArray(1);
		GL.vertexAttribPointer(1, 2, GL.FLOAT, false, 56, 16);
		GL.enableVertexAttribArray(2);
		GL.vertexAttribPointer(2, 2, GL.FLOAT, false, 56, 24);
		GL.enableVertexAttribArray(3);
		GL.vertexAttribPointer(3, 2, GL.FLOAT, false, 56, 32);
		GL.enableVertexAttribArray(4);
		GL.vertexAttribPointer(4, 2, GL.FLOAT, false, 56, 40);
		GL.enableVertexAttribArray(5);
		GL.vertexAttribPointer(5, 2, GL.FLOAT, false, 56, 48);

		GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.groundIBO);
		if (this.iIdx > this.groundIBOLen) {
			GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, this.iIdx * 4, getI32Pointer(), GL.DYNAMIC_DRAW);
			this.groundIBOLen = this.iIdx;
		} else
			GL.bufferSubData(GL.ELEMENT_ARRAY_BUFFER, 0, this.iIdx * 4, getI32Pointer());
		GL.drawElements(GL.TRIANGLES, this.iIdx, GL.UNSIGNED_INT, 0);

		if (this.gameObjectsLen == 0) {
			this.c3d.present();
			return;
		}

		this.i = this.vIdx = this.iIdx = 0;

		var i = 0;
		while (i < this.gameObjectsLen) {
			var obj = this.gameObjects.unsafeGet(i);
			obj.screenYNoZ = obj.mapX * -Camera.sin + obj.mapY * Camera.cos + Camera.csY;
			i++;
		}

		i = 0;

		this.gameObjects.sort((a: GameObject, b: GameObject) -> Std.int(a.screenYNoZ - b.screenYNoZ));

		while (i < this.gameObjectsLen) {
			var obj = this.gameObjects.unsafeGet(i);
			if (obj.curSquare?.lastVisible >= time) {
				switch (obj.objClass) {
					case "Wall":
						drawWall(time, obj);
					case "Player":
						drawPlayer(time, cast(obj, Player));
					case "Projectile":
						drawProjectile(time, cast(obj, Projectile));
					default:
						drawGameObject(time, obj);
				}
			}
				
			i++;
		}

		GL.blendEquation(GL.FUNC_ADD);
		GL.enable(GL.BLEND);
		GL.blendFunc(GL.SRC_ALPHA, GL.ONE_MINUS_SRC_ALPHA);
		switch (Settings.glowType) {
			case GlowType.None:
				GL.useProgram(this.defaultProgram);
			case GlowType.Low:
				GL.useProgram(this.lowGlowProgram);
			case GlowType.Medium:
				GL.useProgram(this.medGlowProgram);
			case GlowType.High:
				GL.useProgram(this.highGlowProgram);
			case GlowType.VeryHigh:
				GL.useProgram(this.veryHighGlowProgram);
		}
		
		GL.bindVertexArray(this.objVAO);

		GL.bindBuffer(GL.ARRAY_BUFFER, this.objVBO);
		if (this.vIdx > this.objVBOLen) {
			GL.bufferData(GL.ARRAY_BUFFER, this.vIdx * 4, getF32Pointer(), GL.DYNAMIC_DRAW);
			this.objVBOLen = this.vIdx;
		} else
			GL.bufferSubData(GL.ARRAY_BUFFER, 0, this.vIdx * 4, getF32Pointer());

		GL.enableVertexAttribArray(0);
		GL.vertexAttribPointer(0, 4, GL.FLOAT, false, 40, 0);
		GL.enableVertexAttribArray(1);
		GL.vertexAttribPointer(1, 2, GL.FLOAT, false, 40, 16);
		GL.enableVertexAttribArray(2);
		GL.vertexAttribPointer(2, 2, GL.FLOAT, false, 40, 24);
		GL.enableVertexAttribArray(3);
		GL.vertexAttribPointer(3, 1, GL.FLOAT, false, 40, 32);
		GL.enableVertexAttribArray(4);
		GL.vertexAttribPointer(4, 1, GL.FLOAT, false, 40, 36);

		GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.objIBO);
		if (this.iIdx > this.objIBOLen) {
			GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, this.iIdx * 4, getI32Pointer(), GL.DYNAMIC_DRAW);
			this.objIBOLen = this.iIdx;
		} else
			GL.bufferSubData(GL.ELEMENT_ARRAY_BUFFER, 0, this.iIdx * 4, getI32Pointer());

		GL.drawElements(GL.TRIANGLES, iIdx, GL.UNSIGNED_INT, 0);

		for (sb in this.speechBalloons) {
			if (sb.disposed || sb.go?.map == null)
				continue;
			
			var dt = time - sb.startTime;
			if (dt > sb.lifetime) {
				sb.disposed = true;
				continue;
			}

			var textureData: GLTextureData;
			switch (sb.sbType) {
				case SpeechBalloon.MESSAGE_BUBBLE:
					textureData = TextureFactory.make(tellBalloonTex);
				case SpeechBalloon.GUILD_BUBBLE:
					textureData = TextureFactory.make(guildBalloonTex);
				case SpeechBalloon.ENEMY_BUBBLE:
					textureData = TextureFactory.make(enemyBalloonTex);
				case SpeechBalloon.PARTY_BUBBLE:
					textureData = TextureFactory.make(partyBalloonTex);
				case SpeechBalloon.ADMIN_BUBBLE:
					textureData = TextureFactory.make(adminBalloonTex);
				default:
					textureData = TextureFactory.make(normalBalloonTex);
			}

			var alpha = 1.0;
			if (dt < 333)
				alpha = -(MathUtil.cos(dt / 333 * MathUtil.PI) - 1) / 2;
			else if (dt > sb.lifetime - 333)
				alpha = -(MathUtil.cos((1 - (dt - sb.lifetime + 333) / 333) * MathUtil.PI) - 1) / 2;

			this.rdSingle.push({cosX: (textureData.width << 2) * RenderUtils.clipSpaceScaleX, 
				sinX: 0, sinY: 0,
				cosY: (textureData.height << 2) * RenderUtils.clipSpaceScaleY,
				x: (sb.go.screenX + 45) * RenderUtils.clipSpaceScaleX, y: (sb.go.screenYNoZ - sb.go.hBase - 40) * RenderUtils.clipSpaceScaleY,
				texelW: 0, texelH: 0,
				texture: textureData.texture, alpha: alpha});

			var textureData = TextureFactory.make(sb.textTex);
			this.rdSingle.push({cosX: textureData.width * RenderUtils.clipSpaceScaleX, 
				sinX: 0, sinY: 0,
				cosY: textureData.height * RenderUtils.clipSpaceScaleY,
				x: (sb.go.screenX + 42) * RenderUtils.clipSpaceScaleX, y:  (sb.go.screenYNoZ - sb.go.hBase - 33 - (sb.numLines * 6)) * RenderUtils.clipSpaceScaleY,
				texelW: 0, texelH: 0,
				texture: textureData.texture, alpha: alpha});	
		}

		for (st in this.statusTexts) {
			if (st.disposed || st.go?.map == null)
				continue;

			var dt = time - st.startTime;
			if (dt > st.lifetime) {
				st.disposed = true;
				continue;
			}

			var frac = dt / st.lifetime;
			var scale = Math.min(1, Math.max(0.7, 1 - frac * 0.3 + 0.075));
			var textureData = TextureFactory.make(st.textTex);
			this.rdSingle.push({cosX: textureData.width * scale * RenderUtils.clipSpaceScaleX, 
				sinX: 0, sinY: 0,
				cosY: textureData.height * scale * RenderUtils.clipSpaceScaleY,
				x: (st.go.screenX + st.xOffset) * RenderUtils.clipSpaceScaleX, y:  (st.go.screenYNoZ + st.yOffset - st.go.hBase - frac * CharacterStatusText.MAX_DRIFT) * RenderUtils.clipSpaceScaleY,
				texelW: 0, texelH: 0,
				texture: textureData.texture, alpha: 1 - frac + 0.33});
		}

		i = 0;
		var rdsLen = this.rdSingle.length;
		if (rdsLen > 0) {
			RenderUtils.bindVertexBuffer(0, this.singleVBO);
			GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.singleIBO);
			GL.useProgram(this.singleProgram);
		}

		while (i < rdsLen) {
			var rd = this.rdSingle[i];
			GL.uniform4f(cast 0, rd.cosX, rd.sinX, rd.sinY, rd.cosY);
			GL.uniform2f(cast 1, rd.x, rd.y);
			GL.uniform2f(cast 2, rd.texelW, rd.texelH);
			GL.uniform1f(cast 3, rd.alpha);
			GL.bindTexture(GL.TEXTURE_2D, rd.texture);
			GL.drawElements(GL.TRIANGLES, 6, GL.UNSIGNED_SHORT, 0);
			i++;
		}

		this.c3d.present();
	}
}
