package util;

import util.NativeTypes.Float32;
import util.BinPacker.Rect;
import util.Utils;
import map.Camera;
import haxe.ds.IntMap;
import openfl.display.BitmapData;
import openfl.geom.Point;
import openfl.geom.Rectangle;

class AnimatedChar {
	public static inline var RIGHT = 0;
	public static inline var LEFT = 1;
	public static inline var DOWN = 2;
	public static inline var UP = 3;
	public static inline var STAND = 0;
	public static inline var WALK = 1;
	public static inline var ATTACK = 2;
	public static inline var FRAMES_PER_DIR = 5;

	private static var SEC_TO_DIRS = [
		[LEFT, UP, DOWN],
		[UP, LEFT, DOWN],
		[UP, RIGHT, DOWN],
		[RIGHT, UP, DOWN],
		[RIGHT, DOWN],
		[DOWN, RIGHT],
		[DOWN, LEFT],
		[LEFT, DOWN]
	];
	private static inline var PI_DIV_4 = MathUtil.PI / 4;

	public var origImage: MaskedImage;

	private var width = 0;
	private var height = 0;
	private var imageDict: IntMap<IntMap<Array<MaskedImage>>>;
	private var rectDict: IntMap<IntMap<Array<Rect>>>;

	public function new(image: MaskedImage, width: Int, height: Int, padding: Int = 0) {
		this.imageDict = new IntMap<IntMap<Array<MaskedImage>>>();
		this.rectDict = new IntMap<IntMap<Array<Rect>>>();
		this.origImage = image;
		this.width = width;
		this.height = height;

		var frames = new MaskedImageSet();
		frames.addFromMaskedImage(image, width, height);

		this.imageDict.set(RIGHT, this.loadImageDir(0, frames));
		this.imageDict.set(LEFT, this.loadImageDir(FRAMES_PER_DIR, frames));
		if (frames.images.length >= FRAMES_PER_DIR * 3) {
			this.imageDict.set(DOWN, this.loadImageDir(FRAMES_PER_DIR * 2, frames));
			if (frames.images.length >= FRAMES_PER_DIR * 4)
				this.imageDict.set(UP, this.loadImageDir(FRAMES_PER_DIR * 3, frames));
		}

		this.rectDict.set(RIGHT, this.loadRectDir(0, frames));
		this.rectDict.set(LEFT, this.loadRectDir(FRAMES_PER_DIR, frames));
		if (frames.images.length >= FRAMES_PER_DIR * 3) {
			this.rectDict.set(DOWN, this.loadRectDir(FRAMES_PER_DIR * 2, frames));
			if (frames.images.length >= FRAMES_PER_DIR * 4)
				this.rectDict.set(UP, this.loadRectDir(FRAMES_PER_DIR * 3, frames));
		}
	}

	public function imageFromDir(dir: Int, action: Int, p: Float) {
		var texVec = this.imageDict.get(dir).get(action);
		p = Math.max(0, Math.min(0.99999, p));
		var i = Std.int(p * texVec.length);
		return texVec[i];
	}

	public function rectFromDir(dir: Int, action: Int, p: Float) {
		var texVec = this.rectDict.get(dir).get(action);
		p = Math.max(0, Math.min(0.99999, p));
		var i = Std.int(p * texVec.length);
		return texVec[i];
	}

	public function imageFromAngle(angle: Float, action: Int, p: Float) {
		var sec = Std.int(angle / PI_DIV_4 + 4) % 8;
		var dirs = SEC_TO_DIRS[sec];
		var actionDict = this.imageDict.get(dirs[0]);
		if (actionDict == null) {
			actionDict = this.imageDict.get(dirs[1]);
			if (actionDict == null)
				actionDict = this.imageDict.get(dirs[2]);
		}

		var texVec = actionDict.get(action);
		p = Math.max(0, Math.min(0.99999, p));
		var i = Std.int(p * texVec.length);
		return texVec[i];
	}

	public function rectFromAngle(angle: Float, action: Int, p: Float) {
		var sec = Std.int(angle / PI_DIV_4 + 4) % 8;
		var dirs = SEC_TO_DIRS[sec];
		var actionDict = this.rectDict.get(dirs[0]);
		if (actionDict == null) {
			actionDict = this.rectDict.get(dirs[1]);
			if (actionDict == null)
				actionDict = this.rectDict.get(dirs[2]);
		}

		var texVec = actionDict.get(action);
		p = Math.max(0, Math.min(0.99999, p));
		var i = Std.int(p * texVec.length);
		return texVec[i];
	}

	public function imageFromFacing(facing: Float32, action: Int, p: Float32) {
		var ca = MathUtil.halfBound(facing - Camera.angleRad);
		var sec = Std.int(Math.abs(Std.int(ca / PI_DIV_4 + 4) % 8));
		var dirs = SEC_TO_DIRS[sec];
		var actionDict = this.imageDict.get(dirs[0]);
		if (actionDict == null) {
			actionDict = this.imageDict.get(dirs[1]);
			if (actionDict == null)
				actionDict = this.imageDict.get(dirs[2]);
		}

		var texVec = actionDict.get(action);
		p = Math.max(0, Math.min(0.99999, p));
		return texVec[Std.int(p * texVec.length)];
	}

	public function facingToDir(facing: Float32) {
		var ca = MathUtil.halfBound(facing - Camera.angleRad);
		var sec = Std.int(Math.abs(Std.int(ca / PI_DIV_4 + 4) % 8));
		var dirs = SEC_TO_DIRS[sec];
		if (!this.rectDict.exists(dirs[0])) {
			if (!this.rectDict.exists(dirs[1]))
				return dirs[2];
			else return dirs[1];
		} else return dirs[0];
	}

	public function rectFromFacing(facing: Float32, action: Int, p: Float32) {
		var ca = MathUtil.halfBound(facing - Camera.angleRad);
		var sec = Std.int(Math.abs(Std.int(ca / PI_DIV_4 + 4) % 8));
		var dirs = SEC_TO_DIRS[sec];
		var actionDict = this.rectDict.get(dirs[0]);
		if (actionDict == null) {
			actionDict = this.rectDict.get(dirs[1]);
			if (actionDict == null)
				actionDict = this.rectDict.get(dirs[2]);
		}

		var texVec = actionDict.get(action);
		p = Math.max(0, Math.min(0.99999, p));
		return texVec[Std.int(p * texVec.length)];
	}

	private function loadImageDir(offset: Int, frames: MaskedImageSet) {
		var imageDict = new IntMap<Array<MaskedImage>>();
		imageDict.set(STAND, [frames.images[offset + 0]]);
		imageDict.set(WALK, [frames.images[offset + 1], frames.images[offset + 2]]);
		imageDict.set(ATTACK, [frames.images[offset + 3], frames.images[offset + 4]]);
		return imageDict;
	}

	private function loadRectDir(offset: Int, frames: MaskedImageSet) {
		var rectDict = new IntMap<Array<Rect>>();
		rectDict.set(STAND, [frames.imageRects[offset + 0]]);
		rectDict.set(WALK, [frames.imageRects[offset + 1], frames.imageRects[offset + 2]]);
		rectDict.set(ATTACK, [frames.imageRects[offset + 3], frames.imageRects[offset + 4]]);
		return rectDict;
	}
}
