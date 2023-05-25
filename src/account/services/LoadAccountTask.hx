package account.services;

import cpp.Stdlib;
import cpp.Pointer;
import sys.io.File;
import sys.FileSystem;
import account.AccountData;
import appengine.RequestHandler;
import lib.tasks.Task;

class LoadAccountTask extends Task {
	private var data: AccountData;

	public function new() {
		this.data = new AccountData();
		super();
	}

	override public function startTask() {
		try {
			if (FileSystem.exists("login"))
				for (s in File.getContent("login").split("\n")) {
					var line = s.split("=>");
					switch (line[0]) {
						case "name":
							this.data.userName = line[1];
						case "email":
							this.data.email = line[1];
						case "password":
							this.data.password = line[1];
					}
				}
		} catch (e) {
			this.data.userName = "";
			this.data.email = "";
			this.data.password = "";
		}

		if (this.data.email != "") {
			RequestHandler.setParameter("email", this.data.email);
			RequestHandler.setParameter("password", this.data.password);
			RequestHandler.complete.once(this.onComplete);
			RequestHandler.sendRequest("/account/verify");
		} else {
			Account.updateUser("Guest", "", "");
			completeTask(true);
		}
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			Account.updateUser(this.data.userName, this.data.email, this.data.password);

		completeTask(compData.success, compData.result);
	}
}
