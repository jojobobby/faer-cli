package game;

import map.Camera;
import network.NetworkHandler;
import lime.system.System;
import constants.GeneralConstants;
import constants.UseType;
import game.model.VialModel;
import objects.Player;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.MouseEvent;
import ui.model.TabStripModel;
import ui.options.Options;
import util.Utils;
import util.Settings;

class InputHandler {
	public var isWalking = false;

	private var moveLeft = 0;
	private var moveRight = 0;
	private var moveUp = 0;
	private var moveDown = 0;
	private var rotateLeft = 0;
	private var rotateRight = 0;
	private var shootDown = false;

	public function new(gs: GameSprite) {
		gs.addEventListener(Event.ADDED_TO_STAGE, this.onAddedToStage);
		gs.addEventListener(Event.REMOVED_FROM_STAGE, this.onRemovedFromStage);
	}

	public function clearInput() {
		this.moveLeft = this.moveRight = this.moveUp = this.moveDown = this.rotateLeft = this.rotateRight = 0;
		this.shootDown = false;

		this.setPlayerMovement();
	}

	private function setPlayerMovement() {
		Global.gameSprite.map.player?.setRelativeMovement(this.rotateRight - this.rotateLeft, this.moveRight - this.moveLeft, this.moveDown - this.moveUp);
	}

	private function useItem(slotId: Int) {
		if (Global.tabStripModel.currentSelection == TabStripModel.BACKPACK)
			slotId += GeneralConstants.NUM_INVENTORY_SLOTS;

		NetworkHandler.useItem_new(Global.gameSprite.map.player, slotId);
	}

	private function togglePerformanceStats() {
		if (Global.gameSprite.statsView != null) {
			Global.gameSprite.statsView.visible = false;
			Global.gameSprite.statsView = null;
		} else {
			Global.gameSprite.addStatsView();
			Global.gameSprite.lastFrameUpdate = System.getTimer();
		}
	}

