package mapeditor;

import map.GroundLibrary;

class GroundChooser extends Chooser {
	public function new() {
		super(Layer.GROUND);
		var ids = new Array<String>();
		for (id in GroundLibrary.idToType.keys())
			ids.push(id);

		ids.sort((s1: String, s2: String) -> {
			var a = s1.toLowerCase();
			var b = s2.toLowerCase();
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			return 0;
		});
		for (id in ids) {
			var type = GroundLibrary.idToType.get(id);
			addElement(new GroundElement(GroundLibrary.xmlLibrary.get(type)));
		}
	}

	public function reloadObjects(search: String) {
		removeElements();

		var ids = new Array<String>();
		for (id in GroundLibrary.idToType.keys())
			if (search == "" || id.toLowerCase().indexOf(search) != -1)
				ids.push(id);

		ids.sort((s1: String, s2: String) -> {
			var a = s1.toLowerCase();
			var b = s2.toLowerCase();
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			return 0;
		});
		for (id in ids) {
			var type = GroundLibrary.idToType.get(id);
			addElement(new GroundElement(GroundLibrary.xmlLibrary.get(type)));
		}
	}
}