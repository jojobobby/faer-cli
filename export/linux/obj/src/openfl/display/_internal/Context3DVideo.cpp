// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectRenderer
#include <openfl/display/DisplayObjectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_OpenGLRenderer
#include <openfl/display/OpenGLRenderer.h>
#endif
#ifndef INCLUDED_openfl_display__internal_Context3DVideo
#include <openfl/display/_internal/Context3DVideo.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_media_Video
#include <openfl/media/Video.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_83dc6c86a6c9c25b_98_renderDrawable,"openfl.display._internal.Context3DVideo","renderDrawable",0x20d4afab,"openfl.display._internal.Context3DVideo.renderDrawable","openfl/display/_internal/Context3DVideo.hx",98,0x07ba4844)
HX_LOCAL_STACK_FRAME(_hx_pos_83dc6c86a6c9c25b_20_boot,"openfl.display._internal.Context3DVideo","boot",0x10f20809,"openfl.display._internal.Context3DVideo.boot","openfl/display/_internal/Context3DVideo.hx",20,0x07ba4844)
namespace openfl{
namespace display{
namespace _internal{

void Context3DVideo_obj::__construct() { }

Dynamic Context3DVideo_obj::__CreateEmpty() { return new Context3DVideo_obj; }

void *Context3DVideo_obj::_hx_vtable = 0;

Dynamic Context3DVideo_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Context3DVideo_obj > _hx_result = new Context3DVideo_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Context3DVideo_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4de6ab29;
}

void Context3DVideo_obj::renderDrawable( ::openfl::media::Video video, ::openfl::display::OpenGLRenderer renderer){
            	HX_STACKFRAME(&_hx_pos_83dc6c86a6c9c25b_98_renderDrawable)
HXDLIN(  98)		renderer->_hx___renderEvent(video);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Context3DVideo_obj,renderDrawable,(void))


Context3DVideo_obj::Context3DVideo_obj()
{
}

bool Context3DVideo_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"renderDrawable") ) { outValue = renderDrawable_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Context3DVideo_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Context3DVideo_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Context3DVideo_obj::__mClass;

static ::String Context3DVideo_obj_sStaticFields[] = {
	HX_("renderDrawable",14,59,d0,dd),
	::String(null())
};

void Context3DVideo_obj::__register()
{
	Context3DVideo_obj _hx_dummy;
	Context3DVideo_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.display._internal.Context3DVideo",f7,6b,1a,00);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Context3DVideo_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Context3DVideo_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Context3DVideo_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Context3DVideo_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Context3DVideo_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Context3DVideo_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_83dc6c86a6c9c25b_20_boot)
HXDLIN(  20)		__mClass->__meta__ =  ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("obj",f7,8f,54,00), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("SuppressWarnings",0c,d3,d2,00),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("checkstyle:FieldDocComment",70,56,1b,20))))));
            	}
}

} // end namespace openfl
} // end namespace display
} // end namespace _internal
