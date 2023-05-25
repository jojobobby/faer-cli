// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_view_CharacterDetailsView
#define INCLUDED_ui_view_CharacterDetailsView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
HX_DECLARE_CLASS1(objects,GameObject)
HX_DECLARE_CLASS1(objects,Player)
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
HX_DECLARE_CLASS2(ui,view,CharacterDetailsView)
HX_DECLARE_CLASS1(util,AnimatedChar)

namespace ui{
namespace view{


class HXCPP_CLASS_ATTRIBUTES CharacterDetailsView_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef CharacterDetailsView_obj OBJ_;
		CharacterDetailsView_obj();

	public:
		enum { _hx_ClassId = 0x535e565b };

		void __construct(::hx::Null< Float >  __o_scale);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.view.CharacterDetailsView")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.view.CharacterDetailsView"); }
		static ::hx::ObjectPtr< CharacterDetailsView_obj > __new(::hx::Null< Float >  __o_scale);
		static ::hx::ObjectPtr< CharacterDetailsView_obj > __alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_scale);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CharacterDetailsView_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CharacterDetailsView",3e,2b,6d,42); }

		 ::openfl::display::Bitmap decor;
		 ::openfl::display::Bitmap portrait;
		 ::openfl::display::Bitmap hpBar;
		 ::ui::SimpleText hpBarText;
		 ::openfl::display::Bitmap mpBar;
		 ::ui::SimpleText mpBarText;
		 ::openfl::display::Bitmap xpBar;
		 ::ui::SimpleText nameText;
		Float scale;
		 ::util::AnimatedChar lastSkin;
		int lastHp;
		int lastMaxHp;
		int lastBoostHp;
		int lastHpMax;
		int lastMp;
		int lastMaxMp;
		int lastBoostMp;
		int lastMpMax;
		void init( ::objects::Player player);
		::Dynamic init_dyn();

		void draw( ::objects::Player player);
		::Dynamic draw_dyn();

};

} // end namespace ui
} // end namespace view

#endif /* INCLUDED_ui_view_CharacterDetailsView */ 
