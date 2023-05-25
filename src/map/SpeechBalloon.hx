package map;

import openfl.text.TextFormatAlign;
import openfl.filters.GlowFilter;
import openfl.geom.Matrix;
import openfl.display.BitmapData;
import lime.system.System;
import objects.GameObject;
import openfl.geom.Point;
import ui.SimpleText;

class SpeechBalloon {
	public static inline var DEFAULT_BUBBLE = 0;
	public static inline var MESSAGE_BUBBLE = 1;
	public static inline var GUILD_BUBBLE = 2;
	public static inline var ENEMY_BUBBLE = 3;
	public static inline var PARTY_BUBBLE = 4;
	public static inline var ADMIN_BUBBLE = 5;

	public var go: GameObject;
	public var lifetime = 0;
	public var hideable = false;
	public var textTex: BitmapData;
	public var numLines = 0;
	public var disposed = false;
	public var startTime = 0;
	public var sbType: Int;

	public function new(go: GameObject, text: String, sbType: Int, lifetime: Int) {
		this.go = go;
		this.startTime = System.getTimer();
		this.lifetime = lifetime * 1000;
		this.disposed = false;
		this.sbType = sbType;
		var color = 0;
		switch (sbType) {
			case DEFAULT_BUBBLE:
				color = 0x151515;
			case MESSAGE_BUBBLE:
				color = 0x002A66;
			case GUILD_BUBBLE:
				color = 0x00660E;
			case ENEMY_BUBBLE:
				color = 0x661100;
			case PARTY_BUBBLE:
				color = 0x1B0066;
			case ADMIN_BUBBLE:
				color = 0x66350A;
		}
		var sText = new SimpleText(12, color, false, 110, 50);
		sText.setBold(true);
		sText.setItalic(true);
		sText.text = text;
		sText.wordWrap = true;
		sText.setAlignment(TextFormatAlign.CENTER);
		sText.updateMetrics();

		this.numLines = Std.int(Math.min(sText.numLines, 3));
		this.textTex = new BitmapData(Std.int(sText.width + 20), 64, true, 0);
		this.textTex.draw(sText, new Matrix(1, 0, 0, 1, 12, 0));

		this.startTime = System.getTimer();
	}
}
