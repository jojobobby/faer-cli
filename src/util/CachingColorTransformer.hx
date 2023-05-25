package util;

import openfl.display.BitmapData;
import openfl.geom.ColorTransform;

class CachingColorTransformer {
	private static var bds: Map<BitmapData, Map<ColorTransform, BitmapData>> = new Map<BitmapData, Map<ColorTransform, BitmapData>>();

	public static function transformBitmapData(bitmapData: BitmapData, ct: ColorTransform) {
		var newBitmapData: BitmapData = null;
		var object = bds.get(bitmapData);
		if (object != null)
			newBitmapData = object.get(ct);
		else {
			object = new Map<ColorTransform, BitmapData>();
			bds.set(bitmapData, object);
		}

		if (newBitmapData == null) {
			newBitmapData = bitmapData.clone();
			newBitmapData.colorTransform(newBitmapData.rect, ct);
			object.set(ct, newBitmapData);
		}

		return newBitmapData;
	}

	public static function clear() {
		for (obj in bds)
			for (objTex in obj)
				objTex.dispose();

		bds.clear();
	}
}
