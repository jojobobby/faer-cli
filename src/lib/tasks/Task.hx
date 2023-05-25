package lib.tasks;

import haxe.Exception;
import util.Signal;

@:stackOnly
class TaskData {
	public var task: Task;
	public var success: Bool;
	public var error: String;

	public function new(task: Task, success: Bool, error: String) {
		this.task = task;
		this.success = success;
		this.error = error;
	}
}

class Task {
	public var started: Signal<Task>;
	public var finished: Signal<TaskData>;
	public var lastly: Signal<TaskData>;
	public var isStarted = false;
	public var isFinished = false;
	public var isOK = false;
	public var error = "";

	public function new() {
		this.started = new Signal<Task>();
		this.finished = this.lastly = new Signal<TaskData>();
	}

	public final function start() {
		if (!this.isStarted) {
			this.isStarted = true;
			this.started.emit(this);
			this.startTask();
		}
	}

	public final function reset() {
		if (this.isStarted) {
			this.isStarted = false;
			if (!this.isFinished)
				throw new Exception("Unable to Task.reset() when a task is ongoing");
		}

		this.started.off();
		this.finished.off();
		this.lastly.off();
		this.onReset();
	}

	public function startTask() {}

	public function onReset() {}

	public final function completeTask(isOK: Bool, error: String = "") {
		this.isOK = isOK;
		this.error = error;
		this.isFinished = true;

		this.finished.emit(new TaskData(this, isOK, error));
		this.lastly.emit(new TaskData(this, isOK, error));

		this.reset();
	}
}
