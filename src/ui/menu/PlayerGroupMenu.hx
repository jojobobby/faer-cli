package ui.menu;

import map.Map;
import objects.Player;
import openfl.events.Event;
import openfl.events.MouseEvent;
import ui.GameObjectListItem;
import ui.LineBreakDesign;
import util.Settings;

class PlayerGroupMenu extends Menu {
	public var map: Map;
	public var players: Array<Player>;
	public var teleportOption: MenuOption;
	public var lineBreakDesign: LineBreakDesign;

	public function new(map: Map, players: Array<Player>) {
		var player: Player = null;
		var playerPlanel: GameObjectListItem = null;
		super(0x363636, 0xFFFFFF);
		this.map = map;
		if (players.length > 0)
			this.players = players.copy();
		else this.players.resize(0);
		var yVal: Int = 4;
		if (this.map.allowPlayerTeleport) {
			this.teleportOption = new TeleportMenuOption(this.map.player);
			this.teleportOption.x = 8;
			this.teleportOption.y = 8;
			this.teleportOption.addEventListener(MouseEvent.CLICK, this.onTeleport);
			addChild(this.teleportOption);
			this.lineBreakDesign = new LineBreakDesign(Std.int(width - 24), 1842204);
			this.lineBreakDesign.x = 6;
			this.lineBreakDesign.y = 40;
			addChild(this.lineBreakDesign);
			yVal = 52;
		}
		for (player in this.players) {
			playerPlanel = new GameObjectListItem(0xB3B3B3, true, player);
			playerPlanel.x = 0;
			playerPlanel.y = yVal;
			addChild(playerPlanel);
			yVal = yVal + 32;
		}
	}

	private function onTeleport(event: Event) {
		var myPlayer: Player = this.map.player;
		var targetPlayer: Player = this.players[0];
		if (targetPlayer != null)
			myPlayer.teleportTo(targetPlayer);
		else
			Global.gameSprite.textBox.addText("No players are eligible for teleporting", 0xFF0000);

		remove();
	}
}
