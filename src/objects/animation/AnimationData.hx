package objects.animation;

using util.Utils;

class AnimationData {
	public var prob: Float = 1.0;
	public var period = 0;
	public var periodJitter = 0;
	public var sync = false;
	public var frames: Array<FrameData>;

	public function new(xml: Xml) {
		this.frames = new Array<FrameData>();
		this.prob = xml.floatAttribute("prob");
		this.period = xml.intAttribute("period");
		this.periodJitter = xml.intAttribute("periodJitter");
		this.sync = xml.attribute("sync") == "true";
		for (frameXML in xml.elementsNamed("Frame"))
			this.frames.push(new FrameData(frameXML));
	}

	public function getLastRun(time: Int) {
		if (this.sync)
			return Math.round(time / this.period) * this.period;

		return Std.int(time + this.getPeriod() + 200 * Math.random());
	}

	public function getNextRun(time: Int) {
		if (this.sync)
			return Math.round(time / this.period) * this.period + this.period;

		return time + this.getPeriod();
	}

	private function getPeriod() {
		if (this.periodJitter == 0)
			return this.period;

		return Std.int(this.period - this.periodJitter + 2 * Math.random() * this.periodJitter);
	}
}
