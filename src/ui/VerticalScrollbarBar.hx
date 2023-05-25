package ui;

import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import util.BevelRect;
import util.GraphicsHelper;
import util.Signal;

final class VerticalScrollbarBar extends Sprite {
	public static inline var WIDTH: Int = VerticalScrollbar.WIDTH;
	public static inline var BEVEL: Int = VerticalScrollbar.BEVEL;
	public static inline var PADDING: Int = VerticalScrollbar.PADDING;

	public var dragging = new Signal<Int>();
	public var rect: BevelRect = new BevelRect(WIDTH - PADDING * 2, 0, BEVEL);

	private var downOffset = 0.0;
	private var isOver = false;
	private var isDown = false;

	public function redraw() {
		var color: Int = this.isOver || this.isDown ? 16767876 : 13421772;
		graphics.clear();
		graphics.beginFill(color);
		GraphicsHelper.drawBevelRect(PADDING, 0, this.rect, graphics);
		graphics.endFill();
	}

	public function addMouseListeners() {
		addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
	}

	public function removeMouseListeners() {
		removeEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		removeEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		removeEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		this.onMouseUp();
	}

	private function onMouseDown(event: MouseEvent = null) {
		this.isDown = true;
		this.downOffset = parent.mouseY - y;
		stage.addEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
		addEventListener(Event.ENTER_FRAME, this.iterate);
		this.redraw();
	}

	private function onMouseUp(event: MouseEvent = null) {
		this.isDown = false;
		stage.removeEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
		removeEventListener(Event.ENTER_FRAME, this.iterate);
		this.redraw();
	}

	private function onMouseOver(event: MouseEvent) {
		this.isOver = true;
		this.redraw();
	}

	private function onMouseOut(event: MouseEvent) {
		this.isOver = false;
		this.redraw();
	}

	private function iterate(event: Event) {
		this.dragging.emit(Std.int(parent.mouseY - this.downOffset));
	}
}
