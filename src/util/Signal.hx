package util;

class EmptySignal {
	final listeners: Array<() -> Void> = [];

	public function new() {}

	public function on(listener: () -> Void) {
		listeners.push(listener);
	}

	public function once(listener: () -> Void) {
		listeners.push(function wrapped() {
			listeners.remove(wrapped);
			listener();
		});
	}

	public function off(?listener: () -> Void) {
		if (listener != null)
			listeners.remove(listener);
		else
			listeners.resize(0);
	}

	public function emit() {
		for (listener in listeners)
			listener();
	}
}

class Signal<T> {
	final listeners: Array<T -> Void> = [];

	public function new() {}

	public function on(listener: T -> Void) {
		listeners.push(listener);
	}

	public function once(listener: T -> Void) {
		listeners.push(function wrapped(data: T) {
			listeners.remove(wrapped);
			listener(data);
		});
	}

	public function off(?listener: T -> Void) {
		if (listener != null)
			listeners.remove(listener);
		else
			listeners.resize(0);
	}

	public function emit(?data: T) {
		for (listener in listeners)
			listener(data);
	}
}