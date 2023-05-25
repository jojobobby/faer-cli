package screens.charrects;
import appengine.SavedCharacter;
import objects.ObjectLibrary;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;
import util.AnimatedChar;
import util.BitmapUtil;

class CreateNewCharacterRect extends CharacterRect {
	private var bitmap: Bitmap;
	private var classNameText: SimpleText;

	public function new() {
		super(0x545454, 0x777777);
		makeContainer();
		var playerXML: Xml = ObjectLibrary.playerChars[Std.int(ObjectLibrary.playerChars.length * Math.random())];
		var bd: BitmapData = SavedCharacter.getImage(null, playerXML, AnimatedChar.RIGHT, AnimatedChar.STAND, 0, false, false);
		bd = BitmapUtil.cropToBitmapData(bd, 6, 6, bd.width - 12, bd.height - 6);
		this.bitmap = new Bitmap();
		this.bitmap.bitmapData = bd;
		this.bitmap.x = this.bitmap.y = 3;
		selectContainer.addChild(this.bitmap);
		this.classNameText = new SimpleText(18, 0xFFFFFF, false, 0, 0);
		this.classNameText.setBold(true);
		this.classNameText.text = "New Character";
		this.classNameText.updateMetrics();
		this.classNameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.classNameText.x = (CharacterRect.WIDTH - this.classNameText.width) / 2;
		this.classNameText.y = (CharacterRect.HEIGHT - this.classNameText.height) / 2 - 3;
		selectContainer.addChild(this.classNameText);
	}
}