// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_ext_OES_EGL_image_external
#include <lime/graphics/opengl/ext/OES_EGL_image_external.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_a78482bd5914f663_4_new,"lime.graphics.opengl.ext.OES_EGL_image_external","new",0x7e01d1fa,"lime.graphics.opengl.ext.OES_EGL_image_external.new","lime/graphics/opengl/ext/OES_EGL_image_external.hx",4,0xf55619d4)
namespace lime{
namespace graphics{
namespace opengl{
namespace ext{

void OES_EGL_image_external_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_a78482bd5914f663_4_new)
HXLINE(   9)		this->REQUIRED_TEXTURE_IMAGE_UNITS_OES = 36200;
HXLINE(   8)		this->TEXTURE_BINDING_EXTERNAL_OES = 36199;
HXLINE(   7)		this->SAMPLER_EXTERNAL_OES = 36198;
HXLINE(   6)		this->TEXTURE_EXTERNAL_OES = 36197;
            	}

Dynamic OES_EGL_image_external_obj::__CreateEmpty() { return new OES_EGL_image_external_obj; }

void *OES_EGL_image_external_obj::_hx_vtable = 0;

Dynamic OES_EGL_image_external_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< OES_EGL_image_external_obj > _hx_result = new OES_EGL_image_external_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool OES_EGL_image_external_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x2b0e9d74;
}


OES_EGL_image_external_obj::OES_EGL_image_external_obj()
{
}

::hx::Val OES_EGL_image_external_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"TEXTURE_EXTERNAL_OES") ) { return ::hx::Val( TEXTURE_EXTERNAL_OES ); }
		if (HX_FIELD_EQ(inName,"SAMPLER_EXTERNAL_OES") ) { return ::hx::Val( SAMPLER_EXTERNAL_OES ); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"TEXTURE_BINDING_EXTERNAL_OES") ) { return ::hx::Val( TEXTURE_BINDING_EXTERNAL_OES ); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"REQUIRED_TEXTURE_IMAGE_UNITS_OES") ) { return ::hx::Val( REQUIRED_TEXTURE_IMAGE_UNITS_OES ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val OES_EGL_image_external_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"TEXTURE_EXTERNAL_OES") ) { TEXTURE_EXTERNAL_OES=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SAMPLER_EXTERNAL_OES") ) { SAMPLER_EXTERNAL_OES=inValue.Cast< int >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"TEXTURE_BINDING_EXTERNAL_OES") ) { TEXTURE_BINDING_EXTERNAL_OES=inValue.Cast< int >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"REQUIRED_TEXTURE_IMAGE_UNITS_OES") ) { REQUIRED_TEXTURE_IMAGE_UNITS_OES=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void OES_EGL_image_external_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("TEXTURE_EXTERNAL_OES",8d,24,93,6b));
	outFields->push(HX_("SAMPLER_EXTERNAL_OES",40,50,34,6c));
	outFields->push(HX_("TEXTURE_BINDING_EXTERNAL_OES",27,e9,a2,b6));
	outFields->push(HX_("REQUIRED_TEXTURE_IMAGE_UNITS_OES",25,2a,48,aa));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo OES_EGL_image_external_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(OES_EGL_image_external_obj,TEXTURE_EXTERNAL_OES),HX_("TEXTURE_EXTERNAL_OES",8d,24,93,6b)},
	{::hx::fsInt,(int)offsetof(OES_EGL_image_external_obj,SAMPLER_EXTERNAL_OES),HX_("SAMPLER_EXTERNAL_OES",40,50,34,6c)},
	{::hx::fsInt,(int)offsetof(OES_EGL_image_external_obj,TEXTURE_BINDING_EXTERNAL_OES),HX_("TEXTURE_BINDING_EXTERNAL_OES",27,e9,a2,b6)},
	{::hx::fsInt,(int)offsetof(OES_EGL_image_external_obj,REQUIRED_TEXTURE_IMAGE_UNITS_OES),HX_("REQUIRED_TEXTURE_IMAGE_UNITS_OES",25,2a,48,aa)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *OES_EGL_image_external_obj_sStaticStorageInfo = 0;
#endif

static ::String OES_EGL_image_external_obj_sMemberFields[] = {
	HX_("TEXTURE_EXTERNAL_OES",8d,24,93,6b),
	HX_("SAMPLER_EXTERNAL_OES",40,50,34,6c),
	HX_("TEXTURE_BINDING_EXTERNAL_OES",27,e9,a2,b6),
	HX_("REQUIRED_TEXTURE_IMAGE_UNITS_OES",25,2a,48,aa),
	::String(null()) };

::hx::Class OES_EGL_image_external_obj::__mClass;

void OES_EGL_image_external_obj::__register()
{
	OES_EGL_image_external_obj _hx_dummy;
	OES_EGL_image_external_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl.ext.OES_EGL_image_external",08,0d,07,ff);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(OES_EGL_image_external_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< OES_EGL_image_external_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = OES_EGL_image_external_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = OES_EGL_image_external_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext
