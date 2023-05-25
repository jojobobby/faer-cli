package ui;

import openfl.display.GraphicsPath;
import openfl.display.GraphicsPathWinding;
import openfl.display.GraphicsSolidFill;
import openfl.display.IGraphicsData;
import openfl.display.Shape;
import openfl.Vector;
import util.GraphicsUtil;

class LineBreakDesign extends Shape {
	private var designFill = new GraphicsSolidFill(0xFFFFFF, 1);
	private var designPath = new GraphicsPath(null, null, GraphicsPathWinding.NON_ZERO);
	private var designGraphicsData = new Vector<IGraphicsData>(0, false, [
		new GraphicsSolidFill(0xFFFFFF, 1),
		new GraphicsPath(null, null, GraphicsPathWinding.NON_ZERO),
		GraphicsUtil.END_FILL
	]);

	public function new(width: Int, color: Int) {
		super();

		this.setWidthColor(width, color);
	}

	public function setWidthColor(width: Int, color: Int) {
		graphics.clear();
		this.designFill.color = color;
		GraphicsUtil.clearPath(this.designPath);
		GraphicsUtil.drawDiamond(0, 0, 4, this.designPath);
		GraphicsUtil.drawDiamond(width, 0, 4, this.designPath);
		GraphicsUtil.drawRect(0, -1, width, 2, this.designPath);
		this.designGraphicsData[1] = this.designPath;
		graphics.drawGraphicsData(this.designGraphicsData);
	}
}
