package ui;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.geom.ColorTransform;
import util.AssetLibrary;
import util.Signal;

class MiniMapZoomButtons extends Sprite {
	private static var FADE: ColorTransform = new ColorTransform(0.5, 0.5, 0.5);
	private static var NORM: ColorTransform = new ColorTransform(1, 1, 1);

	public var zoom = new Signal<Int>();

	private var zoomOut: Sprite;
	private var zoomIn: Sprite;
	private var zoomLevels = 0;
	private var zoomLevel = 0;

	public function new() {
		super();

		this.zoomLevel = 0;
		this.makeZoomOut();
		this.makeZoomIn();
		this.updateButtons();
	}

	public function getZoomLevel() {
		return this.zoomLevel;
	}

	public function setZoomLevel(value: Int) {
		if (this.zoomLevels == 0) {
			return this.zoomLevel;
		}
		if (value < 0) {
			value = 0;
		} else if (value >= this.zoomLevels - 1) {
			value = this.zoomLevels - 1;
		}
		this.zoomLevel = value;
		this.updateButtons();
		return this.zoomLevel;
	}

	public function setZoomLevels(count: Int) {
		this.zoomLevels = count;
		if (this.zoomLevel >= this.zoomLevels) {
			this.zoomLevel = this.zoomLevels - 1;
		}
		this.updateButtons();
		return this.zoomLevels;
	}

	private function makeZoomOut() {
		var data: BitmapData = AssetLibrary.getImageFromSet("misc16", 0x42);
		var bitmap: Bitmap = new Bitmap(data);
		this.zoomOut = new Sprite();
		this.zoomOut.x = 0;
		this.zoomOut.y = 20;
		this.zoomOut.addChild(bitmap);
		this.zoomOut.addEventListener(MouseEvent.CLICK, this.onZoomOut);
		addChild(this.zoomOut);
	}

	private function makeZoomIn() {
		var data: BitmapData = AssetLibrary.getImageFromSet("misc16", 0x41);
		var bitmap: Bitmap = new Bitmap(data);
		this.zoomIn = new Sprite();
		this.zoomIn.x = 0;
		this.zoomIn.y = 4;
		this.zoomIn.addChild(bitmap);
		this.zoomIn.addEventListener(MouseEvent.CLICK, this.onZoomIn);
		addChild(this.zoomIn);
	}

	private function canZoomOut() {
		return this.zoomLevel > 0;
	}

	private function canZoomIn() {
		return this.zoomLevel < (this.zoomLevels - 1);
	}

	private function updateButtons() {
		this.zoomIn.transform.colorTransform = this.canZoomIn() ? NORM : FADE;
		this.zoomOut.transform.colorTransform = this.canZoomOut() ? NORM : FADE;
	}

	private function onZoomOut(event: MouseEvent) {
		if (this.canZoomOut()) {
			this.zoom.emit(--this.zoomLevel);
			this.zoomOut.transform.colorTransform = this.canZoomOut() ? NORM : FADE;
		}
	}

	private function onZoomIn(event: MouseEvent) {
		if (this.canZoomIn()) {
			this.zoom.emit(++this.zoomLevel);
			this.zoomIn.transform.colorTransform = this.canZoomIn() ? NORM : FADE;
		}
	}
}
