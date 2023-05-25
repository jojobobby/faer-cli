package map;

import haxe.ds.IntMap;
import haxe.ds.StringMap;

class RegionLibrary {
	public static var xmlLibrary: IntMap<Xml> = new IntMap<Xml>();
	public static var idToType: StringMap<Int> = new StringMap<Int>();

	public static function parseFromXML(xml: Xml) {
		var objType = 0;
		for (regionXML in xml.elementsNamed("Region")) {
			objType = Std.parseInt(regionXML.get("type"));
			xmlLibrary.set(objType, regionXML);
			idToType.set(regionXML.get("id"), objType);
		}
	}

	public static function getIdFromType(objType: Int) {
		var objectXML: Xml = xmlLibrary.get(objType);
		if (objectXML == null)
			return null;

		return objectXML.get("id");
	}

	public static function getColor(objType: Int) {
		var objectXML = xmlLibrary.get(objType);
		if (objectXML == null)
			return 0;

		return Std.parseInt(objectXML.elementsNamed("Color").next().firstChild().nodeValue);
	}
}
