package objects.animation;

import objects.TextureData;

using util.Utils;

class FrameData {
	public var time = 0;
	public var textureData: TextureData;

	public function new(xml: Xml) {
		this.time = Std.int(xml.floatAttribute("time") * 1000);
		this.textureData = new TextureData(xml);
	}
}
