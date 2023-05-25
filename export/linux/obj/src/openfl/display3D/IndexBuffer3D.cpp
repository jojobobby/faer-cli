// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_lime__internal_backend_native_NativeCFFI
#include <lime/_internal/backend/native/NativeCFFI.h>
#endif
#ifndef INCLUDED_lime__internal_backend_native_NativeOpenGLRenderContext
#include <lime/_internal/backend/native/NativeOpenGLRenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics__WebGLRenderContext_WebGLRenderContext_Impl_
#include <lime/graphics/_WebGLRenderContext/WebGLRenderContext_Impl_.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl_GLObject
#include <lime/graphics/opengl/GLObject.h>
#endif
#ifndef INCLUDED_lime_utils_ArrayBufferView
#include <lime/utils/ArrayBufferView.h>
#endif
#ifndef INCLUDED_openfl__Vector_IVector
#include <openfl/_Vector/IVector.h>
#endif
#ifndef INCLUDED_openfl__Vector_IntVector
#include <openfl/_Vector/IntVector.h>
#endif
#ifndef INCLUDED_openfl_display3D_Context3D
#include <openfl/display3D/Context3D.h>
#endif
#ifndef INCLUDED_openfl_display3D_IndexBuffer3D
#include <openfl/display3D/IndexBuffer3D.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0f6a02916d47e310_39_new,"openfl.display3D.IndexBuffer3D","new",0x7b4eb39c,"openfl.display3D.IndexBuffer3D.new","openfl/display3D/IndexBuffer3D.hx",39,0x3d934296)
HX_LOCAL_STACK_FRAME(_hx_pos_0f6a02916d47e310_95_uploadFromTypedArray,"openfl.display3D.IndexBuffer3D","uploadFromTypedArray",0x49f635fe,"openfl.display3D.IndexBuffer3D.uploadFromTypedArray","openfl/display3D/IndexBuffer3D.hx",95,0x3d934296)
HX_LOCAL_STACK_FRAME(_hx_pos_0f6a02916d47e310_118_uploadFromVector,"openfl.display3D.IndexBuffer3D","uploadFromVector",0xaabe3672,"openfl.display3D.IndexBuffer3D.uploadFromVector","openfl/display3D/IndexBuffer3D.hx",118,0x3d934296)
namespace openfl{
namespace display3D{

void IndexBuffer3D_obj::__construct( ::openfl::display3D::Context3D context3D,int numIndices, ::Dynamic bufferUsage){
            	HX_GC_STACKFRAME(&_hx_pos_0f6a02916d47e310_39_new)
HXLINE(  40)		this->_hx___context = context3D;
HXLINE(  41)		this->_hx___numIndices = numIndices;
HXLINE(  43)		 ::lime::_internal::backend::native::NativeOpenGLRenderContext gl = this->_hx___context->gl;
HXLINE(  44)		int id = ::lime::_internal::backend::native::NativeCFFI_obj::lime_gl_create_buffer();
HXDLIN(  44)		 ::lime::graphics::opengl::GLObject _hx_tmp;
HXDLIN(  44)		if ((id == 0)) {
HXLINE(  44)			_hx_tmp = null();
            		}
            		else {
HXLINE(  44)			 ::lime::graphics::opengl::GLObject object =  ::lime::graphics::opengl::GLObject_obj::__alloc( HX_CTX ,id);
HXDLIN(  44)			object->ptr = ( ( ::Dynamic)(::lime::_internal::backend::native::NativeCFFI_obj::lime_gl_object_register(id,3,::hx::DynamicPtr(object))) );
HXDLIN(  44)			_hx_tmp = object;
            		}
HXDLIN(  44)		this->_hx___id = _hx_tmp;
HXLINE(  46)		int _hx_tmp1;
HXDLIN(  46)		if (::hx::IsEq( bufferUsage,0 )) {
HXLINE(  46)			_hx_tmp1 = gl->DYNAMIC_DRAW;
            		}
            		else {
HXLINE(  46)			_hx_tmp1 = gl->STATIC_DRAW;
            		}
HXDLIN(  46)		this->_hx___usage = _hx_tmp1;
            	}

Dynamic IndexBuffer3D_obj::__CreateEmpty() { return new IndexBuffer3D_obj; }

void *IndexBuffer3D_obj::_hx_vtable = 0;

Dynamic IndexBuffer3D_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< IndexBuffer3D_obj > _hx_result = new IndexBuffer3D_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool IndexBuffer3D_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x5cf47300;
}

void IndexBuffer3D_obj::uploadFromTypedArray( ::lime::utils::ArrayBufferView data,::hx::Null< int >  __o_byteLength){
            		int byteLength = __o_byteLength.Default(-1);
            	HX_STACKFRAME(&_hx_pos_0f6a02916d47e310_95_uploadFromTypedArray)
HXLINE(  96)		if (::hx::IsNull( data )) {
HXLINE(  96)			return;
            		}
HXLINE(  97)		 ::lime::_internal::backend::native::NativeOpenGLRenderContext gl = this->_hx___context->gl;
HXLINE(  98)		this->_hx___context->_hx___bindGLElementArrayBuffer(this->_hx___id);
HXLINE(  99)		::lime::graphics::_WebGLRenderContext::WebGLRenderContext_Impl__obj::bufferData(gl,gl->ELEMENT_ARRAY_BUFFER,data,this->_hx___usage);
            	}


HX_DEFINE_DYNAMIC_FUNC2(IndexBuffer3D_obj,uploadFromTypedArray,(void))

void IndexBuffer3D_obj::uploadFromVector( ::openfl::_Vector::IntVector data,int startOffset,int count){
            	HX_GC_STACKFRAME(&_hx_pos_0f6a02916d47e310_118_uploadFromVector)
HXLINE( 122)		if (::hx::IsNull( data )) {
HXLINE( 122)			return;
            		}
HXLINE( 125)		int length = (startOffset + count);
HXLINE( 126)		 ::lime::utils::ArrayBufferView existingUInt16Array = this->_hx___tempUInt16Array;
HXLINE( 128)		bool _hx_tmp;
HXDLIN( 128)		if (::hx::IsNotNull( this->_hx___tempUInt16Array )) {
HXLINE( 128)			_hx_tmp = (this->_hx___tempUInt16Array->length < count);
            		}
            		else {
HXLINE( 128)			_hx_tmp = true;
            		}
HXDLIN( 128)		if (_hx_tmp) {
HXLINE( 130)			 ::lime::utils::ArrayBufferView this1;
HXDLIN( 130)			if (::hx::IsNotNull( count )) {
HXLINE( 130)				this1 =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,count,6);
            			}
            			else {
HXLINE( 130)				HX_STACK_DO_THROW(HX_("Invalid constructor arguments for UInt16Array",0a,c7,2d,d5));
            			}
HXDLIN( 130)			this->_hx___tempUInt16Array = this1;
HXLINE( 132)			if (::hx::IsNotNull( existingUInt16Array )) {
HXLINE( 134)				 ::lime::utils::ArrayBufferView _this = this->_hx___tempUInt16Array;
HXDLIN( 134)				bool _hx_tmp1;
HXDLIN( 134)				if (::hx::IsNotNull( existingUInt16Array )) {
HXLINE( 134)					_hx_tmp1 = true;
            				}
            				else {
HXLINE( 134)					_hx_tmp1 = false;
            				}
HXDLIN( 134)				if (_hx_tmp1) {
HXLINE( 134)					_this->buffer->blit((0 * _this->bytesPerElement),existingUInt16Array->buffer,existingUInt16Array->byteOffset,existingUInt16Array->byteLength);
            				}
            				else {
HXLINE( 134)					HX_STACK_DO_THROW(HX_("Invalid .set call. either view, or array must be not-null.",64,ba,b7,6c));
            				}
            			}
            		}
HXLINE( 138)		{
HXLINE( 138)			int _g = startOffset;
HXDLIN( 138)			while((_g < length)){
HXLINE( 138)				_g = (_g + 1);
HXDLIN( 138)				int i = (_g - 1);
HXLINE( 140)				{
HXLINE( 140)					 ::lime::utils::ArrayBufferView this2 = this->_hx___tempUInt16Array;
HXDLIN( 140)					int val = data->get(i);
HXDLIN( 140)					 ::__hxcpp_memory_set_ui16(this2->buffer->b,(this2->byteOffset + ((i - startOffset) * 2)),val);
            				}
            			}
            		}
HXLINE( 143)		this->uploadFromTypedArray(this->_hx___tempUInt16Array,null());
            	}


