// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_tooltip_ClassToolTip
#define INCLUDED_ui_tooltip_ClassToolTip

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_tooltip_ToolTip
#include <ui/tooltip/ToolTip.h>
#endif
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(openfl,display,Bitmap)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS1(ui,SimpleText)
HX_DECLARE_CLASS2(ui,tooltip,ClassToolTip)
HX_DECLARE_CLASS2(ui,tooltip,ToolTip)

namespace ui{
namespace tooltip{


class HXCPP_CLASS_ATTRIBUTES ClassToolTip_obj : public  ::ui::tooltip::ToolTip_obj
{
	public:
		typedef  ::ui::tooltip::ToolTip_obj super;
		typedef ClassToolTip_obj OBJ_;
		ClassToolTip_obj();

	public:
		enum { _hx_ClassId = 0x4513255a };

		void __construct( ::Xml playerXML);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.tooltip.ClassToolTip")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.tooltip.ClassToolTip"); }
		static ::hx::ObjectPtr< ClassToolTip_obj > __new( ::Xml playerXML);
		static ::hx::ObjectPtr< ClassToolTip_obj > __alloc(::hx::Ctx *_hx_ctx, ::Xml playerXML);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ClassToolTip_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ClassToolTip",ab,57,07,1b); }

		 ::openfl::display::Bitmap portrait;
		 ::ui::SimpleText nameText;
		 ::ui::SimpleText descriptionText;
};

} // end namespace ui
} // end namespace tooltip

#endif /* INCLUDED_ui_tooltip_ClassToolTip */ 