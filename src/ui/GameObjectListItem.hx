package ui;

import objects.GameObject;
import objects.ObjectLibrary;
import objects.Player;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.filters.DropShadowFilter;
import openfl.geom.ColorTransform;
import util.Utils;
import util.Settings;

class GameObjectListItem extends Sprite {
	public var longVersion = false;
	public var go: GameObject;

	private var portrait: Bitmap;
	private var nameText: SimpleText;
	private var color = 0;
	private var drawColor = 0xFFFFFF;
	private var drawText = "";
	private var isHtml = false;
	private var drawCT: ColorTransform = null;

	public function new(color: Int, longVersion: Bool, go: GameObject) {
		super();

		this.longVersion = longVersion;
		this.color = color;
		this.portrait = new Bitmap();
		this.portrait.x = -4;
		this.portrait.y = -4;
		addChild(this.portrait);
		if (this.longVersion) {
			this.nameText = new SimpleText(13, color, false, 0, 0);
		} else {
			this.nameText = new SimpleText(13, color, false, 66, 20);
			this.nameText.setBold(true);
		}
		this.nameText.x = 32;
		this.nameText.y = 6;
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.nameText);
		this.draw(go);
	}

	public function draw(go: GameObject, ct: ColorTransform = null) {
		this.go = go;
		visible = this.go != null;
		if (!visible)
			return;

		this.portrait.bitmapData = cast(this.go, Player).getPortrait();
		var drawColor = this.color;
		var drawText = "";
		var isHtml = false;
		var p: Player = cast(this.go, Player);
		if (p != null)
			drawColor = p.isFellowGuild ? Settings.FELLOW_GUILD_COLOR : Settings.DEFAULT_COLOR;

		if (this.longVersion) {
			isHtml = true;
			if (this.go.name != null && this.go.name != "")
				drawText = "<b>" + this.go.name + "</b> (" + ObjectLibrary.typeToDisplayId.get(this.go.objectType) + ")";
			else
				drawText = "<b>" + ObjectLibrary.typeToDisplayId.get(this.go.objectType) + "</b>";
		} else if (this.go.name == null || this.go.name == "")
			drawText = ObjectLibrary.typeToDisplayId.get(this.go.objectType);
		else
			drawText = this.go.name;

		this.internalDraw(drawColor, drawText, isHtml, ct);
	}

	private function internalDraw(drawColor: Int, drawText: String, isHtml: Bool, drawCT: ColorTransform) {
		if (drawColor == this.drawColor && drawText == this.drawText && isHtml == this.isHtml && drawCT == this.drawCT) {
			return;
		}
		this.nameText.setColor(drawColor);
		if (isHtml) {
			this.nameText.htmlText = drawText;
		} else {
			this.nameText.text = drawText;
		}
		this.nameText.updateMetrics();
		if (this.drawCT != null || drawCT != null) {
			transform.colorTransform = drawCT == null ? ColorUtils.identity : drawCT;
		}
		this.drawColor = drawColor;
		this.drawText = drawText;
		this.isHtml = isHtml;
		this.drawCT = drawCT;
	}
}
