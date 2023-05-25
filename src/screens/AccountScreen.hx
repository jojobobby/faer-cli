package screens;

import account.view.AccountInfoView;
import openfl.display.DisplayObject;
import openfl.display.Sprite;
import openfl.events.Event;
import ui.GuildText;

class AccountScreen extends Sprite {
	private var guildLayer: Sprite;
	private var accountInfoLayer: Sprite;
	private var guildName = "";
	private var guildRank = 0;
	private var guildText: GuildText;
	private var accountInfo: AccountInfoView;

	public function new() {
		super();

		this.makeLayers();
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);

		this.setGuild(Global.playerModel.getGuildName(), Global.playerModel.getGuildRank());
		this.setAccountInfo(new AccountInfoView());
	}

	public function setGuild(guildName: String, guildRank: Int) {
		this.guildName = guildName;
		this.guildRank = guildRank;
		this.makeGuildText();
	}

	public function setAccountInfo(accountInfo: AccountInfoView) {
		var display: DisplayObject;
		this.accountInfo = accountInfo;
		display = cast(accountInfo, DisplayObject);
		display.x = stage.stageWidth - 10;
		display.y = 2;
		this.accountInfoLayer.addChild(display);
	}

	private function makeLayers() {
		addChild(this.guildLayer = new Sprite());
		addChild(this.accountInfoLayer = new Sprite());
	}

	private function makeGuildText() {
		this.guildText = new GuildText(this.guildName, this.guildRank);
		this.guildText.x = 92;
		this.guildText.y = 6;
		this.guildLayer.addChild(this.guildText);
	}
}
