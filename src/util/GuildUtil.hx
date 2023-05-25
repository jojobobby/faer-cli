package util;

import openfl.display.BitmapData;

class GuildUtil {
	public static inline var INITIATE = 0;
	public static inline var MEMBER: Int = 10;
	public static inline var OFFICER: Int = 20;
	public static inline var LEADER: Int = 30;
	public static inline var FOUNDER: Int = 40;
	public static inline var MAX_MEMBERS: Int = 50;

	public static function rankToString(rank: Int) {
		switch (rank) {
			case INITIATE:
				return "Initiate";
			case MEMBER:
				return "Member";
			case OFFICER:
				return "Officer";
			case LEADER:
				return "Leader";
			case FOUNDER:
				return "Founder";
			default:
				return "Unknown";
		}
	}

	public static function rankToIcon(rank: Int, size: Int) {
		var icon: BitmapData = null;
		switch (rank) {
			case INITIATE:
				icon = AssetLibrary.getImageFromSet("misc16", 26);
			case MEMBER:
				icon = AssetLibrary.getImageFromSet("misc16", 25);
			case OFFICER:
				icon = AssetLibrary.getImageFromSet("misc16", 24);
			case LEADER:
				icon = AssetLibrary.getImageFromSet("misc16", 23);
			case FOUNDER:
				icon = AssetLibrary.getImageFromSet("misc16", 22);
		}

		return TextureRedrawer.redraw(icon, size, true, 0, true);
	}

	public static function allowedChange(authRank: Int, oldRank: Int, newRank: Int) {
		if (oldRank == newRank)
			return false;

		if (authRank == FOUNDER && oldRank < FOUNDER && newRank < FOUNDER)
			return true;

		if (authRank == LEADER && oldRank < LEADER && newRank <= LEADER)
			return true;

		return authRank == OFFICER && oldRank < OFFICER && newRank < OFFICER;
	}

	public static function promotedRank(rank: Int) {
		switch (rank) {
			case INITIATE:
				return MEMBER;
			case MEMBER:
				return OFFICER;
			case OFFICER:
				return LEADER;
			default:
				return FOUNDER;
		}
	}

	public static function canPromote(myRank: Int, rank: Int) {
		var newRank: Int = promotedRank(rank);
		return allowedChange(myRank, rank, newRank);
	}

	public static function demotedRank(rank: Int) {
		switch (rank) {
			case OFFICER:
				return MEMBER;
			case LEADER:
				return OFFICER;
			case FOUNDER:
				return LEADER;
			default:
				return INITIATE;
		}
	}

	public static function canDemote(myRank: Int, rank: Int) {
		var newRank: Int = demotedRank(rank);
		return allowedChange(myRank, rank, newRank);
	}

	public static function canRemove(myRank: Int, rank: Int) {
		return myRank >= OFFICER && rank < myRank;
	}
}
