package account.services;

import cpp.Pointer;
import cpp.Stdlib;
import appengine.RequestHandler;
import lib.tasks.Task;

class SendPasswordReminderTask extends Task {
	public static var email = "";

	override public function startTask() {
		RequestHandler.setParameter("email", Account.email);
		RequestHandler.complete.once(this.onComplete);
		RequestHandler.sendRequest("/account/forgotPassword");
	}

	private function onComplete(compData: CompletionData) {
		email = null;
		if (compData.success)
			this.onForgotDone();
		else
			this.onForgotError(compData.result);
	}

	private function onForgotDone() {
		completeTask(true);
	}

	private function onForgotError(error: String) {
		completeTask(false, error);
	}
}
