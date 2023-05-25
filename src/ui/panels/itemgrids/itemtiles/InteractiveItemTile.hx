package ui.panels.itemgrids.itemtiles;

import openfl.display.DisplayObject;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.events.TimerEvent;
import openfl.geom.Point;
import openfl.utils.Timer;
import ui.panels.itemgrids.ItemGrid;

class InteractiveItemTile extends ItemTile {
	private static inline var DOUBLE_CLICK_PAUSE = 250;
	private static inline var DRAG_DIST = 3;

	private var doubleClickTimer: Timer;
	private var dragStart: Point;
	private var pendingSecondClick = false;
	private var isDragging = false;

	public function new(id: Int, parentGrid: ItemGrid, isInteractive: Bool) {
		super(id, parentGrid);
		mouseChildren = false;
		this.doubleClickTimer = new Timer(DOUBLE_CLICK_PAUSE, 1);
		this.doubleClickTimer.addEventListener(TimerEvent.TIMER_COMPLETE, this.onDoubleClickTimerComplete);
		this.setInteractive(isInteractive);
	}

	public function setInteractive(isInteractive: Bool) {
		if (isInteractive) {
			addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
			addEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
			addEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
			addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
		} else {
			removeEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
			removeEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
			removeEventListener(MouseEvent.MOUSE_OUT, this.onMouseOut);
		}
	}

	public function getDropTarget() {
		return itemSprite.dropTarget;
	}

	public function beginDragCallback() {}

	public function endDragCallback() {}

	private function setPendingDoubleClick(isPending: Bool) {
		this.pendingSecondClick = isPending;
		if (this.pendingSecondClick) {
			this.doubleClickTimer.reset();
			this.doubleClickTimer.start();
		} else
			this.doubleClickTimer.stop();
	}

	private function onMouseOut(e: MouseEvent) {
		this.setPendingDoubleClick(false);
	}

	private function onMouseUp(e: MouseEvent) {
		if (this.isDragging)
			return;

		if (e.shiftKey) {
			this.setPendingDoubleClick(false);
			dispatchEvent(new ItemTileEvent(ItemTileEvent.ITEM_SHIFT_CLICK, this));
		} else if (e.ctrlKey) {
			this.setPendingDoubleClick(false);
			dispatchEvent(new ItemTileEvent(ItemTileEvent.ITEM_CTRL_CLICK, this));
		} else if (!this.pendingSecondClick)
			this.setPendingDoubleClick(true);
		else {
			this.setPendingDoubleClick(false);
			dispatchEvent(new ItemTileEvent(ItemTileEvent.ITEM_DOUBLE_CLICK, this));
		}
	}

	private function onMouseDown(e: MouseEvent) {
		this.beginDragCheck(e);
	}

	private function beginDragCheck(e: MouseEvent) {
		this.dragStart = new Point(e.stageX, e.stageY);
		addEventListener(MouseEvent.MOUSE_MOVE, this.onMouseMoveCheckDrag);
		addEventListener(MouseEvent.MOUSE_OUT, this.cancelDragCheck);
		addEventListener(MouseEvent.MOUSE_UP, this.cancelDragCheck);
	}

	private function cancelDragCheck(e: MouseEvent) {
		removeEventListener(MouseEvent.MOUSE_MOVE, this.onMouseMoveCheckDrag);
		removeEventListener(MouseEvent.MOUSE_OUT, this.cancelDragCheck);
		removeEventListener(MouseEvent.MOUSE_UP, this.cancelDragCheck);
	}

	private function onMouseMoveCheckDrag(e: MouseEvent) {
		var dx = e.stageX - this.dragStart.x;
		var dy = e.stageY - this.dragStart.y;
		var distance = Math.sqrt(dx * dx + dy * dy);
		if (distance > DRAG_DIST) {
			this.cancelDragCheck(null);
			this.setPendingDoubleClick(false);
			this.beginDrag(e);
		}
	}

	private function onDoubleClickTimerComplete(e: TimerEvent) {
		this.setPendingDoubleClick(false);
		dispatchEvent(new ItemTileEvent(ItemTileEvent.ITEM_CLICK, this));
	}

	private function beginDrag(e: MouseEvent) {
		this.isDragging = true;
		stage.addChild(itemSprite);
		itemSprite.startDrag(true);
		itemSprite.x = e.stageX;
		itemSprite.y = e.stageY;
		itemSprite.addEventListener(MouseEvent.MOUSE_UP, this.endDrag);
		this.beginDragCallback();
	}

	private function endDrag(e: MouseEvent) {
		this.isDragging = false;
		itemSprite.stopDrag();
		itemSprite.removeEventListener(MouseEvent.MOUSE_UP, this.endDrag);
		dispatchEvent(new ItemTileEvent(ItemTileEvent.ITEM_MOVE, this));
		this.endDragCallback();
	}

	private function onRemovedFromStage(e: Event) {
		this.setPendingDoubleClick(false);
		this.cancelDragCheck(null);
		if (this.isDragging)
			itemSprite.stopDrag();
	}
}
