package ui;

import openfl.display.Sprite;
import openfl.filters.DropShadowFilter;

class StatusBar extends Sprite {
	public var w = 0;
	public var h = 0;
	public var color = 0;
	public var backColor = 0;
	public var textColor = 0;
	public var val = -1;
	public var max = -1;
	public var boost = -1;
	public var maxMax = -1;
	public var valueText: SimpleText;
	public var boostText: SimpleText;

	private var colorSprite: Sprite;
	private var defaultForegroundColor = 0.0;
	private var defaultBackgroundColor = 0.0;
	private var textXOffset = 0;

	public function new(w: Int, h: Int, color: Int, backColor: Int, textScale: Float = 1, textXOffset: Int = 0) {
		super();

		this.colorSprite = new Sprite();
		addChild(this.colorSprite);
		this.w = w;
		this.h = h;
		this.defaultForegroundColor = this.color = color;
		this.defaultBackgroundColor = this.backColor = backColor;
		this.textColor = 0xFFFFFF;
		this.valueText = new SimpleText(Std.int(14 * textScale), 0xFFFFFF, false, 0, 0);
		this.valueText.setBold(true);
		this.valueText.filters = [new DropShadowFilter(0, 0, 0)];
		this.valueText.y = (h - this.valueText.height) / 2;
		this.boostText = new SimpleText(Std.int(14 * textScale), this.textColor, false, 0, 0);
		this.boostText.setBold(true);
		this.boostText.alpha = 0.6;
		this.boostText.y = 0;
		this.boostText.filters = [new DropShadowFilter(0, 0, 0)];
		this.textXOffset = textXOffset;
	}

	public function draw(val: Int, max: Int, boost: Int, maxMax: Int = -1) {
		if (max > 0) {
			val = Std.int(Math.min(max, Math.max(0, val)));
		}
		if (val == this.val && max == this.max && boost == this.boost && maxMax == this.maxMax) {
			return;
		}
		this.val = val;
		this.max = max;
		this.boost = boost;
		this.maxMax = maxMax;
		this.internalDraw();
	}

	private function setTextColor(textColor: Int) {
		this.textColor = textColor;
		if (this.boostText != null) {
			this.boostText.setColor(this.textColor);
		}
		this.valueText.setColor(this.textColor);
	}

	private function internalDraw() {
		graphics.clear();
		this.colorSprite.graphics.clear();
		var textColor = 0xFFFFFF;
		if (this.maxMax > 0 && this.max - this.boost == this.maxMax)
			textColor = 0xFCDF00;
		else if (this.boost > 0)
			textColor = 0x5EB531;
	
		if (this.textColor != textColor) {
			this.setTextColor(textColor);
		}
		graphics.beginFill(this.backColor);
		graphics.drawRoundRect(0, 0, this.w, this.h, 20);
		graphics.endFill();
		this.colorSprite.graphics.beginFill(this.color);
		if (this.max > 0) {
			this.colorSprite.graphics.drawRoundRect(0, 0, this.w * (this.val / this.max), this.h, 20);
		} else {
			this.colorSprite.graphics.drawRoundRect(0, 0, this.w, this.h, 20);
		}
		this.colorSprite.graphics.endFill();
		if (this.h > 4) {
			if (this.max > 0) {
				this.valueText.text = "" + this.val + "/" + this.max;
			} else {
				this.valueText.text = "" + this.val;
			}
			this.valueText.updateMetrics();
			this.valueText.y = (this.h - this.valueText.height) / 2;

			if (!contains(this.valueText)) {
				addChild(this.valueText);
			}
			if (this.boost != 0) {
				this.boostText.text = " (" + (this.boost > 0 ? "+" : "") + Std.string(this.boost) + ")";
				this.boostText.updateMetrics();
				this.valueText.x = this.w / 2 - (this.valueText.width + this.boostText.width) / 2 + this.textXOffset;
				this.boostText.x = this.valueText.x + this.valueText.width + this.textXOffset;
				if (!contains(this.boostText)) {
					addChild(this.boostText);
				}
			} else {
				this.valueText.x = this.w / 2 - this.valueText.width / 2 + this.textXOffset;
				if (contains(this.boostText)) {
					removeChild(this.boostText);
				}
			}
		}
	}
}
