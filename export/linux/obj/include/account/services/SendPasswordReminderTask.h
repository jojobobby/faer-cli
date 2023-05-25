// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_account_services_SendPasswordReminderTask
#define INCLUDED_account_services_SendPasswordReminderTask

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_lib_tasks_Task
#include <lib/tasks/Task.h>
#endif
HX_DECLARE_CLASS2(account,services,SendPasswordReminderTask)
HX_DECLARE_CLASS1(appengine,CompletionData)
HX_DECLARE_CLASS2(lib,tasks,Task)

namespace account{
namespace services{


class HXCPP_CLASS_ATTRIBUTES SendPasswordReminderTask_obj : public  ::lib::tasks::Task_obj
{
	public:
		typedef  ::lib::tasks::Task_obj super;
		typedef SendPasswordReminderTask_obj OBJ_;
		SendPasswordReminderTask_obj();

	public:
		enum { _hx_ClassId = 0x53d8c55d };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="account.services.SendPasswordReminderTask")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"account.services.SendPasswordReminderTask"); }
		static ::hx::ObjectPtr< SendPasswordReminderTask_obj > __new();
		static ::hx::ObjectPtr< SendPasswordReminderTask_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~SendPasswordReminderTask_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("SendPasswordReminderTask",1a,9d,72,a8); }

		static void __boot();
		static ::String email;
		void startTask();

		void onComplete( ::appengine::CompletionData compData);
		::Dynamic onComplete_dyn();

		void onForgotDone();
		::Dynamic onForgotDone_dyn();

		void onForgotError(::String error);
		::Dynamic onForgotError_dyn();

};

} // end namespace account
} // end namespace services

#endif /* INCLUDED_account_services_SendPasswordReminderTask */ 
