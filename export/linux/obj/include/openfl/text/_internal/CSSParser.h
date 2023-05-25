// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_openfl_text__internal_CSSParser
#define INCLUDED_openfl_text__internal_CSSParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS3(openfl,text,_internal,CSSParser)

namespace openfl{
namespace text{
namespace _internal{


class HXCPP_CLASS_ATTRIBUTES CSSParser_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef CSSParser_obj OBJ_;
		CSSParser_obj();

	public:
		enum { _hx_ClassId = 0x1cb0eda7 };

		void __construct( ::haxe::ds::StringMap options);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl.text._internal.CSSParser")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"openfl.text._internal.CSSParser"); }
		static ::hx::ObjectPtr< CSSParser_obj > __new( ::haxe::ds::StringMap options);
		static ::hx::ObjectPtr< CSSParser_obj > __alloc(::hx::Ctx *_hx_ctx, ::haxe::ds::StringMap options);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CSSParser_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CSSParser",e2,0c,1c,5e); }

		::cpp::VirtualArray importStatements;
		::String keyframeRegex;
		::String combinedCSSRegex;
		::String commentRegex;
		 ::EReg importRegex;
		::Array< ::Dynamic> parseRules(::String rules);
		::Dynamic parseRules_dyn();

		 ::haxe::ds::StringMap parse(::String source);
		::Dynamic parse_dyn();

		::Array< ::String > getMatches( ::EReg ereg,::String input,::hx::Null< int >  index);
		::Dynamic getMatches_dyn();

};

} // end namespace openfl
} // end namespace text
} // end namespace _internal

#endif /* INCLUDED_openfl_text__internal_CSSParser */ 
