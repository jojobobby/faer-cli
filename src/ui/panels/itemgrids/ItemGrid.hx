package ui.panels.itemgrids;

import openfl.display.Stage;
import network.NetworkHandler;
import constants.InventoryOwnerTypes;
import constants.ItemConstants;
import game.model.VialModel;
import map.Map;
import objects.GameObject;
import objects.ObjectLibrary;
import objects.Player;
import openfl.display.DisplayObject;
import openfl.events.Event;
import openfl.events.MouseEvent;
import ui.panels.itemgrids.itemtiles.InteractiveItemTile;
import ui.panels.itemgrids.itemtiles.ItemTile;
import ui.panels.itemgrids.itemtiles.ItemTileEvent;
import ui.panels.Panel;
import ui.tooltip.EquipmentToolTip;
import ui.view.Inventory;
import ui.view.VialSlotView;
import util.NativeTypes;

class ItemGrid extends Panel {
	private static var NO_CUT = [0, 0, 0, 0];
	private static var CutsByNum = [
		[[1, 0, 0, 1], NO_CUT, NO_CUT, [0, 1, 1, 0]],
		[
			[1, 0, 0, 0], NO_CUT, NO_CUT, [0, 1, 0, 0],
			[0, 0, 0, 1], NO_CUT, NO_CUT, [0, 0, 1, 0]
		],
		[
			[1, 0, 0, 1], NO_CUT, NO_CUT, [0, 1, 1, 0],
			[1, 0, 0, 0], NO_CUT, NO_CUT, [0, 1, 0, 0],
			[0, 0, 0, 1], NO_CUT, NO_CUT, [0, 0, 1, 0]
		]
	];
	private static inline var padding = 4;
	private static inline var rowLength = 4;

	public var owner: GameObject;
	public var curPlayer: Player;
	public var interactive = false;
	public var indexOffset = 0;
	public var disableBgDraw = false;

	private var tooltip: EquipmentToolTip;

	public function new(gridOwner: GameObject, currentPlayer: Player, itemIndexOffset: Int, disableBgDraw = false) {
		super(null);
		this.owner = gridOwner;
		this.curPlayer = currentPlayer;
		this.indexOffset = itemIndexOffset;
		this.disableBgDraw = disableBgDraw;
		if (gridOwner == currentPlayer)
			this.interactive = true;

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		addEventListener(ItemTileEvent.ITEM_MOVE, this.onTileMove);
		addEventListener(ItemTileEvent.ITEM_SHIFT_CLICK, onShiftClick);
		addEventListener(ItemTileEvent.ITEM_DOUBLE_CLICK, this.onDoubleClick);
		addEventListener(ItemTileEvent.ITEM_CTRL_CLICK, this.onCtrlClick);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		removeEventListener(ItemTileEvent.ITEM_MOVE, this.onTileMove);
		removeEventListener(ItemTileEvent.ITEM_SHIFT_CLICK, onShiftClick);
		removeEventListener(ItemTileEvent.ITEM_DOUBLE_CLICK, this.onDoubleClick);
		removeEventListener(ItemTileEvent.ITEM_CTRL_CLICK, this.onCtrlClick);
	}

	private function addToVialStack(sourceTile: InteractiveItemTile) {
		if (NetworkHandler == null
			|| !this.interactive
			|| sourceTile == null
			|| VialModel.getVialData(sourceTile.getItemId()).maxVialCount <= Global.gameSprite.map.player.getVialCount(sourceTile.getItemId()))
			return;

		NetworkHandler.invSwapVial(this.curPlayer, this.owner, sourceTile.tileId, sourceTile.itemSprite.itemId, this.curPlayer,
			VialModel.getVialSlot(sourceTile.getItemId()), ItemConstants.NO_ITEM);
		sourceTile.setItem(ItemConstants.NO_ITEM);
		sourceTile.updateUseability(this.curPlayer);
	}

