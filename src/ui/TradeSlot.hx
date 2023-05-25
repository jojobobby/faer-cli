package ui;

import objects.ObjectLibrary;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.CapsStyle;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.GraphicsStroke;
import openfl.display.IGraphicsData;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Shape;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.Vector;
import util.GraphicsUtil;
import util.Utils;

class TradeSlot extends Slot {
	public var id = 0;
	public var item = 0;
	public var tradeable = false;
	public var included = false;
	public var itemBitmap: Bitmap;
	public var overlay: Shape;

	private var overlayFill: GraphicsSolidFill;
	private var lineStyle: GraphicsStroke;
	private var overlayPath: GraphicsPath;
	private var tradeGraphicsData: Vector<IGraphicsData>;

	public function new(item: Int, tradeable: Bool, included: Bool, itemType: Int, hotkey: Int, cuts: Array<Int>, id: Int) {
		var texture: BitmapData = null;
		var eqXML: Xml = null;
		var offset: Point = null;
		var tempText: SimpleText = null;
		this.overlayFill = new GraphicsSolidFill(16711310, 1);
		this.lineStyle = new GraphicsStroke(2, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, this.overlayFill);
		this.overlayPath = new GraphicsPath();
		this.tradeGraphicsData = new Vector<IGraphicsData>(0, false, [this.lineStyle, this.overlayPath, GraphicsUtil.END_STROKE]);
		super(itemType, hotkey, cuts);
		this.id = id;
		this.item = item;
		this.tradeable = tradeable;
		this.included = included;
		if (this.item != -1) {
			if (this.backgroundImage != null && contains(this.backgroundImage))
				removeChild(this.backgroundImage);
			texture = ObjectLibrary.getRedrawnTextureFromType(this.item, 80, true);
			eqXML = ObjectLibrary.xmlLibrary.get(this.item);
			if (eqXML.elementsNamed("Doses").hasNext()) {
				texture = texture.clone();
				tempText = new SimpleText(12, 0xFFFFFF, false, 0, 0);
				tempText.text = eqXML.elementsNamed("Doses").next().firstChild().nodeValue;
				tempText.updateMetrics();
				var m: Matrix = new Matrix();
				m.translate(10, 5);
				texture.draw(tempText, m);
			}

			this.itemBitmap = new Bitmap(texture);
			this.itemBitmap.x = WIDTH / 2 - this.itemBitmap.width / 2 + offset.x;
			this.itemBitmap.y = HEIGHT / 2 - this.itemBitmap.height / 2 + offset.y;
			if (this.itemBitmap != null && !contains(this.itemBitmap))
				addChild(this.itemBitmap);
		}

		if (!this.tradeable)
			transform.colorTransform = ColorUtils.veryDarkCT;

		this.overlay = this.getOverlay();
		addChild(this.overlay);
		this.setIncluded(included);
	}

	public function setIncluded(included: Bool) {
		this.included = included;
		this.overlay.visible = this.included;
		if (this.included)
			fill.color = 0xFFCD57;
		else
			fill.color = 0x545454;

		drawBackground();
	}

	private function getOverlay() {
		var shape = new Shape();
		GraphicsUtil.clearPath(this.overlayPath);
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, HEIGHT, 4, cuts, this.overlayPath);
		shape.graphics.drawGraphicsData(this.tradeGraphicsData);
		return shape;
	}
}
