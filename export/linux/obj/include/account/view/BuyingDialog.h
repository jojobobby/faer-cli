// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_account_view_BuyingDialog
#define INCLUDED_account_view_BuyingDialog

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_dialogs_Dialog
#include <ui/dialogs/Dialog.h>
#endif
HX_DECLARE_CLASS2(account,view,BuyingDialog)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(ui,dialogs,Dialog)

namespace account{
namespace view{


class HXCPP_CLASS_ATTRIBUTES BuyingDialog_obj : public  ::ui::dialogs::Dialog_obj
{
	public:
		typedef  ::ui::dialogs::Dialog_obj super;
		typedef BuyingDialog_obj OBJ_;
		BuyingDialog_obj();

	public:
		enum { _hx_ClassId = 0x193e52ae };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="account.view.BuyingDialog")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"account.view.BuyingDialog"); }
		static ::hx::ObjectPtr< BuyingDialog_obj > __new();
		static ::hx::ObjectPtr< BuyingDialog_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BuyingDialog_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BuyingDialog",64,4b,cf,75); }

};

} // end namespace account
} // end namespace view

#endif /* INCLUDED_account_view_BuyingDialog */ 