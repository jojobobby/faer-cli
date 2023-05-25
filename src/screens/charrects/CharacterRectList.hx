package screens.charrects;

import appengine.SavedCharacter;
import assets.CharacterFactory;
import classes.model.CharacterClass;
import classes.model.CharacterSkin;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.DisplayObject;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import screens.NewCharacterScreen;

class CharacterRectList extends Sprite {
	public function new() {
		super();

		var buyRect: BuyCharacterRect;
		var charType: CharacterClass = null;
		var currCharBox: CurrentCharacterRect = null;
		var i = 0;
		var newCharRect: CreateNewCharacterRect = null;
		var charName: String = Global.playerModel.getName();
		var yOffset: Int = 4, xFlip: Int = 0, idx = 0;
		for (savedChar in Global.playerModel.getSavedCharacters()) {
			charType = Global.classModel.getCharacterClass(savedChar.objectType());
			currCharBox = new CurrentCharacterRect(charName, charType, savedChar);
			currCharBox.setIcon(getIcon(savedChar));
			currCharBox.x = xFlip;
			currCharBox.y = yOffset;
			addChild(currCharBox);
			if (idx % 2 == 0)
				xFlip = CharacterRect.WIDTH + 5;
			else {
				xFlip = 0;
				yOffset += CharacterRect.HEIGHT + 4;
			}
			idx++;
		}
		if (Global.playerModel.hasAvailableCharSlot()) {
			for (i in 0...Global.playerModel.getAvailableCharSlots()) {
				newCharRect = new CreateNewCharacterRect();
				newCharRect.addEventListener(MouseEvent.MOUSE_DOWN, onNewChar);
				newCharRect.x = xFlip;
				newCharRect.y = yOffset;
				addChild(newCharRect);
				if (idx % 2 == 0)
					xFlip = CharacterRect.WIDTH + 5;
				else {
					xFlip = 0;
					yOffset += CharacterRect.HEIGHT + 4;
				}
				idx++;
			}
		}
		buyRect = new BuyCharacterRect();
		buyRect.addEventListener(MouseEvent.MOUSE_DOWN, onBuyCharSlot);
		buyRect.x = xFlip;
		buyRect.y = yOffset;
		addChild(buyRect);
	}

	private static function getIcon(savedChar: SavedCharacter): DisplayObject {
		var chrClass: CharacterClass = Global.classModel.getCharacterClass(savedChar.objectType());
		var skin: CharacterSkin = chrClass.skins.getSkin(savedChar.skinType()) != null ? chrClass.skins.getSkin(savedChar.skinType()) : chrClass.skins.getDefaultSkin();
		var data: BitmapData = CharacterFactory.makeIcon(skin.template, 100);
		return new Bitmap(data);
	}

	private static function onNewChar(event: Event) {
		Global.setScreenValid(new NewCharacterScreen());
	}

	private static function onBuyCharSlot(event: Event) {
		Global.buyCharSlot();
	}
}
