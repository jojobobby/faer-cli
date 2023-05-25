package classes.view;

import account.services.BuySkinTask;
import classes.model.CharacterSkin;
import classes.model.CharacterSkinState;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.filters.ColorMatrixFilter;
import openfl.filters.DropShadowFilter;
import ui.BuyButton;
import ui.RadioButton;
import ui.SimpleText;
import ui.view.NotEnoughGoldDialog;
import util.Utils;

class CharSkinListItem extends Sprite {
	public static inline var WIDTH = 420;
	public static inline var PADDING = 16;
	public static inline var HEIGHT = 60;
	private static inline var HIGHLIGHTED_COLOR = 0x7B7B7B;
	private static inline var AVAILABLE_COLOR = 0x5A5A5A;
	private static inline var LOCKED_COLOR = 0x282828;

	private var grayscaleMatrix = new ColorMatrixFilter(ColorUtils.greyscaleFilterMatrix);
	private var background: Shape;
	private var skinContainer: Sprite;
	private var nameText: SimpleText;
	private var selectionButton: RadioButton;
	private var lock: Bitmap;
	private var lockText: SimpleText;
	private var buyButtonContainer: Sprite;
	private var model: CharacterSkin;
	private var state: CharacterSkinState;
	private var isSelected = false;
	private var skinIcon: Bitmap;
	private var buyButton: BuyButton;
	private var isOver = false;

	private static function drawBackground(graphics: Graphics, width: Int) {
		graphics.clear();
		graphics.beginFill(AVAILABLE_COLOR);
		graphics.drawRect(0, 0, width, HEIGHT);
		graphics.endFill();
	}

	public function new() {
		super();

		this.buyButtonContainer = new Sprite();
		this.buyButtonContainer.x = WIDTH - PADDING;
		this.buyButtonContainer.y = HEIGHT * 0.5;
		addChild(this.buyButtonContainer);
		this.buyButtonContainer.addEventListener(MouseEvent.CLICK, this.onBuy);

		this.lockText = new SimpleText(14, 0xFFFFFF, false, 0, 0);
		addChild(this.lockText);

		this.lock = new Bitmap();
		this.lock.scaleX = 2;
		this.lock.scaleY = 2;
		this.lock.y = HEIGHT * 0.5 - 4;
		this.lock.visible = false;
		addChild(this.lock);

		this.selectionButton = new RadioButton();
		this.selectionButton.setSelected(false);
		this.selectionButton.x = WIDTH - this.selectionButton.width - 15;
		this.selectionButton.y = HEIGHT / 2 - this.selectionButton.height / 2;
		addChild(this.selectionButton);
		this.selectionButton.changed.on(this.onSelected);

		this.nameText = new SimpleText(18, 0xFFFFFF, false, 0, 0);
		this.nameText.x = 75;
		this.nameText.y = 15;
		this.nameText.setBold(true);
		this.nameText.filters = [new DropShadowFilter(0, 0, 0, 1, 8, 8)];
		addChild(this.nameText);

		this.skinContainer = new Sprite();
		this.skinContainer.x = 8;
		this.skinContainer.y = 4;
		addChild(this.skinContainer);

		this.background = new Shape();
		drawBackground(this.background.graphics, WIDTH);
		addChild(this.background);

		this.state = CharacterSkinState.NULL;
		addEventListener(Event.ADDED_TO_STAGE, onAdded);
	}

