// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_ui_MouseCursor
#include <lime/ui/MouseCursor.h>
#endif
#ifndef INCLUDED_openfl_ui__MouseCursor_MouseCursor_Impl_
#include <openfl/ui/_MouseCursor/MouseCursor_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_5ef75db01c4e3075_74_toLimeCursor,"openfl.ui._MouseCursor.MouseCursor_Impl_","toLimeCursor",0xdd84694f,"openfl.ui._MouseCursor.MouseCursor_Impl_.toLimeCursor","openfl/ui/MouseCursor.hx",74,0xebae9dff)
namespace openfl{
namespace ui{
namespace _MouseCursor{

void MouseCursor_Impl__obj::__construct() { }

Dynamic MouseCursor_Impl__obj::__CreateEmpty() { return new MouseCursor_Impl__obj; }

void *MouseCursor_Impl__obj::_hx_vtable = 0;

Dynamic MouseCursor_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< MouseCursor_Impl__obj > _hx_result = new MouseCursor_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool MouseCursor_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x38005e17;
}

 ::lime::ui::MouseCursor MouseCursor_Impl__obj::toLimeCursor(::String this1){
            	HX_STACKFRAME(&_hx_pos_5ef75db01c4e3075_74_toLimeCursor)
HXDLIN(  74)		::String _hx_switch_0 = this1;
            		if (  (_hx_switch_0==HX_("arrow",c9,79,8f,25)) ){
HXLINE(  76)			return ::lime::ui::MouseCursor_obj::ARROW_dyn();
HXDLIN(  76)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("auto",6f,df,76,40)) ){
HXLINE(  77)			return ::lime::ui::MouseCursor_obj::DEFAULT_dyn();
HXDLIN(  77)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("button",f2,61,e0,d9)) ){
HXLINE(  78)			return ::lime::ui::MouseCursor_obj::POINTER_dyn();
HXDLIN(  78)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("crosshair",a2,46,c8,8a)) ){
HXLINE(  81)			return ::lime::ui::MouseCursor_obj::CROSSHAIR_dyn();
HXDLIN(  81)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("custom",b1,87,92,3f)) ){
HXLINE(  88)			return ::lime::ui::MouseCursor_obj::CUSTOM_dyn();
HXDLIN(  88)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("hand",6f,2b,08,45)) ){
HXLINE(  79)			return ::lime::ui::MouseCursor_obj::MOVE_dyn();
HXDLIN(  79)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("ibeam",58,ca,26,b6)) ){
HXLINE(  80)			return ::lime::ui::MouseCursor_obj::TEXT_dyn();
HXDLIN(  80)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("resize_nesw",06,ae,e9,a7)) ){
HXLINE(  82)			return ::lime::ui::MouseCursor_obj::RESIZE_NESW_dyn();
HXDLIN(  82)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("resize_ns",f0,cc,f2,ab)) ){
HXLINE(  83)			return ::lime::ui::MouseCursor_obj::RESIZE_NS_dyn();
HXDLIN(  83)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("resize_nwse",86,56,f7,a7)) ){
HXLINE(  84)			return ::lime::ui::MouseCursor_obj::RESIZE_NWSE_dyn();
HXDLIN(  84)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("resize_we",b9,d4,f2,ab)) ){
HXLINE(  85)			return ::lime::ui::MouseCursor_obj::RESIZE_WE_dyn();
HXDLIN(  85)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("wait",75,5a,f2,4e)) ){
HXLINE(  86)			return ::lime::ui::MouseCursor_obj::WAIT_dyn();
HXDLIN(  86)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("waitarrow",34,17,98,4f)) ){
HXLINE(  87)			return ::lime::ui::MouseCursor_obj::WAIT_ARROW_dyn();
HXDLIN(  87)			goto _hx_goto_0;
            		}
            		/* default */{
HXLINE(  89)			return ::lime::ui::MouseCursor_obj::DEFAULT_dyn();
            		}
            		_hx_goto_0:;
HXLINE(  74)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MouseCursor_Impl__obj,toLimeCursor,return )


MouseCursor_Impl__obj::MouseCursor_Impl__obj()
{
}

bool MouseCursor_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"toLimeCursor") ) { outValue = toLimeCursor_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *MouseCursor_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *MouseCursor_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class MouseCursor_Impl__obj::__mClass;

static ::String MouseCursor_Impl__obj_sStaticFields[] = {
	HX_("toLimeCursor",26,49,3d,7c),
	::String(null())
};

void MouseCursor_Impl__obj::__register()
{
	MouseCursor_Impl__obj _hx_dummy;
	MouseCursor_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.ui._MouseCursor.MouseCursor_Impl_",e5,61,b2,51);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &MouseCursor_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(MouseCursor_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< MouseCursor_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = MouseCursor_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = MouseCursor_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace ui
} // end namespace _MouseCursor
