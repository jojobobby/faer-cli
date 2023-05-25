package mapeditor;

import map.RegionLibrary;

using util.Utils.XmlUtil;

class RegionChooser extends Chooser {
	public function new() {
		super(Layer.REGION);
		for (regionXML in RegionLibrary.xmlLibrary)
			addElement(new RegionElement(regionXML));
	}

	public function reloadObjects(search: String) {
		removeElements();

		for (regionXML in RegionLibrary.xmlLibrary)
			if (search == "" || regionXML.attribute("id").toLowerCase().indexOf(search) != -1)
				addElement(new RegionElement(regionXML));
	}
}
