// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_util_BevelRect
#define INCLUDED_util_BevelRect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_2928d61b2cc417f7_3_new)
HX_DECLARE_CLASS1(util,BevelRect)

namespace util{


class HXCPP_CLASS_ATTRIBUTES BevelRect_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef BevelRect_obj OBJ_;
		BevelRect_obj();

	public:
		enum { _hx_ClassId = 0x1b85445c };

		void __construct(int width,int height,int bevel);
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="util.BevelRect")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"util.BevelRect"); }

		inline static ::hx::ObjectPtr< BevelRect_obj > __new(int width,int height,int bevel) {
			::hx::ObjectPtr< BevelRect_obj > __this = new BevelRect_obj();
			__this->__construct(width,height,bevel);
			return __this;
		}

		inline static ::hx::ObjectPtr< BevelRect_obj > __alloc(::hx::Ctx *_hx_ctx,int width,int height,int bevel) {
			BevelRect_obj *__this = (BevelRect_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BevelRect_obj), false, "util.BevelRect"));
			*(void **)__this = BevelRect_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_2928d61b2cc417f7_3_new)
HXLINE(  10)		( ( ::util::BevelRect)(__this) )->bevel = 0;
HXLINE(   9)		( ( ::util::BevelRect)(__this) )->height = 0;
HXLINE(   8)		( ( ::util::BevelRect)(__this) )->width = 0;
HXLINE(   7)		( ( ::util::BevelRect)(__this) )->bottomRightBevel = true;
HXLINE(   6)		( ( ::util::BevelRect)(__this) )->bottomLeftBevel = true;
HXLINE(   5)		( ( ::util::BevelRect)(__this) )->topRightBevel = true;
HXLINE(   4)		( ( ::util::BevelRect)(__this) )->topLeftBevel = true;
HXLINE(  13)		( ( ::util::BevelRect)(__this) )->width = width;
HXLINE(  14)		( ( ::util::BevelRect)(__this) )->height = height;
HXLINE(  15)		( ( ::util::BevelRect)(__this) )->bevel = bevel;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BevelRect_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BevelRect",9e,66,db,e5); }

		bool topLeftBevel;
		bool topRightBevel;
		bool bottomLeftBevel;
		bool bottomRightBevel;
		int width;
		int height;
		int bevel;
};

} // end namespace util

#endif /* INCLUDED_util_BevelRect */ 