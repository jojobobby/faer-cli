package characters;

import openfl.display.Sprite;
import openfl.events.Event;
import ui.dialogs.Dialog;

using StringTools;

class ConfirmDeleteCharacterDialog extends Sprite {
	private static inline var TEXT_TEMPLATE: String = "Are you really sure you want to delete {NAME} the {DISPLAYID}?";
	private static inline var CANCEL_EVENT: String = Dialog.BUTTON1_EVENT;
	private static inline var DELETE_EVENT: String = Dialog.BUTTON2_EVENT;

	public function new() {
		super();
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);

		var character = Global.charModel.getSelected();
		this.setText(character.name(), character.displayId());
	}

	public function setText(name: String, displayId: String) {
		var text = TEXT_TEMPLATE.replace("{NAME}", name).replace("{DISPLAYID}", displayId);
		var dialog = new Dialog(text, "Verify Deletion", "Cancel", "Delete");
		dialog.addEventListener(CANCEL_EVENT, this.onCancel);
		dialog.addEventListener(DELETE_EVENT, this.onDelete);
		addChild(dialog);
	}

	private function onCancel(_: Event) {
		Global.layers.dialogs.closeDialogs();
	}

	private function onDelete(_: Event) {
		Global.deleteChar();
	}
}
