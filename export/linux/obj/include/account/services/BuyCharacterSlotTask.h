// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_account_services_BuyCharacterSlotTask
#define INCLUDED_account_services_BuyCharacterSlotTask

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_lib_tasks_Task
#include <lib/tasks/Task.h>
#endif
HX_DECLARE_CLASS2(account,services,BuyCharacterSlotTask)
HX_DECLARE_CLASS1(appengine,CompletionData)
HX_DECLARE_CLASS2(lib,tasks,Task)

namespace account{
namespace services{


class HXCPP_CLASS_ATTRIBUTES BuyCharacterSlotTask_obj : public  ::lib::tasks::Task_obj
{
	public:
		typedef  ::lib::tasks::Task_obj super;
		typedef BuyCharacterSlotTask_obj OBJ_;
		BuyCharacterSlotTask_obj();

	public:
		enum { _hx_ClassId = 0x38702acd };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="account.services.BuyCharacterSlotTask")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"account.services.BuyCharacterSlotTask"); }
		static ::hx::ObjectPtr< BuyCharacterSlotTask_obj > __new();
		static ::hx::ObjectPtr< BuyCharacterSlotTask_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BuyCharacterSlotTask_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BuyCharacterSlotTask",26,e3,02,43); }

		void startTask();

		void onComplete( ::appengine::CompletionData compData);
		::Dynamic onComplete_dyn();

};

} // end namespace account
} // end namespace services

#endif /* INCLUDED_account_services_BuyCharacterSlotTask */ 
