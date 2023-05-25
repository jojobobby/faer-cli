package ui.tooltip;

import openfl.filters.DropShadowFilter;
import ui.SimpleText;

class TextToolTip extends ToolTip {
	public var titleText: SimpleText;
	public var tipText: SimpleText;

	public function new(background: Int, outline: Int, title: String, text: String) {
		super(background, 0.6, outline, 1);

		this.tipText = new SimpleText(12, 0xB3B3B3);
		this.tipText.filters = [new DropShadowFilter(0, 0, 0)];

		if (text != null) {
			this.tipText.text = text;
			this.tipText.updateMetrics();
			addChild(this.tipText);
		}

		this.titleText = new SimpleText(16, 0xFFFFFF);
		this.titleText.setBold(true);
		this.titleText.filters = [new DropShadowFilter(0, 0, 0)];

		if (title != null) {
			this.titleText.text = title;
			this.titleText.updateMetrics();
			addChild(this.titleText);

			this.tipText.y = this.titleText.height + 8;
		}
	}

	public function setTitle(title: String) {
		if (this.titleText == null)
			return;

		if (!contains(this.titleText))
			addChild(this.titleText);

		this.titleText.text = title;
		this.titleText.updateMetrics();
		draw();
	}

	public function setText(text: String) {
		if (this.tipText == null)
			return;

		if (!contains(this.tipText))
			addChild(this.tipText);

		this.tipText.text = text;
		this.tipText.updateMetrics();
		draw();
	}
}
