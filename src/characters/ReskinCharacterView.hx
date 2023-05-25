package characters;

import network.NetworkHandler;
import classes.view.CharSkinListItem;
import classes.view.CharSkinListView;
import openfl.display.CapsStyle;
import openfl.display.JointStyle;
import openfl.display.LineScaleMode;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.text.TextFormat;
import openfl.text.TextFormatAlign;
import ui.SimpleText;
import ui.TextButton;
import util.GraphicsUtil;

class ReskinCharacterView extends Sprite {
	private static inline var CANCEL: String = "Cancel";
	private static inline var SELECT: String = "Select";
	private static inline var TITLE_TEXT: String = "Select a Skin";
	private static inline var MARGIN: Int = 10;
	private static inline var DIALOG_WIDTH: Int = CharSkinListView.WIDTH + MARGIN * 2;
	private static inline var BUTTON_WIDTH: Int = 120;
	private static inline var BUTTON_FONT: Int = 16;
	private static inline var BUTTONS_HEIGHT: Int = 40;
	private static inline var TITLE_OFFSET: Int = 27;

	public var viewHeight = 0;

	private var background: Sprite;
	private var list: CharSkinListView;
	private var cancelButton: TextButton;
	private var selectButton: TextButton;

	public function new() {
		super();

		this.background = new Sprite();
		addChild(this.background);

		var text: SimpleText;
		text = new SimpleText(18, 11974326, false, DIALOG_WIDTH, 0);
		var format: TextFormat = text.defaultTextFormat;
		format.align = TextFormatAlign.CENTER;
		format.bold = true;
		text.defaultTextFormat = format;
		text.text = TITLE_TEXT;
		addChild(text);

		this.list = new CharSkinListView();
		this.list.x = MARGIN;
		this.list.y = MARGIN + TITLE_OFFSET;
		addChild(this.list);

		this.cancelButton = new TextButton(BUTTON_FONT, CANCEL, BUTTON_WIDTH);
		addChild(this.cancelButton);
		this.cancelButton.addEventListener(MouseEvent.CLICK, onCancelled);

		this.selectButton = new TextButton(BUTTON_FONT, SELECT, BUTTON_WIDTH);
		addChild(this.selectButton);
		this.selectButton.addEventListener(MouseEvent.CLICK, onSelected);

		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
		this.cancelButton.addEventListener(MouseEvent.CLICK, onCancelled);
		this.selectButton.addEventListener(MouseEvent.CLICK, onSelected);
	}

	private static function onSelected(_: MouseEvent) {
		Global.layers.dialogs.closeDialogs();
		NetworkHandler.reskin(Global.classModel.getSelected().skins.getSelectedSkin().id, null);
	}

	private static function onCancelled(_: MouseEvent) {
		Global.layers.dialogs.closeDialogs();
	}

	public function setList(items: Array<CharSkinListItem>) {
		this.list.setItems(items);

		this.viewHeight = Std.int(Math.min(CharSkinListView.HEIGHT + MARGIN, this.list.getListHeight()));
		this.viewHeight = this.viewHeight + (BUTTONS_HEIGHT + MARGIN * 2 + TITLE_OFFSET);

		this.background.graphics.lineStyle(1, 0xFFFFFF, 1, false, LineScaleMode.NORMAL, CapsStyle.NONE, JointStyle.ROUND, 3);
		this.background.graphics.beginFill(0x363636);
		GraphicsUtil.drawCutEdgeRectGfx(0, 0, DIALOG_WIDTH, this.viewHeight, 4, [1, 1, 1, 1], this.background.graphics);
		this.background.graphics.endFill();
		this.background.graphics.lineStyle(2, 0x5B5B5B, 1, false, LineScaleMode.NONE, CapsStyle.NONE, JointStyle.BEVEL);
		this.background.graphics.moveTo(1, TITLE_OFFSET);
		this.background.graphics.lineTo(DIALOG_WIDTH - 1, TITLE_OFFSET);

		this.cancelButton.x = (width - 2 * this.cancelButton.width) * 0.25;
		this.selectButton.x = (3 * width - 2 * this.selectButton.width) * 0.25;
		this.cancelButton.y = this.selectButton.y = this.viewHeight - this.cancelButton.height - MARGIN;
	}
}
