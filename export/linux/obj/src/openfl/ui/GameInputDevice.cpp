// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_ui_GameInputControl
#include <openfl/ui/GameInputControl.h>
#endif
#ifndef INCLUDED_openfl_ui_GameInputDevice
#include <openfl/ui/GameInputDevice.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_fafdee3291969395_14_new,"openfl.ui.GameInputDevice","new",0x66440344,"openfl.ui.GameInputDevice.new","openfl/ui/GameInputDevice.hx",14,0x744a6f4c)
namespace openfl{
namespace ui{

void GameInputDevice_obj::__construct(::String id,::String name){
            	HX_GC_STACKFRAME(&_hx_pos_fafdee3291969395_14_new)
HXLINE(  50)		this->_hx___controls = ::Array_obj< ::Dynamic>::__new();
HXLINE(  49)		this->_hx___button =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
HXLINE(  48)		this->_hx___axis =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
HXLINE(  66)		this->id = id;
HXLINE(  67)		this->name = name;
HXLINE(  69)		 ::openfl::ui::GameInputControl control;
HXLINE(  71)		{
HXLINE(  72)			{
HXLINE(  73)				control =  ::openfl::ui::GameInputControl_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),(HX_("AXIS_",9e,28,6e,a7) + 0),( (Float)(-1) ),( (Float)(1) ),null());
HXLINE(  74)				this->_hx___axis->set(0,control);
HXLINE(  75)				this->_hx___controls->push(control);
            			}
HXLINE(  72)			{
HXLINE(  73)				control =  ::openfl::ui::GameInputControl_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),(HX_("AXIS_",9e,28,6e,a7) + 1),( (Float)(-1) ),( (Float)(1) ),null());
HXLINE(  74)				this->_hx___axis->set(1,control);
HXLINE(  75)				this->_hx___controls->push(control);
            			}
HXLINE(  72)			{
HXLINE(  73)				control =  ::openfl::ui::GameInputControl_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),(HX_("AXIS_",9e,28,6e,a7) + 2),( (Float)(-1) ),( (Float)(1) ),null());
HXLINE(  74)				this->_hx___axis->set(2,control);
HXLINE(  75)				this->_hx___controls->push(control);
            			}
HXLINE(  72)			{
HXLINE(  73)				control =  ::openfl::ui::GameInputControl_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),(HX_("AXIS_",9e,28,6e,a7) + 3),( (Float)(-1) ),( (Float)(1) ),null());
HXLINE(  74)				this->_hx___axis->set(3,control);
HXLINE(  75)				this->_hx___controls->push(control);
            			}
HXLINE(  72)			{
HXLINE(  73)				control =  ::openfl::ui::GameInputControl_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),(HX_("AXIS_",9e,28,6e,a7) + 4),( (Float)(-1) ),( (Float)(1) ),null());
HXLINE(  74)				this->_hx___axis->set(4,control);
HXLINE(  75)				this->_hx___controls->push(control);
            			}
HXLINE(  72)			{
HXLINE(  73)				control =  ::openfl::ui::GameInputControl_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),(HX_("AXIS_",9e,28,6e,a7) + 5),( (Float)(-1) ),( (Float)(1) ),null());
HXLINE(  74)				this->_hx___axis->set(5,control);
HXLINE(  75)				this->_hx___controls->push(control);
            			}
            		}
HXLINE(  78)		{
HXLINE(  78)			int _g = 0;
HXDLIN(  78)			while((_g < 15)){
HXLINE(  78)				_g = (_g + 1);
HXDLIN(  78)				int i = (_g - 1);
HXLINE(  80)				control =  ::openfl::ui::GameInputControl_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),(HX_("BUTTON_",2d,26,49,4a) + i),( (Float)(0) ),( (Float)(1) ),null());
HXLINE(  81)				this->_hx___button->set(i,control);
HXLINE(  82)				this->_hx___controls->push(control);
            			}
            		}
            	}

