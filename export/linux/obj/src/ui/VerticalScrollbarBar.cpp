// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_openfl_display_Graphics
#include <openfl/display/Graphics.h>
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
#ifndef INCLUDED_openfl_events_MouseEvent
#include <openfl/events/MouseEvent.h>
#endif
#ifndef INCLUDED_ui_VerticalScrollbarBar
#include <ui/VerticalScrollbarBar.h>
#endif
#ifndef INCLUDED_util_BevelRect
#include <util/BevelRect.h>
#endif
#ifndef INCLUDED_util_GraphicsHelper
#include <util/GraphicsHelper.h>
#endif
#ifndef INCLUDED_util_Signal
#include <util/Signal.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_8e55ab003a954db9_10_new,"ui.VerticalScrollbarBar","new",0xb6346b0f,"ui.VerticalScrollbarBar.new","ui/VerticalScrollbarBar.hx",10,0xf43acb60)
HX_LOCAL_STACK_FRAME(_hx_pos_8e55ab003a954db9_22_redraw,"ui.VerticalScrollbarBar","redraw",0x733fe1e8,"ui.VerticalScrollbarBar.redraw","ui/VerticalScrollbarBar.hx",22,0xf43acb60)
HX_LOCAL_STACK_FRAME(_hx_pos_8e55ab003a954db9_30_addMouseListeners,"ui.VerticalScrollbarBar","addMouseListeners",0x433baf8a,"ui.VerticalScrollbarBar.addMouseListeners","ui/VerticalScrollbarBar.hx",30,0xf43acb60)
HX_LOCAL_STACK_FRAME(_hx_pos_8e55ab003a954db9_43_onMouseDown,"ui.VerticalScrollbarBar","onMouseDown",0x1316f5b7,"ui.VerticalScrollbarBar.onMouseDown","ui/VerticalScrollbarBar.hx",43,0xf43acb60)
HX_LOCAL_STACK_FRAME(_hx_pos_8e55ab003a954db9_51_onMouseUp,"ui.VerticalScrollbarBar","onMouseUp",0x4c99f470,"ui.VerticalScrollbarBar.onMouseUp","ui/VerticalScrollbarBar.hx",51,0xf43acb60)
HX_LOCAL_STACK_FRAME(_hx_pos_8e55ab003a954db9_58_onMouseOver,"ui.VerticalScrollbarBar","onMouseOver",0x1a618ea9,"ui.VerticalScrollbarBar.onMouseOver","ui/VerticalScrollbarBar.hx",58,0xf43acb60)
HX_LOCAL_STACK_FRAME(_hx_pos_8e55ab003a954db9_63_onMouseOut,"ui.VerticalScrollbarBar","onMouseOut",0xba1764d9,"ui.VerticalScrollbarBar.onMouseOut","ui/VerticalScrollbarBar.hx",63,0xf43acb60)
HX_LOCAL_STACK_FRAME(_hx_pos_8e55ab003a954db9_69_iterate,"ui.VerticalScrollbarBar","iterate",0x81259829,"ui.VerticalScrollbarBar.iterate","ui/VerticalScrollbarBar.hx",69,0xf43acb60)
namespace ui{

void VerticalScrollbarBar_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_8e55ab003a954db9_10_new)
HXLINE(  20)		this->isDown = false;
HXLINE(  19)		this->isOver = false;
HXLINE(  18)		this->downOffset = ((Float)0.0);
HXLINE(  16)		this->rect =  ::util::BevelRect_obj::__alloc( HX_CTX ,20,0,4);
HXLINE(  15)		this->dragging =  ::util::Signal_obj::__alloc( HX_CTX );
HXLINE(  10)		super::__construct();
            	}

Dynamic VerticalScrollbarBar_obj::__CreateEmpty() { return new VerticalScrollbarBar_obj; }

void *VerticalScrollbarBar_obj::_hx_vtable = 0;

