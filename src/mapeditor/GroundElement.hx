package mapeditor;

import ui.tooltip.ToolTip;
import openfl.display.Bitmap;
import map.GroundLibrary;

using util.Utils;

class GroundElement extends Element {
	public var groundXML: Xml;

	private var tileShape: Bitmap;

	public function new(groundXML: Xml) {
		super(groundXML.intAttribute("type"));
		this.groundXML = groundXML;
		var tileBD = GroundLibrary.getBitmapData(type);
		this.tileShape = new Bitmap(tileBD);
		this.tileShape.scaleX = this.tileShape.scaleY = 5;
		this.tileShape.x = this.tileShape.y = 5;
		addChild(this.tileShape);
	}

	override private function getToolTip(): ToolTip {
		return new GroundTypeToolTip(this.groundXML);
	}
}
