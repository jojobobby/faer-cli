package ui.guild;

import openfl.display.Bitmap;
import openfl.display.Graphics;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.DropShadowFilter;
import openfl.geom.ColorTransform;
import ui.DeleteXGraphic;
import ui.dialogs.Dialog;
import ui.SimpleText;
import util.GuildUtil;
import util.Utils;

class MemberListLine extends Sprite {
	public static inline var WIDTH: Int = 756;
	public static inline var HEIGHT: Int = 32;

	public static var mouseOverCT: ColorTransform = new ColorTransform(1, 220 / 255, 133 / 255);

	private var memberName = "";
	private var rank = 0;
	private var placeText: SimpleText;
	private var nameText: SimpleText;
	private var guildFameText: SimpleText;
	private var guildFameIcon: Bitmap;
	private var rankIcon: Bitmap;
	private var rankText: SimpleText;
	private var promoteButton: Sprite;
	private var demoteButton: Sprite;
	private var removeButton: Sprite;

	private static function createArrow(up: Bool) {
		var sprite: Sprite = new Sprite();
		var g: Graphics = sprite.graphics;
		g.beginFill(0xFFFFFF);
		g.moveTo(-8, -6);
		g.lineTo(8, -6);
		g.lineTo(0, 6);
		g.lineTo(-8, -6);
		if (up)
			sprite.rotation = 180;

		return sprite;
	}

	private static function addHighlighting(sprite: Sprite) {
		sprite.addEventListener(MouseEvent.MOUSE_OVER, onHighlightOver);
		sprite.addEventListener(MouseEvent.ROLL_OUT, onHighlightOut);
	}

	public function new(place: Int, name: String, rank: Int, fame: Int, isMe: Bool, myRank: Int) {
		super();

		this.memberName = name;
		this.rank = rank;
		var textColor = 0xB3B3B3;
		if (isMe)
			textColor = 0xFCC219;

		this.placeText = new SimpleText(22, textColor, false, 0, 0);
		this.placeText.setBold(true);
		this.placeText.text = Std.string(place) + ".";
		this.placeText.useTextDimensions();
		this.placeText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.placeText.x = 60 - this.placeText.width;
		this.placeText.y = HEIGHT / 2 - this.placeText.height / 2;
		addChild(this.placeText);
		this.nameText = new SimpleText(22, textColor, false, 0, 0);
		this.nameText.setBold(true);
		this.nameText.text = name;
		this.nameText.useTextDimensions();
		this.nameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.nameText.x = 100;
		this.nameText.y = HEIGHT / 2 - this.nameText.height / 2;
		addChild(this.nameText);
		this.guildFameText = new SimpleText(22, textColor, false, 0, 0);
		this.guildFameText.text = Std.string(fame);
		this.guildFameText.useTextDimensions();
		this.guildFameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.guildFameText.x = 408 - this.guildFameText.width;
		this.guildFameText.y = HEIGHT / 2 - this.guildFameText.height / 2;
		addChild(this.guildFameText);
		this.rankIcon = new Bitmap(GuildUtil.rankToIcon(rank, 20));
		this.rankIcon.x = 548;
		this.rankIcon.y = HEIGHT / 2 - this.rankIcon.height / 2;
		addChild(this.rankIcon);
		this.rankText = new SimpleText(22, textColor, false, 0, 0);
		this.rankText.text = GuildUtil.rankToString(rank);
		this.rankText.useTextDimensions();
		this.rankText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		this.rankText.x = 580;
		this.rankText.y = HEIGHT / 2 - this.rankText.height / 2;
		addChild(this.rankText);
		if (GuildUtil.canPromote(myRank, rank)) {
			this.promoteButton = createArrow(true);
			addHighlighting(this.promoteButton);
			this.promoteButton.addEventListener(MouseEvent.CLICK, this.onPromote);
			this.promoteButton.x = 670 + 6;
			this.promoteButton.y = HEIGHT / 2;
			addChild(this.promoteButton);
		}
		if (GuildUtil.canDemote(myRank, rank)) {
			this.demoteButton = createArrow(false);
			addHighlighting(this.demoteButton);
			this.demoteButton.addEventListener(MouseEvent.CLICK, this.onDemote);
			this.demoteButton.x = 700 + 6;
			this.demoteButton.y = HEIGHT / 2;
			addChild(this.demoteButton);
		}
		if (GuildUtil.canRemove(myRank, rank)) {
			this.removeButton = new DeleteXGraphic();
			addHighlighting(this.removeButton);
			this.removeButton.addEventListener(MouseEvent.CLICK, this.onRemove);
			this.removeButton.x = 730;
			this.removeButton.y = HEIGHT / 2 - this.removeButton.height / 2;
			addChild(this.removeButton);
		}
	}

