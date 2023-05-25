package mapeditor;
class CommandQueue {
	private var list: Array<CommandList>;
	private var currPos = 0;

	public function new() {
		this.list = new Array<CommandList>();
	}

	public function addCommandList(commandList: CommandList) {
		this.list.resize(this.currPos);
		commandList.execute();
		this.list.push(commandList);
		this.currPos++;
	}

	public function undo() {
		if (this.currPos == 0)
			return;
		
		this.list[--this.currPos].unexecute();
	}

	public function redo() {
		if (this.currPos == this.list.length)
			return;
		
		this.list[this.currPos++].execute();
	}

	public function clear() {
		this.currPos = 0;
		this.list.resize(0);
	}
}
