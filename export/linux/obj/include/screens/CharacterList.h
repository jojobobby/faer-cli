// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_screens_CharacterList
#define INCLUDED_screens_CharacterList

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
HX_DECLARE_CLASS1(screens,CharacterList)
HX_DECLARE_CLASS2(screens,charrects,CharacterRectList)

namespace screens{


class HXCPP_CLASS_ATTRIBUTES CharacterList_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef CharacterList_obj OBJ_;
		CharacterList_obj();

	public:
		enum { _hx_ClassId = 0x7938ad44 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="screens.CharacterList")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"screens.CharacterList"); }
		static ::hx::ObjectPtr< CharacterList_obj > __new();
		static ::hx::ObjectPtr< CharacterList_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CharacterList_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CharacterList",87,fc,8f,88); }

		 ::screens::charrects::CharacterRectList charRectList;
		void setPos(Float pos);
		::Dynamic setPos_dyn();

};

} // end namespace screens

#endif /* INCLUDED_screens_CharacterList */ 
