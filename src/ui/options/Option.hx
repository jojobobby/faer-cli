package ui.options;

import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;
import ui.tooltip.TextToolTip;
import ui.tooltip.ToolTip;

class Option extends Sprite {
	private static var tooltip: ToolTip;

	public var paramName = "";
	public var tooltipText = "";

	private var desc: SimpleText;

	public function new(paramName: String, desc: String, tooltipText: String) {
		super();

		this.paramName = paramName;
		this.tooltipText = tooltipText;
		this.desc = new SimpleText(18, 0xB3B3B3, false, 0, 0);
		this.desc.text = desc;
		this.desc.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4, 2)];
		this.desc.updateMetrics();
		this.desc.x = KeyCodeBox.WIDTH + 24;
		this.desc.y = KeyCodeBox.HEIGHT / 2 - this.desc.height / 2 - 2;
		this.desc.mouseEnabled = true;
		this.desc.addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		this.desc.addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
		addChild(this.desc);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function refresh() {}

	private function removeToolTip() {
		if (tooltip != null && stage.contains(tooltip)) {
			stage.removeChild(tooltip);
			tooltip = null;
		}
	}

	private function onMouseOver(event: MouseEvent) {
		tooltip = new TextToolTip(2565927, 8553090, null, this.tooltipText);
		stage.addChild(tooltip);
	}

	private function onRollOut(event: MouseEvent) {
		this.removeToolTip();
	}

	private function onRemovedFromStage(event: Event) {
		this.removeToolTip();
	}
}
