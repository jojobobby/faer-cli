package classes.model;

import haxe.ds.IntMap;

class CharacterSkins {
	private var skins: Array<CharacterSkin> = new Array<CharacterSkin>();

	private var map: IntMap<CharacterSkin> = new IntMap<CharacterSkin>();
	private var defaultSkin: CharacterSkin;
	private var selectedSkin: CharacterSkin;

	public function new() {}

	public function getCount() {
		return this.skins.length;
	}

	public function getDefaultSkin(): CharacterSkin {
		return this.defaultSkin;
	}

	public function getSelectedSkin(): CharacterSkin {
		return this.selectedSkin;
	}

	public function getSkinAt(index: Int): CharacterSkin {
		return this.skins[index];
	}

	public function addSkin(skin: CharacterSkin, isDefault: Bool = false) {
		skin.changed.on(this.onSkinChanged);
		this.skins.push(skin);
		this.map.set(skin.id, skin);
		updateSkinState(skin);
		if (isDefault) {
			this.defaultSkin = skin;
			if (this.selectedSkin == null) {
				this.selectedSkin = skin;
				skin.setIsSelected(true);
			}
		} else if (skin.getIsSelected())
			this.selectedSkin = skin;
	}

	public function getSkin(id: Int): CharacterSkin {
		return this.map.exists(id) ? this.map.get(id) : this.defaultSkin;
	}

	private function onSkinChanged(skin: CharacterSkin) {
		if (skin.getIsSelected() && this.selectedSkin != skin) {
			this.selectedSkin?.setIsSelected(false);
			this.selectedSkin = skin;
		}
	}

	private static function updateSkinState(skin: CharacterSkin) {
		if (skin.getState() != CharacterSkinState.OWNED)
			skin.setState(CharacterSkinState.PURCHASABLE);
	}
}
