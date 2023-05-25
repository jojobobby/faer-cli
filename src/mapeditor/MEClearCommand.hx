package mapeditor;
class MEClearCommand extends Command {
	private var map: MEMap;
	private var x: Int;
	private var y: Int;
	private var oldTile: METile;

	public function new(map: MEMap, x: Int, y: Int, oldTile: METile) {
		super();
		this.map = map;
		this.x = x;
		this.y = y;
		this.oldTile = oldTile.clone();
	}

	override public function execute() {
		this.map.eraseTile(this.x, this.y);
	}

	override public function unexecute() {
		this.map.setTile(this.x, this.y, this.oldTile);
	}
}