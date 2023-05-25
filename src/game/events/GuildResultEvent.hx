package game.events;

import openfl.events.Event;

class GuildResultEvent extends Event {
	public static inline var EVENT: String = "GUILDRESULTEVENT";

	public var success = false;
	public var errorText = "";

	public function new(success: Bool, errorText: String) {
		super(EVENT);
		this.success = success;
		this.errorText = errorText;
	}

	override public function toString() {
		return formatToString("GUILDRESULTEVENT", "success", "errorText");
	}
}
