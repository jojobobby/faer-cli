// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_lib_ui_impl_NullLayout
#define INCLUDED_lib_ui_impl_NullLayout

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_lib_ui_api_Layout
#include <lib/ui/api/Layout.h>
#endif
HX_DECLARE_CLASS3(lib,ui,api,Layout)
HX_DECLARE_CLASS3(lib,ui,impl,NullLayout)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)

namespace lib{
namespace ui{
namespace impl{


class HXCPP_CLASS_ATTRIBUTES NullLayout_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef NullLayout_obj OBJ_;
		NullLayout_obj();

	public:
		enum { _hx_ClassId = 0x56871186 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lib.ui.impl.NullLayout")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lib.ui.impl.NullLayout"); }
		static ::hx::ObjectPtr< NullLayout_obj > __new();
		static ::hx::ObjectPtr< NullLayout_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~NullLayout_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		void *_hx_getInterface(int inHash);
		::String __ToString() const { return HX_("NullLayout",b1,e4,a8,38); }

		void layout(::Array< ::Dynamic> elements,::hx::Null< int >  offset);
		::Dynamic layout_dyn();

};

} // end namespace lib
} // end namespace ui
} // end namespace impl

#endif /* INCLUDED_lib_ui_impl_NullLayout */ 
