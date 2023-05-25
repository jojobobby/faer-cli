package classes.model;

import util.NativeTypes;

class CharacterClass {
	public var skins: CharacterSkins = new CharacterSkins();
	public var id: Int32 = 0;
	public var name = "";
	public var description = "";
	public var hitSound = "";
	public var deathSound = "";
	public var bloodProb: Float32 = 0.0;
	public var slotTypes: Array<Int32>;
	public var defaultEquipment: Array<Int32>;

	private var isSelected = false;

	public function new() {}

	public function getIsSelected() {
		return this.isSelected;
	}

	public function setIsSelected(value: Bool) {
		if (this.isSelected != value) {
			this.isSelected = value;
			if (this.isSelected)
				Global.classModel.selectClass(this);
		}
	}
}
