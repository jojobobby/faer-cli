// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_openfl_geom_Vector3D
#include <openfl/geom/Vector3D.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_272ec68939e03fc6_147_new,"openfl.geom.Vector3D","new",0x722c67da,"openfl.geom.Vector3D.new","openfl/geom/Vector3D.hx",147,0xc7821076)
HX_LOCAL_STACK_FRAME(_hx_pos_272ec68939e03fc6_488_get_length,"openfl.geom.Vector3D","get_length",0x8c11b075,"openfl.geom.Vector3D.get_length","openfl/geom/Vector3D.hx",488,0xc7821076)
namespace openfl{
namespace geom{

void Vector3D_obj::__construct(::hx::Null< Float >  __o_x,::hx::Null< Float >  __o_y,::hx::Null< Float >  __o_z,::hx::Null< Float >  __o_w){
            		Float x = __o_x.Default(0);
            		Float y = __o_y.Default(0);
            		Float z = __o_z.Default(0);
            		Float w = __o_w.Default(0);
            	HX_STACKFRAME(&_hx_pos_272ec68939e03fc6_147_new)
HXLINE( 148)		this->w = w;
HXLINE( 149)		this->x = x;
HXLINE( 150)		this->y = y;
HXLINE( 151)		this->z = z;
            	}

Dynamic Vector3D_obj::__CreateEmpty() { return new Vector3D_obj; }

void *Vector3D_obj::_hx_vtable = 0;

Dynamic Vector3D_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Vector3D_obj > _hx_result = new Vector3D_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool Vector3D_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4d8b0de0;
}

Float Vector3D_obj::get_length(){
            	HX_STACKFRAME(&_hx_pos_272ec68939e03fc6_488_get_length)
HXDLIN( 488)		return ::Math_obj::sqrt((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,get_length,return )


::hx::ObjectPtr< Vector3D_obj > Vector3D_obj::__new(::hx::Null< Float >  __o_x,::hx::Null< Float >  __o_y,::hx::Null< Float >  __o_z,::hx::Null< Float >  __o_w) {
	::hx::ObjectPtr< Vector3D_obj > __this = new Vector3D_obj();
	__this->__construct(__o_x,__o_y,__o_z,__o_w);
	return __this;
}

::hx::ObjectPtr< Vector3D_obj > Vector3D_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_x,::hx::Null< Float >  __o_y,::hx::Null< Float >  __o_z,::hx::Null< Float >  __o_w) {
	Vector3D_obj *__this = (Vector3D_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Vector3D_obj), false, "openfl.geom.Vector3D"));
	*(void **)__this = Vector3D_obj::_hx_vtable;
	__this->__construct(__o_x,__o_y,__o_z,__o_w);
	return __this;
}

Vector3D_obj::Vector3D_obj()
{
}

::hx::Val Vector3D_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { return ::hx::Val( w ); }
		if (HX_FIELD_EQ(inName,"x") ) { return ::hx::Val( x ); }
		if (HX_FIELD_EQ(inName,"y") ) { return ::hx::Val( y ); }
		if (HX_FIELD_EQ(inName,"z") ) { return ::hx::Val( z ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_length() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return ::hx::Val( get_length_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Vector3D_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("length",e6,94,07,9f));
	outFields->push(HX_("w",77,00,00,00));
	outFields->push(HX_("x",78,00,00,00));
	outFields->push(HX_("y",79,00,00,00));
	outFields->push(HX_("z",7a,00,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Vector3D_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(Vector3D_obj,w),HX_("w",77,00,00,00)},
	{::hx::fsFloat,(int)offsetof(Vector3D_obj,x),HX_("x",78,00,00,00)},
	{::hx::fsFloat,(int)offsetof(Vector3D_obj,y),HX_("y",79,00,00,00)},
	{::hx::fsFloat,(int)offsetof(Vector3D_obj,z),HX_("z",7a,00,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Vector3D_obj_sStaticStorageInfo = 0;
#endif

static ::String Vector3D_obj_sMemberFields[] = {
	HX_("w",77,00,00,00),
	HX_("x",78,00,00,00),
	HX_("y",79,00,00,00),
	HX_("z",7a,00,00,00),
	HX_("get_length",af,04,8f,8f),
	::String(null()) };

::hx::Class Vector3D_obj::__mClass;

void Vector3D_obj::__register()
{
	Vector3D_obj _hx_dummy;
	Vector3D_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.geom.Vector3D",e8,32,f9,44);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Vector3D_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Vector3D_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Vector3D_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Vector3D_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace geom
