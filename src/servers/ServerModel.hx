package servers;

import util.Utils;
import util.Settings;

class ServerModel {
	private var servers: Array<Server> = new Array<Server>();

	public function new() {}

	public function setServers(list: Array<Server>) {
		this.servers.splice(0, this.servers.length);
		for (server in list)
			this.servers.push(server);
	}

	public function getServers(): Array<Server> {
		return this.servers;
	}

	public function getServer(): Server {
		var priority = 0;
		var dist = 0.0;
		var isAdmin = Global.playerModel.isAdmin();
		var myLocation = Global.playerModel.getMyPos();
		var closestServer: Server = null;
		var minDist = MathUtil.FLOAT_MAX;
		var bestPriority = MathUtil.INT_MAX;
		for (server in this.servers) {
			if (!(server.isFull() && !isAdmin)) {
				if (server.name == Settings.selectedServer)
					return server;

				priority = server.priority();
				dist = LatLong.distance(myLocation, server.latLong);
				if (priority < bestPriority || priority == bestPriority && dist < minDist) {
					closestServer = server;
					minDist = dist;
					bestPriority = priority;
				}
			}
		}

		return closestServer;
	}

	public function isServerAvailable() {
		return this.servers.length > 0;
	}
}
