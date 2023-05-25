package objects;

import network.NetworkHandler;
import lime.system.System;
import constants.ActivationType;
import constants.GeneralConstants;
import constants.UseType;
import game.model.VialModel;
import game.MoveRecords;
import map.Camera;
import map.Square;
import openfl.display.BitmapData;
import openfl.filters.GlowFilter;
import openfl.geom.Matrix;
import openfl.geom.Point;
import sound.SoundEffectLibrary;
import ui.model.TabStripModel;
import ui.SimpleText;
import util.AnimatedChar;
import util.GlowRedrawer;
import util.MaskedImage;
import util.Utils;
import util.NativeTypes;
import util.Settings;
import util.TextureRedrawer;

using util.Utils;

class Player extends GameObject {
	public static inline var MS_BETWEEN_TELEPORT: Int32 = 10000;
	private static inline var MOVE_THRESHOLD: Float32 = 0.4;
	private static inline var MIN_MOVE_SPEED: Float32 = 0.004;
	private static inline var MAX_MOVE_SPEED: Float32 = 0.0096;
	private static inline var MIN_STRENGTH_MULT: Float32 = 0.5;
	private static inline var MAX_STRENGTH_MULT: Float32 = 2.0;
	private static inline var MIN_WIT_MULT: Float32 = 0.5;
	private static inline var MAX_WIT_MULT: Float32 = 2.0;
	private static inline var ATTACK_FREQUENCY: Float32 = 0.005;
	private static var newP = new Point();
	private static var nameOffsetMatrix = new Matrix(1, 0, 0, 1, 12, 0);

	public var skinId = 0;
	public var skin: AnimatedChar;
	public var accountId = -1;
	public var gems = 0;
	public var gold = 0;
	public var crowns = 0;
	public var guildName = "";
	public var guildRank = -1;
	public var isFellowGuild = false;
	public var mp = 0;
	public var maxHPBoost = 0;
	public var maxHPMax = 0;
	public var maxMP = 200;
	public var maxMPBoost = 0;
	public var maxMPMax = 0;
	public var defenseBoost = 0;
	public var defenseMax = 0;
	public var resistanceBoost = 0;
	public var resistanceMax = 0;
	public var strength = 0;
	public var strengthBoost = 0;
	public var strengthMax = 0;
	public var wit = 0;
	public var witBoost = 0;
	public var witMax = 0;
	public var speed = 0;
	public var speedBoost = 0;
	public var speedMax = 0;
	public var haste = 0;
	public var hasteBoost = 0;
	public var hasteMax = 0;
	public var stamina = 0;
	public var staminaBoost = 0;
	public var staminaMax = 0;
	public var intelligence = 0;
	public var intelligenceBoost = 0;
	public var intelligenceMax = 0;
	public var piercing = 0;
	public var piercingBoost = 0;
	public var piercingMax = 0;
	public var penetration = 0;
	public var penetrationBoost = 0;
	public var penetrationMax = 0;
	public var tenacity = 0;
	public var tenacityBoost = 0;
	public var tenacityMax = 0;
	public var healthVialCount = 0;
	public var magicVialCount = 0;
	public var damageMult = 1.0;
	public var hitMult = 1.0;
	public var tier = 1;
	public var hasBackpack = false;
	public var locked = false;
	public var ignored = false;
	public var distSqFromThisPlayer = 0.0;
	public var attackPeriod = Std.int(1 / ATTACK_FREQUENCY);
	public var nextAltAttack = 0;
	public var nextTeleportAt = 0;
	public var isDefaultAnimatedChar = true;
	public var moveMultiplier = 1.0;
	public var hurtSound = "";
	public var deathSound = "";

	private var rotate = 0.0;
	private var relMoveVec: Point = null;
	private var lastAttackError = -1;
	private var needsBlinkingClear = false;
	private var objectXML: Xml;

