package core;

import openfl.display.Sprite;
import openfl.events.Event;

class ScreensView extends Sprite {
	private var current: Sprite;
	private var previous: Sprite;

	public function new() {
		super();
	}

	public function setScreen(sprite: Sprite) {
		if (this.current == sprite)
			return;

		this.removePrevious();
		this.current = sprite;
		addChild(sprite);
	}

	private function removePrevious() {
		if (this.current != null && contains(this.current)) {
			this.previous = this.current;
			removeChild(this.current);
		}
	}
}
