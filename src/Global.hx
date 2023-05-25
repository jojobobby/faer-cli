package;

import account.Account;
import account.services.UploadXmlTask;
import account.services.UploadBehaviorTask;
import mapeditor.MapEditor;
import openfl.Assets;
import engine.TextureFactory;
import util.Signal;
import lib.tasks.Task;
import openfl.events.Event;
import lime.system.System;
import account.services.BuyCharacterSlotTask;
import account.services.BuySkinTask;
import account.services.ChangePasswordTask;
import account.services.DeleteCharacterTask;
import account.services.GetCharListTask;
import account.services.LoadAccountTask;
import account.services.LoginTask;
import account.services.RegisterAccountTask;
import account.services.SendPasswordReminderTask;
import account.view.BuyingDialog;
import appengine.SavedCharactersList;
import assets.CharacterTemplate;
import characters.CharacterModel;
import characters.DeletingCharacterView;
import classes.model.CharacterSkin;
import classes.model.CharacterSkinState;
import classes.model.ClassModel;
import constants.UseType;
import core.Layers;
import core.PlayerModel;
import game.GameSprite;
import game.model.GameInitData;
import game.model.VialModel;
import lime.utils.ObjectPool;
import network.NetworkHandler;
import objects.Projectile;
import openfl.display.Sprite;
import screens.AccountLoadingScreen;
import screens.CharacterSelectionScreen;
import screens.LoadingScreen;
import servers.Server;
import servers.ServerModel;
import ui.dialogs.Dialog;
import ui.dialogs.ErrorDialog;
import ui.model.TabStripModel;
import ui.view.TitleView;

using util.Utils;

final class Global {
	public static var currentInteractiveTarget = 0;
	public static var gameSprite: GameSprite;
	public static var layers: Layers;

	public static var currentEditor: MapEditor;

	public static var projPool: ObjectPool<Projectile>;

	public static var serverModel: ServerModel;
	public static var classModel: ClassModel;
	public static var playerModel: PlayerModel;
	public static var charModel: CharacterModel;
	public static var tabStripModel: TabStripModel;

	public static var loadTask: LoadAccountTask;
	public static var loginTask: LoginTask;
	public static var charListTask: GetCharListTask;
	public static var deleteCharacterTask: DeleteCharacterTask;
	public static var buyCharacterSlotTask: BuyCharacterSlotTask;
	public static var registerAccountTask: RegisterAccountTask;
	public static var changePasswordTask: ChangePasswordTask;
	public static var sendPasswordReminderTask: SendPasswordReminderTask;
	public static var buySkinTask: BuySkinTask;
	public static var uploadBehaviorTask: UploadBehaviorTask;
	public static var uploadXmlTask: UploadXmlTask;

	public static var updateAccount: EmptySignal;
	public static var focusCharSkin: Signal<CharacterSkin>;

	public static function init(root: Sprite) {
		projPool = new ObjectPool<Projectile>(() -> {
			return new Projectile();
		});

		loadTask = new LoadAccountTask();
		loginTask = new LoginTask();
		charListTask = new GetCharListTask();
		deleteCharacterTask = new DeleteCharacterTask();
		buyCharacterSlotTask = new BuyCharacterSlotTask();
		registerAccountTask = new RegisterAccountTask();
		changePasswordTask = new ChangePasswordTask();
		sendPasswordReminderTask = new SendPasswordReminderTask();
		buySkinTask = new BuySkinTask();
		uploadBehaviorTask = new UploadBehaviorTask();
		uploadXmlTask = new UploadXmlTask();

		serverModel = new ServerModel();
		classModel = new ClassModel();
		playerModel = new PlayerModel();
		charModel = new CharacterModel();
		tabStripModel = new TabStripModel();

		updateAccount = new EmptySignal();
		focusCharSkin = new Signal<CharacterSkin>();

		layers = new Layers();
		root.addChild(layers);

		var playersXML = Assets.getText("assets/xmls/Players.xml").asXml();
		var skinsXML = Assets.getText("assets/xmls/Skins.xml").asXml();

		for (xml in playersXML.elements()) {
			var charType = xml.intAttribute("type");
			var character = classModel.getCharacterClass(charType);
			character.id = charType;
			character.name = xml.attribute("id");
			character.description = xml.element("Description");
			character.hitSound = xml.element("HitSound");
			character.deathSound = xml.element("DeathSound");
			character.bloodProb = xml.intElement("BloodProb");
			character.slotTypes = xml.intListElement("SlotTypes");
			character.defaultEquipment = xml.intListElement("Equipment");
			character.skins.addSkin(makeDefaultSkin(xml), true);
			classModel.map.set(charType, character);
		}

		for (xml in skinsXML.elements()) {
			var animXML = xml.elementsNamed("AnimatedTexture").next();
			var file = animXML.element("Sheet");
			var index = animXML.intElement("Index");
			var skin = new CharacterSkin();
			skin.id = xml.intAttribute("type");
			skin.name = xml.attribute("id");
			skin.template = new CharacterTemplate(file, index);
			classModel.getCharacterClass(xml.intElement("PlayerClassType")).skins.addSkin(skin);
		}

		Main.primaryStage3D.addEventListener(Event.CONTEXT3D_CREATE, function(_: Event) {
			Main.atlas = TextureFactory.make(Main.tempAtlas, false);
			#if print_atlas
			var imageData = Main.tempAtlas.encode(new openfl.geom.Rectangle(0, 0, 4096, 4096), new openfl.display.PNGEncoderOptions());
			var fileOut = sys.io.File.write("atlas.png", true);
			fileOut.writeBytes(imageData, 0, imageData.length);
			fileOut.close();
			#end
			Main.tempAtlas.dispose();

			layers.screens.setScreen(new AccountLoadingScreen());
			loadTask.start();
			charListTask.start();
			updateAccount.emit();
			layers.screens.setScreen(new TitleView());
		});
		Main.primaryStage3D.requestContext3D();
	}

