// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_tooltip_Restriction
#define INCLUDED_ui_tooltip_Restriction

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_5b53bc7b29f0230c_366_new)
HX_DECLARE_CLASS2(ui,tooltip,Restriction)

namespace ui{
namespace tooltip{


class HXCPP_CLASS_ATTRIBUTES Restriction_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Restriction_obj OBJ_;
		Restriction_obj();

	public:
		enum { _hx_ClassId = 0x0b113281 };

		void __construct(::String text,int color,bool bold);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.tooltip.Restriction")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.tooltip.Restriction"); }

		inline static ::hx::ObjectPtr< Restriction_obj > __new(::String text,int color,bool bold) {
			::hx::ObjectPtr< Restriction_obj > __this = new Restriction_obj();
			__this->__construct(text,color,bold);
			return __this;
		}

		inline static ::hx::ObjectPtr< Restriction_obj > __alloc(::hx::Ctx *_hx_ctx,::String text,int color,bool bold) {
			Restriction_obj *__this = (Restriction_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Restriction_obj), true, "ui.tooltip.Restriction"));
			*(void **)__this = Restriction_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_5b53bc7b29f0230c_366_new)
HXLINE( 369)		( ( ::ui::tooltip::Restriction)(__this) )->bold = false;
HXLINE( 368)		( ( ::ui::tooltip::Restriction)(__this) )->color = 0;
HXLINE( 367)		( ( ::ui::tooltip::Restriction)(__this) )->text = HX_("",00,00,00,00);
HXLINE( 372)		( ( ::ui::tooltip::Restriction)(__this) )->text = text;
HXLINE( 373)		( ( ::ui::tooltip::Restriction)(__this) )->color = color;
HXLINE( 374)		( ( ::ui::tooltip::Restriction)(__this) )->bold = bold;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Restriction_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Restriction",ec,87,9d,9f); }

		::String text;
		int color;
		bool bold;
};

} // end namespace ui
} // end namespace tooltip

#endif /* INCLUDED_ui_tooltip_Restriction */ 
