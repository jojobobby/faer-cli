// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_model_VialData
#define INCLUDED_ui_model_VialData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_b5699a99b5d29ec0_3_new)
HX_DECLARE_CLASS2(ui,model,VialData)

namespace ui{
namespace model{


class HXCPP_CLASS_ATTRIBUTES VialData_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef VialData_obj OBJ_;
		VialData_obj();

	public:
		enum { _hx_ClassId = 0x45897d9d };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="ui.model.VialData")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"ui.model.VialData"); }

		inline static ::hx::ObjectPtr< VialData_obj > __new() {
			::hx::ObjectPtr< VialData_obj > __this = new VialData_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< VialData_obj > __alloc(::hx::Ctx *_hx_ctx) {
			VialData_obj *__this = (VialData_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(VialData_obj), false, "ui.model.VialData"));
			*(void **)__this = VialData_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_b5699a99b5d29ec0_3_new)
HXLINE(   6)		( ( ::ui::model::VialData)(__this) )->position = 0;
HXLINE(   5)		( ( ::ui::model::VialData)(__this) )->maxVialCount = 0;
HXLINE(   4)		( ( ::ui::model::VialData)(__this) )->objectId = 0;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~VialData_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("VialData",48,34,61,6a); }

		int objectId;
		int maxVialCount;
		int position;
};

} // end namespace ui
} // end namespace model

#endif /* INCLUDED_ui_model_VialData */ 