package ui.panels;

import game.GameSprite;
import openfl.display.Sprite;

class Panel extends Sprite {
	public static inline var WIDTH: Int = 200 - 12;
	public static inline var HEIGHT: Int = 100 - 16;

	public var gs: GameSprite;

	public function new(gs: GameSprite) {
		super();

		this.gs = gs;
	}

	public function draw() {}
}
