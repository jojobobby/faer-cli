package game;

import util.Utils.MathUtil;
import util.Utils.StringUtils;
import util.Settings;
#if !disable_rpc
import hxdiscord_rpc.Types;
import hxdiscord_rpc.Discord;
#end
import map.Camera;
import network.NetworkHandler;
import openfl.display.OpenGLRenderer;
import openfl.events.RenderEvent;
import util.NativeTypes;
import lime.system.System;
import screens.CharacterSelectionScreen;
import game.view.CurrencyDisplay;
import map.Map;
import ui.MiniMap;
import objects.Player;
import objects.Projectile;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.filters.DropShadowFilter;
import servers.Server;
import ui.GuildText;
import ui.SimpleText;
import ui.TextBox;
import ui.view.CharacterDetailsView;
import ui.view.Inventory;
import util.PointUtil;
import openfl.utils.ByteArray;

using StringTools;

class GameSprite extends Sprite {
	public var map: Map;
	public var inputHandler: InputHandler;
	public var textBox: TextBox;
	public var miniMap: MiniMap;
	public var characterDetails: CharacterDetailsView;
	public var inventory: Inventory;
	public var guildText: GuildText;
	public var currencyDisplay: CurrencyDisplay;
	public var lastUpdate: Int32 = 0;
	public var lastFixedUpdate: Int32 = 0;
	public var moveRecords: MoveRecords;
	public var statsView: SimpleText;
	public var lastFrameUpdate: Int32 = 0;
	public var frames: Int32 = 0;
	public var fps: Int32 = 0;

	private var focus: Player;

	public var isGameStarted = false;

	private var uiInited = false;
	private var inited = false;
	private var fromEditor = false;

	public function new(server: Server, gameId: Int, createCharacter: Bool, charId: Int, fmMap: ByteArray) {
		super();

		this.moveRecords = new MoveRecords();
		this.map = new Map();
		this.fromEditor = fmMap?.length > 0;
		NetworkHandler.reset(server, gameId, createCharacter, charId, fmMap);
		this.inputHandler = new InputHandler(this);
		this.textBox = new TextBox(this, 400, 250);
		this.textBox.y = Math.max(0, Main.stageHeight - this.textBox.height);
		addChild(this.textBox);
		addEventListener(Event.ADDED_TO_STAGE, this.onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, this.onAdded);
		NetworkHandler.connect();
	}

	public function close() {
		stage.removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
		stage.removeEventListener(Event.RESIZE, this.onResize);
		if (contains(this.miniMap))
			removeChild(this.miniMap);
		if (this.map != null)
			this.map.dispose();
		if (this.miniMap != null)
			this.miniMap.dispose();
		Projectile.disposeBullId();
		Global.layers.dialogs.closeDialogs();
		Global.layers.screens.setScreen(fromEditor ? Global.currentEditor : new CharacterSelectionScreen());
	}

	public function setFocus(focus: Player) {
		focus = focus != null ? focus : this.map.player;
		this.focus = focus;
	}

	public function addStatsView() {
		if (this.statsView != null)
			return;

		this.statsView = new SimpleText(14, 0xFFFFFF);
		this.statsView.cacheAsBitmap = true;
		this.statsView.setText("FPS: -1\nMemory: -1 MB");
		this.statsView.filters = [new DropShadowFilter()];
		this.statsView.setBold(true);
		this.statsView.updateMetrics();
		this.statsView.x = 510;
		this.statsView.y = 35;
		addChild(this.statsView);
	}

	public function updateStats(time: Int32) {
		this.frames++;
		var dt = time - this.lastFrameUpdate;
		if (dt >= 1000) {
			this.lastFrameUpdate = time;
			this.statsView.text = 'FPS: ${this.frames}\nMemory: ${Math.round((untyped __global__.__hxcpp_gc_used_bytes()) / (1024 * 1024))} MB';
			this.statsView.updateMetrics();
			this.frames = 0;
		}
	}

