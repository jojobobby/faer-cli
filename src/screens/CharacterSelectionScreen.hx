package screens;

import appengine.RequestHandler;
import appengine.RequestHandler.CompletionData;
import lib.tasks.Task.TaskData;
#if !disable_rpc
import hxdiscord_rpc.Types;
import hxdiscord_rpc.Discord;
#end
import util.Settings;
import appengine.SavedCharacter;
import classes.model.CharacterClass;
import game.model.GameInitData;
import game.view.CurrencyDisplay;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.geom.Rectangle;
import ui.Scrollbar;
import ui.SimpleText;
import ui.view.ScreenBase;
import ui.view.TitleView;

class CharacterSelectionScreen extends Sprite {
	private static var DROP_SHADOW: DropShadowFilter = new DropShadowFilter(0, 0, 0, 1, 8, 8);

	private var nameText: SimpleText;
	private var currencyDisplay: CurrencyDisplay;
	private var characterList: CharacterList;
	private var characterListHeight = 0.0;
	private var playButton: TitleMenuOption;
	private var backButton: TitleMenuOption;
	private var classesButton: TitleMenuOption;
	private var scrollBar: Scrollbar;

	public function new() {
		super();

		this.playButton = new TitleMenuOption("play", 36, true);
		this.backButton = new TitleMenuOption("main", 22, false);
		this.classesButton = new TitleMenuOption("classes", 22, false);
		addChild(new ScreenBase());
		addChild(new AccountScreen());

		this.backButton.addEventListener(MouseEvent.CLICK, onClose);
		this.classesButton.addEventListener(MouseEvent.CLICK, onNewCharacter);

		Global.charListTask.finished.once(function(td: TaskData) {
			addEventListener(Event.ADDED_TO_STAGE, onAdded);
		});
		Global.charListTask.start();
	}

	private function onAdded(_: Event) {
		#if !disable_rpc
		if (Main.rpcReady) {
			var discordPresence = DiscordRichPresence.create();
			discordPresence.state = 'Character Select';
			discordPresence.details = '';
			discordPresence.largeImageKey = 'logo';
			discordPresence.largeImageText = 'v${Settings.BUILD_VERSION}';
			discordPresence.startTimestamp = Main.startTime;
			Discord.UpdatePresence(cpp.RawConstPointer.addressOf(discordPresence));
		}
		#end

		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		this.initialize();
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		this.backButton.removeEventListener(MouseEvent.CLICK, onClose);
		this.classesButton.removeEventListener(MouseEvent.CLICK, onNewCharacter);
	}

	private static function onNewCharacter(_: MouseEvent) {
		Global.layers.screens.setScreen(new NewCharacterScreen());
	}

	private static function onClose(_: MouseEvent) {
		Global.layers.screens.setScreen(new TitleView());
	}

	public function initialize() {
		this.createDisplayAssets();
	}

	public function getReferenceRectangle(): Rectangle {
		var rectangle: Rectangle = new Rectangle();
		if (stage != null)
			rectangle = new Rectangle(0, 0, stage.stageWidth, stage.stageHeight);

		return rectangle;
	}

	private function createDisplayAssets() {
		this.createNameText();
		this.createCurrencyDisplay();
		this.createCharacterList();
		this.createButtons();
		this.positionButtons();
		if (this.characterListHeight > stage.stageHeight / 2)
			this.createScrollbar();
	}

	private function createButtons() {
		addChild(this.playButton);
		addChild(this.backButton);
		addChild(this.classesButton);
		this.playButton.addEventListener(MouseEvent.CLICK, onPlayClick);
	}

	private function positionButtons() {
		this.playButton.x = (this.getReferenceRectangle().width - this.playButton.width) / 2;
		this.playButton.y = stage.stageHeight - 80;
		this.backButton.x = (this.getReferenceRectangle().width - this.backButton.width) / 2 - 94;
		this.backButton.y = stage.stageHeight - 68;
		this.classesButton.x = (this.getReferenceRectangle().width - this.classesButton.width) / 2 + 96;
		this.classesButton.y = stage.stageHeight - 68;
	}

	private function createScrollbar() {
		this.scrollBar = new Scrollbar(16, stage.stageHeight - 120);
		this.scrollBar.x = (stage.stageWidth - 800) / 2 + 800;
		this.scrollBar.y = 113;
		this.scrollBar.setIndicatorSize(stage.stageHeight / 2, this.characterList.height);
		this.scrollBar.addEventListener(Event.CHANGE, this.onScrollBarChange);
		addChild(this.scrollBar);
	}

	private function createCharacterList() {
		this.characterList = new CharacterList();
		this.characterList.x = (stage.stageWidth - 800) / 2 + 18;
		this.characterList.y = 112;
		this.characterListHeight = this.characterList.height;
		addChild(this.characterList);
	}

	private function createCurrencyDisplay() {
		this.currencyDisplay = new CurrencyDisplay(CurrencyDisplay.RIGHT_TO_LEFT);
		this.currencyDisplay.draw(Global.playerModel.getGems(), Global.playerModel.getGold(), Global.playerModel.getCrowns());
		this.currencyDisplay.x = this.getReferenceRectangle().width - 5;
		this.currencyDisplay.y = 25;
		addChild(this.currencyDisplay);
	}

	private function createNameText() {
		this.nameText = new SimpleText(22, 0xB3B3B3, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.text = Global.playerModel.getName();
		this.nameText.updateMetrics();
		this.nameText.filters = [DROP_SHADOW];
		this.nameText.y = 24;
		this.nameText.x = (this.getReferenceRectangle().width - this.nameText.width) / 2;
		addChild(this.nameText);
	}

	private function onScrollBarChange(event: Event) {
		this.characterList.setPos(-this.scrollBar.pos() * (this.characterListHeight - stage.stageHeight / 2));
	}

	private static function onPlayClick(event: Event) {
		if (Global.playerModel.getCharacterCount() == 0)
			Global.layers.screens.setScreen(new NewCharacterScreen());
		else {
			var character: SavedCharacter = Global.playerModel.getCharacterByIndex(0);
			Global.playerModel.currentCharId = character.charId();
			var characterClass: CharacterClass = Global.classModel.getCharacterClass(character.objectType());
			characterClass.setIsSelected(true);
			characterClass.skins.getSkin(character.skinType()).setIsSelected(true);
			var game: GameInitData = new GameInitData();
			game.createCharacter = false;
			game.charId = character.charId();
			game.gameId = Settings.HUB_GAMEID;
			Global.playGame(game);
		}
	}
}
