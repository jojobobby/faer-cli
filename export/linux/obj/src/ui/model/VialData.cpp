// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_ui_model_VialData
#include <ui/model/VialData.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b5699a99b5d29ec0_3_new,"ui.model.VialData","new",0x8fa82ef9,"ui.model.VialData.new","ui/model/VialData.hx",3,0xf57fef15)
namespace ui{
namespace model{

void VialData_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_b5699a99b5d29ec0_3_new)
HXLINE(   6)		this->position = 0;
HXLINE(   5)		this->maxVialCount = 0;
HXLINE(   4)		this->objectId = 0;
            	}

Dynamic VialData_obj::__CreateEmpty() { return new VialData_obj; }

void *VialData_obj::_hx_vtable = 0;

Dynamic VialData_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< VialData_obj > _hx_result = new VialData_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool VialData_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x45897d9d;
}


VialData_obj::VialData_obj()
{
}

::hx::Val VialData_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"objectId") ) { return ::hx::Val( objectId ); }
		if (HX_FIELD_EQ(inName,"position") ) { return ::hx::Val( position ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"maxVialCount") ) { return ::hx::Val( maxVialCount ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val VialData_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"objectId") ) { objectId=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"maxVialCount") ) { maxVialCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VialData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("objectId",7a,2c,2c,83));
	outFields->push(HX_("maxVialCount",cd,41,38,16));
	outFields->push(HX_("position",a9,a0,fa,ca));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo VialData_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(VialData_obj,objectId),HX_("objectId",7a,2c,2c,83)},
	{::hx::fsInt,(int)offsetof(VialData_obj,maxVialCount),HX_("maxVialCount",cd,41,38,16)},
	{::hx::fsInt,(int)offsetof(VialData_obj,position),HX_("position",a9,a0,fa,ca)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *VialData_obj_sStaticStorageInfo = 0;
#endif

static ::String VialData_obj_sMemberFields[] = {
	HX_("objectId",7a,2c,2c,83),
	HX_("maxVialCount",cd,41,38,16),
	HX_("position",a9,a0,fa,ca),
	::String(null()) };

::hx::Class VialData_obj::__mClass;

void VialData_obj::__register()
{
	VialData_obj _hx_dummy;
	VialData_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.model.VialData",87,3e,5d,6b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(VialData_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< VialData_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = VialData_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = VialData_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace model