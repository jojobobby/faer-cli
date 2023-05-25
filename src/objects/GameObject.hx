package objects;

import openfl.display.Bitmap;
import network.NetworkHandler;
import util.Utils;
import lime.system.System;
import lime.graphics.opengl.GL;
import engine.TextureFactory;
import map.Camera;
import map.CharacterStatusText;
import map.Map;
import map.Square;
import objects.animation.Animations;
import objects.animation.AnimationsData;
import openfl.display.BitmapData;
import openfl.filters.GlowFilter;
import openfl.geom.Point;
import openfl.geom.Vector3D;
import sound.SoundEffectLibrary;
import ui.SimpleText;
import util.AnimatedChar;
import util.BitmapUtil;
import util.BloodComposition;
import util.ConditionEffect;
import util.GlowRedrawer;
import util.MaskedImage;
import util.Utils;
import util.NativeTypes;
import util.TextureRedrawer;

using util.Utils;

class GameObject {
	public static inline var ZERO_LIMIT: Float32 = 0.00001;
	public static inline var NEGATIVE_ZERO_LIMIT: Float32 = -ZERO_LIMIT;
	public static inline var ATTACK_PERIOD: Int32 = 300;

	public var map: Map;
	public var curSquare: Square;
	public var objectId: Int32 = 0;
	public var mapX: Float32 = 0.0;
	public var mapY: Float32 = 0.0;
	public var mapZ: Float32 = 0.0;
	public var screenX: Float32 = 0.0;
	public var screenY: Float32 = 0.0;
	public var screenYNoZ: Float32 = 0.0;
	public var hBase: Float32 = 0.0;
	public var sortVal: Int16 = 0;
	public var props: ObjectProperties;
	public var name = "";
	public var facing: Float32 = 0.0;
	public var flying = false;
	public var floatFlip = false;
	public var lastFloatUpdate = -1;
	public var attackAngle: Float32 = 0.0;
	public var attackStart = 0;
	public var animatedChar: AnimatedChar = null;
	public var uValue: Float32 = 0.0;
	public var vValue: Float32 = 0.0;
	public var topUValue: Float32 = 0.0;
	public var topVValue: Float32 = 0.0;
	public var width: Float32 = 0.0;
	public var height: Float32 = 0.0;
	public var maskUValue: Float32 = 0.0;
	public var maskVValue: Float32 = 0.0;
	public var maskWidth: Float32 = 0.0;
	public var maskHeight: Float32 = 0.0;
	public var randomTextureData: Array<TextureData> = null;
	public var animations: Animations = null;
	public var dead = false;
	public var maxHP = 200;
	public var hp = 200;
	public var size: Float32 = 1;
	public var defense = 0;
	public var resistance = 0;
	public var slotTypes: Array<Int32> = null;
	public var equipment: Array<Int32> = null;
	public var condition = 0;
	public var isInteractive = false;
	public var objectType = 0;
	public var sinkLevel: Float32 = 0.0;
	public var flashStartTime: Float32 = 0.0;
	public var flashPeriodMs: Float32 = 0.0;
	public var flashRepeats: Float32 = 0.0;
	public var flashColor: Float32 = 0.0;
	public var glowColor: Float32 = 0.0;
	public var nameText: SimpleText = null;
	public var nameTex: BitmapData = null;
	public var enterTex: BitmapData = null;
	public var enterKeyTex: BitmapData = null;
	public var isLoot = false;
	public var ownerId = -1;
	public var hpBar: Bitmap;
	public var objClass = "";

	private var portrait: BitmapData = null;
	private var myLastTickId: Int32 = -1;
	private var posAtTick: Point;
	private var tickPosition: Point;
	private var lastTickUpdateTime: Int32 = 0;

	public var moveVec: Vector3D;
	public var yBase: Float32 = 0.0;
	public var yBaseNoZ: Float32 = 0.0;

	private var nextBulletId: Int8 = 1;
	private var sizeMult: Float32 = 1.0;

	public var icons: Array<BitmapData> = null;

	private var floatTimeOffset: Int32 = 0;

	public var w: Float32 = 0.0;
	public var h: Float32 = 0.0;
	public var dh: Float32 = 0.0;

	private var mapColor: UInt32 = 0;
	private var bloodColors: Array<UInt32> = null;

