// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_tooltip_TooltipHelper
#define INCLUDED_ui_tooltip_TooltipHelper

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(ui,tooltip,TooltipHelper)

namespace ui{
namespace tooltip{


class HXCPP_CLASS_ATTRIBUTES TooltipHelper_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef TooltipHelper_obj OBJ_;
		TooltipHelper_obj();

	public:
		enum { _hx_ClassId = 0x7aa83e22 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="ui.tooltip.TooltipHelper")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"ui.tooltip.TooltipHelper"); }

		inline static ::hx::ObjectPtr< TooltipHelper_obj > __new() {
			::hx::ObjectPtr< TooltipHelper_obj > __this = new TooltipHelper_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< TooltipHelper_obj > __alloc(::hx::Ctx *_hx_ctx) {
			TooltipHelper_obj *__this = (TooltipHelper_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TooltipHelper_obj), false, "ui.tooltip.TooltipHelper"));
			*(void **)__this = TooltipHelper_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~TooltipHelper_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("TooltipHelper",b1,12,60,da); }

		static ::String getFormattedString(Float elem);
		static ::Dynamic getFormattedString_dyn();

};

} // end namespace ui
} // end namespace tooltip

#endif /* INCLUDED_ui_tooltip_TooltipHelper */ 
