package ui.tooltip;
import objects.GameObject;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import util.BitmapUtil;

class PortraitToolTip extends ToolTip {
	private var portrait: Bitmap;

	public function new(go: GameObject) {
		super(0x5C1D1D, 1, 0xFC8642, 1, false);
		this.portrait = new Bitmap();
		this.portrait.x = 0;
		this.portrait.y = 0;
		var portraitBD: BitmapData = go.getPortrait();
		portraitBD = BitmapUtil.cropToBitmapData(portraitBD, 10, 10, portraitBD.width - 20, portraitBD.height - 20);
		this.portrait.bitmapData = portraitBD;
		addChild(this.portrait);
		filters = [];
	}
}