	public static function physicalDamage(dmg: Int, def: Int, cond: Int) {
		if ((cond & ConditionEffect.INVULNERABLE_BIT) != 0)
			return 0;

		if ((cond & ConditionEffect.ARMOR_BROKEN_BIT) != 0)
			return dmg;

		if ((cond & ConditionEffect.ARMORED_BIT) != 0)
			return Std.int(dmg - def * 1.25);

		return dmg - def;
	}

	public static function magicDamage(dmg: Int, res: Int, cond: Int) {
		if ((cond & ConditionEffect.INVULNERABLE_BIT) != 0)
			return 0;

		if ((cond & ConditionEffect.ARMOR_BROKEN_BIT) != 0)
			return dmg;

		return dmg - res;
	}

	public static function trueDamage(dmg: Int, cond: Int) {
		if ((cond & ConditionEffect.INVULNERABLE_BIT) != 0)
			return 0;

		return dmg;
	}

	public function new(objectXML: Xml, objClass: String) {
		this.props = ObjectLibrary.defaultProps;
		this.objClass = objClass;
		this.posAtTick = new Point();
		this.tickPosition = new Point();
		this.moveVec = new Vector3D();
		if (objectXML == null)
			return;

		this.objectType = objectXML.intAttribute("type");
		this.props = ObjectLibrary.propsLibrary.get(this.objectType);
		this.size = this.props.getSize() / 100;
		var textureData = ObjectLibrary.typeToTextureData.get(this.objectType);
		this.mapColor = BitmapUtil.mostCommonColor(textureData.texture);
		this.bloodColors = BloodComposition.getBloodComposition(this.objectType, textureData.texture, this.props.bloodProb, this.props.bloodColor);
		this.uValue = textureData.uValue;
		this.vValue = textureData.vValue;
		this.width = textureData.width;
		this.height = textureData.height;
		this.maskUValue = textureData.maskUValue;
		this.maskVValue = textureData.maskVValue;
		this.maskWidth = textureData.maskWidth;
		this.maskHeight = textureData.maskHeight;
		this.animatedChar = textureData.animatedChar;
		this.randomTextureData = textureData.randomTextureData;
		if (ObjectLibrary.typeToTopTextureData.exists(this.objectType)) {
			var topTextureData = ObjectLibrary.typeToTopTextureData.get(this.objectType);
			var topRandTexData = topTextureData.randomTextureData;
			if (topRandTexData != null) {
				var randTex = topRandTexData[
					Math.floor(Math.random() * this.randomTextureData.length)
				];
				this.topUValue = randTex.uValue;
				this.topVValue = randTex.vValue;
			} else {
				this.topUValue = topTextureData.uValue;
				this.topVValue = topTextureData.vValue;
			}
			
		}

		this.sizeMult = this.width == 0 ? 1 : this.width * (Main.ATLAS_WIDTH / 8);

		var animationsData = ObjectLibrary.typeToAnimationsData.get(this.objectType);
		if (animationsData != null)
			this.animations = new Animations(animationsData);

		mapZ = this.props.baseZ;
		this.flying = this.props.flying;
		this.hp = this.maxHP = objectXML.intElement("Health");
		this.defense = objectXML.intElement("Defense");
		this.resistance = objectXML.intElement("Resistance");
		this.slotTypes = objectXML.intListElement("SlotTypes");
		this.equipment = new Array<Int32>();
		for (i in 0...20)
			this.equipment.push(-1);

		if (this.props.showName || objClass == "Portal")
			this.name = this.props.displayId;
	}

	public function dispose() {
		this.map = null;
		this.curSquare = null;
		if (this.portrait != null) {
			this.portrait.dispose();
			this.portrait = null;
		}

		if (this.nameTex != null) {
			this.nameTex.dispose();
			this.nameTex = null;
		}
	}

	public function addTo(map: Map, x: Float32, y: Float32) {
		this.map = map;
		this.posAtTick.x = this.tickPosition.x = x;
		this.posAtTick.y = this.tickPosition.y = y;
		this.moveTo(x, y);

		/*var effLen = this.props != null && this.props.showEffects != null ? this.props.showEffects.length : 0;
			for (i in 0...effLen) {
				var eff = this.props.showEffects[i];
				switch (eff.effType) {
					case "Ring":
						this.map.addObj(new RingEffect(this, eff.radius, eff.color, eff.cooldown), this.mapX, this.mapY);
				}
		}*/

		if (this.props.floating)
			this.floatTimeOffset = Std.int(Math.random() * this.props.floatTime);

		return true;
	}

