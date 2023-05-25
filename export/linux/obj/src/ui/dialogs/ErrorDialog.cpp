// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_core_Layers
#include <core/Layers.h>
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
#ifndef INCLUDED_openfl_events_MouseEvent
#include <openfl/events/MouseEvent.h>
#endif
#ifndef INCLUDED_screens_CharacterSelectionScreen
#include <screens/CharacterSelectionScreen.h>
#endif
#ifndef INCLUDED_ui_dialogs_Dialog
#include <ui/dialogs/Dialog.h>
#endif
#ifndef INCLUDED_ui_dialogs_DialogsView
#include <ui/dialogs/DialogsView.h>
#endif
#ifndef INCLUDED_ui_dialogs_ErrorDialog
#include <ui/dialogs/ErrorDialog.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_db5e7473d0b42cee_8_new,"ui.dialogs.ErrorDialog","new",0x8896e7a5,"ui.dialogs.ErrorDialog.new","ui/dialogs/ErrorDialog.hx",8,0xb55cfbed)
HX_LOCAL_STACK_FRAME(_hx_pos_db5e7473d0b42cee_14_onAdded,"ui.dialogs.ErrorDialog","onAdded",0x0a4210e6,"ui.dialogs.ErrorDialog.onAdded","ui/dialogs/ErrorDialog.hx",14,0xb55cfbed)
HX_LOCAL_STACK_FRAME(_hx_pos_db5e7473d0b42cee_20_onRemoved,"ui.dialogs.ErrorDialog","onRemoved",0x0a223146,"ui.dialogs.ErrorDialog.onRemoved","ui/dialogs/ErrorDialog.hx",20,0xb55cfbed)
HX_LOCAL_STACK_FRAME(_hx_pos_db5e7473d0b42cee_27_onClose,"ui.dialogs.ErrorDialog","onClose",0x366153de,"ui.dialogs.ErrorDialog.onClose","ui/dialogs/ErrorDialog.hx",27,0xb55cfbed)
HX_LOCAL_STACK_FRAME(_hx_pos_db5e7473d0b42cee_30_onComplete,"ui.dialogs.ErrorDialog","onComplete",0xa6756053,"ui.dialogs.ErrorDialog.onComplete","ui/dialogs/ErrorDialog.hx",30,0xb55cfbed)
namespace ui{
namespace dialogs{

void ErrorDialog_obj::__construct(::String errorText){
            	HX_STACKFRAME(&_hx_pos_db5e7473d0b42cee_8_new)
HXLINE(   9)		super::__construct((HX_("An error has occurred:\n",06,60,a4,c4) + errorText),HX_("Error",a8,3b,57,06),HX_("Ok",3c,45,00,00),null());
HXLINE(  10)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null(),null(),null());
HXLINE(  11)		this->addEventListener(HX_("DIALOG_BUTTON1",48,38,81,e9),this->onClose_dyn(),null(),null(),null());
            	}

Dynamic ErrorDialog_obj::__CreateEmpty() { return new ErrorDialog_obj; }

void *ErrorDialog_obj::_hx_vtable = 0;

Dynamic ErrorDialog_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ErrorDialog_obj > _hx_result = new ErrorDialog_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool ErrorDialog_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x46543c1b) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x46543c1b;
		}
	} else {
		if (inClassId<=(int)0x6b353933) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x6b353933;
		} else {
			return inClassId==(int)0x785cb919;
		}
	}
}

void ErrorDialog_obj::onAdded( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_db5e7473d0b42cee_14_onAdded)
HXLINE(  15)		this->removeEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null());
HXLINE(  16)		this->addEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null(),null(),null());
HXLINE(  17)		this->addEventListener(HX_("complete",b9,00,c8,7f),::ui::dialogs::ErrorDialog_obj::onComplete_dyn(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(ErrorDialog_obj,onAdded,(void))

void ErrorDialog_obj::onRemoved( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_db5e7473d0b42cee_20_onRemoved)
HXLINE(  21)		this->removeEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null());
HXLINE(  22)		this->removeEventListener(HX_("complete",b9,00,c8,7f),::ui::dialogs::ErrorDialog_obj::onComplete_dyn(),null());
HXLINE(  23)		this->removeEventListener(HX_("DIALOG_BUTTON1",48,38,81,e9),this->onClose_dyn(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(ErrorDialog_obj,onRemoved,(void))

void ErrorDialog_obj::onClose( ::openfl::events::MouseEvent _){
            	HX_STACKFRAME(&_hx_pos_db5e7473d0b42cee_27_onClose)
HXDLIN(  27)		::Global_obj::layers->dialogs->closeDialogs();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ErrorDialog_obj,onClose,(void))

void ErrorDialog_obj::onComplete( ::openfl::events::Event event){
            	HX_GC_STACKFRAME(&_hx_pos_db5e7473d0b42cee_30_onComplete)
HXLINE(  31)		::Global_obj::invalidate();
HXLINE(  32)		::Global_obj::setScreenValid( ::screens::CharacterSelectionScreen_obj::__alloc( HX_CTX ));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ErrorDialog_obj,onComplete,(void))


::hx::ObjectPtr< ErrorDialog_obj > ErrorDialog_obj::__new(::String errorText) {
	::hx::ObjectPtr< ErrorDialog_obj > __this = new ErrorDialog_obj();
	__this->__construct(errorText);
	return __this;
}

::hx::ObjectPtr< ErrorDialog_obj > ErrorDialog_obj::__alloc(::hx::Ctx *_hx_ctx,::String errorText) {
	ErrorDialog_obj *__this = (ErrorDialog_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ErrorDialog_obj), true, "ui.dialogs.ErrorDialog"));
	*(void **)__this = ErrorDialog_obj::_hx_vtable;
	__this->__construct(errorText);
	return __this;
}

ErrorDialog_obj::ErrorDialog_obj()
{
}

::hx::Val ErrorDialog_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onAdded") ) { return ::hx::Val( onAdded_dyn() ); }
		if (HX_FIELD_EQ(inName,"onClose") ) { return ::hx::Val( onClose_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onRemoved") ) { return ::hx::Val( onRemoved_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool ErrorDialog_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { outValue = onComplete_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *ErrorDialog_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *ErrorDialog_obj_sStaticStorageInfo = 0;
#endif

static ::String ErrorDialog_obj_sMemberFields[] = {
	HX_("onAdded",21,73,81,b2),
	HX_("onRemoved",41,d8,aa,ca),
	HX_("onClose",19,b6,a0,de),
	::String(null()) };

::hx::Class ErrorDialog_obj::__mClass;

static ::String ErrorDialog_obj_sStaticFields[] = {
	HX_("onComplete",f8,d4,7e,5d),
	::String(null())
};

void ErrorDialog_obj::__register()
{
	ErrorDialog_obj _hx_dummy;
	ErrorDialog_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.dialogs.ErrorDialog",33,31,7f,be);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &ErrorDialog_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(ErrorDialog_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ErrorDialog_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ErrorDialog_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ErrorDialog_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ErrorDialog_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace dialogs