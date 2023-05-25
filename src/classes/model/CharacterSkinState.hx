package classes.model;

class CharacterSkinState {
	public static var OWNED: CharacterSkinState = new CharacterSkinState(false, "OWNED");
	public static var PURCHASABLE: CharacterSkinState = new CharacterSkinState(true, "PURCHASABLE");
	public static var PURCHASING: CharacterSkinState = new CharacterSkinState(true, "PURCHASING");
	public static var LOCKED: CharacterSkinState = new CharacterSkinState(true, "LOCKED");
	public static var NULL: CharacterSkinState = new CharacterSkinState(true, "NULL");

	public var isDisabled = false;
	public var name = "";

	public function new(isDisabled: Bool, name: String) {
		this.isDisabled = isDisabled;
		this.name = name;
	}
}
