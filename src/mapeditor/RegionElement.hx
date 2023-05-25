package mapeditor;

import map.RegionLibrary;
import openfl.display.Shape;

using util.Utils;

class RegionElement extends Element {
	public var regionXML: Xml;

	public function new(regionXML: Xml) {
		super(regionXML.intAttribute("type"));
		this.regionXML = regionXML;
		var shape = new Shape();
		shape.graphics.beginFill(RegionLibrary.getColor(type), 0.5);
		shape.graphics.drawRect(0, 0, Element.WIDTH - 8, Element.HEIGHT - 8);
		shape.graphics.endFill();
		shape.x = Element.WIDTH / 2 - shape.width / 2;
		shape.y = Element.HEIGHT / 2 - shape.height / 2;
		addChild(shape);
	}

	override private function getToolTip() {
		return new RegionTypeToolTip(this.regionXML);
	}
}
