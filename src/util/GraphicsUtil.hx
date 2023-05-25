package util;

import openfl.display.Graphics;
import openfl.display.GraphicsEndFill;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsStroke;

class GraphicsUtil {
	public static var END_FILL = new GraphicsEndFill();
	public static var END_STROKE = new GraphicsStroke();
	public static var ALL_CUTS = [1, 1, 1, 1];

	public static function clearPath(graphicsPath: GraphicsPath) {
		if (graphicsPath.commands != null)
			graphicsPath.commands.splice(0, graphicsPath.commands.length);
		if (graphicsPath.data != null)
			graphicsPath.data.splice(0, graphicsPath.data.length);
	}

	public static function drawRect(x: Int, y: Int, width: Int, height: Int, path: GraphicsPath) {
		path.moveTo(x, y);
		path.lineTo(x + width, y);
		path.lineTo(x + width, y + height);
		path.lineTo(x, y + height);
	}

	public static function drawCutEdgeRect(x: Int, y: Int, width: Int, height: Int, cutLen: Int, cuts: Array<Int>, path: GraphicsPath) {
		if (cuts[0] != 0) {
			path.moveTo(x, y + cutLen);
			path.lineTo(x + cutLen, y);
		} else {
			path.moveTo(x, y);
		}
		if (cuts[1] != 0) {
			path.lineTo(x + width - cutLen, y);
			path.lineTo(x + width, y + cutLen);
		} else {
			path.lineTo(x + width, y);
		}
		if (cuts[2] != 0) {
			path.lineTo(x + width, y + height - cutLen);
			path.lineTo(x + width - cutLen, y + height);
		} else
			path.lineTo(x + width, y + height);

		if (cuts[3] != 0) {
			path.lineTo(x + cutLen, y + height);
			path.lineTo(x, y + height - cutLen);
		} else {
			path.lineTo(x, y + height);
		}
		if (cuts[0] != 0) {
			path.lineTo(x, y + cutLen);
		} else {
			path.lineTo(x, y);
		}
	}

	public static function drawCutEdgeRectGfx(x: Int, y: Int, width: Int, height: Int, cutLen: Int, cuts: Array<Int>, graphics: Graphics) {
		if (cuts[0] != 0) {
			graphics.moveTo(x, y + cutLen);
			graphics.lineTo(x + cutLen, y);
		} else {
			graphics.moveTo(x, y);
		}
		if (cuts[1] != 0) {
			graphics.lineTo(x + width - cutLen, y);
			graphics.lineTo(x + width, y + cutLen);
		} else {
			graphics.lineTo(x + width, y);
		}
		if (cuts[2] != 0) {
			graphics.lineTo(x + width, y + height - cutLen);
			graphics.lineTo(x + width - cutLen, y + height);
		} else
			graphics.lineTo(x + width, y + height);

		if (cuts[3] != 0) {
			graphics.lineTo(x + cutLen, y + height);
			graphics.lineTo(x, y + height - cutLen);
		} else {
			graphics.lineTo(x, y + height);
		}
		if (cuts[0] != 0) {
			graphics.lineTo(x, y + cutLen);
		} else {
			graphics.lineTo(x, y);
		}
	}

	public static function drawDiamond(x: Float, y: Float, radius: Float, path: GraphicsPath) {
		path.moveTo(x, y - radius);
		path.lineTo(x + radius, y);
		path.lineTo(x, y + radius);
		path.lineTo(x - radius, y);
	}
}
