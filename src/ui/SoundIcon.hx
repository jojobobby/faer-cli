package ui;

import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.GlowFilter;
import sound.Music;
import sound.SoundEffectLibrary;
import util.AssetLibrary;
import util.Settings;

class SoundIcon extends Sprite {
	private var bitmap: Bitmap;

	public function new() {
		super();

		this.bitmap = new Bitmap();
		addChild(this.bitmap);
		this.bitmap.scaleX = 2;
		this.bitmap.scaleY = 2;
		this.setBitmap();
		addEventListener(MouseEvent.CLICK, this.onIconClick);
		filters = [new GlowFilter(0, 1, 4, 4, 2, 1)];
	}

	private function setBitmap() {
		this.bitmap.bitmapData = Settings.playMusic
			|| Settings.playSfx ? AssetLibrary.getImageFromSet("misc16", 18) : AssetLibrary.getImageFromSet("misc16", 17);
	}

	private function onIconClick(event: MouseEvent) {
		var value = !(Settings.playMusic || Settings.playSfx);
		Music.setPlayMusic(value);
		SoundEffectLibrary.setPlaySFX(value);
		Settings.playWepSfx = value;
		Settings.save();
		this.setBitmap();
	}
}
