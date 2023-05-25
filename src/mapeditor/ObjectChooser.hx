package mapeditor;

import objects.ObjectLibrary;

using util.Utils;

class ObjectChooser extends Chooser {
	public function new() {
		super(Layer.OBJECT);
		var ids = new Array<String>();
		for (id in ObjectLibrary.idToType.keys())
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
			var type = ObjectLibrary.idToType.get(id);
			var objXML = ObjectLibrary.xmlLibrary.get(type);
			if (!(objXML.elementExists("Item") || objXML.elementExists("Player") || objXML.element("Class") == "Projectile"))
				addElement(new ObjectElement(objXML));
		}
	}

	public function reloadObjects(search: String) {
		removeElements();

		var ids = new Array<String>();
		for (id in ObjectLibrary.idToType.keys())
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
			var type = ObjectLibrary.idToType.get(id);
			var objXML = ObjectLibrary.xmlLibrary.get(type);
			if (!(objXML.elementExists("Item") || objXML.elementExists("Player") || objXML.element("Class") == "Projectile"))
				addElement(new ObjectElement(objXML));
		}
	}
}
