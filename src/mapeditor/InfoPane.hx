package mapeditor;

import objects.ObjectLibrary;
import map.RegionLibrary;
import map.GroundLibrary;
import util.GraphicsUtil;
import ui.SimpleText;
import openfl.display.CapsStyle;
import openfl.display.GraphicsPath;
import openfl.display.GraphicsSolidFill;
import openfl.display.GraphicsStroke;
import openfl.display.IGraphicsData;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.filters.DropShadowFilter;
import openfl.geom.Rectangle;
import openfl.text.StyleSheet;
import openfl.Vector;

class InfoPane extends Sprite {
	public static inline var WIDTH = 134;
	public static inline var HEIGHT = 150;
	private static inline var CSS_TEXT = ".in { margin-left:10px; text-indent: -10px; }";

	private var meMap: MEMap;
	private var rectText: SimpleText;
	private var typeText: SimpleText;
	private var path: GraphicsPath;
	private var graphicsData: Vector<IGraphicsData>;

	public function new(meMap: MEMap) {
		super();

		this.path = new GraphicsPath();
		this.graphicsData = new Vector<IGraphicsData>(0, false, [
			new GraphicsStroke(1, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3, new GraphicsSolidFill(16777215, 1)),
			new GraphicsSolidFill(3552822, 1),
			new GraphicsPath(),
			GraphicsUtil.END_FILL,
			GraphicsUtil.END_STROKE
		]);

		this.meMap = meMap;
		this.drawBackground();
		this.rectText = new SimpleText(12, 16777215, false, WIDTH - 10, 0);
		this.rectText.filters = [new DropShadowFilter(0, 0, 0)];
		this.rectText.y = 4;
		this.rectText.x = 4;
		addChild(this.rectText);
		var sheet: StyleSheet = new StyleSheet();
		sheet.parseCSS(CSS_TEXT);
		this.typeText = new SimpleText(12, 16777215, false, WIDTH - 10, 0);
		this.typeText.styleSheet = sheet;
		this.typeText.wordWrap = true;
		this.typeText.filters = [new DropShadowFilter(0, 0, 0)];
		this.typeText.x = 4;
		this.typeText.y = 36;
		addChild(this.typeText);
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	private function onAddedToStage(event: Event) {
		addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onRemovedFromStage(event: Event) {
		addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onEnterFrame(event: Event) {
		var mouseRectT: Rectangle = this.meMap.mouseRectT();
		this.rectText.text = "Position: " + mouseRectT.x + ", " + mouseRectT.y;
		if (mouseRectT.width > 1 || mouseRectT.height > 1)
			this.rectText.text += ("\nRect: " + mouseRectT.width + ", " + mouseRectT.height);
		
		this.rectText.useTextDimensions();
		var tile = this.meMap.getTile(Std.int(mouseRectT.x), Std.int(mouseRectT.y));
		var types = tile == null ? Layer.EMPTY_TILE : tile.types;
		var groundId = types[Layer.GROUND] == 65535 ? "None" : GroundLibrary.getIdFromType(types[Layer.GROUND]);
		var objectId = types[Layer.OBJECT] == 65535 ? "None" : ObjectLibrary.getIdFromType(types[Layer.OBJECT]);
		var regionId = types[Layer.REGION] == 255 ? "None" : RegionLibrary.getIdFromType(types[Layer.REGION]);
		this.typeText.text = "<span class=\'in\'>"
			+ "Ground: "
			+ groundId
			+ "\nObject: "
			+ objectId
			+ "\nRegion: "
			+ regionId
			+ "</span>";
		this.typeText.useTextDimensions();
	}

	private function drawBackground() {
		GraphicsUtil.clearPath(this.path);
		GraphicsUtil.drawCutEdgeRect(0, 0, WIDTH, HEIGHT, 4, [1, 1, 1, 1], this.path);
		this.graphicsData[2] = this.path;
		graphics.drawGraphicsData(this.graphicsData);
	}
}