	public function removeFromMap() {
		if (this.props.staticObj && curSquare != null) {
			if (curSquare.obj == this)
				curSquare.obj = null;

			curSquare = null;
		}

		this.map = null;
		this.curSquare = null;
		this.dispose();
	}

	public function update(time: Int32, dt: Int16) {
		if (!(this.moveVec.x == 0 && this.moveVec.y == 0)) {
			if (this.myLastTickId < NetworkHandler.lastTickId) {
				this.moveVec.x = 0;
				this.moveVec.y = 0;
				this.moveTo(this.tickPosition.x, this.tickPosition.y);
			} else {
				var tickDT = time - this.lastTickUpdateTime;
				this.moveTo(this.posAtTick.x + tickDT * this.moveVec.x, this.posAtTick.y + tickDT * this.moveVec.y);
			}
		}

		if (this.objectId != this.map.player.objectId) {
			var scaleDt: Float32 = dt * 0.01;
			this.moveTo(scaleDt * this.tickPosition.x + (1 - scaleDt) * this.mapX, scaleDt * this.tickPosition.y + (1 - scaleDt) * this.mapY);
		}

		if (this.props.floating && time - this.lastFloatUpdate >= 16) {
			var floatTime = this.props.floatTime;
			var floatHeight = this.props.floatHeight;

			if (this.props.floatSine)
				this.mapZ = floatHeight / 2 * (MathUtil.sin((time + this.floatTimeOffset) / floatTime) + 1);
			else {
				this.mapZ = this.floatFlip ? this.mapZ - 0.00001 * floatTime : this.mapZ + 0.00001 * floatTime;
				if (this.mapZ >= floatHeight)
					this.floatFlip = true;
				if (this.mapZ <= 0)
					this.floatFlip = false;
			}

			this.lastFloatUpdate = time;
		}

		return true;
	}

	public function setObjectId(objId: Int32) {
		var textureData: TextureData = null;
		this.objectId = objId;
		if (this.randomTextureData != null) {
			textureData = this.randomTextureData[objId % this.randomTextureData.length];
			this.uValue = textureData.uValue;
			this.vValue = textureData.vValue;
			this.width = textureData.width;
			this.height = textureData.height;
			this.maskUValue = textureData.maskUValue;
			this.maskVValue = textureData.maskVValue;
			this.maskWidth = textureData.maskWidth;
			this.maskHeight = textureData.maskHeight;
			this.animatedChar = textureData.animatedChar;
		}
	}

	public function setAltTexture(altTextureId: Int32) {
		if (this.randomTextureData != null)
			return;

		var altTextureData: TextureData;
		var textureData = ObjectLibrary.typeToTextureData.get(this.objectType);
		if (altTextureId == 0)
			altTextureData = textureData;
		else {
			altTextureData = textureData.getAltTextureData(altTextureId);
			if (altTextureData == null)
				return;
		}

		this.uValue = altTextureData.uValue;
		this.vValue = altTextureData.vValue;
		this.width = altTextureData.width;
		this.height = altTextureData.height;
		this.maskUValue = altTextureData.maskUValue;
		this.maskVValue = altTextureData.maskVValue;
		this.maskWidth = altTextureData.maskWidth;
		this.maskHeight = altTextureData.maskHeight;
		this.animatedChar = altTextureData.animatedChar;
	}

	public function playSound(id: Int32) {
		SoundEffectLibrary.play(this.props.sounds.get(id));
	}

	public inline function isWeak() {
		return (this.condition & ConditionEffect.WEAK_BIT) != 0;
	}

	public inline function isSlowed() {
		return (this.condition & ConditionEffect.SLOWED_BIT) != 0;
	}

	public inline function isSick() {
		return (this.condition & ConditionEffect.SICK_BIT) != 0;
	}

	public inline function isSpeedy() {
		return (this.condition & ConditionEffect.SPEEDY_BIT) != 0;
	}

