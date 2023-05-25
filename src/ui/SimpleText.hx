package ui;

import openfl.events.Event;
import openfl.text.Font;
import openfl.text.TextField;
import openfl.text.TextFieldType;
import openfl.text.TextFormat;
import openfl.text.TextFormatAlign;
import openfl.text.TextLineMetrics;
import openfl.utils.Assets;

class SimpleText extends TextField {
	public static var font: Font;
	public static var fontRegistered = false;

	public var inputWidth = 0;
	public var inputHeight = 0;
	public var actualWidth = 0;
	public var actualHeight = 0;

	public function new(textSize: Int, color: Int = 0xFFFFFF, settable: Bool = false, widthParam: Int = 0, heightParam: Int = 0, isLink: Bool = false) {
		super();

		if (!fontRegistered) {
			font = Assets.getFont("assets/fonts/Ubuntu-Medium.ttf");
			Font.registerFont(font);
			Font.registerFont(Assets.getFont("assets/fonts/Ubuntu-MediumItalic.ttf"));
			Font.registerFont(Assets.getFont("assets/fonts/Ubuntu-Bold.ttf"));
			Font.registerFont(Assets.getFont("assets/fonts/Ubuntu-BoldItalic.ttf"));
			fontRegistered = true;
		}

		this.inputWidth = widthParam;
		if (this.inputWidth != 0)
			width = widthParam;

		this.inputHeight = heightParam;
		if (this.inputHeight != 0)
			height = heightParam;

		var format: TextFormat = defaultTextFormat;
		format.font = font.fontName;
		format.bold = false;
		format.size = textSize;
		format.color = color;
		embedFonts = true;
		defaultTextFormat = format;
		if (settable) {
			selectable = true;
			mouseEnabled = true;
			type = TextFieldType.INPUT;
			border = true;
			borderColor = color;
			addEventListener(Event.CHANGE, this.onChange);
		} else {
			selectable = false;
			mouseEnabled = false;
		}

		if (isLink)
			mouseEnabled = true;
	}

	public function setSize(size: Int) {
		var format = defaultTextFormat;
		format.size = size;
		this.applyFormat(format);
		return this;
	}

	public function setColor(color: Int) {
		var format = defaultTextFormat;
		format.color = color;
		this.applyFormat(format);
		return this;
	}

	public function setBold(bold: Bool) {
		var format = defaultTextFormat;
		format.bold = bold;
		this.applyFormat(format);
		return this;
	}

	public function setItalic(italic: Bool) {
		var format = defaultTextFormat;
		format.italic = italic;
		this.applyFormat(format);
		return this;
	}

	public function setAlignment(alignment: TextFormatAlign) {
		var format = defaultTextFormat;
		format.align = alignment;
		this.applyFormat(format);
		return this;
	}

	public function setText(text: String) {
		this.text = text;
		return this;
	}

	public function setHtmlText(text: String) {
		this.htmlText = text;
		return this;
	}

	public function updateMetrics() {
		var textMetrics: TextLineMetrics = null;
		var textWidth = 0;
		var textHeight = 0;
		this.actualWidth = 0;
		this.actualHeight = 0;
		for (i in 0...numLines) {
			textMetrics = getLineMetrics(i);
			textWidth = Std.int(textMetrics.width + 4);
			textHeight = Std.int(textMetrics.height + 4);
			if (textWidth > this.actualWidth)
				this.actualWidth = textWidth;

			this.actualHeight += textHeight;
		}

		width = this.inputWidth == 0 ? this.actualWidth + 1 : this.inputWidth;
		height = this.inputHeight == 0 ? this.actualHeight + 1 : this.inputHeight;
		return this;
	}

	public function useTextDimensions() {
		width = this.inputWidth == 0 ? textWidth + 4 : this.inputWidth;
		height = this.inputHeight == 0 ? textHeight + 16 : this.inputHeight;
	}

	private function applyFormat(format: TextFormat) {
		setTextFormat(format);
		defaultTextFormat = format;
	}

	private function onChange(_: Event) {
		this.updateMetrics();
	}
}
