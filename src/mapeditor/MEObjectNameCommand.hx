package mapeditor;
class MEObjectNameCommand extends Command {
	private var map: MEMap;
	private var x: Int;
	private var y: Int;
	private var oldName: String;
	private var newName: String;

	public function new(map: MEMap, x: Int, y: Int, oldName: String, newName: String) {
		super();
		this.map = map;
		this.x = x;
		this.y = y;
		this.oldName = oldName;
		this.newName = newName;
	}

	override public function execute() {
		this.map.modifyObjectName(this.x, this.y, this.newName);
	}

	override public function unexecute() {
		this.map.modifyObjectName(this.x, this.y, this.oldName);
	}
}