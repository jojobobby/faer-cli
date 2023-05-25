package ui;

import openfl.display.GraphicsSolidFill;
import openfl.display.Sprite;
import openfl.events.MouseEvent;

class TextButton extends Sprite {
	public var text: SimpleText;
	public var w = 0;

	private var enabledFill: GraphicsSolidFill = new GraphicsSolidFill(0xFFFFFF, 1);
	private var disabledFill: GraphicsSolidFill = new GraphicsSolidFill(0x7F7F7F, 1);
	private var color: Int = 0xFFFFFF;

	public function new(size: Int, text: String, bWidth: Int = 0) {
		super();

		this.text = new SimpleText(size, 0x363636, false, 0, 0);
		this.text.setBold(true);
		this.text.text = text;
		this.text.updateMetrics();
		addChild(this.text);
		this.w = bWidth != 0 ? bWidth : Std.int(this.text.width + 12);
		this.draw();
		this.text.x = this.w / 2 - this.text.textWidth / 2 - 2;
		this.text.y = 1;
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	public function setText(text: String) {
		this.text.text = text;
		this.text.updateMetrics();
		this.text.x = this.w / 2 - this.text.textWidth / 2 - 2;
		this.text.y = 1;
	}

	public function setEnabled(enabled: Bool) {
		if (enabled == mouseEnabled)
			return;

		mouseEnabled = enabled;
		this.color = enabled ? 0xFFFFFF : 0x7F7F7F;
		this.draw();
	}

	private function draw() {
		graphics.clear();
		graphics.beginFill(this.color, 1);
		graphics.drawRect(0, 0, this.w, Std.int(this.text.textHeight + 8));
	}

	private function onMouseOver(event: MouseEvent) {
		this.color = 0xFFDC85;
		this.draw();
	}

	private function onRollOut(event: MouseEvent) {
		this.color = 0xFFFFFF;
		this.draw();
	}
}
