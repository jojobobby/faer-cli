package account.view;

import account.ChangePasswordData;
import account.services.ChangePasswordTask;
import lib.tasks.Task;
import openfl.events.Event;
import openfl.events.MouseEvent;
import ui.Frame;
import ui.TextInputField;

class ChangePasswordDialog extends Frame {
	public var password: TextInputField;
	public var newPassword: TextInputField;
	public var retypeNewPassword: TextInputField;

	public function new() {
		super("Change your password", "Cancel", "Submit");
		this.password = new TextInputField("Password", true, "");
		addTextInputField(this.password);
		this.newPassword = new TextInputField("New Password", true, "");
		addTextInputField(this.newPassword);
		this.retypeNewPassword = new TextInputField("Retype New Password", true, "");
		addTextInputField(this.retypeNewPassword);
		leftButton.addEventListener(MouseEvent.CLICK, onCancel);
		rightButton.addEventListener(MouseEvent.CLICK, this.onChange);
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		leftButton.removeEventListener(MouseEvent.CLICK, onCancel);
		rightButton.removeEventListener(MouseEvent.CLICK, this.onChange);
	}

	private static function onCancel(_: MouseEvent) {
		Global.layers.dialogs.openDialog(new AccountDetailDialog());
	}

	private function onChange(_: MouseEvent) {
		var data: ChangePasswordData = null;
		if (this.isCurrentPasswordValid() && this.isNewPasswordValid() && this.isNewPasswordVerified()) {
			this.disable();
			data = new ChangePasswordData();
			data.currentPassword = this.password.text();
			data.newPassword = this.newPassword.text();
			ChangePasswordTask.changePwData = data;

			Global.changePasswordTask.finished.once(function(taskData: TaskData) {
				if (taskData.success)
					Global.layers.dialogs.openDialog(new AccountDetailDialog());
				else {
					this.password.setError(taskData.error);
					this.enable();
				}
			});
			Global.changePasswordTask.start();
		}
	}

	private function isCurrentPasswordValid() {
		var isValid = this.password.text().length >= 5;
		if (!isValid)
			this.password.setError("Incorrect password");

		return isValid;
	}

	private function isNewPasswordValid() {
		var isValid = this.newPassword.text().length >= 5;
		if (!isValid)
			this.newPassword.setError("New password too short");

		return isValid;
	}

	private function isNewPasswordVerified() {
		var isValid = this.newPassword.text() == this.retypeNewPassword.text();
		if (!isValid)
			this.retypeNewPassword.setError("Password does not match");

		return isValid;
	}
}
