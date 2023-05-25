package servers;

class Server {
	public var name = "";
	public var address = "";
	public var port = 0;
	public var latLong: LatLong;
	public var usage = 0.0;
	public var isAdminOnly = false;

	public function new() {}

	public function setName(name: String): Server {
		this.name = name;
		return this;
	}

	public function setAddress(address: String): Server {
		this.address = address;
		return this;
	}

	public function setPort(port: Int): Server {
		this.port = port;
		return this;
	}

	public function setLatLong(latitude: Float, longitude: Float): Server {
		this.latLong = new LatLong(latitude, longitude);
		return this;
	}

	public function setUsage(usage: Float): Server {
		this.usage = usage;
		return this;
	}

	public function setIsAdminOnly(isAdminOnly: Bool): Server {
		this.isAdminOnly = isAdminOnly;
		return this;
	}

	public function priority() {
		if (this.isAdminOnly)
			return 2;

		if (this.isCrowded())
			return 1;

		return 0;
	}

	public function isCrowded() {
		return this.usage >= 0.66;
	}

	public function isFull() {
		return this.usage >= 1;
	}

	public function toString() {
		return "["
			+ this.name
			+ ": "
			+ this.address
			+ ":"
			+ this.port
			+ ":"
			+ this.latLong
			+ ":"
			+ this.usage
			+ ":"
			+ this.isAdminOnly
			+ "]";
	}
}
