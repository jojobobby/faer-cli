package util;

import cpp.Stdlib;
import cpp.RawPointer;
import lime.utils.ArrayBufferView;
import lime.graphics.opengl.GLBuffer;
import haxe.exceptions.ArgumentException;
import lime.graphics.opengl.GL;
import util.NativeTypes;
import haxe.ds.Vector;
import openfl.geom.ColorTransform;

using StringTools;

enum abstract KeyCode(UInt8) from UInt8 to UInt8 {
	final A = 65;
	final Alt = 18;
	final B = 66;
	final Backquote = 192;
	final Backslash = 220;
	final Backspace = 8;
	final C = 67;
	final CapsLock = 20;
	final Comma = 188;
	final Command = 15;
	final Control = 17;
	final D = 68;
	final Delete = 46;
	final Down = 40;
	final E = 69;
	final End = 35;
	final Enter = 13;
	final Equal = 187;
	final Escape = 27;
	final F = 70;
	final F1 = 112;
	final F10 = 121;
	final F11 = 122;
	final F12 = 123;
	final F13 = 124;
	final F14 = 125;
	final F15 = 126;
	final F2 = 113;
	final F3 = 114;
	final F4 = 115;
	final F5 = 116;
	final F6 = 117;
	final F7 = 118;
	final F8 = 119;
	final F9 = 120;
	final G = 71;
	final H = 72;
	final Home = 36;
	final I = 73;
	final Insert = 45;
	final J = 74;
	final K = 75;
	final L = 76;
	final Left = 37;
	final LeftBracket = 219;
	final M = 77;
	final Minus = 189;
	final N = 78;
	final Number0 = 48;
	final Number1 = 49;
	final Number2 = 50;
	final Number3 = 51;
	final Number4 = 52;
	final Number5 = 53;
	final Number6 = 54;
	final Number7 = 55;
	final Number8 = 56;
	final Number9 = 57;
	final NumLock = 144;
	final Numpad = 21;
	final Numpad0 = 96;
	final Numpad1 = 97;
	final Numpad2 = 98;
	final Numpad3 = 99;
	final Numpad4 = 100;
	final Numpad5 = 101;
	final Numpad6 = 102;
	final Numpad7 = 103;
	final Numpad8 = 104;
	final Numpad9 = 105;
	final NumpadAdd = 107;
	final NumpadDecimal = 110;
	final NumpadDivide = 111;
	final NumpadEnter = 108;
	final NumpadMultiply = 106;
	final NumpadSubtract = 109;
	final O = 79;
	final P = 80;
	final PageDown = 34;
	final PageUp = 33;
	final Pause = 19;
	final Period = 190;
	final Q = 81;
	final Quote = 222;
	final R = 82;
	final Right = 39;
	final RightBracket = 221;
	final S = 83;
	final ScrollLock = 145;
	final SemiColon = 186;
	final Shift = 16;
	final Slash = 191;
	final Space = 32;
	final T = 84;
	final Tab = 9;
	final U = 85;
	final Up = 38;
	final V = 86;
	final W = 87;
	final X = 88;
	final Y = 89;
	final Z = 90;
	final Mouse1 = 223;
	final Mouse2 = 224;
	final Mouse3 = 225;
	final Unset = 0;
}

class KeyCodeUtil {
	public static final charCodeStrings = [
		"[Unset]", "", "", "", "", "", "", "", "Backspace", "Tab", "", "", "Clear", "Enter", "", "Cmd", "Shift", "Ctrl", "Alt", "Pause", "CapsLock", "", "",
		"", "", "", "", "Esc", "", "", "", "", "Space", "PgUp", "PgDn", "End", "Home", "Left", "Up", "Right", "Down", "", "", "", "", "Insert", "Delete", "",
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "", "", "", "", "", "", "", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
		"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "", "Win", "Menu", "", "", "Numpad 0", "Numpad 1", "Numpad 2", "Numpad 3", "Numpad 4",
		"Numpad 5", "Numpad 6", "Numpad 7", "Numpad 8", "Numpad 9", "Numpad *", "Numpad +", "Numpad Enter", "Numpad -", "Numpad .", "Numpad /", "F1", "F2",
		"F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
		"", "NumLock", "ScrLock", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "", "", ";", "=", ",", "-", ".", "/", "`", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "[", "\\", "]", "\'", "Mouse1", "Mouse2", "Mouse3", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "", "", "", "", ""
	];