Dynamic GameInputDevice_obj::__CreateEmpty() { return new GameInputDevice_obj; }

void *GameInputDevice_obj::_hx_vtable = 0;

Dynamic GameInputDevice_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GameInputDevice_obj > _hx_result = new GameInputDevice_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool GameInputDevice_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1bd2e2aa;
}


::hx::ObjectPtr< GameInputDevice_obj > GameInputDevice_obj::__new(::String id,::String name) {
	::hx::ObjectPtr< GameInputDevice_obj > __this = new GameInputDevice_obj();
	__this->__construct(id,name);
	return __this;
}

::hx::ObjectPtr< GameInputDevice_obj > GameInputDevice_obj::__alloc(::hx::Ctx *_hx_ctx,::String id,::String name) {
	GameInputDevice_obj *__this = (GameInputDevice_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GameInputDevice_obj), true, "openfl.ui.GameInputDevice"));
	*(void **)__this = GameInputDevice_obj::_hx_vtable;
	__this->__construct(id,name);
	return __this;
}

GameInputDevice_obj::GameInputDevice_obj()
{
}

void GameInputDevice_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameInputDevice);
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(_hx___axis,"__axis");
	HX_MARK_MEMBER_NAME(_hx___button,"__button");
	HX_MARK_MEMBER_NAME(_hx___controls,"__controls");
	HX_MARK_END_CLASS();
}

void GameInputDevice_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(enabled,"enabled");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(_hx___axis,"__axis");
	HX_VISIT_MEMBER_NAME(_hx___button,"__button");
	HX_VISIT_MEMBER_NAME(_hx___controls,"__controls");
}

::hx::Val GameInputDevice_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return ::hx::Val( id ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return ::hx::Val( name ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"__axis") ) { return ::hx::Val( _hx___axis ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return ::hx::Val( enabled ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__button") ) { return ::hx::Val( _hx___button ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__controls") ) { return ::hx::Val( _hx___controls ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val GameInputDevice_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"__axis") ) { _hx___axis=inValue.Cast<  ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__button") ) { _hx___button=inValue.Cast<  ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__controls") ) { _hx___controls=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameInputDevice_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("enabled",81,04,31,7e));
	outFields->push(HX_("id",db,5b,00,00));
	outFields->push(HX_("name",4b,72,ff,48));
	outFields->push(HX_("__axis",c1,7f,71,ef));
	outFields->push(HX_("__button",12,cd,0f,82));
	outFields->push(HX_("__controls",96,f9,f4,da));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo GameInputDevice_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(GameInputDevice_obj,enabled),HX_("enabled",81,04,31,7e)},
	{::hx::fsString,(int)offsetof(GameInputDevice_obj,id),HX_("id",db,5b,00,00)},
	{::hx::fsString,(int)offsetof(GameInputDevice_obj,name),HX_("name",4b,72,ff,48)},
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(int)offsetof(GameInputDevice_obj,_hx___axis),HX_("__axis",c1,7f,71,ef)},
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(int)offsetof(GameInputDevice_obj,_hx___button),HX_("__button",12,cd,0f,82)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(GameInputDevice_obj,_hx___controls),HX_("__controls",96,f9,f4,da)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *GameInputDevice_obj_sStaticStorageInfo = 0;
#endif

static ::String GameInputDevice_obj_sMemberFields[] = {
	HX_("enabled",81,04,31,7e),
	HX_("id",db,5b,00,00),
	HX_("name",4b,72,ff,48),
	HX_("__axis",c1,7f,71,ef),
	HX_("__button",12,cd,0f,82),
	HX_("__controls",96,f9,f4,da),
	::String(null()) };

::hx::Class GameInputDevice_obj::__mClass;

void GameInputDevice_obj::__register()
{
	GameInputDevice_obj _hx_dummy;
	GameInputDevice_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.ui.GameInputDevice",52,51,b0,03);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(GameInputDevice_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< GameInputDevice_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GameInputDevice_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GameInputDevice_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace ui