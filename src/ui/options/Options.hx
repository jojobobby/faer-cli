package ui.options;
import network.NetworkHandler;
import game.GameSprite;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import screens.TitleMenuOption;
import sound.Music;
import sound.SoundEffectLibrary;
import ui.SimpleText;
import util.Settings;

class Options extends Sprite {
	private static inline var CONTROLS_TAB = "Controls";
	private static inline var HOTKEYS_TAB = "Hot Keys";
	private static inline var CHAT_TAB = "Chat";
	private static inline var GRAPHICS_TAB = "Graphics";
	private static inline var SOUND_TAB = "Sound";
	private static var TABS = [CONTROLS_TAB, HOTKEYS_TAB, CHAT_TAB, GRAPHICS_TAB, SOUND_TAB];

	private static var registeredCursors = new Array<String>();

	private var gs: GameSprite;
	private var title: SimpleText;
	private var continueButton: TitleMenuOption;
	private var resetToDefaultsButton: TitleMenuOption;
	private var homeButton: TitleMenuOption;
	private var tabs: Array<OptionsTabTitle>;
	private var selected: OptionsTabTitle = null;
	private var options: Array<Sprite>;
	private var optionIndex = 0;

	private static function onPlayMusicChange() {
		Music.setPlayMusic(Settings.playMusic);
	}

	private static function onPlaySoundEffectsChange() {
		SoundEffectLibrary.setPlaySFX(Settings.playSfx);
	}

	private static function onVSyncChange() {
		// Main.primaryStage.vsyncEnabled = Settings.values["vSync"];
	}

	private static function onFPSChange() {
		// Main.primaryStage.frameRate = Std.parseInt(Settings.values.get("fpsCap"));
	}

