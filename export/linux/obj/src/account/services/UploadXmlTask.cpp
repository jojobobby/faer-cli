// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_account_Account
#include <account/Account.h>
#endif
#ifndef INCLUDED_account_services_UploadXmlTask
#include <account/services/UploadXmlTask.h>
#endif
#ifndef INCLUDED_appengine_CompletionData
#include <appengine/CompletionData.h>
#endif
#ifndef INCLUDED_appengine_RequestHandler
#include <appengine/RequestHandler.h>
#endif
#ifndef INCLUDED_core_Layers
#include <core/Layers.h>
#endif
#ifndef INCLUDED_haxe_http_HttpBase
#include <haxe/http/HttpBase.h>
#endif
#ifndef INCLUDED_lib_tasks_Task
#include <lib/tasks/Task.h>
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
#ifndef INCLUDED_sys_Http
#include <sys/Http.h>
#endif
#ifndef INCLUDED_ui_dialogs_Dialog
#include <ui/dialogs/Dialog.h>
#endif
#ifndef INCLUDED_ui_dialogs_DialogsView
#include <ui/dialogs/DialogsView.h>
#endif
#ifndef INCLUDED_util_Signal
#include <util/Signal.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_1c1db4a5b509211e_11_new,"account.services.UploadXmlTask","new",0x4490e95e,"account.services.UploadXmlTask.new","account/services/UploadXmlTask.hx",11,0x196223b2)
HX_LOCAL_STACK_FRAME(_hx_pos_1c1db4a5b509211e_15_startTask,"account.services.UploadXmlTask","startTask",0xdb552445,"account.services.UploadXmlTask.startTask","account/services/UploadXmlTask.hx",15,0x196223b2)
HX_LOCAL_STACK_FRAME(_hx_pos_1c1db4a5b509211e_24_onComplete,"account.services.UploadXmlTask","onComplete",0x45a1f7ba,"account.services.UploadXmlTask.onComplete","account/services/UploadXmlTask.hx",24,0x196223b2)
HX_LOCAL_STACK_FRAME(_hx_pos_1c1db4a5b509211e_28_onComplete,"account.services.UploadXmlTask","onComplete",0x45a1f7ba,"account.services.UploadXmlTask.onComplete","account/services/UploadXmlTask.hx",28,0x196223b2)
HX_LOCAL_STACK_FRAME(_hx_pos_1c1db4a5b509211e_34_onComplete,"account.services.UploadXmlTask","onComplete",0x45a1f7ba,"account.services.UploadXmlTask.onComplete","account/services/UploadXmlTask.hx",34,0x196223b2)
namespace account{
namespace services{

void UploadXmlTask_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_1c1db4a5b509211e_11_new)
HXDLIN(  11)		super::__construct();
            	}

Dynamic UploadXmlTask_obj::__CreateEmpty() { return new UploadXmlTask_obj; }

void *UploadXmlTask_obj::_hx_vtable = 0;

Dynamic UploadXmlTask_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< UploadXmlTask_obj > _hx_result = new UploadXmlTask_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool UploadXmlTask_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x14f9ba14) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x14f9ba14;
	} else {
		return inClassId==(int)0x7e99215e;
	}
}

void UploadXmlTask_obj::startTask(){
            	HX_STACKFRAME(&_hx_pos_1c1db4a5b509211e_15_startTask)
HXLINE(  16)		::appengine::RequestHandler_obj::http->setParameter(HX_("email",1c,cf,ce,6f),::account::Account_obj::email);
HXLINE(  17)		::appengine::RequestHandler_obj::http->setParameter(HX_("password",1b,23,d0,48),::account::Account_obj::password);
HXLINE(  18)		::appengine::RequestHandler_obj::http->setParameter(HX_("data",2a,56,63,42),::account::services::UploadXmlTask_obj::data);
HXLINE(  19)		::appengine::RequestHandler_obj::http->setParameter(HX_("name",4b,72,ff,48),::account::services::UploadXmlTask_obj::name);
HXLINE(  20)		::appengine::RequestHandler_obj::complete->once(this->onComplete_dyn());
HXLINE(  21)		::appengine::RequestHandler_obj::sendRequest(HX_("/app/uploadXml",99,92,c9,15));
            	}


