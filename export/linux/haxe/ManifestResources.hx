package;

import haxe.io.Bytes;
import lime.utils.AssetBundle;
import lime.utils.AssetLibrary;
import lime.utils.AssetManifest;
import lime.utils.Assets;

#if sys
import sys.FileSystem;
#end

#if disable_preloader_assets
@:dox(hide) class ManifestResources {
	public static var preloadLibraries:Array<Dynamic>;
	public static var preloadLibraryNames:Array<String>;
	public static var rootPath:String;

	public static function init (config:Dynamic):Void {
		preloadLibraries = new Array ();
		preloadLibraryNames = new Array ();
	}
}
#else
@:access(lime.utils.Assets)


@:keep @:dox(hide) class ManifestResources {


	public static var preloadLibraries:Array<AssetLibrary>;
	public static var preloadLibraryNames:Array<String>;
	public static var rootPath:String;


	public static function init (config:Dynamic):Void {

		preloadLibraries = new Array ();
		preloadLibraryNames = new Array ();

		rootPath = null;

		if (config != null && Reflect.hasField (config, "rootPath")) {

			rootPath = Reflect.field (config, "rootPath");

			if(!StringTools.endsWith (rootPath, "/")) {

				rootPath += "/";

			}

		}

		if (rootPath == null) {

			#if (ios || tvos || emscripten)
			rootPath = "assets/";
			#elseif android
			rootPath = "";
			#elseif console
			rootPath = lime.system.System.applicationDirectory;
			#else
			rootPath = "./";
			#end

		}

		#if (openfl && !flash && !display)
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_faerbold_ttf);
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_ubuntu_medium_ttf);
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_ubuntu_bold_ttf);
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_ubuntu_mediumitalic_ttf);
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_faer_ttf);
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_ubuntu_bolditalic_ttf);
		
		#end

		var data, manifest, library, bundle;

		#if kha

		null
		library = AssetLibrary.fromManifest (manifest);
		Assets.registerLibrary ("null", library);

		if (library != null) preloadLibraries.push (library);
		else preloadLibraryNames.push ("null");

		#else

		Assets.libraryPaths["default"] = rootPath + "manifest/default.json";
		

		library = Assets.getLibrary ("default");
		if (library != null) preloadLibraries.push (library);
		else preloadLibraryNames.push ("default");
		

		#end

	}


}


#if kha

null

#else

#if !display
#if flash

