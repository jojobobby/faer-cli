package ui.view ;
import openfl.display.Sprite;
import ui.view.VialSlotView;

class VialInventoryView extends Sprite {
	private static var LEFT_BUTTON_CUTS: Array<Int> = [1, 0, 0, 1];
	private static var RIGHT_BUTTON_CUTS: Array<Int> = [0, 1, 1, 0];
	private static var SINGLE_BUTTON_CUTS: Array<Int> = [1, 1, 1, 1];
	private static inline var BUTTON_SPACE: Int = 4;
	private static var cuts: Array<Array<Int>> = [LEFT_BUTTON_CUTS, RIGHT_BUTTON_CUTS];

	public var leftSlot: VialSlotView;
	public var rightSlot: VialSlotView;

	public function new(noMP: Bool) {
		super();

		this.leftSlot = new VialSlotView(noMP ? SINGLE_BUTTON_CUTS : LEFT_BUTTON_CUTS, 0, noMP);
		this.leftSlot.cacheAsBitmap = true;
		addChild(this.leftSlot);

		if (noMP)
			return;

		this.rightSlot = new VialSlotView(RIGHT_BUTTON_CUTS, 1, false);
		this.rightSlot.cacheAsBitmap = true;
		this.rightSlot.x = 42;
		addChild(this.rightSlot);
	}
}