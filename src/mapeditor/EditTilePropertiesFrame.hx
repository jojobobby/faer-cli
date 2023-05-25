package mapeditor;

import openfl.events.Event;
import ui.Frame;
import ui.TextInputField;
import openfl.events.MouseEvent;

class EditTilePropertiesFrame extends Frame {
	public var objectName: TextInputField;

	public function new(oldName: String) {
		super("Tile properties", "Cancel", "Save", 288);
		this.objectName = new TextInputField("Object Name", false, "");
		if (oldName != null)
			this.objectName.inputText.text = oldName;

		addTextInputField(this.objectName);
		leftButton.addEventListener(MouseEvent.CLICK, this.onCancel);
		rightButton.addEventListener(MouseEvent.CLICK, this.onDone);
	}

	private function onCancel(event: MouseEvent) {
		dispatchEvent(new Event(Event.CANCEL));
	}

	private function onDone(event: MouseEvent) {
		dispatchEvent(new Event(Event.COMPLETE));
	}
}
