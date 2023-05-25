package assets;

import openfl.display.BitmapData;
import util.AnimatedChar;
import util.AnimatedChars;
import util.BitmapUtil;
import util.GlowRedrawer;
import util.MaskedImage;
import util.TextureRedrawer;

class CharacterFactory {
	public static function makeCharacter(template: CharacterTemplate): AnimatedChar {
		return AnimatedChars.getAnimatedChar(template.file, template.index);
	}

	public static function makeIcon(template: CharacterTemplate, size: Int = 100) {
		var character: AnimatedChar = makeCharacter(template);
		var data: BitmapData = makeFrame(character, AnimatedChar.STAND, 0, size);
		data = GlowRedrawer.outlineGlow(data, 0);
		data = BitmapUtil.cropToBitmapData(data, 6, 6, data.width - 12, data.height - 6);
		return data;
	}

	public static function makeWalkingIcon(template: CharacterTemplate, size: Int = 100): Animation {
		var character: AnimatedChar = makeCharacter(template);
		var first: BitmapData = makeFrame(character, AnimatedChar.WALK, 0.5, size);
		first = GlowRedrawer.outlineGlow(first, 0);
		var second: BitmapData = makeFrame(character, AnimatedChar.WALK, 0, size);
		second = GlowRedrawer.outlineGlow(second, 0);
		var animation: Animation = new Animation();
		animation.setFrames([first, second]);
		return animation;
	}

	private static function makeFrame(character: AnimatedChar, action: Int, offset: Float, size: Int) {
		var data: MaskedImage = character.imageFromDir(AnimatedChar.RIGHT, action, offset);
		return TextureRedrawer.resize(data.image, size, false);
	}
}
