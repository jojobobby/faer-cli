// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_util_CachingColorTransformer
#define INCLUDED_util_CachingColorTransformer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,geom,ColorTransform)
HX_DECLARE_CLASS1(util,CachingColorTransformer)

namespace util{


class HXCPP_CLASS_ATTRIBUTES CachingColorTransformer_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef CachingColorTransformer_obj OBJ_;
		CachingColorTransformer_obj();

	public:
		enum { _hx_ClassId = 0x7fd21e33 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="util.CachingColorTransformer")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"util.CachingColorTransformer"); }

		inline static ::hx::ObjectPtr< CachingColorTransformer_obj > __new() {
			::hx::ObjectPtr< CachingColorTransformer_obj > __this = new CachingColorTransformer_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< CachingColorTransformer_obj > __alloc(::hx::Ctx *_hx_ctx) {
			CachingColorTransformer_obj *__this = (CachingColorTransformer_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CachingColorTransformer_obj), false, "util.CachingColorTransformer"));
			*(void **)__this = CachingColorTransformer_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CachingColorTransformer_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CachingColorTransformer",35,6e,0e,5f); }

		static void __boot();
		static  ::haxe::ds::ObjectMap bds;
		static  ::openfl::display::BitmapData transformBitmapData( ::openfl::display::BitmapData bitmapData, ::openfl::geom::ColorTransform ct);
		static ::Dynamic transformBitmapData_dyn();

};

} // end namespace util

#endif /* INCLUDED_util_CachingColorTransformer */ 