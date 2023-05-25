// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_core_Layers
#define INCLUDED_core_Layers

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
HX_DECLARE_CLASS1(core,Layers)
HX_DECLARE_CLASS1(core,ScreensView)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(ui,dialogs,DialogsView)
HX_DECLARE_CLASS2(ui,tooltip,TooltipsView)

namespace core{


class HXCPP_CLASS_ATTRIBUTES Layers_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef Layers_obj OBJ_;
		Layers_obj();

	public:
		enum { _hx_ClassId = 0x319bbae5 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="core.Layers")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"core.Layers"); }
		static ::hx::ObjectPtr< Layers_obj > __new();
		static ::hx::ObjectPtr< Layers_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Layers_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Layers",a2,89,45,8d); }

		 ::openfl::display::Sprite overlay;
		 ::core::ScreensView screens;
		 ::ui::tooltip::TooltipsView tooltips;
		 ::ui::dialogs::DialogsView dialogs;
};

} // end namespace core

#endif /* INCLUDED_core_Layers */ 