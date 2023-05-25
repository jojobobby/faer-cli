package map;

import objects.animation.Animations;
import util.NativeTypes;
import objects.GameObject;

class Square {
	public var tileType: Int = 0xFF;
	public var obj: GameObject = null;
	public var props: GroundProperties = GroundLibrary.defaultProps;
	public var animations: Animations;
	public var baseU: Float32 = 1;
	public var baseV: Float32 = 1;
	public var sink: Float32 = 0.0;
	public var lastDamage = 0;
	public var lastVisible: Int32 = 0;
	public var clipX: Float32 = 0.0;
	public var clipY: Float32 = 0.0;

	public var leftBlendU: Float32 = -1.0;
	public var leftBlendV: Float32 = -1.0;
	public var topBlendU: Float32 = -1.0;
	public var topBlendV: Float32 = -1.0;
	public var rightBlendU: Float32 = -1.0;
	public var rightBlendV: Float32 = -1.0;
	public var bottomBlendU: Float32 = -1.0;
	public var bottomBlendV: Float32 = -1.0;

	public var middleX: Float32 = 0.0;
	public var middleY: Float32 = 0.0;
	public var x: UInt16 = 0;
	public var y: UInt16 = 0;

	public function new (x: Float32, y: Float32) {
		this.x = Std.int(x);
		this.y = Std.int(y);
		this.middleX = x;
		this.middleY = y;
	};
}