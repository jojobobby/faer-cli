// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_StatusBar
#define INCLUDED_ui_StatusBar

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
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS1(ui,SimpleText)
HX_DECLARE_CLASS1(ui,StatusBar)

namespace ui{


class HXCPP_CLASS_ATTRIBUTES StatusBar_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef StatusBar_obj OBJ_;
		StatusBar_obj();

	public:
		enum { _hx_ClassId = 0x63185a69 };

		void __construct(int w,int h,int color,int backColor,::hx::Null< Float >  __o_textScale,::hx::Null< int >  __o_textXOffset);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.StatusBar")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.StatusBar"); }
		static ::hx::ObjectPtr< StatusBar_obj > __new(int w,int h,int color,int backColor,::hx::Null< Float >  __o_textScale,::hx::Null< int >  __o_textXOffset);
		static ::hx::ObjectPtr< StatusBar_obj > __alloc(::hx::Ctx *_hx_ctx,int w,int h,int color,int backColor,::hx::Null< Float >  __o_textScale,::hx::Null< int >  __o_textXOffset);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~StatusBar_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("StatusBar",a1,6d,40,1c); }

		int w;
		int h;
		int color;
		int backColor;
		int textColor;
		int val;
		int max;
		int boost;
		int maxMax;
		 ::ui::SimpleText valueText;
		 ::ui::SimpleText boostText;
		 ::openfl::display::Sprite colorSprite;
		Float defaultForegroundColor;
		Float defaultBackgroundColor;
		int textXOffset;
		void draw(int val,int max,int boost,::hx::Null< int >  maxMax);
		::Dynamic draw_dyn();

		void setTextColor(int textColor);
		::Dynamic setTextColor_dyn();

		void internalDraw();
		::Dynamic internalDraw_dyn();

};

} // end namespace ui

#endif /* INCLUDED_ui_StatusBar */ 
