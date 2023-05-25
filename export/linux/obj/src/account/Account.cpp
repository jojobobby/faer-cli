// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_account_Account
#include <account/Account.h>
#endif
#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_e7d45e778ea2c685_10_updateUser,"account.Account","updateUser",0x4218e656,"account.Account.updateUser","account/Account.hx",10,0x999bfdb3)
HX_LOCAL_STACK_FRAME(_hx_pos_e7d45e778ea2c685_21_clear,"account.Account","clear",0x1f41836b,"account.Account.clear","account/Account.hx",21,0x999bfdb3)
HX_LOCAL_STACK_FRAME(_hx_pos_e7d45e778ea2c685_6_boot,"account.Account","boot",0xed1ed814,"account.Account.boot","account/Account.hx",6,0x999bfdb3)
HX_LOCAL_STACK_FRAME(_hx_pos_e7d45e778ea2c685_7_boot,"account.Account","boot",0xed1ed814,"account.Account.boot","account/Account.hx",7,0x999bfdb3)
HX_LOCAL_STACK_FRAME(_hx_pos_e7d45e778ea2c685_8_boot,"account.Account","boot",0xed1ed814,"account.Account.boot","account/Account.hx",8,0x999bfdb3)
namespace account{

void Account_obj::__construct() { }

Dynamic Account_obj::__CreateEmpty() { return new Account_obj; }

void *Account_obj::_hx_vtable = 0;

Dynamic Account_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Account_obj > _hx_result = new Account_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Account_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x30860240;
}

::String Account_obj::userName;

::String Account_obj::email;

::String Account_obj::password;

void Account_obj::updateUser(::String newName,::String newEmail,::String newPassword){
            	HX_STACKFRAME(&_hx_pos_e7d45e778ea2c685_10_updateUser)
HXLINE(  11)		::account::Account_obj::userName = newName;
HXLINE(  12)		::account::Account_obj::email = newEmail;
HXLINE(  13)		::account::Account_obj::password = newPassword;
HXLINE(  15)		 ::sys::io::FileOutput w = ::sys::io::File_obj::write(HX_("login",69,d9,f3,78),null());
HXLINE(  16)		w->writeString((((((HX_("name=>",6c,10,79,1d) + ::account::Account_obj::userName) + HX_("\nemail=>",b3,78,6e,58)) + ::account::Account_obj::email) + HX_("\npassword=>",c6,c5,23,40)) + ::account::Account_obj::password),null());
HXLINE(  17)		w->close();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Account_obj,updateUser,(void))

void Account_obj::clear(){
            	HX_STACKFRAME(&_hx_pos_e7d45e778ea2c685_21_clear)
HXDLIN(  21)		::account::Account_obj::updateUser(HX_("Guest",b8,2e,16,2f),HX_("",00,00,00,00),HX_("",00,00,00,00));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Account_obj,clear,(void))


Account_obj::Account_obj()
{
}

bool Account_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"email") ) { outValue = ( email ); return true; }
		if (HX_FIELD_EQ(inName,"clear") ) { outValue = clear_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userName") ) { outValue = ( userName ); return true; }
		if (HX_FIELD_EQ(inName,"password") ) { outValue = ( password ); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateUser") ) { outValue = updateUser_dyn(); return true; }
	}
	return false;
}

bool Account_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"email") ) { email=ioValue.Cast< ::String >(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userName") ) { userName=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"password") ) { password=ioValue.Cast< ::String >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Account_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo Account_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &Account_obj::userName,HX_("userName",36,b2,c4,0b)},
	{::hx::fsString,(void *) &Account_obj::email,HX_("email",1c,cf,ce,6f)},
	{::hx::fsString,(void *) &Account_obj::password,HX_("password",1b,23,d0,48)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Account_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Account_obj::userName,"userName");
	HX_MARK_MEMBER_NAME(Account_obj::email,"email");
	HX_MARK_MEMBER_NAME(Account_obj::password,"password");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Account_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Account_obj::userName,"userName");
	HX_VISIT_MEMBER_NAME(Account_obj::email,"email");
	HX_VISIT_MEMBER_NAME(Account_obj::password,"password");
};

#endif

::hx::Class Account_obj::__mClass;

static ::String Account_obj_sStaticFields[] = {
	HX_("userName",36,b2,c4,0b),
	HX_("email",1c,cf,ce,6f),
	HX_("password",1b,23,d0,48),
	HX_("updateUser",f4,7c,62,06),
	HX_("clear",8d,71,5b,48),
	::String(null())
};

void Account_obj::__register()
{
	Account_obj _hx_dummy;
	Account_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("account.Account",cc,97,95,08);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Account_obj::__GetStatic;
	__mClass->mSetStaticField = &Account_obj::__SetStatic;
	__mClass->mMarkFunc = Account_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Account_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Account_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Account_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Account_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Account_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Account_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_e7d45e778ea2c685_6_boot)
HXDLIN(   6)		userName = HX_("",00,00,00,00);
            	}
{
            	HX_STACKFRAME(&_hx_pos_e7d45e778ea2c685_7_boot)
HXDLIN(   7)		email = HX_("",00,00,00,00);
            	}
{
            	HX_STACKFRAME(&_hx_pos_e7d45e778ea2c685_8_boot)
HXDLIN(   8)		password = HX_("",00,00,00,00);
            	}
}

} // end namespace account