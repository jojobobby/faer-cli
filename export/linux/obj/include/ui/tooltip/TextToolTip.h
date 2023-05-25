// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_tooltip_TextToolTip
#define INCLUDED_ui_tooltip_TextToolTip

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_tooltip_ToolTip
#include <ui/tooltip/ToolTip.h>
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
HX_DECLARE_CLASS2(ui,tooltip,TextToolTip)
HX_DECLARE_CLASS2(ui,tooltip,ToolTip)

namespace ui{
namespace tooltip{


class HXCPP_CLASS_ATTRIBUTES TextToolTip_obj : public  ::ui::tooltip::ToolTip_obj
{
	public:
		typedef  ::ui::tooltip::ToolTip_obj super;
		typedef TextToolTip_obj OBJ_;
		TextToolTip_obj();

	public:
		enum { _hx_ClassId = 0x6aa0b4c7 };

		void __construct(int background,int outline,::String title,::String text);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.tooltip.TextToolTip")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.tooltip.TextToolTip"); }
		static ::hx::ObjectPtr< TextToolTip_obj > __new(int background,int outline,::String title,::String text);
		static ::hx::ObjectPtr< TextToolTip_obj > __alloc(::hx::Ctx *_hx_ctx,int background,int outline,::String title,::String text);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~TextToolTip_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("TextToolTip",96,f7,26,2a); }

		 ::ui::SimpleText titleText;
		 ::ui::SimpleText tipText;
};

} // end namespace ui
} // end namespace tooltip

#endif /* INCLUDED_ui_tooltip_TextToolTip */ 
