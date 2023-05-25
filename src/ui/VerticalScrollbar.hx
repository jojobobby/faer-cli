package ui;

import openfl.display.Sprite;
import util.Signal;

class VerticalScrollbar extends Sprite {
	public static inline var WIDTH: Int = 20;
	public static inline var BEVEL: Int = 4;
	public static inline var PADDING = 0;

	public var groove: VerticalScrollbarGroove = new VerticalScrollbarGroove();
	public var bar: VerticalScrollbarBar = new VerticalScrollbarBar();

	private var position = 0.0;
	private var range = 0;
	private var invRange = 0.0;
	private var isEnabled = true;

	public var positionChanged = new Signal<Float>();

	public function new() {
		super();

		addChild(this.groove);
		addChild(this.bar);
		this.addMouseListeners();
	}

	public function getIsEnabled() {
		return this.isEnabled;
	}

	public function setIsEnabled(isEnabled: Bool) {
		if (this.isEnabled != isEnabled) {
			this.isEnabled = isEnabled;
			if (isEnabled) {
				this.addMouseListeners();
			} else {
				this.removeMouseListeners();
			}
		}
	}

	public function setSize(barSize: Int, grooveSize: Int) {
		this.bar.rect.height = barSize;
		this.groove.rect.height = grooveSize;
		this.range = grooveSize - barSize - PADDING * 2;
		this.invRange = 1 / this.range;
		this.groove.redraw();
		this.bar.redraw();
		this.setPosition(this.getPosition());
	}

	public function getBarSize() {
		return this.bar.rect.height;
	}

	public function getGrooveSize() {
		return this.groove.rect.height;
	}

	public function getPosition() {
		return this.position;
	}

	public function setPosition(value: Float) {
		if (value < 0) {
			value = 0;
		} else if (value > 1) {
			value = 1;
		}
		this.position = value;
		this.bar.y = PADDING + this.range * this.position;
		if (this.positionChanged != null)
			this.positionChanged.emit(this.position);
	}

	public function scrollPosition(value: Float) {
		var position: Float = (this.position + value);
		this.setPosition(position);
	}

	private function addMouseListeners() {
		this.groove.addMouseListeners();
		this.groove.clicked.on(this.onGrooveClicked);
		this.bar.addMouseListeners();
		this.bar.dragging.on(this.onBarDrag);
	}

	private function removeMouseListeners() {
		this.groove.removeMouseListeners();
		this.groove.clicked.off(this.onGrooveClicked);
		this.bar.removeMouseListeners();
		this.bar.dragging.off(this.onBarDrag);
	}

	private function onBarDrag(value: Int) {
		this.setPosition((value - PADDING) * this.invRange);
	}

	private function onGrooveClicked(value: Int) {
		var barHeight: Int = Std.int(this.bar.rect.height);
		var numerator: Int = Std.int(value - barHeight * 0.5);
		var denominator: Int = this.groove.rect.height - barHeight;
		this.setPosition(numerator / denominator);
	}
}
