package engine;

import lime.graphics.opengl.GL;
import lime.graphics.opengl.GLTexture;
import openfl.display.BitmapData;

class GLTextureData {
	public var width = 0;
	public var height = 0;
	public var xOffset = 0.0;
	public var yOffset = 0.0;
	public var texture: GLTexture;

	public function new(w: Int, h: Int, tex: BitmapData) {
		this.width = tex.width;
		this.height = tex.height;

		var dataCopy = tex.image.data;
		for (i in 0...Std.int(dataCopy.byteLength / 4)) {
			var temp = dataCopy[i * 4];
			dataCopy[i * 4] = dataCopy[i * 4 + 2];
			dataCopy[i * 4 + 2] = temp;
		}

		this.texture = GL.createTexture();
		GL.bindTexture(GL.TEXTURE_2D, this.texture);
		GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, w, h, 0, GL.RGBA, GL.UNSIGNED_BYTE, dataCopy);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.NEAREST);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
	}
}
