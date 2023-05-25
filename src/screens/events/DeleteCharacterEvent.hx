package screens.events;
import appengine.SavedCharacter;
import openfl.events.Event;

class DeleteCharacterEvent extends Event {
	public static inline var DELETE_CHARACTER_EVENT: String = "DELETE_CHARACTER_EVENT";
	public var savedChar: SavedCharacter;

	public function new(savedChar: SavedCharacter) {
		super(DELETE_CHARACTER_EVENT);
		this.savedChar = savedChar;
	}
}