	public static function fromPlayerXML(name: String, playerXML: Xml) {
		var player = new Player(ObjectLibrary.xmlLibrary.get(playerXML.intElement("ObjectType")));
		player.name = name;
		player.equipment = playerXML.intListElement("Equipment");
		for (i in 0...player.equipment.length)
			if (player.equipment[i] == 65535)
				player.equipment[i] = -1;
		player.maxHP = player.hp = playerXML.intElement("Health");
		player.maxMP = player.mp = playerXML.intElement("Mana");
		player.strength = playerXML.intElement("Strength");
		player.wit = playerXML.intElement("Wit");
		player.defense = playerXML.intElement("Defense");
		player.resistance = playerXML.intElement("Resistance");
		player.speed = playerXML.intElement("Speed");
		player.haste = playerXML.intElement("Haste");
		player.stamina = playerXML.intElement("Stamina");
		player.intelligence = playerXML.intElement("Intelligence");
		player.piercing = playerXML.intElement("Piercing");
		player.penetration = playerXML.intElement("Penetration");
		player.tenacity = playerXML.intElement("Tenacity");
		player.tier = playerXML.intElement("Tier");
		return player;
	}

	public function new(objectXML: Xml) {
		super(objectXML, "Player");
		this.hurtSound = objectXML.elementsNamed("HitSound")
			.hasNext() ? objectXML.elementsNamed("HitSound")
			.next()
			.firstChild()
			.nodeValue : "monster/default_hit";
		this.deathSound = objectXML.elementsNamed("DeathSound")
			.hasNext() ? objectXML.elementsNamed("DeathSound")
			.next()
			.firstChild()
			.nodeValue : "monster/default_death";
		this.tier = objectXML.intElement("Tier");
		this.objectXML = objectXML;
		this.updateMaxValues();
	}

	public function updateMaxValues() {
		this.maxHPMax = this.objectXML.elementsNamed("Health").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.maxMPMax = this.objectXML.elementsNamed("Mana").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.strengthMax = this.objectXML.elementsNamed("Strength").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.witMax = this.objectXML.elementsNamed("Wit").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.defenseMax = this.objectXML.elementsNamed("Defense").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.resistanceMax = this.objectXML.elementsNamed("Resistance").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.speedMax = this.objectXML.elementsNamed("Speed").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.hasteMax = this.objectXML.elementsNamed("Haste").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.staminaMax = this.objectXML.elementsNamed("Stamina").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.intelligenceMax = this.objectXML.elementsNamed("Intelligence").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.piercingMax = this.objectXML.elementsNamed("Piercing").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.penetrationMax = this.objectXML.elementsNamed("Penetration").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
		this.tenacityMax = this.objectXML.elementsNamed("Tenacity").next().intAttribute('t${this.tier > 0 ? this.tier : 1}');
	}

	override public function update(time: Int32, dt: Int16) {
		if (this.relMoveVec != null) {
			if (this.rotate != 0)
				Camera.angleRad = (Camera.angleRad + dt * Settings.PLAYER_ROTATE_SPEED * this.rotate) % (MathUtil.PI * 2);

			if (this.relMoveVec.x != 0 || this.relMoveVec.y != 0) {
				var moveSpeed = this.getMoveSpeed();
				var moveVecAngle = Math.atan2(this.relMoveVec.y, this.relMoveVec.x);
				moveVec.x = moveSpeed * MathUtil.cos(Camera.angleRad + moveVecAngle);
				moveVec.y = moveSpeed * MathUtil.sin(Camera.angleRad + moveVecAngle);
			} else {
				moveVec.x = 0;
				moveVec.y = 0;
			}

			if (curSquare != null && curSquare.props.push) {
				moveVec.x -= curSquare.props.animate.dx / 1000;
				moveVec.y -= curSquare.props.animate.dy / 1000;
			}
			this.walkTo(mapX + dt * moveVec.x, mapY + dt * moveVec.y);
		} else if (!super.update(time, dt))
			return false;

		if (map.player == this
			&& curSquare != null
			&& curSquare.props.damage > 0
			&& curSquare.lastDamage + 500 < time
			&& (curSquare.obj == null || !curSquare.obj.props.protectFromGroundDamage)) {
			var dmg = curSquare.props.damage;
			damage(-1, Std.int(dmg * this.hitMult), null, hp <= dmg, null);
			NetworkHandler.groundDamage(time, mapX, mapY);
			curSquare.lastDamage = time;
		}

		return true;
	}

