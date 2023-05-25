// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
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
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_ui_options_ChoiceBox
#include <ui/options/ChoiceBox.h>
#endif
#ifndef INCLUDED_ui_options_ChoiceOption
#include <ui/options/ChoiceOption.h>
#endif
#ifndef INCLUDED_ui_options_Option
#include <ui/options/Option.h>
#endif
#ifndef INCLUDED_util_Settings
#include <util/Settings.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0eeb7a2c9c0ca055_10_new,"ui.options.ChoiceOption","new",0x82339632,"ui.options.ChoiceOption.new","ui/options/ChoiceOption.hx",10,0x0efcbebc)
HX_LOCAL_STACK_FRAME(_hx_pos_0eeb7a2c9c0ca055_19_refresh,"ui.options.ChoiceOption","refresh",0x24ecf0ad,"ui.options.ChoiceOption.refresh","ui/options/ChoiceOption.hx",19,0x0efcbebc)
HX_LOCAL_STACK_FRAME(_hx_pos_0eeb7a2c9c0ca055_22_onChange,"ui.options.ChoiceOption","onChange",0x31e768dd,"ui.options.ChoiceOption.onChange","ui/options/ChoiceOption.hx",22,0x0efcbebc)
namespace ui{
namespace options{

void ChoiceOption_obj::__construct(::String paramName,::Array< ::String > labels,::cpp::VirtualArray values,::String desc,::String tooltipText, ::Dynamic callback){
            	HX_GC_STACKFRAME(&_hx_pos_0eeb7a2c9c0ca055_10_new)
HXLINE(  11)		super::__construct(paramName,desc,tooltipText);
HXLINE(  12)		this->callback = callback;
HXLINE(  13)		this->choiceBox =  ::ui::options::ChoiceBox_obj::__alloc( HX_CTX ,labels,values,( (::String)(::Reflect_obj::getProperty(::hx::ClassOf< ::util::Settings >(),paramName)) ));
HXLINE(  14)		this->choiceBox->addEventListener(HX_("change",70,91,72,b7),this->onChange_dyn(),null(),null(),null());
HXLINE(  15)		this->addChild(this->choiceBox);
            	}

Dynamic ChoiceOption_obj::__CreateEmpty() { return new ChoiceOption_obj; }

void *ChoiceOption_obj::_hx_vtable = 0;

Dynamic ChoiceOption_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ChoiceOption_obj > _hx_result = new ChoiceOption_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return _hx_result;
}

bool ChoiceOption_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x4af7dd8e) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		}
	} else {
		if (inClassId<=(int)0x6b353933) {
			return inClassId==(int)0x594ff93c || inClassId==(int)0x6b353933;
		} else {
			return inClassId==(int)0x75a8715f;
		}
	}
}

void ChoiceOption_obj::refresh(){
            	HX_STACKFRAME(&_hx_pos_0eeb7a2c9c0ca055_19_refresh)
HXDLIN(  19)		 ::ui::options::ChoiceBox _hx_tmp = this->choiceBox;
HXDLIN(  19)		_hx_tmp->setValue(( (::String)(::Reflect_obj::getProperty(::hx::ClassOf< ::util::Settings >(),this->paramName)) ));
            	}


void ChoiceOption_obj::onChange( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_0eeb7a2c9c0ca055_22_onChange)
HXLINE(  23)		::String _hx_tmp = this->paramName;
HXDLIN(  23)		::Reflect_obj::setProperty(::hx::ClassOf< ::util::Settings >(),_hx_tmp,this->choiceBox->value());
HXLINE(  24)		::util::Settings_obj::save();
HXLINE(  25)		if (::hx::IsNotNull( this->callback )) {
HXLINE(  26)			this->callback();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ChoiceOption_obj,onChange,(void))


::hx::ObjectPtr< ChoiceOption_obj > ChoiceOption_obj::__new(::String paramName,::Array< ::String > labels,::cpp::VirtualArray values,::String desc,::String tooltipText, ::Dynamic callback) {
	::hx::ObjectPtr< ChoiceOption_obj > __this = new ChoiceOption_obj();
	__this->__construct(paramName,labels,values,desc,tooltipText,callback);
	return __this;
}

::hx::ObjectPtr< ChoiceOption_obj > ChoiceOption_obj::__alloc(::hx::Ctx *_hx_ctx,::String paramName,::Array< ::String > labels,::cpp::VirtualArray values,::String desc,::String tooltipText, ::Dynamic callback) {
	ChoiceOption_obj *__this = (ChoiceOption_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ChoiceOption_obj), true, "ui.options.ChoiceOption"));
	*(void **)__this = ChoiceOption_obj::_hx_vtable;
	__this->__construct(paramName,labels,values,desc,tooltipText,callback);
	return __this;
}

ChoiceOption_obj::ChoiceOption_obj()
{
}

void ChoiceOption_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ChoiceOption);
	HX_MARK_MEMBER_NAME(callback,"callback");
	HX_MARK_MEMBER_NAME(choiceBox,"choiceBox");
	 ::ui::options::Option_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ChoiceOption_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(callback,"callback");
	HX_VISIT_MEMBER_NAME(choiceBox,"choiceBox");
	 ::ui::options::Option_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val ChoiceOption_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"refresh") ) { return ::hx::Val( refresh_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"callback") ) { return ::hx::Val( callback ); }
		if (HX_FIELD_EQ(inName,"onChange") ) { return ::hx::Val( onChange_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"choiceBox") ) { return ::hx::Val( choiceBox ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ChoiceOption_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"callback") ) { callback=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"choiceBox") ) { choiceBox=inValue.Cast<  ::ui::options::ChoiceBox >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ChoiceOption_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("choiceBox",2a,c9,c1,16));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ChoiceOption_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(ChoiceOption_obj,callback),HX_("callback",c5,99,06,7f)},
	{::hx::fsObject /*  ::ui::options::ChoiceBox */ ,(int)offsetof(ChoiceOption_obj,choiceBox),HX_("choiceBox",2a,c9,c1,16)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ChoiceOption_obj_sStaticStorageInfo = 0;
#endif

static ::String ChoiceOption_obj_sMemberFields[] = {
	HX_("callback",c5,99,06,7f),
	HX_("choiceBox",2a,c9,c1,16),
	HX_("refresh",db,d9,20,ed),
	HX_("onChange",ef,87,1f,97),
	::String(null()) };

::hx::Class ChoiceOption_obj::__mClass;

void ChoiceOption_obj::__register()
{
	ChoiceOption_obj _hx_dummy;
	ChoiceOption_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.options.ChoiceOption",40,55,84,e8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ChoiceOption_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ChoiceOption_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ChoiceOption_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ChoiceOption_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace options