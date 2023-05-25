package ui.panels.itemgrids.itemtiles;

import constants.ItemConstants;
import objects.ObjectLibrary;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.filters.BitmapFilter;
import openfl.filters.ColorMatrixFilter;
import openfl.geom.Matrix;
import ui.SimpleText;

class ItemTileSprite extends Sprite {
	public static var DIM_FILTER: Array<BitmapFilter> = [
		new ColorMatrixFilter([0.4, 0, 0, 0, 0, 0, 0.4, 0, 0, 0, 0, 0, 0.4, 0, 0, 0, 0, 0, 1, 0])
	];

	public var itemId = 0;
	public var itemBitmap: Bitmap;

	public function new() {
		super();

		this.itemBitmap = new Bitmap();
		addChild(this.itemBitmap);
		this.itemId = -1;
	}

	public function setDim(dim: Bool) {
		filters = dim ? DIM_FILTER : null;
	}

	public function setType(displayedItemType: Int) {
		var texture: BitmapData = null;
		var eqXML: Xml = null;
		var tempText: SimpleText = null;
		this.itemId = displayedItemType;
		if (this.itemId != ItemConstants.NO_ITEM) {
			texture = ObjectLibrary.getRedrawnTextureFromType(this.itemId, 80, true);
			eqXML = ObjectLibrary.xmlLibrary.get(this.itemId);
			if (eqXML?.elementsNamed("Doses").hasNext()) {
				texture = texture.clone();
				tempText = new SimpleText(12, 0xFFFFFF, false, 0, 0);
				tempText.text = eqXML.elementsNamed("Doses").next().firstChild().nodeValue;
				tempText.updateMetrics();
				var m: Matrix = new Matrix();
				m.translate(10, 5);
				texture.draw(tempText, m);
			}

			this.itemBitmap.bitmapData = texture;
			this.itemBitmap.x = -texture.width / 2;
			this.itemBitmap.y = -texture.height / 2;
			visible = true;
		} else
			visible = false;
	}
}
