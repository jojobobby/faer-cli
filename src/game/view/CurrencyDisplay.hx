package game.view;

import game.GameSprite;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;
import util.AssetLibrary;
import util.TextureRedrawer;

class CurrencyDisplay extends Sprite {
	public static inline var RIGHT_TO_LEFT: String = "rtl";
	public static inline var LEFT_TO_RIGHT: String = "ltr";

	private var gemText: SimpleText;
	private var goldText: SimpleText;
	private var crownText: SimpleText;
	private var gemIcon: Bitmap;
	private var goldIcon: Bitmap;
	private var crownIcon: Bitmap;
	private var gems: Int = -1;
	private var gold: Int = -1;
	private var crowns: Int = -1;
	private var gs: GameSprite;
	private var orientation = "";

	public function new(orientation: String, gs: GameSprite = null) {
		super();

		this.orientation = orientation;
		this.gs = gs;

		this.gemText = new SimpleText(14, 0xFFFFFF, false, 0, 0);
		this.gemText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4, 2)];
		addChild(this.gemText);
		var gemTex: BitmapData = AssetLibrary.getImageFromSet("misc", 21);
		this.gemIcon = new Bitmap(TextureRedrawer.redraw(gemTex, 30, true, 0));
		addChild(this.gemIcon);

		this.goldText = new SimpleText(14, 0xFFFFFF, false, 0, 0);
		this.goldText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4, 2)];
		addChild(this.goldText);
		var goldTex: BitmapData = AssetLibrary.getImageFromSet("misc", 20);
		this.goldIcon = new Bitmap(TextureRedrawer.redraw(goldTex, 30, true, 0));
		addChild(this.goldIcon);

		this.crownText = new SimpleText(14, 0xFFFFFF, false, 0, 0);
		this.crownText.filters = [new DropShadowFilter(0, 0, 0, 1, 4, 4, 2)];
		addChild(this.crownText);
		var crownTex: BitmapData = AssetLibrary.getImageFromSet("misc16", 50);
		this.crownIcon = new Bitmap(TextureRedrawer.redraw(crownTex, 17, true, 0));
		addChild(this.crownIcon);

		this.draw(0, 0, 0);

		mouseEnabled = false;
		doubleClickEnabled = false;
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		Global.playerModel.gemsChanged.on(this.onGemsChanged);
		Global.playerModel.goldChanged.on(this.onGoldChanged);
		Global.playerModel.crownsChanged.on(this.onCrownsChanged);
		this.draw(Global.playerModel.getGems(), Global.playerModel.getGold(), Global.playerModel.getCrowns());
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		Global.playerModel.gemsChanged.off(this.onGemsChanged);
		Global.playerModel.goldChanged.off(this.onGoldChanged);
		Global.playerModel.crownsChanged.off(this.onCrownsChanged);
	}

	private function onGemsChanged(gems: Int) {
		this.draw(gems, Global.playerModel.charList.gold, Global.playerModel.charList.crowns);
	}

	private function onGoldChanged(gold: Int) {
		this.draw(Global.playerModel.charList.gems, gold, Global.playerModel.charList.crowns);
	}

	private function onCrownsChanged(crowns: Int) {
		this.draw(Global.playerModel.charList.gems, Global.playerModel.charList.gold, crowns);
	}

	public inline function draw(gems: Int, gold: Int, crowns: Int) {
		if (gems == this.gems && gold == this.gold && crowns == this.crowns)
			return;

		this.gems = gems;
		this.gold = gold;
		this.crowns = crowns;

		switch (this.orientation) {
			case RIGHT_TO_LEFT:
				this.gemIcon.x = -this.gemIcon.width;
				this.gemText.text = Std.string(this.gems);
				this.gemText.updateMetrics();
				this.gemText.x = this.gemIcon.x - this.gemText.width;
				this.gemText.y = this.gemIcon.height / 2 - this.gemText.height / 2;

				this.goldIcon.x = this.gemText.x - this.goldIcon.width;
				this.goldText.text = Std.string(this.gold);
				this.goldText.updateMetrics();
				this.goldText.x = this.goldIcon.x - this.goldText.width;
				this.goldText.y = this.goldIcon.height / 2 - this.goldText.height / 2;

				this.crownIcon.x = this.goldText.x - this.crownIcon.width;
				this.crownText.text = Std.string(this.crowns);
				this.crownText.updateMetrics();
				this.crownText.x = this.crownIcon.x - this.crownText.width;
				this.crownText.y = this.crownIcon.height / 2 - this.crownText.height / 2;
			case LEFT_TO_RIGHT:
				this.gemText.text = Std.string(this.gems);
				this.gemText.updateMetrics();
				this.gemText.x = this.gemIcon.x + this.gemIcon.width;
				this.gemText.y = this.gemIcon.height / 2 - this.gemText.height / 2;

				this.goldIcon.x = this.gemText.x + this.gemText.width;
				this.goldText.text = Std.string(this.gold);
				this.goldText.updateMetrics();
				this.goldText.x = this.goldIcon.x + this.goldIcon.width;
				this.goldText.y = this.goldIcon.height / 2 - this.goldText.height / 2;

				this.crownIcon.x = this.goldText.x + this.goldText.width;
				this.crownText.text = Std.string(this.crowns);
				this.crownText.updateMetrics();
				this.crownText.x = this.crownIcon.x + this.crownIcon.width;
				this.crownText.y = this.crownIcon.height / 2 - this.crownText.height / 2;
		}
	}
}
