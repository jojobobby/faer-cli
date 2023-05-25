package mapeditor;

class METile {
	public var types: Array<Int>;
	public var objName = "";

	public function new() {
		this.types = [65535, 65535, 255];
	}

	public function clone() {
		var tile = new METile();
		if (this.types.length > 0)
			tile.types = this.types.copy();
		tile.objName = this.objName;
		return tile;
	}

	public function isEmpty() {
		if (this.types[Layer.GROUND] != 65535)
			return false;
		if (this.types[Layer.OBJECT] != 65535)
			return false;
		if (this.types[Layer.REGION] != 255)
			return false;

		return true;
	}
}