	private static function onHighlightOver(event: MouseEvent) {
		var target: Sprite = cast(event.currentTarget, Sprite);
		target.transform.colorTransform = mouseOverCT;
	}

	private static function onHighlightOut(event: MouseEvent) {
		var target: Sprite = cast(event.currentTarget, Sprite);
		target.transform.colorTransform = ColorUtils.identity;
	}

	private function onPromote(event: MouseEvent) {
		var dialog: Dialog = new Dialog("Are you sure you want to promote "
			+ this.memberName
			+ " to "
			+ GuildUtil.rankToString(GuildUtil.promotedRank(this.rank))
			+ "?",
			"Promote "
			+ this.memberName, "Cancel", "Promote");
		dialog.addEventListener(Dialog.BUTTON1_EVENT, this.onCancelDialog);
		dialog.addEventListener(Dialog.BUTTON2_EVENT, this.onVerifiedPromote);
		stage.addChild(dialog);
	}

	private function onVerifiedPromote(event: Event) {
		var dialog: Dialog = cast(event.currentTarget, Dialog);
		stage.removeChild(dialog);
		dispatchEvent(new GuildPlayerListEvent(GuildPlayerListEvent.SET_RANK, this.memberName, GuildUtil.promotedRank(this.rank)));
	}

	private function onDemote(event: MouseEvent) {
		var dialog: Dialog = new Dialog("Are you sure you want to demote " + this.memberName + " to "
			+ GuildUtil.rankToString(GuildUtil.demotedRank(this.rank)) + "?",
			"Demote " + this.memberName, "Cancel", "Demote");
		dialog.addEventListener(Dialog.BUTTON1_EVENT, this.onCancelDialog);
		dialog.addEventListener(Dialog.BUTTON2_EVENT, this.onVerifiedDemote);
		stage.addChild(dialog);
	}

	private function onVerifiedDemote(event: Event) {
		var dialog: Dialog = cast(event.currentTarget, Dialog);
		stage.removeChild(dialog);
		dispatchEvent(new GuildPlayerListEvent(GuildPlayerListEvent.SET_RANK, this.memberName, GuildUtil.demotedRank(this.rank)));
	}

	private function onRemove(event: MouseEvent) {
		var dialog: Dialog = new Dialog("Are you sure you want to remove " + this.memberName + " from the guild?", "Remove " + this.memberName, "Cancel",
			"Remove");
		dialog.addEventListener(Dialog.BUTTON1_EVENT, this.onCancelDialog);
		dialog.addEventListener(Dialog.BUTTON2_EVENT, this.onVerifiedRemove);
		stage.addChild(dialog);
	}

	private function onVerifiedRemove(event: Event) {
		var dialog: Dialog = cast(event.currentTarget, Dialog);
		stage.removeChild(dialog);
		dispatchEvent(new GuildPlayerListEvent(GuildPlayerListEvent.REMOVE_MEMBER, this.memberName));
	}

	private function onCancelDialog(event: Event) {
		var dialog: Dialog = cast(event.currentTarget, Dialog);
		stage.removeChild(dialog);
	}
}
