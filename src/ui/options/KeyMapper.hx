package ui.options;

import openfl.events.Event;
import util.Settings;
import util.Utils;

class KeyMapper extends Option {
	private var keyCodeBox: KeyCodeBox;
	private var disabled = false;

	public function new(paramName: String, desc: String, tooltipText: String, disabled: Bool = false) {
		super(paramName, desc, tooltipText);
		this.keyCodeBox = new KeyCodeBox(Reflect.getProperty(Settings, paramName));
		this.keyCodeBox.addEventListener(Event.CHANGE, this.onChange);
		addChild(this.keyCodeBox);
		this.setDisabled(disabled);
	}

	override public function refresh() {
		this.keyCodeBox.setKeyCode(Reflect.getProperty(Settings, paramName));
	}

	public function setDisabled(disabled: Bool) {
		this.disabled = disabled;
		transform.colorTransform = this.disabled ? ColorUtils.darkCT : ColorUtils.identity;
		mouseEnabled = !this.disabled;
		mouseChildren = !this.disabled;
	}

	private function onChange(event: Event) {
		Reflect.setProperty(Settings, paramName, this.keyCodeBox.value());
		Settings.save();
	}
}
