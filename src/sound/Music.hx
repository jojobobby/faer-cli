package sound;

import lime.utils.Assets;
import lime.media.AudioSource;
import util.Utils;
import util.Settings;

class Music {
	private static var music: AudioSource;

	public static function load() {
		music = new AudioSource(Assets.getAudioBuffer("assets/music/sorc.ogg"));
		music.loops = MathUtil.INT_MAX;
		music.gain = 0.3;
		if (Settings.playMusic)
			music.play();
	}

	public static function setPlayMusic(playMusic: Bool) {
		Settings.playMusic = !Settings.playMusic;
		Settings.save();

		if (music != null) {
			if (!playMusic)
				music.stop();
			else
				music.play();
		}
	}
}
