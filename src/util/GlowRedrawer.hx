package util;
import openfl.geom.Point;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.BlendMode;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.GlowFilter;

class GlowRedrawer {
	private static var GLOW_FILTER = new GlowFilter(0, 1, 4, 4, 0xFF, BitmapFilterQuality.HIGH, false, false);

	private static var glowHashes = new Map<BitmapData, Map<Int, BitmapData>>();

	public static function outlineGlow(texture: BitmapData, glowColor: Int, outlineSize: Float = 1.4,
									   caching: Bool = true, outlineColor: Int = 0) {
		var hash = getHash(glowColor, outlineSize, outlineColor);
		if (caching && isCached(texture, hash))
			return glowHashes.get(texture).get(hash);

		var newTexture: BitmapData = texture.clone();
		var origBitmap: Bitmap = new Bitmap(texture);
		newTexture.draw(origBitmap, null, null, BlendMode.ALPHA);
		for (x in 0...newTexture.width)
			for (y in 0...newTexture.height) {
				if (((newTexture.getPixel32(x, y) >> 24) & 0xFF) / 255 == 0 && (
					((newTexture.getPixel32(x - 1, y - 1) >> 24) & 0xFF) / 255 != 0 &&
						newTexture.getPixel(x - 1, y - 1) != 0 ||
					((newTexture.getPixel32(x - 1, y + 1) >> 24) & 0xFF) / 255 != 0 &&
						newTexture.getPixel(x - 1, y + 1) != 0 ||
					((newTexture.getPixel32(x + 1, y - 1) >> 24) & 0xFF) / 255 != 0 &&
						newTexture.getPixel(x + 1, y - 1) != 0 ||
					((newTexture.getPixel32(x + 1, y + 1) >> 24) & 0xFF) / 255 != 0 &&
						newTexture.getPixel(x + 1, y + 1) != 0))
					newTexture.setPixel32(x, y, 0xFF000000);
			}
			
		if (glowColor != -1) {
			GLOW_FILTER.color = glowColor;
			newTexture.applyFilter(newTexture, newTexture.rect, new Point(0, 0), GLOW_FILTER);
		}

		if (caching)
			cache(texture, glowColor, outlineSize, newTexture, outlineColor);

		return newTexture;
	}

	private static function cache(texture: BitmapData, glowColor: Int, outlineSize: Float, newTexture: BitmapData, outlineColor: Int) {
		var hash = getHash(glowColor, outlineSize, outlineColor);
		if (glowHashes.get(texture) != null)
			glowHashes.get(texture).set(hash, newTexture);
		else {
			var glowHash = new Map<Int, BitmapData>();
			glowHash.set(hash, newTexture);
			glowHashes.set(texture, glowHash);
		}
	}

	private static function isCached(texture: BitmapData, hash: Int) {
		var outlineHash = glowHashes.get(texture);
		return outlineHash != null && outlineHash.exists(hash);
	}

	private static function getHash(glowColor: Int, outlineSize: Float, outlineColor: Int) {
		return Std.int(outlineSize * 10 + glowColor + outlineColor);
	}
}