package mapeditor;

import util.Utils;

class MECommandMenu extends CommandMenu {
	public static inline var NONE_COMMAND = 0;
	public static inline var DRAW_COMMAND = 1;
	public static inline var ERASE_COMMAND = 2;
	public static inline var SAMPLE_COMMAND = 3;
	public static inline var FILL_COMMAND = 4;
	public static inline var RANDOM_COMMAND = 5;

	public function new() {
		super();
		addCommandMenuItem("(D)raw", KeyCode.D, this.select, DRAW_COMMAND);
		addCommandMenuItem("(E)rase", KeyCode.E, this.select, ERASE_COMMAND);
		addCommandMenuItem("S(A)mple", KeyCode.A, this.select, SAMPLE_COMMAND);
		addCommandMenuItem("(F)ill", KeyCode.F, this.select, FILL_COMMAND);
		addCommandMenuItem("Ra(N)dom", KeyCode.N, this.select, RANDOM_COMMAND);
		addCommandMenuItem("(U)ndo", KeyCode.U, this.onUndo, NONE_COMMAND);
		addCommandMenuItem("(R)edo", KeyCode.R, this.onRedo, NONE_COMMAND);
		addCommandMenuItem("(C)lear", KeyCode.C, this.onClear, NONE_COMMAND);
		addBreak();
		addCommandMenuItem("(L)oad", KeyCode.L, this.onLoad, NONE_COMMAND);
		addCommandMenuItem("(S)ave", KeyCode.S, this.onSave, NONE_COMMAND);
		addCommandMenuItem("(T)est", KeyCode.T, this.onTest, NONE_COMMAND);
		addBreak();
		addCommandMenuItem("Quit", KeyCode.Unset, this.onQuit, NONE_COMMAND);
	}

	private function select(item: CommandMenuItem) {
		setSelected(item);
	}

	private function onUndo(_: CommandMenuItem) {
		dispatchEvent(new CommandEvent(CommandEvent.UNDO_COMMAND_EVENT));
	}

	private function onRedo(_: CommandMenuItem) {
		dispatchEvent(new CommandEvent(CommandEvent.REDO_COMMAND_EVENT));
	}

	private function onClear(_: CommandMenuItem) {
		dispatchEvent(new CommandEvent(CommandEvent.CLEAR_COMMAND_EVENT));
	}

	private function onLoad(_: CommandMenuItem) {
		dispatchEvent(new CommandEvent(CommandEvent.LOAD_COMMAND_EVENT));
	}

	private function onSave(_: CommandMenuItem) {
		dispatchEvent(new CommandEvent(CommandEvent.SAVE_COMMAND_EVENT));
	}

	private function onTest(_: CommandMenuItem) {
		dispatchEvent(new CommandEvent(CommandEvent.TEST_COMMAND_EVENT));
	}

	private function onQuit(_: CommandMenuItem) {
		dispatchEvent(new CommandEvent(CommandEvent.QUIT_COMMAND_EVENT));
	}
}
