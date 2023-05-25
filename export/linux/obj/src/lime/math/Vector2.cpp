// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_math_Vector2
#include <lime/math/Vector2.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_c8980fb157cd0afb_47_new,"lime.math.Vector2","new",0xaef3c434,"lime.math.Vector2.new","lime/math/Vector2.hx",47,0x7105521c)
HX_LOCAL_STACK_FRAME(_hx_pos_c8980fb157cd0afb_137_offset,"lime.math.Vector2","offset",0x89fac03f,"lime.math.Vector2.offset","lime/math/Vector2.hx",137,0x7105521c)
HX_LOCAL_STACK_FRAME(_hx_pos_c8980fb157cd0afb_185___toFlashPoint,"lime.math.Vector2","__toFlashPoint",0xf695b9a7,"lime.math.Vector2.__toFlashPoint","lime/math/Vector2.hx",185,0x7105521c)
namespace lime{
namespace math{

void Vector2_obj::__construct(::hx::Null< Float >  __o_x,::hx::Null< Float >  __o_y){
            		Float x = __o_x.Default(0);
            		Float y = __o_y.Default(0);
            	HX_STACKFRAME(&_hx_pos_c8980fb157cd0afb_47_new)
HXLINE(  48)		this->x = x;
HXLINE(  49)		this->y = y;
            	}

Dynamic Vector2_obj::__CreateEmpty() { return new Vector2_obj; }

void *Vector2_obj::_hx_vtable = 0;

Dynamic Vector2_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Vector2_obj > _hx_result = new Vector2_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Vector2_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x38fae9aa;
}

void Vector2_obj::offset(Float dx,Float dy){
            	HX_STACKFRAME(&_hx_pos_c8980fb157cd0afb_137_offset)
HXLINE( 138)		this->x = (this->x + dx);
HXLINE( 139)		this->y = (this->y + dy);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,offset,(void))

 ::Dynamic Vector2_obj::_hx___toFlashPoint(){
            	HX_STACKFRAME(&_hx_pos_c8980fb157cd0afb_185___toFlashPoint)
HXDLIN( 185)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,_hx___toFlashPoint,return )


Vector2_obj::Vector2_obj()
{
}

::hx::Val Vector2_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return ::hx::Val( x ); }
		if (HX_FIELD_EQ(inName,"y") ) { return ::hx::Val( y ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return ::hx::Val( offset_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__toFlashPoint") ) { return ::hx::Val( _hx___toFlashPoint_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Vector2_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("x",78,00,00,00));
	outFields->push(HX_("y",79,00,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Vector2_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(Vector2_obj,x),HX_("x",78,00,00,00)},
	{::hx::fsFloat,(int)offsetof(Vector2_obj,y),HX_("y",79,00,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Vector2_obj_sStaticStorageInfo = 0;
#endif

static ::String Vector2_obj_sMemberFields[] = {
	HX_("x",78,00,00,00),
	HX_("y",79,00,00,00),
	HX_("offset",93,97,3f,60),
	HX_("__toFlashPoint",fb,04,40,a7),
	::String(null()) };

::hx::Class Vector2_obj::__mClass;

void Vector2_obj::__register()
{
	Vector2_obj _hx_dummy;
	Vector2_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.math.Vector2",42,da,50,4d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Vector2_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Vector2_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Vector2_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Vector2_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace math
