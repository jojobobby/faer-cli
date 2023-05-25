package ui.view;
import openfl.display.Sprite;
import ui.SoundIcon;

class ScreenBase extends Sprite {
	private var map: MapBackground;
	private var soundIcon: SoundIcon;

	public function new() {
		super();

		this.map = new MapBackground();
		addChild(this.map);
		this.soundIcon = new SoundIcon();
		this.soundIcon.x = 2;
		addChild(this.soundIcon);
	}
}