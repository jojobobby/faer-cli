package util;

import util.BinPacker.Rect;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import openfl.display.BitmapData;

class ImageSet {
	public final images: Array<BitmapData>;
	public final rects: Array<Rect>;
	public var allowsAtlas = true;

	public final function new() {
		this.images = [];
		this.rects = [];
	}

	public final function add(bitmapData: BitmapData) {
		this.images.push(bitmapData);
	}

	public final function random() {
		return this.images[Std.int(Math.random() * this.images.length)];
	}

	public final function addFromBitmapData(bitmapData: BitmapData, width: Int, height: Int, ignoreAtlas: Bool = false, animChar: Bool = false) {
		this.allowsAtlas = !ignoreAtlas;

		var maxX = Std.int(bitmapData.width / width),
			maxY = Std.int(bitmapData.height / height);

		var mirrored = false;
		for (y in 0...maxY)
			for (x in 0...maxX) {
				if (animChar && x == 5) {
					if (!mirrored) {
						for (i in 0...5) {
							var w = i == 4 ? width * 2 : width;
							var tex = BitmapUtil.mirror(this.images[i]);
							this.images.push(tex);

							if (!ignoreAtlas) {
								var rect = Main.atlasPacker.insert(w + Main.PADDING * 2, height + Main.PADDING * 2);
								this.rects.push(rect);
								Main.tempAtlas.copyPixels(tex, new Rectangle(0, 0, rect.width, rect.height),
									new Point(rect.x + Main.PADDING, rect.y + Main.PADDING));
							} else
								this.rects.push(new Rect(4096, 4096, 8, 8));
						}

						mirrored = true;
					}

					continue;
				}

				var w = animChar && x == 4 ? width * 2 : width;
				var tex = BitmapUtil.cropToBitmapData(bitmapData, x * width, y * height, w, height);
				this.images.push(tex);

				if (!ignoreAtlas) {
					var rect = Main.atlasPacker.insert(w + Main.PADDING * 2, height + Main.PADDING * 2);
					this.rects.push(rect);
					Main.tempAtlas.copyPixels(tex, new Rectangle(0, 0, rect.width, rect.height), new Point(rect.x + Main.PADDING, rect.y + Main.PADDING));
				} else
					this.rects.push(new Rect(4096, 4096, 8, 8));
			}
	}
}
