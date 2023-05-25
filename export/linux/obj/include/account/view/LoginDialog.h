// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_account_view_LoginDialog
#define INCLUDED_account_view_LoginDialog

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_Frame
#include <ui/Frame.h>
#endif
HX_DECLARE_CLASS2(account,view,LoginDialog)
HX_DECLARE_CLASS2(lib,tasks,TaskData)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,MouseEvent)
HX_DECLARE_CLASS1(ui,ClickableText)
HX_DECLARE_CLASS1(ui,Frame)
HX_DECLARE_CLASS1(ui,TextInputField)

namespace account{
namespace view{


class HXCPP_CLASS_ATTRIBUTES LoginDialog_obj : public  ::ui::Frame_obj
{
	public:
		typedef  ::ui::Frame_obj super;
		typedef LoginDialog_obj OBJ_;
		LoginDialog_obj();

	public:
		enum { _hx_ClassId = 0x3791321f };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="account.view.LoginDialog")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"account.view.LoginDialog"); }
		static ::hx::ObjectPtr< LoginDialog_obj > __new();
		static ::hx::ObjectPtr< LoginDialog_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~LoginDialog_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("LoginDialog",f1,5e,24,bb); }

		static void onRegister( ::openfl::events::MouseEvent _);
		static ::Dynamic onRegister_dyn();

		static void onCancel( ::openfl::events::MouseEvent _);
		static ::Dynamic onCancel_dyn();

		static void onForgot( ::openfl::events::MouseEvent _);
		static ::Dynamic onForgot_dyn();

		 ::ui::TextInputField email;
		 ::ui::TextInputField password;
		 ::ui::ClickableText forgotText;
		 ::ui::ClickableText registerText;
		void onAdded( ::openfl::events::Event _);
		::Dynamic onAdded_dyn();

		void onRemoved( ::openfl::events::Event _);
		::Dynamic onRemoved_dyn();

		bool isPasswordValid();
		::Dynamic isPasswordValid_dyn();

		bool isEmailValid();
		::Dynamic isEmailValid_dyn();

		void onSignIn( ::openfl::events::MouseEvent event);
		::Dynamic onSignIn_dyn();

		void loginComplete( ::lib::tasks::TaskData _);
		::Dynamic loginComplete_dyn();

		void charListComplete( ::lib::tasks::TaskData _);
		::Dynamic charListComplete_dyn();

};

} // end namespace account
} // end namespace view

#endif /* INCLUDED_account_view_LoginDialog */ 