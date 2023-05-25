package ui.options;

import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.MouseEvent;
import openfl.geom.ColorTransform;
import util.AssetLibrary;
import util.Utils;
import util.TextureRedrawer;

class KeyCodeBox extends Sprite {
	public static inline var WIDTH = 50;
	public static inline var HEIGHT = 50;

	public var keyCode = 0;
	public var selected = false;
	public var inputMode = false;

	private var keyIcon: Bitmap = null;

	public function new(keyCode: Int) {
		super();

		this.keyCode = keyCode;
		this.selected = false;
		this.inputMode = false;
		this.keyIcon = new Bitmap();
		addChild(this.keyIcon);
		this.setNormalMode();
	}

	public function value() {
		return this.keyCode;
	}

	public function setKeyCode(keyCode: Int) {
		if (keyCode == this.keyCode)
			return;

		this.keyCode = keyCode;
		this.setText(KeyCodeUtil.charCodeIconIndices[this.keyCode]);
		dispatchEvent(new Event(Event.CHANGE, true));
	}

	private function setText(keyCodeIndex: Int) {
		this.keyIcon.bitmapData = TextureRedrawer.resize(AssetLibrary.getImageFromSet("keyIndicators", keyCodeIndex), 10, false);
		this.keyIcon.x = 25 - this.keyIcon.width / 2;
		this.keyIcon.y = 25 - this.keyIcon.height / 2 - 6;
	}

	private function setNormalMode() {
		this.inputMode = false;

		this.keyIcon.transform.colorTransform = new ColorTransform(1, 1, 1);
		if (stage != null) {
			removeEventListener(KeyboardEvent.KEY_DOWN, this.onInputKeyDown);
			stage.removeEventListener(MouseEvent.CLICK, this.onMouse1, true);
			stage.removeEventListener(MouseEvent.RIGHT_CLICK, this.onMouse2, true);
			stage.removeEventListener(MouseEvent.MIDDLE_CLICK, this.onMouse3, true);
		}

		this.setText(KeyCodeUtil.charCodeIconIndices[this.keyCode]);
		addEventListener(MouseEvent.CLICK, this.onNormalClick);
	}

	private function setInputMode() {
		if (stage == null)
			return;

		this.keyIcon.transform.colorTransform = new ColorTransform(1, 0.8627, 0.5216);
		stage.stageFocusRect = false;
		stage.focus = this;
		this.inputMode = true;
		removeEventListener(MouseEvent.CLICK, this.onNormalClick);
		addEventListener(KeyboardEvent.KEY_DOWN, this.onInputKeyDown);
		stage.addEventListener(MouseEvent.CLICK, this.onMouse1, true);
		stage.addEventListener(MouseEvent.RIGHT_CLICK, this.onMouse2, true);
		stage.addEventListener(MouseEvent.MIDDLE_CLICK, this.onMouse3, true);
	}

	private function onNormalClick(event: MouseEvent) {
		this.setInputMode();
	}

	private function onInputKeyDown(event: KeyboardEvent) {
		event.stopImmediatePropagation();
		this.keyCode = event.keyCode;
		this.setNormalMode();
		dispatchEvent(new Event(Event.CHANGE, true));
	}

	private function onMouse1(event: MouseEvent) {
		event.stopImmediatePropagation();
		this.keyCode = KeyCode.Mouse1;
		this.setNormalMode();
		dispatchEvent(new Event(Event.CHANGE, true));
	}

	private function onMouse2(event: MouseEvent) {
		event.stopImmediatePropagation();
		this.keyCode = KeyCode.Mouse2;
		this.setNormalMode();
		dispatchEvent(new Event(Event.CHANGE, true));
	}

	private function onMouse3(event: MouseEvent) {
		event.stopImmediatePropagation();
		this.keyCode = KeyCode.Mouse3;
		this.setNormalMode();
		dispatchEvent(new Event(Event.CHANGE, true));
	}
}
