package ui.tooltip;

import objects.Player;
import openfl.filters.DropShadowFilter;
import ui.GameObjectListItem;
import ui.SimpleText;

class PlayerGroupToolTip extends ToolTip {
	public var players: Array<Player> = null;

	private var playerPanels: Array<GameObjectListItem>;
	private var clickMessage: SimpleText;

	public function new(players: Array<Player>, followMouse: Bool = true) {
		this.playerPanels = new Array<GameObjectListItem>();
		super(0x363636, 0.5, 0xFFFFFF, 1, followMouse);
		this.clickMessage = new SimpleText(12, 0xB3B3B3, false, 0, 0);
		this.clickMessage.text = "(Click to open menu)";
		this.clickMessage.updateMetrics();
		this.clickMessage.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(this.clickMessage);
		this.setPlayers(players);
		if (!followMouse)
			filters = [];
	}

	public function setPlayers(players: Array<Player>) {
		var player: Player = null;
		var playerPlanel: GameObjectListItem = null;
		this.clear();
		this.players = players.slice(0);
		if (this.players == null || this.players.length == 0)
			return;

		var yVal = 0;
		for (player in players) {
			playerPlanel = new GameObjectListItem(0xB3B3B3, true, player);
			playerPlanel.x = 0;
			playerPlanel.y = yVal;
			addChild(playerPlanel);
			this.playerPanels.push(playerPlanel);
			yVal = yVal + 32;
		}

		this.clickMessage.x = width / 2 - this.clickMessage.width / 2;
		this.clickMessage.y = yVal;
		draw();
	}

	private function clear() {
		var playerPanel: GameObjectListItem = null;
		graphics.clear();
		for (playerPanel in this.playerPanels)
			removeChild(playerPanel);

		this.playerPanels.splice(0, this.playerPanels.length);
	}
}
