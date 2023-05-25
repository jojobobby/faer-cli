package mapeditor;

import openfl.events.Event;

class TilesEvent extends Event {
	public static inline var TILES_EVENT = "TILES_EVENT";

	public var tiles: Array<IntPoint>;

	public function new(tiles: Array<IntPoint>) {
		super(TILES_EVENT);
		this.tiles = tiles;
	}
}
