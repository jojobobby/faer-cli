package map;

using util.Utils;

class GroundProperties {
	public var objType = 0;
	public var objId = "";
	public var noWalk = true;
	public var damage = 0;
	public var animate: AnimateProperties;
	public var blendPriority: Int = -1;
	public var speed: Float = 1.0;
	public var uOffset = 0.0;
	public var vOffset = 0.0;
	public var push = false;
	public var sink = false;
	public var sinking = false;

	public function new(groundXML: Xml) {
		this.objType = groundXML.intAttribute("type");
		this.objId = groundXML.attribute("id");
		this.noWalk = groundXML.elementExists("NoWalk");
		this.damage = groundXML.intElement("Damage");
		this.push = groundXML.elementExists("Push");
		this.blendPriority = groundXML.intElement("BlendPriority");
		this.speed = groundXML.floatElement("Speed", 1.0);
		this.uOffset = groundXML.intElement("XOffset");
		this.vOffset = groundXML.intElement("YOffset");
		this.push = groundXML.elementExists("Push");
		this.sink = groundXML.elementExists("Sink");
		this.sinking = groundXML.elementExists("Sinking");

		if (groundXML.elementExists("Animate"))
			this.animate = new AnimateProperties(groundXML.elementsNamed("Animate").next());
		else
			this.animate = new AnimateProperties(Xml.parse(""));
	}
}