	override public function damage(origType: Int32, damageAmount: Int32, effects: Array<Int32>, kill: Bool, proj: Projectile, textColor: UInt32 = 0xB02020) {
		super.damage(origType, damageAmount, effects, kill, proj, textColor);
		if (dead)
			SoundEffectLibrary.play(this.deathSound);
		else
			SoundEffectLibrary.play(this.hurtSound);
	}

	/*override public function draw(time: Int32) {
		if (hp < maxHP * 0.2) {
			if (this.flashPeriodMs == 0) {
				this.flashStartTime = System.getTimer();
				this.flashColor = 0x820000;
				this.flashRepeats = -1;
				this.flashPeriodMs = 1000;
				this.needsBlinkingClear = true;
			}
		} else if (this.needsBlinkingClear) {
			this.flashStartTime = this.flashColor = this.flashRepeats = this.flashPeriodMs = 0;
			this.needsBlinkingClear = true;
		}
	}*/

	public function getPortrait(sizeMult: Float32 = 1, animCharOverride: AnimatedChar = null) {
		var image: MaskedImage = null;
		var size = 0;
		if (portrait == null) {
			image = animCharOverride != null ? animCharOverride.imageFromDir(AnimatedChar.RIGHT, AnimatedChar.STAND,
				0) : animatedChar.imageFromDir(AnimatedChar.RIGHT, AnimatedChar.STAND, 0);
			size = Std.int(4 / image.image.width * 100 * sizeMult);
			portrait = TextureRedrawer.resize(image.image, size, true);
			portrait = GlowRedrawer.outlineGlow(portrait, 0);
		}

		return portrait;
	}

	public function setRelativeMovement(rotate: Float32, relMoveVecX: Float32, relMoveVecY: Float32) {
		if (this.relMoveVec == null)
			this.relMoveVec = new Point();

		this.rotate = rotate;
		this.relMoveVec.x = relMoveVecX;
		this.relMoveVec.y = relMoveVecY;
	}

	public function setGuildName(guildName: String) {
		var player: Player = null;
		var isFellowGuild = false;
		this.guildName = guildName;
		var myPlayer = map?.player;
		if (myPlayer == this)
			for (go in map.gameObjects) {
				if (go != null && go.props.isPlayer && go != this)
					cast(go, Player).setGuildName(cast(go, Player).guildName);
			}
		else {
			isFellowGuild = myPlayer != null && myPlayer.guildName != null && myPlayer.guildName != "" && myPlayer.guildName == this.guildName;
			if (isFellowGuild != this.isFellowGuild) {
				this.isFellowGuild = isFellowGuild;
				nameTex = null;
			}
		}
	}

	public function msUntilTeleport() {
		return Std.int(Math.max(0, this.nextTeleportAt - System.getTimer()));
	}

	public function teleportTo(player: Player) {
		var msUntil = this.msUntilTeleport();
		if (msUntil > 0) {
			Global.gameSprite.textBox.addText("You can not teleport for another " + Std.int(msUntil / 1000 + 1) + " seconds.", 0xFF0000);
			return false;
		}

		NetworkHandler.teleport(player.objectId);
		this.nextTeleportAt = System.getTimer() + MS_BETWEEN_TELEPORT;
		return true;
	}

	public function walkTo(x: Float32, y: Float32) {
		this.modifyMove(x, y, newP);
		return this.moveTo(newP.x, newP.y);
	}

