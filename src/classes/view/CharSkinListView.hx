package classes.view;

import classes.model.CharacterClass;
import lib.ui.api.Size;
import openfl.display.DisplayObject;
import openfl.display.Sprite;
import openfl.events.Event;
import ui.VerticalScrollingList;

class CharSkinListView extends Sprite {
	public static inline var PADDING: Int = 5;
	public static inline var WIDTH: Int = 442;
	public static inline var HEIGHT: Int = 400;

	private var list: VerticalScrollingList;
	private var items: Array<CharSkinListItem>;

	public function new() {
		super();

		list = makeList();
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		Global.classModel.selected.on(this.setSkins);
		this.setSkins(Global.classModel.getSelected());
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		Global.classModel.selected.off(this.setSkins);
	}

	private function setSkins(charClass: CharacterClass) {
		this.setItems(CharSkinListItemFactory.make(charClass.skins));
	}

	public function setItems(items: Array<CharSkinListItem>) {
		this.items = items;
		var doItems = new Array<DisplayObject>();
		for (item in items)
			doItems.push(cast item);
		this.list.setItems(doItems);
		this.onScrollStateChanged(this.list.isScrollbarVisible());
	}

	public function getListHeight() {
		return this.list.getListHeight();
	}

	private function makeList(): VerticalScrollingList {
		var list: VerticalScrollingList = new VerticalScrollingList();
		list.setSize(new Size(WIDTH, HEIGHT));
		list.scrollStateChanged.on(this.onScrollStateChanged);
		list.setPadding(PADDING);
		addChild(list);
		return list;
	}

	private function onScrollStateChanged(isVisible: Bool) {
		var item: CharSkinListItem = null;
		var width: Int = CharSkinListItem.WIDTH;
		if (!isVisible)
			width += VerticalScrollingList.SCROLLBAR_GUTTER;

		for (item in this.items)
			item.width = width;
	}
}
