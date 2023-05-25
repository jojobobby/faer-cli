package assets;

import openfl.display.BitmapData;
import util.AssetLibrary;
import util.BitmapUtil;
import util.GlowRedrawer;
import util.TextureRedrawer;

class IconFactory {
	public static function makeGems() {
		return cropAndGlowIcon(TextureRedrawer.resize(AssetLibrary.getImageFromSet("misc", 21), 40, true));
	}

	public static function makeGold() {
		return cropAndGlowIcon(TextureRedrawer.resize(AssetLibrary.getImageFromSet("misc", 20), 40, true));
	}

	private static function cropAndGlowIcon(data: BitmapData) {
		data = GlowRedrawer.outlineGlow(data, 0xFFFFFFFF);
		data = BitmapUtil.cropToBitmapData(data, 10, 10, data.width - 20, data.height - 20);
		return data;
	}
}
