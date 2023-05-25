package ui.dialogs;

import openfl.display.CapsStyle;
import openfl.display.Graphics;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.GraphicsStroke;
import openfl.display.IGraphicsData;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import openfl.Vector;
import ui.SimpleText;
import ui.TextButton;
import util.GraphicsUtil;

class Dialog extends Sprite {
	public static inline var BUTTON1_EVENT: String = "DIALOG_BUTTON1";
	public static inline var BUTTON2_EVENT: String = "DIALOG_BUTTON2";
	private static inline var WIDTH: Int = 300;

	public var box: Sprite;
	public var rect: Shape;
	public var textText: SimpleText;
	public var titleText: SimpleText = null;
	public var button1: TextButton = null;
	public var button2: TextButton = null;
	public var offsetX = 0.0;
	public var offsetY = 0.0;

	private var path: GraphicsPath = new GraphicsPath();
	private var outlineFill: GraphicsSolidFill = new GraphicsSolidFill(0xFFFFFF, 1);
	private var lineStyle: GraphicsStroke;
	private var backgroundFill: GraphicsSolidFill = new GraphicsSolidFill(0x363636, 1);
	private var graphicsData: Vector<IGraphicsData>;

	public function new(text: String, title: String, button1: String = null, button2: String = null) {
		super();

		this.lineStyle = new GraphicsStroke(1, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, outlineFill);
		this.graphicsData = new Vector<IGraphicsData>(0, false, [lineStyle, backgroundFill, path, GraphicsUtil.END_FILL, GraphicsUtil.END_STROKE]);
		this.box = new Sprite();
		this.initText(text);
		this.initTitleText(title);
		if (button1 != null) {
			this.button1 = new TextButton(16, button1, 120);
			this.button1.addEventListener(MouseEvent.CLICK, this.onButton1Click);
		}
		if (button2 != null) {
			this.button2 = new TextButton(16, button2, 120);
			this.button2.addEventListener(MouseEvent.CLICK, this.onButton2Click);
		}
		this.draw();
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
	}

	public function setBaseAlpha(value: Float) {
		this.rect.alpha = value > 1 ? 1 : value < 0 ? 0 : value;
	}

	public function initText(text: String) {
		this.textText = new SimpleText(14, 0xB3B3B3, false, WIDTH - 40, 0);
		this.textText.x = 20;
		this.textText.multiline = true;
		this.textText.wordWrap = true;
		this.textText.htmlText = "<p align=\"center\">" + text + "</p>";
		this.textText.autoSize = TextFieldAutoSize.CENTER;
		this.textText.mouseEnabled = true;
		this.textText.updateMetrics();
		this.textText.filters = [new DropShadowFilter(0, 0, 0, 1, 6, 6, 1)];
	}

	public function draw() {
		var by = 0;
		if (this.titleText != null) {
			this.titleText.y = 2;
			this.box.addChild(this.titleText);
			this.textText.y = this.box.height + 8;
		} else {
			this.textText.y = 4;
		}
		this.box.addChild(this.textText);
		if (this.button1 != null) {
			by = Std.int(this.box.height + 16);
			this.box.addChild(this.button1);
			this.button1.y = by;
			if (this.button2 == null) {
				this.button1.x = WIDTH / 2 - this.button1.width / 2;
			} else {
				this.button1.x = WIDTH / 4 - this.button1.width / 2;
				this.box.addChild(this.button2);
				this.button2.x = 3 * WIDTH / 4 - this.button2.width / 2;
				this.button2.y = by;
			}
		}
		GraphicsUtil.clearPath(this.path);
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, Std.int(this.box.height + 10), 4, [1, 1, 1, 1], this.path);
		this.rect = new Shape();
		var g: Graphics = this.rect.graphics;
		g.drawGraphicsData(this.graphicsData);
		this.box.addChildAt(this.rect, 0);
		this.box.filters = [new DropShadowFilter(0, 0, 0, 1, 16, 16, 1)];
		addChild(this.box);
	}

	private function initTitleText(title: String) {
		if (title != null) {
			this.titleText = new SimpleText(18, 5746018, false, WIDTH, 0);
			this.titleText.setBold(true);
			this.titleText.htmlText = "<p align=\"center\">" + title + "</p>";
			this.titleText.updateMetrics();
			this.titleText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8, 1)];
		}
	}

	private function onAddedToStage(event: Event) {
		this.box.x = this.offsetX + stage.stageWidth / 2 - this.box.width / 2;
		this.box.y = this.offsetY + stage.stageHeight / 2 - this.box.height / 2;
	}

	private function onButton1Click(event: MouseEvent) {
		dispatchEvent(new Event(BUTTON1_EVENT));
	}

	private function onButton2Click(event: Event) {
		dispatchEvent(new Event(BUTTON2_EVENT));
	}
}
