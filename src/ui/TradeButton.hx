package ui;

import lime.system.System;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;

class TradeButton extends Sprite {
	private static inline var WAIT_TIME: Int = 2999;
	private static inline var COUNTDOWN_STATE = 0;
	private static inline var NORMAL_STATE: Int = 1;
	private static inline var WAITING_STATE: Int = 2;
	private static inline var DISABLED_STATE: Int = 3;

	public var statusBar: Sprite;
	public var barMask: Shape;
	public var text: SimpleText;
	public var w = 0;
	public var h = 0;

	private var state = 0;
	private var lastResetTime = 0;

	public function new(size: Int, bWidth: Int = 0) {
		super();
		this.lastResetTime = System.getTimer();
		this.text = new SimpleText(size, 0x363636, false, 0, 0);
		this.text.setBold(true);
		this.text.text = "Trade";
		this.text.updateMetrics();
		this.w = bWidth != 0 ? bWidth : Std.int(this.text.width + 12);
		this.h = Std.int(this.text.textHeight + 8);
		graphics.clear();
		graphics.lineStyle(2, 0xFFFFFF);
		graphics.beginFill(12566463, 1);
		graphics.drawRect(0, 0, this.w, this.text.textHeight + 8);
		this.text.x = this.w / 2 - this.text.textWidth / 2 - 2;
		this.text.y = 1;
		this.statusBar = this.newStatusBar();
		addChild(this.statusBar);
		addChild(this.text);
		this.draw();
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
		addEventListener(MouseEvent.CLICK, this.onClick);
	}

	public function reset() {
		this.lastResetTime = System.getTimer();
		this.state = COUNTDOWN_STATE;
		this.setEnabled(false);
		this.setText("Trade");
	}

	public function disable() {
		this.state = DISABLED_STATE;
		this.setEnabled(false);
		this.setText("Trade");
	}

	private function setText(text: String) {
		this.text.text = text;
		this.text.updateMetrics();
		this.text.x = this.w / 2 - this.text.textWidth / 2 - 2;
		this.text.y = 1;
	}

	private function setEnabled(enabled: Bool) {
		if (enabled == mouseEnabled) {
			return;
		}
		mouseEnabled = enabled;
		mouseChildren = enabled;
		// this.graphicsData[0] = enabled ? this.enabledFill : this.disabledFill;
		this.draw();
	}

	private function newStatusBar() {
		var statusBar: Sprite = new Sprite();
		var bar: Sprite = new Sprite();
		var barShape: Shape = new Shape();
		barShape.graphics.clear();
		// barShape.graphics.drawGraphicsData(this.barGraphicsData);
		bar.addChild(barShape);
		this.barMask = new Shape();
		bar.addChild(this.barMask);
		bar.mask = this.barMask;
		statusBar.addChild(bar);
		var outline: Shape = new Shape();
		outline.graphics.clear();
		// outline.graphics.drawGraphicsData(this.outlineGraphicsData);
		statusBar.addChild(outline);
		return statusBar;
	}

	private function drawCountDown(t: Float) {
		this.barMask.graphics.clear();
		this.barMask.graphics.beginFill(12566463);
		this.barMask.graphics.drawRect(0, 0, this.w * t, this.h);
		this.barMask.graphics.endFill();
	}

	private function draw() {
		graphics.clear();
		graphics.lineStyle(2, 0xFFFFFF);
		graphics.beginFill(12566463, 1);
		graphics.drawRect(0, 0, this.w, this.text.textHeight + 8);
	}

	private function onAddedToStage(event: Event) {
		addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		this.reset();
		this.draw();
	}

	private function onRemovedFromStage(event: Event) {
		removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onEnterFrame(event: Event) {
		this.draw();
	}

	private function onMouseOver(event: MouseEvent) {
		// this.enabledFill.color = 0xFFDC85;
		this.draw();
	}

	private function onRollOut(event: MouseEvent) {
		// this.enabledFill.color = 0xFFFFFF;
		this.draw();
	}

	private function onClick(event: MouseEvent) {
		this.state = WAITING_STATE;
		this.setEnabled(false);
		this.setText("Waiting");
	}
}
