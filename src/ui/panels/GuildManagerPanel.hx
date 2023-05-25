package ui.panels;

import game.GameSprite;
import openfl.events.MouseEvent;
import ui.guild.GuildChronicleScreen;

class GuildManagerPanel extends ButtonPanel {
	public function new(gs: GameSprite) {
		super(gs, "Guild Chronicle", "View");
	}

	override public function onButtonClick(event: MouseEvent) {
		gs.inputHandler.clearInput();
		gs.addChild(new GuildChronicleScreen(gs));
	}
}
