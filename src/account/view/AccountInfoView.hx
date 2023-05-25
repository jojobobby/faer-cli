package account.view;

import classes.model.CharacterClass;
import classes.model.CharacterSkin;
import classes.model.CharacterSkinState;
import classes.model.ClassModel;
import openfl.display.DisplayObject;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import screens.TitleMenuOption;
import ui.SimpleText;

using StringTools;

class AccountInfoView extends Sprite {
	private static inline var LOG_IN: String = "log in";
	private static inline var LOG_OUT: String = "log out";
	private static inline var LOGGED_IN_TEXT: String = "logged in as {userName} - ";
	private static inline var GUEST_ACCOUNT: String = "guest account - ";
	private static inline var REGISTER: String = "register";
	private static inline var FONT_SIZE: Int = 18;

	private var userName = "";
	private var isRegistered = false;
	private var accountText: SimpleText;
	private var registerButton: TitleMenuOption;
	private var dividerText: SimpleText;
	private var loginButton: TitleMenuOption;

	public function new() {
		super();

		this.accountText = new SimpleText(FONT_SIZE, 0xB3B3B3, false, 0, 0);
		this.accountText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4)];
		this.loginButton = new TitleMenuOption("log in", FONT_SIZE, false);
		this.loginButton.addEventListener(MouseEvent.CLICK, this.onLoginToggle);
		this.registerButton = new TitleMenuOption(REGISTER, FONT_SIZE, false);
		this.registerButton.addEventListener(MouseEvent.CLICK, onRegister);
		this.dividerText = new SimpleText(FONT_SIZE, 0xB3B3B3, false, 0, 0);
		this.dividerText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4)];
		this.dividerText.text = " - ";
		this.dividerText.updateMetrics();

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.setInfo(Account.userName, Account.password != "");
		Global.updateAccount.once(this.updateLogin);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.loginButton.removeEventListener(MouseEvent.CLICK, this.onLoginToggle);
		this.registerButton.removeEventListener(MouseEvent.CLICK, onRegister);
	}

	private function updateLogin() {
		this.setInfo(Account.userName, Account.password != "");
	}

	private static function onRegister(_: MouseEvent) {
		Global.layers.dialogs.openDialog(new RegisterDialog());
	}

	private function onLoginToggle(_: MouseEvent) {
		if (Account.password != "") {
			Account.clear();
			// Global.invalidate();
			// Global.setScreenValid(Global.currentScreenType != null ? cast Global.currentScreenType : new CharacterSelectionScreen());

			var count: Int = Global.classModel.getCount();
			var charClass: CharacterClass;
			for (i in 0...count) {
				charClass = Global.classModel.getClassAtIndex(i);

				charClass.setIsSelected(charClass.id == ClassModel.WIZARD_ID);
				var skin: CharacterSkin = null;
				var defaultSkin: CharacterSkin = charClass.skins.getDefaultSkin();
				var skinCount: Int = charClass.skins.getCount();
				for (j in 0...skinCount) {
					skin = charClass.skins.getSkinAt(j);
					if (skin != defaultSkin)
						charClass.skins.getSkinAt(j).setState(CharacterSkinState.LOCKED);
				}
			}

			this.setInfo("", false);
		} else
			Global.layers.dialogs.openDialog(new LoginDialog());
	}

	public function setInfo(userName: String, isRegistered: Bool) {
		this.userName = userName;
		this.isRegistered = isRegistered;
		this.updateUI();
	}

	private function updateUI() {
		this.removeUIElements();
		if (this.isRegistered)
			this.showUIForRegisteredAccount();
		else
			this.showUIForGuestAccount();
	}

	private function removeUIElements() {
		while (numChildren > 0)
			removeChildAt(0);
	}

	private function showUIForRegisteredAccount() {
		this.accountText.text = LOGGED_IN_TEXT.replace("{userName}", this.userName);
		this.accountText.updateMetrics();
		this.loginButton.setText(LOG_OUT);
		this.addAndAlignHorizontally([this.accountText, this.loginButton]);
	}

	private function showUIForGuestAccount() {
		this.accountText.text = GUEST_ACCOUNT;
		this.accountText.updateMetrics();
		this.loginButton.setText(LOG_IN);
		this.addAndAlignHorizontally([this.accountText, this.registerButton, this.dividerText, this.loginButton]);
	}

	private function addAndAlignHorizontally(uiElements: Array<DisplayObject>) {
		var x = 0.0;
		var i: Int = uiElements.length;
		while (i-- > 0) {
			var ui = uiElements[i];
			x -= ui.width;
			ui.x = x;
			addChild(ui);
		}
	}
}
