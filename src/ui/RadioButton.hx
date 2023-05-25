package ui;

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
import openfl.Vector;
import util.GraphicsUtil;
import util.Signal;

class RadioButton extends Sprite {
	public var changed = new Signal<Bool>();

	private static inline var WIDTH: Int = 28;
	private static inline var HEIGHT: Int = 28;

	private var unselected: Shape;
	private var selected: Shape;

	public function new() {
		super();

		addChild(this.unselected = this.makeUnselected());
		addChild(this.selected = this.makeSelected());
		this.setSelected(false);
	}

	public function setSelected(value: Bool) {
		this.unselected.visible = !value;
		this.selected.visible = value;
		this.changed.emit(value);
	}

	private function makeUnselected(): Shape {
		var shape: Shape = new Shape();
		this.drawOutline(shape.graphics);
		return shape;
	}

	private function makeSelected(): Shape {
		var shape: Shape = new Shape();
		this.drawOutline(shape.graphics);
		this.drawFill(shape.graphics);
		return shape;
	}

	private function drawOutline(graphics: Graphics) {
		var internalFill: GraphicsSolidFill = new GraphicsSolidFill(0, 0.01);
		var outlineFill: GraphicsSolidFill = new GraphicsSolidFill(0xFFFFFF, 1);
		var outlineStyle: GraphicsStroke = new GraphicsStroke(2, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, outlineFill);
		var outlinePath: GraphicsPath = new GraphicsPath();
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, HEIGHT, 4, GraphicsUtil.ALL_CUTS, outlinePath);
		var data: Vector<IGraphicsData> = new Vector<IGraphicsData>(0, false, [
			outlineStyle,
			internalFill,
			outlinePath,
			GraphicsUtil.END_FILL,
			GraphicsUtil.END_STROKE
		]);
		graphics.drawGraphicsData(data);
	}

	private function drawFill(graphics: Graphics) {
		var boxFill: GraphicsSolidFill = new GraphicsSolidFill(0xFFFFFF, 1);
		var boxPath: GraphicsPath = new GraphicsPath();
		GraphicsUtil.drawCutEdgeRect(4, 4, WIDTH - 8, HEIGHT - 8, 2, GraphicsUtil.ALL_CUTS, boxPath);
		var data: Vector<IGraphicsData> = new Vector<IGraphicsData>(0, false, [boxFill, boxPath, GraphicsUtil.END_FILL]);
		graphics.drawGraphicsData(data);
	}
}
