package mapeditor;

import haxe.ds.IntMap;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.KeyboardEvent;

class CommandMenu extends Sprite {
	private var keyCodeDict: IntMap<CommandMenuItem>;
	private var yOffset = 0;
	private var selected: CommandMenuItem = null;

	public function new() {
		super();
		this.keyCodeDict = new IntMap<CommandMenuItem>();
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function getCommand() {
		return this.selected.command;
	}

	public function setCommand(command: Int) {
		for (c in 0...numChildren) {
			var item = cast(getChildAt(c), CommandMenuItem);
			if (item != null)
				if (item.command == command) {
					this.setSelected(item);
					break;
				}
		}
	}

	private function setSelected(item: CommandMenuItem) {
		if (this.selected != null)
			this.selected.setSelected(false);

		this.selected = item;
		this.selected.setSelected(true);
	}

	private function onAddedToStage(_: Event) {
		stage.addEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
	}

	private function onRemovedFromStage(_: Event) {
		stage.removeEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
	}

	private function onKeyDown(event: KeyboardEvent) {
		if (stage.focus != null)
			return;

		var item = this.keyCodeDict.get(event.keyCode);
		if (item == null)
			return;

		item.callback(item);
	}

	private function addCommandMenuItem(label: String, keyCode: Int, callback: CommandMenuItem->Void, command: Int) {
		var commandMenuItem = new CommandMenuItem(label, callback, command);
		commandMenuItem.y = this.yOffset;
		addChild(commandMenuItem);
		this.keyCodeDict.set(keyCode, commandMenuItem);
		if (this.selected == null)
			this.setSelected(commandMenuItem);

		this.yOffset += 30;
	}

	private function addBreak() {
		this.yOffset += 30;
	}
}
