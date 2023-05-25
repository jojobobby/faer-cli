package servers;

import util.Utils;

final class LatLong {
	private static inline var DISTANCE_SCALAR = 60 * 1.1515 * 1.609344 * 1000;

	public var latitude = 0.0;
	public var longitude = 0.0;

	public static function distance(a: LatLong, b: LatLong) {
		var theta = MathUtil.TO_RAD * (a.longitude - b.longitude);
		var lat1 = MathUtil.TO_RAD * a.latitude;
		var lat2 = MathUtil.TO_RAD * b.latitude;
		var dist = MathUtil.sin(lat1) * MathUtil.sin(lat2) + MathUtil.cos(lat1) * MathUtil.cos(lat2) * MathUtil.cos(theta);
		dist = MathUtil.TO_DEG * Math.acos(dist) * DISTANCE_SCALAR;
		return dist;
	}

	public function new(latitude: Float, longitude: Float) {
		this.latitude = latitude;
		this.longitude = longitude;
	}
}
