package classes.view;
import assets.CharacterFactory;
import classes.model.CharacterSkin;
import classes.model.CharacterSkins;
import openfl.display.Bitmap;
import ui.BuyButton;
import util.AssetLibrary;

class CharSkinListItemFactory {
	public static function make(skins: CharacterSkins): Array<CharSkinListItem> {
		var count: Int = skins.getCount();
		var items: Array<CharSkinListItem> = new Array<CharSkinListItem>();
		var model: CharacterSkin;
		var button: BuyButton = new BuyButton("Buy for ", 16, 0, 0);
		button.setWidth(120);

		for (i in 0...count) {
			model = skins.getSkinAt(i);

			items[i] = new CharSkinListItem();
			items[i].setSkin(new Bitmap(CharacterFactory.makeIcon(model.template)));
			items[i].setModel(model);
			items[i].setLockIcon(AssetLibrary.getImageFromSet("misc", 11));
			items[i].setBuyButton(button);
		}

		return items;
	}
}
