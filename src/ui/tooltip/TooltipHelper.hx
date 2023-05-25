package ui.tooltip;

class TooltipHelper {
	public static inline var BETTER_COLOR: String = "#00ff00";
	public static inline var WORSE_COLOR: String = "#ff0000";
	public static inline var NO_DIFF_COLOR: String = "#FFFF8F";

	public static function wrapInFontTag(text: String, color: String) {
		var tagStr: String = "<font color=\"" + color + "\">" + text + "</font>";
		return tagStr;
	}

	public static function getFormattedString(elem: Float) {
		var decimalPart: Float = elem - Std.int(elem);
		return Std.string(elem);
	}

	public static function getTextColor(difference: Float) {
		if (difference < 0)
			return WORSE_COLOR;

		if (difference > 0)
			return BETTER_COLOR;

		return NO_DIFF_COLOR;
	}
}
