package account.services;

import cpp.Stdlib;
import cpp.Pointer;
import account.Account;
import appengine.RequestHandler;
import lib.tasks.Task;

class DeleteCharacterTask extends Task {
	override public function startTask() {
		RequestHandler.setParameter("email", Account.email);
		RequestHandler.setParameter("password", Account.password);
		RequestHandler.setParameter("charId", Std.string(Global.charModel.getSelected().charId()));
		RequestHandler.maxRetries = 2;
		RequestHandler.complete.once(this.onComplete);
		RequestHandler.sendRequest("/char/delete");
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			updateUserData();

		completeTask(compData.success, compData.result);
	}

	private static function updateUserData() {
		Global.charModel.deleteCharacter(Global.charModel.getSelected().charId());
	}
}
