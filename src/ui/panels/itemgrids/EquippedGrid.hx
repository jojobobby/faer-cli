package ui.panels.itemgrids;

import objects.GameObject;
import objects.Player;
import ui.panels.itemgrids.itemtiles.EquipmentTile;
import util.NativeTypes;

class EquippedGrid extends ItemGrid {
	private static inline var NUM_SLOTS = 4;

	private var tiles: Array<EquipmentTile>;

	public function new(gridOwner: GameObject, invTypes: Array<Int32>, currentPlayer: Player, itemIndexOffset: Int = 0, disableBgDraw: Bool = false) {
		var tile: EquipmentTile = null;
		super(gridOwner, currentPlayer, itemIndexOffset, disableBgDraw);
		this.tiles = new Array<EquipmentTile>();
		for (i in 0...NUM_SLOTS) {
			tile = new EquipmentTile(i, this, interactive);
			addToGrid(tile, 0, i);
			tile.setType(invTypes[i]);
			this.tiles[i] = tile;
		}
	}

	override public function setItems(items: Array<Int32>, itemIndexOffset: Int = 0) {
		var numItems = 0;
		var i = 0;
		if (items != null) {
			numItems = items.length;
			for (i in 0...this.tiles.length) {
				if (i + itemIndexOffset < numItems) {
					this.tiles[i].setItem(items[i + itemIndexOffset]);
				} else {
					this.tiles[i].setItem(-1);
				}
				this.tiles[i].updateDim(curPlayer);
			}
		}
	}
}
