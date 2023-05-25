// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_map_GroundLibrary
#define INCLUDED_map_GroundLibrary

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(map,GroundLibrary)
HX_DECLARE_CLASS1(map,GroundProperties)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)

namespace map{


class HXCPP_CLASS_ATTRIBUTES GroundLibrary_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GroundLibrary_obj OBJ_;
		GroundLibrary_obj();

	public:
		enum { _hx_ClassId = 0x365827f8 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="map.GroundLibrary")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"map.GroundLibrary"); }

		inline static ::hx::ObjectPtr< GroundLibrary_obj > __new() {
			::hx::ObjectPtr< GroundLibrary_obj > __this = new GroundLibrary_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< GroundLibrary_obj > __alloc(::hx::Ctx *_hx_ctx) {
			GroundLibrary_obj *__this = (GroundLibrary_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GroundLibrary_obj), false, "map.GroundLibrary"));
			*(void **)__this = GroundLibrary_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GroundLibrary_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GroundLibrary",14,eb,4b,6a); }

		static void __boot();
		static  ::haxe::ds::IntMap propsLibrary;
		static  ::haxe::ds::IntMap xmlLibrary;
		static  ::haxe::ds::IntMap typeToTextureData;
		static  ::haxe::ds::IntMap typeToAnimationsData;
		static  ::haxe::ds::StringMap idToType;
		static  ::map::GroundProperties defaultProps;
		static  ::haxe::ds::IntMap tileTypeColor;
		static void parseFromXML( ::Xml xml);
		static ::Dynamic parseFromXML_dyn();

		static ::String getIdFromType(int tileType);
		static ::Dynamic getIdFromType_dyn();

		static  ::openfl::display::BitmapData getBitmapData(int tileType,::hx::Null< int >  id);
		static ::Dynamic getBitmapData_dyn();

		static  ::Dynamic getColor(int groundType);
		static ::Dynamic getColor_dyn();

};

} // end namespace map

#endif /* INCLUDED_map_GroundLibrary */ 
