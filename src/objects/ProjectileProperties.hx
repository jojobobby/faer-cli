package objects;

import util.NativeTypes;
import util.ConditionEffect;

class ProjectileProperties {
	public var bulletType = 0;
	public var objectId = "";
	public var lifetime = 0;
	public var speed = 0.0;
	public var realSpeed = 0;
	public var size = 0;
	public var physicalDamage = 0;
	public var magicDamage = 0;
	public var trueDamage = 0;
	public var effects: Array<Int32> = null;
	public var multiHit = false;
	public var armorPiercing = false;
	public var particleTrail = false;
	public var wavy = false;
	public var parametric = false;
	public var boomerang = false;
	public var amplitude = 0.0;
	public var frequency = 0.0;
	public var magnitude = 0.0;
	public var acceleration = 0.0;
	public var accelerationDelay = 0;
	public var speedClamp = 0;

	public function new(projectileXML: Xml) {
		this.bulletType = Std.parseInt(projectileXML.get("id"));
		this.objectId = projectileXML.elementsNamed("ObjectId").next().firstChild().nodeValue;
		this.lifetime = Std.parseInt(projectileXML.elementsNamed("LifetimeMS").next().firstChild().nodeValue);
		this.realSpeed = Std.parseInt(projectileXML.elementsNamed("Speed").next().firstChild().nodeValue);
		this.speed = this.realSpeed / 10000.0;
		this.size = projectileXML.elementsNamed("Size").hasNext() ? Std.parseInt(projectileXML.elementsNamed("Size").next().firstChild().nodeValue) : -1;

		if (projectileXML.elementsNamed("Damage").hasNext())
			this.physicalDamage = Std.parseInt(projectileXML.elementsNamed("Damage").next().firstChild().nodeValue);

		if (projectileXML.elementsNamed("MagicDamage").hasNext())
			this.magicDamage = Std.parseInt(projectileXML.elementsNamed("MagicDamage").next().firstChild().nodeValue);

		if (projectileXML.elementsNamed("TrueDamage").hasNext())
			this.trueDamage = Std.parseInt(projectileXML.elementsNamed("TrueDamage").next().firstChild().nodeValue);

		for (condEffectXML in projectileXML.elementsNamed("ConditionEffect")) {
			if (this.effects == null)
				this.effects = new Array<Int32>();
			this.effects.push(ConditionEffect.getConditionEffectFromName(condEffectXML.firstChild().nodeValue));
		}

		this.multiHit = projectileXML.elementsNamed("MultiHit").hasNext();
		this.armorPiercing = projectileXML.elementsNamed("ArmorPiercing").hasNext();
		this.particleTrail = projectileXML.elementsNamed("ParticleTrail").hasNext();
		this.wavy = projectileXML.elementsNamed("Wavy").hasNext();
		this.parametric = projectileXML.elementsNamed("Parametric").hasNext();
		this.boomerang = projectileXML.elementsNamed("Boomerang").hasNext();
		this.amplitude = projectileXML.elementsNamed("Amplitude")
			.hasNext() ? Std.parseFloat(projectileXML.elementsNamed("Amplitude").next().firstChild().nodeValue) : 0;
		this.frequency = projectileXML.elementsNamed("Frequency")
			.hasNext() ? Std.parseFloat(projectileXML.elementsNamed("Frequency").next().firstChild().nodeValue) : 1;
		this.magnitude = projectileXML.elementsNamed("Magnitude")
			.hasNext() ? Std.parseFloat(projectileXML.elementsNamed("Magnitude").next().firstChild().nodeValue) : 3;
		this.acceleration = projectileXML.elementsNamed("Acceleration")
			.hasNext() ? Std.parseFloat(projectileXML.elementsNamed("Acceleration").next().firstChild().nodeValue) : 0;
		this.accelerationDelay = projectileXML.elementsNamed("AccelerationDelay")
			.hasNext() ? Std.parseInt(projectileXML.elementsNamed("AccelerationDelay").next().firstChild().nodeValue) : 0;
		this.speedClamp = projectileXML.elementsNamed("SpeedClamp")
			.hasNext() ? Std.parseInt(projectileXML.elementsNamed("SpeedClamp").next().firstChild().nodeValue) : -1;
	}
}
