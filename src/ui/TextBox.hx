package ui;

import openfl.Assets;
import openfl.display.Bitmap;
import util.NativeTypes;
import network.NetworkHandler;
import lime.system.System;
import game.GameSprite;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.MouseEvent;
import openfl.events.TimerEvent;
import openfl.filters.GlowFilter;
import openfl.text.TextField;
import openfl.text.TextFieldType;
import openfl.text.TextFormat;
import openfl.utils.Timer;
import util.Utils;
import util.Settings;

using StringTools;

class TextBox extends Sprite {
	private static inline final MAX_LINES = 10;
	private static inline final INDENT = 20;
	private static inline final MIN_LINE_HEIGHT = 16;
	private static inline final BLOCK_SPACING = 20;
	public static var isInputtingText = false;
	private static var lines = new Array<TextBoxLine>();

	public var textSprite: Sprite;

	private var gs: GameSprite;
	private var w = 0;
	private var h = 0;
	private var textSpriteYPos = 0.0;
	private var inputField: TextField;
	private var showMax = false;
	private var lc = 0;
	private var tellers: Array<String>;
	private var currentTeller = 0;
	private var timer: Timer;
	private var selectedMessageIdx = -1;
	private var decor: Bitmap;

	public function new(gs: GameSprite, w: Int, h: Int) {
		super();

		this.tellers = [];
		this.timer = new Timer(1000);
		this.gs = gs;
		this.w = w;
		this.h = h;
		this.decor = new Bitmap(Assets.getBitmapData("assets/ui/chat.png"));
		this.decor.cacheAsBitmap = true;
		this.decor.visible = false;
		addChild(this.decor);
		this.textSprite = new Sprite();
		this.textSprite.x = 5;
		this.textSprite.filters = [new GlowFilter(0, 1, 3, 3, 2, 1)];
		this.textSprite.mouseEnabled = false;
		this.textSprite.mouseChildren = false;
		addChild(this.textSprite);
		var format: TextFormat = new TextFormat();
		format.font = "Faer";
		format.size = 14;
		format.color = 0xFFFFFF;
		format.bold = true;
		this.inputField = new TextField();
		this.inputField.embedFonts = true;
		this.inputField.defaultTextFormat = format;
		this.inputField.type = TextFieldType.INPUT;
		this.inputField.border = false;
		this.inputField.maxChars = 128;
		this.inputField.filters = [new GlowFilter(0, 1, 3, 3, 2, 1)];
		this.inputField.addEventListener(KeyboardEvent.KEY_UP, this.onInputFieldKeyUp);
		this.inputField.width = this.w - 10;
		this.inputField.height = 18;
		this.inputField.x = 5;
		this.inputField.y = -5;
		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
		this.inputField.addEventListener(MouseEvent.CLICK, onClick);
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);

