package map;

import lime.system.System;
import objects.GameObject;

class Quest {
	public var map: Map;
	public var objectId: Int = -1;

	private var questAvailableAt = 0;
	private var questOldAt = 0;

	public function new(map: Map) {
		this.map = map;
	}

	public function setObject(objectId: Int) {
		if (this.objectId == -1 && objectId != -1) {
			this.questAvailableAt = System.getTimer() + 4000;
			this.questOldAt = this.questAvailableAt + 2000;
		}
		this.objectId = objectId;
	}

	public function completed() {
		this.questAvailableAt = Std.int(System.getTimer() + 15000 - Math.random() * 10000);
		this.questOldAt = this.questAvailableAt + 2000;
	}

	public function getObject(time: Int) {
		if (time < this.questAvailableAt)
			return null;

		return this.map.getGameObject(this.objectId);
	}

	public function isNew(time: Int) {
		return time < this.questOldAt;
	}
}
