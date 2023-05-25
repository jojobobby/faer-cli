package ui.guild;
import network.NetworkHandler;
import game.events.GuildResultEvent;
import game.GameSprite;
import objects.Player;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.MouseEvent;
import screens.TitleMenuOption;
import ui.dialogs.Dialog;

class GuildChronicleScreen extends Sprite {
	private var gs: GameSprite;
	private var guildPlayerList: GuildPlayerList;
	private var continueButton: TitleMenuOption;

	public function new(gs: GameSprite) {
		super();

		this.gs = gs;
		graphics.clear();
		graphics.beginFill(2829099, 0.8);
		graphics.drawRect(0, 0, 800, 600);
		graphics.endFill();
		this.addList();
		this.continueButton = new TitleMenuOption("continue", 36, false);
		this.continueButton.addEventListener(MouseEvent.CLICK, this.onContinueClick);
		addChild(this.continueButton);
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	private function addList() {
		var player: Player = this.gs.map.player;
		this.guildPlayerList = new GuildPlayerList(50, 0, player == null ? "" : player.name, player.guildRank);
		this.guildPlayerList.addEventListener(GuildPlayerListEvent.SET_RANK, this.onSetRank);
		this.guildPlayerList.addEventListener(GuildPlayerListEvent.REMOVE_MEMBER, this.onRemoveMember);
		addChild(this.guildPlayerList);
	}

	private function removeList() {
		this.guildPlayerList.removeEventListener(GuildPlayerListEvent.SET_RANK, this.onSetRank);
		this.guildPlayerList.removeEventListener(GuildPlayerListEvent.REMOVE_MEMBER, this.onRemoveMember);
		removeChild(this.guildPlayerList);
	}

	private function showError(errorText: String) {
		var dialog: Dialog = new Dialog(errorText, "Error", "Ok", null);
		dialog.addEventListener(Dialog.BUTTON1_EVENT, this.onErrorTextDone);
		stage.addChild(dialog);
	}

	private function close() {
		stage.focus = null;
		parent.removeChild(this);
	}

	private function onSetRank(event: GuildPlayerListEvent) {
		this.removeList();
		this.gs.addEventListener(GuildResultEvent.EVENT, this.onSetRankResult);
		NetworkHandler.changeGuildRank(event.name, event.rank);
	}

	private function onSetRankResult(event: GuildResultEvent) {
		this.gs.removeEventListener(GuildResultEvent.EVENT, this.onSetRankResult);
		if (!event.success)
			this.showError(event.errorText);
		else
			this.addList();
	}

	private function onRemoveMember(event: GuildPlayerListEvent) {
		this.removeList();
		this.gs.addEventListener(GuildResultEvent.EVENT, this.onRemoveResult);
		NetworkHandler.guildRemove(event.name);
	}

	private function onRemoveResult(event: GuildResultEvent) {
		this.gs.removeEventListener(GuildResultEvent.EVENT, this.onRemoveResult);
		if (!event.success)
			this.showError(event.errorText);
		else
			this.addList();
	}

	private function onErrorTextDone(event: Event) {
		var dialog: Dialog = cast(event.currentTarget, Dialog);
		stage.removeChild(dialog);
		this.addList();
	}

	private function onContinueClick(event: MouseEvent) {
		this.close();
	}

	private function onAddedToStage(event: Event) {
		this.continueButton.x = stage.stageWidth / 2 - this.continueButton.width / 2;
		this.continueButton.y = 520;
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown, false, 1);
		stage.addEventListener(KeyboardEvent.KEY_UP, onKeyUp, false, 1);
	}

	private function onRemovedFromStage(event: Event) {
		stage.removeEventListener(KeyboardEvent.KEY_DOWN, onKeyDown, false);
		stage.removeEventListener(KeyboardEvent.KEY_UP, onKeyUp, false);
	}

	private static function onKeyDown(event: KeyboardEvent) {
		event.stopImmediatePropagation();
	}

	private static function onKeyUp(event: KeyboardEvent) {
		event.stopImmediatePropagation();
	}
}
