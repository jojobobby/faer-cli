package account.view;

import lib.tasks.Task.TaskData;
import cpp.Stdlib;
import cpp.Pointer;
import appengine.RequestHandler;
import openfl.events.Event;
import openfl.events.MouseEvent;
import screens.CharacterSelectionScreen;
import ui.ClickableText;
import ui.Frame;
import ui.TextInputField;

class LoginDialog extends Frame {
	public var email: TextInputField;
	public var password: TextInputField;

	private var forgotText: ClickableText;
	private var registerText: ClickableText;

	public function new() {
		super("Sign in", "Cancel", "Sign in");

		this.email = new TextInputField("Email", false, "");
		addTextInputField(this.email);

		this.password = new TextInputField("Password", true, "");
		addTextInputField(this.password);

		this.forgotText = new ClickableText(12, false, "Forgot your password?  Click here");
		addNavigationText(this.forgotText);
		this.forgotText.addEventListener(MouseEvent.CLICK, onForgot);

		this.registerText = new ClickableText(12, false, "New user?  Click here to Register");
		addNavigationText(this.registerText);
		this.registerText.addEventListener(MouseEvent.CLICK, onRegister);

		leftButton.addEventListener(MouseEvent.CLICK, onCancel);
		rightButton.addEventListener(MouseEvent.CLICK, this.onSignIn);

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		this.forgotText.removeEventListener(MouseEvent.CLICK, onForgot);
		this.registerText.removeEventListener(MouseEvent.CLICK, onRegister);
		leftButton.removeEventListener(MouseEvent.CLICK, onCancel);
		rightButton.removeEventListener(MouseEvent.CLICK, this.onSignIn);
	}

	private static function onRegister(_: MouseEvent) {
		Global.layers.dialogs.openDialog(new RegisterDialog());
	}

	private static function onCancel(_: MouseEvent) {
		Global.layers.dialogs.closeDialogs();
	}

	private static function onForgot(_: MouseEvent) {
		Global.layers.dialogs.openDialog(new ForgotPasswordDialog());
	}

	private function isPasswordValid() {
		var isValid = this.password.text() != "";
		if (!isValid)
			this.password.setError("Password too short");

		return isValid;
	}

	private function isEmailValid() {
		var isValid = this.email.text() != "";
		if (!isValid)
			this.email.setError("Not a valid email address");

		return isValid;
	}

	private function onSignIn(event: MouseEvent) {
		if (this.isEmailValid() && this.isPasswordValid()) {
			Account.email = this.email.text();
			Account.password = this.password.text();

			this.disable();

			Global.loginTask.finished.once(this.loginComplete);
			Global.loginTask.start();
		}
	}

	private function loginComplete(_: TaskData) {
		Global.charListTask.finished.once(this.charListComplete);
		Global.charListTask.start();
	}

	private function charListComplete(_: TaskData) {
		Global.layers.dialogs.closeDialogs();
		Global.invalidate();
		Global.setScreenValid(new CharacterSelectionScreen());
	}
}
