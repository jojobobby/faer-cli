package ui.tooltip;

import openfl.display.Sprite;
import openfl.events.Event;

class TooltipsView extends Sprite {
	private var toolTip: ToolTip;

	public function new() {
		super();
	}

	public function show(toolTip: ToolTip) {
		this.hide();
		this.toolTip = toolTip;
		if (toolTip != null)
			addChild(toolTip);
	}

	public function hide() {
		this.toolTip?.parent?.removeChild(this.toolTip);
		this.toolTip = null;
	}
}
