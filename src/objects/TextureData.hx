package objects;

import util.BinPacker.Rect;
import util.NativeTypes;
import haxe.ds.IntMap;
import openfl.display.BitmapData;
import util.AnimatedChar;
import util.AnimatedChars;
import util.AssetLibrary;
import util.MaskedImage;

using util.Utils;

class TextureData {
	public var texture: BitmapData = null;
	public var mask: BitmapData = null;
	public var animatedChar: AnimatedChar = null;
	public var randomTextureData: Array<TextureData> = null;
	public var altTextures: IntMap<TextureData> = null;
	public var rect: Rect = null;
	public var uValue: Float32 = 0.0;
	public var vValue: Float32 = 0.0;
	public var width: Float32 = 0.0;
	public var height: Float32 = 0.0;
	public var maskUValue: Float32 = 0.0;
	public var maskVValue: Float32 = 0.0;
	public var maskWidth: Float32 = 0.0;
	public var maskHeight: Float32 = 0.0;

	public function new(objectXML: Xml, forceTex: Bool = false) {
		if (forceTex) {
			this.parse(objectXML, "Texture");
			return;
		}

		if (objectXML.elementsNamed("Texture").hasNext())
			this.parse(objectXML.elementsNamed("Texture").next(), "Texture");
		else if (objectXML.elementsNamed("AnimatedTexture").hasNext())
			this.parse(objectXML.elementsNamed("AnimatedTexture").next(), "AnimatedTexture");
		else if (objectXML.elementsNamed("RandomTexture").hasNext())
			this.parse(objectXML.elementsNamed("RandomTexture").next(), "RandomTexture");

		for (altTexture in objectXML.elementsNamed("AltTexture"))
			this.parse(altTexture, "AltTexture");

		if (objectXML.elementsNamed("Mask").hasNext())
			this.parse(objectXML.elementsNamed("Mask").next(), "Mask");
	}

	public function getTexture(id: Int = 0) {
		if (this.randomTextureData == null)
			return this.texture;

		return this.randomTextureData[
			id == -1 ? Math.floor(Math.random() * this.randomTextureData.length) : id % this.randomTextureData.length
		].texture;
	}

	public function getRect(id: Int = 0) {
		if (this.randomTextureData == null)
			return this.rect;

		return this.randomTextureData[
			id == -1 ? Math.floor(Math.random() * this.randomTextureData.length) : id % this.randomTextureData.length
		].rect;
	}

	public function getTextureData(id: Int = -1) {
		if (this.randomTextureData == null)
			return this;

		return this.randomTextureData[
			id == -1 ? Math.floor(Math.random() * this.randomTextureData.length) : id % this.randomTextureData.length
		];
	}

	public function getAltTextureData(id: Int) {
		if (this.altTextures == null)
			return null;

		return this.altTextures.get(id);
	}

	private function parse(xml: Xml, type: String) {
		var image: MaskedImage = null;
		switch (type) {
			case "Texture":
				var index = xml.intElement("Index");
				var sheet = xml.element("Sheet");
				this.texture = AssetLibrary.getImageFromSet(sheet, index);
				this.rect = AssetLibrary.getRectFromSet(sheet, index);
				if (sheet == "ground") {
					this.uValue = (this.rect.x + Main.PADDING) / Main.ATLAS_WIDTH;
					this.vValue = (this.rect.y + Main.PADDING) / Main.ATLAS_HEIGHT;
					this.width = this.rect.width / Main.ATLAS_WIDTH;
					this.height = this.rect.height / Main.ATLAS_HEIGHT;
				} else {
					this.uValue = this.rect.x / Main.ATLAS_WIDTH;
					this.vValue = this.rect.y / Main.ATLAS_HEIGHT;
					this.width = this.rect.width / Main.ATLAS_WIDTH;
					this.height = this.rect.height / Main.ATLAS_HEIGHT;
				}
			case "Mask":
				var index = xml.intElement("Index");
				var sheet = xml.element("Sheet");
				this.mask = AssetLibrary.getImageFromSet(sheet, index);
				this.rect = AssetLibrary.getRectFromSet(sheet, index);
				if (sheet == "ground") {
					this.uValue = (this.rect.x + Main.PADDING) / Main.ATLAS_WIDTH;
					this.vValue = (this.rect.y + Main.PADDING) / Main.ATLAS_HEIGHT;
					this.width = this.rect.width / Main.ATLAS_WIDTH;
					this.height = this.rect.height / Main.ATLAS_HEIGHT;
				} else {
					this.uValue = this.rect.x / Main.ATLAS_WIDTH;
					this.vValue = this.rect.y / Main.ATLAS_HEIGHT;
					this.width = this.rect.width / Main.ATLAS_WIDTH;
					this.height = this.rect.height / Main.ATLAS_HEIGHT;
				}
			case "AnimatedTexture":
				this.animatedChar = AnimatedChars.getAnimatedChar(xml.element("Sheet"), xml.intElement("Index"));
				if (this.animatedChar != null) {
					image = this.animatedChar.imageFromAngle(0, AnimatedChar.STAND, 0);
					this.texture = image.image;
					this.mask = image.mask;
				}

			case "RandomTexture":
				this.randomTextureData = new Array<TextureData>();
				for (childXML in xml.elementsNamed("Texture"))
					this.randomTextureData.push(new TextureData(childXML, true));
			case "AltTexture":
				if (this.altTextures == null)
					this.altTextures = new IntMap<TextureData>();

				this.altTextures.set(Std.parseInt(xml.get("id")), new TextureData(xml));
		}
	}
}
