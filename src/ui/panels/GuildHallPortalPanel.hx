package ui.panels;
import network.NetworkHandler;
import game.GameSprite;
import objects.GuildHallPortal;
import objects.Player;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import ui.SimpleText;
import ui.TextBox;
import ui.TextButton;
import util.Settings;

class GuildHallPortalPanel extends Panel {
	private var owner: GuildHallPortal;
	private var nameText: SimpleText;
	private var enterButton: TextButton;
	private var noGuildText: SimpleText;

	public function new(gs: GameSprite, owner: GuildHallPortal) {
		super(gs);
		this.owner = owner;
		if (gs.map == null || gs.map.player == null)
			return;

		var p: Player = gs.map.player;
		this.nameText = new SimpleText(18, 0xFFFFFF, false, Panel.WIDTH, 0);
		this.nameText.setBold(true);
		this.nameText.htmlText = "<p align=\"center\">Guild Hall</p>";
		this.nameText.wordWrap = true;
		this.nameText.multiline = true;
		this.nameText.autoSize = TextFieldAutoSize.CENTER;
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		this.nameText.y = 6;
		addChild(this.nameText);
		if (p.guildName != null && p.guildName.length > 0) {
			this.enterButton = new TextButton(16, "Enter");
			this.enterButton.addEventListener(MouseEvent.CLICK, this.onEnterSpriteClick);
			this.enterButton.x = Panel.WIDTH / 2 - this.enterButton.width / 2;
			this.enterButton.y = Panel.HEIGHT - this.enterButton.height - 4;
			addChild(this.enterButton);
			addEventListener(Event.ADDED_TO_STAGE, this.onAdded);
			addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
		} else {
			this.noGuildText = new SimpleText(18, 0xFF0000, false, Panel.WIDTH, 0);
			this.noGuildText.setBold(true);
			this.noGuildText.htmlText = "<p align=\"center\">Not In Guild</p>";
			this.noGuildText.autoSize = TextFieldAutoSize.CENTER;
			this.noGuildText.filters = [new DropShadowFilter(0, 0, 0)];
			this.noGuildText.y = Panel.HEIGHT - this.noGuildText.height - 12;
			addChild(this.noGuildText);
		}
	}

	private function enterPortal() {
		NetworkHandler.usePortal(this.owner.objectId);
	}

	private function onAdded(event: Event) {
		stage.addEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
	}

	private function onRemovedFromStage(event: Event) {
		stage.removeEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
	}

	private function onEnterSpriteClick(event: MouseEvent) {
		this.enterPortal();
	}

	private function onKeyDown(event: KeyboardEvent) {
		if (event.keyCode == Settings.interact && !TextBox.isInputtingText)
			this.enterPortal();
	}
}
