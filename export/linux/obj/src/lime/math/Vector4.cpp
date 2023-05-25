// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_math_Vector4
#include <lime/math/Vector4.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_4684393cb692a867_68_new,"lime.math.Vector4","new",0xd5c0ed36,"lime.math.Vector4.new","lime/math/Vector4.hx",68,0x7257bf5a)
namespace lime{
namespace math{

void Vector4_obj::__construct(::hx::Null< Float >  __o_x,::hx::Null< Float >  __o_y,::hx::Null< Float >  __o_z,::hx::Null< Float >  __o_w){
            		Float x = __o_x.Default(((Float)0.));
            		Float y = __o_y.Default(((Float)0.));
            		Float z = __o_z.Default(((Float)0.));
            		Float w = __o_w.Default(((Float)0.));
            	HX_STACKFRAME(&_hx_pos_4684393cb692a867_68_new)
HXLINE(  69)		this->w = w;
HXLINE(  70)		this->x = x;
HXLINE(  71)		this->y = y;
HXLINE(  72)		this->z = z;
            	}

Dynamic Vector4_obj::__CreateEmpty() { return new Vector4_obj; }

void *Vector4_obj::_hx_vtable = 0;

Dynamic Vector4_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Vector4_obj > _hx_result = new Vector4_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool Vector4_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x38fae9ac;
}


Vector4_obj::Vector4_obj()
{
}

::hx::Val Vector4_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { return ::hx::Val( w ); }
		if (HX_FIELD_EQ(inName,"x") ) { return ::hx::Val( x ); }
		if (HX_FIELD_EQ(inName,"y") ) { return ::hx::Val( y ); }
		if (HX_FIELD_EQ(inName,"z") ) { return ::hx::Val( z ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Vector4_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
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

void Vector4_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("w",77,00,00,00));
	outFields->push(HX_("x",78,00,00,00));
	outFields->push(HX_("y",79,00,00,00));
	outFields->push(HX_("z",7a,00,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Vector4_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(Vector4_obj,w),HX_("w",77,00,00,00)},
	{::hx::fsFloat,(int)offsetof(Vector4_obj,x),HX_("x",78,00,00,00)},
	{::hx::fsFloat,(int)offsetof(Vector4_obj,y),HX_("y",79,00,00,00)},
	{::hx::fsFloat,(int)offsetof(Vector4_obj,z),HX_("z",7a,00,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Vector4_obj_sStaticStorageInfo = 0;
#endif

static ::String Vector4_obj_sMemberFields[] = {
	HX_("w",77,00,00,00),
	HX_("x",78,00,00,00),
	HX_("y",79,00,00,00),
	HX_("z",7a,00,00,00),
	::String(null()) };

::hx::Class Vector4_obj::__mClass;

void Vector4_obj::__register()
{
	Vector4_obj _hx_dummy;
	Vector4_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.math.Vector4",44,da,50,4d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Vector4_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Vector4_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Vector4_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Vector4_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace math
