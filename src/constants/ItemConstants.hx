package constants;

class ItemConstants {
	public static inline var NO_ITEM: Int = -1;
	public static inline var ALL_TYPE = 0;
	public static inline var ACCESSORY_TYPE: Int = 9;
	public static inline var CONSUMABLE_TYPE: Int = 10;

	public static inline var SWORD_TYPE: Int = 1;
	public static inline var BOW_TYPE: Int = 3;
	public static inline var STAFF_TYPE: Int = 17;
	public static inline var SCEPTER_TYPE: Int = 23;
	public static inline var ANY_WEAPON_TYPE: Int = 22;
	public static var WEAPON_TYPES: Array<Int> = [SWORD_TYPE, BOW_TYPE, STAFF_TYPE, SCEPTER_TYPE];

	public static inline var HIDE_TYPE: Int = 6;
	public static inline var VEST_TYPE: Int = 7;
	public static inline var ROBE_TYPE: Int = 14;
	public static inline var ANY_ARMOR_TYPE: Int = 20;
	public static var ARMOR_TYPES: Array<Int> = [HIDE_TYPE, VEST_TYPE, ROBE_TYPE];

	public static inline var FLASK_TYPE: Int = 4;
	public static inline var BLOODSTONE_TYPE: Int = 5;
	public static inline var TOTEM_TYPE: Int = 8;
	public static inline var HELM_TYPE: Int = 16;
	public static inline var BULWARK_TYPE: Int = 12;
	public static inline var CLOCK_TYPE: Int = 15;
	public static inline var CAGE_TYPE: Int = 19;
	public static inline var ANY_ABILITY_TYPE: Int = 21;
	public static var ABILITY_TYPES: Array<Int> = [
		FLASK_TYPE, BLOODSTONE_TYPE, TOTEM_TYPE,
		 HELM_TYPE,    BULWARK_TYPE, CLOCK_TYPE
	];
}
