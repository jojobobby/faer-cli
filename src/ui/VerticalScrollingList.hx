package ui;

import lib.ui.api.Size;
import lib.ui.impl.LayoutList;
import lib.ui.impl.VerticalLayout;
import openfl.display.DisplayObject;
import openfl.display.Sprite;
import util.Signal;

class VerticalScrollingList extends Sprite {
	public static inline var SCROLLBAR_PADDING: Int = 2;
	public static inline var SCROLLBAR_GUTTER: Int = VerticalScrollbar.WIDTH + SCROLLBAR_PADDING;

	public var scrollStateChanged = new Signal<Bool>();

	private var layout: VerticalLayout;
	private var list: LayoutList;
	private var scrollbar: VerticalScrollbar;
	private var isEnabled = true;
	private var size: Size;

	public function new() {
		super();

		this.makeLayout();
		this.makeVerticalList();
		this.makeScrollbar();
	}

	public function getIsEnabled() {
		return this.isEnabled;
	}

	public function setIsEnabled(value: Bool) {
		this.isEnabled = value;
		this.scrollbar.setIsEnabled(value);
	}

	public function setSize(size: Size) {
		this.size = size;
		if (this.isScrollbarVisible())
			size = new Size(size.width - SCROLLBAR_GUTTER, size.height);

		this.list.setSize(size);
		this.refreshScrollbar();
	}

	public function setPadding(padding: Int) {
		this.layout.setPadding(padding);
		this.list.updateLayout();
		this.refreshScrollbar();
	}

	public function addItem(item: DisplayObject) {
		this.list.addItem(item);
	}

	public function setItems(items: Array<DisplayObject>) {
		this.list.setItems(items);
	}

	public function getItemAt(index: Int): DisplayObject {
		return this.list.getItemAt(index);
	}

	public function getItemCount() {
		return this.list.getItemCount();
	}

	public function getListHeight() {
		return this.list.getSizeOfItems().height;
	}

	public function isScrollbarVisible() {
		return this.scrollbar.visible;
	}

	private function makeLayout() {
		this.layout = new VerticalLayout();
	}

	private function makeVerticalList() {
		this.list = new LayoutList();
		this.list.itemsChanged.on(this.refreshScrollbar);
		this.list.setLayout(this.layout);
		addChild(this.list);
	}

	private function refreshScrollbar() {
		var isVisible = false;
		var listSize: Size = this.list.getSize();
		var visibleSize: Int = listSize.height;
		var itemsSize: Int = this.list.getSizeOfItems().height;
		isVisible = itemsSize > visibleSize;
		var isChanged: Bool = this.scrollbar.visible != isVisible;
		this.scrollbar.visible = isVisible;
		if (isVisible)
			this.updateScrollbarSize(visibleSize, itemsSize);
		if (isChanged)
			this.updateUiAndDispatchStateChange(isVisible);
	}

	private function updateUiAndDispatchStateChange(isVisible: Bool) {
		this.setSize(this.size);
		this.scrollStateChanged.emit(isVisible);
	}

	private function updateScrollbarSize(visibleSize: Int, itemsSize: Int) {
		var barSize: Int = Std.int(visibleSize * (visibleSize / itemsSize));
		this.scrollbar.setSize(barSize, visibleSize);
		this.scrollbar.x = this.list.getSize().width + SCROLLBAR_PADDING;
	}

	private function makeScrollbar() {
		this.scrollbar = new VerticalScrollbar();
		this.scrollbar.positionChanged.on(this.onPositionChanged);
		this.scrollbar.visible = false;
		addChild(this.scrollbar);
	}

	private function onPositionChanged(value: Float) {
		var maxOffset: Int = this.list.getSizeOfItems().height - this.list.getSize().height;
		this.list.setOffset(Std.int(maxOffset * value));
	}
}
