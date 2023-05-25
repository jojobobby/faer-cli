package ui.tooltip;

import openfl.display.DisplayObject;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;

class ToolTip extends Sprite {
	public var contentWidth = 0;
	public var contentHeight = 0;

	private var background = 0;
	private var backgroundAlpha = 0.0;
	private var outline = 0;
	private var outlineAlpha = 0.0;
	private var followMouse = false;
	private var targetObj: DisplayObject;

	public function new(background: Int, backgroundAlpha: Float, outline: Int, outlineAlpha: Float, followMouse: Bool = true) {
		super();

		this.background = background;
		this.backgroundAlpha = backgroundAlpha;
		this.outline = outline;
		this.outlineAlpha = outlineAlpha;
		this.followMouse = followMouse;
		mouseEnabled = false;
		mouseChildren = false;
		filters = [new DropShadowFilter(0, 0, 0, 1, 16, 16)];
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function attachToTarget(dObj: DisplayObject) {
		if (dObj != null) {
			this.targetObj = dObj;
			this.targetObj.addEventListener(MouseEvent.ROLL_OUT, this.onLeaveTarget);
		}
	}

	public function detachFromTarget() {
		if (this.targetObj != null) {
			this.targetObj.removeEventListener(MouseEvent.ROLL_OUT, this.onLeaveTarget);
			parent?.removeChild(this);
			this.targetObj = null;
		}
	}

	public function draw() {
		this.contentWidth = Std.int(width);
		this.contentHeight = Std.int(height);

		graphics.clear();
		graphics.lineStyle(2, this.outline, this.outlineAlpha);
		graphics.beginFill(this.background, this.backgroundAlpha);
		graphics.drawRect(-4, -4, this.contentWidth + 12, this.contentHeight + 12);
	}

	private function position() {
		if (Main.primaryStage == null)
			return;

		if (Main.primaryStage.mouseX < Main.stageWidth / 2)
			x = Main.primaryStage.mouseX + 12;
		else
			x = Main.primaryStage.mouseX - width - 1;

		if (x < 12)
			x = 12;

		if (Main.primaryStage.mouseY < Main.stageHeight / 3)
			y = Main.primaryStage.mouseY + 12;
		else
			y = Main.primaryStage.mouseY - height - 1;

		if (y < 12)
			y = 12;
	}

	private function onLeaveTarget(e: MouseEvent) {
		this.detachFromTarget();
	}

	private function onAddedToStage(event: Event) {
		this.draw();
		if (this.followMouse) {
			this.position();
			addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		}
	}

	private function onRemovedFromStage(event: Event) {
		if (this.followMouse)
			removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onEnterFrame(event: Event) {
		this.position();
	}
}
