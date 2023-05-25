// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_objects_ScepterProperties
#define INCLUDED_objects_ScepterProperties

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS1(objects,DrainProperties)
HX_DECLARE_CLASS1(objects,ScepterProperties)

namespace objects{


class HXCPP_CLASS_ATTRIBUTES ScepterProperties_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ScepterProperties_obj OBJ_;
		ScepterProperties_obj();

	public:
		enum { _hx_ClassId = 0x3516b149 };

		void __construct( ::Xml scepterXML);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="objects.ScepterProperties")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"objects.ScepterProperties"); }
		static ::hx::ObjectPtr< ScepterProperties_obj > __new( ::Xml scepterXML);
		static ::hx::ObjectPtr< ScepterProperties_obj > __alloc(::hx::Ctx *_hx_ctx, ::Xml scepterXML);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ScepterProperties_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ScepterProperties",39,5f,52,b6); }

		int color;
		Float range;
		int tickMs;
		int damage;
		 ::objects::DrainProperties drain;
};

} // end namespace objects

#endif /* INCLUDED_objects_ScepterProperties */ 