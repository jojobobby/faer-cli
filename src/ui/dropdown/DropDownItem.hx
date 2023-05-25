package ui.dropdown;

import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;

class DropDownItem extends Sprite {
	public var w = 0;
	public var h = 0;

	private var nameText: SimpleText;

	public function new(name: String, w: Int, h: Int) {
		super();

		this.w = w;
		this.h = h;
		this.nameText = new SimpleText(16, 0xB3B3B3, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.text = name;
		this.nameText.updateMetrics();
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		this.nameText.x = this.w / 2 - this.nameText.width / 2;
		this.nameText.y = this.h / 2 - this.nameText.height / 2;
		addChild(this.nameText);
		this.drawBackground(0x363636);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
	}

	public function getValue() {
		return this.nameText.text;
	}

	private function drawBackground(color: Int) {
		graphics.clear();
		graphics.lineStyle(1, 0xB3B3B3);
		graphics.beginFill(color, 1);
		graphics.drawRect(0, 0, this.w, this.h);
		graphics.endFill();
		graphics.lineStyle();
	}

	private function onMouseOver(event: MouseEvent) {
		this.drawBackground(5658198);
	}

	private function onMouseOut(event: MouseEvent) {
		this.drawBackground(0x363636);
	}
}
