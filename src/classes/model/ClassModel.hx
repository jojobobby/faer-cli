package classes.model;

import haxe.ds.IntMap;
import util.Signal;

class ClassModel {
	public static inline var WIZARD_ID = 782;

	public var selected = new Signal<CharacterClass>();
	public var map: IntMap<CharacterClass>;

	private var classes: Array<CharacterClass> = new Array<CharacterClass>();
	private var count = 0;
	private var selectedChar: CharacterClass;

	public function new() {
		this.map = new IntMap<CharacterClass>();
	}

	public function getCount() {
		return this.count;
	}

	public function getClassAtIndex(index: Int) {
		return this.classes[index];
	}

	public function getCharacterClass(id: Int) {
		return this.map.get(id) ?? this.makeCharacterClass();
	}

	public function getSelected() {
		return this.selectedChar ?? this.getCharacterClass(WIZARD_ID);
	}

	public function getCharacterSkin(objType: Int) {
		var skin: CharacterSkin = null;
		for (character in this.classes) {
			skin = character.skins.getSkin(objType);
			if (skin != character.skins.getDefaultSkin())
				break;
		}

		return skin;
	}

	private function makeCharacterClass() {
		var character = new CharacterClass();
		this.count = this.classes.push(character);
		return character;
	}

	public function selectClass(charClass: CharacterClass) {
		if (this.selectedChar != charClass) {
			if (this.selectedChar != null)
				this.selectedChar.setIsSelected(false);
			this.selectedChar = charClass;
			this.selected.emit(charClass);
		}
	}
}
