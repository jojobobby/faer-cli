package characters;

import classes.view.CharSkinListItemFactory;
import game.GameSprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import ui.panels.Panel;
import ui.SimpleText;
import ui.TextButton;

class SkinChangerPanel extends Panel {
	private static inline var TITLE: String = "Change Skin";
	private static inline var CHOOSE: String = "Choose";

	private var button: TextButton;

	public function new(gs: GameSprite) {
		super(gs);

		var title: SimpleText;
		title = new SimpleText(18, 0xFFFFFF, false, Panel.WIDTH, 0);
		title.setBold(true);
		title.wordWrap = true;
		title.multiline = true;
		title.autoSize = TextFieldAutoSize.CENTER;
		title.filters = [new DropShadowFilter(0, 0, 0)];
		title.htmlText = "<p align=\"center\">" + TITLE + "</p>";
		addChild(title);

		this.button = new TextButton(16, CHOOSE);
		this.button.x = Panel.WIDTH / 2 - this.button.width / 2;
		this.button.y = Panel.HEIGHT - this.button.height - 4;
		addChild(this.button);
		this.button.addEventListener(MouseEvent.CLICK, onReskin);

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		this.button.removeEventListener(MouseEvent.CLICK, onReskin);
	}

	private static function onReskin(_: MouseEvent) {
		var view: ReskinCharacterView = new ReskinCharacterView();
		view.setList(CharSkinListItemFactory.make(Global.classModel.getSelected().skins));
		view.x = (Main.stageWidth - view.width) * 0.5;
		view.y = (Main.stageHeight - view.viewHeight) * 0.5;
		Global.layers.dialogs.openDialog(view);
	}
}
