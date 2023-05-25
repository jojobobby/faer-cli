package ui.panels.itemgrids.itemtiles;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import ui.panels.itemgrids.ItemGrid;
import ui.SimpleText;

class InventoryTile extends InteractiveItemTile {
	public function new(id: Int, parentGrid: ItemGrid, isInteractive: Bool) {
		super(id, parentGrid, isInteractive);
	}

	override public function setItemSprite(newItemSprite: ItemTileSprite) {
		super.setItemSprite(newItemSprite);
		newItemSprite.setDim(false);
	}
}
