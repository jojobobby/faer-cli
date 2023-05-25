package screens;

import lime.system.System;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.geom.ColorTransform;
import sound.SoundEffectLibrary;
import ui.SimpleText;
import util.Utils;
import util.Signal;

class TitleMenuOption extends Sprite {
	public static var OVER_COLOR_TRANSFORM: ColorTransform = new ColorTransform(1, 220 / 255, 133 / 255);

	public var clicked = new EmptySignal();

	private var colorTransform: ColorTransform;
	private var size = 0;
	private var textField: SimpleText;
	private var isPulse = false;

	public var active = false;

	private var originalWidth = 0.0;
	private var originalHeight = 0.0;

	public function new(text: String, size: Int, pulse: Bool) {
		super();

		this.buttonMode = true;
		this.size = size;
		this.setText(text);
		this.isPulse = pulse;
		this.originalWidth = width;
		this.originalHeight = height;
		activate();
	}

	public function setText(text: String) {
		name = text;
		if (this.textField != null)
			removeChild(this.textField);

		this.textField = new SimpleText(this.size, 0xFFFFFF, false, 0, 0);
		this.textField.setBold(true);
		this.textField.text = text.toLowerCase();
		this.textField.updateMetrics();
		this.textField.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		addChild(this.textField);

		// needed for mouse events to register...
		graphics.clear();
		graphics.beginFill(0xFFFFFF, 0);
		graphics.drawRect(this.textField.x - 4, this.textField.y - 4, this.textField.width + 8, this.textField.height + 8);
	}

	public function activate() {
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
		this.active = true;
	}

	public function deactivate() {
		var ct = new ColorTransform();
		ct.color = 0x363636;
		this.setColorTransform(ct);
		removeEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		removeEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
		this.active = false;
	}

	public function setColorTransform(ct: ColorTransform) {
		if (ct == this.colorTransform) {
			return;
		}
		this.colorTransform = ct;
		if (this.colorTransform == null) {
			this.textField.transform.colorTransform = ColorUtils.identity;
		} else {
			this.textField.transform.colorTransform = this.colorTransform;
		}
	}

	public function onMouseOver(event: MouseEvent) {
		this.setColorTransform(OVER_COLOR_TRANSFORM);
	}

	public function onMouseOut(event: MouseEvent) {
		this.setColorTransform(null);
	}

	public function onMouseClick(event: MouseEvent) {
		SoundEffectLibrary.play("button_click");
		this.clicked.emit();
	}

	private function onAddedToStage(event: Event) {
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		addEventListener(MouseEvent.CLICK, this.onMouseClick);
		if (this.isPulse) {
			addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		}
	}

	private function onRemovedFromStage(event: Event) {
		removeEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		removeEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		removeEventListener(MouseEvent.CLICK, this.onMouseClick);
		if (this.isPulse) {
			removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		}
	}

	private function onEnterFrame(event: Event) {
		var s = 1.05 + 0.05 * MathUtil.sin(System.getTimer() / 200);
		this.textField.scaleX = s;
		this.textField.scaleY = s;
		this.textField.x = this.originalWidth / 2 - this.textField.width / 2;
		this.textField.y = this.originalHeight / 2 - this.textField.height / 2;
	}
}
