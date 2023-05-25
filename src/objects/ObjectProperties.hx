package objects;

import util.Utils;
import haxe.ds.IntMap;
import sound.SoundEffectLibrary;

class ObjectProperties {
	public var objType = 0;
	public var objId = "";
	public var displayId = "";
	public var isPlayer = false;
	public var isEnemy = false;
	public var drawOnGround = false;
	public var drawUnder = false;
	public var occupySquare = false;
	public var fullOccupy = false;
	public var enemyOccupySquare = false;
	public var staticObj = false;
	public var noMiniMap = false;
	public var protectFromGroundDamage = false;
	public var protectFromSink = false;
	public var baseZ = 0.0;
	public var flying = false;
	public var color = 0xFFFFFF;
	public var showName = false;
	public var dontFaceAttacks = false;
	public var bloodProb = 0.0;
	public var bloodColor = 0xFF0000;
	public var shadowColor = 0;
	public var sounds: IntMap<String> = null;
	public var portrait: TextureData = null;
	public var minSize = 100;
	public var maxSize = 100;
	public var sizeStep = 5;
	public var whileMoving: WhileMovingProperties = null;
	public var oldSound = "";
	public var projectiles: IntMap<ProjectileProperties>;
	public var scepterProps: ScepterProperties;
	public var angleCorrection = 0.0;
	public var rotation = 0.0;
	public var floating = false;
	public var floatTime = 0;
	public var floatHeight = 0.0;
	public var floatSine = false;
	public var showEffects: Array<ShowEffectProperties> = null;

	public function new(objectXML: Xml) {
		var bulletType = 0;
		this.projectiles = new IntMap<ProjectileProperties>();
		if (objectXML == null)
			return;

		this.objType = Std.parseInt(objectXML.get("type"));
		this.objId = objectXML.get("id");
		this.displayId = this.objId;
		if (objectXML.elementsNamed("DisplayId").hasNext())
			this.displayId = objectXML.elementsNamed("DisplayId").next().firstChild().nodeValue;

		this.isPlayer = objectXML.elementsNamed("Player").hasNext();
		this.isEnemy = objectXML.elementsNamed("Enemy").hasNext();
		this.drawOnGround = objectXML.elementsNamed("DrawOnGround").hasNext();
		if (this.drawOnGround || objectXML.elementsNamed("DrawUnder").hasNext())
			this.drawUnder = true;

		this.occupySquare = objectXML.elementsNamed("OccupySquare").hasNext();
		this.fullOccupy = objectXML.elementsNamed("FullOccupy").hasNext();
		this.enemyOccupySquare = objectXML.elementsNamed("EnemyOccupySquare").hasNext();
		this.staticObj = objectXML.elementsNamed("Static").hasNext();
		this.noMiniMap = objectXML.elementsNamed("NoMiniMap").hasNext();
		this.protectFromGroundDamage = objectXML.elementsNamed("ProtectFromGroundDamage").hasNext();
		this.protectFromSink = objectXML.elementsNamed("ProtectFromSink").hasNext();
		this.flying = objectXML.elementsNamed("Flying").hasNext();
		this.showName = objectXML.elementsNamed("ShowName").hasNext();
		this.dontFaceAttacks = objectXML.elementsNamed("DontFaceAttacks").hasNext();
		this.floating = objectXML.elementsNamed("Float").hasNext();
		if (this.floating) {
			this.floatSine = objectXML.elementsNamed("Float")
				.next()
				.exists("sine") ? false : objectXML.elementsNamed("Float")
				.next()
				.get("sine") == "true";
			this.floatTime = objectXML.elementsNamed("Float").next().exists("time") ? 500 : Std.parseInt(objectXML.elementsNamed("Float").next().get("time"));
			this.floatHeight = objectXML.elementsNamed("Float")
				.next()
				.exists("height") ? 0.5 : Std.parseFloat(objectXML.elementsNamed("Float").next().get("height"));
		}

		if (objectXML.elementsNamed("Z").hasNext())
			this.baseZ = Std.parseFloat(objectXML.elementsNamed("Z").next().firstChild().nodeValue);

		if (objectXML.elementsNamed("Color").hasNext())
			this.color = Std.parseInt(objectXML.elementsNamed("Color").next().firstChild().nodeValue);

		if (objectXML.elementsNamed("Size").hasNext())
			this.minSize = this.maxSize = Std.parseInt(objectXML.elementsNamed("Size").next().firstChild().nodeValue);
		else {
			if (objectXML.elementsNamed("MinSize").hasNext())
				this.minSize = Std.parseInt(objectXML.elementsNamed("MinSize").next().firstChild().nodeValue);

			if (objectXML.elementsNamed("MaxSize").hasNext())
				this.maxSize = Std.parseInt(objectXML.elementsNamed("MaxSize").next().firstChild().nodeValue);

			if (objectXML.elementsNamed("SizeStep").hasNext())
				this.sizeStep = Std.parseInt(objectXML.elementsNamed("SizeStep").next().firstChild().nodeValue);
		}

		this.oldSound = objectXML.elementsNamed("OldSound")
			.hasNext() ? objectXML.elementsNamed("OldSound")
			.next()
			.firstChild()
			.nodeValue : null;
		for (xml in objectXML.elementsNamed("Projectile")) {
			bulletType = Std.parseInt(xml.get("id"));
			this.projectiles.set(bulletType, new ProjectileProperties(xml));
		}

		if (objectXML.elementsNamed("Scepter").hasNext())
			this.scepterProps = new ScepterProperties(objectXML.elementsNamed("Scepter").next());

		this.showEffects = new Array<ShowEffectProperties>();
		for (xml in objectXML.elementsNamed("ShowEffect"))
			this.showEffects.push(new ShowEffectProperties(xml));

		this.angleCorrection = objectXML.elementsNamed("AngleCorrection")
			.hasNext() ? Std.parseFloat(objectXML.elementsNamed("AngleCorrection").next().firstChild().nodeValue) * (MathUtil.PI / 4) : 0;
		this.rotation = objectXML.elementsNamed("Rotation").hasNext() ? Std.parseFloat(objectXML.elementsNamed("Rotation").next().firstChild().nodeValue) : 0;

		for (xml in objectXML.elementsNamed("BloodProb"))
			this.bloodProb = Std.parseFloat(objectXML.elementsNamed("BloodProb").next().firstChild().nodeValue);

		for (xml in objectXML.elementsNamed("BloodColor"))
			this.bloodColor = Std.parseInt(objectXML.elementsNamed("BloodColor").next().firstChild().nodeValue);

		for (xml in objectXML.elementsNamed("ShadowColor"))
			this.shadowColor = Std.parseInt(objectXML.elementsNamed("ShadowColor").next().firstChild().nodeValue);

		for (soundXML in objectXML.elementsNamed("Sound")) {
			if (this.sounds == null)
				this.sounds = new IntMap<String>();
			this.sounds.set(Std.parseInt(soundXML.get("id")), soundXML.firstChild().nodeValue);
		}

		for (xml in objectXML.elementsNamed("Portrait"))
			this.portrait = new TextureData(objectXML.elementsNamed("Portrait").next());

		for (xml in objectXML.elementsNamed("WhileMoving"))
			this.whileMoving = new WhileMovingProperties(objectXML.elementsNamed("WhileMoving").next());
	}

