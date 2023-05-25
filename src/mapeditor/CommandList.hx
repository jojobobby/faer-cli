package mapeditor;
class CommandList {
	private var list: Array<Command>;

	public function new() {
		this.list = new Array<Command>();
	}

	public function empty() {
		return this.list.length == 0;
	}

	public function addCommand(command: Command) {
		this.list.push(command);
	}

	public function execute() {
		for (command in this.list)
			command.execute();
	}

	public function unexecute() {
		for (command in this.list)
			command.unexecute();
	}
}