package core;
import openfl.display.Sprite;
import ui.dialogs.DialogsView;
import ui.tooltip.TooltipsView;

class Layers extends Sprite {
	public var overlay: Sprite;
	public var screens: ScreensView;
	public var tooltips: TooltipsView;
	public var dialogs: DialogsView;

	public function new() {
		super();

		addChild(this.screens = new ScreensView());
		addChild(this.overlay = new Sprite());
		addChild(this.tooltips = new TooltipsView());
		addChild(this.dialogs = new DialogsView());
	}
}