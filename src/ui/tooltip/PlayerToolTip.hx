package ui.tooltip;

import objects.Player;
import openfl.filters.DropShadowFilter;
import ui.GameObjectListItem;
import ui.GuildText;
import ui.panels.itemgrids.EquippedGrid;
import ui.SimpleText;
import ui.StatusBar;

class PlayerToolTip extends ToolTip {
	public var player: Player;

	private var playerPanel: GameObjectListItem;
	private var guildText: GuildText;
	private var hpBar: StatusBar;
	private var mpBar: StatusBar;
	private var clickMessage: SimpleText;
	private var eGrid: EquippedGrid;

	public function new(player: Player) {
		var yOffset = 0;
		super(0x363636, 0.5, 0xFFFFFF, 1);
		this.player = player;
		this.playerPanel = new GameObjectListItem(0xB3B3B3, true, this.player);
		addChild(this.playerPanel);
		yOffset = 34;
		if ((player?.guildName ?? "") != "") {
			this.guildText = new GuildText(this.player.guildName, this.player.guildRank, 136);
			this.guildText.x = 6;
			this.guildText.y = yOffset - 2;
			addChild(this.guildText);
			yOffset = yOffset + 30;
		}

		if (player.maxMP < 0) {
			this.hpBar = new StatusBar(176, 40, 0xE03434, 0x545454);
			this.hpBar.x = 6;
			this.hpBar.y = yOffset;
			addChild(this.hpBar);
			yOffset += 48;
		} else {
			this.hpBar = new StatusBar(176, 16, 0xE03434, 0x545454);
			this.hpBar.x = 6;
			this.hpBar.y = yOffset;
			addChild(this.hpBar);
			yOffset += 24;
			this.mpBar = new StatusBar(176, 16, 0x6084E0, 0x545454);
			this.mpBar.x = 6;
			this.mpBar.y = yOffset;
			addChild(this.mpBar);
			yOffset += 24;
		}

		this.eGrid = new EquippedGrid(null, this.player.slotTypes, this.player);
		this.eGrid.x = 8;
		this.eGrid.y = yOffset;
		addChild(this.eGrid);
		yOffset += 52;
		this.clickMessage = new SimpleText(12, 0xB3B3B3, false, 0, 0);
		this.clickMessage.text = "(Click to open menu)";
		this.clickMessage.updateMetrics();
		this.clickMessage.filters = [new DropShadowFilter(0, 0, 0)];
		this.clickMessage.x = width / 2 - this.clickMessage.width / 2;
		this.clickMessage.y = yOffset;
		addChild(this.clickMessage);
	}

	override public function draw() {
		this.hpBar.draw(this.player.hp, this.player.maxHP, this.player.maxHPBoost, this.player.maxHPMax);
		this.mpBar?.draw(this.player.mp, this.player.maxMP, this.player.maxMPBoost, this.player.maxMPMax);
		this.eGrid.setItems(this.player.equipment);
		super.draw();
	}
}
