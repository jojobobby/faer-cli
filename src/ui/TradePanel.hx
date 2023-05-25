package ui;

import game.GameSprite;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;

class TradePanel extends Sprite {
	public static inline var WIDTH: Int = 200;
	public static inline var HEIGHT: Int = 400;

	public var gs: GameSprite;

	private var myInv: TradeInventory;
	private var yourInv: TradeInventory;
	private var cancelButton: TextButton;
	private var tradeButton: TradeButton;

	public function new(gs: GameSprite, tradeStart: TradeStart) {
		super();

		this.gs = gs;
		var playerName: String = this.gs.map.player.name;
		this.myInv = new TradeInventory(gs, playerName, tradeStart.myItems, true);
		this.myInv.x = 14;
		this.myInv.y = 0;
		this.myInv.addEventListener(Event.CHANGE, this.onMyInvChange);
		addChild(this.myInv);
		this.yourInv = new TradeInventory(gs, tradeStart.yourName, tradeStart.yourItems, false);
		this.yourInv.x = 14;
		this.yourInv.y = 174;
		addChild(this.yourInv);
		this.cancelButton = new TextButton(16, "Cancel", 80);
		this.cancelButton.addEventListener(MouseEvent.CLICK, this.onCancelClick);
		this.cancelButton.x = WIDTH / 4 - this.cancelButton.width / 2;
		this.cancelButton.y = HEIGHT - this.cancelButton.height - 10;
		addChild(this.cancelButton);
		this.tradeButton = new TradeButton(16, 80);
		this.tradeButton.addEventListener(MouseEvent.CLICK, this.onTradeClick);
		this.tradeButton.x = 3 * WIDTH / 4 - this.tradeButton.width / 2;
		this.tradeButton.y = this.cancelButton.y;
		addChild(this.tradeButton);
		this.checkTrade();
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function setYourOffer(offer: Array<Bool>) {
		this.yourInv.setOffer(offer);
		this.checkTrade();
	}

	public function youAccepted(myOffer: Array<Bool>, yourOffer: Array<Bool>) {
		if (this.myInv.isOffer(myOffer) && this.yourInv.isOffer(yourOffer))
			this.yourInv.setMessage(TradeInventory.TRADEACCEPTED_MESSAGE);
	}

	public function checkTrade() {
		var myTrading: Int = this.myInv.numIncluded();
		var myEmpty: Int = this.myInv.numEmpty();
		var yourTrading: Int = this.yourInv.numIncluded();
		var yourEmpty: Int = this.yourInv.numEmpty();
		var valid = true;
		if (yourTrading - myTrading - myEmpty > 0) {
			this.myInv.setMessage(TradeInventory.NOTENOUGHSPACE_MESSAGE);
			valid = false;
		} else
			this.myInv.setMessage(TradeInventory.CLICKITEMS_MESSAGE);

		if (myTrading - yourTrading - yourEmpty > 0) {
			this.yourInv.setMessage(TradeInventory.NOTENOUGHSPACE_MESSAGE);
			valid = false;
		} else
			this.yourInv.setMessage(TradeInventory.TRADEWAITING_MESSAGE);

		if (valid)
			this.tradeButton.reset();
		else
			this.tradeButton.disable();
	}

	private function onAddedToStage(event: Event) {
		stage.addEventListener(Event.ACTIVATE, this.onActivate);
	}

	private function onRemovedFromStage(event: Event) {
		stage.removeEventListener(Event.ACTIVATE, this.onActivate);
	}

	private function onActivate(event: Event) {
		this.tradeButton.reset();
	}

	private function onMyInvChange(event: Event) {
		this.gs.server.changeTrade(this.myInv.getOffer());
		this.checkTrade();
	}

	private function onCancelClick(event: MouseEvent) {
		this.gs.server.cancelTrade();
		dispatchEvent(new Event(Event.CANCEL));
	}

	private function onTradeClick(event: MouseEvent) {
		this.gs.server.acceptTrade(this.myInv.getOffer(), this.yourInv.getOffer());
		this.myInv.setMessage(TradeInventory.TRADEACCEPTED_MESSAGE);
	}
}
