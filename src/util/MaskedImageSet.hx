package util;

import util.BinPacker.Rect;
import openfl.display.BitmapData;

class MaskedImageSet {
	public final images: Array<MaskedImage>;
	public final imageRects: Array<Rect>;
	public final maskRects: Array<Rect>;

	public function new() {
		this.images = [];
		this.imageRects = [];
		this.maskRects = [];
	}

	public function addFromBitmapData(images: BitmapData, masks: BitmapData, width: Int, height: Int, ignoreAtlas: Bool = false) {
		var imagesSet = new ImageSet();
		imagesSet.addFromBitmapData(images, width, height, ignoreAtlas, true);
		var masksNull = masks == null;
		var masksSet: ImageSet = null;
		if (!masksNull) {
			masksSet = new ImageSet();
			masksSet.addFromBitmapData(masks, width, height, ignoreAtlas, true);
		}

		for (i in 0...imagesSet.images.length) {
			this.images.push(new MaskedImage(imagesSet.images[i], masksNull ? null : masksSet.images[i]));
			this.imageRects.push(imagesSet.rects[i]);
			this.maskRects.push(masksNull ? null : masksSet.rects[i]);
		}
	}

	public function addFromMaskedImage(maskedImage: MaskedImage, width: Int, height: Int) {
		this.addFromBitmapData(maskedImage.image, maskedImage.mask, width, height);
	}
}
