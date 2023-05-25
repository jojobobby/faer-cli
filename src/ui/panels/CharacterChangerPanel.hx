package ui.panels;

import game.GameSprite;
import openfl.events.MouseEvent;

class CharacterChangerPanel extends ButtonPanel {
	public function new(gs: GameSprite) {
		super(gs, "Change Characters", "Change");
	}

	override public function onButtonClick(event: MouseEvent) {
		GameSprite.close();
	}
}
