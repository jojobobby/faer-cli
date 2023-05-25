package ui.panels.itemgrids.itemtiles;

import openfl.Assets;
import constants.ItemConstants;
import objects.ObjectLibrary;
import objects.Player;
import openfl.display.Bitmap;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.IGraphicsData;
import openfl.display.Sprite;
import openfl.Vector;
import ui.panels.itemgrids.ItemGrid;
import util.AssetLibrary;
import util.BitmapUtil;
import util.GraphicsUtil;
import util.Utils;
import util.TextureRedrawer;

using util.Utils.XmlUtil;

class ItemTile extends Sprite {
	public static inline var WIDTH: Int = 40;
	public static inline var HEIGHT: Int = 40;

	public var restrictionBitmap: Bitmap;
	public var itemSprite: ItemTileSprite;
	public var tileId = 0;
	public var ownerGrid: ItemGrid;

	private var fill: GraphicsSolidFill = new GraphicsSolidFill(0x545454, 1);
	private var path: GraphicsPath = new GraphicsPath();
	private var graphicsData: Vector<IGraphicsData> = new Vector<IGraphicsData>(0, false,
		[new GraphicsSolidFill(0x545454, 1), new GraphicsPath(), GraphicsUtil.END_FILL]);
	private var cuts: Array<Int>;

	private var rareBackground: Bitmap;
	private var epicBackground: Bitmap;
	private var legendaryBackground: Bitmap;
	private var mythicBackground: Bitmap;

	public function new(id: Int, parentGrid: ItemGrid) {
		super();

		this.restrictionBitmap = new Bitmap(TextureRedrawer.redraw(BitmapUtil.trimAlpha(AssetLibrary.getImageFromSet("misc", 30)), 60, false, 0));
		this.restrictionBitmap.x = WIDTH - this.restrictionBitmap.width / 1.4 - 5;
		this.restrictionBitmap.y = HEIGHT - this.restrictionBitmap.height - 2;
		this.restrictionBitmap.visible = false;

		this.rareBackground = new Bitmap(Assets.getBitmapData("assets/ui/inventorySlotRare.png"));
		this.rareBackground.visible = false;
		addChild(this.rareBackground);

		this.epicBackground = new Bitmap(Assets.getBitmapData("assets/ui/inventorySlotEpic.png"));
		this.epicBackground.visible = false;
		addChild(this.epicBackground);

		this.legendaryBackground = new Bitmap(Assets.getBitmapData("assets/ui/inventorySlotLegendary.png"));
		this.legendaryBackground.visible = false;
		addChild(this.legendaryBackground);

		this.mythicBackground = new Bitmap(Assets.getBitmapData("assets/ui/inventorySlotMythic.png"));
		this.mythicBackground.visible = false;
		addChild(this.mythicBackground);

		this.tileId = id;
		this.ownerGrid = parentGrid;
		this.setItemSprite(new ItemTileSprite());
	}

	public function drawBackground(cuts: Array<Int>) {
		var itemId = this.itemSprite != null ? this.itemSprite.itemId : -1;

		if (cuts == null) {
			// for hit test
			graphics.clear();
			graphics.beginFill(0, 0);
			graphics.drawRect(0, 0, 40, 40);
			graphics.endFill();

			this.rareBackground.visible = false;
			this.epicBackground.visible = false;
			this.legendaryBackground.visible = false;
			this.mythicBackground.visible = false;

			if (itemId != -1) {
				switch (ObjectLibrary.xmlLibrary.get(itemId)?.element("Tier")) {
					case "Rare": 
						this.rareBackground.visible = true;
					case "Epic":
						this.epicBackground.visible = true;
					case "Legendary":
						this.legendaryBackground.visible = true;
					case "Mythic":
						this.mythicBackground.visible = true;
				}
			}
			return;
		}

		this.cuts = cuts;
		var fill: GraphicsSolidFill = new GraphicsSolidFill(0x545454, 1);
		if (itemId != -1) {
			var xml = ObjectLibrary.xmlLibrary.get(itemId);
			if (xml?.elementsNamed("Tier").hasNext()) {
				this.fill.color = fill.color = ColorUtils.getRarityColor(xml.elementsNamed("Tier").next().firstChild().nodeValue, 0x545454);
				this.graphicsData[0] = this.fill;
			}
		} else {
			this.fill.color = fill.color = 0x545454;
			this.graphicsData[0] = this.fill;
		}
		GraphicsUtil.clearPath(this.path);
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, HEIGHT, 4, this.cuts, this.path);
		this.graphicsData[1] = this.path;
		graphics.clear();
		graphics.drawGraphicsData(this.graphicsData);
	}

	public function setItem(itemId: Int) {
		if (itemId == this.itemSprite.itemId)
			return false;

		this.itemSprite.setType(itemId);
		this.drawBackground(this.cuts);
		this.updateUseability(this.ownerGrid.curPlayer);
		return true;
	}

	public function setItemSprite(itemTileSprite: ItemTileSprite) {
		this.itemSprite = itemTileSprite;
		this.itemSprite.x = WIDTH / 2;
		this.itemSprite.y = HEIGHT / 2;

		this.drawBackground(this.cuts);

		addChild(this.itemSprite);
		addChild(this.restrictionBitmap);
	}

	public function updateUseability(player: Player) {
		if (this.itemSprite.itemId != ItemConstants.NO_ITEM)
			this.restrictionBitmap.visible = !ObjectLibrary.isUsableByPlayer(this.itemSprite.itemId, player);
		else
			this.restrictionBitmap.visible = false;
	}

	public function canHoldItem(itemType: Int) {
		return true;
	}

	public function resetItemPosition() {
		this.setItemSprite(this.itemSprite);
	}

	public function getItemId() {
		return this.itemSprite.itemId;
	}
}
