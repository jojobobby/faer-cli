package screens.charrects;

import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.MouseEvent;

class CharacterRect extends Sprite {
	public static inline var WIDTH = 384;
	public static inline var HEIGHT = 59;

	public var selectContainer: Sprite;

	private var color = 0;
	private var overColor = 0;
	private var box: Shape;

	public function new(color: Int, overColor: Int) {
		super();

		this.color = color;
		this.overColor = overColor;
		this.box = new Shape();
		this.drawBox(false);
		addChild(this.box);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	public function makeContainer() {
		this.selectContainer = new Sprite();
		this.selectContainer.mouseChildren = false;
		this.selectContainer.buttonMode = true;
		this.selectContainer.graphics.beginFill(0xFF00FF, 0);
		this.selectContainer.graphics.drawRect(0, 0, WIDTH, HEIGHT);
		addChild(this.selectContainer);
	}

	private function drawBox(over: Bool) {
		var g: Graphics = this.box.graphics;
		g.clear();
		g.beginFill(over ? this.overColor : this.color);
		g.drawRect(0, 0, WIDTH, HEIGHT);
		g.endFill();
	}

	public function onMouseOver(_: MouseEvent) {
		this.drawBox(true);
	}

	public function onRollOut(_: MouseEvent) {
		this.drawBox(false);
	}
}
