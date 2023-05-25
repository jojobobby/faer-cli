package ui.panels;
import network.NetworkHandler;
import game.GameSprite;
import objects.Player;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import ui.BuyButton;
import ui.CreateGuildFrame;
import ui.dialogs.Dialog;
import ui.FrameOverlay;
import ui.SimpleText;
import ui.TextButton;
import util.GuildUtil;

class FoundingTablePanel extends Panel {
	private var title: SimpleText;
	private var button: Sprite;

	public function new(gs: GameSprite) {
		var rankName: String = null;
		var buyButton: BuyButton = null;
		super(gs);
		if (gs.map == null || gs.map.player == null)
			return;

		var p: Player = gs.map.player;
		this.title = new SimpleText(18, 0xFFFFFF, false, Panel.WIDTH, 0);
		this.title.setBold(true);
		this.title.wordWrap = true;
		this.title.multiline = true;
		this.title.autoSize = TextFieldAutoSize.CENTER;
		this.title.filters = [new DropShadowFilter(0, 0, 0)];
		if (p.guildName != null && p.guildName.length > 0) {
			rankName = GuildUtil.rankToString(p.guildRank);
			this.title.htmlText = "<p align=\"center\">" + rankName + " of \n" + p.guildName + "</p>";
			this.title.y = 0;
			addChild(this.title);
			this.button = new TextButton(16, "Renounce");
			this.button.addEventListener(MouseEvent.CLICK, this.onRenounceClick);
			this.button.x = Panel.WIDTH / 2 - this.button.width / 2;
			this.button.y = Panel.HEIGHT - this.button.height - 4;
			addChild(this.button);
		} else {
			this.title.htmlText = "<p align=\"center\">Create a Guild</p>";
			this.title.y = 0;
			addChild(this.title);
			buyButton = new BuyButton("Create ", 16, 1000, 1);
			buyButton.addEventListener(MouseEvent.CLICK, this.onCreateClick);
			buyButton.x = Panel.WIDTH / 2 - buyButton.width / 2;
			buyButton.y = Panel.HEIGHT - buyButton.height / 2 - 31;
			addChild(buyButton);
			this.button = buyButton;
		}
	}

	public function onRenounceClick(event: MouseEvent) {
		if (gs.map == null || gs.map.player == null)
			return;

		var p: Player = gs.map.player;
		var renounceDialog: Dialog = new Dialog("Are you sure you want to quit:\n" + p.guildName, "Renounce Guild", "No, I\'ll stay", "Yes, I\'ll quit");
		renounceDialog.addEventListener(Dialog.BUTTON1_EVENT, this.onNoRenounce);
		renounceDialog.addEventListener(Dialog.BUTTON2_EVENT, this.onRenounce);
		stage.addChild(renounceDialog);
	}

	public function onCreateClick(event: MouseEvent) {
		var sprite: Sprite = new FrameOverlay(new CreateGuildFrame(gs));
		stage.addChild(sprite);
		visible = false;
	}

	private function onNoRenounce(event: Event) {
		stage.removeChild(cast(event.currentTarget, Dialog));
	}

	private function onRenounce(event: Event) {
		if (gs.map == null || gs.map.player == null)
			return;

		var p: Player = gs.map.player;
		NetworkHandler.guildRemove(p.name);
		stage.removeChild(cast(event.currentTarget, Dialog));
		visible = false;
	}
}
