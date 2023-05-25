package map;

using util.Utils;

class AnimateProperties {
	public static inline var NO_ANIMATE = 0;
	public static inline var WAVE_ANIMATE: Int = 1;
	public static inline var FLOW_ANIMATE: Int = 2;

	public var animType = 0;
	public var dx = 0.0;
	public var dy = 0.0;

	public function new(animateXML: Xml) {
		if (animateXML == null || animateXML.firstElement() == null)
			return;

		switch (animateXML.nodeValue) {
			case "Wave":
				this.animType = WAVE_ANIMATE;
			case "Flow":
				this.animType = FLOW_ANIMATE;
		}

		this.dx = animateXML.floatAttribute("dx");
		this.dy = animateXML.floatAttribute("dy");
	}
}
