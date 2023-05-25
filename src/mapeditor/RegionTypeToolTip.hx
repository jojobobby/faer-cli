package mapeditor;

import ui.SimpleText;
import ui.tooltip.ToolTip;
import openfl.filters.DropShadowFilter;

using util.Utils;

class RegionTypeToolTip extends ToolTip {
	private static inline var MAX_WIDTH = 180;

	private var titleText: SimpleText;

	public function new(regionXML: Xml) {
		super(0x363636, 1, 0x9B9B9B, 1, true);
		this.titleText = new SimpleText(16, 0xFFFFFF, false, MAX_WIDTH - 4, 0);
		this.titleText.setBold(true);
		this.titleText.wordWrap = true;
		this.titleText.text = regionXML.attribute("id");
		this.titleText.useTextDimensions();
		this.titleText.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		this.titleText.x = 0;
		this.titleText.y = 0;
		addChild(this.titleText);
	}
}
