package screens.charrects;

import util.Settings;
import appengine.SavedCharacter;
import characters.ConfirmDeleteCharacterDialog;
import classes.model.CharacterClass;
import game.model.GameInitData;
import openfl.display.DisplayObject;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import screens.events.DeleteCharacterEvent;
import ui.DeleteXGraphic;
import ui.SimpleText;
import ui.tooltip.MyPlayerToolTip;
import ui.tooltip.ToolTip;

class CurrentCharacterRect extends CharacterRect {
	private static var toolTip: ToolTip = null;

	public var charName = "";
	public var savedChar: SavedCharacter;

	private var charType: CharacterClass;
	private var classNameText: SimpleText;
	private var deleteButton: Sprite;
	private var icon: DisplayObject;

	private static function removeToolTip() {
		if (toolTip != null) {
			if (toolTip.parent != null && toolTip.parent.contains(toolTip))
				toolTip.parent.removeChild(toolTip);
			toolTip = null;
		}
	}

	public function new(charName: String, charType: CharacterClass, savedChar: SavedCharacter) {
		super(0x5C5C5C, 0x7F7F7F);
		this.charName = charName;
		this.charType = charType;
		this.savedChar = savedChar;
		makeContainer();

		this.classNameText = new SimpleText(18, 0xFFFFFF, false, 0, 0);
		this.classNameText.setBold(true);
		this.classNameText.text = "T" + this.savedChar.tier() + " " + this.charType.name;
		this.classNameText.updateMetrics();
		this.classNameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.classNameText.x = (CharacterRect.WIDTH - this.classNameText.width) / 2;
		this.classNameText.y = (CharacterRect.HEIGHT - this.classNameText.height) / 2 - 3;
		this.selectContainer.addChild(this.classNameText);
		this.selectContainer.addEventListener(MouseEvent.CLICK, this.onSelected);

		this.deleteButton = new DeleteXGraphic();
		this.deleteButton.addEventListener(MouseEvent.MOUSE_DOWN, this.onDeleteDown);
		this.deleteButton.x = CharacterRect.WIDTH - 40;
		this.deleteButton.y = (CharacterRect.HEIGHT - this.deleteButton.height) * 0.5;
		addChild(this.deleteButton);
		this.deleteButton.addEventListener(MouseEvent.CLICK, this.onDeleteCharacter);

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.selectContainer.removeEventListener(MouseEvent.CLICK, this.onSelected);
		this.deleteButton.removeEventListener(MouseEvent.CLICK, this.onDeleteCharacter);

		removeToolTip();
	}

	private function onSelected(_: MouseEvent) {
		var characterClass: CharacterClass = Global.classModel.getCharacterClass(this.savedChar.objectType());
		characterClass.setIsSelected(true);
		characterClass.skins.getSkin(this.savedChar.skinType()).setIsSelected(true);

		var data: GameInitData = new GameInitData();
		data.createCharacter = false;
		data.charId = this.savedChar.charId();
		data.gameId = Settings.HUB_GAMEID;
		Global.playGame(data);
	}

	private function onDeleteCharacter(_: MouseEvent) {
		Global.charModel.select(this.savedChar);
		Global.layers.dialogs.openDialog(new ConfirmDeleteCharacterDialog());
	}

	public function setIcon(value: DisplayObject) {
		if (this.icon != null)
			selectContainer.removeChild(this.icon);
		this.icon = value;
		this.icon.x = this.icon.y = 3;
		if (this.icon != null)
			selectContainer.addChild(this.icon);
	}

	override public function onMouseOver(event: MouseEvent) {
		super.onMouseOver(event);
		removeToolTip();
		toolTip = new MyPlayerToolTip(this.charName, this.savedChar.charXML);
		stage.addChild(toolTip);
	}

	override public function onRollOut(event: MouseEvent) {
		super.onRollOut(event);
		removeToolTip();
	}

	private function onDeleteDown(event: MouseEvent) {
		event.stopImmediatePropagation();
		dispatchEvent(new DeleteCharacterEvent(this.savedChar));
	}
}
