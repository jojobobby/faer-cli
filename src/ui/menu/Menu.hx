package ui.menu;

import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.geom.Rectangle;
import util.PointUtil;

class Menu extends Sprite {
	private var background = 0;
	private var outline = 0;
	private var yOffset = 0;

	public function new(background: Int, outline: Int) {
		super();

		this.background = background;
		this.outline = outline;
		this.yOffset = 40;
		filters = [new DropShadowFilter(0, 0, 0, 1, 16, 16)];
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function addOption(option: MenuOption) {
		option.x = 8;
		option.y = this.yOffset;
		addChild(option);
		this.yOffset = this.yOffset + 28;
	}

	public function remove() {
		if (parent != null)
			parent.removeChild(this);
	}

	public function draw() {
		graphics.clear();
		graphics.lineStyle(1, this.outline);
		graphics.beginFill(this.background, 1);
		graphics.drawRect(-6, -6, Std.int(Math.max(154, width + 12)), Std.int(height + 12));
	}

	private function position() {
		if (stage == null)
			return;

		if (stage.mouseX < stage.stageWidth / 2)
			x = stage.mouseX + 12;
		else
			x = stage.mouseX - width - 1;

		if (x < 12)
			x = 12;

		if (stage.mouseY < stage.stageHeight / 3)
			y = stage.mouseY + 12;
		else
			y = stage.mouseY - height - 1;

		if (y < 12)
			y = 12;
	}

	public function onAddedToStage(_: Event) {
		this.draw();
		this.position();
		addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	public function onRemovedFromStage(_: Event) {
		removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		removeEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	public function onEnterFrame(_: Event) {
		if (stage == null)
			return;

		var rect = getRect(stage);
		var cX = x;
		var cY = y;
		if (cX < rect.x)
			cX = rect.x;
		else if (cX > rect.right)
			cX = rect.right;

		if (cY < rect.y)
			cY = rect.y;
		else if (cY > rect.bottom)
			cY = rect.bottom;

		if (cX == x && cY == y)
			return;

		if (PointUtil.distanceSquaredXY(cX, cY, x, y) > 40 * 40)
			this.remove();
	}

	public function onRollOut(_: Event) {
		this.remove();
	}
}
