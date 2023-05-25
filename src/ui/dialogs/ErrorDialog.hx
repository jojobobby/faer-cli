package ui.dialogs;

import openfl.events.Event;
import openfl.events.MouseEvent;
import screens.CharacterSelectionScreen;

class ErrorDialog extends Dialog {
	public function new(errorText: String) {
		super("An error has occurred:\n" + errorText, "Error", "Ok", null);
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Dialog.BUTTON1_EVENT, onClose);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		addEventListener(Event.COMPLETE, onComplete);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		removeEventListener(Event.COMPLETE, onComplete);
		removeEventListener(Dialog.BUTTON1_EVENT, onClose);
	}

	public function onClose(_: MouseEvent) {
		Global.layers.dialogs.closeDialogs();
	}

	private static function onComplete(event: Event) {
		Global.invalidate();
		Global.setScreenValid(new CharacterSelectionScreen());
	}
}
