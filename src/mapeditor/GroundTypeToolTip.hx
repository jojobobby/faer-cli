package mapeditor;

import ui.tooltip.ToolTip;
import ui.SimpleText;
import openfl.filters.DropShadowFilter;

using util.Utils;

class GroundTypeToolTip extends ToolTip {
	private static inline var MAX_WIDTH = 180;

	private var titleText: SimpleText;
	private var descText: SimpleText;

	public function new(groundXML: Xml) {
		super(3552822, 1, 10197915, 1, true);
		this.titleText = new SimpleText(16, 16777215, false, MAX_WIDTH - 4, 0);
		this.titleText.setBold(true);
		this.titleText.wordWrap = true;
		this.titleText.text = groundXML.attribute("id");
		this.titleText.useTextDimensions();
		this.titleText.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		this.titleText.x = 0;
		this.titleText.y = 0;
		addChild(this.titleText);
		var desc = "";
		if (groundXML.elementExists("Speed"))
			desc += "Speed: " + groundXML.floatElement("Speed") + "\n";
		else
			desc += "Speed: 1.00\n";

		if (groundXML.elementExists("NoWalk"))
			desc += "Unwalkable\n";

		if (groundXML.elementExists("Push"))
			desc += "Push\n";

		if (groundXML.elementExists("Sink"))
			desc += "Sink\n";

		if (groundXML.elementExists("Sinking"))
			desc += "Sinking\n";

		if (groundXML.elementExists("Animate"))
			desc += "Animated\n";

		this.descText = new SimpleText(14, 11776947, false, MAX_WIDTH, 0);
		this.descText.wordWrap = true;
		this.descText.text = desc;
		this.descText.useTextDimensions();
		this.descText.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		this.descText.x = 0;
		this.descText.y = this.titleText.height + 2;
		addChild(this.descText);
	}
}