	private function onAdded(_: Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onAdded);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoved);
	}

	private function onRemoved(_: Event) {
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoved);

		this.buyButtonContainer.removeEventListener(MouseEvent.CLICK, this.onBuy);
		this.selectionButton.changed.off(this.onSelected);
		this.setModel(null);
	}

	private function onBuy(_: MouseEvent) {
		var skin = this.getModel();
		if (skin.getState() != CharacterSkinState.PURCHASABLE)
			return;

		if (Global.playerModel.getGems() >= skin.cost) {
			BuySkinTask.skin = skin;
			Global.buySkinTask.start();
		} else
			Global.layers.dialogs.openDialog(new NotEnoughGoldDialog());
	}

	private function onSelected(isSelected: Bool) {
		this.getModel().setIsSelected(isSelected);
	}

	public function setLockIcon(data: BitmapData) {
		this.lock.bitmapData = data;
		this.lock.x = this.lockText.x - this.lock.width - 5;
	}

	public function setBuyButton(buyButton: BuyButton) {
		this.buyButton = buyButton;
		if (this.model != null)
			this.setCost();
		this.buyButtonContainer.addChild(buyButton);
		buyButton.x = -buyButton.width;
		buyButton.y = -buyButton.height * 0.5;
		this.buyButtonContainer.visible = this.state == CharacterSkinState.PURCHASABLE;
	}

	public function setSkin(icon: Bitmap) {
		if (this.skinIcon != null)
			this.skinContainer.removeChild(this.skinIcon);
		this.skinIcon = icon;
		if (this.skinIcon != null)
			this.skinContainer.addChild(this.skinIcon);
	}

	public function getModel() {
		return this.model;
	}

	public function setModel(value: CharacterSkin) {
		if (this.model != null)
			this.model.changed.off(this.onModelChanged);
		this.model = value;
		if (this.model != null)
			this.model.changed.on(this.onModelChanged);
		this.onModelChanged(this.model);
		addEventListener(MouseEvent.MOUSE_OVER, this.onOver);
		addEventListener(MouseEvent.MOUSE_OUT, this.onOut);
	}

	public function getState() {
		return this.state;
	}

	public function getIsSelected() {
		return this.isSelected;
	}

	public function setIsSelected(value: Bool) {
		this.isSelected = value;
		if (this.isSelected)
			this.state == CharacterSkinState.OWNED;
		this.selectionButton.setSelected(value);
		this.updateBackground();
	}

	public function setWidth(width: Int) {
		this.buyButtonContainer.x = width - PADDING;
		this.lockText.x = width - this.lockText.width - 15;
		this.lock.x = this.lockText.x - this.lock.width - 5;
		this.selectionButton.x = width - this.selectionButton.width - 15;
		drawBackground(this.background.graphics, width);
	}

	function removeEventListeners() {
		removeEventListener(MouseEvent.CLICK, this.onClick);
	}

	private function onModelChanged(skin: CharacterSkin) {
		this.state = this.model?.getState() ?? CharacterSkinState.NULL;
		this.updateName();
		this.updateState();
		if (this.buyButton != null)
			this.setCost();

		if (this.model != null)
			this.setIsSelected(this.model.getIsSelected());
	}

	private function updateName() {
		this.nameText.text = this.model != null ? this.model.name : "";
		this.nameText.updateMetrics();
	}

	private function updateState() {
		this.setButtonVisibilities();
		this.updateBackground();
		this.setEventListeners();
		this.updateGrayFilter();
	}

	private function setButtonVisibilities() {
		var isOwned = this.state == CharacterSkinState.OWNED;
		var isPurchasable = this.state == CharacterSkinState.PURCHASABLE;
		var isPurchasing = this.state == CharacterSkinState.PURCHASING;
		var isLocked = this.state == CharacterSkinState.LOCKED;
		this.selectionButton.visible = isOwned;
		if (this.buyButtonContainer != null)
			this.buyButtonContainer.visible = isPurchasable;
		this.lock.visible = isLocked;
		this.lockText.visible = isLocked || isPurchasing;
	}

	private function setEventListeners() {
		if (this.state == CharacterSkinState.OWNED)
			this.addEventListeners();
		else
			this.removeEventListeners();
	}

	private function setCost() {
		var cost = this.model != null ? this.model.cost : 0;
		this.buyButton.setPrice(cost, 0);
		this.buyButton.setWidth(120);
	}

	private function addEventListeners() {
		addEventListener(MouseEvent.CLICK, this.onClick);
	}

	private function updateBackground() {
		var ct = this.background.transform.colorTransform;
		ct.color = this.getColor();
		this.background.transform.colorTransform = ct;
	}

	private function getColor() {
		if (this.state.isDisabled)
			return LOCKED_COLOR;

		if (this.isSelected || this.isOver)
			return HIGHLIGHTED_COLOR;

		return AVAILABLE_COLOR;
	}

	private function updateGrayFilter() {
		filters = this.state == CharacterSkinState.PURCHASING ? [this.grayscaleMatrix] : [];
	}

	private function onClick(_: MouseEvent) {
		this.setIsSelected(true);
	}

	private function onOver(_: MouseEvent) {
		this.isOver = true;
		this.updateBackground();
		Global.focusCharSkin.emit(this.getModel());
	}

	private function onOut(_: MouseEvent) {
		this.isOver = false;
		this.updateBackground();
		Global.focusCharSkin.emit(null);
	}
}