	public inline function isHealing() {
		return (this.condition & ConditionEffect.HEALING_BIT) != 0;
	}

	public inline function isDamaging() {
		return (this.condition & ConditionEffect.DAMAGING_BIT) != 0;
	}

	public inline function isInvulnerable() {
		return (this.condition & ConditionEffect.INVULNERABLE_BIT) != 0;
	}

	public inline function isArmored() {
		return (this.condition & ConditionEffect.ARMORED_BIT) != 0;
	}

	public inline function isArmorBroken() {
		return (this.condition & ConditionEffect.ARMOR_BROKEN_BIT) != 0;
	}

	public function getName() {
		return this.name == null || this.name == "" ? ObjectLibrary.typeToDisplayId.get(this.objectType) : this.name;
	}

	public function getColor() {
		return this.mapColor;
	}

	public function getBulletId(): Int8 {
		var ret = this.nextBulletId;
		++this.nextBulletId %= 128;
		return ret;
	}

	public function distTo(x: Float32, y: Float32) {
		var dx = x - mapX;
		var dy = y - mapY;
		return Math.sqrt(dx * dx + dy * dy);
	}

	public function moveTo(x: Float32, y: Float32) {
		var square = map.lookupSquare(Std.int(x), Std.int(y));
		mapX = x;
		mapY = y;
		if (this.props.staticObj) {
			if (curSquare != null)
				curSquare.obj = null;
			if (square != null)
				square.obj = this;
		}

		curSquare = square;
		return true;
	}

	public function onGoto(x: Float32, y: Float32, time: Int32) {
		this.moveTo(x, y);
		this.lastTickUpdateTime = time;
		this.tickPosition.x = x;
		this.tickPosition.y = y;
		this.posAtTick.x = x;
		this.posAtTick.y = y;
		this.moveVec.x = 0;
		this.moveVec.y = 0;
	}

	public function onTickPos(x: Float32, y: Float32, tickTime: Int32, tickId: Int32) {
		if (this.myLastTickId < NetworkHandler.lastTickId)
			this.moveTo(this.tickPosition.x, this.tickPosition.y);

		this.lastTickUpdateTime = Global.gameSprite.lastUpdate;
		this.tickPosition.x = x;
		this.tickPosition.y = y;
		this.posAtTick.x = mapX;
		this.posAtTick.y = mapY;
		this.moveVec.x = (this.tickPosition.x - this.posAtTick.x) / tickTime;
		this.moveVec.y = (this.tickPosition.y - this.posAtTick.y) / tickTime;
		this.myLastTickId = tickId;
	}

	public function damage(origType: Int32, damageAmount: Int32, effects: Array<Int32>, kill: Bool, proj: Projectile, textColor: UInt32 = 0xB02020) {
		if (kill)
			this.dead = true;
		else if (effects != null) {
			for (conditionEffect in effects) {
				var ce: ConditionEffect = null;
				switch (conditionEffect) {
					case ConditionEffect.WEAK:
					case ConditionEffect.SLOWED:
					case ConditionEffect.SICK:
					case ConditionEffect.SPEEDY:
					case ConditionEffect.BLEEDING:
					case ConditionEffect.ARMOR_BROKEN:
						ce = ConditionEffect.effects[conditionEffect];
						break;
				}

				if (ce != null && (this.condition | ce.bit) != this.condition) {
					this.condition |= ce.bit;
					map.addStatusText(new CharacterStatusText(this, ce.name, textColor, 750));
				}
			}
		}

		/*if (this.dead)
				map.addObj(new ExplosionEffect(this.bloodColors, this.size, 30), mapX, mapY);
			else if (proj != null)
				map.addObj(new HitEffect(this.bloodColors, this.size, 10, proj.angle, proj.projProps.realSpeed), mapX, mapY);
			else
				map.addObj(new ExplosionEffect(this.bloodColors,, this.size, 10), mapX, mapY); */

		if (damageAmount > 0)
			map.addStatusText(new CharacterStatusText(this, "-" + damageAmount, textColor, 750));
	}

	public function setAttack(containerType: Int32, attackAngle: Float32) {
		this.attackAngle = attackAngle;
		this.attackStart = System.getTimer();
	}
}
