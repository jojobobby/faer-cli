package ui;

import constants.ItemConstants;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.IGraphicsData;
import openfl.display.Sprite;
import openfl.filters.ColorMatrixFilter;
import openfl.geom.Matrix;
import openfl.Vector;
import util.AssetLibrary;
import util.GraphicsUtil;
import util.Utils;

class Slot extends Sprite {
	public static inline var WIDTH: Int = 40;
	public static inline var HEIGHT: Int = 40;

	private static var greyColorFilter: ColorMatrixFilter = new ColorMatrixFilter(ColorUtils.singleColorFilterMatrix(0x363636));

	public var itemType = 0;
	public var hotkey = 0;
	public var cuts: Array<Int>;
	public var backgroundImage: Bitmap;
	public var fill: GraphicsSolidFill;
	public var path: GraphicsPath;

	private var graphicsData: Vector<IGraphicsData>;

	public static function slotTypeToName(itemType: Int) {
		switch (itemType) {
			case ItemConstants.ACCESSORY_TYPE:
				return "Ring";
			case ItemConstants.CONSUMABLE_TYPE:
				return "Consumable";

			case ItemConstants.SWORD_TYPE:
				return "Sword";
			case ItemConstants.BOW_TYPE:
				return "Bow";
			case ItemConstants.STAFF_TYPE:
				return "Staff";
			case ItemConstants.SCEPTER_TYPE:
				return "Scepter";

			case ItemConstants.VEST_TYPE:
				return "Vest";
			case ItemConstants.HIDE_TYPE:
				return "Hide";
			case ItemConstants.ROBE_TYPE:
				return "Robe";

			case ItemConstants.FLASK_TYPE:
				return "Flask";
			case ItemConstants.BLOODSTONE_TYPE:
				return "Bloodstone";
			case ItemConstants.TOTEM_TYPE:
				return "Totem";
			case ItemConstants.HELM_TYPE:
				return "Helm";
			case ItemConstants.BULWARK_TYPE:
				return "Bulwark";
			case ItemConstants.CLOCK_TYPE:
				return "Clock";
			case ItemConstants.CAGE_TYPE:
				return "Cage";

			default:
				return "Unknown";
		}
	}

	public function new(itemType: Int, hotkey: Int, cuts: Array<Int>) {
		super();

		this.fill = new GraphicsSolidFill(0x545454, 1);
		this.path = new GraphicsPath();
		this.graphicsData = new Vector<IGraphicsData>(0, false, [this.fill, this.path, GraphicsUtil.END_FILL]);
		this.itemType = itemType;
		this.hotkey = hotkey;
		this.cuts = cuts;
		this.drawBackground();
	}

	public function drawBackground() {
		GraphicsUtil.clearPath(this.path);
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, HEIGHT, 4, this.cuts, this.path);
		graphics.clear();
		this.graphicsData[1] = this.path;
		graphics.drawGraphicsData(this.graphicsData);

		var sheetId: Int = -1;
		switch (this.itemType) {
			case ItemConstants.ACCESSORY_TYPE:
				sheetId = 241;

			case ItemConstants.SWORD_TYPE:
				sheetId = 1;
			case ItemConstants.BOW_TYPE:
				sheetId = 65;
			case ItemConstants.STAFF_TYPE:
				sheetId = 81;
			case ItemConstants.SCEPTER_TYPE:
				sheetId = 161;

			case ItemConstants.VEST_TYPE:
				sheetId = 33;
			case ItemConstants.HIDE_TYPE:
				sheetId = 17;
			case ItemConstants.ROBE_TYPE:
				sheetId = 97;

			case ItemConstants.FLASK_TYPE:
				sheetId = 113;
			case ItemConstants.BLOODSTONE_TYPE:
				sheetId = 129;
			case ItemConstants.TOTEM_TYPE:
				sheetId = 145;
			case ItemConstants.HELM_TYPE:
				sheetId = 177;
			case ItemConstants.BULWARK_TYPE:
				sheetId = 193;
			case ItemConstants.CLOCK_TYPE:
				sheetId = 209;
			case ItemConstants.CAGE_TYPE:
				sheetId = 225;
		}

		if (this.backgroundImage == null) {
			if (sheetId != -1) {
				this.backgroundImage = new Bitmap(AssetLibrary.getImageFromSet("tieredItems", sheetId));
				this.backgroundImage.x = (40 - this.backgroundImage.width) / 2;
				this.backgroundImage.y = (40 - this.backgroundImage.height) / 2;
				this.backgroundImage.scaleX = 4;
				this.backgroundImage.scaleY = 4;
				this.backgroundImage.filters = [greyColorFilter];
				addChild(this.backgroundImage);
			} else if (this.hotkey > 0) {
				var hotkeyText: SimpleText = new SimpleText(26, 0x363636, false, 0, 0);
				hotkeyText.text = Std.string(this.hotkey);
				hotkeyText.setBold(true);
				hotkeyText.updateMetrics();
				var bd: BitmapData = new BitmapData(26, 30, true, 0);
				var m: Matrix = new Matrix();
				bd.draw(hotkeyText, m);
				this.backgroundImage = new Bitmap(bd);
				this.backgroundImage.x = WIDTH / 2 - hotkeyText.width / 2;
				this.backgroundImage.y = HEIGHT / 2 - 18;
				addChild(this.backgroundImage);
			}
		}
	}
}