Dynamic VerticalScrollbarBar_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< VerticalScrollbarBar_obj > _hx_result = new VerticalScrollbarBar_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool VerticalScrollbarBar_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0caec37b) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x0caec37b;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void VerticalScrollbarBar_obj::redraw(){
            	HX_STACKFRAME(&_hx_pos_8e55ab003a954db9_22_redraw)
HXLINE(  23)		int color;
HXDLIN(  23)		bool color1;
HXDLIN(  23)		if (!(this->isOver)) {
HXLINE(  23)			color1 = this->isDown;
            		}
            		else {
HXLINE(  23)			color1 = true;
            		}
HXDLIN(  23)		if (color1) {
HXLINE(  23)			color = 16767876;
            		}
            		else {
HXLINE(  23)			color = 13421772;
            		}
HXLINE(  24)		this->get_graphics()->clear();
HXLINE(  25)		this->get_graphics()->beginFill(color,null());
HXLINE(  26)		 ::util::BevelRect _hx_tmp = this->rect;
HXDLIN(  26)		::util::GraphicsHelper_obj::drawBevelRect(0,0,_hx_tmp,this->get_graphics());
HXLINE(  27)		this->get_graphics()->endFill();
            	}


HX_DEFINE_DYNAMIC_FUNC0(VerticalScrollbarBar_obj,redraw,(void))