	private function dropItem(itemTile: InteractiveItemTile) {
		var equipment: Array<Int32> = null;
		var equipCount = 0;
		var openIndex = 0;
		var isUntradable = ObjectLibrary.isUntradable(itemTile.itemSprite.itemId);
		if (this.owner?.map != null && (this.owner.objectId == this.curPlayer.objectId
			|| this.owner.ownerId == this.curPlayer.accountId) && !isUntradable) {
			var go = this.owner.map.getGameObject(Global.currentInteractiveTarget);
			if (go?.objClass == "Container") {
				equipment = go.equipment;
				equipCount = equipment.length;
				for (openIndex in 0...equipCount)
					if (equipment[openIndex] < 0)
						break;

				if (openIndex < equipCount)
					this.dropWithoutDestTile(itemTile, go, openIndex);
				else
					NetworkHandler.invDrop(this.owner, itemTile.tileId, itemTile.getItemId());
			} else
				NetworkHandler.invDrop(this.owner, itemTile.tileId, itemTile.getItemId());
		}
		itemTile.setItem(-1);
	}

	private function swapItemTiles(sourceTile: ItemTile, destTile: ItemTile) {
		if (NetworkHandler == null || !this.interactive || sourceTile == null || destTile == null)
			return false;

		NetworkHandler.invSwap(this.curPlayer, this.owner, sourceTile.tileId, sourceTile.itemSprite.itemId, destTile.ownerGrid.owner, destTile.tileId,
			destTile.itemSprite.itemId);
		var tempItemId: Int = sourceTile.getItemId();
		sourceTile.setItem(destTile.getItemId());
		destTile.setItem(tempItemId);
		sourceTile.updateUseability(this.curPlayer);
		destTile.updateUseability(this.curPlayer);
		return true;
	}

	private function dropWithoutDestTile(sourceTile: ItemTile, container: GameObject, containerIndex: Int) {
		if (NetworkHandler == null || !this.interactive || sourceTile == null || container == null)
			return;

		NetworkHandler.invSwap(this.curPlayer, this.owner, sourceTile.tileId, sourceTile.itemSprite.itemId, container, containerIndex, -1);
		sourceTile.setItem(ItemConstants.NO_ITEM);
	}

	private function equipOrUseContainer(tile: InteractiveItemTile) {
		var tileOwner: GameObject = tile.ownerGrid.owner;
		var player: Player = this.curPlayer;
		var nextAvailableSlotIndex: Int = this.curPlayer.nextAvailableInventorySlot();
		if (nextAvailableSlotIndex != -1)
			NetworkHandler.invSwap(player, this.owner, tile.tileId, tile.itemSprite.itemId, this.curPlayer, nextAvailableSlotIndex, ItemConstants.NO_ITEM);
		else
			NetworkHandler.useItem_new(tileOwner, tile.tileId);
	}

	private function equipOrUseInventory(tile: InteractiveItemTile) {
		var tileOwner: GameObject = tile.ownerGrid.owner;
		var player: Player = this.curPlayer;
		var matchingSlotIndex: Int = ObjectLibrary.getMatchingSlotIndex(tile.getItemId(), player);
		if (matchingSlotIndex != -1)
			NetworkHandler.invSwap(player, tileOwner, tile.tileId, tile.getItemId(), player, matchingSlotIndex, player.equipment[matchingSlotIndex]);
		else
			NetworkHandler.useItem_new(tileOwner, tile.tileId);
	}

	private function onTileMove(e: ItemTileEvent) {
		var targetTile: InteractiveItemTile = null;
		var slot = 0;
		var sourceTile: InteractiveItemTile = e.tile;
		var target = sourceTile.getDropTarget();
		if ((sourceTile.getItemId() == VialModel.HEALTH_VIAL_ID || sourceTile.getItemId() == VialModel.MAGIC_VIAL_ID)
			&& Std.isOfType(target, VialSlotView)) {
			this.onVialMove(e);
			return;
		} else if (Std.isOfType(target, InteractiveItemTile)) {
			targetTile = cast(target, InteractiveItemTile);
			if (sourceTile.canHoldItem(targetTile.getItemId()) && targetTile.canHoldItem(sourceTile.getItemId()))
				this.swapItemTiles(sourceTile, targetTile);
		} else if (Std.isOfType(target, Inventory)) {
			slot = sourceTile.ownerGrid.curPlayer.nextAvailableInventorySlot();
			if (slot != -1) {
				NetworkHandler.invSwap(this.curPlayer, sourceTile.ownerGrid.owner, sourceTile.tileId, sourceTile.itemSprite.itemId, this.curPlayer, slot,
					ItemConstants.NO_ITEM);
				sourceTile.setItem(ItemConstants.NO_ITEM);
				sourceTile.updateUseability(this.curPlayer);
			}
		} else if (target == null || Std.isOfType(target, Stage))
			this.dropItem(sourceTile);

		sourceTile.resetItemPosition();
	}