	public function initialize() {
		if (this.inited) {
			this.miniMap.update();
			for (go in this.map.gameObjects)
				go.dispose();
			this.map.gameObjects.resize(0);
			this.map.gameObjectsLen = 0;

			this.map.speechBalloons.clear();
			this.map.statusTexts.resize(0);
			this.connect();
			return;
		}

		this.connect();
		this.map.initialize();

		this.miniMap = new MiniMap(200, 200);
		this.miniMap.x = Main.stageWidth - 120;
		this.miniMap.y = 100;
		addChild(this.miniMap);

		this.characterDetails = new CharacterDetailsView();
		this.characterDetails.cacheAsBitmap = true;
		this.characterDetails.x = this.characterDetails.y = 20;
		addChild(this.characterDetails);

		this.inventory = new Inventory();
		this.inventory.cacheAsBitmap = true;
		this.inventory.x = Main.stageWidth - 220;
		this.inventory.y = Main.stageHeight - 320;
		addChild(this.inventory);

		this.currencyDisplay = new CurrencyDisplay(CurrencyDisplay.LEFT_TO_RIGHT, this);
		this.currencyDisplay.cacheAsBitmap = true;
		this.currencyDisplay.x = 300;
		this.currencyDisplay.y = 90;
		addChild(this.currencyDisplay);

		this.guildText = new GuildText("", -1);
		this.guildText.cacheAsBitmap = true;
		this.guildText.x = 64;
		this.guildText.y = 6;
		addChild(this.guildText);

		this.addStatsView();
		this.lastFrameUpdate = System.getTimer();
		this.inited = true;
	}

	public function connect() {
		if (!this.isGameStarted) {
			this.isGameStarted = true;
			this.lastFrameUpdate = -1;
			this.frames = -1;
			this.lastUpdate = System.getTimer();
			stage.addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
			stage.addEventListener(Event.RESIZE, this.onResize);
		}
	}

	public function disconnect() {
		if (this.isGameStarted) {
			this.isGameStarted = false;
			this.uiInited = false;
			stage.removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
			stage.removeEventListener(Event.RESIZE, this.onResize);
			// this.map.dispose();
			// this.miniMap.dispose();
			Projectile.disposeBullId();
		}
	}

	private function onResize(_: Event) {
		if (this.inventory != null) {
			this.inventory.x = Main.stageWidth - 220;
			this.inventory.y = Main.stageHeight - 320;
		}

		if (this.miniMap != null)
			this.miniMap.x = Main.stageWidth - 120;

		if (this.textBox != null)
			this.textBox.y = Math.max(0, Main.stageHeight - this.textBox.height);
	}

	private function onEnterFrame(event: Event) {
		if (!this.isGameStarted)
			return;

		var time: Int32 = System.getTimer();
		if (time - this.lastFixedUpdate > 33) {
			if (this.map == null || this.map.player == null)
				return;

			var minDist = 1.0;
			var closestInteractive = -1;
			var playerX = this.map.player.mapX;
			var playerY = this.map.player.mapY;
			for (go in this.map.gameObjects)
				if (go?.props != null && (go.objClass == "Portal" || go.objClass == "Container") && (Math.abs(playerX - go.mapX) < 1 || Math.abs(playerY - go.mapY) < 1)) {
					var dist = PointUtil.distanceXY(go.mapX, go.mapY, playerX, playerY);
					if (dist < minDist) {
						minDist = dist;
						closestInteractive = go.objectId;
					}
				}

			Global.currentInteractiveTarget = closestInteractive;

			var player = this.map.player;
			if (player != null) {
				if (!this.uiInited) {
					this.inventory.init(player);
					this.characterDetails.init(player);
					#if !disable_rpc
					if (Main.rpcReady) {
						final className = player.props.displayId;
						var discordPresence = DiscordRichPresence.create();
						discordPresence.state = 'In ${this.map.mapName}';
						discordPresence.details = '';
						discordPresence.largeImageKey = 'logo';
						discordPresence.largeImageText = 'v${Settings.BUILD_VERSION}';
						discordPresence.smallImageKey = className.toLowerCase().replace(' ', '_');
						discordPresence.smallImageText = 'Tier ${StringUtils.toRoman(player.tier)} $className';
						discordPresence.startTimestamp = Main.startTime;
						Discord.UpdatePresence(cpp.RawConstPointer.addressOf(discordPresence));
					}
					#end

					this.uiInited = true;
				}

				this.miniMap.draw();
				this.inventory.draw(player);
				this.characterDetails.draw(player);
				this.currencyDisplay.draw(player.gems, player.gold, player.crowns);
				if (this.map.showDisplays)
					this.guildText.draw(player.guildName, player.guildRank);

				this.moveRecords.addRecord(time, player.mapX, player.mapY);
			}

			this.lastFixedUpdate = time;
		}

		if (this.statsView != null)
			this.updateStats(time);

		var dt: Int16 = time - this.lastUpdate;
		if (dt < 1)
			dt = 1;

		this.map.update(time, dt);
		Camera.update(dt);

		if (this.focus != null) {
			Camera.configureCamera(this.focus.mapX, this.focus.mapY);
			this.map.draw(time);
		}

		this.lastUpdate = time;
	}
}
