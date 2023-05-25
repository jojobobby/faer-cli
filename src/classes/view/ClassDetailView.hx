package classes.view;

import assets.Animation;
import assets.CharacterFactory;
import classes.model.CharacterSkin;
import haxe.ds.IntMap;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.TimerEvent;
import openfl.filters.DropShadowFilter;
import openfl.text.TextFieldAutoSize;
import openfl.text.TextFormat;
import openfl.text.TextFormatAlign;
import openfl.utils.Timer;
import ui.SimpleText;

class ClassDetailView extends Sprite {
	private static inline var WIDTH: Int = 344;
	private static inline var TEXT_WIDTH: Int = 188;

	private var skins: IntMap<Animation> = new IntMap<Animation>();
	private var nextSkinTimer: Timer = new Timer(250, 1);

	private var nextSkin: CharacterSkin;
	private var classNameText: SimpleText;
	private var classDescriptionText: SimpleText;
	private var animContainer: Sprite;
	private var animation: Animation;

	public function new() {
		super();

		var dropShadowFilter: DropShadowFilter;
		dropShadowFilter = new DropShadowFilter(0, 0, 0, 1, 8, 8);
		this.animContainer = new Sprite();
		this.animContainer.x = (WIDTH - 104) * 0.5;
		addChild(this.animContainer);
		this.classNameText = new SimpleText(20, 0xFFFFFF, false, 0, 0);
		this.classNameText.setBold(true);
		this.classNameText.filters = [dropShadowFilter];
		this.classNameText.width = TEXT_WIDTH;
		this.classNameText.autoSize = TextFieldAutoSize.CENTER;
		addChild(this.classNameText);
		this.classDescriptionText = new SimpleText(14, 0xFFFFFF, false, 0, 0);
		this.classDescriptionText.filters = [dropShadowFilter];
		this.classDescriptionText.width = TEXT_WIDTH;
		this.classDescriptionText.wordWrap = true;
		var tf: TextFormat = this.classDescriptionText.getTextFormat();
		tf.align = TextFormatAlign.CENTER;
		this.classDescriptionText.defaultTextFormat = tf;
		this.classDescriptionText.setTextFormat(tf);
		addChild(this.classDescriptionText);
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.nextSkinTimer.addEventListener(TimerEvent.TIMER, this.delayedFocusSet);
		Global.focusCharSkin.once(this.onFocusSet);
		this.setData(Global.classModel.getSelected().name, Global.classModel.getSelected().description);
		this.onFocusSet();
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.nextSkinTimer.removeEventListener(TimerEvent.TIMER, this.delayedFocusSet);
		this.setWalkingAnimation(null);

		for (skin in this.skins)
			skin.dispose();
	}

	private function onFocusSet(skin: CharacterSkin = null) {
		this.nextSkin = skin != null ? skin : Global.classModel.getSelected().skins.getSelectedSkin();
		this.nextSkinTimer.start();
	}

	private function delayedFocusSet(e: TimerEvent) {
		if (!this.skins.exists(this.nextSkin.id))
			this.skins.set(this.nextSkin.id, CharacterFactory.makeWalkingIcon(this.nextSkin.template, 200));

		this.setWalkingAnimation(this.skins.get(this.nextSkin.id));
	}

	public function setData(name: String, description: String) {
		this.classNameText.text = name;
		this.classDescriptionText.text = description;
		this.layout();
	}

	public function setWalkingAnimation(value: Animation) {
		if (this.animation != null)
			this.removeAnimation(this.animation);
		this.animation = value;
		if (this.animation != null)
			this.addAnimation(this.animation);
		this.layout();
	}

	private function removeAnimation(animation: Animation) {
		animation.stop();
		this.animContainer.removeChild(animation);
	}

	private function addAnimation(animation: Animation) {
		this.animContainer.addChild(animation);
		animation.start();
	}

	private function layout() {
		this.classNameText.x = WIDTH / 2 - this.classNameText.width / 2;
		this.classNameText.y = 110;
		this.classDescriptionText.y = this.classNameText.y + this.classNameText.textHeight + 5;
		this.classDescriptionText.x = WIDTH / 2 - this.classDescriptionText.width / 2;
	}
}
