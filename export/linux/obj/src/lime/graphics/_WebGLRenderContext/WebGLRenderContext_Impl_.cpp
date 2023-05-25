// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime__internal_backend_native_NativeOpenGLRenderContext
#include <lime/_internal/backend/native/NativeOpenGLRenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics__WebGL2RenderContext_WebGL2RenderContext_Impl_
#include <lime/graphics/_WebGL2RenderContext/WebGL2RenderContext_Impl_.h>
#endif
#ifndef INCLUDED_lime_graphics__WebGLRenderContext_WebGLRenderContext_Impl_
#include <lime/graphics/_WebGLRenderContext/WebGLRenderContext_Impl_.h>
#endif
#ifndef INCLUDED_lime_utils_ArrayBufferView
#include <lime/utils/ArrayBufferView.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_03d5164364d6a378_81_bufferData,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_","bufferData",0x95dd935f,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_.bufferData","lime/graphics/WebGLRenderContext.hx",81,0x59a06254)
HX_LOCAL_STACK_FRAME(_hx_pos_03d5164364d6a378_147_uniformMatrix2fv,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_","uniformMatrix2fv",0x2c1d1c62,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_.uniformMatrix2fv","lime/graphics/WebGLRenderContext.hx",147,0x59a06254)
HX_LOCAL_STACK_FRAME(_hx_pos_03d5164364d6a378_152_uniformMatrix3fv,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_","uniformMatrix3fv",0x2c1ddea3,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_.uniformMatrix3fv","lime/graphics/WebGLRenderContext.hx",152,0x59a06254)
HX_LOCAL_STACK_FRAME(_hx_pos_03d5164364d6a378_157_uniformMatrix4fv,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_","uniformMatrix4fv",0x2c1ea0e4,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_.uniformMatrix4fv","lime/graphics/WebGLRenderContext.hx",157,0x59a06254)
HX_LOCAL_STACK_FRAME(_hx_pos_03d5164364d6a378_162_fromWebGL2RenderContext,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_","fromWebGL2RenderContext",0x08f222a1,"lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_.fromWebGL2RenderContext","lime/graphics/WebGLRenderContext.hx",162,0x59a06254)
namespace lime{
namespace graphics{
namespace _WebGLRenderContext{

void WebGLRenderContext_Impl__obj::__construct() { }

Dynamic WebGLRenderContext_Impl__obj::__CreateEmpty() { return new WebGLRenderContext_Impl__obj; }

void *WebGLRenderContext_Impl__obj::_hx_vtable = 0;

Dynamic WebGLRenderContext_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< WebGLRenderContext_Impl__obj > _hx_result = new WebGLRenderContext_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool WebGLRenderContext_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x04e3519f;
}

void WebGLRenderContext_Impl__obj::bufferData( ::lime::_internal::backend::native::NativeOpenGLRenderContext this1,int target, ::lime::utils::ArrayBufferView srcData,int usage){
            	HX_STACKFRAME(&_hx_pos_03d5164364d6a378_81_bufferData)
HXDLIN(  81)		::lime::graphics::_WebGL2RenderContext::WebGL2RenderContext_Impl__obj::bufferData(this1,target,srcData,usage,null(),null());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(WebGLRenderContext_Impl__obj,bufferData,(void))

void WebGLRenderContext_Impl__obj::uniformMatrix2fv( ::lime::_internal::backend::native::NativeOpenGLRenderContext this1,int location,bool transpose, ::lime::utils::ArrayBufferView v){
            	HX_STACKFRAME(&_hx_pos_03d5164364d6a378_147_uniformMatrix2fv)
HXDLIN( 147)		::lime::graphics::_WebGL2RenderContext::WebGL2RenderContext_Impl__obj::uniformMatrix2fv(this1,location,transpose,v,null(),null());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(WebGLRenderContext_Impl__obj,uniformMatrix2fv,(void))

void WebGLRenderContext_Impl__obj::uniformMatrix3fv( ::lime::_internal::backend::native::NativeOpenGLRenderContext this1,int location,bool transpose, ::lime::utils::ArrayBufferView v){
            	HX_STACKFRAME(&_hx_pos_03d5164364d6a378_152_uniformMatrix3fv)
HXDLIN( 152)		::lime::graphics::_WebGL2RenderContext::WebGL2RenderContext_Impl__obj::uniformMatrix3fv(this1,location,transpose,v,null(),null());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(WebGLRenderContext_Impl__obj,uniformMatrix3fv,(void))

void WebGLRenderContext_Impl__obj::uniformMatrix4fv( ::lime::_internal::backend::native::NativeOpenGLRenderContext this1,int location,bool transpose, ::lime::utils::ArrayBufferView v){
            	HX_STACKFRAME(&_hx_pos_03d5164364d6a378_157_uniformMatrix4fv)
HXDLIN( 157)		::lime::graphics::_WebGL2RenderContext::WebGL2RenderContext_Impl__obj::uniformMatrix4fv(this1,location,transpose,v,null(),null());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(WebGLRenderContext_Impl__obj,uniformMatrix4fv,(void))

 ::lime::_internal::backend::native::NativeOpenGLRenderContext WebGLRenderContext_Impl__obj::fromWebGL2RenderContext( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl){
            	HX_STACKFRAME(&_hx_pos_03d5164364d6a378_162_fromWebGL2RenderContext)
HXDLIN( 162)		return gl;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(WebGLRenderContext_Impl__obj,fromWebGL2RenderContext,return )


WebGLRenderContext_Impl__obj::WebGLRenderContext_Impl__obj()
{
}

bool WebGLRenderContext_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"bufferData") ) { outValue = bufferData_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"uniformMatrix2fv") ) { outValue = uniformMatrix2fv_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uniformMatrix3fv") ) { outValue = uniformMatrix3fv_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uniformMatrix4fv") ) { outValue = uniformMatrix4fv_dyn(); return true; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"fromWebGL2RenderContext") ) { outValue = fromWebGL2RenderContext_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *WebGLRenderContext_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *WebGLRenderContext_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class WebGLRenderContext_Impl__obj::__mClass;

static ::String WebGLRenderContext_Impl__obj_sStaticFields[] = {
	HX_("bufferData",4a,bf,73,93),
	HX_("uniformMatrix2fv",8d,8a,59,c5),
	HX_("uniformMatrix3fv",ce,4c,5a,c5),
	HX_("uniformMatrix4fv",0f,0f,5b,c5),
	HX_("fromWebGL2RenderContext",d6,9f,b8,97),
	::String(null())
};

void WebGLRenderContext_Impl__obj::__register()
{
	WebGLRenderContext_Impl__obj _hx_dummy;
	WebGLRenderContext_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics._WebGLRenderContext.WebGLRenderContext_Impl_",39,1a,af,6a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &WebGLRenderContext_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(WebGLRenderContext_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< WebGLRenderContext_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = WebGLRenderContext_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = WebGLRenderContext_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace _WebGLRenderContext