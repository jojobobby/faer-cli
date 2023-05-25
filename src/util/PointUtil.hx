package util;
class PointUtil {
	public static inline function distanceSquaredXY(x1: Float, y1: Float, x2: Float, y2: Float) {
		var dX: Float = x2 - x1;
		var dY: Float = y2 - y1;
		return (dX * dX) + (dY * dY);
	}

	public static inline function distanceXY(x1: Float, y1: Float, x2: Float, y2: Float) {
		var dX: Float = x2 - x1;
		var dY: Float = y2 - y1;
		return Math.sqrt((dX * dX) + (dY * dY));
	}
}