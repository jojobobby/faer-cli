package screens;

import openfl.display.Sprite;
import openfl.events.MouseEvent;
import servers.Server;
import util.Settings;

class ServerBoxes extends Sprite {
	private var boxes: Array<ServerBox>;

	public function new(servers: Array<Server>) {
		super();

		var serverBox: ServerBox;
		var i: Int = 2;
		this.boxes = new Array<ServerBox>();
		serverBox = new ServerBox(null);
		serverBox.setSelected(true);
		serverBox.x = ServerBox.WIDTH / 2 + 2;
		serverBox.addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		addChild(serverBox);
		this.boxes.push(serverBox);
		for (server in servers) {
			serverBox = new ServerBox(server);
			if (server.name == Settings.selectedServer)
				this.setSelected(serverBox);

			serverBox.x = i % 2 * (ServerBox.WIDTH + 4);
			serverBox.y = Std.int(i / 2) * (ServerBox.HEIGHT + 4);
			serverBox.addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
			addChild(serverBox);
			this.boxes.push(serverBox);
			i++;
		}
	}

	private function setSelected(serverBox: ServerBox) {
		for (otherServerBox in this.boxes)
			otherServerBox.setSelected(false);

		serverBox.setSelected(true);
	}

	private function onMouseDown(event: MouseEvent) {
		var serverBox = cast(event.target, ServerBox);
		this.setSelected(serverBox);
		Settings.selectedServer = serverBox.value;
		Settings.save();
	}
}
