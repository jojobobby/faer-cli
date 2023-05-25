package ui;

import openfl.display.Sprite;

class DeleteXGraphic extends Sprite {
	public function new() {
		super();

		graphics.clear();
		graphics.lineStyle(2, 0x666666);
		graphics.beginFill(0x1B1B1B);
		graphics.drawRoundRect(-13, 0, 26, 26, 10);
		graphics.lineStyle(4, 0xFFFFFF);
		graphics.moveTo(-5, 8);
		graphics.lineTo(5, 18);
		graphics.moveTo(5, 8);
		graphics.lineTo(-5, 18);
	}
}
