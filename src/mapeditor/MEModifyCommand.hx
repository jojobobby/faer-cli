package mapeditor;
class MEModifyCommand extends Command {
	private var map: MEMap;
	private var x: Int;
	private var y: Int;
	private var layer: Int;
	private var oldType: Int;
	private var newType: Int;

	public function new(map: MEMap, x: Int, y: Int, layer: Int, oldType: Int, type: Int) {
		super();
		this.map = map;
		this.x = x;
		this.y = y;
		this.layer = layer;
		this.oldType = oldType;
		this.newType = type;
	}

	override public function execute() {
		this.map.modifyTile(this.x, this.y, this.layer, this.newType);
	}

	override public function unexecute() {
		this.map.modifyTile(this.x, this.y, this.layer, this.oldType);
	}
}
