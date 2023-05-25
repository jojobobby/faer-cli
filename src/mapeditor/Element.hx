package mapeditor;

import ui.tooltip.ToolTip;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;

class Element extends Sprite {
	public static inline var WIDTH = 50;
	public static inline var HEIGHT = 50;

	private static var toolTip: ToolTip = null;

	public var type: Int;

	private var selected = false;
	private var mouseOver = false;

	public function new(type: Int) {
		super();
		this.type = type;
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function setSelected(selected: Bool) {
		this.selected = selected;
		this.draw();
	}

	private function onAddedToStage(_: Event) {
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	private function onRemovedFromStage(_: Event) {
		removeEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		removeEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	private function onMouseOver(_: Event) {
		this.mouseOver = true;
		this.draw();
		this.setToolTip(this.getToolTip());
	}

	private function onRollOut(_: Event) {
		this.mouseOver = false;
		this.draw();
		this.removeTooltip();
	}

	private function setToolTip(newToolTip: ToolTip) {
		this.removeTooltip();
		Global.layers.tooltips.show(newToolTip);
	}

	private function removeTooltip() {
		Global.layers.tooltips.hide();
	}

	private function getToolTip(): ToolTip {
		return null;
	}

	private function draw() {
		graphics.clear();
		var color = 3552822;
		if (this.selected) {
			graphics.lineStyle(1, 16777215);
			color = 8355711;
		}

		graphics.beginFill(this.mouseOver ? 5658198 : 3552822, 1);
		graphics.drawRect(2, 2, WIDTH - 4, HEIGHT - 4);
		if (this.selected)
			graphics.lineStyle();

		graphics.endFill();
	}
}
