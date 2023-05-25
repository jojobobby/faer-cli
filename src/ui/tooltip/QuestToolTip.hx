package ui.tooltip;
import objects.GameObject;
import openfl.filters.DropShadowFilter;
import ui.GameObjectListItem;
import ui.SimpleText;

class QuestToolTip extends ToolTip {
	public var enemyGOLI: GameObjectListItem;
	private var text: SimpleText;

	public function new(go: GameObject) {
		super(0x5C1D1D, 1, 0xFC8642, 1, false);
		this.text = new SimpleText(22, 0xFC8642, false, 0, 0);
		this.text.setBold(true);
		this.text.text = "Quest!";
		this.text.updateMetrics();
		this.text.filters = [new DropShadowFilter(0, 0, 0)];
		this.text.x = 0;
		this.text.y = 0;
		addChild(this.text);
		this.enemyGOLI = new GameObjectListItem(0xB3B3B3, true, go);
		this.enemyGOLI.x = 0;
		this.enemyGOLI.y = 32;
		addChild(this.enemyGOLI);
		filters = [];
	}
}