		this.addText(Settings.BUILD_LABEL, 0x0000FF);
	}

	private function onClick(_: MouseEvent) {
		this.stage.focus = null;
	}

	public function addText(text: String, textColor: UInt32) {
		var textBoxLine = new TextBoxLine(System.getTimer(), "", text, "", false, 0xFFFFFF, textColor);
		lines.push(textBoxLine);
		this.refreshStatusBox();
	}

	public function addTextWithName(name: String, text: String, nameColor: UInt32, textColor: UInt32) {
		var textBoxLine = new TextBoxLine(System.getTimer(), name, text, "", false, nameColor, textColor);
		lines.push(textBoxLine);
		this.refreshStatusBox();
	}

	public function addTextFull(name: String, recipient: String, text: String, nameColor: UInt32, textColor: UInt32) {
		var fromMe = recipient != "" && name == Global.playerModel.getName();
		var toMe = recipient == Global.playerModel.getName();
		var textBoxLine = new TextBoxLine(System.getTimer(), name, text, recipient, toMe, nameColor, textColor);
		lines.push(textBoxLine);
		this.refreshStatusBox();
		if (toMe) {
			if (this.tellers.length == 0 || this.tellers[this.tellers.length - 1] != name)
				this.tellers.push(name);
		} else if (recipient != "*Guild*" && fromMe && this.tellers.length == 0 || this.tellers[this.tellers.length - 1] != recipient)
			this.tellers.push(recipient);
	}

	private function clearTextSprite() {
		this.textSprite.removeChildren();
		this.textSprite.visible = false;
		this.textSpriteYPos = 0;
	}

	private function addTextBlock(text: String) {
		var textSpr = new SimpleText(14, 0xFFFFFF, false, 395);
		textSpr.wordWrap = true;
		textSpr.setHtmlText(text);
		textSpr.updateMetrics();
		textSpr.y = this.textSpriteYPos;
		this.textSprite.addChild(textSpr);
		this.textSprite.visible = true;
		this.textSpriteYPos += BLOCK_SPACING * textSpr.numLines;
	}

	private function refreshStatusBox() {
		this.clearTextSprite();

		var now = System.getTimer();
		var startL = Std.int(Math.max(0, lines.length - 1 - this.lc - MAX_LINES));
		var endL = Std.int(Math.min(lines.length, startL + MAX_LINES + 1));
		for (l in startL...endL) {
			var line = lines[l];
			if (this.showMax || now <= line.time + 20000) {
				if (line.name == "" || line.name == null) {
					this.addTextBlock('<i><b><font color=\"#${line.textColor.hex(6)}\">' + line.text.replace("<", "&lt;") + '</b></i></font>');
					continue;
				}
				
				this.addTextBlock('<b><font color=\"#${line.nameColor.hex(6)}\">[' + line.name 
					+ ']:</b></font> <i><font color=\"#${line.textColor.hex(6)}\">'
					+ line.text.replace("<", "&lt;") + '</font></i>');
			}
		}

		this.placeTextField();
	}

	private function insertTellPrefix(backward: Bool) {
		this.inputField.text = "/tell ";
		if (this.tellers.length != 0) {
			if (backward)
				this.currentTeller++;
			else
				this.currentTeller--;

			if (this.currentTeller <= 0)
				this.currentTeller = 0;

			if (this.currentTeller >= this.tellers.length)
				this.currentTeller = this.tellers.length - 1;

			this.inputField.appendText(this.tellers[this.currentTeller] + " ");
		}

		this.inputField.setSelection(this.inputField.length, this.inputField.length);
	}

	private function selectInput() {
		this.decor.visible = true;

		this.inputField.type = TextFieldType.INPUT;
		TextBox.isInputtingText = true;
		if (!contains(this.inputField))
			addChild(this.inputField);
		if (stage != null)
			stage.focus = this.inputField;

		this.placeTextField();
		this.currentTeller = this.tellers.length;
	}

	private function unselectInput() {
		if (stage != null)
			stage.focus = null;

		this.decor.visible = false;

		if (contains(this.inputField)) {
			TextBox.isInputtingText = false;
			removeChild(this.inputField);
		}

		this.placeTextField();
	}

	private function placeTextField() {
		if (contains(this.inputField))
			this.textSprite.y = this.h - 20 - this.inputField.height - this.textSpriteYPos;
		else
			this.textSprite.y = this.h - 4 - this.textSpriteYPos;
	}

	private function onTimer(event: TimerEvent) {
		this.refreshStatusBox();
	}

	private function onAddedToStage(event: Event) {
		stage.addEventListener(KeyboardEvent.KEY_UP, this.onKeyUp);
		this.inputField.y = this.h - 25;
		this.placeTextField();
		this.timer.addEventListener(TimerEvent.TIMER, this.onTimer);
		this.timer.start();
	}

	private function onRemovedFromStage(event: Event) {
		stage.removeEventListener(KeyboardEvent.KEY_UP, this.onKeyUp);
		this.timer.stop();
		this.timer.removeEventListener(TimerEvent.TIMER, this.onTimer);
	}

	private function onKeyUp(event: KeyboardEvent) {
		var keyCode: KeyCode = event.keyCode;
		if (keyCode == Settings.chatCmd) {
			if (stage.focus == null) {
				this.selectInput();
				this.inputField.text = "/";
				this.inputField.setSelection(this.inputField.length, this.inputField.length);
			}
		} else if (keyCode == Settings.chat) {
			if (stage.focus == null)
				this.selectInput();
		} else if (keyCode == Settings.respond) {
			if (stage.focus == null)
				this.selectInput();

			this.insertTellPrefix(event.shiftKey);
		} else if (keyCode == Settings.guildChat) {
			if (stage.focus == null) {
				this.selectInput();
				this.inputField.text = "/g ";
				this.inputField.setSelection(this.inputField.length, this.inputField.length);
			}
		} else if (keyCode == Settings.chatUp) {
			if (!this.showMax)
				this.showMax = true;
			else
				this.lc = Std.int(Math.max(0, Math.min(lines.length - MAX_LINES, this.lc + MAX_LINES)));

			this.refreshStatusBox();
		} else if (keyCode == Settings.chatDown) {
			if (this.lc == 0)
				this.showMax = false;
			else
				this.lc = Std.int(Math.max(0, this.lc - MAX_LINES));

			this.refreshStatusBox();
		} else if (keyCode == KeyCode.Up) {
			if (stage.focus == this.inputField && selectedMessageIdx < Settings.messagesSent.length - 1) {
				this.inputField.text = Settings.messagesSent[Settings.messagesSent.length - ++selectedMessageIdx - 1];
				this.inputField.setSelection(this.inputField.length, this.inputField.length);
			}
		} else if (keyCode == KeyCode.Down) {
			if (stage.focus == this.inputField && selectedMessageIdx > 0) {
				this.inputField.text = Settings.messagesSent[Settings.messagesSent.length - --selectedMessageIdx - 1];
				this.inputField.setSelection(this.inputField.length, this.inputField.length);
			}
		}
	}

	private function onInputFieldKeyUp(event: KeyboardEvent) {
		if (event.keyCode == Settings.chat) {
			if (this.inputField.text.length != 0) {
				if (this.gs.map.player != null)
					NetworkHandler.playerText(this.inputField.text);
				Settings.messagesSent.push(this.inputField.text);
				selectedMessageIdx = 0;
				this.inputField.text = "";
			}

			this.unselectInput();
			event.stopImmediatePropagation();
		}
	}
}