	public static final charCodeIconIndices = [
		-1, -1, -1, -1, -1, -1, -1, -1, 35, 79, -1, -1, -1, 55, -1, 48, 15, 49, 21, -1, 40, -1, -1, -1, -1, -1, -1, 64, -1, -1, -1, -1, 57, 89, 90, 53, 87,
		23, 32, 24, 22, -1, -1, -1, -1, 62, 51, -1, 0, 4, 5, 6, 7, 8, 16, 17, 18, 19, -1, -1, -1, -1, -1, -1, -1, 20, 34, 39, 50, 52, 84, 85, 86, 88, 63, 74,
		75, 76, 61, 65, 66, 25, 28, 29, 73, 67, 31, 10, 12, 13, 14, -1, 11, -1, -1, -1, 0, 4, 5, 6, 7, 8, 16, 17, 18, -1, -1, 55, 45, -1, -1, 67, 68, 69, 70,
		71, 79, 80, 81, 82, 1, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 30, -1, -1, 45, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 37, 41, 38, -1, -1, 46, 59, 58, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
	];
}

class MathUtil {
	public static inline var INT_MAX = 2147483647;
	public static inline var INT_MIN = -2147483648;
	public static inline var FLOAT_MAX: Float32 = 3.4028235E+38;
	public static inline var FLOAT_MIN: Float32 = -3.4028235E+38;
	public static inline var PI: Float32 = 3.141592653589793;
	public static inline var PI_DIV_2: Float32 = PI / 2;
	public static inline var TO_DEG: Float32 = 180 / PI;
	public static inline var TO_RAD: Float32 = PI / 180;

	private static inline var SIN_MASK = ~(-1 << 16);
	private static inline var SIN_COUNT = SIN_MASK + 1;

	private static inline var RAD_FULL = PI * 2;
	private static inline var RAD_TO_INDEX = SIN_COUNT / RAD_FULL;
	private static inline var DEG_TO_INDEX = SIN_COUNT / 360;

	private static var SIN_TABLE: RawPointer<Float32>;

	public static function init() {
		SIN_TABLE = cast Stdlib.nativeMalloc(SIN_COUNT * 4);
		for (i in 0...SIN_COUNT)
			SIN_TABLE[i] = Math.sin((i + 0.5) / SIN_COUNT * RAD_FULL);

		var i = 0;
		while (i < 360) {
			SIN_TABLE[Std.int(i * DEG_TO_INDEX) & SIN_MASK] = Math.sin(i * TO_RAD);
			i += 90;
		}
	}

	public static #if !tracing inline #end function sin(x: Float32) {
		return SIN_TABLE[Math.round(x * RAD_TO_INDEX) & SIN_MASK];
	}

	public static #if !tracing inline #end function cos(x: Float32) {
		return SIN_TABLE[Math.round((x + MathUtil.PI * 0.5) * RAD_TO_INDEX) & SIN_MASK];
	}

	public static #if !tracing inline #end function plusMinus(range: Float32) {
		return Math.random() * range * 2 - range;
	}

	public static function halfBound(x: Float32) {
		if (x < -PI)
			return x + (Math.floor(x / -PI) + 1) * PI;
		else if (x > PI)
			return x - (Math.floor(x / PI) + 1) * PI;
		else
			return x;
	}
}

class StringUtils {
	public static function toRoman(n: Int) {
		if (n == 0)
			return "0";

		var number = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
		var sign = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];
		var ret = "";
		var i = 0;
		while (i < 13 && n > 0) {
			while (number[i] <= n) {
				n -= number[i];
				ret += sign[i];
			}
			i++;
		}

		return ret;
	}
}

class ColorUtils {
	public static var greyscaleFilterMatrix = [
		0.3, 0.59, 0.11, 0, 0, 0.3, 0.59, 0.11, 0, 0, 0.3, 0.59, 0.11, 0, 0, 0, 0, 0, 1, 0
	];
	public static var identity = new ColorTransform();
	public static var darkCT = new ColorTransform(0.6, 0.6, 0.6, 1, 0, 0, 0, 0);
	public static var veryDarkCT = new ColorTransform(0.4, 0.4, 0.4, 1, 0, 0, 0, 0);

