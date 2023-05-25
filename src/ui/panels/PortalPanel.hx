package ui.panels;
import network.NetworkHandler;
import game.GameSprite;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import ui.TextBox;
import util.Settings;

class PortalPanel extends Panel {
	public var ownerObjId = 0;

	public function new(gs: GameSprite, objId: Int) {
		super(gs);
		this.ownerObjId = objId;
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	private function enterPortal() {
		NetworkHandler.usePortal(this.ownerObjId);
	}

	private function onAddedToStage(event: Event) {
		stage.addEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
	}

	private function onRemovedFromStage(event: Event) {
		stage.removeEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
	}

	private function onKeyDown(event: KeyboardEvent) {
		if (event.keyCode == Settings.interact && !TextBox.isInputtingText)
			this.enterPortal();
	}
}