	private static function makeDefaultSkin(xml: Xml) {
		var animXML = xml.elementsNamed("AnimatedTexture").next();
		var file = animXML.element("Sheet");
		var index = animXML.intElement("Index");
		var skin = new CharacterSkin();
		skin.id = -1;
		skin.name = "Classic";
		skin.template = new CharacterTemplate(file, index);
		skin.setState(CharacterSkinState.OWNED);
		skin.setIsSelected(true);
		return skin;
	}

	public static function playGame(gameInit: GameInitData) {
		playerModel.currentCharId = gameInit.charId;
		gameSprite = new GameSprite(serverModel.getServer(), gameInit.gameId, gameInit.createCharacter, gameInit.charId, gameInit.fmMap);
		layers.screens.setScreen(gameSprite);
	}

	public static function useVial(vialId: Int) {
		var player = gameSprite.map.player;
		if (player.getVialCount(vialId) <= 0 || vialId == VialModel.HEALTH_VIAL_ID && player.hp >= player.maxHP || vialId == VialModel.MAGIC_VIAL_ID
			&& player.mp >= player.maxMP)
			return;

		NetworkHandler.useItem(System.getTimer(), player.objectId, VialModel.getVialSlot(vialId), vialId, player.mapX, player.mapY, UseType.START_USE);
	}

	public static function parseCharList(xml: Xml) {
		for (iterXML in xml.elementsNamed("ItemCosts").next().elementsNamed("ItemCost")) {
			var skin = classModel.getCharacterSkin(iterXML.intAttribute("type"));
			if (skin != null)
				skin.cost = iterXML.intValue();
		}

		Account.updateUser(xml.elementsNamed("Account").next().element("Name"), Account.email, Account.password);

		for (owned in xml.intListElement("OwnedSkins"))
			classModel.getCharacterSkin(owned) ?.setState(CharacterSkinState.OWNED);

		playerModel.setCharacterList(new SavedCharactersList(xml));
		playerModel.isInvalidated = false;

		var list = new Array<Server>();
		for (iterXML in xml.elementsNamed("Servers").next().elementsNamed("Server"))
			list.push(new Server().setName(XmlUtil.element(iterXML, "Name"))
				.setAddress(XmlUtil.element(iterXML, "DNS"))
				.setPort(2050)
				.setLatLong(XmlUtil.floatElement(iterXML, "Lat"), XmlUtil.floatElement(iterXML, "Long"))
				.setUsage(XmlUtil.floatElement(iterXML, "Usage"))
				.setIsAdminOnly(iterXML.elementsNamed("AdminOnly").hasNext()));

		serverModel.setServers(list);
	}

	public static function deleteChar() {
		layers.dialogs.openDialog(new DeletingCharacterView());
		deleteCharacterTask.finished.once(function(taskData: TaskData) {
			if (taskData.success) {
				layers.screens.setScreen(new CharacterSelectionScreen());
				layers.dialogs.closeDialogs();
			} else
				layers.dialogs.openDialog(new Dialog("", "Unable to delete character"));
		});
		deleteCharacterTask.start();
	}

	public static function buyCharSlot() {
		if (playerModel.getGems() < playerModel.getNextCharSlotPrice()) {
			layers.dialogs.openDialog(new Dialog("Not Enough " + (playerModel.isNextCharSlotCurrencyGems() ? "Gems" : "Gold"),
				"Insufficient funds when trying to buy a slot.", "Close", null));
			return;
		}

		layers.dialogs.openDialog(new BuyingDialog());

		buyCharacterSlotTask.finished.once(function(taskData: TaskData) {
			if (taskData.success)
				layers.screens.setScreen(new CharacterSelectionScreen());
			else
				layers.dialogs.openDialog(new ErrorDialog("Unable to complete character slot purchase"));
			layers.dialogs.closeDialogs();
		});
		buyCharacterSlotTask.start();
	}

	public static function invalidate() {
		playerModel.isInvalidated = true;
	}

	public static function setScreenValid(sprite: Sprite) {
		if (playerModel.isInvalidated) {
			layers.screens.setScreen(new LoadingScreen());
			charListTask.start();
		}

		layers.screens.setScreen(sprite);
	}
}
