package account.services;

import cpp.Stdlib;
import cpp.Pointer;
import account.Account;
import appengine.RequestHandler;
import classes.model.CharacterSkin;
import classes.model.CharacterSkinState;
import lib.tasks.Task;
import ui.dialogs.ErrorDialog;

class BuySkinTask extends Task {
	public static var skin: CharacterSkin;

	override public function startTask() {
		skin.setState(CharacterSkinState.PURCHASING);
		Global.playerModel.addGems(-skin.cost);
		RequestHandler.setParameter("email", Account.email);
		RequestHandler.setParameter("password", Account.password);
		RequestHandler.setParameter("skinType", Std.string(skin.id));
		RequestHandler.complete.once(this.onComplete);
		RequestHandler.sendRequest("account/purchaseSkin");
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			this.completePurchase();
		else
			this.abandonPurchase(compData.result);

		completeTask(compData.success, compData.result);
	}

	private function completePurchase() {
		skin.setState(CharacterSkinState.OWNED);
		skin.setIsSelected(true);
	}

	private function abandonPurchase(problem: String) {
		Global.layers.dialogs.openDialog(new ErrorDialog(problem));
		skin.setState(CharacterSkinState.PURCHASABLE);
		Global.playerModel.addGems(skin.cost);
	}
}
