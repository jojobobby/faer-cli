package ui.guild;

import cpp.Stdlib;
import cpp.Pointer;
import account.Account;
import appengine.RequestHandler;
import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.filters.DropShadowFilter;
import ui.Scrollbar;
import ui.SimpleText;
import util.GuildUtil;

class GuildPlayerList extends Sprite {
	private var num = 0;
	private var offset = 0;
	private var myName = "";
	private var myRank = 0;
	private var loadingText: SimpleText;
	private var titleText: SimpleText;
	private var guildFameText: SimpleText;
	private var lines: Shape;
	private var mainSprite: Sprite;
	private var listSprite: Sprite;
	private var openSlotsText: SimpleText;
	private var scrollBar: Scrollbar;

	private static function onTextError(error: String) {
		trace("error event: " + error);
	}

	public function new(num: Int, offset: Int, myName: String = "", myRank: Int = 0) {
		super();

		this.num = num;
		this.offset = offset;
		this.myName = myName;
		this.myRank = myRank;
		this.loadingText = new SimpleText(22, 0xB3B3B3, false, 0, 0);
		this.loadingText.setBold(true);
		this.loadingText.text = "Loading...";
		this.loadingText.useTextDimensions();
		this.loadingText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.loadingText.x = stage.stageWidth / 2 - this.loadingText.width / 2;
		this.loadingText.y = stage.stageHeight / 2 - this.loadingText.height / 2;
		addChild(this.loadingText);

		RequestHandler.setParameter("email", Account.email);
		RequestHandler.setParameter("password", Account.password);
		RequestHandler.setParameter("num", Std.string(num));
		RequestHandler.setParameter("offset", Std.string(offset));
		RequestHandler.maxRetries = 2;
		RequestHandler.complete.once(this.onComplete);
		RequestHandler.sendRequest("/guild/listMembers");
	}

	private function onComplete(compData: CompletionData) {
		if (compData.success)
			this.onGenericData(compData.result);
		else
			onTextError(compData.result);
	}

	private function onGenericData(data: String) {
		this.build(Xml.parse(data));
	}

	private function build(guildXML: Xml) {
		var g: Graphics;
		var id = 0;
		var openSlots = 0;
		var isMe = false;
		var rank = 0;
		var listLine: MemberListLine = null;
		removeChild(this.loadingText);
		this.titleText = new SimpleText(32, 0xB3B3B3, false, 0, 0);
		this.titleText.setBold(true);
		this.titleText.text = guildXML.get("name");
		this.titleText.useTextDimensions();
		this.titleText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.titleText.y = 24;
		this.titleText.x = stage.stageWidth / 2 - this.titleText.width / 2;
		addChild(this.titleText);
		this.guildFameText = new SimpleText(22, 0xFFFFFF, false, 0, 0);
		this.guildFameText.text = guildXML.elementsNamed("CurrentFame").next().firstChild().nodeValue;
		this.guildFameText.useTextDimensions();
		this.guildFameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.guildFameText.x = 768 - this.guildFameText.width;
		this.guildFameText.y = 32 / 2 - this.guildFameText.height / 2;
		addChild(this.guildFameText);
		this.lines = new Shape();
		g = this.lines.graphics;
		g.clear();
		g.lineStyle(2, 0x545454);
		g.moveTo(0, 100);
		g.lineTo(stage.stageWidth, 100);
		g.lineStyle();
		addChild(this.lines);
		this.mainSprite = new Sprite();
		this.mainSprite.x = 10;
		this.mainSprite.y = 110;
		var shape: Shape = new Shape();
		g = shape.graphics;
		g.beginFill(0);
		g.drawRect(0, 0, MemberListLine.WIDTH, 430);
		g.endFill();
		this.mainSprite.addChild(shape);
		this.mainSprite.mask = shape;
		addChild(this.mainSprite);
		this.listSprite = new Sprite();
		id = 0;
		for (memberXML in guildXML.elementsNamed("Member")) {
			isMe = this.myName == memberXML.elementsNamed("Name").next().firstChild().nodeValue;
			rank = Std.parseInt(memberXML.elementsNamed("Rank").next().firstChild().nodeValue);
			listLine = new MemberListLine(this.offset + id + 1, memberXML.elementsNamed("Name").next().firstChild().nodeValue,
				Std.parseInt(memberXML.elementsNamed("Rank").next().firstChild().nodeValue),
				Std.parseInt(memberXML.elementsNamed("Fame").next().firstChild().nodeValue), isMe, this.myRank);
			listLine.y = id * MemberListLine.HEIGHT;
			this.listSprite.addChild(listLine);
			id++;
		}

		openSlots = GuildUtil.MAX_MEMBERS - (this.offset + id);
		this.openSlotsText = new SimpleText(22, 0xB3B3B3, false, 0, 0);
		this.openSlotsText.text = openSlots + " open slots";
		this.openSlotsText.useTextDimensions();
		this.openSlotsText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.openSlotsText.x = MemberListLine.WIDTH / 2 - this.openSlotsText.width / 2;
		this.openSlotsText.y = id * MemberListLine.HEIGHT;
		this.listSprite.addChild(this.openSlotsText);
		this.mainSprite.addChild(this.listSprite);
		if (this.listSprite.height > 400) {
			this.scrollBar = new Scrollbar(16, 400);
			this.scrollBar.x = 800 - this.scrollBar.width - 4;
			this.scrollBar.y = 104;
			this.scrollBar.setIndicatorSize(400, this.listSprite.height);
			this.scrollBar.addEventListener(Event.CHANGE, this.onScrollBarChange);
			addChild(this.scrollBar);
		}
	}

	private function onScrollBarChange(event: Event) {
		this.listSprite.y = -this.scrollBar.pos() * (this.listSprite.height - 400);
	}
}
