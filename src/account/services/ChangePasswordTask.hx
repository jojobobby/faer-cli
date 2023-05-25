package account.services;

import cpp.Stdlib;
import cpp.Pointer;
import appengine.RequestHandler;
import lib.tasks.Task;

class ChangePasswordTask extends Task {
	public static var changePwData: ChangePasswordData;

	override public function startTask() {
		RequestHandler.setParameter("email", Account.email);
		RequestHandler.setParameter("password", changePwData.currentPassword);
		RequestHandler.setParameter("newPassword", changePwData.newPassword);
		RequestHandler.complete.once(this.onComplete);
		RequestHandler.sendRequest("/account/changePassword");
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			this.onChangeDone();
		changePwData = null;
		completeTask(compData.success, compData.result);
	}

	private function onChangeDone() {
		Account.updateUser(Account.userName, Account.email, changePwData.newPassword);
	}
}
