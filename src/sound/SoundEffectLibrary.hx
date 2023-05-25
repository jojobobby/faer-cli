package sound;

import haxe.ds.StringMap;
import lime.utils.Assets;
import lime.media.AudioSource;
import util.Settings;

class SoundEffectLibrary {
	private static var sfxCache = new StringMap<AudioSource>();

	public static function play(name: String, volume: Float = 1.0, isFX: Bool = true) {
		var playFX = Settings.playSfx && isFX || !isFX && Settings.playWepSfx;
		if (!playFX)
			return;

		if (sfxCache.exists(name))
			sfxCache.get(name).play();

		var sound = new AudioSource(Assets.getAudioBuffer('assets/sfx/$name.ogg'));
		sound.gain = volume;
		sound.play();

		sfxCache.set(name, sound);
	}

	public static function setPlaySFX(playSFX: Bool) {
		Settings.playSfx = !Settings.playSfx;
		Settings.save();
	}
}
