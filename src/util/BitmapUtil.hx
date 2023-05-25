package util;

import haxe.ds.IntMap;
import openfl.display.BitmapData;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import util.Utils;

class BitmapUtil {
	public static function trimAlpha(tex: BitmapData) {
		if (tex.width == 0 || tex.height == 0)
			return tex;

		var colorBounds: Rectangle = tex.getColorBoundsRect(0xFF000000, 0, false);
		if (colorBounds.width == 0 || colorBounds.height == 0)
			return tex;

		var modTex: BitmapData = new BitmapData(Std.int(colorBounds.width), Std.int(colorBounds.height), true, 0);
		modTex.copyPixels(tex, colorBounds, new Point());
		return modTex;
	}

	public static function mirror(bitmapData: BitmapData, width: Int = 0) {
		if (width == 0)
			width = bitmapData.width;

		var mirrored: BitmapData = new BitmapData(bitmapData.width, bitmapData.height, true, 0);
		for (x in 0...bitmapData.width)
			for (y in 0...bitmapData.height)
				mirrored.setPixel32(width - x - 1, y, bitmapData.getPixel32(x, y));

		return mirrored;
	}

	public static function rotateBitmapData(bitmapData: BitmapData, clockwiseTurns: Int) {
		var matrix: Matrix = new Matrix();
		matrix.translate(-bitmapData.width / 2, -bitmapData.height / 2);
		matrix.rotate(clockwiseTurns * MathUtil.PI / 2);
		matrix.translate(bitmapData.height / 2, bitmapData.width / 2);
		var rotated: BitmapData = new BitmapData(bitmapData.height, bitmapData.width, true, 0);
		rotated.draw(bitmapData, matrix);
		return rotated;
	}

	public static function cropToBitmapData(bitmapData: BitmapData, x: Int, y: Int, width: Int, height: Int) {
		var cropped: BitmapData = new BitmapData(width, height);
		cropped.copyPixels(bitmapData, new Rectangle(x, y, width, height), new Point(0, 0));
		return cropped;
	}

	public static function amountTransparent(bitmapData: BitmapData) {
		var alpha = 0;
		var trans = 0;
		for (x in 0...bitmapData.width)
			for (y in 0...bitmapData.height) {
				alpha = bitmapData.getPixel32(x, y) & 0xFF000000;
				if (alpha == 0)
					trans++;
			}

		return trans / (bitmapData.width * bitmapData.height);
	}

	public static function mostCommonColor(bitmapData: BitmapData) {
		if (bitmapData == null)
			return 0;

		var color = 0;
		var colors = new IntMap<Int>();
		for (x in 0...bitmapData.width)
			for (y in 0...bitmapData.height) {
				color = bitmapData.getPixel32(x, y);
				if ((color & 0xFF000000) != 0) {
					if (!colors.exists(color))
						colors.set(color, 1);
					else
						colors.set(color, colors.get(color) + 1);
				}
			}

		var bestColor = 0;
		var bestCount = 0;
		for (color in colors.keys()) {
			var count = colors.get(color);
			if (count > bestCount || count == bestCount && color > bestColor) {
				bestColor = color;
				bestCount = count;
			}
		}

		return bestColor;
	}
}
