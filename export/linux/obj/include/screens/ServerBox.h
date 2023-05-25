// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_screens_ServerBox
#define INCLUDED_screens_ServerBox

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
HX_DECLARE_CLASS2(openfl,events,MouseEvent)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS1(screens,ServerBox)
HX_DECLARE_CLASS1(servers,Server)
HX_DECLARE_CLASS1(ui,SimpleText)

namespace screens{


class HXCPP_CLASS_ATTRIBUTES ServerBox_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef ServerBox_obj OBJ_;
		ServerBox_obj();

	public:
		enum { _hx_ClassId = 0x4ed53525 };

		void __construct( ::servers::Server server);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="screens.ServerBox")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"screens.ServerBox"); }
		static ::hx::ObjectPtr< ServerBox_obj > __new( ::servers::Server server);
		static ::hx::ObjectPtr< ServerBox_obj > __alloc(::hx::Ctx *_hx_ctx, ::servers::Server server);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ServerBox_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ServerBox",e8,e6,dc,1a); }

		::String value;
		 ::ui::SimpleText nameText;
		 ::ui::SimpleText statusText;
		bool selected;
		bool over;
		void setSelected(bool selected);
		::Dynamic setSelected_dyn();

		void draw();
		::Dynamic draw_dyn();

		void onMouseOver( ::openfl::events::MouseEvent event);
		::Dynamic onMouseOver_dyn();

		void onRollOut( ::openfl::events::MouseEvent event);
		::Dynamic onRollOut_dyn();

};

} // end namespace screens

#endif /* INCLUDED_screens_ServerBox */ 