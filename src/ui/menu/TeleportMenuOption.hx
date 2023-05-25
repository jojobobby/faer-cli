package ui.menu;

import objects.Player;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.geom.ColorTransform;
import ui.SimpleText;
import util.AssetLibrary;

class TeleportMenuOption extends MenuOption {
	private static var inactiveCT: ColorTransform = new ColorTransform(84 / 255, 84 / 255, 84 / 255);

	private var player: Player;
	private var mouseOver = false;
	private var barText: SimpleText;
	private var barTextOrigWidth = 0;

	public function new(player: Player) {
		super(AssetLibrary.getImageFromSet("misc16", 27), 0xFFFFFF, "Teleport");
		this.player = player;
		this.barText = new SimpleText(18, 0xFFFFFF, false, 0, 0);
		this.barText.setBold(true);
		this.barText.text = "Teleport";
		this.barText.updateMetrics();
		this.barText.x = text.x;
		this.barText.y = text.y;
		this.barTextOrigWidth = Std.int(this.barText.width);
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	override public function onMouseOver(event: MouseEvent) {
		this.mouseOver = true;
	}

	override public function onMouseOut(event: MouseEvent) {
		this.mouseOver = false;
	}

	private function onAddedToStage(event: Event) {
		addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onRemovedFromStage(event: Event) {
		removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onEnterFrame(event: Event) {
		var msUtilTeleport: Int = this.player.msUntilTeleport();
		if (msUtilTeleport > 0) {
			if (!contains(this.barText))
				addChild(this.barText);

			this.barText.width = this.barTextOrigWidth * (1 - msUtilTeleport / Player.MS_BETWEEN_TELEPORT);
			setColorTransform(inactiveCT);
		} else {
			if (contains(this.barText))
				removeChild(this.barText);

			if (this.mouseOver)
				setColorTransform(MenuOption.mouseOverCT);
			else
				setColorTransform(null);
		}
	}
}
