// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_account_ChangePasswordData
#include <account/ChangePasswordData.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f89c1b53f34b5008_3_new,"account.ChangePasswordData","new",0x1b9453a8,"account.ChangePasswordData.new","account/ChangePasswordData.hx",3,0xa4dc2327)
namespace account{

void ChangePasswordData_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_f89c1b53f34b5008_3_new)
HXLINE(   5)		this->newPassword = HX_("",00,00,00,00);
HXLINE(   4)		this->currentPassword = HX_("",00,00,00,00);
            	}

Dynamic ChangePasswordData_obj::__CreateEmpty() { return new ChangePasswordData_obj; }

void *ChangePasswordData_obj::_hx_vtable = 0;

Dynamic ChangePasswordData_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ChangePasswordData_obj > _hx_result = new ChangePasswordData_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool ChangePasswordData_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x446121c2;
}


ChangePasswordData_obj::ChangePasswordData_obj()
{
}

void ChangePasswordData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ChangePasswordData);
	HX_MARK_MEMBER_NAME(currentPassword,"currentPassword");
	HX_MARK_MEMBER_NAME(newPassword,"newPassword");
	HX_MARK_END_CLASS();
}

void ChangePasswordData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(currentPassword,"currentPassword");
	HX_VISIT_MEMBER_NAME(newPassword,"newPassword");
}

::hx::Val ChangePasswordData_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"newPassword") ) { return ::hx::Val( newPassword ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"currentPassword") ) { return ::hx::Val( currentPassword ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ChangePasswordData_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"newPassword") ) { newPassword=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"currentPassword") ) { currentPassword=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ChangePasswordData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("currentPassword",74,dc,21,1d));
	outFields->push(HX_("newPassword",9b,0f,ad,6d));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ChangePasswordData_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(ChangePasswordData_obj,currentPassword),HX_("currentPassword",74,dc,21,1d)},
	{::hx::fsString,(int)offsetof(ChangePasswordData_obj,newPassword),HX_("newPassword",9b,0f,ad,6d)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ChangePasswordData_obj_sStaticStorageInfo = 0;
#endif

static ::String ChangePasswordData_obj_sMemberFields[] = {
	HX_("currentPassword",74,dc,21,1d),
	HX_("newPassword",9b,0f,ad,6d),
	::String(null()) };

::hx::Class ChangePasswordData_obj::__mClass;

void ChangePasswordData_obj::__register()
{
	ChangePasswordData_obj _hx_dummy;
	ChangePasswordData_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("account.ChangePasswordData",b6,9f,2f,38);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ChangePasswordData_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ChangePasswordData_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ChangePasswordData_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ChangePasswordData_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace account