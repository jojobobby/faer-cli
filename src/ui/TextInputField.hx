package ui;

import openfl.display.CapsStyle;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.filters.DropShadowFilter;

class TextInputField extends Sprite {
	public static inline var HEIGHT: Int = 88;

	public var nameText: SimpleText;
	public var inputText: SimpleText;
	public var errorText: SimpleText;

	public function new(name: String, isPassword: Bool, error: String) {
		super();

		this.nameText = new SimpleText(18, 0xB3B3B3, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.text = name;
		this.nameText.updateMetrics();
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.nameText);
		this.inputText = new SimpleText(20, 0xB3B3B3, true, 238, 30);
		this.inputText.y = 30;
		this.inputText.x = 6;
		this.inputText.border = false;
		this.inputText.displayAsPassword = isPassword;
		this.inputText.updateMetrics();
		addChild(this.inputText);
		graphics.lineStyle(2, 0x454545, 1, false, LineScaleMode.NORMAL, CapsStyle.ROUND, JointStyle.ROUND);
		graphics.beginFill(0x333333, 1);
		graphics.drawRect(0, this.inputText.y, 238, 30);
		graphics.endFill();
		graphics.lineStyle();
		this.inputText.addEventListener(Event.CHANGE, this.onInputChange);
		this.errorText = new SimpleText(12, 0xFC8642, false, 0, 0);
		this.errorText.y = this.inputText.y + 32;
		this.errorText.text = error;
		this.errorText.updateMetrics();
		this.errorText.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.errorText);
	}

	public function text() {
		return this.inputText.text;
	}

	public function setError(error: String) {
		this.errorText.text = error;
		this.errorText.updateMetrics();
	}

	public function onInputChange(event: Event) {
		this.setError("");
	}
}
