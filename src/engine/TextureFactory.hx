package engine;

import haxe.ds.ObjectMap;
import engine.GLTextureData;
import openfl.display.BitmapData;
import openfl.geom.Point;

class TextureFactory {
	private static var textures: ObjectMap<BitmapData, GLTextureData> = new ObjectMap<BitmapData, GLTextureData>();
	private static var count = 0;

	public static function disposeTextures() {
		textures.clear();
		count = 0;
	}

	public static function disposeNormalTextures() {
		textures.clear();
		count = 0;
	}

	public static inline function getNextPowerOf2(value: Int) {
		value--;
		value |= value >> 1;
		value |= value >> 2;
		value |= value >> 4;
		value |= value >> 8;
		value |= value >> 16;
		return ++value;
	}

	public static inline function make(bitmapData: BitmapData, needsPad: Bool = true) {
		if (bitmapData == null)
			return null;

		if (textures.exists(bitmapData))
			return textures.get(bitmapData);

		if (bitmapData.image == null)
			return null;

		var preW = bitmapData.width;
		var preH = bitmapData.height;
		var pad = needsPad ? 4 : 0;
		var width = getNextPowerOf2(bitmapData.width + pad);
		var height = getNextPowerOf2(bitmapData.height + pad);
		var xOff = (width - preW) / 2;
		var yOff = (height - preH) / 2;

		var bitmapTexture = new BitmapData(width, height, true, 0);
		bitmapTexture.copyPixels(bitmapData, bitmapData.rect, needsPad ? new Point(xOff == 0 ? 2 : xOff, yOff == 0 ? 2 : yOff) : new Point(0, 0));

		var texture = new GLTextureData(width, height, bitmapTexture);
		texture.xOffset = xOff;
		texture.yOffset = yOff;

		if (count > 1000) {
			disposeNormalTextures();
			count = 0;
		}

		textures.set(bitmapData, texture);
		count++;
		return texture;
	}
}
