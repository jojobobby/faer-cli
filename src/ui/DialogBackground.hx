package ui;

import openfl.display.CapsStyle;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import util.BevelRect;
import util.GraphicsHelper;

class DialogBackground extends Sprite {
	private static inline var BEVEL: Int = 4;

	public function draw(width: Int, height: Int) {
		var rect: BevelRect = new BevelRect(width, height, BEVEL);
		var helper: GraphicsHelper = new GraphicsHelper();
		graphics.lineStyle(1, 0xFFFFFF, 1, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3);
		graphics.beginFill(0x363636);
		helper.drawBevelRect(0, 0, rect, graphics);
		graphics.endFill();
	}
}
