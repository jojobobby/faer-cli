package map;

import objects.animation.AnimationsData;
import util.NativeTypes.UInt16;
import haxe.ds.IntMap;
import haxe.ds.StringMap;
import objects.TextureData;
import util.BitmapUtil;

using util.Utils;

class GroundLibrary {
	public static var propsLibrary = new IntMap<GroundProperties>();
	public static var xmlLibrary = new IntMap<Xml>();
	public static var typeToTextureData = new IntMap<TextureData>();
	public static var typeToAnimationsData = new IntMap<AnimationsData>();
	public static var idToType = new StringMap<Int>();
	public static var defaultProps: GroundProperties;
	private static var tileTypeColor = new IntMap<Int>();

	public static function parseFromXML(xml: Xml) {
		for (groundXML in xml.elementsNamed("Ground")) {
			var groundType: UInt16 = groundXML.intAttribute("type");
			propsLibrary.set(groundType, new GroundProperties(groundXML));
			xmlLibrary.set(groundType, groundXML);
			typeToTextureData.set(groundType, new TextureData(groundXML));
			idToType.set(groundXML.attribute("id"), groundType);

			if (groundXML.elementsNamed("Animation").hasNext())
				typeToAnimationsData.set(groundType, new AnimationsData(groundXML));
		}

		defaultProps = propsLibrary.get(idToType.get("Grass"));
	}

	public static function getIdFromType(tileType: Int) {
		if (!propsLibrary.exists(tileType))
			return null;

		return propsLibrary.get(tileType).objId;
	}

	public static function getBitmapData(tileType: Int, id: Int = 0) {
		return typeToTextureData.get(tileType).getTexture(id);
	}

	public static function getColor(groundType: Int) {
		if (!tileTypeColor.exists(groundType))
			tileTypeColor.set(groundType, BitmapUtil.mostCommonColor(getBitmapData(groundType)));

		return tileTypeColor.get(groundType);
	}
}
