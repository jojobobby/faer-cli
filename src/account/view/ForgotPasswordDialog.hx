package account.view;

import account.services.SendPasswordReminderTask;
import lib.tasks.Task;
import openfl.events.Event;
import openfl.events.MouseEvent;
import ui.ClickableText;
import ui.Frame;
import ui.TextInputField;

class ForgotPasswordDialog extends Frame {
	private var emailInput: TextInputField;
	private var registerText: ClickableText;

	public function new() {
		super("Forgot your password?  We\'ll email it.", "Cancel", "Submit");

		this.emailInput = new TextInputField("Email", false, "");
		addTextInputField(this.emailInput);

		this.registerText = new ClickableText(12, false, "New user?  Click here to Register");
		addNavigationText(this.registerText);
		this.registerText.addEventListener(MouseEvent.CLICK, onRegister);

		leftButton.addEventListener(MouseEvent.CLICK, onCancel);
		rightButton.addEventListener(MouseEvent.CLICK, this.onSubmit);

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		this.registerText.removeEventListener(MouseEvent.CLICK, onRegister);
		leftButton.removeEventListener(MouseEvent.CLICK, onCancel);
		rightButton.removeEventListener(MouseEvent.CLICK, this.onSubmit);
	}

	private static function onRegister(_: MouseEvent) {
		Global.layers.dialogs.openDialog(new RegisterDialog());
	}

	private static function onCancel(_: MouseEvent) {
		Global.layers.dialogs.openDialog(new LoginDialog());
	}

	private function isEmailValid() {
		var isValid: Bool = this.emailInput.text() != "";
		if (!isValid)
			this.emailInput.setError("Not a valid email address");

		return isValid;
	}

	private function onSubmit(_: MouseEvent) {
		if (this.isEmailValid()) {
			disable();

			SendPasswordReminderTask.email = this.emailInput.text();

			Global.sendPasswordReminderTask.finished.once(function(taskData: TaskData) {
				if (taskData.success)
					Global.layers.dialogs.openDialog(new LoginDialog());
				else {
					this.emailInput.setError(taskData.error);
					this.enable();
				}
			});
			Global.sendPasswordReminderTask.start();
		}
	}
}