HX_DEFINE_DYNAMIC_FUNC3(IndexBuffer3D_obj,uploadFromVector,(void))


::hx::ObjectPtr< IndexBuffer3D_obj > IndexBuffer3D_obj::__new( ::openfl::display3D::Context3D context3D,int numIndices, ::Dynamic bufferUsage) {
	::hx::ObjectPtr< IndexBuffer3D_obj > __this = new IndexBuffer3D_obj();
	__this->__construct(context3D,numIndices,bufferUsage);
	return __this;
}

::hx::ObjectPtr< IndexBuffer3D_obj > IndexBuffer3D_obj::__alloc(::hx::Ctx *_hx_ctx, ::openfl::display3D::Context3D context3D,int numIndices, ::Dynamic bufferUsage) {
	IndexBuffer3D_obj *__this = (IndexBuffer3D_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(IndexBuffer3D_obj), true, "openfl.display3D.IndexBuffer3D"));
	*(void **)__this = IndexBuffer3D_obj::_hx_vtable;
	__this->__construct(context3D,numIndices,bufferUsage);
	return __this;
}

IndexBuffer3D_obj::IndexBuffer3D_obj()
{
}

void IndexBuffer3D_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IndexBuffer3D);
	HX_MARK_MEMBER_NAME(_hx___context,"__context");
	HX_MARK_MEMBER_NAME(_hx___id,"__id");
	HX_MARK_MEMBER_NAME(_hx___numIndices,"__numIndices");
	HX_MARK_MEMBER_NAME(_hx___tempUInt16Array,"__tempUInt16Array");
	HX_MARK_MEMBER_NAME(_hx___usage,"__usage");
	HX_MARK_END_CLASS();
}

