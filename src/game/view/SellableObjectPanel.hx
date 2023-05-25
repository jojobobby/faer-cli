package game.view;

import network.NetworkHandler;
import game.GameSprite;
import objects.Player;
import objects.SellableObject;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import ui.BuyButton;
import ui.panels.Panel;
import ui.SimpleText;
import ui.tooltip.ToolTip;
import util.GuildUtil;

class SellableObjectPanel extends Panel {
	private static inline var BUTTON_OFFSET: Int = 17;

	private var owner: SellableObject;
	private var nameText: SimpleText;
	private var buyButton: BuyButton;
	private var rankReqText: Sprite = null;
	private var guildRankReqText: SimpleText = null;
	private var toolTip: ToolTip;
	private var bitmap: Bitmap;

	private static function createRankReqText(rankReq: Int) {
		var requiredText: SimpleText;
		var rankReqText: Sprite = new Sprite();
		requiredText = new SimpleText(16, 0xFFFFFF, false, 0, 0);
		requiredText.setBold(true);
		requiredText.text = "Rank Required:";
		requiredText.updateMetrics();
		requiredText.filters = [new DropShadowFilter(0, 0, 0)];
		rankReqText.addChild(requiredText);
		return rankReqText;
	}

	private static function createGuildRankReqText(guildRankReq: Int): SimpleText {
		var requiredText: SimpleText;
		requiredText = new SimpleText(16, 0xFF0000, false, 0, 0);
		requiredText.setBold(true);
		requiredText.text = GuildUtil.rankToString(guildRankReq) + " Rank Required";
		requiredText.useTextDimensions();
		requiredText.filters = [new DropShadowFilter(0, 0, 0)];
		return requiredText;
	}

	public function new(gs: GameSprite, owner: SellableObject) {
		this.bitmap = new Bitmap();
		super(gs);
		this.createNameText();
		this.createBuyButton();
		this.setOwner(owner);
		this.createIcon();
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	override public function draw() {
		var player: Player = gs.map.player;
		this.nameText.y = this.nameText.height > 30 ? 0 : 10;
		if (player.guildRank < this.owner.guildRankReq) {
			this.removeButtons();
			if (this.guildRankReqText == null || !contains(this.guildRankReqText)) {
				this.updateGuildRankRequiredText();
			}
		} else {
			this.buyButton.setPrice(this.owner.price, owner.currency);
			this.buyButton.x = Panel.WIDTH / 2 - this.buyButton.width / 2;
			this.buyButton.y = Panel.HEIGHT - this.buyButton.height / 2 - BUTTON_OFFSET;
			this.addButtons();
			if (this.rankReqText != null && contains(this.rankReqText)) {
				removeChild(this.rankReqText);
			}
		}
	}

	public function setOwner(_owner: SellableObject) {
		if (this.owner == _owner) {
			return;
		}
		this.owner = _owner;
		var title: String = this.owner.soldObjectName();
		this.buyButton.setPrice(this.owner.price, _owner.currency);
		this.nameText.htmlText = "<p align=\"center\">" + title + "</p>";
	}

	private function createBuyButton() {
		this.buyButton = new BuyButton("", 16, 0, 0);
		this.buyButton.addEventListener(MouseEvent.CLICK, this.onBuyButtonClick);
		addChild(this.buyButton);
	}

	private function createIcon() {
		this.bitmap.x = 2;
		this.bitmap.y = -2;
		this.bitmap.bitmapData = this.owner.getIcon();
		addChild(this.bitmap);
	}

	private function createNameText() {
		this.nameText = new SimpleText(16, 0xFFFFFF, false, Panel.WIDTH - 44, 0);
		this.nameText.setBold(true);
		this.nameText.htmlText = "<p align=\"center\">Unknown</p>";
		this.nameText.wordWrap = true;
		this.nameText.multiline = true;
		this.nameText.autoSize = TextFieldAutoSize.CENTER;
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		this.nameText.x = 44;
		addChild(this.nameText);
	}

	private function resetTooltip() {
		if (this.toolTip != null) {
			if (this.toolTip.parent != null) {
				this.toolTip.parent.removeChild(this.toolTip);
			}
			this.toolTip = null;
		}
	}

	private function updateRankRequiredText(rankReq: Int) {
		this.rankReqText = createRankReqText(rankReq);
		this.rankReqText.x = Panel.WIDTH / 2 - this.rankReqText.width / 2;
		this.rankReqText.y = Panel.HEIGHT - this.rankReqText.height / 2 - 20;
		addChild(this.rankReqText);
	}

	private function updateGuildRankRequiredText() {
		this.guildRankReqText = createGuildRankReqText(this.owner.guildRankReq);
		this.guildRankReqText.x = (Panel.WIDTH - this.guildRankReqText.width) * 0.5;
		this.guildRankReqText.y = Panel.HEIGHT - this.guildRankReqText.height / 2 - 20;
		addChild(this.guildRankReqText);
	}

	private function addButtons() {
		if (!contains(this.buyButton)) {
			addChild(this.buyButton);
		}
	}

	private function removeButtons() {
		if (contains(this.buyButton)) {
			removeChild(this.buyButton);
		}
	}

	private function onAddedToStage(_: Event) {
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
	}

	private function onRemovedFromStage(_: Event) {
		removeEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		removeEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		this.resetTooltip();
	}

	private function onMouseOver(_: MouseEvent) {
		this.resetTooltip();
		stage.addChild(this.toolTip = this.owner.getTooltip());
	}

	private function onMouseOut(_: MouseEvent) {
		this.resetTooltip();
	}

	private function onBuyButtonClick(_: MouseEvent) {
		NetworkHandler.buy(this.owner.objectId);
	}
}
