package ui;

import constants.GeneralConstants;
import constants.InventoryOwnerTypes;
import game.GameSprite;
import network.data.TradeItem;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import ui.tooltip.EquipmentToolTip;
import ui.tooltip.ToolTip;

class TradeInventory extends Sprite {
	private static var NO_CUT: Array<Int> = [0, 0, 0, 0];
	private static var cuts: Array<Array<Int>> = [
		[1, 0, 0, 1], NO_CUT, NO_CUT, [0, 1, 1, 0], [1, 0, 0, 0], NO_CUT, NO_CUT, [0, 1, 0, 0], [0, 0, 0, 1], NO_CUT, NO_CUT, [0, 0, 1, 0]];
	public static inline var CLICKITEMS_MESSAGE = 0;
	public static inline var NOTENOUGHSPACE_MESSAGE: Int = 1;
	public static inline var TRADEACCEPTED_MESSAGE: Int = 2;
	public static inline var TRADEWAITING_MESSAGE: Int = 3;
	private static var tooltip: ToolTip = null;

	public var gs: GameSprite;
	public var playerName = "";
	public var slots: Array<TradeSlot>;

	private var nameText: SimpleText;
	private var taglineText: SimpleText;

	private static function removeTooltip() {
		if (tooltip != null) {
			if (tooltip.parent != null)
				tooltip.parent.removeChild(tooltip);
			tooltip = null;
		}
	}

	public function new(gs: GameSprite, playerName: String, items: Array<TradeItem>, canSelect: Bool) {
		super();

		var item: TradeItem = null;
		var slot: TradeSlot = null;
		this.slots = new Array<TradeSlot>();
		this.gs = gs;
		this.playerName = playerName;
		this.nameText = new SimpleText(20, 0xB3B3B3, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.x = 0;
		this.nameText.y = 0;
		this.nameText.text = this.playerName;
		this.nameText.updateMetrics();
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.nameText);
		this.taglineText = new SimpleText(12, 0xB3B3B3, false, 0, 0);
		this.taglineText.x = 0;
		this.taglineText.y = 22;
		this.taglineText.text = "";
		this.taglineText.updateMetrics();
		this.taglineText.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.taglineText);
		for (i in 0...GeneralConstants.NUM_EQUIPMENT_SLOTS + GeneralConstants.NUM_INVENTORY_SLOTS) {
			item = items[i];
			slot = new TradeSlot(item.item, item.tradeable, item.included, item.slotType, i - 3, cuts[i], i);
			slot.x = Math.floor(i % 4) * (Slot.WIDTH + 4);
			slot.y = Math.floor(i / 4) * (Slot.HEIGHT + 4) + 46;
			if (item.item != -1) {
				slot.addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
				slot.addEventListener(MouseEvent.ROLL_OUT, onRollOut);
			}
			if (canSelect && item.tradeable) {
				slot.addEventListener(MouseEvent.MOUSE_DOWN, this.onSlotClick);
			}
			this.slots.push(slot);
			addChild(slot);
		}
		addEventListener(Event.REMOVED_FROM_STAGE, onRemovedFromStage);
	}

	public function getOffer(): Array<Bool> {
		var offer: Array<Bool> = new Array<Bool>();
		for (i in 0...this.slots.length) {
			offer.push(this.slots[i].included);
		}
		return offer;
	}

	public function setOffer(offer: Array<Bool>) {
		for (i in 0...this.slots.length) {
			this.slots[i].setIncluded(offer[i]);
		}
	}

	public function isOffer(offer: Array<Bool>) {
		for (i in 0...this.slots.length) {
			if (offer[i] != this.slots[i].included) {
				return false;
			}
		}
		return true;
	}

	public function numIncluded() {
		var num = 0;
		for (i in 0...this.slots.length) {
			if (this.slots[i].included) {
				num++;
			}
		}
		return num;
	}

	public function numEmpty() {
		var num = 0;
		for (i in 4...this.slots.length) {
			if (this.slots[i].item == -1) {
				num++;
			}
		}
		return num;
	}

	public function setMessage(message: Int) {
		switch (message) {
			case CLICKITEMS_MESSAGE:
				this.nameText.setColor(0xB3B3B3);
				this.taglineText.setColor(0xB3B3B3);
				this.taglineText.text = "Click items you want to trade";
				this.taglineText.updateMetrics();
			case NOTENOUGHSPACE_MESSAGE:
				this.nameText.setColor(0xFF0000);
				this.taglineText.setColor(0xFF0000);
				this.taglineText.text = "Not enough space for trade!";
				this.taglineText.updateMetrics();
			case TRADEACCEPTED_MESSAGE:
				this.nameText.setColor(0x89AB5C);
				this.taglineText.setColor(0x89AB5C);
				this.taglineText.text = "Trade accepted!";
				this.taglineText.updateMetrics();
			case TRADEWAITING_MESSAGE:
				this.nameText.setColor(0xB3B3B3);
				this.taglineText.setColor(0xB3B3B3);
				this.taglineText.text = "Player is selecting items";
				this.taglineText.updateMetrics();
		}
	}

	private function setToolTip(toolTip: ToolTip) {
		removeTooltip();
		tooltip = toolTip;
		if (tooltip != null) {
			stage.addChild(tooltip);
		}
	}

	private static function onRemovedFromStage(event: Event) {
		removeTooltip();
	}

	private function onMouseOver(event: Event) {
		var tradeSlot: TradeSlot = cast(event.currentTarget, TradeSlot);
		this.setToolTip(new EquipmentToolTip(tradeSlot.item, this.gs.map.player, -1, InventoryOwnerTypes.OTHER_PLAYER, tradeSlot.id));
	}

	private static function onRollOut(event: Event) {
		removeTooltip();
	}

	private function onSlotClick(event: MouseEvent) {
		var slot: TradeSlot = cast(event.currentTarget, TradeSlot);
		slot.setIncluded(!slot.included);
		dispatchEvent(new Event(Event.CHANGE));
	}
}
