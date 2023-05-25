package mapeditor;

import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;

class EditTileProperties extends Sprite {
	public var tiles: Array<IntPoint>;

	private var darkBox: Shape;
	private var frame: EditTilePropertiesFrame;

	public function new(tiles: Array<IntPoint>, oldName: String) {
		super();
		this.tiles = tiles;
		this.darkBox = new Shape();
		var g: Graphics = this.darkBox.graphics;
		g.clear();
		g.beginFill(0, 0.8);
		g.drawRect(0, 0, 800, 600);
		g.endFill();
		addChild(this.darkBox);
		this.frame = new EditTilePropertiesFrame(oldName);
		this.frame.addEventListener(Event.COMPLETE, this.onComplete);
		this.frame.addEventListener(Event.CANCEL, this.onCancel);
		addChild(this.frame);
	}

	public function getObjectName() {
		if (this.frame.objectName.text() == "")
			return null;
		
		return this.frame.objectName.text();
	}

	public function onComplete(event: Event) {
		dispatchEvent(new Event(Event.COMPLETE));
		parent.removeChild(this);
	}

	public function onCancel(event: Event) {
		parent.removeChild(this);
	}
}
