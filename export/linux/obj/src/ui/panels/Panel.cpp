// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_game_GameSprite
#include <game/GameSprite.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_ui_panels_Panel
#include <ui/panels/Panel.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f66151deec35fd77_12_new,"ui.panels.Panel","new",0x797e98f1,"ui.panels.Panel.new","ui/panels/Panel.hx",12,0x0fc521bf)
namespace ui{
namespace panels{

void Panel_obj::__construct( ::game::GameSprite gs){
            	HX_STACKFRAME(&_hx_pos_f66151deec35fd77_12_new)
HXLINE(  13)		super::__construct();
HXLINE(  15)		this->gs = gs;
            	}

Dynamic Panel_obj::__CreateEmpty() { return new Panel_obj; }

void *Panel_obj::_hx_vtable = 0;

Dynamic Panel_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Panel_obj > _hx_result = new Panel_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Panel_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1f4df417) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x1f4df417;
		}
	} else {
		if (inClassId<=(int)0x6b353933) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x6b353933;
		} else {
			return inClassId==(int)0x7fae8619;
		}
	}
}


::hx::ObjectPtr< Panel_obj > Panel_obj::__new( ::game::GameSprite gs) {
	::hx::ObjectPtr< Panel_obj > __this = new Panel_obj();
	__this->__construct(gs);
	return __this;
}

::hx::ObjectPtr< Panel_obj > Panel_obj::__alloc(::hx::Ctx *_hx_ctx, ::game::GameSprite gs) {
	Panel_obj *__this = (Panel_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Panel_obj), true, "ui.panels.Panel"));
	*(void **)__this = Panel_obj::_hx_vtable;
	__this->__construct(gs);
	return __this;
}

Panel_obj::Panel_obj()
{
}

void Panel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Panel);
	HX_MARK_MEMBER_NAME(gs,"gs");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Panel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(gs,"gs");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Panel_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"gs") ) { return ::hx::Val( gs ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Panel_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"gs") ) { gs=inValue.Cast<  ::game::GameSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Panel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("gs",2c,5a,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Panel_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::game::GameSprite */ ,(int)offsetof(Panel_obj,gs),HX_("gs",2c,5a,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Panel_obj_sStaticStorageInfo = 0;
#endif

static ::String Panel_obj_sMemberFields[] = {
	HX_("gs",2c,5a,00,00),
	::String(null()) };

::hx::Class Panel_obj::__mClass;

void Panel_obj::__register()
{
	Panel_obj _hx_dummy;
	Panel_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.panels.Panel",7f,4c,49,6e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Panel_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Panel_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Panel_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Panel_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace panels