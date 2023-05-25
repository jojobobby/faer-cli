package util;

import util.BinPacker.Rect;
import util.NativeTypes;
import haxe.ds.StringMap;
import openfl.display.BitmapData;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.GlowFilter;
import openfl.geom.Matrix;

class ConditionEffect {
	public static inline var NOTHING = 0;
	public static inline var DEAD = 1;
	public static inline var WEAK = 2;
	public static inline var SLOWED = 3;
	public static inline var SICK = 4;
	public static inline var SPEEDY = 5;
	public static inline var BLEEDING = 6;
	public static inline var HEALING = 7;
	public static inline var DAMAGING = 8;
	public static inline var INVULNERABLE = 9;
	public static inline var ARMORED = 10;
	public static inline var ARMOR_BROKEN = 11;
	public static inline var HIDDEN = 12;
	public static inline var TARGETED = 13;

	public static inline var DEAD_BIT = 1 << DEAD - 1;
	public static inline var WEAK_BIT = 1 << WEAK - 1;
	public static inline var SLOWED_BIT = 1 << SLOWED - 1;
	public static inline var SICK_BIT = 1 << SICK - 1;
	public static inline var SPEEDY_BIT = 1 << SPEEDY - 1;
	public static inline var BLEEDING_BIT = 1 << BLEEDING - 1;
	public static inline var HEALING_BIT = 1 << HEALING - 1;
	public static inline var DAMAGING_BIT = 1 << DAMAGING - 1;
	public static inline var INVULNERABLE_BIT = 1 << INVULNERABLE - 1;
	public static inline var ARMORED_BIT = 1 << ARMORED - 1;
	public static inline var ARMOR_BROKEN_BIT = 1 << ARMOR_BROKEN - 1;
	public static inline var HIDDEN_BIT = 1 << HIDDEN - 1;
	public static inline var TARGETED_BIT = 1 << TARGETED - 1;

	public static var effects: Array<ConditionEffect> = [
		new ConditionEffect("Nothing"),
		new ConditionEffect("Dead"),
		new ConditionEffect("Weak"),
		new ConditionEffect("Slowed"),
		new ConditionEffect("Sick"),
		new ConditionEffect("Speedy"),
		new ConditionEffect("Bleeding"),
		new ConditionEffect("Healing"),
		new ConditionEffect("Damaging"),
		new ConditionEffect("Invulnerable"),
		new ConditionEffect("Armored"),
		new ConditionEffect("Armor Broken"),
		new ConditionEffect("Hidden")
	];

	public static var effectRects: Array<Rect>;

	private static var conditionEffectFromName: StringMap<Int> = null;

	public var name = "";
	public var bit = 0;
	public var iconOffsets: Array<Int>;

	public static function initRects() {
		effectRects = [
			null,
			AssetLibrary.getRectFromSet("conditions", 5),
			AssetLibrary.getRectFromSet("conditions", 7),
			AssetLibrary.getRectFromSet("conditions", 10),
			AssetLibrary.getRectFromSet("conditions", 6),
			AssetLibrary.getRectFromSet("conditions", 2),
			AssetLibrary.getRectFromSet("conditions", 1),
			AssetLibrary.getRectFromSet("conditions", 4),
			AssetLibrary.getRectFromSet("conditions", 11),
			AssetLibrary.getRectFromSet("conditions", 3),
			AssetLibrary.getRectFromSet("conditions", 0),
			AssetLibrary.getRectFromSet("conditions", 9)
		];
	}

	public static function getConditionEffectFromName(name: String) {
		if (conditionEffectFromName == null) {
			conditionEffectFromName = new StringMap<Int>();
			for (ce in 0...effects.length)
				conditionEffectFromName.set(effects[ce].name, ce);
		}

		return conditionEffectFromName.get(name);
	}

	public function new(name: String) {
		this.name = name;
	}
}
