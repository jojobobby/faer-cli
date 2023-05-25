package ui;

import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import sound.SoundEffectLibrary;

class ClickableText extends Sprite {
	public var text: SimpleText;
	public var defaultColor = 0xFFFFFF;

	public function new(textSize: Int, bold: Bool, text: String) {
		super();

		this.text = new SimpleText(textSize, 0xFFFFFF, false, 0, 0);
		this.text.setBold(bold);
		this.text.text = text;
		this.text.updateMetrics();
		addChild(this.text);
		this.text.filters = [new DropShadowFilter(0, 0, 0)];
		// needed for mouse events to register...
		graphics.clear();
		graphics.beginFill(0xFFFFFF, 0);
		graphics.drawRect(this.text.x - 4, this.text.y - 4, this.text.width + 8, this.text.height + 8);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		addEventListener(MouseEvent.CLICK, onMouseClick);
	}

	public function setDefaultColor(color: Int) {
		this.defaultColor = color;
		this.text.setColor(this.defaultColor);
	}

	private function onMouseOver(event: MouseEvent) {
		this.text.setColor(0xFFDC85);
	}

	private function onMouseOut(event: MouseEvent) {
		this.text.setColor(this.defaultColor);
	}

	private static function onMouseClick(event: MouseEvent) {
		SoundEffectLibrary.play("button_click");
	}
}
