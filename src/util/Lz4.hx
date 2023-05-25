package util;

import haxe.io.UInt8Array;
import haxe.io.Bytes;

class Lz4 {
	public static function decode(b: Bytes, oLen: Int) {
		var iBuf = new UInt8Array(b.length);
		for (i in 0...b.length)
			iBuf[i] = b.get(i);

		var iLen = iBuf.length;
		var oBuf = new UInt8Array(oLen);
		var iPos = 0;
		var oPos = 0;

		while (iPos < iLen) {
			var token = iBuf[iPos++];

			var clen = token >>> 4;

			if (clen != 0) {
				if (clen == 15) {
					var l = 0;
					while (true) {
						l = iBuf[iPos++];
						if (l != 255)
							break;
						clen += 255;
					}
					clen += l;
				}

				var end = iPos + clen;
				while (iPos < end)
					oBuf[oPos++] = iBuf[iPos++];
				
				if (iPos == iLen)
					break;
			}

			var mOffset = iBuf[iPos + 0] | (iBuf[iPos + 1] << 8);
			if (mOffset == 0 || mOffset > oPos)
				return null;
			iPos += 2;

			clen = (token & 0x0f) + 4;
			if (clen == 19) {
				var l = 0;
				while (true) {
					l = iBuf[iPos++];
					if (l != 255)
						break;
					clen += 255;
				}
				clen += l;
			}

			var mPos = oPos - mOffset;
			var end = oPos + clen;
			while (oPos < end)
				oBuf[oPos++] = oBuf[mPos++];
		}

		var bOut = Bytes.alloc(oLen);
		for (i in 0...oLen)
			bOut.set(i, oBuf[i]);
		
		return bOut;
	}
}