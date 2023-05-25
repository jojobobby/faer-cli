package ui.view;

import account.services.UploadXmlTask;
import account.services.UploadBehaviorTask;
import openfl.events.IOErrorEvent;
import haxe.Exception;
import openfl.net.FileFilter;
import openfl.net.FileReference;
#if !disable_rpc
import hxdiscord_rpc.Discord;
import hxdiscord_rpc.Types;
#end
import mapeditor.MapEditor;
import account.Account;
import util.Settings;
import account.view.AccountDetailDialog;
import account.view.RegisterDialog;
import game.model.GameInitData;
import openfl.display.Sprite;
import openfl.events.Event;
import screens.AccountScreen;
import screens.CharacterSelectionScreen;
import screens.ServersScreen;
import screens.TitleMenuOption;
import ui.dialogs.Dialog;
import ui.SoundIcon;
import ui.view.MapBackground;
import util.Signal;

class TitleView extends Sprite {
	public var playClicked: EmptySignal;
	public var serversClicked: EmptySignal;
	public var accountClicked: EmptySignal;
	public var editorClicked: EmptySignal;
	public var behaviorClicked: EmptySignal;
	public var xmlClicked: EmptySignal;

	private var container: Sprite;
	private var playButton: TitleMenuOption;
	private var serversButton: TitleMenuOption;
	private var accountButton: TitleMenuOption;
	private var editorButton: TitleMenuOption;
	private var behaviorButton: TitleMenuOption;
	private var xmlButton: TitleMenuOption;

	public function new() {
		super();

		addChild(new MapBackground());
		addChild(new AccountScreen());
		this.makeChildren();
		addChild(new SoundIcon());
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		#if !disable_rpc
		if (Main.rpcReady) {
			var discordPresence = DiscordRichPresence.create();
			discordPresence.state = 'Main Menu';
			discordPresence.details = '';
			discordPresence.largeImageKey = 'logo';
			discordPresence.largeImageText = 'v${Settings.BUILD_VERSION}';
			discordPresence.startTimestamp = Main.startTime;
			Discord.UpdatePresence(cpp.RawConstPointer.addressOf(discordPresence));
		}
		#end

		this.initialize();
		this.playClicked.on(handleIntentionToPlay);
		this.serversClicked.on(showServersScreen);
		this.accountClicked.on(handleIntentionToReviewAccount);
		this.editorClicked.on(showEditorScreen);
		this.behaviorClicked.on(dispatchBehaviorRequest);
		this.xmlClicked.on(dispatchXmlRequest);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.playClicked.off(handleIntentionToPlay);
		this.serversClicked.off(showServersScreen);
		this.accountClicked.off(handleIntentionToReviewAccount);
		this.editorClicked.off(showEditorScreen);
		this.behaviorClicked.off(dispatchBehaviorRequest);
		this.xmlClicked.off(dispatchXmlRequest);
	}

	private static function handleIntentionToPlay() {
		if (!Global.serverModel.isServerAvailable()) {
			var dialog = new Dialog("Faer is currently offline.\n\n"
				+ "Visit our discord for more information:\n"
				+ "<font color=\"#7777EE\"><a href=\"https://discord.gg/2XdgUW29rw\">discord.gg/mUPuzKtajq</a></font>.",
				"Server Offline", "Close", null);
			dialog.addEventListener(Dialog.BUTTON1_EVENT, (_: Event) -> {
				Global.layers.dialogs.closeDialogs();
			});
			Global.layers.dialogs.openDialog(dialog);
		}
		else {
			if (Account.password == "") {
				var data = new GameInitData();
				data.createCharacter = true;
				data.charId = Global.playerModel.getNextCharId();
				data.gameId = Settings.HUB_GAMEID;
			} else
				Global.setScreenValid(new CharacterSelectionScreen());
		}
	}

	private static function showServersScreen() {
		Global.layers.screens.setScreen(new ServersScreen());
	}

	private static function showEditorScreen() {
		Global.layers.screens.setScreen(Global.currentEditor = new MapEditor());
	}

	private static function handleIntentionToReviewAccount() {
		if (Account.password != "")
			Global.layers.dialogs.openDialog(new AccountDetailDialog());
		else
			Global.layers.dialogs.openDialog(new RegisterDialog());
	}