	public function modifyMove(x: Float32, y: Float32, newP: Point) {
		var dx = x - mapX;
		var dy = y - mapY;
		if (dx < MOVE_THRESHOLD && dx > -MOVE_THRESHOLD && dy < MOVE_THRESHOLD && dy > -MOVE_THRESHOLD) {
			this.modifyStep(x, y, newP);
			return;
		}

		var stepSize = MOVE_THRESHOLD / Math.max(Math.abs(dx), Math.abs(dy));
		var d = 0.0;
		newP.x = mapX;
		newP.y = mapY;
		var done = false;
		while (!done) {
			if (d + stepSize >= 1) {
				stepSize = 1 - d;
				done = true;
			}

			this.modifyStep(newP.x + dx * stepSize, newP.y + dy * stepSize, newP);
			d += stepSize;
		}
	}

	public function modifyStep(x: Float32, y: Float32, newP: Point) {
		var nextXBorder = 0.0;
		var nextYBorder = 0.0;
		var xCross = mapX % 0.5 == 0 && x != mapX || Math.floor(mapX / 0.5) != Math.floor(x / 0.5);
		var yCross = mapY % 0.5 == 0 && y != mapY || Math.floor(mapY / 0.5) != Math.floor(y / 0.5);
		if (!xCross && !yCross || this.isValidPosition(x, y)) {
			newP.x = x;
			newP.y = y;
			return;
		}

		if (xCross) {
			nextXBorder = x > mapX ? (Math.floor(x * 2) / 2) : (Math.floor(mapX * 2) / 2);
			if (Math.floor(nextXBorder) > Math.floor(mapX))
				nextXBorder -= 0.01;
		}

		if (yCross) {
			nextYBorder = y > mapY ? (Math.floor(y * 2) / 2) : (Math.floor(mapY * 2) / 2);
			if (Math.floor(nextYBorder) > Math.floor(mapY))
				nextYBorder -= 0.01;
		}

		if (!xCross) {
			newP.x = x;
			newP.y = nextYBorder;
			return;
		}

		if (!yCross) {
			newP.x = nextXBorder;
			newP.y = y;
			return;
		}

		var xBorderDist = x > mapX ? x - nextXBorder : nextXBorder - x;
		var yBorderDist = y > mapY ? y - nextYBorder : nextYBorder - y;
		if (xBorderDist > yBorderDist) {
			if (this.isValidPosition(x, nextYBorder)) {
				newP.x = x;
				newP.y = nextYBorder;
				return;
			}

			if (this.isValidPosition(nextXBorder, y)) {
				newP.x = nextXBorder;
				newP.y = y;
				return;
			}
		} else {
			if (this.isValidPosition(nextXBorder, y)) {
				newP.x = nextXBorder;
				newP.y = y;
				return;
			}

			if (this.isValidPosition(x, nextYBorder)) {
				newP.x = x;
				newP.y = nextYBorder;
				return;
			}
		}

		newP.x = nextXBorder;
		newP.y = nextYBorder;
	}

	public function isValidPosition(x: Float32, y: Float32) {
		var square = map.lookupSquare(Std.int(x), Std.int(y));
		if (curSquare != square && (square == null || !(!square.props.noWalk && (square.obj == null || !square.obj.props.occupySquare))))
			return false;

		var xFrac = x - Math.floor(x);
		var yFrac = y - Math.floor(y);
		if (xFrac < 0.5) {
			if (this.isFullOccupy(x - 1, y))
				return false;

			if (yFrac < 0.5) {
				if (this.isFullOccupy(x, y - 1) || this.isFullOccupy(x - 1, y - 1))
					return false;
			} else if (yFrac > 0.5) {
				if (this.isFullOccupy(x, y + 1) || this.isFullOccupy(x - 1, y + 1))
					return false;
			}
		} else if (xFrac > 0.5) {
			if (this.isFullOccupy(x + 1, y))
				return false;

			if (yFrac < 0.5) {
				if (this.isFullOccupy(x, y - 1) || this.isFullOccupy(x + 1, y - 1))
					return false;
			} else if (yFrac > 0.5) {
				if (this.isFullOccupy(x, y + 1) || this.isFullOccupy(x + 1, y + 1))
					return false;
			}
		} else if (yFrac < 0.5) {
			if (this.isFullOccupy(x, y - 1))
				return false;
		} else if (yFrac > 0.5) {
			if (this.isFullOccupy(x, y + 1))
				return false;
		}

		return true;
	}

