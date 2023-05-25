package ui.tooltip;

import assets.CharacterFactory;
import classes.model.CharacterClass;
import classes.model.CharacterSkin;
import constants.GeneralConstants;
import objects.Player;
import ui.GameObjectListItem;
import ui.panels.itemgrids.EquippedGrid;
import ui.panels.itemgrids.InventoryGrid;
import ui.StatusBar;

class MyPlayerToolTip extends ToolTip {
	public var player: Player;

	private var playerPanel: GameObjectListItem;
	private var hpBar: StatusBar;
	private var mpBar: StatusBar;
	private var eGrid: EquippedGrid;
	private var iGrid: InventoryGrid;

	public function new(accountName: String, charXML: Xml) {
		super(0x363636, 1, 0xFFFFFF, 1);
		this.player = Player.fromPlayerXML(accountName, charXML);
		var chrClass: CharacterClass = Global.classModel.getCharacterClass(this.player.objectType);
		var skin: CharacterSkin = chrClass.skins.getSkin(Std.parseInt(charXML.elementsNamed("Texture").next().firstChild().nodeValue));
		this.player.animatedChar = CharacterFactory.makeCharacter(skin.template);
		this.playerPanel = new GameObjectListItem(0xB3B3B3, true, this.player);
		addChild(this.playerPanel);
		if (player.maxMP < 0) {
			this.hpBar = new StatusBar(176, 40, 0xE03434, 0x545454);
			this.hpBar.x = 6;
			this.hpBar.y = 40;
			addChild(this.hpBar);
		} else {
			this.hpBar = new StatusBar(176, 16, 0xE03434, 0x545454);
			this.hpBar.x = 6;
			this.hpBar.y = 40;
			addChild(this.hpBar);
			this.mpBar = new StatusBar(176, 16, 0x6084E0, 0x545454);
			this.mpBar.x = 6;
			this.mpBar.y = 64;
			addChild(this.mpBar);
		}

		this.eGrid = new EquippedGrid(null, this.player.slotTypes, this.player);
		this.eGrid.x = 8;
		this.eGrid.y = 88;
		addChild(this.eGrid);
		this.eGrid.setItems(this.player.equipment);
		this.iGrid = new InventoryGrid(null, this.player, GeneralConstants.NUM_EQUIPMENT_SLOTS);
		this.iGrid.x = 8;
		this.iGrid.y = 132;
		addChild(this.iGrid);
		this.iGrid.setItems(this.player.equipment);
	}

	override public function draw() {
		this.hpBar.draw(this.player.hp, this.player.maxHP, this.player.maxHPBoost, this.player.maxHPMax);
		this.mpBar?.draw(this.player.mp, this.player.maxMP, this.player.maxMPBoost, this.player.maxMPMax);
		super.draw();
	}
}
