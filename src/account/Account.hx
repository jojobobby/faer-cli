package account;

import sys.io.File;

class Account {
	public static var userName = "";
	public static var email = "";
	public static var password = "";

	public static function updateUser(newName: String,newEmail: String, newPassword: String) {
		userName = newName;
		email = newEmail;
		password = newPassword;

		var w = File.write("login");
		w.writeString('name=>$userName\nemail=>$email\npassword=>$password');
		w.close();
	}

	public static function clear() {
		updateUser("Guest", "", "");
	}
}
