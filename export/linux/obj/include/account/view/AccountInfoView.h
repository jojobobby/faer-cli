// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_account_view_AccountInfoView
#define INCLUDED_account_view_AccountInfoView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
HX_DECLARE_CLASS2(account,view,AccountInfoView)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,MouseEvent)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS1(screens,TitleMenuOption)
HX_DECLARE_CLASS1(ui,SimpleText)

namespace account{
namespace view{


class HXCPP_CLASS_ATTRIBUTES AccountInfoView_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef AccountInfoView_obj OBJ_;
		AccountInfoView_obj();

	public:
		enum { _hx_ClassId = 0x52704efa };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="account.view.AccountInfoView")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"account.view.AccountInfoView"); }
		static ::hx::ObjectPtr< AccountInfoView_obj > __new();
		static ::hx::ObjectPtr< AccountInfoView_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~AccountInfoView_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("AccountInfoView",a0,1b,0b,cc); }

		static void onRegister( ::openfl::events::MouseEvent _);
		static ::Dynamic onRegister_dyn();

		::String userName;
		bool isRegistered;
		 ::ui::SimpleText accountText;
		 ::screens::TitleMenuOption registerButton;
		 ::ui::SimpleText dividerText;
		 ::screens::TitleMenuOption loginButton;
		void onAdded( ::openfl::events::Event _);
		::Dynamic onAdded_dyn();

		void onRemoved( ::openfl::events::Event _);
		::Dynamic onRemoved_dyn();

		void updateLogin();
		::Dynamic updateLogin_dyn();

		void onLoginToggle( ::openfl::events::MouseEvent _);
		::Dynamic onLoginToggle_dyn();

		void setInfo(::String userName,bool isRegistered);
		::Dynamic setInfo_dyn();

		void updateUI();
		::Dynamic updateUI_dyn();

		void removeUIElements();
		::Dynamic removeUIElements_dyn();

		void showUIForRegisteredAccount();
		::Dynamic showUIForRegisteredAccount_dyn();

		void showUIForGuestAccount();
		::Dynamic showUIForGuestAccount_dyn();

		void addAndAlignHorizontally(::Array< ::Dynamic> uiElements);
		::Dynamic addAndAlignHorizontally_dyn();

};

} // end namespace account
} // end namespace view

#endif /* INCLUDED_account_view_AccountInfoView */ 