void IndexBuffer3D_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_hx___context,"__context");
	HX_VISIT_MEMBER_NAME(_hx___id,"__id");
	HX_VISIT_MEMBER_NAME(_hx___numIndices,"__numIndices");
	HX_VISIT_MEMBER_NAME(_hx___tempUInt16Array,"__tempUInt16Array");
	HX_VISIT_MEMBER_NAME(_hx___usage,"__usage");
}

::hx::Val IndexBuffer3D_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"__id") ) { return ::hx::Val( _hx___id ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__usage") ) { return ::hx::Val( _hx___usage ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__context") ) { return ::hx::Val( _hx___context ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__numIndices") ) { return ::hx::Val( _hx___numIndices ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"uploadFromVector") ) { return ::hx::Val( uploadFromVector_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"__tempUInt16Array") ) { return ::hx::Val( _hx___tempUInt16Array ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"uploadFromTypedArray") ) { return ::hx::Val( uploadFromTypedArray_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val IndexBuffer3D_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"__id") ) { _hx___id=inValue.Cast<  ::lime::graphics::opengl::GLObject >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__usage") ) { _hx___usage=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__context") ) { _hx___context=inValue.Cast<  ::openfl::display3D::Context3D >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__numIndices") ) { _hx___numIndices=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"__tempUInt16Array") ) { _hx___tempUInt16Array=inValue.Cast<  ::lime::utils::ArrayBufferView >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IndexBuffer3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("__context",cf,e6,c5,9a));
	outFields->push(HX_("__id",fb,b6,13,3f));
	outFields->push(HX_("__numIndices",a1,00,08,4c));
	outFields->push(HX_("__tempUInt16Array",66,92,c0,bd));
	outFields->push(HX_("__usage",01,b6,8d,14));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo IndexBuffer3D_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::display3D::Context3D */ ,(int)offsetof(IndexBuffer3D_obj,_hx___context),HX_("__context",cf,e6,c5,9a)},
	{::hx::fsObject /*  ::lime::graphics::opengl::GLObject */ ,(int)offsetof(IndexBuffer3D_obj,_hx___id),HX_("__id",fb,b6,13,3f)},
	{::hx::fsInt,(int)offsetof(IndexBuffer3D_obj,_hx___numIndices),HX_("__numIndices",a1,00,08,4c)},
	{::hx::fsObject /*  ::lime::utils::ArrayBufferView */ ,(int)offsetof(IndexBuffer3D_obj,_hx___tempUInt16Array),HX_("__tempUInt16Array",66,92,c0,bd)},
	{::hx::fsInt,(int)offsetof(IndexBuffer3D_obj,_hx___usage),HX_("__usage",01,b6,8d,14)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *IndexBuffer3D_obj_sStaticStorageInfo = 0;
#endif

static ::String IndexBuffer3D_obj_sMemberFields[] = {
	HX_("__context",cf,e6,c5,9a),
	HX_("__id",fb,b6,13,3f),
	HX_("__numIndices",a1,00,08,4c),
	HX_("__tempUInt16Array",66,92,c0,bd),
	HX_("__usage",01,b6,8d,14),
	HX_("uploadFromTypedArray",ba,7c,f4,d1),
	HX_("uploadFromVector",2e,6f,6b,a8),
	::String(null()) };

::hx::Class IndexBuffer3D_obj::__mClass;

void IndexBuffer3D_obj::__register()
{
	IndexBuffer3D_obj _hx_dummy;
	IndexBuffer3D_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.display3D.IndexBuffer3D",aa,f5,d5,3f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(IndexBuffer3D_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< IndexBuffer3D_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = IndexBuffer3D_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = IndexBuffer3D_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace display3D
