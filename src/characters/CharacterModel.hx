package characters;

import appengine.SavedCharacter;

class CharacterModel {
	private var selected: SavedCharacter;

	public function new() {}

	public function getCharacterCount() {
		return Global.playerModel.getCharacterCount();
	}

	public function getCharacter(characterId: Int): SavedCharacter {
		return Global.playerModel.getCharById(characterId);
	}

	public function deleteCharacter(characterId: Int) {
		Global.playerModel.deleteCharacter(characterId);
		if (this.selected.charId() == characterId)
			this.selected = null;
	}

	public function select(character: SavedCharacter) {
		this.selected = character;
	}

	public function getSelected(): SavedCharacter {
		return this.selected;
	}
}