	public static function adjustBrightness(color: Int, num: Float) {
		var a = color & 0xFF000000;
		var r = Std.int(((color & 0xFF0000) >> 16) + num * 255);
		r = r < 0 ? 0 : r > 255 ? 255 : r;
		var g = Std.int(((color & 65280) >> 8) + num * 255);
		g = g < 0 ? 0 : g > 255 ? 255 : g;
		var b = Std.int((color & 255) + num * 255);
		b = b < 0 ? 0 : b > 255 ? 255 : b;
		return a | r << 16 | g << 8 | b;
	}

	public static function greenToRed(perc: Int) {
		return perc > 50 ? 0x00FF00 + 0x050000 * (100 - perc) : 0xFFFF00 - 0x000500 * (50 - perc);
	}

	public static function singleColorFilterMatrix(color: Int) {
		return [
			0.0, 0, 0, 0, (color & 0xFF0000) >> 16, 0, 0, 0, 0, (color & 65280) >> 8, 0, 0, 0, 0, color & 255, 0, 0, 0, 1, 0
		];
	}

	public static function getRarityColor(rarity: String, defaultColor: Int = 0x545454) {
		switch (rarity) {
			case "Mythic":
				return 0x930000;
			case "Legendary":
				return 0xE6A100;
			case "Epic":
				return 0xA825E6;
			case "Rare":
				return 0x2575E6;
			default:
				return defaultColor;
		}
	}
}

class RenderUtils {
	public static var clipSpaceScaleX: Float32 = 2 / 1280;
	public static var clipSpaceScaleY: Float32 = 2 / 720;

	public static #if !tracing inline #end function compileShaders(vertSrc: String, fragSrc: String) {
		var vert = GL.createShader(GL.VERTEX_SHADER);
		GL.shaderSource(vert, vertSrc);
		GL.compileShader(vert);

		if (GL.getShaderParameter(vert, GL.COMPILE_STATUS) == 0)
			throw new ArgumentException("Error compiling vertex shader:" + "\n" + GL.getShaderInfoLog(vert) + "\n" + vertSrc);

		var frag = GL.createShader(GL.FRAGMENT_SHADER);
		GL.shaderSource(frag, fragSrc);
		GL.compileShader(frag);

		if (GL.getShaderParameter(frag, GL.COMPILE_STATUS) == 0)
			throw new ArgumentException("Error compiling fragment shader:" + "\n" + GL.getShaderInfoLog(frag) + "\n" + fragSrc);

		var prog = GL.createProgram();
		GL.attachShader(prog, vert);
		GL.attachShader(prog, frag);
		GL.linkProgram(prog);

		if (GL.getProgramParameter(prog, GL.LINK_STATUS) == 0)
			throw new ArgumentException("Unable to initialize the shader program" + "\n" + GL.getProgramInfoLog(prog));

