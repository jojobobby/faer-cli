package screens;

import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import servers.Server;
import ui.SimpleText;

class ServerBox extends Sprite {
	public static inline var WIDTH: Int = 384;
	public static inline var HEIGHT: Int = 52;

	public var value = "";

	private var nameText: SimpleText;
	private var statusText: SimpleText;
	private var selected = false;
	private var over = false;

	public function new(server: Server) {
		super();

		var color = 0;
		var text: String = null;
		this.value = server == null ? null : server.name;
		this.nameText = new SimpleText(18, 0xFFFFFF, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.text = server == null ? "Best Server" : server.name;
		this.nameText.updateMetrics();
		this.nameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.nameText.x = 18;
		this.nameText.y = ServerBox.HEIGHT / 2 - this.nameText.height / 2;
		addChild(this.nameText);
		if (server != null) {
			color = 65280;
			text = "Normal";
			if (server.isFull()) {
				color = 0xFF0000;
				text = "Full";
			} else if (server.isCrowded()) {
				color = 0xFC8642;
				text = "Crowded";
			}
			this.statusText = new SimpleText(18, color, false, 0, 0);
			this.statusText.setBold(true);
			this.statusText.text = text;
			this.statusText.updateMetrics();
			this.statusText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
			this.statusText.x = WIDTH / 2 + (WIDTH / 4 - this.statusText.width / 2);
			this.statusText.y = ServerBox.HEIGHT / 2 - this.nameText.height / 2;
			addChild(this.statusText);
		}
		this.draw();
		addEventListener(MouseEvent.MOUSE_OVER, this.onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, this.onRollOut);
	}

	public function setSelected(selected: Bool) {
		this.selected = selected;
		this.draw();
	}

	private function draw() {
		graphics.clear();
		if (this.selected) {
			graphics.lineStyle(2, 0xFFFF8F);
		}
		graphics.beginFill(this.over ? 0x6B6B6B : 0x5C5C5C, 1);
		graphics.drawRect(0, 0, WIDTH, HEIGHT);
		if (this.selected) {
			graphics.lineStyle();
		}
	}

	private function onMouseOver(event: MouseEvent) {
		this.over = true;
		this.draw();
	}

	private function onRollOut(event: MouseEvent) {
		this.over = false;
		this.draw();
	}
}
