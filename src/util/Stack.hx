package util;

class Cell<T> {
	public var elt:T;
	public var next:Cell<T>;

	public function new(elt, next) {
		this.elt = elt;
		this.next = next;
	}
}

private class StackIterator<T> extends cpp.FastIterator<T> {
	public var current:Cell<T>;

	override public function hasNext():Bool {
		return current != null;
	}

	override public function next():T {
		var result = current.elt;
		current = current.next;
		return result;
	}

	public function new(head) {
		current = head;
	}
}

class Stack<T> {
	public var head:Cell<T>;

	public function new() {}

	public inline function add(item:T) {
		head = new Cell<T>(item, head);
	}

	public inline function first():Null<T> {
		return if (head == null) null else head.elt;
	}

	public inline function pop():Null<T> {
		var k = head;
		if (k == null)
			return null;
		else {
			head = k.next;
			return k.elt;
		}
	}

	public inline function isEmpty():Bool {
		return (head == null);
	}

	public function remove(v:T):Bool {
		var prev:Cell<T> = null;
		var l = head;
		while (l != null) {
			if (l.elt == v) {
				if (prev == null)
					head = l.next;
				else
					prev.next = l.next;
				break;
			}
			prev = l;
			l = l.next;
		}
		return (l != null);
	}

	public function iterator():Iterator<T> {
		return new StackIterator<T>(head);
	}
}
