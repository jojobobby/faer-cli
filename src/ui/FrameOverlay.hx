package ui;

import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;

class FrameOverlay extends Sprite {
	private var darkBox: Shape;
	private var frame: Frame;

	public function new(frame: Frame) {
		super();

		this.darkBox = new Shape();
		var g: Graphics = this.darkBox.graphics;
		g.clear();
		g.beginFill(0, 0.8);
		g.drawRect(0, 0, Main.stageWidth, Main.stageHeight);
		g.endFill();
		addChild(this.darkBox);
		this.frame = frame;
		this.frame.addEventListener(Event.COMPLETE, this.onFrameDone);
		addChild(this.frame);
	}

	private function onFrameDone(event: Event) {
		parent.removeChild(this);
	}
}
