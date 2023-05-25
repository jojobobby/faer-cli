package util;
import haxe.macro.Context;

class MacroUtil {
	macro public static function buildDate(): ExprOf<Date> {
		var date = Date.now();
		return macro new Date(${macro $v{date.getFullYear()}}, ${macro $v{date.getMonth()}}, ${macro $v{date.getDate()}}, ${macro $v{date.getHours()}},
			${macro $v{date.getMinutes()}}, ${macro $v{date.getSeconds()}});
	}

	macro public static function buildDateString(): ExprOf<String> {
		return macro $v{Date.now().toString()};
	}

	macro public static function readFile(path: String): ExprOf<String> {
		try {
			var p = Context.resolvePath(path);
			Context.registerModuleDependency(Context.getLocalModule(), p);
			return macro $v{sys.io.File.getContent(p)};
		} catch (e) {
			return haxe.macro.Context.error('Failed to load string file $path: $e', Context.currentPos());
		}
	}

	macro public static function readJson(path: String) {
		return try {
			var p = Context.resolvePath(path);
			Context.registerModuleDependency(Context.getLocalModule(), p);
			return macro $v{haxe.Json.parse(sys.io.File.getContent(p))};
		} catch (e) {
			return haxe.macro.Context.error('Failed to load json: $e', haxe.macro.Context.currentPos());
		}
	}
}