// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_appengine_SavedCharacter
#define INCLUDED_appengine_SavedCharacter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS1(appengine,SavedCharacter)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,geom,ColorTransform)

namespace appengine{


class HXCPP_CLASS_ATTRIBUTES SavedCharacter_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef SavedCharacter_obj OBJ_;
		SavedCharacter_obj();

	public:
		enum { _hx_ClassId = 0x77161d65 };

		void __construct( ::Xml charXML,::String name);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="appengine.SavedCharacter")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"appengine.SavedCharacter"); }
		static ::hx::ObjectPtr< SavedCharacter_obj > __new( ::Xml charXML,::String name);
		static ::hx::ObjectPtr< SavedCharacter_obj > __alloc(::hx::Ctx *_hx_ctx, ::Xml charXML,::String name);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~SavedCharacter_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("SavedCharacter",42,fc,d9,b2); }

		static void __boot();
		static  ::openfl::geom::ColorTransform notAvailableCT;
		static  ::openfl::geom::ColorTransform dimCT;
		static  ::openfl::display::BitmapData getImage( ::appengine::SavedCharacter savedChar, ::Xml playerXML,int dir,int action,Float p,bool available,bool selected);
		static ::Dynamic getImage_dyn();

		static int compare( ::appengine::SavedCharacter char1, ::appengine::SavedCharacter char2);
		static ::Dynamic compare_dyn();

		 ::Xml charXML;
		::String _name;
		 ::Dynamic charId();
		::Dynamic charId_dyn();

		::String name();
		::Dynamic name_dyn();

		 ::Dynamic objectType();
		::Dynamic objectType_dyn();

		 ::Dynamic skinType();
		::Dynamic skinType_dyn();

		 ::Dynamic tier();
		::Dynamic tier_dyn();

		::String displayId();
		::Dynamic displayId_dyn();

};

} // end namespace appengine

#endif /* INCLUDED_appengine_SavedCharacter */ 