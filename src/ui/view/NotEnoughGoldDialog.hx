package ui.view;

import openfl.events.Event;
import openfl.events.MouseEvent;
import ui.dialogs.Dialog;

class NotEnoughGoldDialog extends Dialog {
	private static inline var TEXT: String = "You do not have enough Gold for this item.";
	private static inline var TITLE: String = "Not Enough Gold";
	private static inline var CANCEL: String = "Cancel";

	public function new(message: String = "") {
		var text: String = message == "" ? TEXT : message;
		super(text, TITLE, CANCEL, null);

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Dialog.BUTTON1_EVENT, onCancel);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		removeEventListener(Dialog.BUTTON1_EVENT, onCancel);
	}

	public function onCancel(_: MouseEvent) {
		Global.layers.dialogs.closeDialogs();
	}
}
