package util;

class BevelRect {
	public var topLeftBevel = true;
	public var topRightBevel = true;
	public var bottomLeftBevel = true;
	public var bottomRightBevel = true;
	public var width = 0;
	public var height = 0;
	public var bevel = 0;

	public function new(width: Int, height: Int, bevel: Int) {
		this.width = width;
		this.height = height;
		this.bevel = bevel;
	}
}
