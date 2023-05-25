package mapeditor;

import ui.SimpleText;
import openfl.display.Sprite;
import openfl.events.MouseEvent;

class CommandMenuItem extends Sprite {
	private static inline var WIDTH = 80;
	private static inline var HEIGHT = 25;

	public var callback: CommandMenuItem->Void;
	public var command: Int;

	private var over = false;
	private var down = false;
	private var selected = false;
	private var text: SimpleText;

	public function new(label: String, callback: CommandMenuItem->Void, command: Int) {
		super();
		this.callback = callback;
		this.command = command;
		this.text = new SimpleText(16, 16777215, false, 0, 0);
		this.text.setBold(true);
		this.text.text = label;
		this.text.updateMetrics();
		this.text.x = 2;
		addChild(this.text);
		this.redraw();
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		addEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
		addEventListener(MouseEvent.CLICK, this.onClick);
	}

	public function setSelected(selected: Bool) {
		this.selected = selected;
		this.redraw();
	}

	public function setLabel(label: String) {
		this.text.text = label;
		this.text.updateMetrics();
	}

	private function redraw() {
		graphics.clear();
		if (this.selected || this.down) {
			graphics.lineStyle(2, 16777215);
			graphics.beginFill(8355711, 1);
			graphics.drawRect(0, 0, WIDTH, HEIGHT);
			graphics.endFill();
			graphics.lineStyle();
		} else if (this.over) {
			graphics.lineStyle(2, 16777215);
			graphics.beginFill(0, 0);
			graphics.drawRect(0, 0, WIDTH, HEIGHT);
			graphics.endFill();
			graphics.lineStyle();
		} else {
			graphics.lineStyle(1, 16777215);
			graphics.beginFill(0, 0);
			graphics.drawRect(0, 0, WIDTH, HEIGHT);
			graphics.endFill();
			graphics.lineStyle();
		}
	}

	private function onMouseOver(_: MouseEvent) {
		this.over = true;
		this.redraw();
	}

	private function onMouseOut(_: MouseEvent) {
		this.over = false;
		this.down = false;
		this.redraw();
	}

	private function onMouseDown(_: MouseEvent) {
		this.down = true;
		this.redraw();
	}

	private function onMouseUp(_: MouseEvent) {
		this.down = false;
		this.redraw();
	}

	private function onClick(_: MouseEvent) {
		this.callback(this);
	}
}
