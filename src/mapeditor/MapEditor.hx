package mapeditor;
import util.Settings;
#if !disable_rpc
import hxdiscord_rpc.Types;
import hxdiscord_rpc.Discord;
#end
import servers.Server;
import core.PlayerModel;
import openfl.display.Sprite;
import openfl.events.Event;

class MapEditor extends Sprite {
	private var model: PlayerModel;
	private var server: Server;
	private var editingScreen: EditingScreen;

	public function new() {
		super();

		this.editingScreen = new EditingScreen();
		addChild(this.editingScreen);

		#if !disable_rpc
		if (Main.rpcReady) {
			var discordPresence = DiscordRichPresence.create();
			discordPresence.state = 'Map Editor';
			discordPresence.details = '';
			discordPresence.largeImageKey = 'logo';
			discordPresence.largeImageText = 'v${Settings.BUILD_VERSION}';
			discordPresence.startTimestamp = Main.startTime;
			Discord.UpdatePresence(cpp.RawConstPointer.addressOf(discordPresence));
		}
		#end
	}

	public function initialize(model: PlayerModel, server: Server) {
		this.model = model;
		this.server = server;
	}

	private function onMapTestDone(event: Event) {
		addChild(this.editingScreen);
	}

	private function onClientUpdate(event: Event) {
		addChild(this.editingScreen);
	}
}