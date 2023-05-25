// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_screens_charrects_CharacterRectList
#define INCLUDED_screens_charrects_CharacterRectList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
HX_DECLARE_CLASS1(appengine,SavedCharacter)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(screens,charrects,CharacterRectList)

namespace screens{
namespace charrects{


class HXCPP_CLASS_ATTRIBUTES CharacterRectList_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef CharacterRectList_obj OBJ_;
		CharacterRectList_obj();

	public:
		enum { _hx_ClassId = 0x11d760f1 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="screens.charrects.CharacterRectList")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"screens.charrects.CharacterRectList"); }
		static ::hx::ObjectPtr< CharacterRectList_obj > __new();
		static ::hx::ObjectPtr< CharacterRectList_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CharacterRectList_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CharacterRectList",4b,a0,05,af); }

		static  ::openfl::display::DisplayObject getIcon( ::appengine::SavedCharacter savedChar);
		static ::Dynamic getIcon_dyn();

		static void onNewChar( ::openfl::events::Event event);
		static ::Dynamic onNewChar_dyn();

		static void onBuyCharSlot( ::openfl::events::Event event);
		static ::Dynamic onBuyCharSlot_dyn();

};

} // end namespace screens
} // end namespace charrects

#endif /* INCLUDED_screens_charrects_CharacterRectList */ 
