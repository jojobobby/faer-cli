package classes.model;

import assets.CharacterTemplate;
import util.Signal;

class CharacterSkin {
	public var changed = new Signal<CharacterSkin>();
	public var id = 0;
	public var name = "";
	public var template: CharacterTemplate;
	public var cost = 0;

	private var state: CharacterSkinState;
	private var isSelected = false;

	public function new() {
		this.state = CharacterSkinState.NULL;
	}

	public function getIsSelected() {
		return this.isSelected;
	}

	public function setIsSelected(value: Bool) {
		if (this.isSelected != value) {
			this.isSelected = value;
			this.changed.emit(this);
		}
	}

	public function getState(): CharacterSkinState {
		return this.state;
	}

	public function setState(value: CharacterSkinState) {
		if (this.state != value) {
			this.state = value;
			this.changed.emit(this);
		}
	}
}
