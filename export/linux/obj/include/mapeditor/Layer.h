// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_mapeditor_Layer
#define INCLUDED_mapeditor_Layer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mapeditor,Layer)

namespace mapeditor{


class HXCPP_CLASS_ATTRIBUTES Layer_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Layer_obj OBJ_;
		Layer_obj();

	public:
		enum { _hx_ClassId = 0x03e0fb88 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="mapeditor.Layer")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"mapeditor.Layer"); }

		inline static ::hx::ObjectPtr< Layer_obj > __new() {
			::hx::ObjectPtr< Layer_obj > __this = new Layer_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Layer_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Layer_obj *__this = (Layer_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Layer_obj), false, "mapeditor.Layer"));
			*(void **)__this = Layer_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Layer_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Layer",b1,f1,ed,02); }

		static void __boot();
		static ::Array< int > EMPTY_TILE;
};

} // end namespace mapeditor

#endif /* INCLUDED_mapeditor_Layer */ 
