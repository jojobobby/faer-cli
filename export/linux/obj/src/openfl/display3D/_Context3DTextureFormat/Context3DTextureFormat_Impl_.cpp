// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_openfl_display3D__Context3DTextureFormat_Context3DTextureFormat_Impl_
#include <openfl/display3D/_Context3DTextureFormat/Context3DTextureFormat_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_ce38ee0aefe74adb_60_toString,"openfl.display3D._Context3DTextureFormat.Context3DTextureFormat_Impl_","toString",0xc7ab9ed2,"openfl.display3D._Context3DTextureFormat.Context3DTextureFormat_Impl_.toString","openfl/display3D/Context3DTextureFormat.hx",60,0xa18085d1)
namespace openfl{
namespace display3D{
namespace _Context3DTextureFormat{

void Context3DTextureFormat_Impl__obj::__construct() { }

Dynamic Context3DTextureFormat_Impl__obj::__CreateEmpty() { return new Context3DTextureFormat_Impl__obj; }

void *Context3DTextureFormat_Impl__obj::_hx_vtable = 0;

Dynamic Context3DTextureFormat_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Context3DTextureFormat_Impl__obj > _hx_result = new Context3DTextureFormat_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Context3DTextureFormat_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7feceabc;
}

::String Context3DTextureFormat_Impl__obj::toString( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_ce38ee0aefe74adb_60_toString)
HXDLIN(  60)		 ::Dynamic _hx_switch_0 = this1;
            		if (  (_hx_switch_0==0) ){
HXLINE(  62)			return HX_("bgrPacked565",6f,69,33,84);
HXDLIN(  62)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==1) ){
HXLINE(  63)			return HX_("bgra",b4,74,15,41);
HXDLIN(  63)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==2) ){
HXLINE(  64)			return HX_("bgraPacked4444",4c,10,af,4f);
HXDLIN(  64)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==3) ){
HXLINE(  65)			return HX_("compressed",81,4c,da,67);
HXDLIN(  65)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==4) ){
HXLINE(  66)			return HX_("compressedAlpha",1d,d7,1f,4a);
HXDLIN(  66)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==5) ){
HXLINE(  67)			return HX_("rgbaHalfFloat",95,5b,55,9e);
HXDLIN(  67)			goto _hx_goto_0;
            		}
            		/* default */{
HXLINE(  68)			return null();
            		}
            		_hx_goto_0:;
HXLINE(  60)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Context3DTextureFormat_Impl__obj,toString,return )


Context3DTextureFormat_Impl__obj::Context3DTextureFormat_Impl__obj()
{
}

bool Context3DTextureFormat_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { outValue = toString_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Context3DTextureFormat_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Context3DTextureFormat_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class Context3DTextureFormat_Impl__obj::__mClass;

static ::String Context3DTextureFormat_Impl__obj_sStaticFields[] = {
	HX_("toString",ac,d0,6e,38),
	::String(null())
};

void Context3DTextureFormat_Impl__obj::__register()
{
	Context3DTextureFormat_Impl__obj _hx_dummy;
	Context3DTextureFormat_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.display3D._Context3DTextureFormat.Context3DTextureFormat_Impl_",08,ef,41,50);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Context3DTextureFormat_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Context3DTextureFormat_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Context3DTextureFormat_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Context3DTextureFormat_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Context3DTextureFormat_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace display3D
} // end namespace _Context3DTextureFormat
