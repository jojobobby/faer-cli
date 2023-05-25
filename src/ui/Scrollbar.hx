package ui;

import lime.system.System;
import openfl.display.Graphics;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.IGraphicsData;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.geom.ColorTransform;
import openfl.geom.Rectangle;
import openfl.Vector;
import util.GraphicsUtil;

class Scrollbar extends Sprite {
	private var w = 0;
	private var h = 0;
	private var speed = 0.0;
	private var indicatorRect: Rectangle;
	private var jumpDist = 0.0;
	private var background: Sprite;
	private var upArrow: Sprite;
	private var downArrow: Sprite;
	private var posIndicator: Sprite;
	private var lastUpdateTime = 0;
	private var change = 0.0;
	private var backgroundFill: GraphicsSolidFill = new GraphicsSolidFill(0xFFFFFF, 1);
	private var path: GraphicsPath = new GraphicsPath();
	private var graphicsData: Vector<IGraphicsData> = new Vector<IGraphicsData>(0, false,
		[new GraphicsSolidFill(0xFFFFFF, 1), new GraphicsPath(), GraphicsUtil.END_FILL]);

	private static function drawArrow(w: Int, h: Int, g: Graphics) {
		g.clear();
		g.beginFill(3487029, 0.01);
		g.drawRect(-w / 2, -h / 2, w, h);
		g.endFill();
		g.beginFill(0xFFFFFF, 1);
		g.moveTo(-w / 2, -h / 2);
		g.lineTo(w / 2, 0);
		g.lineTo(-w / 2, h / 2);
		g.lineTo(-w / 2, -h / 2);
		g.endFill();
	}

	private static function getSprite(downFunction: MouseEvent -> Void) {
		var sprite: Sprite = new Sprite();
		sprite.addEventListener(MouseEvent.MOUSE_DOWN, downFunction);
		sprite.addEventListener(MouseEvent.ROLL_OVER, onRollOver);
		sprite.addEventListener(MouseEvent.ROLL_OUT, onRollOut);
		return sprite;
	}

