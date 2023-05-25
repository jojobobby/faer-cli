package ui;

import openfl.display.Sprite;
import openfl.events.MouseEvent;
import util.BevelRect;
import util.GraphicsHelper;
import util.Signal;

final class VerticalScrollbarGroove extends Sprite {
	public static inline var WIDTH: Int = VerticalScrollbar.WIDTH;
	public static inline var BEVEL: Int = Std.int(VerticalScrollbar.BEVEL + VerticalScrollbar.PADDING * 0.5);

	public var clicked = new Signal<Int>();
	public var rect: BevelRect = new BevelRect(WIDTH, 0, BEVEL);

	public function redraw() {
		graphics.clear();
		graphics.beginFill(0x545454);
		GraphicsHelper.drawBevelRect(0, 0, this.rect, graphics);
		graphics.endFill();
	}

	public function addMouseListeners() {
		addEventListener(MouseEvent.CLICK, this.onClick);
	}

	public function removeMouseListeners() {
		removeEventListener(MouseEvent.CLICK, this.onClick);
	}

	private function onClick(event: MouseEvent) {
		this.clicked.emit(Std.int(mouseY));
	}
}