	private function onVialMove(e: ItemTileEvent) {
		var sourceTile: InteractiveItemTile = e.tile;
		var target = sourceTile.getDropTarget();
		if (target == null || Std.isOfType(target, Stage))
			this.dropItem(sourceTile);
		else if (Std.isOfType(target, VialSlotView))
			this.addToVialStack(sourceTile);

		sourceTile.resetItemPosition();
	}

	private static function onShiftClick(e: ItemTileEvent) {
		var tile: InteractiveItemTile = e.tile;
		if (Std.isOfType(tile.ownerGrid, InventoryGrid) || Std.isOfType(tile.ownerGrid, ContainerGrid))
			NetworkHandler.useItem_new(tile.ownerGrid.owner, tile.tileId);
	}

	private function onCtrlClick(e: ItemTileEvent) {
		var tile: InteractiveItemTile = e.tile;
		var slot = 0;
		if (Std.isOfType(tile.ownerGrid, InventoryGrid)) {
			slot = tile.ownerGrid.curPlayer.swapInventoryIndex(Global.tabStripModel.currentSelection);
			if (slot != -1) {
				NetworkHandler.invSwap(this.curPlayer, tile.ownerGrid.owner, tile.tileId, tile.itemSprite.itemId, this.curPlayer, slot, ItemConstants.NO_ITEM);
				tile.setItem(ItemConstants.NO_ITEM);
				tile.updateUseability(this.curPlayer);
			}
		}
	}

	private function onDoubleClick(e: ItemTileEvent) {
		var tile: InteractiveItemTile = e.tile;
		if (Std.isOfType(tile.ownerGrid, ContainerGrid))
			this.equipOrUseContainer(tile);
		else
			this.equipOrUseInventory(tile);
	}

	override public function draw() {
		this.setItems(this.owner.equipment, this.indexOffset);
	}

	public function setItems(items: Array<Int32>, itemIndexOffset: Int32 = 0) {}

	public function addToGrid(tile: ItemTile, numRows: Int, tileIndex: Int) {
		tile.drawBackground(this.disableBgDraw ? null : CutsByNum[numRows][tileIndex]);
		tile.addEventListener(MouseEvent.ROLL_OVER, this.onTileHover);
		tile.x = Std.int(tileIndex % rowLength) * (ItemTile.WIDTH + padding);
		tile.y = Std.int(tileIndex / rowLength) * (ItemTile.HEIGHT + padding);
		addChild(tile);
	}

	private function getCharacterType() {
		if (this.owner == this.curPlayer) {
			return InventoryOwnerTypes.CURRENT_PLAYER;
		}
		if (Std.isOfType(this.owner, Player)) {
			return InventoryOwnerTypes.OTHER_PLAYER;
		}
		return InventoryOwnerTypes.NPC;
	}

	private function onTileHover(e: MouseEvent) {
		if (stage == null)
			return;

		var tile: ItemTile = cast(e.currentTarget, ItemTile);
		if (tile.itemSprite.itemId > 0) {
			this.tooltip = new EquipmentToolTip(tile.itemSprite.itemId, this.curPlayer, this.owner != null ? this.owner.objectType : -1,
				this.getCharacterType(), tile.tileId);
			this.tooltip.attachToTarget(tile);
			stage.addChild(this.tooltip);
		}
	}
}
