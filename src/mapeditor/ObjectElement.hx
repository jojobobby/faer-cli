package mapeditor;

import objects.ObjectLibrary;
import openfl.display.Bitmap;

using util.Utils;

class ObjectElement extends Element {
	public var objXML: Xml;

	public function new(objXML: Xml) {
		super(objXML.intAttribute("type"));
		this.objXML = objXML;
		var texture = ObjectLibrary.getRedrawnTextureFromType(type, 100, true, false);
		var bitmap = new Bitmap(texture);
		var scale = (Element.WIDTH - 4) / Math.max(bitmap.width, bitmap.height);
		bitmap.scaleX = bitmap.scaleY = scale;
		bitmap.x = Element.WIDTH / 2 - bitmap.width / 2;
		bitmap.y = Element.HEIGHT / 2 - bitmap.height / 2;
		addChild(bitmap);
	}

	override private function getToolTip() {
		return new ObjectTypeToolTip(this.objXML);
	}
}