	public function getSize() {
		if (this.minSize == this.maxSize)
			return Std.int(this.minSize * 1.25);

		var maxSteps: Int = Math.round((this.maxSize - this.minSize) / this.sizeStep);
		return Std.int((this.minSize + Math.round(Math.random() * maxSteps) * this.sizeStep) * 1.25);
	}
}

class DrainProperties {
	public var drainStat = 0;
	public var drainPerSec = 0;

	public function new(drainXML: Xml) {
		this.drainStat = Std.parseInt(drainXML.get("stat"));
		this.drainPerSec = Std.parseInt(drainXML.firstChild().nodeValue);
	}
}

class ScepterProperties {
	public var color = 0;
	public var range = 0.0;
	public var tickMs = 0;
	public var damage = 0;
	public var drain: DrainProperties;

	public function new(scepterXML: Xml) {
		this.color = Std.parseInt(scepterXML.elementsNamed("Color").next().firstChild().nodeValue);
		this.range = Std.parseFloat(scepterXML.elementsNamed("Range").next().firstChild().nodeValue);
		this.tickMs = Std.parseInt(scepterXML.elementsNamed("TickMS").next().firstChild().nodeValue);
		this.damage = Std.parseInt(scepterXML.elementsNamed("Damage").next().firstChild().nodeValue);
		this.drain = new DrainProperties(scepterXML.elementsNamed("Drain").next());
	}
}

class ShowEffectProperties {
	public var effType = "";
	public var radius = 0;
	public var cooldown = 0;
	public var color = 0;

	public function new(showEffXML: Xml) {
		this.effType = showEffXML.firstChild().nodeValue;
		this.radius = Std.parseInt(showEffXML.get("radius"));
		this.cooldown = Std.parseInt(showEffXML.get("cooldown"));
		this.color = Std.parseInt(showEffXML.get("color"));
	}
}

class WhileMovingProperties {
	public var z = 0.0;
	public var flying = false;

	public function new(whileMovingXML: Xml) {
		if (whileMovingXML.elementsNamed("Z").hasNext())
			this.z = Std.parseFloat(whileMovingXML.elementsNamed("Z").next().firstChild().nodeValue);

		this.flying = whileMovingXML.elementsNamed("Flying").hasNext();
	}
}