	public function isFullOccupy(x: Float32, y: Float32) {
		var square = map.lookupSquare(Math.floor(x), Math.floor(y));
		return square == null || square.tileType == 255 || square.obj != null && square.obj.props.fullOccupy;
	}

	public function useAltWeapon(xS: Float32, yS: Float32, useType: Int32) {
		var now = 0;
		var cooldown = 0;
		if (map == null || this.objectType == ObjectLibrary.idToType.get("Warlock"))
			return false;

		var itemType = equipment[1];
		if (itemType == -1)
			return false;

		var objectXML = ObjectLibrary.xmlLibrary.get(itemType);
		if (objectXML == null)
			return false;

		var angle = Camera.angleRad;
		var cosAngle = MathUtil.cos(angle), sinAngle = MathUtil.sin(angle);
		xS /= Camera.PX_PER_TILE;
		yS /= Camera.PX_PER_TILE;
		var targetX = xS * cosAngle + yS * sinAngle;
		var targetY = xS * -sinAngle + yS * cosAngle;

		for (activateXML in objectXML.elementsNamed("Activate"))
			if (activateXML.value() == ActivationType.TELEPORT && !this.isValidPosition(targetX, targetY)) {
				SoundEffectLibrary.play("error");
				return false;
			}

		now = System.getTimer();
		if (useType == UseType.START_USE) {
			if (now < this.nextAltAttack) {
				SoundEffectLibrary.play("error");
				return false;
			}

			var mpCost: Int32 = objectXML.intElement("MpCost"),
				hpCost: Int32 = objectXML.intElement("HpCost");
			if (mpCost > this.mp || hpCost > this.hp) {
				SoundEffectLibrary.play("no_mana");
				return false;
			}

			cooldown = 500;
			if (objectXML.elementExists("Cooldown"))
				cooldown = objectXML.intElement("Cooldown") * 1000;

			if (objectXML.elementExists("Sound"))
				SoundEffectLibrary.play(objectXML.element("Sound"));

			this.nextAltAttack = now + cooldown;
			NetworkHandler.useItem(now, objectId, 1, itemType, targetX, targetY, useType);
		}

		return true;
	}

	public function attemptAttackAngle(angle: Float32) {
		this.shoot(Camera.angleRad + angle);
	}

	public function nextAvailableInventorySlot() {
		var len = this.hasBackpack ? equipment.length : equipment.length - GeneralConstants.NUM_INVENTORY_SLOTS;
		for (i in 4...len)
			if (equipment[i] <= 0)
				return i;

		return -1;
	}

	public function swapInventoryIndex(current: String) {
		var start = 0;
		var end = 0;
		if (!this.hasBackpack)
			return -1;

		if (current == TabStripModel.BACKPACK) {
			start = GeneralConstants.NUM_EQUIPMENT_SLOTS;
			end = GeneralConstants.NUM_EQUIPMENT_SLOTS + GeneralConstants.NUM_INVENTORY_SLOTS;
		} else {
			start = GeneralConstants.NUM_EQUIPMENT_SLOTS + GeneralConstants.NUM_INVENTORY_SLOTS;
			end = equipment.length;
		}

		for (i in start...end)
			if (equipment[i] <= 0)
				return i;

		return -1;
	}

