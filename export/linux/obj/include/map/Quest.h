// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_map_Quest
#define INCLUDED_map_Quest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(map,Map)
HX_DECLARE_CLASS1(map,Quest)

namespace map{


class HXCPP_CLASS_ATTRIBUTES Quest_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Quest_obj OBJ_;
		Quest_obj();

	public:
		enum { _hx_ClassId = 0x78aab4a6 };

		void __construct( ::map::Map map);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="map.Quest")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"map.Quest"); }
		static ::hx::ObjectPtr< Quest_obj > __new( ::map::Map map);
		static ::hx::ObjectPtr< Quest_obj > __alloc(::hx::Ctx *_hx_ctx, ::map::Map map);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Quest_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Quest",c2,fb,17,f1); }

		 ::map::Map map;
		int objectId;
		int questAvailableAt;
		int questOldAt;
		void setObject(int objectId);
		::Dynamic setObject_dyn();

		void completed();
		::Dynamic completed_dyn();

};

} // end namespace map

#endif /* INCLUDED_map_Quest */ 
