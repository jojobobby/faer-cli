package screens;

import appengine.SavedCharacter;
import classes.view.CharSkinView;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.geom.ColorTransform;
import openfl.text.TextFieldAutoSize;
import ui.SimpleText;
import ui.tooltip.ClassToolTip;
import ui.tooltip.ToolTip;
import util.AnimatedChar;
import util.AssetLibrary;

class CharacterBox extends Sprite {
	public var playerXML: Xml = null;
	public var available = true;

	private var graphicContainer: Sprite;
	private var graphic: Sprite;
	private var bitmap: Bitmap;
	private var statusText: SimpleText;
	private var classNameText: SimpleText;
	private var lock: Bitmap;

	private function onClick(event: MouseEvent) {
		this.graphicContainer.removeEventListener(MouseEvent.CLICK, this.onClick);

		Global.layers.tooltips.hide();
		if (!this.available)
			return;

		Global.classModel.getCharacterClass(this.objectType()).setIsSelected(true);
		Global.layers.screens.setScreen(new CharSkinView(this.playerXML));
	}

	public function new(playerXML: Xml) {
		super();

		this.playerXML = playerXML;
		this.graphic = new Sprite();
		this.graphic.graphics.lineStyle(2, 0x666666);
		this.graphic.graphics.beginFill(0x111111);
		this.graphic.graphics.drawRect(0, 0, 100, 100);
		this.graphicContainer = new Sprite();
		addChild(this.graphicContainer);
		this.graphicContainer.addChild(this.graphic);
		this.graphicContainer.addEventListener(MouseEvent.CLICK, this.onClick);
		this.bitmap = new Bitmap(null);
		this.bitmap.y = 10;
		this.setImage(AnimatedChar.DOWN, AnimatedChar.STAND, 0);
		this.graphic.addChild(this.bitmap);
		this.classNameText = new SimpleText(14, 0xFFFFFF, false, 0, 0);
		this.classNameText.setBold(true);
		this.classNameText.htmlText = "<p align=\"center\">" + this.playerXML.get("id") + "</p>";
		this.classNameText.autoSize = TextFieldAutoSize.CENTER;
		this.classNameText.updateMetrics();
		this.classNameText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4)];
		this.classNameText.y = 65;
		this.graphic.addChild(this.classNameText);
		this.setStatusButton();
		if (!this.available) {
			this.lock = new Bitmap(AssetLibrary.getImageFromSet("misc", 11));
			this.lock.scaleX = 2;
			this.lock.scaleY = 2;
			this.lock.x = 4;
			this.lock.y = 8;
			addChild(this.lock);
		}
	}

	public function objectType() {
		return Std.parseInt(this.playerXML.get("type"));
	}

	public function getTooltip(): ToolTip {
		return new ClassToolTip(this.playerXML);
	}

	public function setOver(over: Bool) {
		if (!this.available)
			return;

		if (over)
			transform.colorTransform = new ColorTransform(1.2, 1.2, 1.2);
		else
			transform.colorTransform = new ColorTransform(1, 1, 1);
	}

	private function setImage(dir: Int, action: Int, p: Float) {
		this.bitmap.bitmapData = SavedCharacter.getImage(null, this.playerXML, dir, action, p, this.available, false);
		this.bitmap.x = this.graphic.width / 2 - this.bitmap.bitmapData.width / 2;
	}

	private function setStatusButton() {
		this.statusText = new SimpleText(14, 0xFF0000, false, 0, 0);
		this.statusText.htmlText = "<p align=\"center\">Locked</p>";
		this.statusText.setBold(true);
		this.statusText.autoSize = TextFieldAutoSize.CENTER;
		this.statusText.updateMetrics();
		this.statusText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4)];
		this.statusText.y = 58;
	}
}
