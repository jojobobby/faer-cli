package ui.dialogs;

import openfl.display.DisplayObjectContainer;
import openfl.display.Sprite;
import openfl.events.Event;

class DialogsView extends Sprite {
	private var container: DisplayObjectContainer;
	private var current: Sprite;

	public function new() {
		super();

		addChild(this.container = new Sprite());
	}

	public function openDialog(dialog: Sprite) {
		this.removeCurrentDialog();
		this.current = dialog;
		dialog.addEventListener(Event.REMOVED, this.onRemoved);
		this.container.addChild(dialog);
	}

	public function closeDialogs() {
		this.stage.focus = null;
		this.removeCurrentDialog();
	}

	private function removeCurrentDialog() {
		if (this.current != null && this.container.contains(this.current)) {
			this.current.removeEventListener(Event.REMOVED, this.onRemoved);
			this.container.removeChild(this.current);
		}
	}

	private function onRemoved(event: Event) {
		var target: Sprite = cast(event.target, Sprite);
		if (this.current == target)
			this.current = null;
	}
}