	public function new(widthParam: Int, heightParam: Int, speed: Float = 1.0) {
		super();

		this.background = new Sprite();
		this.background.addEventListener(MouseEvent.MOUSE_DOWN, this.onBackgroundDown);
		addChild(this.background);
		this.upArrow = getSprite(this.onUpArrowDown);
		addChild(this.upArrow);
		this.downArrow = getSprite(this.onDownArrowDown);
		addChild(this.downArrow);
		this.posIndicator = getSprite(this.onStartIndicatorDrag);
		addChild(this.posIndicator);
		this.resize(widthParam, heightParam, speed);
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function pos() {
		if (this.indicatorRect.height == this.posIndicator.height)
			return 0.0;

		return (this.posIndicator.y - this.indicatorRect.y) / (this.indicatorRect.height - this.posIndicator.height);
	}

	public function setIndicatorSize(windowHeight: Float, totalHeight: Float, doSetPos: Bool = true) {
		var h: Int = totalHeight == 0 ? Std.int(this.indicatorRect.height) : Std.int(windowHeight / totalHeight * this.indicatorRect.height);
		h = Std.int(Math.min(this.indicatorRect.height, Math.max(this.w, h)));
		this.drawIndicator(this.w, h, this.posIndicator.graphics);
		this.jumpDist = windowHeight / (totalHeight - windowHeight);
		if (doSetPos) {
			this.setPos(0);
		}
	}

	public function setPos(v: Float) {
		v = Math.max(0, Math.min(1, v));
		this.posIndicator.y = v * (this.indicatorRect.height - this.posIndicator.height) + this.indicatorRect.y;
		this.sendPos();
	}

	public function jumpUp(mult: Float) {
		this.setPos(this.pos() - (this.jumpDist * mult));
	}

	public function jumpDown(mult: Float) {
		this.setPos(this.pos() + (this.jumpDist * mult));
	}

	public function resize(widthParam: Int, heightParam: Int, speed: Float = 1.0) {
		this.w = widthParam;
		this.h = heightParam;
		this.speed = speed;
		var arrowHeight: Int = Std.int(this.w * 0.75);
		this.indicatorRect = new Rectangle(0, arrowHeight + 5, this.w, this.h - arrowHeight * 2 - 10);
		var g: Graphics = this.background.graphics;
		g.clear();
		g.beginFill(0x545454, 1);
		g.drawRect(this.indicatorRect.x, this.indicatorRect.y, this.indicatorRect.width, this.indicatorRect.height);
		g.endFill();
		drawArrow(arrowHeight, this.w, this.upArrow.graphics);
		this.upArrow.rotation = -90;
		this.upArrow.x = this.w / 2;
		this.upArrow.y = arrowHeight / 2;
		drawArrow(arrowHeight, this.w, this.downArrow.graphics);
		this.downArrow.x = this.w / 2;
		this.downArrow.y = this.h - arrowHeight / 2;
		this.downArrow.rotation = 90;
		this.drawIndicator(this.w, this.h, this.posIndicator.graphics);
		this.posIndicator.x = 0;
		this.posIndicator.y = this.indicatorRect.y;
	}

	private function sendPos() {
		dispatchEvent(new Event(Event.CHANGE));
	}

	private function drawIndicator(w: Int, h: Int, g: Graphics) {
		GraphicsUtil.clearPath(this.path);
		GraphicsUtil.drawCutEdgeRect(0, 0, w, h, 4, [1, 1, 1, 1], this.path);
		this.graphicsData[1] = this.path;
		g.clear();
		g.drawGraphicsData(this.graphicsData);
	}

	public function onAddedToStage(event: Event) {
		parent.addEventListener(MouseEvent.MOUSE_WHEEL, this.onMouseWheel);
	}

	public function onRemovedFromStage(event: Event) {
		parent.removeEventListener(MouseEvent.MOUSE_WHEEL, this.onMouseWheel);
		removeEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		removeEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function onMouseWheel(event: MouseEvent) {
		if (event.delta > 0) {
			this.jumpUp(0.2);
		} else {
			if (event.delta < 0) {
				this.jumpDown(0.2);
			}
		}
	}

	private static function onRollOver(event: MouseEvent) {
		var sprite: Sprite = cast(event.target, Sprite);
		sprite.transform.colorTransform = new ColorTransform(1, 0.8627, 0.5216);
	}

	private static function onRollOut(event: MouseEvent) {
		var sprite: Sprite = cast(event.target, Sprite);
		sprite.transform.colorTransform = new ColorTransform(1, 1, 1);
	}

	private function onBackgroundDown(event: MouseEvent) {
		if (event.localY < this.posIndicator.y) {
			this.jumpUp(1);
		} else {
			this.jumpDown(1);
		}
	}

	private function onUpArrowDown(event: MouseEvent) {
		addEventListener(Event.ENTER_FRAME, this.onArrowFrame);
		addEventListener(MouseEvent.MOUSE_UP, this.onArrowUp);
		this.lastUpdateTime = System.getTimer();
		this.change = -this.speed;
	}

	private function onDownArrowDown(event: MouseEvent) {
		addEventListener(Event.ENTER_FRAME, this.onArrowFrame);
		addEventListener(MouseEvent.MOUSE_UP, this.onArrowUp);
		this.lastUpdateTime = System.getTimer();
		this.change = this.speed;
	}

	private function onArrowFrame(event: Event) {
		var time: Int = System.getTimer();
		var dt: Float = (time - this.lastUpdateTime) / 1000;
		var dist: Int = Math.round((this.h - this.w * 3) * dt * this.change);
		this.setPos((this.posIndicator.y + dist - this.indicatorRect.y) / (this.indicatorRect.height - this.posIndicator.height));
		this.lastUpdateTime = time;
	}

	private function onArrowUp(event: Event) {
		removeEventListener(Event.ENTER_FRAME, this.onArrowFrame);
		removeEventListener(MouseEvent.MOUSE_UP, this.onArrowUp);
	}

	private function onStartIndicatorDrag(event: MouseEvent) {
		this.posIndicator.startDrag(false, new Rectangle(0, this.indicatorRect.y, 0, this.indicatorRect.height - this.posIndicator.height));
		stage.addEventListener(MouseEvent.MOUSE_UP, this.onStopIndicatorDrag);
		stage.addEventListener(MouseEvent.MOUSE_MOVE, this.onDragMove);
		this.sendPos();
	}

	private function onStopIndicatorDrag(event: MouseEvent) {
		stage.removeEventListener(MouseEvent.MOUSE_UP, this.onStopIndicatorDrag);
		stage.removeEventListener(MouseEvent.MOUSE_MOVE, this.onDragMove);
		this.posIndicator.stopDrag();
		this.sendPos();
	}

	private function onDragMove(event: MouseEvent) {
		this.sendPos();
	}
}
