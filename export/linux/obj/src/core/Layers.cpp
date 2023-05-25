// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_core_Layers
#include <core/Layers.h>
#endif
#ifndef INCLUDED_core_ScreensView
#include <core/ScreensView.h>
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
#ifndef INCLUDED_ui_dialogs_DialogsView
#include <ui/dialogs/DialogsView.h>
#endif
#ifndef INCLUDED_ui_tooltip_TooltipsView
#include <ui/tooltip/TooltipsView.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_263b81aea9fc5248_12_new,"core.Layers","new",0x8d8efa43,"core.Layers.new","core/Layers.hx",12,0x3976b66c)
namespace core{

void Layers_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_263b81aea9fc5248_12_new)
HXLINE(  13)		super::__construct();
HXLINE(  15)		this->addChild((this->screens =  ::core::ScreensView_obj::__alloc( HX_CTX )));
HXLINE(  16)		this->addChild((this->overlay =  ::openfl::display::Sprite_obj::__alloc( HX_CTX )));
HXLINE(  17)		this->addChild((this->tooltips =  ::ui::tooltip::TooltipsView_obj::__alloc( HX_CTX )));
HXLINE(  18)		this->addChild((this->dialogs =  ::ui::dialogs::DialogsView_obj::__alloc( HX_CTX )));
            	}

Dynamic Layers_obj::__CreateEmpty() { return new Layers_obj; }

void *Layers_obj::_hx_vtable = 0;

Dynamic Layers_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Layers_obj > _hx_result = new Layers_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Layers_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x319bbae5 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}


::hx::ObjectPtr< Layers_obj > Layers_obj::__new() {
	::hx::ObjectPtr< Layers_obj > __this = new Layers_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< Layers_obj > Layers_obj::__alloc(::hx::Ctx *_hx_ctx) {
	Layers_obj *__this = (Layers_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Layers_obj), true, "core.Layers"));
	*(void **)__this = Layers_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

Layers_obj::Layers_obj()
{
}

void Layers_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Layers);
	HX_MARK_MEMBER_NAME(overlay,"overlay");
	HX_MARK_MEMBER_NAME(screens,"screens");
	HX_MARK_MEMBER_NAME(tooltips,"tooltips");
	HX_MARK_MEMBER_NAME(dialogs,"dialogs");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Layers_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(overlay,"overlay");
	HX_VISIT_MEMBER_NAME(screens,"screens");
	HX_VISIT_MEMBER_NAME(tooltips,"tooltips");
	HX_VISIT_MEMBER_NAME(dialogs,"dialogs");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Layers_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"overlay") ) { return ::hx::Val( overlay ); }
		if (HX_FIELD_EQ(inName,"screens") ) { return ::hx::Val( screens ); }
		if (HX_FIELD_EQ(inName,"dialogs") ) { return ::hx::Val( dialogs ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tooltips") ) { return ::hx::Val( tooltips ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Layers_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"overlay") ) { overlay=inValue.Cast<  ::openfl::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"screens") ) { screens=inValue.Cast<  ::core::ScreensView >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dialogs") ) { dialogs=inValue.Cast<  ::ui::dialogs::DialogsView >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tooltips") ) { tooltips=inValue.Cast<  ::ui::tooltip::TooltipsView >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Layers_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("overlay",90,43,10,a9));
	outFields->push(HX_("screens",87,c3,36,2a));
	outFields->push(HX_("tooltips",10,b6,8a,d0));
	outFields->push(HX_("dialogs",ab,2a,71,5b));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Layers_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::display::Sprite */ ,(int)offsetof(Layers_obj,overlay),HX_("overlay",90,43,10,a9)},
	{::hx::fsObject /*  ::core::ScreensView */ ,(int)offsetof(Layers_obj,screens),HX_("screens",87,c3,36,2a)},
	{::hx::fsObject /*  ::ui::tooltip::TooltipsView */ ,(int)offsetof(Layers_obj,tooltips),HX_("tooltips",10,b6,8a,d0)},
	{::hx::fsObject /*  ::ui::dialogs::DialogsView */ ,(int)offsetof(Layers_obj,dialogs),HX_("dialogs",ab,2a,71,5b)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Layers_obj_sStaticStorageInfo = 0;
#endif

static ::String Layers_obj_sMemberFields[] = {
	HX_("overlay",90,43,10,a9),
	HX_("screens",87,c3,36,2a),
	HX_("tooltips",10,b6,8a,d0),
	HX_("dialogs",ab,2a,71,5b),
	::String(null()) };

::hx::Class Layers_obj::__mClass;

void Layers_obj::__register()
{
	Layers_obj _hx_dummy;
	Layers_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("core.Layers",d1,1c,d6,bc);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Layers_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Layers_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Layers_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Layers_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace core
