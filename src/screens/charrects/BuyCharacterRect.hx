package screens.charrects;

import assets.IconFactory;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;

class BuyCharacterRect extends CharacterRect {
	private var classNameText: SimpleText;
	private var priceText: SimpleText;
	private var currency: Bitmap;

	private static function buildIcon(): Shape {
		var shape: Shape = new Shape();
		var g: Graphics = shape.graphics;
		g.beginFill(0x3B3536);
		g.lineStyle(1, 0x463E41);
		g.drawCircle(22, 22, 19);
		g.lineStyle();
		g.endFill();
		g.beginFill(0x1F1F1F);
		g.drawRect(14, 20, 16, 4);
		g.endFill();
		g.beginFill(0x1F1F1F);
		g.drawRect(20, 14, 4, 16);
		g.endFill();
		return shape;
	}

	private static function getOrdinalString(num: Int) {
		var str: String = Std.string(num);
		var ones: Int = num % 10;
		var tens: Int = Std.int(num / 10) % 10;
		if (tens == 1) {
			str = str + "th";
		} else if (ones == 1) {
			str = str + "st";
		} else if (ones == 2) {
			str = str + "nd";
		} else if (ones == 3) {
			str = str + "rd";
		} else {
			str = str + "th";
		}
		return str;
	}

	public function new() {
		super(0x1F1F1F, 0x424242);
		var icon: Shape = buildIcon();
		icon.x = 7;
		icon.y = 7;
		addChild(icon);
		makeContainer();
		this.classNameText = new SimpleText(18, 0xFFFFFF);
		this.classNameText.setBold(true);
		this.classNameText.text = "Buy " + getOrdinalString(Global.playerModel.getMaxCharacters() + 1) + " Character Slot";
		this.classNameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.classNameText.updateMetrics();
		this.classNameText.x = (CharacterRect.WIDTH - this.classNameText.width) / 2 - 22;
		this.classNameText.y = (CharacterRect.HEIGHT - this.classNameText.height) / 2 - 3;
		selectContainer.addChild(this.classNameText);
		this.priceText = new SimpleText(18, 0xFFFFFF);
		this.priceText.text = Std.string(Global.playerModel.getNextCharSlotPrice());
		this.priceText.updateMetrics();
		this.priceText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.priceText.x = CharacterRect.WIDTH - 43 - this.priceText.width;
		this.priceText.y = this.classNameText.y;
		selectContainer.addChild(this.priceText);
		var bd: BitmapData = Global.playerModel.isNextCharSlotCurrencyGems() ? IconFactory.makeGold() : IconFactory.makeGems();
		this.currency = new Bitmap(bd);
		this.currency.x = CharacterRect.WIDTH - 43;
		this.currency.y = this.priceText.y + 2;
		selectContainer.addChild(this.currency);
	}
}
