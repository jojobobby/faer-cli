// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_account_Account
#include <account/Account.h>
#endif
#ifndef INCLUDED_account_services_BuyCharacterSlotTask
#include <account/services/BuyCharacterSlotTask.h>
#endif
#ifndef INCLUDED_appengine_CompletionData
#include <appengine/CompletionData.h>
#endif
#ifndef INCLUDED_appengine_RequestHandler
#include <appengine/RequestHandler.h>
#endif
#ifndef INCLUDED_haxe_http_HttpBase
#include <haxe/http/HttpBase.h>
#endif
#ifndef INCLUDED_lib_tasks_Task
#include <lib/tasks/Task.h>
#endif
#ifndef INCLUDED_sys_Http
#include <sys/Http.h>
#endif
#ifndef INCLUDED_util_Signal
#include <util/Signal.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_790db8098b86d1af_8_new,"account.services.BuyCharacterSlotTask","new",0xa8987ce7,"account.services.BuyCharacterSlotTask.new","account/services/BuyCharacterSlotTask.hx",8,0x39156089)
HX_LOCAL_STACK_FRAME(_hx_pos_790db8098b86d1af_9_startTask,"account.services.BuyCharacterSlotTask","startTask",0x92c9848e,"account.services.BuyCharacterSlotTask.startTask","account/services/BuyCharacterSlotTask.hx",9,0x39156089)
HX_LOCAL_STACK_FRAME(_hx_pos_790db8098b86d1af_19_onComplete,"account.services.BuyCharacterSlotTask","onComplete",0x1401d751,"account.services.BuyCharacterSlotTask.onComplete","account/services/BuyCharacterSlotTask.hx",19,0x39156089)
namespace account{
namespace services{

void BuyCharacterSlotTask_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_790db8098b86d1af_8_new)
HXDLIN(   8)		super::__construct();
            	}

Dynamic BuyCharacterSlotTask_obj::__CreateEmpty() { return new BuyCharacterSlotTask_obj; }

void *BuyCharacterSlotTask_obj::_hx_vtable = 0;

Dynamic BuyCharacterSlotTask_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BuyCharacterSlotTask_obj > _hx_result = new BuyCharacterSlotTask_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool BuyCharacterSlotTask_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x38702acd) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x38702acd;
	} else {
		return inClassId==(int)0x7e99215e;
	}
}

void BuyCharacterSlotTask_obj::startTask(){
            	HX_STACKFRAME(&_hx_pos_790db8098b86d1af_9_startTask)
HXLINE(  10)		::appengine::RequestHandler_obj::http->setParameter(HX_("email",1c,cf,ce,6f),::account::Account_obj::email);
HXLINE(  11)		::appengine::RequestHandler_obj::http->setParameter(HX_("password",1b,23,d0,48),::account::Account_obj::password);
HXLINE(  12)		::appengine::RequestHandler_obj::complete->once(this->onComplete_dyn());
HXLINE(  13)		::appengine::RequestHandler_obj::sendRequest(HX_("/account/purchaseCharSlot",e6,b8,20,56));
            	}


void BuyCharacterSlotTask_obj::onComplete( ::appengine::CompletionData compData){
            	HX_STACKFRAME(&_hx_pos_790db8098b86d1af_19_onComplete)
HXDLIN(  19)		this->completeTask(compData->success,compData->result);
            	}


HX_DEFINE_DYNAMIC_FUNC1(BuyCharacterSlotTask_obj,onComplete,(void))


::hx::ObjectPtr< BuyCharacterSlotTask_obj > BuyCharacterSlotTask_obj::__new() {
	::hx::ObjectPtr< BuyCharacterSlotTask_obj > __this = new BuyCharacterSlotTask_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< BuyCharacterSlotTask_obj > BuyCharacterSlotTask_obj::__alloc(::hx::Ctx *_hx_ctx) {
	BuyCharacterSlotTask_obj *__this = (BuyCharacterSlotTask_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BuyCharacterSlotTask_obj), true, "account.services.BuyCharacterSlotTask"));
	*(void **)__this = BuyCharacterSlotTask_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

BuyCharacterSlotTask_obj::BuyCharacterSlotTask_obj()
{
}

::hx::Val BuyCharacterSlotTask_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *BuyCharacterSlotTask_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *BuyCharacterSlotTask_obj_sStaticStorageInfo = 0;
#endif

static ::String BuyCharacterSlotTask_obj_sMemberFields[] = {
	HX_("startTask",c7,38,ea,05),
	HX_("onComplete",f8,d4,7e,5d),
	::String(null()) };

::hx::Class BuyCharacterSlotTask_obj::__mClass;

void BuyCharacterSlotTask_obj::__register()
{
	BuyCharacterSlotTask_obj _hx_dummy;
	BuyCharacterSlotTask_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("account.services.BuyCharacterSlotTask",75,7d,78,f9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(BuyCharacterSlotTask_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< BuyCharacterSlotTask_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BuyCharacterSlotTask_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BuyCharacterSlotTask_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace account
} // end namespace services