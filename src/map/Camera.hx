package map;

import util.NativeTypes;
import lime.utils.Float32Array;
import openfl.geom.Rectangle;
import util.Utils;
import util.Settings;

class Camera {
	public static inline var PX_PER_TILE: Int8 = 88;
	public static inline var SIZE_MULT: Float32 = 5.5;//PX_PER_TILE / 16;

	private static inline var MAX_JITTER: Float32 = 0.5;
	private static inline var JITTER_BUILDUP_MS: Int16 = 10000;

	public static var mapX: Float32 = 0.0;
	public static var mapY: Float32 = 0.0;
	public static var mapZ: Float32 = 0.0;

	public static var cos: Float32 = 1.0;
	public static var sin: Float32 = 0.0;
	public static var xScaledCos: Float32 = 0.5;
	public static var yScaledCos: Float32 = 0.5;
	public static var xScaledSin: Float32 = 0.0;
	public static var yScaledSin: Float32 = 0.0;
	public static var csX: Float32 = 0.0;
	public static var csY: Float32 = 0.0;

	public static var angleRad: Float32 = 0.0;
	public static var clipRect: Rectangle;
	public static var maxDist: Float32 = 0.0;
	public static var maxDistSq: Float32 = 0.0;
	public static var viewMatrix: Float32Array;

	private static var isJittering = false;
	private static var jitter: Float32 = 0.0;

	public static function init() {
		clipRect = new Rectangle(-Main.stageWidth * 0.5, -Main.stageHeight * 0.5, Main.stageWidth, Main.stageHeight);
		viewMatrix = new Float32Array([
			0, 0,  0, 0,
			0, 0, -1, 0,
			0, 0, -1, 0,
			0, 0,  0, 1
		]);
	}

	public static function configureCamera(x: Float32, y: Float32) {
		if (isJittering) {
			x += MathUtil.plusMinus(jitter);
			y += MathUtil.plusMinus(jitter);
		}

		mapX = x;
		mapY = y;
		// viewMatrix[11] = mapZ = 0;

		var cosAngle = MathUtil.cos(angleRad),
			sinAngle = MathUtil.sin(angleRad);
		cos = cosAngle * Camera.PX_PER_TILE;
		sin = sinAngle * Camera.PX_PER_TILE;
		xScaledCos = cos * RenderUtils.clipSpaceScaleX * 0.5;
		yScaledCos = cos * RenderUtils.clipSpaceScaleY * 0.5;
		xScaledSin = sin * RenderUtils.clipSpaceScaleX * 0.5;
		yScaledSin = sin * RenderUtils.clipSpaceScaleY * 0.5;
		csX = (x * cosAngle + y * sinAngle) * -Camera.PX_PER_TILE;
		csY = (x * -sinAngle + y * cosAngle) * -Camera.PX_PER_TILE;

		viewMatrix[0] = viewMatrix[5] = cos;
		viewMatrix[4] = -sin;
		viewMatrix[1] = sin;
		viewMatrix[3] = csX;
		viewMatrix[7] = csY;

		clipRect.x = -Main.stageWidth * 0.5;
		clipRect.y = -Main.stageHeight * 0.5;
		clipRect.width = Main.stageWidth;
		clipRect.height = Main.stageHeight;

		var w = clipRect.width / (2 * PX_PER_TILE);
		var h = clipRect.height / (2 * PX_PER_TILE);

		maxDist = Math.ceil(Math.sqrt(w * w + h * h)) + 1;
		maxDistSq = maxDist * maxDist;
	}

	public static function startJitter() {
		isJittering = true;
		jitter = 0;
	}

	public static function update(dt: Int16) {
		if (isJittering && jitter < MAX_JITTER) {
			jitter = jitter + dt * MAX_JITTER / JITTER_BUILDUP_MS;
			if (jitter > MAX_JITTER)
				jitter = MAX_JITTER;
		}
	}
}
