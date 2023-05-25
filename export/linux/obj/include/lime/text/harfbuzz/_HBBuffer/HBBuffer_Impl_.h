// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_lime_text_harfbuzz__HBBuffer_HBBuffer_Impl_
#define INCLUDED_lime_text_harfbuzz__HBBuffer_HBBuffer_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(lime,text,harfbuzz,HBGlyphInfo)
HX_DECLARE_CLASS3(lime,text,harfbuzz,HBGlyphPosition)
HX_DECLARE_CLASS4(lime,text,harfbuzz,_HBBuffer,HBBuffer_Impl_)

namespace lime{
namespace text{
namespace harfbuzz{
namespace _HBBuffer{


class HXCPP_CLASS_ATTRIBUTES HBBuffer_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef HBBuffer_Impl__obj OBJ_;
		HBBuffer_Impl__obj();

	public:
		enum { _hx_ClassId = 0x56d99e0d };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lime.text.harfbuzz._HBBuffer.HBBuffer_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lime.text.harfbuzz._HBBuffer.HBBuffer_Impl_"); }

		inline static ::hx::ObjectPtr< HBBuffer_Impl__obj > __new() {
			::hx::ObjectPtr< HBBuffer_Impl__obj > __this = new HBBuffer_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< HBBuffer_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			HBBuffer_Impl__obj *__this = (HBBuffer_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(HBBuffer_Impl__obj), false, "lime.text.harfbuzz._HBBuffer.HBBuffer_Impl_"));
			*(void **)__this = HBBuffer_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~HBBuffer_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("HBBuffer_Impl_",ba,d3,3b,a1); }

		static  ::Dynamic _new();
		static ::Dynamic _new_dyn();

		static void addUTF16( ::Dynamic this1,Float text,int textLength,int itemOffset,int itemLength);
		static ::Dynamic addUTF16_dyn();

		static ::Array< ::Dynamic> getGlyphInfo( ::Dynamic this1);
		static ::Dynamic getGlyphInfo_dyn();

		static ::Array< ::Dynamic> getGlyphPositions( ::Dynamic this1);
		static ::Dynamic getGlyphPositions_dyn();

		static void reset( ::Dynamic this1);
		static ::Dynamic reset_dyn();

};

} // end namespace lime
} // end namespace text
} // end namespace harfbuzz
} // end namespace _HBBuffer

#endif /* INCLUDED_lime_text_harfbuzz__HBBuffer_HBBuffer_Impl_ */ 