	public function getVialCount(objectType: Int) {
		switch (objectType) {
			case VialModel.HEALTH_VIAL_ID:
				return this.healthVialCount;
			case VialModel.MAGIC_VIAL_ID:
				return this.magicVialCount;
			default:
				return 0;
		}
	}

	private function getMoveSpeed() {
		if (isSlowed())
			return MIN_MOVE_SPEED * this.moveMultiplier;

		var moveSpeed = MIN_MOVE_SPEED + this.speed / 75 * (MAX_MOVE_SPEED - MIN_MOVE_SPEED);
		if (isSpeedy())
			moveSpeed *= 1.5;

		return moveSpeed * this.moveMultiplier * (Global.gameSprite.inputHandler.isWalking ? 0.5 : 1);
	}

	private function strMult() {
		if (isWeak())
			return MIN_STRENGTH_MULT;

		var strMult = MIN_STRENGTH_MULT + this.strength / 75 * (MAX_STRENGTH_MULT - MIN_STRENGTH_MULT);
		if (isDamaging())
			strMult *= 1.5;

		return strMult * this.damageMult;
	}

	private function witMult() {
		var witMult = MIN_WIT_MULT + this.wit / 75 * (MAX_WIT_MULT - MIN_WIT_MULT);
		return witMult * this.damageMult;
	}

	/*private function makeSkinTexture() {
		var image = this.skin.imageFromAngle(0, AnimatedChar.STAND, 0);
		animatedChar = this.skin;
		texture = image.image;
		mask = image.mask;
		this.isDefaultAnimatedChar = true;
	}*/
	private function shoot(angle: Float32) {
		if (map == null)
			return;

		var time = System.getTimer();
		var weaponType = equipment[0];
		if (weaponType == -1) {
			if (time - this.lastAttackError > 2000) {
				Global.gameSprite.textBox.addText("You do not have a weapon equipped!", 0xFF0000);
				this.lastAttackError = time;
			}

			return;
		}

		var weaponXML = ObjectLibrary.xmlLibrary.get(weaponType);
		var rateOfFire = weaponXML.floatElement("RateOfFire", 1);
		this.attackPeriod = Std.int(1 / (ATTACK_FREQUENCY * rateOfFire));
		if (time < attackStart + this.attackPeriod)
			return;

		attackAngle = angle;
		attackStart = time;
		this.doShoot(attackStart, weaponType, weaponXML, attackAngle, true);
	}

	private function doShoot(time: Int32, weaponType: Int32, weaponXML: Xml, attackAngle: Float32, useMult: Bool) {
		var numProjs = weaponXML.intElement("NumProjectiles", 1);
		var arcGap = weaponXML.floatElement("ArcGap", 11.25) * MathUtil.TO_RAD;
		var totalArc = arcGap * (numProjs - 1);
		var angle = attackAngle - totalArc / 2;
		for (i in 0...numProjs) {
			var bulletId = this.nextBulletId;
			this.nextBulletId = (this.nextBulletId + 1) % 128;
			var proj = Global.projPool.get();
			proj.reset(weaponType, 0, objectId, bulletId, angle, time);
			var physDmg = proj.projProps.physicalDamage;
			var magicDmg = proj.projProps.magicDamage;
			var trueDmg = proj.projProps.trueDamage;
			if (useMult) {
				physDmg = Std.int(physDmg * this.strMult());
				magicDmg = Std.int(magicDmg * this.witMult());
				trueDmg = Std.int(trueDmg * this.damageMult);
			}

			proj.setDamages(physDmg, magicDmg, trueDmg);
			if (i == 0 && proj.sound != null)
				SoundEffectLibrary.play(proj.sound, 0.75, false);

			map.addGameObject(cast proj, mapX + MathUtil.cos(attackAngle) * 0.25, mapY + MathUtil.sin(attackAngle) * 0.25);
			NetworkHandler.playerShoot(time, proj);
			angle += arcGap;
		}
	}
}