		return prog;
	}

	public static #if !tracing inline #end function createVertexBuffer(data: ArrayBufferView, drawType: Int32 = GL.STATIC_DRAW) {
		#if debug
		if (drawType != GL.STATIC_DRAW && drawType != GL.DYNAMIC_DRAW && drawType != GL.STREAM_DRAW)
			throw new ArgumentException("Invalid draw type");
		#end

		var vbo = GL.createBuffer();
		uploadVertexData(vbo, data, drawType);
		return vbo;
	}

	public static #if !tracing inline #end function uploadVertexData(vbo: GLBuffer, data: ArrayBufferView, drawType: Int32 = GL.STATIC_DRAW) {
		#if debug
		if (drawType != GL.STATIC_DRAW && drawType != GL.DYNAMIC_DRAW && drawType != GL.STREAM_DRAW)
			throw new ArgumentException("Invalid draw type");
		#end

		GL.bindBuffer(GL.ARRAY_BUFFER, vbo);
		GL.bufferData(GL.ARRAY_BUFFER, data.byteLength, data, drawType);
	}

	public static #if !tracing inline #end function createIndexBuffer(data: ArrayBufferView, drawType: Int32 = GL.STATIC_DRAW) {
		#if debug
		if (drawType != GL.STATIC_DRAW && drawType != GL.DYNAMIC_DRAW && drawType != GL.STREAM_DRAW)
			throw new ArgumentException("Invalid draw type");
		#end

		var ibo = GL.createBuffer();
		uploadIndexData(ibo, data, drawType);
		return ibo;
	}

	public static #if !tracing inline #end function uploadIndexData(ibo: GLBuffer, data: ArrayBufferView, drawType: Int32 = GL.STATIC_DRAW) {
		#if debug
		if (drawType != GL.STATIC_DRAW && drawType != GL.DYNAMIC_DRAW && drawType != GL.STREAM_DRAW)
			throw new ArgumentException("Invalid draw type");
		#end

		GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, ibo);
		GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, data.byteLength, data, drawType);
	}

	public static #if !tracing inline #end function bindVertexBuffer(index: Int32, vbo: GLBuffer, size: Int32 = 4, stride: Int32 = 0) {
		GL.bindBuffer(GL.ARRAY_BUFFER, vbo);
		GL.enableVertexAttribArray(index);
		GL.vertexAttribPointer(index, size, GL.FLOAT, false, stride, 0);
	}

	public static #if !tracing inline #end function uploadFlashUniforms(color: Int32, strength: Float32) {
		GL.uniform1i(cast 6, color);
		GL.uniform1f(cast 7, strength);
	}

	public static #if !tracing inline #end function baseRender(w: Float32, h: Float32, x: Float32, y: Float32, uMult: Float32, vMult: Float32, u: Float32,
			v: Float32, outlineSize: Int32 = 2, glowColor: Int32 = 0) {
		GL.uniform4f(cast 0, w * clipSpaceScaleX, 0, 0, h * clipSpaceScaleY);
		GL.uniform2f(cast 1, x * clipSpaceScaleX, y * clipSpaceScaleY);
		GL.uniform2f(cast 2, uMult, vMult);
		GL.uniform2f(cast 3, u, v);
		GL.uniform2f(cast 4, outlineSize / Main.ATLAS_WIDTH / 11, outlineSize / Main.ATLAS_HEIGHT / 11);
		GL.uniform1i(cast 5, glowColor);
		GL.drawElements(GL.TRIANGLES, 6, GL.UNSIGNED_SHORT, 0);
	}

	public static #if !tracing inline #end function baseRenderRotate(cos: Float32, sin: Float32, w: Float32, h: Float32, x: Float32, y: Float32,
			uMult: Float32, vMult: Float32, u: Float32, v: Float32, outlineSize: Int32 = 2, glowColor: Int32 = 0) {
		GL.uniform4f(cast 0, cos * w * clipSpaceScaleX, sin * h * clipSpaceScaleX, -sin * w * clipSpaceScaleY, cos * h * clipSpaceScaleY);
		GL.uniform2f(cast 1, x * clipSpaceScaleX, y * clipSpaceScaleY);
		GL.uniform2f(cast 2, uMult, vMult);
		GL.uniform2f(cast 3, u, v);
		GL.uniform2f(cast 4, outlineSize / Main.ATLAS_WIDTH / 11, outlineSize / Main.ATLAS_HEIGHT / 11);
		GL.uniform1i(cast 5, glowColor);
		GL.drawElements(GL.TRIANGLES, 6, GL.UNSIGNED_SHORT, 0);
	}
}

class ArrayUtils {
	// https://github.com/jeremyfa/polyline/blob/a6184e74a73b047fee4e66e1c43da8a3748fe766/polyline/Extensions.hx
	#if !debug #if !tracing inline #end #end public static function unsafeGet<T>(array: Array<T>, index: Int): T {
		#if debug
		if (index < 0 || index >= array.length)
			throw 'Invalid unsafeGet: index=$index length=${array.length}';
		#end
		#if cpp
		return untyped array.__unsafe_get(index);
		#elseif cs
		return cast untyped __cs__('{0}.__a[{1}]', array, index);
		#else
		return array[index];
		#end
	}

	#if !debug #if !tracing inline #end #end public static function unsafeSet<T>(array: Array<T>, index: Int, value: T): Void {
		#if debug
		if (index < 0 || index >= array.length)
			throw 'Invalid unsafeSet: index=$index length=${array.length}';
		#end
		#if cpp
		untyped array.__unsafe_set(index, value);
		#elseif cs
		return cast untyped __cs__('{0}.__a[{1}] = {2}', array, index, value);
		#else
		array[index] = value;
		#end
	}
}