	private function onAddedToStage(event: Event) {
		Main.primaryStage.addEventListener(Event.DEACTIVATE, this.onDeactivate);
		Main.primaryStage.addEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
		Main.primaryStage.addEventListener(KeyboardEvent.KEY_UP, this.onKeyUp);
		Main.primaryStage.addEventListener(MouseEvent.MOUSE_WHEEL, onMouseWheel);
		Main.primaryStage.addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		Main.primaryStage.addEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
		Main.primaryStage.addEventListener(MouseEvent.RIGHT_MOUSE_DOWN, this.onRightMouseDown);
		Main.primaryStage.addEventListener(MouseEvent.RIGHT_MOUSE_UP, this.onRightMouseUp);
		Main.primaryStage.addEventListener(MouseEvent.MIDDLE_MOUSE_DOWN, this.onMiddleMouseDown);
		Main.primaryStage.addEventListener(MouseEvent.MIDDLE_MOUSE_UP, this.onMiddleMouseUp);
		Main.primaryStage.addEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onRemovedFromStage(event: Event) {
		Main.primaryStage.removeEventListener(Event.DEACTIVATE, this.onDeactivate);
		Main.primaryStage.removeEventListener(KeyboardEvent.KEY_DOWN, this.onKeyDown);
		Main.primaryStage.removeEventListener(KeyboardEvent.KEY_UP, this.onKeyUp);
		Main.primaryStage.removeEventListener(MouseEvent.MOUSE_WHEEL, onMouseWheel);
		Main.primaryStage.removeEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		Main.primaryStage.removeEventListener(MouseEvent.MOUSE_UP, this.onMouseUp);
		Main.primaryStage.removeEventListener(MouseEvent.RIGHT_MOUSE_DOWN, this.onRightMouseDown);
		Main.primaryStage.removeEventListener(MouseEvent.RIGHT_MOUSE_UP, this.onRightMouseUp);
		Main.primaryStage.removeEventListener(MouseEvent.MIDDLE_MOUSE_DOWN, this.onMiddleMouseDown);
		Main.primaryStage.removeEventListener(MouseEvent.MIDDLE_MOUSE_UP, this.onMiddleMouseUp);
		Main.primaryStage.removeEventListener(Event.ENTER_FRAME, this.onEnterFrame);
	}

	private function onDeactivate(event: Event) {
		this.clearInput();
	}

	private function onMouseDown(event: MouseEvent) {
		downAction(KeyCode.Mouse1, event.currentTarget == event.target
			|| event.target == Global.gameSprite.map
			|| event.target == Global.gameSprite);
	}

	private function onMouseUp(_: MouseEvent) {
		upAction(KeyCode.Mouse1);
	}

	private function onRightMouseDown(event: MouseEvent) {
		downAction(KeyCode.Mouse2, event.currentTarget == event.target
			|| event.target == Global.gameSprite.map
			|| event.target == Global.gameSprite);
	}

	private function onRightMouseUp(_: MouseEvent) {
		upAction(KeyCode.Mouse2);
	}

	private function onMiddleMouseDown(event: MouseEvent) {
		downAction(KeyCode.Mouse3, event.currentTarget == event.target
			|| event.target == Global.gameSprite.map
			|| event.target == Global.gameSprite);
	}

	private function onMiddleMouseUp(_: MouseEvent) {
		upAction(KeyCode.Mouse3);
	}

	private static function onMouseWheel(event: MouseEvent) {
		Global.gameSprite?.miniMap?.onMiniMapZoom(event.delta > 0 ? "in" : "out");
	}

	private function onEnterFrame(event: Event) {
		if (!this.shootDown)
			return;

		Global.gameSprite.map.player?.attemptAttackAngle(Math.atan2(Main.primaryStage.mouseY - Main.mouseYOffset + 20, Main.primaryStage.mouseX - Main.mouseXOffset));
	}

	private function onKeyDown(event: KeyboardEvent) {
		if (Main.primaryStage.focus != null)
			return;

		downAction(event.keyCode);
	}

	private function onKeyUp(event: KeyboardEvent) {
		if (Main.primaryStage.focus != null)
			return;

		upAction(event.keyCode);
	}

	private function downAction(keyCode: KeyCode, shootCheck: Bool = true) {
		var player = Global.gameSprite.map.player;

		if (keyCode == Settings.shoot) {
			if (shootCheck)
				player?.attemptAttackAngle(Math.atan2(Main.primaryStage.mouseY - Main.mouseYOffset + 20, Main.primaryStage.mouseX - Main.mouseXOffset));
			else
				return;

			this.shootDown = true;
		} else if (keyCode == Settings.walk)
			this.isWalking = true;
		else if (keyCode == Settings.moveUp)
			this.moveUp = 1;
		else if (keyCode == Settings.moveDown)
			this.moveDown = 1;
		else if (keyCode == Settings.moveLeft)
			this.moveLeft = 1;
		else if (keyCode == Settings.moveRight)
			this.moveRight = 1;
		else if (keyCode == Settings.rotateLeft)
			this.rotateLeft = 1;
		else if (keyCode == Settings.rotateRight)
			this.rotateRight = 1;
		else if (keyCode == Settings.resetCamera)
			Camera.angleRad = 0;
		else if (keyCode == Settings.useAbility)
			player?.useAltWeapon(Main.primaryStage.mouseX - Main.mouseXOffset, Main.primaryStage.mouseY - Main.mouseYOffset, UseType.START_USE);
		else if (keyCode == Settings.inv1)
			this.useItem(4);
		else if (keyCode == Settings.inv2)
			this.useItem(5);
		else if (keyCode == Settings.inv3)
			this.useItem(6);
		else if (keyCode == Settings.inv4)
			this.useItem(7);
		else if (keyCode == Settings.inv5)
			this.useItem(8);
		else if (keyCode == Settings.inv6)
			this.useItem(9);
		else if (keyCode == Settings.inv7)
			this.useItem(10);
		else if (keyCode == Settings.inv8)
			this.useItem(11);
		else if (keyCode == Settings.healthVial) {
			if (player != null && player.healthVialCount > 0 && player.hp < player.maxHP)
				Global.useVial(VialModel.HEALTH_VIAL_ID);
		} else if (keyCode == Settings.magicVial) {
			if (player != null && player.magicVialCount > 0 && player.mp < player.maxMP)
				Global.useVial(VialModel.MAGIC_VIAL_ID);
		} else if (keyCode == Settings.perfStats)
			this.togglePerformanceStats();
		else if (keyCode == Settings.goToHub)
			NetworkHandler.escape();
		else if (keyCode == Settings.options) {
			this.clearInput();
			var options = new Options(Global.gameSprite);
			options.x = (Main.stageWidth - 800) / 2;
			options.y = (Main.stageHeight - 600) / 2;
			Global.layers.overlay.addChild(options);
		} else if (keyCode == Settings.toggleCentering) {
			Settings.centerCamera = !Settings.centerCamera;
			Settings.save();
		} else if (keyCode == Settings.interact) {
			if (Global.currentInteractiveTarget > 0)
				NetworkHandler.usePortal(Global.currentInteractiveTarget);
		}

		this.setPlayerMovement();
	}

	private function upAction(keyCode: KeyCode) {
		if (keyCode == Settings.shoot)
			this.shootDown = false;
		else if (keyCode == Settings.walk)
			this.isWalking = false;
		else if (keyCode == Settings.moveUp)
			this.moveUp = 0;
		else if (keyCode == Settings.moveDown)
			this.moveDown = 0;
		else if (keyCode == Settings.moveLeft)
			this.moveLeft = 0;
		else if (keyCode == Settings.moveRight)
			this.moveRight = 0;
		else if (keyCode == Settings.rotateLeft)
			this.rotateLeft = 0;
		else if (keyCode == Settings.rotateRight)
			this.rotateRight = 0;

		this.setPlayerMovement();
	}
}
