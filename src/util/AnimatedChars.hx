package util;

import haxe.ds.StringMap;
import openfl.display.BitmapData;

class AnimatedChars {
	private static var nameMap: StringMap<Array<AnimatedChar>> = new StringMap<Array<AnimatedChar>>();

	public static function getAnimatedChar(name: String, id: Int) {
		var chars = nameMap.get(name);
		if (chars == null || id >= chars.length) {
			trace('Could not parse anim char: $name (id: $id, exists: ${nameMap.exists(name)}, charsLen: ${nameMap.get(name)?.length})');
			return null;
		}

		return chars[id];
	}

	public static function add(name: String, images: BitmapData, masks: BitmapData, charWidth: Int, charHeight: Int,
			sheetWidth: Int, sheetHeight: Int) {
		var chars = new Array<AnimatedChar>();
		var charImages = new MaskedImageSet();
		charImages.addFromBitmapData(images, masks, sheetWidth, sheetHeight, true);
		for (image in charImages.images)
			chars.push(new AnimatedChar(image, charWidth, charHeight));

		nameMap.set(name, chars);

		images.dispose();
		images = null;

		if (masks != null) {
			masks.dispose();
			masks = null;
		}
	}
}