class XmlUtil {
	public static #if !tracing inline #end function asXml(str: String): Xml {
		return Xml.parse(str).firstElement();
	}

	public static #if !tracing inline #end function elementExists(xml: Xml, elemName: String) {
		return xml.elementsNamed(elemName).hasNext();
	}

	public static #if !tracing inline #end function attribute(xml: Xml, attr: String, defaultValue: String = "") {
		return xml.get(attr) ?? defaultValue;
	}

	public static #if !tracing inline #end function intAttribute(xml: Xml, attr: String, defaultValue: Int32 = 0): Int32 {
		return xml.get(attr) != null ? Std.parseInt(xml.get(attr)) : defaultValue;
	}

	public static #if !tracing inline #end function floatAttribute(xml: Xml, attr: String, defaultValue: Float32 = 0): Float32 {
		return xml.get(attr) != null ? Std.parseFloat(xml.get(attr)) : defaultValue;
	}

	public static #if !tracing inline #end function element(xml: Xml, elemName: String, defaultValue: String = "") {
		return xml.elementsNamed(elemName)
			.hasNext() ? xml.elementsNamed(elemName)
			.next()
			.firstChild()
			.nodeValue : defaultValue;
	}

	public static #if !tracing inline #end function intElement(xml: Xml, elemName: String, defaultValue: Int32 = 0): Int32 {
		return xml.elementsNamed(elemName).hasNext() ? Std.parseInt(xml.elementsNamed(elemName).next().firstChild().nodeValue) : defaultValue;
	}

	public static #if !tracing inline #end function floatElement(xml: Xml, elemName: String, defaultValue: Float32 = 0): Float32 {
		return xml.elementsNamed(elemName).hasNext() ? Std.parseFloat(xml.elementsNamed(elemName).next().firstChild().nodeValue) : defaultValue;
	}

	public static #if !tracing inline #end function value(xml: Xml, defaultValue: String = "") {
		return xml?.firstChild().nodeValue ?? defaultValue;
	}

	public static #if !tracing inline #end function intValue(xml: Xml, defaultValue: Int32 = 0): Int32 {
		return xml != null ? Std.parseInt(xml.firstChild().nodeValue) : defaultValue;
	}

	public static #if !tracing inline #end function floatValue(xml: Xml, defaultValue: Float32 = 0): Float32 {
		return xml != null ? Std.parseFloat(xml.firstChild().nodeValue) : defaultValue;
	}

	public static #if !hl #if !tracing inline #end #end function intListElement(xml: Xml, elemName: String): Array<Int32> {
		#if hl
		var list: Array<Int32> = [];
		if (!elementExists(xml, elemName))
			return list;

		for (child in xml.elementsNamed(elemName))
			for (str in value(child).split(","))
				list.push(cast(Std.parseInt(str), Int32));

		return list;
		#end

		return xml.elementsNamed(elemName)
			.hasNext() ? xml.elementsNamed(elemName)
			.next()
			.firstChild()
			.nodeValue.split(",")
			.map(x -> cast(Std.parseInt(x), Int32)) : new Array<Int32>();
	}

	public static #if !hl #if !tracing inline #end #end function floatListElement(xml: Xml, elemName: String): Array<Float32> {
		#if hl
		var list: Array<Float32> = [];
		if (!elementExists(xml, elemName))
			return list;

		for (child in xml.elementsNamed(elemName))
			for (str in value(child).split(","))
				list.push(cast(Std.parseFloat(str), Float32));

		return list;
		#end

		return xml.elementsNamed(elemName)
			.hasNext() ? xml.elementsNamed(elemName)
			.next()
			.firstChild()
			.nodeValue.split(",")
			.map(x -> cast(Std.parseFloat(x), Float32)) : new Array<Float32>();
	}
}
