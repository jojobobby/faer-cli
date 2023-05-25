package ui.options;

import openfl.display.CapsStyle;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.GraphicsStroke;
import openfl.display.IGraphicsData;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.Vector;
import ui.SimpleText;
import util.GraphicsUtil;

class ChoiceBox extends Sprite {
	public static inline var WIDTH: Int = 80;
	public static inline var HEIGHT: Int = 32;

	public var labels: Array<String>;
	public var values: Array<Dynamic>;
	public var selectedIndex: Int = -1;

	private var labelText: SimpleText = null;
	private var over = false;
	private var internalFill = new GraphicsSolidFill(0x333333, 1);
	private var overLineFill = new GraphicsSolidFill(0xB3B3B3, 1);
	private var normalLineFill = new GraphicsSolidFill(4473924, 1);
	private var path = new GraphicsPath();
	private var lineStyle = new GraphicsStroke(2, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, new GraphicsSolidFill(4473924, 1));
	private var graphicsData = new Vector<IGraphicsData>(0, false, [
		new GraphicsSolidFill(0x333333, 1),
		new GraphicsStroke(2, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, new GraphicsSolidFill(4473924, 1)),
		new GraphicsPath(),
		GraphicsUtil.END_STROKE,
		GraphicsUtil.END_FILL
	]);

	public function new(labels: Array<String>, values: Array<Dynamic>, value: String) {
		super();

		this.labels = labels;
		this.values = values;
		this.labelText = new SimpleText(16, 0xFFFFFF, false, 0, 0);
		this.labelText.setBold(true);
		this.labelText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4, 2)];
		addChild(this.labelText);
		this.setValue(value);
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
		addEventListener(MouseEvent.CLICK, this.onClick);
	}

	public function setValue(value: String) {
		for (i in 0...this.values.length)
			if (value == this.values[i]) {
				if (i == this.selectedIndex)
					return;

				this.selectedIndex = i;
				break;
			}

		this.setSelected(this.selectedIndex);
		dispatchEvent(new Event(Event.CHANGE));
	}

	public function value() {
		return this.values[this.selectedIndex];
	}

	private function drawBackground() {
		GraphicsUtil.clearPath(this.path);
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, HEIGHT, 4, [1, 1, 1, 1], this.path);
		this.lineStyle.fill = this.over ? this.overLineFill : this.normalLineFill;
		this.graphicsData[1] = this.lineStyle;
		this.graphicsData[2] = this.path;
		graphics.clear();
		graphics.drawGraphicsData(this.graphicsData);
	}

	private function setSelected(index: Int) {
		this.selectedIndex = Std.int(Math.max(0, Math.min(index, this.labels.length - 1)));
		this.setText(this.labels[this.selectedIndex]);
	}

	private function setText(text: String) {
		this.labelText.text = text;
		this.labelText.updateMetrics();
		this.labelText.x = WIDTH / 2 - this.labelText.width / 2;
		this.labelText.y = HEIGHT / 2 - this.labelText.height / 2 - 2;
		this.drawBackground();
	}

	private function onMouseOver(event: MouseEvent) {
		this.over = true;
		this.drawBackground();
	}

	private function onRollOut(event: MouseEvent) {
		this.over = false;
		this.drawBackground();
	}

	private function onClick(event: MouseEvent) {
		this.setSelected((this.selectedIndex + 1) % this.values.length);
		dispatchEvent(new Event(Event.CHANGE));
	}
}
