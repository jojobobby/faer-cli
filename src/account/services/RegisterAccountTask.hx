package account.services;

import cpp.Stdlib;
import cpp.Pointer;
import account.AccountData;
import appengine.RequestHandler;
import lib.tasks.Task;

class RegisterAccountTask extends Task {
	public static var accountData: AccountData;

	override public function startTask() {
		RequestHandler.setParameter("username", accountData.userName);
		RequestHandler.setParameter("email", accountData.email);
		RequestHandler.setParameter("password", accountData.password);
		RequestHandler.complete.once(this.onComplete);
		RequestHandler.sendRequest("/account/register");
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			onRegisterDone();

		accountData = null;
		completeTask(compData.success, compData.result);
	}

	private static function onRegisterDone() {
		Account.updateUser(accountData.userName, accountData.email, accountData.password);
	}
}
