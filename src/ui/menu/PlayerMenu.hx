package ui.menu;

import game.GameSprite;
import objects.Player;
import openfl.events.Event;
import openfl.events.MouseEvent;
import ui.GameObjectListItem;
import util.AssetLibrary;
import util.GuildUtil;

class PlayerMenu extends Menu {
	public var gs: GameSprite;
	public var playerName = "";
	public var player: Player;
	public var playerPanel: GameObjectListItem;

	public function new(gs: GameSprite, player: Player) {
		var option: MenuOption = null;
		super(0x363636, 0xFFFFFF);
		this.gs = gs;
		this.playerName = player.name;
		this.player = player;
		this.playerPanel = new GameObjectListItem(0xB3B3B3, true, this.player);
		addChild(this.playerPanel);
		if (this.gs.map.allowPlayerTeleport && this.player.isTeleportEligible(this.player)) {
			option = new TeleportMenuOption(this.gs.map.player);
			option.addEventListener(MouseEvent.CLICK, this.onTeleport);
			addOption(option);
		}

		if (this.gs.map.player.guildRank >= GuildUtil.OFFICER && (player.guildName == null || player.guildName.length == 0)) {
			option = new MenuOption(AssetLibrary.getImageFromSet("misc16", 30), 0xFFFFFF, "Invite");
			option.addEventListener(MouseEvent.CLICK, this.onInvite);
			addOption(option);
		}

		if (!this.player.locked) {
			option = new MenuOption(AssetLibrary.getImageFromSet("misc16", 28), 0xFFFFFF, "Lock");
			option.addEventListener(MouseEvent.CLICK, this.onLock);
			addOption(option);
		} else {
			option = new MenuOption(AssetLibrary.getImageFromSet("misc16", 29), 0xFFFFFF, "Unlock");
			option.addEventListener(MouseEvent.CLICK, this.onUnlock);
			addOption(option);
		}

		option = new MenuOption(AssetLibrary.getImageFromSet("misc16", 16), 0xFFFFFF, "Trade");
		option.addEventListener(MouseEvent.CLICK, this.onTrade);
		addOption(option);
		if (!this.player.ignored) {
			option = new MenuOption(AssetLibrary.getImageFromSet("misc16", 17), 0xFFFFFF, "Ignore");
			option.addEventListener(MouseEvent.CLICK, this.onIgnore);
			addOption(option);
		} else {
			option = new MenuOption(AssetLibrary.getImageFromSet("misc16", 18), 0xFFFFFF, "Unignore");
			option.addEventListener(MouseEvent.CLICK, this.onUnignore);
			addOption(option);
		}
	}

	private function onTeleport(event: Event) {
		this.gs.map.player.teleportTo(this.player);
		remove();
	}

	private function onInvite(event: Event) {
		this.gs.server.guildInvite(this.playerName);
		remove();
	}

	private function onLock(event: Event) {
		this.gs.map.party.lockPlayer(this.player);
		remove();
	}

	private function onUnlock(event: Event) {
		this.gs.map.party.unlockPlayer(this.player);
		remove();
	}

	private function onTrade(event: Event) {
		this.gs.server.requestTrade(this.playerName);
		remove();
	}

	private function onIgnore(event: Event) {
		this.gs.map.party.ignorePlayer(this.player);
		remove();
	}

	private function onUnignore(event: Event) {
		this.gs.map.party.unignorePlayer(this.player);
		remove();
	}
}
