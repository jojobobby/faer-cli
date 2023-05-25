package account.services;

import cpp.Stdlib;
import cpp.Pointer;
import appengine.RequestHandler;
import lib.tasks.Task;

class LoginTask extends Task {
	public function new() {
		super();
	}

	override public function startTask() {
		if (Account.email != "") {
			RequestHandler.setParameter("email", Account.email);
			RequestHandler.setParameter("password", Account.password);
			RequestHandler.setParameter("test", "123");
			RequestHandler.complete.once(this.onComplete);
			RequestHandler.sendRequest("/account/verify");
		} else {
			Account.updateUser("Guest", "", "");
			completeTask(true);
		}
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			Account.updateUser("", Account.email, Account.password);

		completeTask(compData.success, compData.result);
	}
}
