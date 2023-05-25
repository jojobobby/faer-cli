package ui;

import account.view.LabeledField;
import openfl.display.CapsStyle;
import openfl.display.DisplayObject;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.GraphicsStroke;
import openfl.display.IGraphicsData;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.filters.DropShadowFilter;
import openfl.Vector;
import util.GraphicsUtil;

class Frame extends Sprite {
	public var titleText: SimpleText;
	public var leftButton: ClickableText;
	public var rightButton: ClickableText;
	public var textInputFields: Array<TextInputField>;
	public var navigationLinks: Array<ClickableText>;
	public var w: Int = 288;
	public var h: Int = 100;

	private var titleFill: GraphicsSolidFill = new GraphicsSolidFill(5066061, 1);
	private var backgroundFill: GraphicsSolidFill = new GraphicsSolidFill(0x363636, 1);
	private var outlineFill: GraphicsSolidFill = new GraphicsSolidFill(0xFFFFFF, 1);
	private var lineStyle: GraphicsStroke;
	private var path1: GraphicsPath = new GraphicsPath();
	private var path2: GraphicsPath = new GraphicsPath();
	private var graphicsData: Vector<IGraphicsData>;

	public function new(title: String, leftButton: String, rightButton: String, w: Int = 288) {
		super();

		this.lineStyle = new GraphicsStroke(1, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, outlineFill);
		this.graphicsData = new Vector<IGraphicsData>(0, false, [
			backgroundFill,
			path2,
			GraphicsUtil.END_FILL,
			titleFill,
			path1,
			GraphicsUtil.END_FILL,
			lineStyle,
			path2,
			GraphicsUtil.END_STROKE
		]);
		this.textInputFields = new Array<TextInputField>();
		this.navigationLinks = new Array<ClickableText>();
		this.w = w;
		this.titleText = new SimpleText(12, 0xB3B3B3, false, 0, 0);
		this.titleText.text = title;
		this.titleText.updateMetrics();
		this.titleText.filters = [new DropShadowFilter(0, 0, 0)];
		this.titleText.x = 5;
		this.titleText.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		addChild(this.titleText);
		this.leftButton = new ClickableText(18, true, leftButton);
		if (leftButton != "") {
			this.leftButton.buttonMode = true;
			this.leftButton.x = 109;
			addChild(this.leftButton);
		}
		this.rightButton = new ClickableText(18, true, rightButton);
		this.rightButton.buttonMode = true;
		this.rightButton.x = this.w - this.rightButton.width - 26;
		addChild(this.rightButton);
		filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function addLabeledField(labeledField: LabeledField) {
		addChild(labeledField);
		labeledField.y = this.h - 60;
		labeledField.x = 17;
		this.h += Std.int(labeledField.getHeight());
	}

	public function addTextInputField(textInputField: TextInputField) {
		this.textInputFields.push(textInputField);
		addChild(textInputField);
		textInputField.y = this.h - 60;
		textInputField.x = 17;
		this.h += TextInputField.HEIGHT;
	}

	public function addNavigationText(navigationLink: ClickableText) {
		this.navigationLinks.push(navigationLink);
		addChild(navigationLink);
		navigationLink.y = this.h - 66;
		navigationLink.x = 17;
		this.h = this.h + 20;
	}

	public function addComponent(component: DisplayObject, offsetX: Int = 8) {
		addChild(component);
		component.y = this.h - 66;
		component.x = offsetX;
		this.h = Std.int(this.h + component.height);
	}

	public function addPlainText(plainText: String) {
		var text: SimpleText = new SimpleText(12, 0xFFFFFF, false, 0, 0);
		text.text = plainText;
		text.updateMetrics();
		text.filters = [new DropShadowFilter(0, 0, 0)];
		addChild(text);
		text.y = this.h - 66;
		text.x = 17;
		this.h = this.h + 20;
	}

	public function addTitle(title: String) {
		var text: SimpleText;
		text = new SimpleText(20, 11711154, false, 0, 0);
		text.text = title;
		text.setBold(true);
		text.updateMetrics();
		text.filters = [new DropShadowFilter(0, 0, 0, 0.5, 12, 12)];
		addChild(text);
		text.y = this.h - 60;
		text.x = 15;
		this.h = this.h + 40;
	}

	public function addCheckBox(checkBox: CheckBoxField) {
		addChild(checkBox);
		checkBox.y = this.h - 66;
		checkBox.x = 17;
		this.h = this.h + 44;
	}

	public function addSpace(space: Int) {
		this.h = this.h + space;
	}

	public function disable() {
		mouseEnabled = false;
		mouseChildren = false;
		for (navigationLink in this.navigationLinks) {
			navigationLink.setDefaultColor(0xB3B3B3);
		}
		this.leftButton.setDefaultColor(0xB3B3B3);
		this.rightButton.setDefaultColor(0xB3B3B3);
	}

	public function enable() {
		mouseEnabled = true;
		mouseChildren = true;
		for (navigationLink in this.navigationLinks) {
			navigationLink.setDefaultColor(0xFFFFFF);
		}
		this.leftButton.setDefaultColor(0xFFFFFF);
		this.rightButton.setDefaultColor(0xFFFFFF);
	}

	private function draw() {
		graphics.clear();
		GraphicsUtil.clearPath(this.path1);
		GraphicsUtil.drawCutEdgeRect(-6, -6, this.w, 20 + 12, 4, [1, 1, 0, 0], this.path1);
		GraphicsUtil.clearPath(this.path2);
		GraphicsUtil.drawCutEdgeRect(-6, -6, this.w, this.h, 4, [1, 1, 1, 1], this.path2);
		this.leftButton.y = this.h - 52;
		this.rightButton.y = this.h - 52;
		graphics.drawGraphicsData(this.graphicsData);
	}

	public function onAddedToStage(event: Event) {
		this.draw();
		x = stage.stageWidth / 2 - (this.w - 6) / 2;
		y = stage.stageHeight / 2 - height / 2;
		if (this.textInputFields.length > 0)
			stage.focus = this.textInputFields[0].inputText;
	}

	private function onRemovedFromStage(event: Event) {}
}
