package mapeditor;

import haxe.ds.Vector;
import openfl.display.BitmapData;
import openfl.geom.Matrix;
import openfl.geom.Rectangle;

class BigBitmapData {
	private static inline var CHUNK_SIZE = 256;

	public var width: Int;
	public var height: Int;
	public var fillColor: UInt;

	private var maxChunkX: Int;
	private var maxChunkY: Int;
	private var chunks: Vector<BitmapData>;

	public function new(width: Int, height: Int, transparent: Bool, fillColor: UInt) {
		this.width = width;
		this.height = height;
		this.fillColor = fillColor;
		this.maxChunkX = Math.ceil(this.width / CHUNK_SIZE);
		this.maxChunkY = Math.ceil(this.height / CHUNK_SIZE);
		this.chunks = new Vector<BitmapData>(this.maxChunkX * this.maxChunkY);
		for (cX in 0...this.maxChunkX)
			for (cY in 0...this.maxChunkY) {
				var sizeX = Std.int(Math.min(CHUNK_SIZE, this.width - cX * CHUNK_SIZE));
				var sizeY = Std.int(Math.min(CHUNK_SIZE, this.height - cY * CHUNK_SIZE));
				this.chunks[cX + cY * this.maxChunkX] = new BitmapData(sizeX, sizeY, transparent, this.fillColor);
			}
	}

	public function copyTo(source: BitmapData, sourceRect: Rectangle, destRect: Rectangle) {
		var scaleX = destRect.width / sourceRect.width;
		var scaleY = destRect.height / sourceRect.height;
		var startChunkX = Std.int(destRect.x / CHUNK_SIZE);
		var startChunkY = Std.int(destRect.y / CHUNK_SIZE);
		var endChunkX = Math.ceil(destRect.right / CHUNK_SIZE);
		var endChunkY = Math.ceil(destRect.bottom / CHUNK_SIZE);
		var m = new Matrix();
		for (cX in startChunkX...endChunkX)
			for (cY in startChunkY...endChunkY) {
				var chunk = this.chunks[cX + cY * this.maxChunkX];
				m.identity();
				m.scale(scaleX, scaleY);
				m.translate(destRect.x - cX * CHUNK_SIZE - sourceRect.x * scaleX, destRect.y - cY * CHUNK_SIZE - sourceRect.x * scaleY);
				var clipRect = new Rectangle(destRect.x - cX * CHUNK_SIZE, destRect.y - cY * CHUNK_SIZE, destRect.width, destRect.height);
				chunk.draw(source, m, null, null, clipRect, false);
			}
	}

	public function copyFrom(sourceRect: Rectangle, dest: BitmapData, destRect: Rectangle) {
		var scaleX = destRect.width / sourceRect.width;
		var scaleY = destRect.height / sourceRect.height;
		var startChunkX = Math.floor(Math.max(0, sourceRect.x / CHUNK_SIZE));
		var startChunkY = Math.floor(Math.max(0, sourceRect.y / CHUNK_SIZE));
		var endChunkX = Math.ceil(Math.min(this.maxChunkX - 1, sourceRect.right / CHUNK_SIZE));
		var endChunkY = Math.ceil(Math.min(this.maxChunkY - 1, sourceRect.bottom / CHUNK_SIZE));
		var m = new Matrix();
		for (cX in startChunkX...endChunkX)
			for (cY in startChunkY...endChunkY) {
				var chunk = this.chunks[cX + cY * this.maxChunkX];
				m.identity();
				m.translate(destRect.x / scaleX - sourceRect.x + cX * CHUNK_SIZE, destRect.y / scaleY - sourceRect.y + cY * CHUNK_SIZE);
				m.scale(scaleX, scaleY);
				dest.draw(chunk, m, null, null, destRect, false);
			}
	}

	public function erase(rect: Rectangle) {
		var startChunkX = Math.floor(rect.x / CHUNK_SIZE);
		var startChunkY = Math.floor(rect.y / CHUNK_SIZE);
		var endChunkX = Math.ceil(rect.right / CHUNK_SIZE);
		var endChunkY = Math.ceil(rect.bottom / CHUNK_SIZE);
		var chunkRect = new Rectangle();
		for (cX in startChunkX...endChunkX)
			for (cY in startChunkY...endChunkY) {
				var chunk = this.chunks[cX + cY * this.maxChunkX];
				chunkRect.x = rect.x - cX * CHUNK_SIZE;
				chunkRect.y = rect.y - cY * CHUNK_SIZE;
				chunkRect.right = rect.right - cX * CHUNK_SIZE;
				chunkRect.bottom = rect.bottom - cY * CHUNK_SIZE;
				chunk.fillRect(chunkRect, this.fillColor);
			}
	}

	public function dispose() {
		for (tex in this.chunks)
			tex.dispose();
		this.chunks = null;
	}
}
