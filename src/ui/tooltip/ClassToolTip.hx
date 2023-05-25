package ui.tooltip;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;
import util.AnimatedChar;
import util.AnimatedChars;
import util.MaskedImage;
import util.TextureRedrawer;

class ClassToolTip extends ToolTip {
	private var portrait: Bitmap;
	private var nameText: SimpleText;
	private var descriptionText: SimpleText;

	public function new(playerXML: Xml) {
		super(0x363636, 1, 0xFFFFFF, 1);

		var xml = playerXML.elementsNamed("AnimatedTexture").next();
		var animatedChar: AnimatedChar = AnimatedChars.getAnimatedChar(xml.elementsNamed("Sheet").next().firstChild().nodeValue,
			Std.parseInt(xml.elementsNamed("Index").next().firstChild().nodeValue));
		var image: MaskedImage = animatedChar.imageFromDir(AnimatedChar.RIGHT, AnimatedChar.STAND, 0);
		var size: Int = Std.int(4 / image.width() * 100);
		var bd: BitmapData = TextureRedrawer.redraw(image.image, size, true, 0);

		this.portrait = new Bitmap();
		this.portrait.bitmapData = bd;
		this.portrait.x = 4;
		this.portrait.y = 0;
		addChild(this.portrait);

		this.nameText = new SimpleText(13, 0xB3B3B3, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.text = playerXML.get("id");
		this.nameText.updateMetrics();
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		this.nameText.x = 40;
		this.nameText.y = 6;
		addChild(this.nameText);

		this.descriptionText = new SimpleText(13, 0xB3B3B3, false, 174, 0);
		this.descriptionText.wordWrap = true;
		this.descriptionText.multiline = true;
		this.descriptionText.text = playerXML.elementsNamed("Description").next().firstChild().nodeValue;
		this.descriptionText.updateMetrics();
		this.descriptionText.filters = [new DropShadowFilter(0, 0, 0)];
		this.descriptionText.x = 8;
		this.descriptionText.y = 40;
		addChild(this.descriptionText);
	}
}