void VerticalScrollbarBar_obj::addMouseListeners(){
            	HX_STACKFRAME(&_hx_pos_8e55ab003a954db9_30_addMouseListeners)
HXLINE(  31)		this->addEventListener(HX_("mouseDown",27,b1,c2,ee),this->onMouseDown_dyn(),null(),null(),null());
HXLINE(  32)		this->addEventListener(HX_("mouseOver",19,4a,0d,f6),this->onMouseOver_dyn(),null(),null(),null());
HXLINE(  33)		this->addEventListener(HX_("mouseOut",69,e7,1d,a4),this->onMouseOut_dyn(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(VerticalScrollbarBar_obj,addMouseListeners,(void))

void VerticalScrollbarBar_obj::onMouseDown( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_8e55ab003a954db9_43_onMouseDown)
HXLINE(  44)		this->isDown = true;
HXLINE(  45)		Float _hx_tmp = this->parent->get_mouseY();
HXDLIN(  45)		this->downOffset = (_hx_tmp - this->get_y());
HXLINE(  46)		this->stage->addEventListener(HX_("mouseUp",e0,f3,72,c0),this->onMouseUp_dyn(),null(),null(),null());
HXLINE(  47)		this->addEventListener(HX_("enterFrame",f5,03,50,02),this->iterate_dyn(),null(),null(),null());
HXLINE(  48)		this->redraw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(VerticalScrollbarBar_obj,onMouseDown,(void))

void VerticalScrollbarBar_obj::onMouseUp( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_8e55ab003a954db9_51_onMouseUp)
HXLINE(  52)		this->isDown = false;
HXLINE(  53)		this->stage->removeEventListener(HX_("mouseUp",e0,f3,72,c0),this->onMouseUp_dyn(),null());
HXLINE(  54)		this->removeEventListener(HX_("enterFrame",f5,03,50,02),this->iterate_dyn(),null());
HXLINE(  55)		this->redraw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(VerticalScrollbarBar_obj,onMouseUp,(void))

void VerticalScrollbarBar_obj::onMouseOver( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_8e55ab003a954db9_58_onMouseOver)
HXLINE(  59)		this->isOver = true;
HXLINE(  60)		this->redraw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(VerticalScrollbarBar_obj,onMouseOver,(void))

void VerticalScrollbarBar_obj::onMouseOut( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_8e55ab003a954db9_63_onMouseOut)
HXLINE(  64)		this->isOver = false;
HXLINE(  65)		this->redraw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(VerticalScrollbarBar_obj,onMouseOut,(void))

void VerticalScrollbarBar_obj::iterate( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_8e55ab003a954db9_69_iterate)
HXDLIN(  69)		 ::util::Signal _hx_tmp = this->dragging;
HXDLIN(  69)		Float _hx_tmp1 = this->parent->get_mouseY();
HXDLIN(  69)		_hx_tmp->emit(::Std_obj::_hx_int((_hx_tmp1 - this->downOffset)));
            	}


HX_DEFINE_DYNAMIC_FUNC1(VerticalScrollbarBar_obj,iterate,(void))


::hx::ObjectPtr< VerticalScrollbarBar_obj > VerticalScrollbarBar_obj::__new() {
	::hx::ObjectPtr< VerticalScrollbarBar_obj > __this = new VerticalScrollbarBar_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< VerticalScrollbarBar_obj > VerticalScrollbarBar_obj::__alloc(::hx::Ctx *_hx_ctx) {
	VerticalScrollbarBar_obj *__this = (VerticalScrollbarBar_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(VerticalScrollbarBar_obj), true, "ui.VerticalScrollbarBar"));
	*(void **)__this = VerticalScrollbarBar_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

VerticalScrollbarBar_obj::VerticalScrollbarBar_obj()
{
}

void VerticalScrollbarBar_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VerticalScrollbarBar);
	HX_MARK_MEMBER_NAME(dragging,"dragging");
	HX_MARK_MEMBER_NAME(rect,"rect");
	HX_MARK_MEMBER_NAME(downOffset,"downOffset");
	HX_MARK_MEMBER_NAME(isOver,"isOver");
	HX_MARK_MEMBER_NAME(isDown,"isDown");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void VerticalScrollbarBar_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(dragging,"dragging");
	HX_VISIT_MEMBER_NAME(rect,"rect");
	HX_VISIT_MEMBER_NAME(downOffset,"downOffset");
	HX_VISIT_MEMBER_NAME(isOver,"isOver");
	HX_VISIT_MEMBER_NAME(isDown,"isDown");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val VerticalScrollbarBar_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { return ::hx::Val( rect ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isOver") ) { return ::hx::Val( isOver ); }
		if (HX_FIELD_EQ(inName,"isDown") ) { return ::hx::Val( isDown ); }
		if (HX_FIELD_EQ(inName,"redraw") ) { return ::hx::Val( redraw_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"iterate") ) { return ::hx::Val( iterate_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"dragging") ) { return ::hx::Val( dragging ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return ::hx::Val( onMouseUp_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"downOffset") ) { return ::hx::Val( downOffset ); }
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return ::hx::Val( onMouseOut_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return ::hx::Val( onMouseDown_dyn() ); }
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return ::hx::Val( onMouseOver_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"addMouseListeners") ) { return ::hx::Val( addMouseListeners_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val VerticalScrollbarBar_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { rect=inValue.Cast<  ::util::BevelRect >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isOver") ) { isOver=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isDown") ) { isDown=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"dragging") ) { dragging=inValue.Cast<  ::util::Signal >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"downOffset") ) { downOffset=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VerticalScrollbarBar_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("dragging",cf,3c,8c,37));
	outFields->push(HX_("rect",24,4d,a7,4b));
	outFields->push(HX_("downOffset",95,79,43,9d));
	outFields->push(HX_("isOver",5e,56,1f,67));
	outFields->push(HX_("isDown",6c,bd,d4,5f));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo VerticalScrollbarBar_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::util::Signal */ ,(int)offsetof(VerticalScrollbarBar_obj,dragging),HX_("dragging",cf,3c,8c,37)},
	{::hx::fsObject /*  ::util::BevelRect */ ,(int)offsetof(VerticalScrollbarBar_obj,rect),HX_("rect",24,4d,a7,4b)},
	{::hx::fsFloat,(int)offsetof(VerticalScrollbarBar_obj,downOffset),HX_("downOffset",95,79,43,9d)},
	{::hx::fsBool,(int)offsetof(VerticalScrollbarBar_obj,isOver),HX_("isOver",5e,56,1f,67)},
	{::hx::fsBool,(int)offsetof(VerticalScrollbarBar_obj,isDown),HX_("isDown",6c,bd,d4,5f)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *VerticalScrollbarBar_obj_sStaticStorageInfo = 0;
#endif

static ::String VerticalScrollbarBar_obj_sMemberFields[] = {
	HX_("dragging",cf,3c,8c,37),
	HX_("rect",24,4d,a7,4b),
	HX_("downOffset",95,79,43,9d),
	HX_("isOver",5e,56,1f,67),
	HX_("isDown",6c,bd,d4,5f),
	HX_("redraw",37,e5,97,fe),
	HX_("addMouseListeners",9b,60,3f,cf),
	HX_("onMouseDown",08,94,05,11),
	HX_("onMouseUp",81,ac,1d,98),
	HX_("onMouseOver",fa,2c,50,18),
	HX_("onMouseOut",a8,bb,d4,81),
	HX_("iterate",fa,79,d0,e2),
	::String(null()) };

::hx::Class VerticalScrollbarBar_obj::__mClass;

void VerticalScrollbarBar_obj::__register()
{
	VerticalScrollbarBar_obj _hx_dummy;
	VerticalScrollbarBar_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.VerticalScrollbarBar",9d,37,a8,33);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(VerticalScrollbarBar_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< VerticalScrollbarBar_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = VerticalScrollbarBar_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = VerticalScrollbarBar_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui