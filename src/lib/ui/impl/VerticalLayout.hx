package lib.ui.impl;

import lib.ui.api.Layout;
import openfl.display.DisplayObject;

class VerticalLayout implements Layout {
	private var padding = 0;

	public function new() {}

	public function getPadding() {
		return this.padding;
	}

	public function setPadding(value: Int) {
		this.padding = value;
	}

	public function layout(elements: Array<DisplayObject>, offset: Int = 0) {
		var element: DisplayObject = null;
		var y: Int = offset;
		var length: Int = elements.length;
		for (i in 0...length) {
			element = elements[i];
			element.y = y;
			y += cast element.height + this.padding;
		}
	}
}
