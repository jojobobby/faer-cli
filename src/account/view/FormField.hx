package account.view;
import openfl.display.CapsStyle;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import ui.SimpleText;

class FormField extends Sprite {
	public static inline var BACKGROUND_COLOR = 0x333333;
	public static inline var ERROR_BORDER_COLOR = 0xFC8642;
	public static inline var NORMAL_BORDER_COLOR = 0x454545;
	public static inline var TEXT_COLOR = 0xB3B3B3;

	public function getHeight() {
		return 0;
	}

	public function drawSimpleTextBackground(simpleText: SimpleText, hPadding: Int, vPadding: Int, hasError: Bool) {
		var borderColor = hasError ? ERROR_BORDER_COLOR : NORMAL_BORDER_COLOR;
		graphics.lineStyle(2, borderColor, 1, false, LineScaleMode.NORMAL, CapsStyle.ROUND, JointStyle.ROUND);
		graphics.beginFill(BACKGROUND_COLOR, 1);
		graphics.drawRect(simpleText.x - hPadding - 5, simpleText.y - vPadding, simpleText.width + hPadding * 2, simpleText.height + vPadding * 2);
		graphics.endFill();
		graphics.lineStyle();
	}
}