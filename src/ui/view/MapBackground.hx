package ui.view;

import haxe.ValueException;
import openfl.utils.ByteArray;
import objects.ObjectLibrary;
import util.Utils;
import map.Camera;
import util.NativeTypes;
import lime.system.System;
import map.Map;
import openfl.Assets;
import openfl.display.Sprite;
import openfl.events.Event;
import util.Settings;

class MapBackground extends Sprite {
	private static inline var ANGLE: Float32 = 7 * MathUtil.PI / 4;
	private static inline var TO_SEC_HALF: Float32 = 0.5 / 1000;
	private static var backgroundMap: Map;
	private static var nextFakeObjectId = 0;

	private static function makeMap() {
		var data: ByteArray = Assets.getBytes("assets/misc/MapBackground.fm");
		data.uncompress();
		var version: Int8 = data.readUnsignedByte();
		if (version != 1)
			throw new ValueException("Version not supported");

		var map = new Map();
		var xStart: UInt16 = data.readUnsignedShort();
		var yStart: UInt16 = data.readUnsignedShort();
		var w: UInt16 = data.readUnsignedShort();
		var h: UInt16 = data.readUnsignedShort();
		map.setProps(w, h, "Background Map", 0, false, false);
		map.initialize();

		for (y in 0...h)
			for (x in 0...w) {
				var ground: UInt16 = data.readUnsignedShort();
				if (ground != 65535)
					map.setGroundTile(x, y, ground);

				var object: UInt16 = data.readUnsignedShort();
				if (object != 65535) {
					var go = ObjectLibrary.getObjectFromType(object);
					go.size = go.props.getSize() / 100;
					go.objectId = 0x7F000000 | nextFakeObjectId++;
					map.addGameObject(go, x + 0.5, y + 0.5);
				}	
				
				var region = data.readUnsignedByte();
			}

		return map;
	}

	public function new() {
		super();

		if (Settings.DISABLE_MAP_BG)
			return;

		addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	private function onAddedToStage(_: Event) {
		backgroundMap = makeMap();
		addEventListener(Event.ENTER_FRAME, onEnterFrame);
	}

	private function onRemovedFromStage(_: Event) {
		removeEventListener(Event.ENTER_FRAME, onEnterFrame);
	}

	private static function onEnterFrame(_: Event) {
		var time: Int32 = System.getTimer();
		var xVal: Float32 = 60 + 5 * MathUtil.sin(time * TO_SEC_HALF);
		var yVal: Float32 = 70 + 5 * MathUtil.sin(time * TO_SEC_HALF);
		Camera.configureCamera(xVal, yVal);
		backgroundMap.draw(time);
	}
}
