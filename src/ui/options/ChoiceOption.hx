package ui.options;

import openfl.events.Event;
import util.Settings;

class ChoiceOption extends Option {
	private var callback: () -> Void;
	private var choiceBox: ChoiceBox;

	public function new(paramName: String, labels: Array<String>, values: Array<Dynamic>, desc: String, tooltipText: String, callback: () -> Void) {
		super(paramName, desc, tooltipText);
		this.callback = callback;
		this.choiceBox = new ChoiceBox(labels, values, Reflect.getProperty(Settings, paramName));
		this.choiceBox.addEventListener(Event.CHANGE, this.onChange);
		addChild(this.choiceBox);
	}

	override public function refresh() {
		this.choiceBox.setValue(Reflect.getProperty(Settings, paramName));
	}

	private function onChange(event: Event) {
		Reflect.setProperty(Settings, paramName, this.choiceBox.value());
		Settings.save();
		if (this.callback != null)
			this.callback();
	}
}
