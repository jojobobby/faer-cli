package ui;
import util.NativeTypes;

class TextBoxLine {
	public var time = 0;
	public var name = "";
	public var recipient = "";
	public var toMe = false;
	public var text = "";
	public var nameColor: UInt32 = 0xFFFFFF;
	public var textColor: UInt32 = 0xFFFFFF;

	public function new(time: Int32, name: String, text: String = "", recipient: String = "", toMe: Bool = false, 
		nameColor: UInt32 = 0xFFFFFF, textColor: UInt32 = 0xFFFFFF) {
		this.time = time;
		this.name = name;
		this.recipient = recipient;
		this.toMe = toMe;
		this.text = text;
		this.nameColor = nameColor;
		this.textColor = textColor;
	}
}
