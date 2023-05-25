package game.model;

import haxe.ds.IntMap;
import ui.model.VialData;

class VialModel {
	public static inline var HEALTH_VIAL_ID = 0xaa1;
	public static inline var HEALTH_VIAL_SLOT = 254;
	public static inline var MAGIC_VIAL_ID = 0xaa2;
	public static inline var MAGIC_VIAL_SLOT = 255;

	public static var vialData = new IntMap<VialData>();

	public static function getVialSlot(objectType: Int) {
		switch (objectType) {
			case HEALTH_VIAL_ID:
				return HEALTH_VIAL_SLOT;
			case MAGIC_VIAL_ID:
				return MAGIC_VIAL_SLOT;
			default:
				return -1;
		}
	}

	public static function init() {
		var data = new VialData();
		data.maxVialCount = 4;
		data.objectId = HEALTH_VIAL_ID;
		data.position = 0;
		vialData.set(data.position, data);

		var data = new VialData();
		data.maxVialCount = 4;
		data.objectId = MAGIC_VIAL_ID;
		data.position = 1;
		vialData.set(data.position, data);
	}

	public static function getVialData(objectId: Int) {
		for (vial in vialData)
			if (vial.objectId == objectId)
				return vial;

		return null;
	}
}
