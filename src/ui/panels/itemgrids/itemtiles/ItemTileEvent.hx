package ui.panels.itemgrids.itemtiles;
import openfl.events.Event;

class ItemTileEvent extends Event {
	public static inline var ITEM_MOVE: String = "ITEM_MOVE";
	public static inline var ITEM_DOUBLE_CLICK: String = "ITEM_DOUBLE_CLICK";
	public static inline var ITEM_SHIFT_CLICK: String = "ITEM_SHIFT_CLICK";
	public static inline var ITEM_CLICK: String = "ITEM_CLICK";
	public static inline var ITEM_CTRL_CLICK: String = "ITEM_CTRL_CLICK";

	public var tile: InteractiveItemTile;

	public function new(eventType: String, itemTile: InteractiveItemTile) {
		super(eventType, true);
		this.tile = itemTile;
	}
}