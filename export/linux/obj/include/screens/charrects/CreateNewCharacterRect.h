// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_screens_charrects_CreateNewCharacterRect
#define INCLUDED_screens_charrects_CreateNewCharacterRect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_screens_charrects_CharacterRect
#include <screens/charrects/CharacterRect.h>
#endif
HX_DECLARE_CLASS2(openfl,display,Bitmap)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS2(screens,charrects,CharacterRect)
HX_DECLARE_CLASS2(screens,charrects,CreateNewCharacterRect)
HX_DECLARE_CLASS1(ui,SimpleText)

namespace screens{
namespace charrects{


class HXCPP_CLASS_ATTRIBUTES CreateNewCharacterRect_obj : public  ::screens::charrects::CharacterRect_obj
{
	public:
		typedef  ::screens::charrects::CharacterRect_obj super;
		typedef CreateNewCharacterRect_obj OBJ_;
		CreateNewCharacterRect_obj();

	public:
		enum { _hx_ClassId = 0x0afc5f5f };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="screens.charrects.CreateNewCharacterRect")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"screens.charrects.CreateNewCharacterRect"); }
		static ::hx::ObjectPtr< CreateNewCharacterRect_obj > __new();
		static ::hx::ObjectPtr< CreateNewCharacterRect_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CreateNewCharacterRect_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CreateNewCharacterRect",29,50,fd,d0); }

		 ::openfl::display::Bitmap bitmap;
		 ::ui::SimpleText classNameText;
};

} // end namespace screens
} // end namespace charrects

#endif /* INCLUDED_screens_charrects_CreateNewCharacterRect */ 