	private static function dispatchBehaviorRequest() {
		var loadedFile = new FileReference();
		loadedFile.addEventListener(Event.SELECT, (_: Event) -> {
			loadedFile.addEventListener(Event.COMPLETE, (_: Event) -> {
				UploadBehaviorTask.data = loadedFile.data.toString();
				UploadBehaviorTask.name = loadedFile.name;
				Global.uploadBehaviorTask.startTask();
			});
			loadedFile.addEventListener(IOErrorEvent.IO_ERROR, (e: IOErrorEvent) -> {
				var dialog = new Dialog('${e.toString()}', 'File IO Error', "Close", null);
				dialog.addEventListener(Dialog.BUTTON1_EVENT, (_: Event) -> {
					Global.layers.dialogs.closeDialogs();
				});
				Global.layers.dialogs.openDialog(dialog);
				trace('File IO error: ${e.toString()}');
			});
			try {
				loadedFile.load();
			} catch (e: Exception) {
				var dialog = new Dialog('${e.details()}', 'File Load Error', "Close", null);
				dialog.addEventListener(Dialog.BUTTON1_EVENT, (_: Event) -> {
					Global.layers.dialogs.closeDialogs();
				});
				Global.layers.dialogs.openDialog(dialog);
				trace('File load error: ${e.details()}, stack trace: ${e.stack}');
			}
		});
		loadedFile.browse([new FileFilter("XML Files (*.xml)", "*.xml")]);
	}

	private static function dispatchXmlRequest() {
		var loadedFile = new FileReference();
		loadedFile.addEventListener(Event.SELECT, (_: Event) -> {
			loadedFile.addEventListener(Event.COMPLETE, (_: Event) -> {
				UploadXmlTask.data = loadedFile.data.toString();
				UploadXmlTask.name = loadedFile.name;
				Global.uploadXmlTask.startTask();
				
			});
			loadedFile.addEventListener(IOErrorEvent.IO_ERROR, (e: IOErrorEvent) -> {
				var dialog = new Dialog('${e.toString()}', 'File IO Error', "Close", null);
				dialog.addEventListener(Dialog.BUTTON1_EVENT, (_: Event) -> {
					Global.layers.dialogs.closeDialogs();
				});
				Global.layers.dialogs.openDialog(dialog);
				trace('File IO error: ${e.toString()}');
			});
			try {
				loadedFile.load();
			} catch (e: Exception) {
				var dialog = new Dialog('${e.details()}', 'File Load Error', "Close", null);
				dialog.addEventListener(Dialog.BUTTON1_EVENT, (_: Event) -> {
					Global.layers.dialogs.closeDialogs();
				});
				Global.layers.dialogs.openDialog(dialog);
				trace('File load error: ${e.details()}, stack trace: ${e.stack}');
			}
		});
		loadedFile.browse([new FileFilter("XML Files (*.xml)", "*.xml")]);
	}

	public function initialize() {
		this.positionButtons();
		this.addChildren();
	}

	private function makeChildren() {
		this.container = new Sprite();
		this.playButton = new TitleMenuOption("play", 36, true);
		this.playClicked = this.playButton.clicked;
		this.container.addChild(this.playButton);
		this.serversButton = new TitleMenuOption("servers", 22, false);
		this.serversClicked = this.serversButton.clicked;
		this.container.addChild(this.serversButton);
		this.accountButton = new TitleMenuOption("account", 22, false);
		this.accountClicked = this.accountButton.clicked;
		this.container.addChild(this.accountButton);
		this.editorButton = new TitleMenuOption("editor", 22, false);
		this.editorClicked = this.editorButton.clicked;
		this.container.addChild(this.editorButton);
		this.behaviorButton = new TitleMenuOption("upload behaviors", 22, false);
		this.behaviorClicked = this.behaviorButton.clicked;
		this.container.addChild(this.behaviorButton);
		this.xmlButton = new TitleMenuOption("upload xmls", 22, false);
		this.xmlClicked = this.xmlButton.clicked;
		this.container.addChild(this.xmlButton);
	}

	private function addChildren() {
		addChild(this.container);
	}

	private function positionButtons() {
		this.playButton.x = stage.stageWidth / 2 - this.playButton.width / 2;
		this.playButton.y = stage.stageHeight - 80;
		this.serversButton.x = stage.stageWidth / 2 - this.serversButton.width / 2 - 94;
		this.serversButton.y = stage.stageHeight - 68;
		this.editorButton.x = stage.stageWidth / 2 - this.editorButton.width / 2 - 94 - 94;
		this.editorButton.y = stage.stageHeight - 68;
		this.accountButton.x = stage.stageWidth / 2 - this.accountButton.width / 2 + 96;
		this.accountButton.y = stage.stageHeight - 68;
		this.behaviorButton.x = stage.stageWidth / 2 - this.behaviorButton.width / 2 - 94 - 94 - 94 - 40;
		this.behaviorButton.y = stage.stageHeight - 68;
		this.xmlButton.x = stage.stageWidth / 2 - this.xmlButton.width / 2 + 96 + 96 + 20;
		this.xmlButton.y = stage.stageHeight - 68;
	}
}
