// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
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
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_DropShadowFilter
#include <openfl/filters/DropShadowFilter.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_screens_LoadingScreen
#include <screens/LoadingScreen.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_view_ScreenBase
#include <ui/view/ScreenBase.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_39674d6a06d07a03_12_new,"screens.LoadingScreen","new",0xf3ca2533,"screens.LoadingScreen.new","screens/LoadingScreen.hx",12,0x2277939e)
HX_LOCAL_STACK_FRAME(_hx_pos_39674d6a06d07a03_18_onAddedToStage,"screens.LoadingScreen","onAddedToStage",0xab4e082f,"screens.LoadingScreen.onAddedToStage","screens/LoadingScreen.hx",18,0x2277939e)
HX_LOCAL_STACK_FRAME(_hx_pos_39674d6a06d07a03_42_onResize,"screens.LoadingScreen","onResize",0x008e9ec0,"screens.LoadingScreen.onResize","screens/LoadingScreen.hx",42,0x2277939e)
namespace screens{

void LoadingScreen_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_39674d6a06d07a03_12_new)
HXLINE(  13)		super::__construct();
HXLINE(  15)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAddedToStage_dyn(),null(),null(),null());
            	}

Dynamic LoadingScreen_obj::__CreateEmpty() { return new LoadingScreen_obj; }

void *LoadingScreen_obj::_hx_vtable = 0;

Dynamic LoadingScreen_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< LoadingScreen_obj > _hx_result = new LoadingScreen_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool LoadingScreen_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x68f183a5) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x68f183a5;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void LoadingScreen_obj::onAddedToStage( ::openfl::events::Event event){
            	HX_GC_STACKFRAME(&_hx_pos_39674d6a06d07a03_18_onAddedToStage)
HXLINE(  19)		this->removeEventListener(HX_("addedToStage",63,22,55,0c),this->onAddedToStage_dyn(),null());
HXLINE(  21)		this->addChild( ::ui::view::ScreenBase_obj::__alloc( HX_CTX ));
HXLINE(  22)		this->loadingText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,30,16777215,false,0,0,null());
HXLINE(  23)		this->loadingText->setBold(true);
HXLINE(  24)		this->loadingText->set_text(HX_("Loading...",12,7b,0c,0d));
HXLINE(  25)		this->loadingText->updateMetrics();
HXLINE(  26)		 ::ui::SimpleText _hx_tmp = this->loadingText;
HXDLIN(  26)		_hx_tmp->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,4,4,null(),null(),null(),null(),null())));
HXLINE(  27)		this->addChild(this->loadingText);
HXLINE(  29)		this->stage->addEventListener(HX_("resize",f4,59,7b,08),this->onResize_dyn(),null(),null(),null());
HXLINE(  30)		this->onResize(null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(LoadingScreen_obj,onAddedToStage,(void))

void LoadingScreen_obj::onResize( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_39674d6a06d07a03_42_onResize)
HXLINE(  43)		if (::hx::IsNull( this->loadingText )) {
HXLINE(  44)			return;
            		}
HXLINE(  46)		 ::ui::SimpleText _hx_tmp = this->loadingText;
HXDLIN(  46)		Float _hx_tmp1 = (( (Float)(::Main_obj::stageWidth) ) / ( (Float)(2) ));
HXDLIN(  46)		_hx_tmp->set_x((_hx_tmp1 - (this->loadingText->get_width() / ( (Float)(2) ))));
HXLINE(  47)		this->loadingText->set_y(( (Float)((::Main_obj::stageHeight - 74)) ));
            	}


HX_DEFINE_DYNAMIC_FUNC1(LoadingScreen_obj,onResize,(void))


::hx::ObjectPtr< LoadingScreen_obj > LoadingScreen_obj::__new() {
	::hx::ObjectPtr< LoadingScreen_obj > __this = new LoadingScreen_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< LoadingScreen_obj > LoadingScreen_obj::__alloc(::hx::Ctx *_hx_ctx) {
	LoadingScreen_obj *__this = (LoadingScreen_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(LoadingScreen_obj), true, "screens.LoadingScreen"));
	*(void **)__this = LoadingScreen_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

LoadingScreen_obj::LoadingScreen_obj()
{
}

void LoadingScreen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoadingScreen);
	HX_MARK_MEMBER_NAME(loadingText,"loadingText");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LoadingScreen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(loadingText,"loadingText");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val LoadingScreen_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"onResize") ) { return ::hx::Val( onResize_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"loadingText") ) { return ::hx::Val( loadingText ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onAddedToStage") ) { return ::hx::Val( onAddedToStage_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val LoadingScreen_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"loadingText") ) { loadingText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LoadingScreen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("loadingText",49,b5,f4,92));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo LoadingScreen_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(LoadingScreen_obj,loadingText),HX_("loadingText",49,b5,f4,92)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *LoadingScreen_obj_sStaticStorageInfo = 0;
#endif

static ::String LoadingScreen_obj_sMemberFields[] = {
	HX_("loadingText",49,b5,f4,92),
	HX_("onAddedToStage",22,82,44,36),
	HX_("onResize",73,50,28,e8),
	::String(null()) };

::hx::Class LoadingScreen_obj::__mClass;

void LoadingScreen_obj::__register()
{
	LoadingScreen_obj _hx_dummy;
	LoadingScreen_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("screens.LoadingScreen",c1,0f,85,0b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(LoadingScreen_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< LoadingScreen_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = LoadingScreen_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = LoadingScreen_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace screens