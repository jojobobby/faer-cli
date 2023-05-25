package account.view;

import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import ui.ClickableText;
import ui.Frame;
import ui.SimpleText;

class AccountDetailDialog extends Frame {
	private var loginText: SimpleText;
	private var emailText: SimpleText;
	private var changeText: ClickableText;
	private var logoutText: ClickableText;

	public function new() {
		super("Current account", "", "Continue");
		this.makeLoginText();
		this.makeEmailText();
		h += 88;
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.setUserInfo(Account.email);
		rightButton.addEventListener(MouseEvent.CLICK, onDone);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		rightButton.removeEventListener(MouseEvent.CLICK, onDone);
	}

	private static function onChange(_: MouseEvent) {
		Global.layers.dialogs.openDialog(new ChangePasswordDialog());
	}

	private static function onLogout(_: MouseEvent) {
		Account.clear();
		Global.layers.dialogs.openDialog(new LoginDialog());
	}

	private static function onDone(_: MouseEvent) {
		Global.layers.dialogs.closeDialogs();
	}

	public function setUserInfo(email: String) {
		this.emailText.text = email ?? "Unknown e-mail";
		this.makeChangeText();
		this.makeLogoutText();
	}

	private function makeChangeText() {
		this.changeText = new ClickableText(12, false, "Click here to change password");
		this.changeText.addEventListener(MouseEvent.CLICK, onChange);
		addNavigationText(this.changeText);
	}

	private function makeLogoutText() {
		this.logoutText = new ClickableText(12, false, "Not you?  Click here");
		this.logoutText.addEventListener(MouseEvent.CLICK, onLogout);
		addNavigationText(this.logoutText);
	}

	private function makeLoginText() {
		this.loginText = new SimpleText(18, 0xB3B3B3, false, 0, 0);
		this.loginText.setBold(true);
		this.loginText.text = "Currently logged in as:";
		this.loginText.updateMetrics();
		this.loginText.filters = [new DropShadowFilter(0, 0, 0)];
		this.loginText.y = h - 60;
		this.loginText.x = 17;
		addChild(this.loginText);
	}

	private function makeEmailText() {
		this.emailText = new SimpleText(16, 0xB3B3B3, false, 238, 30);
		this.emailText.updateMetrics();
		this.emailText.y = h - 30;
		this.emailText.x = 17;
		addChild(this.emailText);
	}
}
