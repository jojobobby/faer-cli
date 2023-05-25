package ui.view;

import openfl.text.TextFormatAlign;
import openfl.display.Shape;
import openfl.Assets;
import objects.Player;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.filters.DropShadowFilter;
import ui.SimpleText;
import ui.StatusBar;
import util.AnimatedChar;

class CharacterDetailsView extends Sprite {
	private var decor: Bitmap;
	private var portrait: Bitmap;
	private var hpBar: Bitmap;
	private var hpBarText: SimpleText;
	private var mpBar: Bitmap;
	private var mpBarText: SimpleText;
	private var xpBar: Bitmap;
	private var nameText: SimpleText;
	private var scale = 0.0;
	private var lastSkin: AnimatedChar;

	private var lastHp = 0;
	private var lastMaxHp = 0;
	private var lastBoostHp = 0;
	private var lastHpMax = 0;

	private var lastMp = 0;
	private var lastMaxMp = 0;
	private var lastBoostMp = 0;
	private var lastMpMax = 0;

	public function new(scale: Float = 1) {
		super();

		this.decor = new Bitmap(Assets.getBitmapData("assets/ui/playerInterfaceDecor.png"));
		this.decor.scaleX = this.decor.scaleY = 2 * scale;
		this.decor.cacheAsBitmap = true;
		addChild(this.decor);

		this.hpBar = new Bitmap(Assets.getBitmapData("assets/ui/playerInterfaceHealthBar.png"));
		this.hpBar.scaleX = this.hpBar.scaleY = 2 * scale;
		this.hpBar.cacheAsBitmap = true;
		this.hpBar.x = 106 * scale;
		this.hpBar.y = 8 * scale;
		addChild(this.hpBar);

		this.hpBarText = new SimpleText(Std.int(15 * scale), 0xB3B3B3, false, Std.int(360 * scale));
		this.hpBarText.setAlignment(TextFormatAlign.CENTER);
		this.hpBarText.setBold(true);
		this.hpBarText.filters = [new DropShadowFilter(0, 0, 0)];
		this.hpBarText.x = 106;
		this.hpBarText.y = 8 * scale;
		addChild(this.hpBarText);

		this.mpBar = new Bitmap(Assets.getBitmapData("assets/ui/playerInterfaceManaBar.png"));
		this.mpBar.scaleX = this.mpBar.scaleY = 2 * scale;
		this.mpBar.cacheAsBitmap = true;
		this.mpBar.x = 106 * scale;
		this.mpBar.y = 38 * scale;
		addChild(this.mpBar);

		this.mpBarText = new SimpleText(Std.int(15 * scale), 0xB3B3B3, false, Std.int(360 * scale));
		this.mpBarText.setAlignment(TextFormatAlign.CENTER);
		this.mpBarText.setBold(true);
		this.mpBarText.filters = [new DropShadowFilter(0, 0, 0)];
		this.mpBarText.x = 106;
		this.mpBarText.y = 38 * scale;
		addChild(this.mpBarText);

		this.xpBar = new Bitmap(Assets.getBitmapData("assets/ui/playerInterfaceXPBar.png"));
		this.xpBar.scaleX = this.xpBar.scaleY = 2 * scale;
		this.xpBar.cacheAsBitmap = true;
		this.xpBar.x = 106 * scale;
		this.xpBar.y = 68 * scale;
		addChild(this.xpBar);

		this.portrait = new Bitmap(null);
		this.portrait.cacheAsBitmap = true;

		this.nameText = new SimpleText(Std.int(15 * scale), 0xFCDF00, false, 0, 0);
		this.nameText.cacheAsBitmap = true;
		this.scale = scale;
	}

	public function init(player: Player) {
		if (contains(this.portrait))
			removeChild(this.portrait);

		this.portrait.bitmapData = player.getPortrait(2 * this.scale);
		this.portrait.x = (100 * this.scale - this.portrait.width) / 2;
		this.portrait.y = (90 * this.scale - this.portrait.height) / 2;
		addChild(this.portrait);
		this.lastSkin = player.skin;

		if (contains(this.nameText))
			removeChild(this.nameText);

		this.nameText.setBold(true);
		this.nameText.filters = [new DropShadowFilter(0, 0, 0)];
		this.nameText.text = player.name;
		this.nameText.updateMetrics();
		this.nameText.x = (370 * this.scale - this.nameText.width) / 2;
		this.nameText.y = 68 * this.scale;
		addChild(this.nameText);
	}

	public function draw(player: Player) {
		var partialHpCheck = player.hp != this.lastHp || player.maxHP != this.lastMaxHp;
		if (partialHpCheck || player.maxHPBoost != this.lastBoostHp || player.maxHPMax != this.lastHpMax) {
			if (partialHpCheck)
				this.hpBar.scaleX = 2 * this.scale * (player.hp / player.maxHP);

			this.hpBarText.setText('${player.hp}/${player.maxHP} ${player.maxHPBoost > 0 ? '(+${player.maxHPBoost})' : ''}');
			this.hpBarText.setColor(player.maxHP - player.maxHPBoost >= player.maxHPMax ? 0xFCDF00 : (player.maxHPBoost > 0 ? 0x5EB531 : 0xB3B3B3));
			this.hpBarText.updateMetrics();

			this.lastHp = player.hp;
			this.lastMaxHp = player.maxHP;
			this.lastBoostHp = player.maxHPBoost;
			this.lastHpMax = player.maxHPMax;
		}

		var partialMpCheck = player.mp != this.lastMp || player.maxMP != this.lastMaxMp;
		if (partialMpCheck || player.maxMPBoost != this.lastBoostMp || player.maxMPMax != this.lastMpMax) {
			if (partialMpCheck)
				this.mpBar.scaleX = 2 * this.scale * (player.mp / player.maxMP);

			this.mpBarText.setText('${player.mp}/${player.maxMP} ${player.maxMPBoost > 0 ? '(+${player.maxMPBoost})' : ''}');
			this.mpBarText.setColor(player.maxMP - player.maxMPBoost >= player.maxMPMax ? 0xFCDF00 : (player.maxMPBoost > 0 ? 0x5EB531 : 0xB3B3B3));
			this.mpBarText.updateMetrics();

			this.lastMp = player.mp;
			this.lastMaxMp = player.maxMP;
			this.lastBoostMp = player.maxMPBoost;
			this.lastMpMax = player.maxMPMax;
		}	
	}
}
