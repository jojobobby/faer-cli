package lib.ui.api;

import openfl.display.DisplayObject;

interface Layout {
	function getPadding(): Int;
	function setPadding(pad: Int): Void;
	function layout(items: Array<DisplayObject>, offset: Int = 0): Void;
}