@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_misc_transbackground_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_misc_mapbackground_fm extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_transbg_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_keyindicators_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_props_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_misc_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_ground_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_playersmask_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_speechballoons_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_conditions_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_portals_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_lowrealm16_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_props16_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_bars_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_playerskins_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_midrealm_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_errortexture_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_items_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_playerskinsmask_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_midrealm16_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_tiereditems_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_players_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_portals16_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_misc16_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_tieredprojectiles_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_lowrealm_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_miscchars_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_cursors_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sheets_projectiles_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_meshes_cube_obj extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_meshes_cube_mtl extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_fonts_faerbold_ttf extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_medium_ttf extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_bold_ttf extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_mediumitalic_ttf extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_fonts_faer_ttf extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_fonts_ufl_txt extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_bolditalic_ttf extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_fire_dagger_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_wand_of_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_fire_sword_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_fire_wand_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_blunt_dagger_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_mithril_dagger_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_heavy_crossbow_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_wand_of_dark_magic_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_golden_sword_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_mithril_sword_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_firework_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_glass_sword_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_poison_fang_dagger_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_missile_wand_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_sprite_wand_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_double_bow_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_dirk_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_golden_dagger_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_poor_quality_bow_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_hells_fire_wand_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_crossbow_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_fire_bow_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_long_sword_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_golden_bow_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_obsidian_dagger_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_weapon_blunt_sword_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_error_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_loot_appears_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_death_screen_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_button_click_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_use_key_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_bladeswing_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_spell_major_heal_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_spell_light_heal_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_spell_fire_spray_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_spell_clock_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_spell_fire_nova_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_spell_magic_nova_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_enter_realm_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_thunder_god_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_flayers_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_undead_hobbits_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_sprite_god_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_sprites_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_demons_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_rocks_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_spider_queen_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_blobs_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_cubes_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_greater_pit_snakes_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_chicken_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_traps_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_elves_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pit_snakes_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pirate_king_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_bats_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_wooden_walls_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dragons_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_greater_demons_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_abyss_demons_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_flaming_skulls_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_stone_walls_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_mummies_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_golems_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_beholder_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_slimes_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_djinn_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dwarf_god_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_hobbits_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_chicken_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_abyss_brutes_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ogres_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_bats_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ents_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_lizard_god_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ghosts_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dragons_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pirates_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_blobs_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_snake_queen_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_minion_of_oryx_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_golems_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dwarf_god_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ghost_god_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ghosts_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_rocks_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_goblins_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_lizard_god_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_sprites_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_default_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_skull_shrine_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ogres_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_goblins_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_slimes_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_night_elves_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_night_elves_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_abyss_demons_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_oryx_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_traps_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_undead_dwarves_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_scorpions_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_eggs_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_trees_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_hobbits_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_flaming_skulls_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_undead_dwarves_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_beholder_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pythons_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_greater_pit_snakes_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_skull_shrine_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_spiders_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_snakes_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_demons_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_scorpions_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_cave_pirates_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_djinn_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_minion_of_oryx_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_elves_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_medusa_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pit_snakes_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_snake_queen_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_orcs_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_oryx_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_undead_hobbits_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pythons_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_spider_queen_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_thunder_god_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_default_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_spiders_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_orcs_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_sprite_god_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_mummies_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_cubes_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_flayers_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_medusa_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_trees_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_flying_brain_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_stone_walls_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ents_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_wooden_walls_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dark_elves_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_greater_demons_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_flying_brain_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dwarves_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_eggs_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_skeletons_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_abyss_brutes_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_skeletons_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_ghost_god_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dark_elves_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_cyclops_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_snakes_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_cave_pirates_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_cyclops_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pirates_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_dwarves_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_monster_pirate_king_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_no_mana_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_magicshoot_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_daggerswing_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_use_potion_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_arrowshoot_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_archer_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_rogue_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_warrior_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_archer_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_wizard_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_rogue_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_paladin_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_wizard_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_warrior_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_priest_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_paladin_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_knight_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_knight_death_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_player_priest_hit_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_inventory_move_item_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_sfx_level_up_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_playerinterfacedecor_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_minimap_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_inventoryslotmythic_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_partyinterfacehealthbar_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_chat_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_playerinterfacemanabar_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_inventoryinterface_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_partyinterfacemanabar_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_inventoryslotlegendary_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_inventoryslotepic_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_partyinterface_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_playerinterfacehealthbar_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_inventoryslotrare_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_playerinterfacexpbar_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_ui_containerinterface_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_music_sorc_ogg extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_basesingle_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_ocean_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_base_vert extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_basehighglow_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_ground_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_basesingle_vert extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_ground_vert extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_baselowglow_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_basemedglow_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_basevhighglow_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_base_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_containers_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_test_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_enemieslowrealm_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_equip_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_portals_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_staticobjects_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_projectiles_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_objects_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_enemiesmidrealm_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_skins_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_ground_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_players_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_xmls_regions_xml extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__manifest_default_json extends null { }


#elseif (desktop || cpp)


@:keep @:noCompletion #if display private #end class __ASSET__assets_fonts_faerbold_ttf extends lime.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/FaerBold.ttf"; name = "Faer Bold"; super (); }}
@:keep @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_medium_ttf extends lime.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-Medium.ttf"; name = "Ubuntu Medium"; super (); }}
@:keep @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_bold_ttf extends lime.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-Bold.ttf"; name = "Ubuntu Bold"; super (); }}
@:keep @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_mediumitalic_ttf extends lime.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-MediumItalic.ttf"; name = "Ubuntu Medium Italic"; super (); }}
@:keep @:noCompletion #if display private #end class __ASSET__assets_fonts_faer_ttf extends lime.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Faer.ttf"; name = "Faer"; super (); }}
@:keep @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_bolditalic_ttf extends lime.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-BoldItalic.ttf"; name = "Ubuntu Bold Italic"; super (); }}


#else

