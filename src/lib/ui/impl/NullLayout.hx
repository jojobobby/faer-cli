package lib.ui.impl;

import lib.ui.api.Layout;
import openfl.display.DisplayObject;

class NullLayout implements Layout {
	public function new() {}

	public function getPadding() {
		return 0;
	}

	public function setPadding(value: Int) {}

	public function layout(elements: Array<DisplayObject>, offset: Int = 0) {}
}
