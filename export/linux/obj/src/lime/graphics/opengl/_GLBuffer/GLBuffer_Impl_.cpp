// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_GLObject
#include <lime/graphics/opengl/GLObject.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl__GLBuffer_GLBuffer_Impl_
#include <lime/graphics/opengl/_GLBuffer/GLBuffer_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_0f2401efb1b32638_12_fromInt,"lime.graphics.opengl._GLBuffer.GLBuffer_Impl_","fromInt",0x6ac84e1b,"lime.graphics.opengl._GLBuffer.GLBuffer_Impl_.fromInt","lime/graphics/opengl/GLBuffer.hx",12,0xd18082c3)
namespace lime{
namespace graphics{
namespace opengl{
namespace _GLBuffer{

void GLBuffer_Impl__obj::__construct() { }

Dynamic GLBuffer_Impl__obj::__CreateEmpty() { return new GLBuffer_Impl__obj; }

void *GLBuffer_Impl__obj::_hx_vtable = 0;

Dynamic GLBuffer_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GLBuffer_Impl__obj > _hx_result = new GLBuffer_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool GLBuffer_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x74fd3192;
}

 ::lime::graphics::opengl::GLObject GLBuffer_Impl__obj::fromInt(int id){
            	HX_STACKFRAME(&_hx_pos_0f2401efb1b32638_12_fromInt)
HXDLIN(  12)		return ::lime::graphics::opengl::GLObject_obj::fromInt(3,id);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GLBuffer_Impl__obj,fromInt,return )


GLBuffer_Impl__obj::GLBuffer_Impl__obj()
{
}

bool GLBuffer_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"fromInt") ) { outValue = fromInt_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GLBuffer_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *GLBuffer_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class GLBuffer_Impl__obj::__mClass;

static ::String GLBuffer_Impl__obj_sStaticFields[] = {
	HX_("fromInt",a5,dd,fa,57),
	::String(null())
};

void GLBuffer_Impl__obj::__register()
{
	GLBuffer_Impl__obj _hx_dummy;
	GLBuffer_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl._GLBuffer.GLBuffer_Impl_",e4,6a,41,4e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GLBuffer_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(GLBuffer_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< GLBuffer_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GLBuffer_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GLBuffer_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace _GLBuffer
