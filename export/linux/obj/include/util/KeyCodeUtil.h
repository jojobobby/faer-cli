// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_util_KeyCodeUtil
#define INCLUDED_util_KeyCodeUtil

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(util,KeyCodeUtil)

namespace util{


class HXCPP_CLASS_ATTRIBUTES KeyCodeUtil_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef KeyCodeUtil_obj OBJ_;
		KeyCodeUtil_obj();

	public:
		enum { _hx_ClassId = 0x08832dac };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="util.KeyCodeUtil")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"util.KeyCodeUtil"); }

		inline static ::hx::ObjectPtr< KeyCodeUtil_obj > __new() {
			::hx::ObjectPtr< KeyCodeUtil_obj > __this = new KeyCodeUtil_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< KeyCodeUtil_obj > __alloc(::hx::Ctx *_hx_ctx) {
			KeyCodeUtil_obj *__this = (KeyCodeUtil_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(KeyCodeUtil_obj), false, "util.KeyCodeUtil"));
			*(void **)__this = KeyCodeUtil_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~KeyCodeUtil_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("KeyCodeUtil",6e,e4,57,ae); }

		static void __boot();
		static ::Array< int > charCodeIconIndices;
};

} // end namespace util

#endif /* INCLUDED_util_KeyCodeUtil */ 