@:keep @:expose('__ASSET__assets_fonts_faerbold_ttf') @:noCompletion #if display private #end class __ASSET__assets_fonts_faerbold_ttf extends lime.text.Font { public function new () { #if !html5 __fontPath = "assets/fonts/FaerBold.ttf"; #else ascender = null; descender = null; height = null; numGlyphs = null; underlinePosition = null; underlineThickness = null; unitsPerEM = null; #end name = "Faer Bold"; super (); }}
@:keep @:expose('__ASSET__assets_fonts_ubuntu_medium_ttf') @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_medium_ttf extends lime.text.Font { public function new () { #if !html5 __fontPath = "assets/fonts/Ubuntu-Medium.ttf"; #else ascender = null; descender = null; height = null; numGlyphs = null; underlinePosition = null; underlineThickness = null; unitsPerEM = null; #end name = "Ubuntu Medium"; super (); }}
@:keep @:expose('__ASSET__assets_fonts_ubuntu_bold_ttf') @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_bold_ttf extends lime.text.Font { public function new () { #if !html5 __fontPath = "assets/fonts/Ubuntu-Bold.ttf"; #else ascender = null; descender = null; height = null; numGlyphs = null; underlinePosition = null; underlineThickness = null; unitsPerEM = null; #end name = "Ubuntu Bold"; super (); }}
@:keep @:expose('__ASSET__assets_fonts_ubuntu_mediumitalic_ttf') @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_mediumitalic_ttf extends lime.text.Font { public function new () { #if !html5 __fontPath = "assets/fonts/Ubuntu-MediumItalic.ttf"; #else ascender = null; descender = null; height = null; numGlyphs = null; underlinePosition = null; underlineThickness = null; unitsPerEM = null; #end name = "Ubuntu Medium Italic"; super (); }}
@:keep @:expose('__ASSET__assets_fonts_faer_ttf') @:noCompletion #if display private #end class __ASSET__assets_fonts_faer_ttf extends lime.text.Font { public function new () { #if !html5 __fontPath = "assets/fonts/Faer.ttf"; #else ascender = null; descender = null; height = null; numGlyphs = null; underlinePosition = null; underlineThickness = null; unitsPerEM = null; #end name = "Faer"; super (); }}
@:keep @:expose('__ASSET__assets_fonts_ubuntu_bolditalic_ttf') @:noCompletion #if display private #end class __ASSET__assets_fonts_ubuntu_bolditalic_ttf extends lime.text.Font { public function new () { #if !html5 __fontPath = "assets/fonts/Ubuntu-BoldItalic.ttf"; #else ascender = null; descender = null; height = null; numGlyphs = null; underlinePosition = null; underlineThickness = null; unitsPerEM = null; #end name = "Ubuntu Bold Italic"; super (); }}


#end

#if (openfl && !flash)

#if html5
@:keep @:expose('__ASSET__OPENFL__assets_fonts_faerbold_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_faerbold_ttf extends openfl.text.Font { public function new () { name = "Faer Bold"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_medium_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_medium_ttf extends openfl.text.Font { public function new () { name = "Ubuntu Medium"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_bold_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_bold_ttf extends openfl.text.Font { public function new () { name = "Ubuntu Bold"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_mediumitalic_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_mediumitalic_ttf extends openfl.text.Font { public function new () { name = "Ubuntu Medium Italic"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_faer_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_faer_ttf extends openfl.text.Font { public function new () { name = "Faer"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_bolditalic_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_bolditalic_ttf extends openfl.text.Font { public function new () { name = "Ubuntu Bold Italic"; super (); }}

#else
@:keep @:expose('__ASSET__OPENFL__assets_fonts_faerbold_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_faerbold_ttf extends openfl.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/FaerBold.ttf"; name = "Faer Bold"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_medium_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_medium_ttf extends openfl.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-Medium.ttf"; name = "Ubuntu Medium"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_bold_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_bold_ttf extends openfl.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-Bold.ttf"; name = "Ubuntu Bold"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_mediumitalic_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_mediumitalic_ttf extends openfl.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-MediumItalic.ttf"; name = "Ubuntu Medium Italic"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_faer_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_faer_ttf extends openfl.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Faer.ttf"; name = "Faer"; super (); }}
@:keep @:expose('__ASSET__OPENFL__assets_fonts_ubuntu_bolditalic_ttf') @:noCompletion #if display private #end class __ASSET__OPENFL__assets_fonts_ubuntu_bolditalic_ttf extends openfl.text.Font { public function new () { __fontPath = ManifestResources.rootPath + "assets/fonts/Ubuntu-BoldItalic.ttf"; name = "Ubuntu Bold Italic"; super (); }}

#end

#end
#end

#end

#end