package util;

import sound.Music;
import map.GroundLibrary;
import map.RegionLibrary;
import objects.ObjectLibrary;
import openfl.display.BitmapData;
import openfl.utils.Assets;

using util.Utils;

class AssetLoader {
	public static var MODELS = ["cube"];
	public static var GROUND_FILES = ["Ground"];
	public static var OBJECT_FILES = [
		"Projectiles", "Equip", "Players", "EnemiesLowRealm", "EnemiesMidRealm", "Containers", "Portals", "StaticObjects", "Test", "Objects", "Skins"
	];
	public static var REGION_FILES = ["Regions"];

	public static function load() {
		AssetLibrary.addImageSet("invisible", new BitmapData(8, 8, true, 0), 8, 8);

		// all ui currently. not part of the sprite batcher
		AssetLibrary.addImageSet("keyIndicators", Assets.getBitmapData("assets/sheets/KeyIndicators.png"), 100, 100, true);
		AssetLibrary.addImageSet("cursors", Assets.getBitmapData("assets/sheets/Cursors.png"), 32, 32, true);
		AssetLibrary.addImageSet("items", Assets.getBitmapData("assets/sheets/Items.png"), 8, 8, true);
		AssetLibrary.addImageSet("skinItems", Assets.getBitmapData("assets/sheets/Players.png"), 8, 8, true);
		AssetLibrary.addImageSet("tieredItems", Assets.getBitmapData("assets/sheets/TieredItems.png"), 8, 8, true);
		AssetLibrary.addImageSet("speechBalloons", Assets.getBitmapData("assets/sheets/SpeechBalloons.png"), 32, 24, true);
		
		AssetLibrary.addImageSet("errorTexture", Assets.getBitmapData("assets/sheets/ErrorTexture.png"), 8, 8, true);
		AssetLibrary.addImageSet("bars", Assets.getBitmapData("assets/sheets/Bars.png"), 24, 8);
		AssetLibrary.addImageSet("ground", Assets.getBitmapData("assets/sheets/Ground.png"), 8, 8);
		AssetLibrary.addImageSet("conditions", Assets.getBitmapData("assets/sheets/Conditions.png"), 16, 16);
		AssetLibrary.addImageSet("misc", Assets.getBitmapData("assets/sheets/Misc.png"), 8, 8);
		AssetLibrary.addImageSet("misc16", Assets.getBitmapData("assets/sheets/Misc16.png"), 16, 16);
		AssetLibrary.addImageSet("portals", Assets.getBitmapData("assets/sheets/Portals.png"), 8, 8);
		AssetLibrary.addImageSet("portals16", Assets.getBitmapData("assets/sheets/Portals16.png"), 16, 16);
		AssetLibrary.addImageSet("projectiles", Assets.getBitmapData("assets/sheets/Projectiles.png"), 8, 8);
		AssetLibrary.addImageSet("props", Assets.getBitmapData("assets/sheets/Props.png"), 8, 8);
		AssetLibrary.addImageSet("props16", Assets.getBitmapData("assets/sheets/Props16.png"), 16, 16);
		AssetLibrary.addImageSet("tieredProjectiles", Assets.getBitmapData("assets/sheets/TieredProjectiles.png"), 8, 8);

		AnimatedChars.add("miscChars", Assets.getBitmapData("assets/sheets/MiscChars.png"), null, 8, 8, 48, 8);
		AnimatedChars.add("lowrealm", Assets.getBitmapData("assets/sheets/LowRealm.png"), null, 8, 8, 48, 8);
		AnimatedChars.add("lowrealm16", Assets.getBitmapData("assets/sheets/LowRealm16.png"), null, 16, 16, 96, 16);
		AnimatedChars.add("midrealm", Assets.getBitmapData("assets/sheets/MidRealm.png"), null, 8, 8, 48, 8);
		AnimatedChars.add("midrealm16", Assets.getBitmapData("assets/sheets/MidRealm16.png"), null, 16, 16, 96, 16);
		AnimatedChars.add("players", Assets.getBitmapData("assets/sheets/Players.png"), Assets.getBitmapData("assets/sheets/PlayersMask.png"), 8, 8, 48, 24);
		AnimatedChars.add("playerskins", Assets.getBitmapData("assets/sheets/PlayerSkins.png"), Assets.getBitmapData("assets/sheets/PlayerSkinsMask.png"), 8,
			8, 48, 24);

		for (name in GROUND_FILES)
			GroundLibrary.parseFromXML(Assets.getText("assets/xmls/" + name + ".xml").asXml());

		for (name in OBJECT_FILES)
			ObjectLibrary.parseFromXML(Assets.getText("assets/xmls/" + name + ".xml").asXml());

		for (name in REGION_FILES)
			RegionLibrary.parseFromXML(Assets.getText("assets/xmls/" + name + ".xml").asXml());

		Music.load();
	}
}
