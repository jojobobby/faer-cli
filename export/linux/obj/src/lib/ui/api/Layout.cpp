// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lib_ui_api_Layout
#include <lib/ui/api/Layout.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif

namespace lib{
namespace ui{
namespace api{


static ::String Layout_obj_sMemberFields[] = {
	HX_("layout",aa,ae,b8,58),
	::String(null()) };

::hx::Class Layout_obj::__mClass;

void Layout_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lib.ui.api.Layout",0f,d5,38,97);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Layout_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0x26c49eeb >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lib
} // end namespace ui
} // end namespace api