	public function new(gs: GameSprite) {
		super();

		var tab: OptionsTabTitle = null;
		this.tabs = new Array<OptionsTabTitle>();
		this.options = new Array<Sprite>();
		this.gs = gs;

		graphics.clear();
		graphics.lineStyle(4, 0x666666);
		graphics.beginFill(0x1B1B1B, 0.8);
		graphics.drawRect(0, 0, 800, 600);
		graphics.endFill();

		this.title = new SimpleText(36, 0xFFFFFF, false, 800, 0);
		this.title.setBold(true);
		this.title.htmlText = "<p align=\"center\">Options</p>";
		this.title.autoSize = TextFieldAutoSize.CENTER;
		this.title.filters = [new DropShadowFilter(0, 0, 0)];
		this.title.updateMetrics();
		this.title.x = 800 / 2 - this.title.width / 2;
		this.title.y = 8;
		addChild(this.title);

		this.continueButton = new TitleMenuOption("continue", 36, false);
		this.continueButton.addEventListener(MouseEvent.CLICK, this.onContinueClick);
		addChild(this.continueButton);
		this.resetToDefaultsButton = new TitleMenuOption("defaults", 22, false);
		this.resetToDefaultsButton.addEventListener(MouseEvent.CLICK, this.onResetToDefaultsClick);
		addChild(this.resetToDefaultsButton);
		this.homeButton = new TitleMenuOption("menu", 22, false);
		this.homeButton.addEventListener(MouseEvent.CLICK, this.onHomeClick);
		addChild(this.homeButton);

		var xOffset: Int = 14;
		for (i in 0...TABS.length) {
			tab = new OptionsTabTitle(TABS[i]);
			tab.x = xOffset;
			tab.y = 70;
			addChild(tab);
			tab.addEventListener(MouseEvent.CLICK, this.onTabClick);
			this.tabs.push(tab);
			xOffset += 108;
		}

		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	private function setSelected(tab: OptionsTabTitle) {
		if (tab == this.selected)
			return;

		if (this.selected != null)
			this.selected.setSelected(false);

		this.selected = tab;
		this.selected.setSelected(true);
		this.removeOptions();
		switch (this.selected.text) {
			case CONTROLS_TAB:
				this.addControlsOptions();
			case HOTKEYS_TAB:
				this.addHotKeysOptions();
			case CHAT_TAB:
				this.addChatOptions();
			case GRAPHICS_TAB:
				this.addGraphicsOptions();
			case SOUND_TAB:
				this.addSoundOptions();
		}
	}

	private function close() {
		stage.focus = null;
		parent.removeChild(this);
	}

	private function removeOptions() {
		for (option in this.options)
			removeChild(option);

		this.options.splice(0, this.options.length);
		this.optionIndex = 0;
	}

	private function addControlsOptions() {
		this.addOption(new KeyMapper("moveUp", "Move Up", "This key will move character up"));
		this.addOption(new KeyMapper("moveLeft", "Move Left", "This key will move character to the left"));
		this.addOption(new KeyMapper("moveDown", "Move Down", "This key will move character down"));
		this.addOption(new KeyMapper("moveRight", "Move Right", "This key will move character to the right"));
		this.addOption(new KeyMapper("rotateLeft", "Rotate Left", "This key will rotate the camera to the left"));
		this.addOption(new KeyMapper("rotateRight", "Rotate Right", "This key will rotate the camera to the right"));
		this.addOption(new KeyMapper("useAbility", "Use Ability", "This key will activate your ability"));
		this.addOption(new KeyMapper("resetCamera", "Reset Camera Angle", "This key will reset the camera angle to the default position"));
		this.addOption(new KeyMapper("perfStats", "Toggle Performance Stats", "This key will toggle a display of fps and memory usage"));
		this.addOption(new KeyMapper("toggleCentering", "Toggle Centering", "This key will toggle the position between centered and offset"));
		this.addOption(new KeyMapper("interact", "Interact", "This key will allow you to interact with world objects"));
		this.addOption(new KeyMapper("walk", "Walk", "This key will allow you to move slowly"));
	}

	private function addHotKeysOptions() {
		this.addOption(new KeyMapper("healthVial", "Use Health Vial", "This key will use health vials if available"));
		this.addOption(new KeyMapper("magicVial", "Use Magic Vial", "This key will use magic vials if available"));
		this.addOption(new KeyMapper("inv1", "Use Inventory Slot 1", "Use item in inventory slot 1"));
		this.addOption(new KeyMapper("inv2", "Use Inventory Slot 2", "Use item in inventory slot 2"));
		this.addOption(new KeyMapper("inv3", "Use Inventory Slot 3", "Use item in inventory slot 3"));
		this.addOption(new KeyMapper("inv4", "Use Inventory Slot 4", "Use item in inventory slot 4"));
		this.addOption(new KeyMapper("inv5", "Use Inventory Slot 5", "Use item in inventory slot 5"));
		this.addOption(new KeyMapper("inv6", "Use Inventory Slot 6", "Use item in inventory slot 6"));
		this.addOption(new KeyMapper("inv7", "Use Inventory Slot 7", "Use item in inventory slot 7"));
		this.addOption(new KeyMapper("inv8", "Use Inventory Slot 8", "Use item in inventory slot 8"));
		this.addOption(new KeyMapper("goToHub", "Escape To Hub", "This key will instantly escape you to the Hub"));
		this.addOption(new KeyMapper("options", "Show Options", "This key will bring up the options screen"));
		this.addOption(new KeyMapper("switchTabs", "Switch Tabs", "This key will switch from available tabs"));
	}

	private function addChatOptions() {
		this.addOption(new KeyMapper("chat", "Activate Chat", "This key will bring up the chat input box"));
		this.addOption(new KeyMapper("chatCmd", "Start Chat Command", "This key will bring up the chat with a \'/\' prepended to allow for commands"));
		this.addOption(new KeyMapper("respond", "Begin Tell", "This key will bring up a tell (private message) in the chat input box"));
		this.addOption(new KeyMapper("guildChat", "Begin Guild Chat", "This key will bring up a guild chat in the chat input box"));
		this.addOption(new KeyMapper("chatUp", "Scroll Chat Up", "This key will scroll up to older messages in the chat buffer"));
		this.addOption(new KeyMapper("chatDown", "Scroll Chat Down", "This key will scroll down to newer messages in the chat buffer"));
	}

	private function addGraphicsOptions() {
		this.addOption(new ChoiceOption("selectedCursor", ["Faer", "Royal", "Ranger", "Aztec", "Fiery"], ["0", "1", "2", "3", "4"], "Cursor Type",
			"This toggles between various cursor types", Main.refreshCursor));
		this.addOption(new ChoiceOption("glowType", ["Off", "Low", "Medium", "High", "Very High"], [GlowType.None, GlowType.Low, GlowType.Medium, GlowType.High, GlowType.VeryHigh], "Object Glow",
			"This toggles between object glows of various quality", Main.refreshCursor));
	}

	private function addSoundOptions() {
		this.addOption(new ChoiceOption("playMusic", ["On", "Off"], [true, false], "Play Music", "This toggles whether music is played",
			onPlayMusicChange));
		this.addOption(new ChoiceOption("playSfx", ["On", "Off"], [true, false], "Play Sound Effects", "This toggles whether sound effects are played",
			onPlaySoundEffectsChange));
		this.addOption(new ChoiceOption("playWepSfx", ["On", "Off"], [true, false], "Play Weapon Sounds", "This toggles whether weapon sounds are played",
			null));
	}

	private function addOption(option: Sprite) {
		option.x = this.optionIndex % 2 == 0 ? 20 : 415;
		option.y = Std.int(this.optionIndex / 2) * 62 + 122;
		addChild(option);
		option.addEventListener(Event.CHANGE, this.onChange);
		this.options.push(option);
		this.optionIndex++;
	}

	private function refresh() {
		var option: Option = null;
		for (i in 0...this.options.length) {
			option = cast(this.options[i], Option);
			if (option != null)
				option.refresh();
		}
	}

	private function onContinueClick(event: MouseEvent) {
		this.close();
	}

	private function onResetToDefaultsClick(event: MouseEvent) {
		Settings.setDefaults();
		Settings.save();
		this.refresh();
	}

	private function onHomeClick(event: MouseEvent) {
		this.close();
		NetworkHandler.disconnect();
	}

	private function onTabClick(event: MouseEvent) {
		var tab: OptionsTabTitle = cast(event.target, OptionsTabTitle);
		this.setSelected(tab);
	}

	private function onAddedToStage(event: Event) {
		this.continueButton.x = 400 - this.continueButton.width / 2;
		this.continueButton.y = 520;
		this.resetToDefaultsButton.x = 20;
		this.resetToDefaultsButton.y = 532;
		this.homeButton.x = 780 - this.homeButton.width;
		this.homeButton.y = 532;
		this.setSelected(this.tabs[0]);
		stage.addEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown, false, 1);
		stage.addEventListener(KeyboardEvent.KEY_UP, onKeyUp, false, 1);
	}

	private function onRemovedFromStage(event: Event) {
		stage.removeEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown, false);
		stage.removeEventListener(KeyboardEvent.KEY_UP, onKeyUp, false);
	}

	private function onKeyDown(event: KeyboardEvent) {
		if (event.keyCode == Settings.options)
			this.close();

		event.stopImmediatePropagation();
	}

	private static function onKeyUp(event: KeyboardEvent) {
		event.stopImmediatePropagation();
	}

	private function onChange(event: Event) {
		this.refresh();
	}
}
