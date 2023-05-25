package ui.menu;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.geom.ColorTransform;
import ui.SimpleText;
import util.CachingColorTransformer;
import util.Utils;
import util.TextureRedrawer;

class MenuOption extends Sprite {
	public static var mouseOverCT = new ColorTransform(1, 220 / 255, 133 / 255);

	public var origIconBitmapData: BitmapData;
	public var iconBitmapData: BitmapData;
	public var icon: Bitmap;
	public var text: SimpleText;
	public var ct: ColorTransform = null;

	public function new(origIconBitmapData: BitmapData, color: Int, textStr: String) {
		super();

		this.origIconBitmapData = origIconBitmapData;
		this.iconBitmapData = TextureRedrawer.redraw(origIconBitmapData, this.redrawSize(), true, 0);
		this.icon = new Bitmap(this.iconBitmapData);
		this.icon.filters = [new DropShadowFilter(0, 0, 0)];
		this.icon.x = -12;
		this.icon.y = -12;
		addChild(this.icon);
		this.text = new SimpleText(18, color, false, 0, 0);
		this.text.setBold(true);
		this.text.text = textStr;
		this.text.updateMetrics();
		this.text.filters = [new DropShadowFilter(0, 0, 0)];
		this.text.x = 20;
		this.text.y = -6;
		addChild(this.text);
		// needed for mouse events to register...
		graphics.clear();
		graphics.beginFill(0xFFFFFF, 0);
		graphics.drawRect(this.text.x - 4, this.text.y - 4, this.text.width + 8, this.text.height + 8);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
	}

	public function setColorTransform(ct: ColorTransform) {
		var transformedBitmapData: BitmapData = null;
		if (ct == this.ct)
			return;

		this.ct = ct;
		if (this.ct == null) {
			this.icon.bitmapData = this.iconBitmapData;
			this.text.transform.colorTransform = ColorUtils.identity;
		} else {
			transformedBitmapData = CachingColorTransformer.transformBitmapData(this.origIconBitmapData, this.ct);
			transformedBitmapData = TextureRedrawer.redraw(transformedBitmapData, this.redrawSize(), true, 0);
			this.icon.bitmapData = transformedBitmapData;
			this.text.transform.colorTransform = this.ct;
		}
	}

	public function redrawSize() {
		return Std.int(40 / (this.origIconBitmapData.width / 8));
	}

	public function onMouseOver(event: MouseEvent) {
		this.setColorTransform(mouseOverCT);
	}

	public function onMouseOut(event: MouseEvent) {
		this.setColorTransform(null);
	}
}
