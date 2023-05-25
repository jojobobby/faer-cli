package ui;

import assets.IconFactory;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.IGraphicsData;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.Vector;
import ui.SimpleText;
import util.GraphicsUtil;

class BuyButton extends Sprite {
	private static inline var BEVEL: Int = 4;
	private static inline var PADDING: Int = 5;
	public static var coin: BitmapData;
	public static var fame: BitmapData;

	private var enabledFill: GraphicsSolidFill = new GraphicsSolidFill(0xFFFFFF, 1);
	private var disabledFill: GraphicsSolidFill = new GraphicsSolidFill(0x7F7F7F, 1);
	private var graphicsPath: GraphicsPath = new GraphicsPath();
	private var graphicsData: Vector<IGraphicsData> = new Vector<IGraphicsData>(0, false, [
		new GraphicsSolidFill(0xFFFFFF, 1),
		new GraphicsSolidFill(0x7F7F7F, 1),
		GraphicsUtil.END_FILL
	]);

	public var prefix = "";
	public var text: SimpleText;
	public var icon: Bitmap;
	public var price: Int = -1;
	public var currency: Int = -1;
	public var _width: Int = -1;

	public function new(prefix: String, size: Int, price: Int, currency: Int) {
		super();

		this.prefix = prefix;
		this.text = new SimpleText(size, 0x363636, false, 0, 0);
		this.text.setBold(true);
		addChild(this.text);
		coin = IconFactory.makeGems();
		fame = IconFactory.makeGold();
		this.icon = new Bitmap();
		addChild(this.icon);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
		this.setPrice(price, currency);
	}

	public function setPrice(price: Int, currency: Int) {
		if (this.price != price || this.currency != currency) {
			this.price = price;
			this.currency = currency;
			this.updateUI();
		}
	}

	public function setEnabled(enabled: Bool) {
		if (enabled != mouseEnabled) {
			mouseEnabled = enabled;
			this.draw();
		}
	}

	public function setWidth(value: Int) {
		this._width = value;
		this.updateUI();
	}

	private function updateUI() {
		this.updateText();
		this.updateIcon();
		this.updateBackground();
		this.draw();
	}

	private function updateIcon() {
		switch (this.currency) {
			case 0:
				this.icon.bitmapData = coin;
			case 1:
				this.icon.bitmapData = fame;
			default:
				this.icon.bitmapData = null;
		}
		this.updateIconPosition();
	}

	private function updateBackground() {
		GraphicsUtil.clearPath(this.graphicsPath);
		GraphicsUtil.drawCutEdgeRect(0, 0, this.getWidth(), this.getHeight(), BEVEL, [1, 1, 1, 1], this.graphicsPath);
	}

	private function updateText() {
		this.text.text = this.prefix + Std.string(this.price);
		this.text.updateMetrics();
		this.text.x = (this.getWidth() - this.icon.width - this.text.textWidth - PADDING) * 0.5;
		this.text.y = 1;
	}

	private function updateIconPosition() {
		this.icon.x = this.text.x + this.text.textWidth + PADDING;
		this.icon.y = (this.getHeight() - this.icon.height) * 0.5;
	}

	private function draw() {
		this.graphicsData[0] = mouseEnabled ? this.enabledFill : this.disabledFill;
		graphics.clear();
		graphics.drawGraphicsData(this.graphicsData);
	}

	private function getWidth() {
		return Std.int(Math.max(this._width, this.text.width + this.icon.width + 3 * PADDING));
	}

	private function getHeight() {
		return Std.int(this.text.textHeight + 8);
	}

	private function onMouseOver(event: MouseEvent) {
		this.enabledFill.color = 0xFFDC85;
		this.draw();
	}

	private function onRollOut(event: MouseEvent) {
		this.enabledFill.color = 0xFFFFFF;
		this.draw();
	}
}
