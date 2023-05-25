package ui.panels.itemgrids;

import objects.GameObject;
import objects.Player;
import ui.panels.itemgrids.itemtiles.InteractiveItemTile;
import util.NativeTypes;

class ContainerGrid extends ItemGrid {
	private static inline var NUM_SLOTS = 8;

	private var tiles: Array<InteractiveItemTile>;

	public function new(gridOwner: GameObject, currentPlayer: Player, disableBgDraw: Bool = false) {
		var tile: InteractiveItemTile = null;
		super(gridOwner, currentPlayer, 0, disableBgDraw);
		this.tiles = new Array<InteractiveItemTile>();
		for (i in 0...NUM_SLOTS) {
			tile = new InteractiveItemTile(i + indexOffset, this, true);
			addToGrid(tile, 2, i);
			this.tiles[i] = tile;
		}
	}

	override public function setItems(items: Array<Int32>, itemIndexOffset: Int32 = 0) {
		var numItems = 0;
		var i = 0;
		if (items != null) {
			numItems = items.length;
			for (i in 0...NUM_SLOTS) {
				if (i + indexOffset < numItems) {
					this.tiles[i].setItem(items[i + indexOffset]);
				} else {
					this.tiles[i].setItem(-1);
				}
			}
		}
	}
}
