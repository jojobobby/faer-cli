package util;
import haxe.ds.IntMap;
import openfl.display.BitmapData;
import openfl.geom.ColorTransform;
import openfl.geom.Matrix;
import openfl.geom.Rectangle;

class TextureRedrawer {
	public static inline var magic = 12;
	public static inline var minSize = 2 * magic;
	public static var caches = new IntMap<BitmapData>();
	public static var faceCaches = new IntMap<Map<BitmapData, BitmapData>>();
	public static var redrawCaches = new Map<BitmapData, IntMap<BitmapData>>();
	public static var hpBarCaches = new IntMap<BitmapData>();

	public static function redraw(tex: BitmapData, size: Int, padBottom: Bool, glowColor: Int,
	                              useCache: Bool = true, sMult: Float = 5, noAlphaTrim: Bool = false) {
		var hash = getHash(size, padBottom, glowColor, sMult);
		if (useCache && isCached(tex, hash))
			return redrawCaches.get(tex).get(hash);

		var modTex = resize(tex, size, padBottom, sMult);
		modTex = GlowRedrawer.outlineGlow(modTex, glowColor, 1.4, useCache);
		if (!noAlphaTrim)
			modTex = BitmapUtil.trimAlpha(modTex);

		if (useCache)
			cache(tex, hash, modTex);

		return modTex;
	}

	public static function resize(tex: BitmapData, size: Int, padBottom: Bool, sMult: Float = 5) {
		var w = Math.round(sMult * size / 100 * tex.width),
			h = Math.round(sMult * size / 100 * tex.height);
		var m = new Matrix();
		m.scale(w / tex.width, h / tex.height);
		m.translate(magic, magic);
		var ret = new BitmapData(w + minSize, h + (padBottom ? magic : 2) + magic, true, 0);
		ret.draw(tex, m);
		return ret;
	}

	public static function redrawSolidSquare(color: Int, size: Int) {
		var hash = size * 907 + color;
		var tex = caches.get(hash);
		if (tex != null)
			return tex;

		tex = new BitmapData(size + 2, size + 2, false, 0);
		tex.fillRect(new Rectangle(1, 1, size, size), 0xFF000000 | color);

		caches.set(hash, tex);
		return tex;
	}

	public static function redrawHPBar(outColor: Int, outFillColor: Int, fillColor: Int, width: Int, height: Int, hpPerc: Float) {
		var hash = Std.int(((((width * 907 + height) * 911 + outFillColor) * 919 + fillColor) * 929 + hpPerc) * 937 + outColor);
		var tex = hpBarCaches.get(hash);
		if (tex != null)
			return tex;

		tex = new BitmapData(width, height, false, outColor);
		tex.fillRect(new Rectangle(0, 0, width - 2, height - 2), 0xFF000000 | outFillColor);

		var hpW = Math.round((width - 2) * hpPerc);
		if (hpW <= 0) {
			hpBarCaches.set(hash, tex);
			return tex;
		}

		tex.fillRect(new Rectangle(1, 1, hpW, height - 2), 0xFF000000 | fillColor);

		hpBarCaches.set(hash, tex);
		return tex;
	}

	public static function clearCache() {
		for (tex in caches) {
			tex.dispose();
			tex = null;
		}

		caches.clear();

		for (dict in faceCaches)
			for (tex in dict.keys()) {
				var modTex = dict[tex];
				modTex.dispose();
				modTex = null;
				tex.dispose();
				tex = null;
			}

		faceCaches.clear();

		for (dict in redrawCaches)
			for (tex in dict) {
				tex.dispose();
				tex = null;
			}

		redrawCaches.clear();
	}

	public static function redrawFace(tex: BitmapData, shade: Float) {
		if (shade == 1)
			return tex;

		var shadeRound = Math.round(shade * 100);
		var dict = faceCaches.get(shadeRound);
		if (dict == null) {
			dict = new Map<BitmapData, BitmapData>();
			faceCaches.set(shadeRound, dict);
		}

		var modTex = dict.get(tex);
		if (modTex != null)
			return modTex;

		modTex = tex.clone();
		modTex.colorTransform(modTex.rect, new ColorTransform(shade, shade, shade));
		dict.set(tex, modTex);
		return modTex;
	}

	private static function getHash(size: Int, padBottom: Bool, glowColor: Int, sMult: Float) {
		var h: Int = (padBottom ? (1 << 27) : 0) | Std.int(size * sMult);
		return h * 1000002449 + glowColor;
	}

	private static function cache(tex: BitmapData, hash: Int, modifiedTex: BitmapData) {
		if (!redrawCaches.exists(tex))
			redrawCaches.set(tex, new IntMap<BitmapData>());

		redrawCaches.get(tex).set(hash, modifiedTex);
	}

	private static function isCached(tex: BitmapData, hash: Int) {
		var texCache = redrawCaches.get(tex);
		return texCache != null && texCache.exists(hash);
	}
}