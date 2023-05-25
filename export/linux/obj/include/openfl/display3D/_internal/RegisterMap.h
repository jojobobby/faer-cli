// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_openfl_display3D__internal_RegisterMap
#define INCLUDED_openfl_display3D__internal_RegisterMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(openfl,display3D,_internal,RegisterMap)
HX_DECLARE_CLASS4(openfl,display3D,_internal,_AGALConverter,DestRegister)
HX_DECLARE_CLASS4(openfl,display3D,_internal,_AGALConverter,RegisterMapEntry)
HX_DECLARE_CLASS4(openfl,display3D,_internal,_AGALConverter,RegisterUsage)
HX_DECLARE_CLASS4(openfl,display3D,_internal,_AGALConverter,SamplerRegister)
HX_DECLARE_CLASS4(openfl,display3D,_internal,_AGALConverter,SourceRegister)

namespace openfl{
namespace display3D{
namespace _internal{


class HXCPP_CLASS_ATTRIBUTES RegisterMap_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef RegisterMap_obj OBJ_;
		RegisterMap_obj();

	public:
		enum { _hx_ClassId = 0x326c9b3c };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl.display3D._internal.RegisterMap")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"openfl.display3D._internal.RegisterMap"); }
		static ::hx::ObjectPtr< RegisterMap_obj > __new();
		static ::hx::ObjectPtr< RegisterMap_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~RegisterMap_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("RegisterMap",d9,93,09,fc); }

		static void __boot();
		static  ::Dynamic __meta__;
		::Array< ::Dynamic> mEntries;
		void add(int type,::String name,int number, ::openfl::display3D::_internal::_AGALConverter::RegisterUsage usage);
		::Dynamic add_dyn();

		void addDR( ::openfl::display3D::_internal::_AGALConverter::DestRegister dr, ::openfl::display3D::_internal::_AGALConverter::RegisterUsage usage);
		::Dynamic addDR_dyn();

		void addSaR( ::openfl::display3D::_internal::_AGALConverter::SamplerRegister sr, ::openfl::display3D::_internal::_AGALConverter::RegisterUsage usage);
		::Dynamic addSaR_dyn();

		void addSR( ::openfl::display3D::_internal::_AGALConverter::SourceRegister sr, ::openfl::display3D::_internal::_AGALConverter::RegisterUsage usage,::hx::Null< int >  offset);
		::Dynamic addSR_dyn();

		 ::openfl::display3D::_internal::_AGALConverter::RegisterUsage getRegisterUsage( ::openfl::display3D::_internal::_AGALConverter::SourceRegister sr);
		::Dynamic getRegisterUsage_dyn();

		 ::openfl::display3D::_internal::_AGALConverter::RegisterUsage getUsage(int type,::String name,int number);
		::Dynamic getUsage_dyn();

		::String toGLSL(bool tempRegistersOnly);
		::Dynamic toGLSL_dyn();

};

} // end namespace openfl
} // end namespace display3D
} // end namespace _internal

#endif /* INCLUDED_openfl_display3D__internal_RegisterMap */ 