void UploadXmlTask_obj::onComplete( ::appengine::CompletionData compData){
            	HX_GC_STACKFRAME(&_hx_pos_1c1db4a5b509211e_24_onComplete)
HXLINE(  25)		bool _hx_tmp;
HXDLIN(  25)		if ((compData->result.indexOf(HX_("<Error>",d2,cc,04,45),null()) == -1)) {
HXLINE(  25)			_hx_tmp = compData->success;
            		}
            		else {
HXLINE(  25)			_hx_tmp = false;
            		}
HXDLIN(  25)		if (_hx_tmp) {
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(1)
            			void _hx_run( ::openfl::events::Event _){
            				HX_GC_STACKFRAME(&_hx_pos_1c1db4a5b509211e_28_onComplete)
HXLINE(  28)				::Global_obj::layers->dialogs->closeDialogs();
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE(  26)			 ::ui::dialogs::Dialog dialog =  ::ui::dialogs::Dialog_obj::__alloc( HX_CTX ,((HX_("Successfully uploaded ",a7,c9,7f,de) + ::account::services::UploadXmlTask_obj::name) + HX_(" to the server",f7,5c,4f,94)),HX_("Success",a3,4d,9f,85),HX_("Close",98,87,90,db),null());
HXLINE(  27)			dialog->addEventListener(HX_("DIALOG_BUTTON1",48,38,81,e9), ::Dynamic(new _hx_Closure_0()),null(),null(),null());
HXLINE(  30)			::Global_obj::layers->dialogs->openDialog(dialog);
            		}
            		else {
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_1) HXARGC(1)
            			void _hx_run( ::openfl::events::Event _){
            				HX_GC_STACKFRAME(&_hx_pos_1c1db4a5b509211e_34_onComplete)
HXLINE(  34)				::Global_obj::layers->dialogs->closeDialogs();
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE(  32)			 ::ui::dialogs::Dialog dialog1 =  ::ui::dialogs::Dialog_obj::__alloc( HX_CTX ,(((HX_("Failed to upload ",bd,84,b4,d4) + ::account::services::UploadXmlTask_obj::name) + HX_(" to the server: ",5d,fb,99,cc)) + compData->result),HX_("Error",a8,3b,57,06),HX_("Close",98,87,90,db),null());
HXLINE(  33)			dialog1->addEventListener(HX_("DIALOG_BUTTON1",48,38,81,e9), ::Dynamic(new _hx_Closure_1()),null(),null(),null());
HXLINE(  36)			::Global_obj::layers->dialogs->openDialog(dialog1);
            		}
HXLINE(  39)		this->completeTask(compData->success,compData->result);
            	}


HX_DEFINE_DYNAMIC_FUNC1(UploadXmlTask_obj,onComplete,(void))

::String UploadXmlTask_obj::data;

::String UploadXmlTask_obj::name;


::hx::ObjectPtr< UploadXmlTask_obj > UploadXmlTask_obj::__new() {
	::hx::ObjectPtr< UploadXmlTask_obj > __this = new UploadXmlTask_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< UploadXmlTask_obj > UploadXmlTask_obj::__alloc(::hx::Ctx *_hx_ctx) {
	UploadXmlTask_obj *__this = (UploadXmlTask_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(UploadXmlTask_obj), true, "account.services.UploadXmlTask"));
	*(void **)__this = UploadXmlTask_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

UploadXmlTask_obj::UploadXmlTask_obj()
{
}

::hx::Val UploadXmlTask_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"startTask") ) { return ::hx::Val( startTask_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return ::hx::Val( onComplete_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool UploadXmlTask_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { outValue = ( data ); return true; }
		if (HX_FIELD_EQ(inName,"name") ) { outValue = ( name ); return true; }
	}
	return false;
}

bool UploadXmlTask_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"name") ) { name=ioValue.Cast< ::String >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *UploadXmlTask_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo UploadXmlTask_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &UploadXmlTask_obj::data,HX_("data",2a,56,63,42)},
	{::hx::fsString,(void *) &UploadXmlTask_obj::name,HX_("name",4b,72,ff,48)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String UploadXmlTask_obj_sMemberFields[] = {
	HX_("startTask",c7,38,ea,05),
	HX_("onComplete",f8,d4,7e,5d),
	::String(null()) };

static void UploadXmlTask_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UploadXmlTask_obj::data,"data");
	HX_MARK_MEMBER_NAME(UploadXmlTask_obj::name,"name");
};

#ifdef HXCPP_VISIT_ALLOCS
static void UploadXmlTask_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UploadXmlTask_obj::data,"data");
	HX_VISIT_MEMBER_NAME(UploadXmlTask_obj::name,"name");
};

#endif

::hx::Class UploadXmlTask_obj::__mClass;

static ::String UploadXmlTask_obj_sStaticFields[] = {
	HX_("data",2a,56,63,42),
	HX_("name",4b,72,ff,48),
	::String(null())
};

void UploadXmlTask_obj::__register()
{
	UploadXmlTask_obj _hx_dummy;
	UploadXmlTask_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("account.services.UploadXmlTask",6c,a2,15,de);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &UploadXmlTask_obj::__GetStatic;
	__mClass->mSetStaticField = &UploadXmlTask_obj::__SetStatic;
	__mClass->mMarkFunc = UploadXmlTask_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(UploadXmlTask_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(UploadXmlTask_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< UploadXmlTask_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = UploadXmlTask_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = UploadXmlTask_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = UploadXmlTask_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace account
} // end namespace services
