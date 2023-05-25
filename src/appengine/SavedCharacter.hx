package appengine;

import objects.ObjectLibrary;
import openfl.display.BitmapData;
import openfl.geom.ColorTransform;
import util.AnimatedChar;
import util.AnimatedChars;
import util.CachingColorTransformer;
import util.GlowRedrawer;
import util.MaskedImage;
import util.TextureRedrawer;

class SavedCharacter {
	private static var notAvailableCT: ColorTransform = new ColorTransform(0, 0, 0, 0.5, 0, 0, 0, 0);
	private static var dimCT: ColorTransform = new ColorTransform(0.75, 0.75, 0.75, 1, 0, 0, 0, 0);

	public var charXML: Xml;
	public var _name: String = null;

	public static function getImage(savedChar: SavedCharacter, playerXML: Xml, dir: Int, action: Int, p: Float, available: Bool, selected: Bool) {
		var animXML: Xml = playerXML.elementsNamed("AnimatedTexture").next();
		var animatedChar: AnimatedChar = AnimatedChars.getAnimatedChar(animXML.elementsNamed("Sheet").next().firstChild().nodeValue,
			Std.parseInt(animXML.elementsNamed("Index").next().firstChild().nodeValue));
		var image: MaskedImage = animatedChar.imageFromDir(dir, action, p);
		var bd: BitmapData = GlowRedrawer.outlineGlow(TextureRedrawer.resize(image.image, 100, false), 0);
		if (!available)
			bd = CachingColorTransformer.transformBitmapData(bd, notAvailableCT);
		else if (!selected)
			bd = CachingColorTransformer.transformBitmapData(bd, dimCT);

		return bd;
	}

	public static function compare(char1: SavedCharacter, char2: SavedCharacter) {
		return char2.tier() - char1.tier();
	}

	public function new(charXML: Xml, name: String) {
		this.charXML = charXML;
		this._name = name;
	}

	public function charId() {
		return Std.parseInt(this.charXML.get("id"));
	}

	public function name() {
		return this._name;
	}

	public function objectType() {
		return Std.parseInt(this.charXML.elementsNamed("ObjectType").next().firstChild().nodeValue);
	}

	public function skinType() {
		return Std.parseInt(this.charXML.elementsNamed("Texture").next().firstChild().nodeValue);
	}

	public function tier() {
		return this.charXML.elementsNamed("Tier").hasNext() ? Std.parseInt(this.charXML.elementsNamed("Tier").next().firstChild().nodeValue) : 0;
	}

	public function displayId() {
		return ObjectLibrary.typeToDisplayId.get(this.objectType());
	}
}
