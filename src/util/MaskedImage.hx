package util;

import openfl.display.BitmapData;

class MaskedImage {
	public var image: BitmapData;
	public var mask: BitmapData;

	public function new(image: BitmapData, mask: BitmapData) {
		this.image = image;
		this.mask = mask;
	}

	public function width() {
		return this.image.width;
	}

	public function height() {
		return this.image.height;
	}

	public function mirror(width: Int = 0): MaskedImage {
		var mirroredImage: BitmapData = BitmapUtil.mirror(this.image, width);
		var mirroredMask: BitmapData = this.mask == null ? null : BitmapUtil.mirror(this.mask, width);
		return new MaskedImage(mirroredImage, mirroredMask);
	}

	public function amountTransparent() {
		return BitmapUtil.amountTransparent(this.image);
	}
}
