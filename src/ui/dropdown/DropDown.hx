package ui.dropdown;

import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.geom.Point;
import ui.SimpleText;

class DropDown extends Sprite {
	public var strings: Array<String>;
	public var w = 0;
	public var h = 0;
	public var labelText: SimpleText;
	public var xOffset = 0;
	public var selected: DropDownItem;
	public var all: Sprite;

	public function new(strings: Array<String>, w: Int, h: Int, label: String = null) {
		super();

		this.all = new Sprite();
		this.strings = strings;
		this.w = w;
		this.h = h;
		if (label != null) {
			this.labelText = new SimpleText(16, 0xFFFFFF, false, 0, 0);
			this.labelText.setBold(true);
			this.labelText.text = label + ":";
			this.labelText.updateMetrics();
			addChild(this.labelText);
			this.xOffset = Std.int(this.labelText.width + 5);
		}

		this.setIndex(0);
	}

	public function getValue() {
		return this.selected.getValue();
	}

	public function setIndex(index: Int) {
		this.setSelected(this.strings[index]);
	}

	private function setSelected(value: String) {
		var prevValue: String = this.selected != null ? this.selected.getValue() : null;
		this.selected = new DropDownItem(value, this.w, this.h);
		this.selected.x = this.xOffset;
		this.selected.y = 0;
		addChild(this.selected);
		this.selected.addEventListener(MouseEvent.CLICK, this.onClick);
		if (value != prevValue)
			dispatchEvent(new Event(Event.CHANGE));
	}

	private function showAll() {
		var global: Point;
		var item: DropDownItem = null;
		var yOffset = 0;
		global = parent.localToGlobal(new Point(x, y));
		this.all.x = global.x;
		this.all.y = global.y;
		for (i in 0...this.strings.length) {
			item = new DropDownItem(this.strings[i], this.w, this.h);
			item.addEventListener(MouseEvent.CLICK, this.onSelect);
			item.x = this.xOffset;
			item.y = yOffset;
			this.all.addChild(item);
			yOffset = yOffset + item.h;
		}

		this.all.addEventListener(MouseEvent.ROLL_OUT, this.onOut);
		stage.addChild(this.all);
	}

	private function hideAll() {
		this.all.removeEventListener(MouseEvent.ROLL_OUT, this.onOut);
		stage.removeChild(this.all);
	}

	private function onClick(event: MouseEvent) {
		event.stopImmediatePropagation();
		this.selected.removeEventListener(MouseEvent.CLICK, this.onClick);
		if (contains(this.selected))
			removeChild(this.selected);

		this.showAll();
	}

	private function onSelect(event: MouseEvent) {
		event.stopImmediatePropagation();
		this.hideAll();
		var dropDownItem: DropDownItem = cast(event.target, DropDownItem);
		this.setSelected(dropDownItem.getValue());
	}

	private function onOut(event: MouseEvent) {
		this.hideAll();
		this.setSelected(this.selected.getValue());
	}
}
