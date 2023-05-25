package ui;

import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.filters.DropShadowFilter;
import util.GuildUtil;

class GuildText extends Sprite {
	private var guildName = "";
	private var rank = 0;
	private var icon: Bitmap;
	private var guildText: SimpleText;

	public function new(name: String, rank: Int, w: Int = 0) {
		super();

		this.icon = new Bitmap(null);
		this.icon.y = -8;
		this.icon.x = -8;
		var stWidth: Int = w == 0 ? 0 : Std.int(w - (this.icon.width - 16));
		this.guildText = new SimpleText(16, 0xFFFFFF, false, stWidth, 0);
		this.guildText.filters = [new DropShadowFilter(0, 0, 0)];
		this.guildText.x = 24;
		this.draw(name, rank);
	}

	public inline function draw(name: String, rank: Int) {
		if (this.guildName == name && rank == rank)
			return;

		this.guildName = name;
		this.rank = rank;
		if (this.guildName == null || this.guildName == "") {
			if (this.icon != null && contains(this.icon))
				removeChild(this.icon);
			if (this.guildText != null && contains(this.guildText))
				removeChild(this.guildText);
		} else {
			this.icon.bitmapData = GuildUtil.rankToIcon(this.rank, 20);
			if (this.icon != null && !contains(this.icon))
				addChild(this.icon);
			this.guildText.text = this.guildName;
			this.guildText.useTextDimensions();
			if (this.guildText != null && !contains(this.guildText))
				addChild(this.guildText);
		}
	}
}
