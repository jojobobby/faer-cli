// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_mapeditor_FillData
#include <mapeditor/FillData.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f188b45f4628fcd3_36_new,"mapeditor.FillData","new",0xeb127024,"mapeditor.FillData.new","mapeditor/EditingScreen.hx",36,0x58b10980)
namespace mapeditor{

void FillData_obj::__construct(int x1,int x2,int y,int dy){
            	HX_STACKFRAME(&_hx_pos_f188b45f4628fcd3_36_new)
HXDLIN(  36)		this->x1 = x1;
HXDLIN(  36)		this->x2 = x2;
HXDLIN(  36)		this->y = y;
HXDLIN(  36)		this->dy = dy;
            	}

Dynamic FillData_obj::__CreateEmpty() { return new FillData_obj; }

void *FillData_obj::_hx_vtable = 0;

Dynamic FillData_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FillData_obj > _hx_result = new FillData_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool FillData_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x45b18e12;
}


FillData_obj::FillData_obj()
{
}

::hx::Val FillData_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return ::hx::Val( y ); }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"x1") ) { return ::hx::Val( x1 ); }
		if (HX_FIELD_EQ(inName,"x2") ) { return ::hx::Val( x2 ); }
		if (HX_FIELD_EQ(inName,"dy") ) { return ::hx::Val( dy ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FillData_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< int >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"x1") ) { x1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x2") ) { x2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dy") ) { dy=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FillData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("x1",b9,68,00,00));
	outFields->push(HX_("x2",ba,68,00,00));
	outFields->push(HX_("y",79,00,00,00));
	outFields->push(HX_("dy",95,57,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FillData_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(FillData_obj,x1),HX_("x1",b9,68,00,00)},
	{::hx::fsInt,(int)offsetof(FillData_obj,x2),HX_("x2",ba,68,00,00)},
	{::hx::fsInt,(int)offsetof(FillData_obj,y),HX_("y",79,00,00,00)},
	{::hx::fsInt,(int)offsetof(FillData_obj,dy),HX_("dy",95,57,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *FillData_obj_sStaticStorageInfo = 0;
#endif

static ::String FillData_obj_sMemberFields[] = {
	HX_("x1",b9,68,00,00),
	HX_("x2",ba,68,00,00),
	HX_("y",79,00,00,00),
	HX_("dy",95,57,00,00),
	::String(null()) };

::hx::Class FillData_obj::__mClass;

void FillData_obj::__register()
{
	FillData_obj _hx_dummy;
	FillData_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("mapeditor.FillData",32,ce,ce,77);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FillData_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FillData_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FillData_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FillData_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mapeditor