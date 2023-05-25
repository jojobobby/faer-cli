package screens;

import game.view.CurrencyDisplay;
import haxe.ds.IntMap;
import objects.ObjectLibrary;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import ui.view.ScreenBase;

class NewCharacterScreen extends Sprite {
	private var backButton: TitleMenuOption;
	private var currencyDisplay: CurrencyDisplay;
	private var boxes: IntMap<CharacterBox>;

	public function new() {
		super();

		this.boxes = new IntMap<CharacterBox>();
		addChild(new ScreenBase());
		addChild(new AccountScreen());

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);

		var playerXML: Xml = null;
		var objectType = 0;
		var characterType: String = null;
		var charBox: CharacterBox = null;

		this.backButton = new TitleMenuOption("back", 36, false);
		this.backButton.addEventListener(MouseEvent.CLICK, onBackClick);
		addChild(this.backButton);
		this.currencyDisplay = new CurrencyDisplay(CurrencyDisplay.RIGHT_TO_LEFT);
		this.currencyDisplay.draw(Global.playerModel.getGems(), Global.playerModel.getGold(), Global.playerModel.getCrowns());
		addChild(this.currencyDisplay);
		for (i in 0...ObjectLibrary.playerChars.length) {
			playerXML = ObjectLibrary.playerChars[i];
			objectType = Std.parseInt(playerXML.get("type"));
			characterType = playerXML.get("id");
			charBox = new CharacterBox(playerXML);
			charBox.x = (Main.stageWidth - 800) / 2 + 50 + 140 * Math.floor(i % 5) + 70 - charBox.width / 2;
			charBox.y = (Main.stageHeight - 600) / 2 + 88 + 140 * Math.floor(i / 5);
			this.boxes.set(objectType, charBox);
			charBox.addEventListener(MouseEvent.ROLL_OVER, onCharBoxOver);
			charBox.addEventListener(MouseEvent.ROLL_OUT, onCharBoxOut);
			addChild(charBox);
		}

		this.backButton.x = stage.stageWidth / 2 - this.backButton.width / 2;
		this.backButton.y = stage.stageHeight - 76;
		this.currencyDisplay.x = stage.stageWidth - 5;
		this.currencyDisplay.y = 25;
	}

	public function update() {
		var playerXML: Xml = null;
		var objectType = 0;
		var characterType: String = null;
		var charBox: CharacterBox = null;
		for (i in 0...ObjectLibrary.playerChars.length) {
			playerXML = ObjectLibrary.playerChars[i];
			objectType = Std.parseInt(playerXML.get("type"));
			characterType = playerXML.get("id");
			charBox = this.boxes.get(objectType);
		}
	}

	private static function onBackClick(event: Event) {
		Global.layers.screens.setScreen(new CharacterSelectionScreen());
	}

	private static function onCharBoxOver(event: MouseEvent) {
		var charBox: CharacterBox = cast(event.currentTarget, CharacterBox);
		charBox.setOver(true);
		Global.layers.tooltips.show(charBox.getTooltip());
	}

	private static function onCharBoxOut(event: MouseEvent) {
		var charBox: CharacterBox = cast(event.currentTarget, CharacterBox);
		charBox.setOver(false);
		Global.layers.tooltips.hide();
	}
}
