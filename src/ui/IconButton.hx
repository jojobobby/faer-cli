package ui;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.geom.ColorTransform;
import ui.tooltip.TextToolTip;
import util.Utils;
import util.Settings;
import util.TextureRedrawer;

class IconButton extends Sprite {
	public static var mouseOverCT: ColorTransform = new ColorTransform(1, 220 / 255, 133 / 255);

	public var origIconBitmapData: BitmapData;
	public var iconBitmapData: BitmapData;
	public var icon: Bitmap;
	public var hotkeyName = "";
	public var ct: ColorTransform = null;
	public var toolTip: TextToolTip = null;

	public function new(bitmapData: BitmapData, toolTipTitle: String, hotkeyName: String) {
		super();

		this.origIconBitmapData = bitmapData;
		this.iconBitmapData = TextureRedrawer.redraw(this.origIconBitmapData, Std.int(320 / this.origIconBitmapData.width), true, 0);
		this.icon = new Bitmap(this.iconBitmapData);
		this.icon.x = this.icon.y = -12;
		addChild(this.icon);
		this.hotkeyName = hotkeyName;
		if (toolTipTitle != "")
			this.toolTip = new TextToolTip(0x363636, 0x9B9B9B, toolTipTitle, "");
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
	}

	public function setColorTransform(ct: ColorTransform) {
		if (ct == this.ct)
			return;

		this.ct = ct;
		if (this.ct == null)
			transform.colorTransform = ColorUtils.identity;
		else
			transform.colorTransform = this.ct;
	}

	public function onMouseOver(event: MouseEvent) {
		this.setColorTransform(mouseOverCT);
		if (this.toolTip != null && !stage.contains(this.toolTip)) {
			// this.toolTip.setText("Hotkey: " + KeyCodeUtil.charCodeStrings[Std.parseInt(Settings.values.get(this.hotkeyName))]);
			stage.addChild(this.toolTip);
		}
	}

	public function onMouseOut(event: MouseEvent) {
		this.setColorTransform(null);
		if (this.toolTip != null && this.toolTip.parent != null)
			this.toolTip.parent.removeChild(this.toolTip);
	}

	private function onRemovedFromStage(event: Event) {
		if (this.toolTip != null && this.toolTip.parent != null)
			this.toolTip.parent.removeChild(this.toolTip);
	}
}
