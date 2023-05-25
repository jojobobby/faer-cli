package lib.ui.impl;

import lib.ui.api.Layout;
import lib.ui.api.Size;
import openfl.display.DisplayObject;
import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.geom.Rectangle;
import util.Signal;

class LayoutList extends Sprite {
	private static var NULL_LAYOUT: NullLayout = new NullLayout();
	private static var ZERO_SIZE: Size = new Size(0, 0);

	public var itemsChanged = new EmptySignal();

	private var list: Array<DisplayObject> = new Array<DisplayObject>();
	private var container: Sprite = new Sprite();
	private var containerMask: Shape = new Shape();

	private var layout: Layout;
	private var size: Size;
	private var offset = 0;

	public function new() {
		super();

		this.layout = NULL_LAYOUT;
		this.size = ZERO_SIZE;
		addChild(this.container);
		addChild(this.containerMask);
	}

	public function getLayout(): Layout {
		return this.layout;
	}

	public function setLayout(layout: Layout) {
		this.layout = layout != null ? layout : NULL_LAYOUT;
		layout.layout(this.list, -this.offset);
	}

	public function getSize(): Size {
		return this.size;
	}

	public function setSize(size: Size) {
		this.size = size != null ? size : ZERO_SIZE;
		this.applySizeToMask();
	}

	public function getSizeOfItems(): Size {
		var rect: Rectangle = this.container.getRect(this.container);
		return new Size(Std.int(rect.width), Std.int(rect.height));
	}

	public function addItem(item: DisplayObject) {
		this.addToListAndContainer(item);
		this.updateLayout();
		this.itemsChanged.emit();
	}

	public function getItemAt(index: Int): DisplayObject {
		return this.list[index];
	}

	public function setItems(items: Array<DisplayObject>) {
		this.clearList();
		this.addItemsToListAndContainer(items);
		this.offset = 0;
		this.updateLayout();
		this.itemsChanged.emit();
	}

	public function getItemCount() {
		return this.list.length;
	}

	public function setOffset(value: Int) {
		this.offset = value;
		this.updateLayout();
	}

	public function getOffset() {
		return this.offset;
	}

	public function updateLayout() {
		this.layout.layout(this.list, -this.offset);
	}

	private function applySizeToMask() {
		var g: Graphics = this.containerMask.graphics;
		g.clear();
		g.beginFill(10027263);
		g.drawRect(0, 0, this.size.width, this.size.height);
		g.endFill();
		this.container.mask = this.containerMask;
	}

	private function clearList() {
		var i: Int = this.list.length;
		while (i-- > 0)
			this.container.removeChild(this.list[i]);

		this.list.splice(0, this.list.length);
	}

	private function addItemsToListAndContainer(items: Array<DisplayObject>) {
		var item: DisplayObject = null;
		for (item in items)
			this.addToListAndContainer(item);
	}

	private function addToListAndContainer(item: DisplayObject) {
		this.list.push(item);
		this.container.addChild(item);
	}
}
