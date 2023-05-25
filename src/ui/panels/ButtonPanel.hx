package ui.panels;

import game.GameSprite;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import ui.SimpleText;
import ui.TextButton;

class ButtonPanel extends Panel {
	public var button: TextButton;

	private var titleText: SimpleText;

	public function new(gs: GameSprite, title: String, button: String) {
		super(gs);
		this.titleText = new SimpleText(18, 0xFFFFFF, false, Panel.WIDTH, 0);
		this.titleText.setBold(true);
		this.titleText.htmlText = "<p align=\"center\">" + title + "</p>";
		this.titleText.wordWrap = true;
		this.titleText.multiline = true;
		this.titleText.autoSize = TextFieldAutoSize.CENTER;
		this.titleText.filters = [new DropShadowFilter(0, 0, 0)];
		this.titleText.y = 6;
		addChild(this.titleText);
		this.button = new TextButton(16, button);
		this.button.addEventListener(MouseEvent.CLICK, this.onButtonClick);
		this.button.x = Panel.WIDTH / 2 - this.button.width / 2;
		this.button.y = Panel.HEIGHT - this.button.height - 4;
		addChild(this.button);
	}

	public function onButtonClick(event: MouseEvent) {}
}
