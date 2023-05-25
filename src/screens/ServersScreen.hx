package screens;

#if !disable_rpc
import hxdiscord_rpc.Types;
import hxdiscord_rpc.Discord;
#end
import util.Settings;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import servers.Server;
import ui.Scrollbar;
import ui.SimpleText;
import ui.view.ScreenBase;
import ui.view.TitleView;

class ServersScreen extends Sprite {
	private var doneButton: TitleMenuOption;
	private var selectServerText: SimpleText;
	private var lines: Shape;
	private var content: Sprite;
	private var serverBoxes: ServerBoxes;
	private var scrollBar: Scrollbar;

	public function new() {
		super();

		addChild(new ScreenBase());
		addChild(new AccountScreen());

		this.selectServerText = new SimpleText(18, 0xB3B3B3, false, 0, 0);
		this.selectServerText.setBold(true);
		this.selectServerText.text = "Select Server";
		this.selectServerText.updateMetrics();
		this.selectServerText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.selectServerText.x = (Main.stageWidth - this.selectServerText.width) / 2;
		this.selectServerText.y = 72;
		addChild(this.selectServerText);
		this.lines = new Shape();
		addChild(this.lines);
		this.content = new Sprite();
		this.content.x = (Main.stageWidth - 800) / 2 + 4;
		this.content.y = 100;
		var maskShape: Shape = new Shape();
		maskShape.graphics.beginFill(0xFFFFFF);
		maskShape.graphics.drawRect(0, 0, Main.stageWidth - 24, Main.stageHeight / 2 + 30);
		maskShape.graphics.endFill();
		this.content.addChild(maskShape);
		this.content.mask = maskShape;
		addChild(this.content);
		this.serverBoxes = new ServerBoxes(Global.serverModel.getServers());
		this.serverBoxes.y = 8;
		this.serverBoxes.addEventListener(Event.COMPLETE, onDone);
		this.content.addChild(this.serverBoxes);
		if (this.serverBoxes.height > 400) {
			this.scrollBar = new Scrollbar(16, Std.int(Main.stageHeight / 2));
			this.scrollBar.x = Main.stageWidth - this.scrollBar.width - 4;
			this.scrollBar.y = 104;
			this.scrollBar.setIndicatorSize(Main.stageHeight / 2, this.serverBoxes.height);
			this.scrollBar.addEventListener(Event.CHANGE, this.onScrollBarChange);
			addChild(this.scrollBar);
		}
		this.doneButton = new TitleMenuOption("done", 36, false);
		this.doneButton.addEventListener(MouseEvent.CLICK, onDone);
		addChild(this.doneButton);
		this.doneButton.x = Main.stageWidth / 2 - this.doneButton.width / 2;
		this.doneButton.y = Main.stageHeight - 76;

		#if !disable_rpc
		if (Main.rpcReady) {
			var discordPresence = DiscordRichPresence.create();
			discordPresence.state = 'Server Select';
			discordPresence.details = '';
			discordPresence.largeImageKey = 'logo';
			discordPresence.largeImageText = 'v${Settings.BUILD_VERSION}';
			discordPresence.startTimestamp = Main.startTime;
			Discord.UpdatePresence(cpp.RawConstPointer.addressOf(discordPresence));
		}
		#end
	}

	public function initialize(servers: Array<Server>) {}

	private function onScrollBarChange(event: Event) {
		this.serverBoxes.y = 8 - this.scrollBar.pos() * (this.serverBoxes.height - 400);
	}

	private static function onDone(event: Event) {
		Global.layers.screens.setScreen(new TitleView());
	}
}
