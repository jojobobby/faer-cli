package mapeditor;

import ui.tooltip.ToolTip;
import ui.SimpleText;
import openfl.filters.DropShadowFilter;

using util.Utils;

class ObjectTypeToolTip extends ToolTip {
	private static inline var MAX_WIDTH = 180;

	private var titleText: SimpleText;
	private var descText: SimpleText;

	public function new(objectXML: Xml) {
		super(0x363636, 1, 0x9B9B9B, 1, true);
		this.titleText = new SimpleText(16, 0xFFFFFF, false, MAX_WIDTH - 4, 0);
		this.titleText.setBold(true);
		this.titleText.wordWrap = true;
		this.titleText.text = objectXML.attribute("id");
		this.titleText.useTextDimensions();
		this.titleText.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		this.titleText.x = 0;
		this.titleText.y = 0;
		addChild(this.titleText);

		var desc = "";
		if (objectXML.elementExists("Static"))
			desc += "Static\n";
		if (objectXML.elementExists("Enemy")) {
			desc += "Enemy\n";
			if (objectXML.elementExists("MaxHitPoints"))
				desc += "MaxHitPoints: " + objectXML.element("MaxHitPoints") + "\n";
			if (objectXML.elementExists("Defense"))
				desc += "Defense: " + objectXML.element("Defense") + "\n";
		}

		this.descText = new SimpleText(14, 0xB3B3B3, false, MAX_WIDTH, 0);
		this.descText.wordWrap = true;
		this.descText.text = desc;
		this.descText.useTextDimensions();
		this.descText.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		this.descText.x = 0;
		this.descText.y = this.titleText.height + 2;
		addChild(this.descText);
	}
}
