// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_system_CFFI
#include <lime/system/CFFI.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_a915f6dcce8b5bed_25___init__,"::lime::_hx_system::CFFI_obj","__init__",0xd08dc78c,"::lime::_hx_system::CFFI_obj.__init__","lime/system/CFFI.hx",25,0x441ad672)
namespace lime{
namespace _hx_system{

void CFFI_obj::__construct() { }

Dynamic CFFI_obj::__CreateEmpty() { return new CFFI_obj; }

void *CFFI_obj::_hx_vtable = 0;

Dynamic CFFI_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CFFI_obj > _hx_result = new CFFI_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CFFI_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x277adf4e;
}

void CFFI_obj::__init__(){
            	HX_STACKFRAME(&_hx_pos_a915f6dcce8b5bed_25___init__)
HXLINE(  27)		::lime::_hx_system::CFFI_obj::available = true;
HXLINE(  28)		::lime::_hx_system::CFFI_obj::enabled = true;
            	}


bool CFFI_obj::available;

bool CFFI_obj::enabled;


CFFI_obj::CFFI_obj()
{
}

bool CFFI_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { outValue = ( enabled ); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"available") ) { outValue = ( available ); return true; }
	}
	return false;
}

bool CFFI_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=ioValue.Cast< bool >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"available") ) { available=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *CFFI_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo CFFI_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &CFFI_obj::available,HX_("available",c9,59,83,77)},
	{::hx::fsBool,(void *) &CFFI_obj::enabled,HX_("enabled",81,04,31,7e)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void CFFI_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CFFI_obj::available,"available");
	HX_MARK_MEMBER_NAME(CFFI_obj::enabled,"enabled");
};

#ifdef HXCPP_VISIT_ALLOCS
static void CFFI_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CFFI_obj::available,"available");
	HX_VISIT_MEMBER_NAME(CFFI_obj::enabled,"enabled");
};

#endif

::hx::Class CFFI_obj::__mClass;

static ::String CFFI_obj_sStaticFields[] = {
	HX_("available",c9,59,83,77),
	HX_("enabled",81,04,31,7e),
	::String(null())
};

void CFFI_obj::__register()
{
	CFFI_obj _hx_dummy;
	CFFI_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.system.CFFI",ac,d1,df,76);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &CFFI_obj::__GetStatic;
	__mClass->mSetStaticField = &CFFI_obj::__SetStatic;
	__mClass->mMarkFunc = CFFI_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(CFFI_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< CFFI_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = CFFI_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CFFI_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CFFI_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void CFFI_obj::__boot()
{
}

} // end namespace lime
} // end namespace system
