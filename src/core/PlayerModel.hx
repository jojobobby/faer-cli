package core;

import appengine.SavedCharacter;
import appengine.SavedCharactersList;
import servers.LatLong;
import util.Signal;

class PlayerModel {
	public var gemsChanged = new Signal<Int>();
	public var goldChanged = new Signal<Int>();
	public var crownsChanged = new Signal<Int>();

	public var charList: SavedCharactersList;
	public var isInvalidated = false;
	public var currentCharId = 0;

	public function new() {
		this.isInvalidated = true;
	}

	public function getMaxCharacters() {
		return this.charList?.maxNumChars ?? 0;
	}

	public function setMaxCharacters(value: Int) {
		if (this.charList == null)
			return;

		this.charList.maxNumChars = value;
	}

	public function getGems() {
		return this.charList?.gems ?? 0;
	}

	public function addGems(gems: Int) {
		if (this.charList == null)
			return;

		this.charList.gems += gems;
		this.gemsChanged.emit(this.charList.gems);
	}

	public function setGems(gems: Int) {
		if (this.charList?.gems != gems) {
			this.charList.gems = gems;
			this.gemsChanged.emit(gems);
		}
	}

	public function getGold() {
		return this.charList?.gold ?? 0;
	}

	public function addGold(gold: Int) {
		if (this.charList == null)
			return;

		this.charList.gold += gold;
		this.goldChanged.emit(this.charList.gold);
	}

	public function setGold(gold: Int) {
		if (this.charList?.gold != gold) {
			this.charList.gold = gold;
			this.goldChanged.emit(gold);
		}
	}

	public function getCrowns() {
		return this.charList?.crowns ?? 0;
	}

	public function addCrowns(crowns: Int) {
		if (this.charList == null)
			return;

		this.charList.crowns += crowns;
		this.crownsChanged.emit(this.charList.crowns);
	}

	public function setCrowns(crowns: Int) {
		if (this.charList?.crowns != crowns) {
			this.charList.crowns = crowns;
			this.crownsChanged.emit(crowns);
		}
	}

	public function getCharacterCount() {
		return this.charList?.numChars ?? 0;
	}

	public function getCharById(characterId: Int) {
		return this.charList?.getCharById(characterId) ?? new SavedCharacter(Xml.parse(""), "Unknown");
	}

	public function deleteCharacter(characterId: Int) {
		if (this.charList == null)
			return;

		var savedChar = this.charList.getCharById(characterId);
		var idx = this.charList.savedChars.indexOf(savedChar);
		if (idx != -1) {
			this.charList.savedChars.splice(idx, 1);
			this.charList.numChars--;
		}
	}

	public function addCharacter(savedChar: SavedCharacter) {
		if (this.charList == null)
			return;

		var idx = this.charList.savedChars.indexOf(savedChar);
		if (idx == -1) {
			this.charList.savedChars.push(savedChar);
			this.charList.numChars++;
		}
	}

	public function getGuildName() {
		return this.charList?.guildName ?? "";
	}

	public function getGuildRank() {
		return this.charList?.guildRank ?? 0;
	}

	public function getNextCharSlotPrice() {
		return this.charList?.nextCharSlotPrice ?? 0;
	}

	public function getNextCharSlotCurrency() {
		return this.charList?.nextCharSlotCurrency ?? 0;
	}

	public function isNextCharSlotCurrencyGems() {
		return getNextCharSlotCurrency() == 1;
	}

	public function getNextCharId() {
		return this.charList?.nextCharId ?? 0;
	}

	public function getCharacterByIndex(idx: Int) {
		return this.charList?.savedChars[idx] ?? new SavedCharacter(Xml.parse(""), "Unknown");
	}

	public function isAdmin() {
		return this.charList?.isAdmin ?? false;
	}

	public function getMyPos() {
		return this.charList?.myPos ?? new LatLong(0, 0);
	}

	public function getName() {
		return this.charList?.name ?? "Unknown";
	}

	public function hasAvailableCharSlot() {
		return this.charList?.hasAvailableCharSlot() ?? false;
	}

	public function getAvailableCharSlots() {
		return this.charList?.availableCharSlots() ?? 0;
	}

	public function getSavedCharacters() {
		return this.charList?.savedChars ?? new Array<SavedCharacter>();
	}

	public function setCharacterList(savedCharactersList: SavedCharactersList) {
		this.charList = savedCharactersList;
	}
}
