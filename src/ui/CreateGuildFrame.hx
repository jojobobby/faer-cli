package ui;
import network.NetworkHandler;
import game.events.GuildResultEvent;
import game.GameSprite;
import openfl.events.Event;
import openfl.events.MouseEvent;

class CreateGuildFrame extends Frame {
	private var textField: TextInputField;
	private var gs: GameSprite;

	public function new(gs: GameSprite) {
		super("Create a new Guild", "Cancel", "Create");
		this.gs = gs;
		this.textField = new TextInputField("Guild Name", false, "");
		this.textField.inputText.restrict = "A-Za-z ";
		this.textField.inputText.maxChars = 20;
		addTextInputField(this.textField);
		addPlainText("Maximum 20 characters");
		addPlainText("No Floats or punctuation");
		addPlainText("Racism or profanity gets your guild banned");
		leftButton.addEventListener(MouseEvent.CLICK, this.onCancel);
		rightButton.addEventListener(MouseEvent.CLICK, this.onCreate);
	}

	private function onCancel(event: MouseEvent) {
		dispatchEvent(new Event(Event.COMPLETE));
	}

	private function onCreate(event: MouseEvent) {
		this.gs.addEventListener(GuildResultEvent.EVENT, this.onResult);
		NetworkHandler.createGuild(this.textField.text());
		disable();
	}

	private function onResult(event: GuildResultEvent) {
		this.gs.removeEventListener(GuildResultEvent.EVENT, this.onResult);
		if (event.success)
			dispatchEvent(new Event(Event.COMPLETE));
		else {
			this.textField.setError(event.errorText);
			enable();
		}
	}
}
