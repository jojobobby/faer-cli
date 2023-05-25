package account.view;

import appengine.RequestHandler;
import account.AccountData;
import account.services.RegisterAccountTask;
import lib.tasks.Task;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.events.TextEvent;
import openfl.filters.DropShadowFilter;
import ui.Frame;
import ui.SimpleText;
import util.Settings;

class RegisterDialog extends Frame {
	private static inline var TOS_TEXT: String = "By clicking \'Register\', you are indicating that you have<br>read and agreed to the <font color=\"#7777EE\"><a href=\""
		+ Settings.TERMS_OF_USE_URL
		+ "\" target=\"_blank\">Terms of Use</a></font> and "
		+ "<font color=\"#7777EE\"><a href=\""
		+ Settings.PRIVACY_POLICY_URL
		+ "\" target=\"_blank\">Privacy Policy</a></font>";
	private static inline var SIGN_IN_TEXT: String = "Already registered? <font color=\"#7777EE\"><a href=\"event:flash.events.TextEvent\">here</a></font> to sign in!";
	private static inline var REGISTER_IMPERATIVE: String = "Register in order to save your progress";
	private static inline var MULTIPLE_ERRORS_MESSAGE: String = "Please fix the errors below";
	private static inline var PASSWORDS_DONT_MATCH: String = "The password did not match";
	private static inline var PASSWORD_TOO_SHORT: String = "The password is too short";
	private static inline var INVALID_EMAIL_ADDRESS: String = "Not a valid email address";

	private var errors: Array<String> = new Array<String>();
	private var nameInput: LabeledField;
	private var emailInput: LabeledField;
	private var passwordInput: LabeledField;
	private var retypePasswordInput: LabeledField;
	private var signInText: SimpleText;
	private var tosText: SimpleText;

	public function new() {
		super(REGISTER_IMPERATIVE, "Cancel", "Register", 326);

		this.nameInput = new LabeledField("Name", false, 275);
		this.emailInput = new LabeledField("Email", false, 275);
		this.passwordInput = new LabeledField("Password", true, 275);
		this.retypePasswordInput = new LabeledField("Retype Password", true, 275);
		this.tosText = new SimpleText(12, 0xB3B3B3, false, 0, 0, true);
		this.tosText.setBold(true);
		this.tosText.multiline = true;
		this.tosText.htmlText = TOS_TEXT;
		this.tosText.updateMetrics();
		this.tosText.filters = [new DropShadowFilter(0, 0, 0)];
		this.signInText = new SimpleText(12, 0xB3B3B3, false, 0, 0, true);
		this.signInText.setBold(true);
		this.signInText.htmlText = SIGN_IN_TEXT;
		this.signInText.updateMetrics();
		this.signInText.filters = [new DropShadowFilter(0, 0, 0)];
		this.signInText.addEventListener(TextEvent.LINK, onSignIn);
		addLabeledField(this.nameInput);
		addLabeledField(this.emailInput);
		addLabeledField(this.passwordInput);
		addLabeledField(this.retypePasswordInput);
		addSpace(8);
		addComponent(this.tosText, 14);
		addSpace(8);
		addComponent(this.signInText, 14);

		leftButton.addEventListener(MouseEvent.CLICK, onCancel);
		rightButton.addEventListener(MouseEvent.CLICK, this.onRegister);

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		leftButton.removeEventListener(MouseEvent.CLICK, onCancel);
		rightButton.removeEventListener(MouseEvent.CLICK, this.onRegister);
	}

	private static function onCancel(_: MouseEvent) {
		Global.layers.dialogs.closeDialogs();
	}

	private static function onSignIn(_: TextEvent) {
		Global.layers.dialogs.openDialog(new LoginDialog());
	}

	public function displayErrors() {
		if (this.errors.length == 0)
			this.clearErrors();
		else
			this.displayErrorText(this.errors.length == 1 ? this.errors[0] : MULTIPLE_ERRORS_MESSAGE);
	}

	private function areInputsValid() {
		this.errors.splice(0, this.errors.length);
		var isValid = true;
		isValid = this.isNameValid() && isValid;
		isValid = this.isEmailValid() && isValid;
		isValid = this.isPasswordValid() && isValid;
		isValid = this.isPasswordVerified() && isValid;
		return isValid;
	}

	private function isNameValid() {
		var isValid: Bool = this.nameInput.text().length < 10;
		this.nameInput.setErrorHighlight(!isValid);
		if (!isValid)
			this.errors.push("Name too long");
		return isValid;
	}

	private function isEmailValid() {
		var regex = ~/^[A-Z0-9._%+-]+@(?:[A-Z0-9-]+\.)+[A-Z]{2,4}$/i;
		var isValid: Bool = regex.match(this.emailInput.text());
		this.emailInput.setErrorHighlight(!isValid);
		if (!isValid)
			this.errors.push(INVALID_EMAIL_ADDRESS);
		return isValid;
	}

	private function isPasswordValid() {
		var isValid: Bool = this.passwordInput.text().length >= 5;
		this.passwordInput.setErrorHighlight(!isValid);
		if (!isValid)
			this.errors.push(PASSWORD_TOO_SHORT);
		return isValid;
	}

	private function isPasswordVerified() {
		var isValid: Bool = this.passwordInput.text() == this.retypePasswordInput.text();
		this.retypePasswordInput.setErrorHighlight(!isValid);
		if (!isValid)
			this.errors.push(PASSWORDS_DONT_MATCH);
		return isValid;
	}

	private function clearErrors() {
		titleText.text = REGISTER_IMPERATIVE;
		titleText.updateMetrics();
		titleText.setColor(0xB3B3B3);
	}

	private function displayErrorText(value: String) {
		titleText.text = value;
		titleText.updateMetrics();
		titleText.setColor(0xFC8642);
	}

	private function sendData() {
		var data = new AccountData();
		data.userName = this.nameInput.text();
		data.email = this.emailInput.text();
		data.password = this.passwordInput.text();
		RegisterAccountTask.accountData = data;

		Global.registerAccountTask.finished.once(function(taskData: TaskData) {
			if (taskData.success) {
				Global.updateAccount.emit();
				Global.charListTask.finished.once(function(taskData: TaskData) {
					if (taskData.success)
						Global.layers.dialogs.openDialog(new AccountDetailDialog());
					else {
						this.displayErrorText(taskData.error);
						this.enable();
					}
				});
				Global.charListTask.start();
			} else {
				this.displayErrorText(taskData.error);
				this.enable();
			}
		});
		Global.registerAccountTask.start();
	}

	private function onRegister(_: MouseEvent) {
		this.displayErrors();
		if (this.areInputsValid())
			this.sendData();
	}
}
