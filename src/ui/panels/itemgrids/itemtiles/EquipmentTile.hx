package ui.panels.itemgrids.itemtiles;

import constants.ItemConstants;
import objects.ObjectLibrary;
import objects.Player;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.filters.ColorMatrixFilter;
import ui.panels.itemgrids.ItemGrid;
import util.AssetLibrary;
import util.Utils;

class EquipmentTile extends InteractiveItemTile {
	private static var greyColorFilter = new ColorMatrixFilter(ColorUtils.singleColorFilterMatrix(0x363636));

	public var backgroundDetail: Bitmap;
	public var slotType = 0;

	private var minManaUsage = 0;
	private var minHealthUsage = 0;

	public function new(id: Int, parentGrid: ItemGrid, isInteractive: Bool) {
		super(id, parentGrid, isInteractive);
	}

	override public function canHoldItem(itemType: Int) {
		return itemType <= 0 || ObjectLibrary.slotsMatching(this.slotType, ObjectLibrary.getSlotTypeFromType(itemType));
	}

	override public function setItem(itemId: Int) {
		var itemChanged: Bool = super.setItem(itemId);
		if (itemChanged) {
			this.backgroundDetail.visible = itemSprite.itemId <= 0;
			this.updateMinMana();
		}

		return itemChanged;
	}

	override public function beginDragCallback() {
		this.backgroundDetail.visible = true;
	}

	override public function endDragCallback() {
		this.backgroundDetail.visible = itemSprite.itemId <= 0;
	}

	public function setType(slotType: Int) {
		var sheetId: Int = 16; // empty, todo
		switch (slotType) {
			case ItemConstants.ACCESSORY_TYPE:
				sheetId = 241;

			case ItemConstants.ANY_WEAPON_TYPE:
				sheetId = 48;
			case ItemConstants.SWORD_TYPE:
				sheetId = 1;
			case ItemConstants.BOW_TYPE:
				sheetId = 65;
			case ItemConstants.STAFF_TYPE:
				sheetId = 81;
			case ItemConstants.SCEPTER_TYPE:
				sheetId = 161;

			case ItemConstants.ANY_ARMOR_TYPE:
				sheetId = 49;
			case ItemConstants.VEST_TYPE:
				sheetId = 33;
			case ItemConstants.HIDE_TYPE:
				sheetId = 17;
			case ItemConstants.ROBE_TYPE:
				sheetId = 97;

			case ItemConstants.ANY_ABILITY_TYPE:
				sheetId = 50;
			case ItemConstants.FLASK_TYPE:
				sheetId = 113;
			case ItemConstants.BLOODSTONE_TYPE:
				sheetId = 129;
			case ItemConstants.TOTEM_TYPE:
				sheetId = 145;
			case ItemConstants.HELM_TYPE:
				sheetId = 177;
			case ItemConstants.BULWARK_TYPE:
				sheetId = 193;
			case ItemConstants.CLOCK_TYPE:
				sheetId = 209;
			case ItemConstants.CAGE_TYPE:
				sheetId = 225;
		}

		var bd: BitmapData = AssetLibrary.getImageFromSet("tieredItems", sheetId);
		if (bd != null) {
			this.backgroundDetail = new Bitmap(bd);
			this.backgroundDetail.scaleX = 4;
			this.backgroundDetail.scaleY = 4;
			this.backgroundDetail.x = (40 - this.backgroundDetail.width) / 2;
			this.backgroundDetail.y = (40 - this.backgroundDetail.height) / 2;
			this.backgroundDetail.filters = [greyColorFilter];
			addChildAt(this.backgroundDetail, 0);
		}

		this.slotType = slotType;
	}

	public function updateDim(player: Player) {
		itemSprite.setDim(this.minManaUsage > 0 && player != null && player.mp < this.minManaUsage || this.minHealthUsage > 0 && player != null
			&& player.hp < this.minHealthUsage);
	}

	private function updateMinMana() {
		var itemDataXML: Xml = null;
		if (itemSprite.itemId > 0) {
			itemDataXML = ObjectLibrary.xmlLibrary.get(itemSprite.itemId);
			if (itemDataXML != null) {
				this.minManaUsage = itemDataXML.elementsNamed("MpCost")
					.hasNext() ? Std.parseInt(itemDataXML.elementsNamed("MpCost").next().firstChild().nodeValue) : 0;
				this.minHealthUsage = itemDataXML.elementsNamed("HpCost")
					.hasNext() ? Std.parseInt(itemDataXML.elementsNamed("HpCost").next().firstChild().nodeValue) : 0;
				return;
			}
		}

		this.minManaUsage = 0;
		this.minHealthUsage = 0;
	}
}
