// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_util_RenderUtils
#define INCLUDED_util_RenderUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(util,RenderUtils)

namespace util{


class HXCPP_CLASS_ATTRIBUTES RenderUtils_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef RenderUtils_obj OBJ_;
		RenderUtils_obj();

	public:
		enum { _hx_ClassId = 0x7f6584a1 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="util.RenderUtils")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"util.RenderUtils"); }

		inline static ::hx::ObjectPtr< RenderUtils_obj > __new() {
			::hx::ObjectPtr< RenderUtils_obj > __this = new RenderUtils_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< RenderUtils_obj > __alloc(::hx::Ctx *_hx_ctx) {
			RenderUtils_obj *__this = (RenderUtils_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(RenderUtils_obj), false, "util.RenderUtils"));
			*(void **)__this = RenderUtils_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~RenderUtils_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("RenderUtils",db,6e,c2,5a); }

		static void __boot();
		static float clipSpaceScaleX;
		static float clipSpaceScaleY;
};

} // end namespace util

#endif /* INCLUDED_util_RenderUtils */ 
