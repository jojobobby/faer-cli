package mapeditor;
import openfl.events.Event;

class CommandEvent extends Event {
	public static inline var UNDO_COMMAND_EVENT = "UNDO_COMMAND_EVENT";
	public static inline var REDO_COMMAND_EVENT = "REDO_COMMAND_EVENT";
	public static inline var CLEAR_COMMAND_EVENT = "CLEAR_COMMAND_EVENT";
	public static inline var LOAD_COMMAND_EVENT = "LOAD_COMMAND_EVENT";
	public static inline var SAVE_COMMAND_EVENT = "SAVE_COMMAND_EVENT";
	public static inline var TEST_COMMAND_EVENT = "TEST_COMMAND_EVENT";
	public static inline var QUIT_COMMAND_EVENT = "QUIT_COMMAND_EVENT";

	public function new(type: String) {
		super(type);
	}
}