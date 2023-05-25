package objects.animation;
class AnimationsData {
	public var animations: Array<AnimationData>;

	public function new(xml: Xml) {
		this.animations = new Array<AnimationData>();
		for (animationXML in xml.elementsNamed("Animation"))
			this.animations.push(new AnimationData(animationXML));
	}
}
