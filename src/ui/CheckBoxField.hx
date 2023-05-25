package ui;

import openfl.display.CapsStyle;
import openfl.display.Graphics;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;

class CheckBoxField extends Sprite {
	private static inline var BOX_SIZE = 20;

	public var checkBox: Sprite;
	public var text: SimpleText;
	public var errorText: SimpleText;

	private var checked = false;
	private var hasError = false;

	public function new(text: String, checked: Bool, error: String, fontSize: Int = 16) {
		super();

		this.checked = checked;
		this.checkBox = new Sprite();
		this.checkBox.x = 2;
		this.checkBox.y = 2;
		this.redrawCheckBox();
		this.checkBox.addEventListener(MouseEvent.CLICK, this.onClick);
		addChild(this.checkBox);
		this.text = new SimpleText(fontSize, 0xB3B3B3, false, 0, 0);
		this.text.x = this.checkBox.x + BOX_SIZE + 8;
		this.text.setBold(true);
		this.text.multiline = true;
		this.text.htmlText = text;
		this.text.mouseEnabled = true;
		this.text.updateMetrics();
		this.text.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.text);
		this.errorText = new SimpleText(12, 0xFC8642, false, 0, 0);
		this.errorText.x = this.text.x;
		this.errorText.y = this.text.y + 20;
		this.errorText.text = error;
		this.errorText.updateMetrics();
		this.errorText.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.errorText);
	}

	public function isChecked() {
		return this.checked;
	}

	public function setError(error: String) {
		this.errorText.text = error;
		this.errorText.updateMetrics();
	}

	private function redrawCheckBox() {
		var g = this.checkBox.graphics;
		g.clear();
		g.beginFill(0x333333, 1);
		g.drawRect(0, 0, BOX_SIZE, BOX_SIZE);
		g.endFill();
		if (this.checked) {
			g.lineStyle(4, 0xB3B3B3, 1, false, LineScaleMode.NORMAL, CapsStyle.ROUND, JointStyle.ROUND);
			g.moveTo(2, 2);
			g.lineTo(BOX_SIZE - 2, BOX_SIZE - 2);
			g.moveTo(2, BOX_SIZE - 2);
			g.lineTo(BOX_SIZE - 2, 2);
			g.lineStyle();
			this.hasError = false;
		}

		var color = 0;
		if (this.hasError)
			color = 0xFC8642;
		else
			color = 0x454545;

		g.lineStyle(2, color, 1, false, LineScaleMode.NORMAL, CapsStyle.ROUND, JointStyle.ROUND);
		g.drawRect(0, 0, BOX_SIZE, BOX_SIZE);
		g.lineStyle();
	}

	private function onClick(_: MouseEvent) {
		this.setError("");
		this.checked = !this.checked;
		this.redrawCheckBox();
	}
}
