package appengine;

import openfl.events.Event;
import servers.LatLong;

class SavedCharactersList extends Event {
	public static inline var SAVED_CHARS_LIST: String = "SAVED_CHARS_LIST";
	private static var DEFAULT_LATLONG: LatLong = new LatLong(37.4436, -122.412);

	public var accountId = 0;
	public var nextCharId = 0;
	public var maxNumChars = 0;
	public var numChars = 0;
	public var savedChars: Array<SavedCharacter>;
	public var gems = 0;
	public var gold = 0;
	public var crowns = 0;
	public var nextCharSlotPrice = 0;
	public var nextCharSlotCurrency = 0;
	public var guildName = "";
	public var guildRank = 0;
	public var name: String = null;
	public var isAdmin = false;
	public var myPos: LatLong;
	public var hasPlayerDied = false;

	private var charsXML: Xml;

	public function new(data: Xml) {
		this.savedChars = new Array<SavedCharacter>();
		super(SAVED_CHARS_LIST);
		this.charsXML = data;
		var accountXML: Xml = data.elementsNamed("Account").next();
		this.parseUserData(accountXML);
		this.parseGuildData(accountXML);
		this.parseCharacterData();
		this.parseGeoPositioningData();
	}

	override public function clone(): Event {
		return new SavedCharactersList(this.charsXML);
	}

	override public function toString() {
		return "[" + " numChars: " + this.numChars + " maxNumChars: " + this.maxNumChars + " ]";
	}

	public function getCharById(id: Int): SavedCharacter {
		var savedChar: SavedCharacter = null;
		for (savedChar in this.savedChars)
			if (savedChar.charId() == id)
				return savedChar;

		return null;
	}

	public function availableCharSlots() {
		return this.maxNumChars - this.numChars;
	}

	public function hasAvailableCharSlot() {
		return this.numChars < this.maxNumChars;
	}

	private function parseUserData(accountXML: Xml) {
		this.accountId = Std.parseInt(accountXML.elementsNamed("AccountId").next().firstChild().nodeValue);
		this.name = accountXML.elementsNamed("Name").next().firstChild().nodeValue;
		this.isAdmin = accountXML.elementsNamed("Admin").hasNext();
		//this.gems = Std.parseInt(accountXML.elementsNamed("Gems").next().firstChild().nodeValue);
		//this.gold = Std.parseInt(accountXML.elementsNamed("Gold").next().firstChild().nodeValue);
		//this.crowns = Std.parseInt(accountXML.elementsNamed("Crowns").next().firstChild().nodeValue);
		//this.nextCharSlotPrice = Std.parseInt(accountXML.elementsNamed("NextCharSlotPrice").next().firstChild().nodeValue);
		//this.nextCharSlotCurrency = Std.parseInt(accountXML.elementsNamed("NextCharSlotCurrency").next().firstChild().nodeValue);
		//this.hasPlayerDied = !accountXML.elementsNamed("isFirstDeath").hasNext();
	}

	private function parseGuildData(accountXML: Xml) {
		if (accountXML.elementsNamed("Guild").hasNext()
			&& accountXML.elementsNamed("Guild").next().elementsNamed("Name").hasNext()
			&& accountXML.elementsNamed("Guild").next().elementsNamed("Name").next().firstChild() != null) {
			this.guildName = accountXML.elementsNamed("Guild").next().elementsNamed("Name").next().firstChild().nodeValue;
			this.guildRank = Std.parseInt(accountXML.elementsNamed("Guild").next().elementsNamed("Rank").next().firstChild().nodeValue);
		}
	}

	private function parseCharacterData() {
		this.nextCharId = Std.parseInt(this.charsXML.get("nextCharId"));
		this.maxNumChars = Std.parseInt(this.charsXML.get("maxNumChars"));
		for (charXML in this.charsXML.elementsNamed("Char")) {
			this.savedChars.push(new SavedCharacter(charXML, this.name));
			this.numChars++;
		}

		this.savedChars.sort(SavedCharacter.compare);
	}

	private function parseGeoPositioningData() {
		if (this.charsXML.elementsNamed("Lat").hasNext() && this.charsXML.elementsNamed("Long").hasNext())
			this.myPos = new LatLong(Std.parseFloat(this.charsXML.elementsNamed("Lat").next().firstChild().nodeValue),
				Std.parseFloat(this.charsXML.elementsNamed("Long").next().firstChild().nodeValue));
		else
			this.myPos = DEFAULT_LATLONG;
	}
}
