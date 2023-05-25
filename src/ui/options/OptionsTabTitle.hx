package ui.options;

import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;

class OptionsTabTitle extends Sprite {
	private static inline var TEXT_SIZE: Int = 16;

	public var text = "";
	public var textField: SimpleText;
	public var selected = false;

	public function new(text: String) {
		super();

		this.text = text;
		this.textField = new SimpleText(TEXT_SIZE, 0xB3B3B3, false, 0, 0);
		this.textField.setBold(true);
		this.textField.text = this.text;
		this.textField.updateMetrics();
		this.textField.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		addChild(this.textField);

		// needed for mouse events to register...
		graphics.clear();
		graphics.beginFill(0xFFFFFF, 0);
		graphics.drawRect(this.textField.x - 4, this.textField.y - 4, this.textField.width + 8, this.textField.height + 8);

		this.selected = false;
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	public function setSelected(selected: Bool) {
		this.selected = selected;
		this.redraw(false);
	}

	private function redraw(over: Bool) {
		this.textField.setSize(TEXT_SIZE).setColor(this.getColor(over));
	}

	private function getColor(isOver: Bool) {
		if (this.selected)
			return 0xFFC800;

		return isOver ? 0xFFFFFF : 0xB3B3B3;
	}

	private function onMouseOver(event: MouseEvent) {
		this.redraw(true);
	}

	private function onRollOut(event: MouseEvent) {
		this.redraw(false);
	}
}
