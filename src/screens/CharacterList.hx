package screens;

import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import screens.charrects.CharacterRectList;

class CharacterList extends Sprite {
	public static inline var WIDTH: Int = 760;

	public var charRectList: CharacterRectList;

	public function new() {
		super();

		var shape: Shape = null;
		var g: Graphics = null;
		this.charRectList = new CharacterRectList();
		addChild(this.charRectList);
		if (height > Main.stageHeight - 120) {
			shape = new Shape();
			g = shape.graphics;
			g.beginFill(0);
			g.drawRect(0, 0, WIDTH, Main.stageHeight - 120);
			g.endFill();
			addChild(shape);
			mask = shape;
		}
	}

	public function setPos(pos: Float) {
		this.charRectList.y = pos;
	}
}
