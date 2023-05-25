package screens;

import openfl.display.Sprite;
import openfl.events.Event;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;

class AccountLoadingScreen extends Sprite {
	private var loadingText: SimpleText;

	public function new() {
		super();

		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
	}

	public function onAddedToStage(event: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);

		this.loadingText = new SimpleText(30, 0xFFFFFF, false, 0, 0);
		this.loadingText.setBold(true);
		this.loadingText.text = "Loading...";
		this.loadingText.updateMetrics();
		this.loadingText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4)];
		addChild(this.loadingText);

		stage.addEventListener(Event.RESIZE, onResize);
		onResize(null);
	}

	private function onResize(_: Event) {
		if (this.loadingText == null)
			return;

		this.loadingText.x = Main.stageWidth / 2 - this.loadingText.width / 2;
		this.loadingText.y = Main.stageHeight - 74;
	}
}
