package mapeditor;

import util.GraphicsUtil;
import ui.Scrollbar;
import openfl.display.CapsStyle;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.GraphicsStroke;
import openfl.display.IGraphicsData;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.Vector;

class Chooser extends Sprite {
	public static inline var WIDTH = 136;
	public static inline var HEIGHT = 480;
	private static inline var SCROLLBAR_WIDTH = 20;

	public var layer: Int;

	private var elementSprite: Sprite;

	public var selected: Element;

	private var scrollBar: Scrollbar;
	private var elements: Vector<Element>;
	private var path: GraphicsPath = new GraphicsPath();
	private var graphicsData = new Vector<IGraphicsData>(0, false, [
		new GraphicsStroke(1, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, new GraphicsSolidFill(0xFFFFFF, 1)),
		new GraphicsSolidFill(0x363636, 1),
		new GraphicsPath(),
		GraphicsUtil.END_FILL,
		GraphicsUtil.END_STROKE
	]);

	function new(layer: Int) {
		this.elements = new Vector<Element>();
		super();
		this.layer = layer;
		this.drawBackground();
		this.elementSprite = new Sprite();
		this.elementSprite.x = 4;
		this.elementSprite.y = 6;
		addChild(this.elementSprite);
		this.scrollBar = new Scrollbar(SCROLLBAR_WIDTH, HEIGHT - 8);
		this.scrollBar.x = WIDTH - SCROLLBAR_WIDTH - 6;
		this.scrollBar.y = 4;
		this.scrollBar.addEventListener(Event.CHANGE, this.onScrollBarChange);
		var maskShape: Shape = new Shape();
		maskShape.graphics.beginFill(0);
		maskShape.graphics.drawRect(0, 2, Chooser.WIDTH - SCROLLBAR_WIDTH - 4, Chooser.HEIGHT - 4);
		addChild(maskShape);
		this.elementSprite.mask = maskShape;
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function selectedType() {
		return this.selected.type;
	}

	public function setSelectedType(type: Int) {
		for (element in this.elements)
			if (element.type == type) {
				this.setSelected(element);
				return;
			}
	}

	private function removeElements() {
		this.elements = new Vector<Element>();
		removeChild(this.elementSprite);
		this.elementSprite = new Sprite();
		this.elementSprite.x = 4;
		this.elementSprite.y = 6;
		var maskShape: Shape = new Shape();
		maskShape.graphics.beginFill(0);
		maskShape.graphics.drawRect(0, 2, Chooser.WIDTH - SCROLLBAR_WIDTH - 4, Chooser.HEIGHT - 4);
		addChild(maskShape);
		this.elementSprite.mask = maskShape;
		addChild(this.elementSprite);
	}

	private function addElement(element: Element) {
		var i = this.elements.length;
		element.x = i % 2 == 0 ? 0 : 2 + Element.WIDTH;
		element.y = Std.int(i / 2) * Element.HEIGHT + 6;
		this.elementSprite.addChild(element);
		if (i == 0)
			this.setSelected(element);

		element.addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		this.elements.push(element);
	}

	private function onMouseDown(event: MouseEvent) {
		this.setSelected(cast(event.currentTarget, Element));
	}

	private function setSelected(element: Element) {
		this.selected?.setSelected(false);
		this.selected = element;
		this.selected.setSelected(true);
	}

	private function onScrollBarChange(_: Event) {
		this.elementSprite.y = 6 - this.scrollBar.pos() * (this.elementSprite.height + 12 - HEIGHT);
	}

	private function onAddedToStage(_: Event) {
		this.scrollBar.setIndicatorSize(HEIGHT, this.elementSprite.height);
		addChild(this.scrollBar);
	}

	private function onRemovedFromStage(_: Event) {}

	private function drawBackground() {
		GraphicsUtil.clearPath(this.path);
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, HEIGHT, 4, [1, 1, 1, 1], this.path);
		this.graphicsData[2] = this.path;
		graphics.drawGraphicsData(this.graphicsData);
	}
}
