package account.services;

import cpp.Stdlib;
import cpp.Pointer;
import appengine.RequestHandler;
import lib.tasks.Task;

class BuyCharacterSlotTask extends Task {
	override public function startTask() {
		RequestHandler.setParameter("email", Account.email);
		RequestHandler.setParameter("password", Account.password);
		RequestHandler.complete.once(this.onComplete);
		RequestHandler.sendRequest("/account/purchaseCharSlot");
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			updatePlayerData();
		completeTask(compData.success, compData.result);
	}

	private static function updatePlayerData() {
		//Global.playerModel.setMaxCharacters(Global.playerModel.getMaxCharacters() + 1);
		//Global.playerModel.addGems(-Global.playerModel.getNextCharSlotPrice());
	}
}
