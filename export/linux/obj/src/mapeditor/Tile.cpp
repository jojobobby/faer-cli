// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_mapeditor_Tile
#include <mapeditor/Tile.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_acb18d22a29caa16_49_new,"mapeditor.Tile","new",0x82421b05,"mapeditor.Tile.new","mapeditor/EditingScreen.hx",49,0x58b10980)
namespace mapeditor{

void Tile_obj::__construct(unsigned short tileType,unsigned short objType,unsigned char regionType){
            	HX_STACKFRAME(&_hx_pos_acb18d22a29caa16_49_new)
HXLINE(  50)		this->tileType = tileType;
HXLINE(  51)		this->objType = objType;
HXLINE(  52)		this->regionType = regionType;
            	}

Dynamic Tile_obj::__CreateEmpty() { return new Tile_obj; }

void *Tile_obj::_hx_vtable = 0;

Dynamic Tile_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Tile_obj > _hx_result = new Tile_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool Tile_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x5db93557;
}


Tile_obj::Tile_obj()
{
}

::hx::Val Tile_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"objType") ) { return ::hx::Val( objType ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tileType") ) { return ::hx::Val( tileType ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"regionType") ) { return ::hx::Val( regionType ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Tile_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"objType") ) { objType=inValue.Cast< unsigned short >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tileType") ) { tileType=inValue.Cast< unsigned short >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"regionType") ) { regionType=inValue.Cast< unsigned char >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Tile_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("tileType",08,19,0f,87));
	outFields->push(HX_("objType",51,76,23,77));
	outFields->push(HX_("regionType",ce,69,94,db));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Tile_obj_sMemberStorageInfo[] = {
	{::hx::fsUnknown /* unsigned short */ ,(int)offsetof(Tile_obj,tileType),HX_("tileType",08,19,0f,87)},
	{::hx::fsUnknown /* unsigned short */ ,(int)offsetof(Tile_obj,objType),HX_("objType",51,76,23,77)},
	{::hx::fsUnknown /* unsigned char */ ,(int)offsetof(Tile_obj,regionType),HX_("regionType",ce,69,94,db)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Tile_obj_sStaticStorageInfo = 0;
#endif

static ::String Tile_obj_sMemberFields[] = {
	HX_("tileType",08,19,0f,87),
	HX_("objType",51,76,23,77),
	HX_("regionType",ce,69,94,db),
	::String(null()) };

::hx::Class Tile_obj::__mClass;

void Tile_obj::__register()
{
	Tile_obj _hx_dummy;
	Tile_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("mapeditor.Tile",93,34,f5,ca);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Tile_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Tile_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Tile_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Tile_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mapeditor