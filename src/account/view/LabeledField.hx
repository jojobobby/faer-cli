package account.view;

import account.view.FormField;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;

class LabeledField extends FormField {
	public var nameText: SimpleText;
	public var inputText: SimpleText;
	public var isHighlighted = false;

	public function new(name: String, isPassword: Bool, w: Int = 238, h: Int = 30) {
		super();

		this.nameText = new SimpleText(18, FormField.TEXT_COLOR, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.text = name;
		this.nameText.updateMetrics();
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.nameText);
		this.inputText = new SimpleText(20, FormField.TEXT_COLOR, true, w, h);
		this.inputText.y = 30;
		this.inputText.x = 6;
		this.inputText.border = false;
		this.inputText.displayAsPassword = isPassword;
		this.inputText.updateMetrics();
		addChild(this.inputText);
		this.setErrorHighlight(false);
	}

	override public function getHeight() {
		return 68;
	}

	public function text() {
		return this.inputText.text;
	}

	public function setErrorHighlight(hasError: Bool) {
		this.isHighlighted = hasError;
		drawSimpleTextBackground(this.inputText, 0, 0, hasError);
	}
}
