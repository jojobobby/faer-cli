package objects.animation;

import util.BinPacker.Rect;
import openfl.display.BitmapData;

class Animations {
	public var animationsData: AnimationsData;
	public var nextRun: Array<Int> = null;
	public var running: RunningAnimation = null;

	public function new(animationsData: AnimationsData) {
		this.animationsData = animationsData;
	}

	public function getTexture(time: Int) {
		var animationData: AnimationData = null;
		var start = 0;
		if (this.nextRun == null) {
			this.nextRun = [];
			for (animationData in this.animationsData.animations)
				this.nextRun.push(animationData.getLastRun(time));
		}

		if (this.running != null) {
			var rect = this.running.getRect(time);
			if (rect != null)
				return rect;
			this.running = null;
		}

		for (i in 0...this.nextRun.length)
			if (time > this.nextRun[i]) {
				start = this.nextRun[i];
				animationData = this.animationsData.animations[i];
				this.nextRun[i] = animationData.getNextRun(time);
				if (!(animationData.prob != 1 && Math.random() > animationData.prob)) {
					this.running = new RunningAnimation(animationData, start);
					return this.running.getRect(time);
				}
			}

		return null;
	}
}

class RunningAnimation {
	public var animationData: AnimationData;
	public var start = 0;
	public var frameId = 0;
	public var frameStart = 0;
	public var rect: Rect;

	public function new(animationData: AnimationData, start: Int) {
		this.animationData = animationData;
		this.start = start;
		this.frameId = 0;
		this.frameStart = start;
		this.rect = null;
	}

	public function getRect(time: Int) {
		var frame: FrameData = this.animationData.frames[this.frameId];
		while (time - this.frameStart > frame.time) {
			if (this.frameId >= this.animationData.frames.length - 1)
				return null;

			this.frameStart = this.frameStart + frame.time;
			this.frameId++;
			frame = this.animationData.frames[this.frameId];
			this.rect = null;
		}

		if (this.rect == null)
			this.rect = frame.textureData.getRect(Std.int(Math.random() * 100));

		return this.rect;
	}
}
