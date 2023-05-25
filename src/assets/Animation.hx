package assets;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.events.TimerEvent;
import openfl.utils.Timer;

class Animation extends Sprite {
	private static inline var DEFAULT_SPEED: Int = 200;

	private var bitmap: Bitmap;
	private var frames: Array<BitmapData> = new Array<BitmapData>();
	private var timer: Timer;
	private var isStarted = false;
	private var index = 0;
	private var count = 0;

	public function new() {
		super();

		this.timer = makeTimer();
		this.bitmap = makeBitmap();
	}

	public function getSpeed() {
		return Std.int(this.timer.delay);
	}

	public function setSpeed(speed: Int) {
		this.timer.delay = speed;
	}

	public function setFrames(newFrames: Array<BitmapData>) {
		var frame: BitmapData = null;
		this.frames.splice(0, this.frames.length);
		this.index = 0;
		for (frame in newFrames)
			this.count = this.frames.push(frame);

		if (this.isStarted)
			this.start();
		else
			this.iterate();
	}

	public function addFrame(frame: BitmapData) {
		this.count = this.frames.push(frame);
		if (this.isStarted)
			this.start();
	}

	public function start() {
		if (!this.isStarted && this.count > 0) {
			this.timer.start();
			this.iterate();
		}

		this.isStarted = true;
	}

	public function stop() {
		if (this.isStarted)
			this.timer.stop();
		this.isStarted = false;
	}

	public function dispose() {
		var frame: BitmapData = null;
		this.stop();
		this.index = 0;
		this.count = 0;
		this.frames.splice(0, this.frames.length);
		for (frame in this.frames)
			frame.dispose();
	}

	private function makeBitmap() {
		var bitmap = new Bitmap();
		addChild(bitmap);
		return bitmap;
	}

	private function makeTimer() {
		var timer = new Timer(DEFAULT_SPEED);
		timer.addEventListener(TimerEvent.TIMER, this.iterate);
		return timer;
	}

	private function iterate(event: TimerEvent = null) {
		this.index = ++this.index % this.count;
		this.bitmap.bitmapData = this.frames[this.index];
	}
}
