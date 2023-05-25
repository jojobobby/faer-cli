package ui.guild;

import openfl.events.Event;

class GuildPlayerListEvent extends Event {
	public static inline var SET_RANK: String = "SET_RANK";
	public static inline var REMOVE_MEMBER: String = "REMOVE_MEMBER";

	public var name = "";
	public var rank = 0;

	public function new(eventType: String, name: String, rank: Int = -1) {
		super(eventType, true);
		this.name = name;
		this.rank = rank;
	}
}
