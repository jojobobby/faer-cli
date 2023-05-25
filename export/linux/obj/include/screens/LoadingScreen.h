// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_screens_LoadingScreen
#define INCLUDED_screens_LoadingScreen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS1(screens,LoadingScreen)
HX_DECLARE_CLASS1(ui,SimpleText)

namespace screens{


class HXCPP_CLASS_ATTRIBUTES LoadingScreen_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef LoadingScreen_obj OBJ_;
		LoadingScreen_obj();

	public:
		enum { _hx_ClassId = 0x68f183a5 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="screens.LoadingScreen")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"screens.LoadingScreen"); }
		static ::hx::ObjectPtr< LoadingScreen_obj > __new();
		static ::hx::ObjectPtr< LoadingScreen_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~LoadingScreen_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("LoadingScreen",e8,d2,48,78); }

		 ::ui::SimpleText loadingText;
		void onAddedToStage( ::openfl::events::Event event);
		::Dynamic onAddedToStage_dyn();

		void onResize( ::openfl::events::Event _);
		::Dynamic onResize_dyn();

};

} // end namespace screens

#endif /* INCLUDED_screens_LoadingScreen */ 
