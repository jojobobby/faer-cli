package util;

import openfl.display.Graphics;

class GraphicsHelper {
	public static function drawBevelRect(x: Int, y: Int, rect: BevelRect, graphics: Graphics) {
		var right: Int = x + rect.width;
		var bottom: Int = y + rect.height;
		var bevel: Int = rect.bevel;
		if (rect.topLeftBevel) {
			graphics.moveTo(x, y + bevel);
			graphics.lineTo(x + bevel, y);
		} else {
			graphics.moveTo(x, y);
		}
		if (rect.topRightBevel) {
			graphics.lineTo(right - bevel, y);
			graphics.lineTo(right, y + bevel);
		} else {
			graphics.lineTo(right, y);
		}
		if (rect.bottomRightBevel) {
			graphics.lineTo(right, bottom - bevel);
			graphics.lineTo(right - bevel, bottom);
		} else {
			graphics.lineTo(right, bottom);
		}
		if (rect.bottomLeftBevel) {
			graphics.lineTo(x + bevel, bottom);
			graphics.lineTo(x, bottom - bevel);
		} else {
			graphics.lineTo(x, bottom);
		}
	}
}
