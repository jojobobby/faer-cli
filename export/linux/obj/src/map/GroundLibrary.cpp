// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_map_GroundLibrary
#include <map/GroundLibrary.h>
#endif
#ifndef INCLUDED_map_GroundProperties
#include <map/GroundProperties.h>
#endif
#ifndef INCLUDED_objects_TextureData
#include <objects/TextureData.h>
#endif
#ifndef INCLUDED_objects_animation_AnimationsData
#include <objects/animation/AnimationsData.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_util_BitmapUtil
#include <util/BitmapUtil.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_21_parseFromXML,"map.GroundLibrary","parseFromXML",0x23efc8c6,"map.GroundLibrary.parseFromXML","map/GroundLibrary.hx",21,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_36_getIdFromType,"map.GroundLibrary","getIdFromType",0x81299cc9,"map.GroundLibrary.getIdFromType","map/GroundLibrary.hx",36,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_44_getBitmapData,"map.GroundLibrary","getBitmapData",0xeb8ba643,"map.GroundLibrary.getBitmapData","map/GroundLibrary.hx",44,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_47_getColor,"map.GroundLibrary","getColor",0x70cb4d19,"map.GroundLibrary.getColor","map/GroundLibrary.hx",47,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_13_boot,"map.GroundLibrary","boot",0x9bf6ca5e,"map.GroundLibrary.boot","map/GroundLibrary.hx",13,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_14_boot,"map.GroundLibrary","boot",0x9bf6ca5e,"map.GroundLibrary.boot","map/GroundLibrary.hx",14,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_15_boot,"map.GroundLibrary","boot",0x9bf6ca5e,"map.GroundLibrary.boot","map/GroundLibrary.hx",15,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_16_boot,"map.GroundLibrary","boot",0x9bf6ca5e,"map.GroundLibrary.boot","map/GroundLibrary.hx",16,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_17_boot,"map.GroundLibrary","boot",0x9bf6ca5e,"map.GroundLibrary.boot","map/GroundLibrary.hx",17,0xd25f503d)
HX_LOCAL_STACK_FRAME(_hx_pos_0df3556b348cfb72_19_boot,"map.GroundLibrary","boot",0x9bf6ca5e,"map.GroundLibrary.boot","map/GroundLibrary.hx",19,0xd25f503d)
namespace map{

void GroundLibrary_obj::__construct() { }

Dynamic GroundLibrary_obj::__CreateEmpty() { return new GroundLibrary_obj; }

void *GroundLibrary_obj::_hx_vtable = 0;

Dynamic GroundLibrary_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GroundLibrary_obj > _hx_result = new GroundLibrary_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool GroundLibrary_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x365827f8;
}

 ::haxe::ds::IntMap GroundLibrary_obj::propsLibrary;

 ::haxe::ds::IntMap GroundLibrary_obj::xmlLibrary;

 ::haxe::ds::IntMap GroundLibrary_obj::typeToTextureData;

 ::haxe::ds::IntMap GroundLibrary_obj::typeToAnimationsData;

 ::haxe::ds::StringMap GroundLibrary_obj::idToType;

 ::map::GroundProperties GroundLibrary_obj::defaultProps;

 ::haxe::ds::IntMap GroundLibrary_obj::tileTypeColor;

void GroundLibrary_obj::parseFromXML( ::Xml xml){
            	HX_GC_STACKFRAME(&_hx_pos_0df3556b348cfb72_21_parseFromXML)
HXLINE(  22)		{
HXLINE(  22)			 ::Dynamic groundXML = xml->elementsNamed(HX_("Ground",a7,96,bc,50));
HXDLIN(  22)			while(( (bool)(groundXML->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  22)				 ::Xml groundXML1 = ( ( ::Xml)(groundXML->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  23)				unsigned short groundType;
HXDLIN(  23)				if (::hx::IsNotNull( groundXML1->get(HX_("type",ba,f2,08,4d)) )) {
HXLINE(  23)					groundType = ( (unsigned short)(::Std_obj::parseInt(groundXML1->get(HX_("type",ba,f2,08,4d)))) );
            				}
            				else {
HXLINE(  23)					groundType = ( (unsigned short)(0) );
            				}
HXLINE(  24)				 ::haxe::ds::IntMap _hx_tmp = ::map::GroundLibrary_obj::propsLibrary;
HXDLIN(  24)				_hx_tmp->set(( (int)(groundType) ), ::map::GroundProperties_obj::__alloc( HX_CTX ,groundXML1));
HXLINE(  25)				::map::GroundLibrary_obj::xmlLibrary->set(( (int)(groundType) ),groundXML1);
HXLINE(  26)				 ::haxe::ds::IntMap _hx_tmp1 = ::map::GroundLibrary_obj::typeToTextureData;
HXDLIN(  26)				_hx_tmp1->set(( (int)(groundType) ), ::objects::TextureData_obj::__alloc( HX_CTX ,groundXML1,null()));
HXLINE(  27)				 ::haxe::ds::StringMap _hx_tmp2 = ::map::GroundLibrary_obj::idToType;
HXDLIN(  27)				::String tmp = groundXML1->get(HX_("id",db,5b,00,00));
HXDLIN(  27)				::String _hx_tmp3;
HXDLIN(  27)				if (::hx::IsNotNull( tmp )) {
HXLINE(  27)					_hx_tmp3 = tmp;
            				}
            				else {
HXLINE(  27)					_hx_tmp3 = HX_("",00,00,00,00);
            				}
HXDLIN(  27)				_hx_tmp2->set(_hx_tmp3,groundType);
HXLINE(  29)				if (( (bool)(groundXML1->elementsNamed(HX_("Animation",e4,ce,07,ed))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  30)					 ::haxe::ds::IntMap _hx_tmp4 = ::map::GroundLibrary_obj::typeToAnimationsData;
HXDLIN(  30)					_hx_tmp4->set(( (int)(groundType) ), ::objects::animation::AnimationsData_obj::__alloc( HX_CTX ,groundXML1));
            				}
            			}
            		}
HXLINE(  33)		 ::haxe::ds::IntMap _hx_tmp5 = ::map::GroundLibrary_obj::propsLibrary;
HXDLIN(  33)		::map::GroundLibrary_obj::defaultProps = ( ( ::map::GroundProperties)(_hx_tmp5->get(::map::GroundLibrary_obj::idToType->get(HX_("Grass",d6,81,17,2d)))) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GroundLibrary_obj,parseFromXML,(void))

::String GroundLibrary_obj::getIdFromType(int tileType){
            	HX_STACKFRAME(&_hx_pos_0df3556b348cfb72_36_getIdFromType)
HXLINE(  37)		if (!(::map::GroundLibrary_obj::propsLibrary->exists(tileType))) {
HXLINE(  38)			return null();
            		}
HXLINE(  40)		return ( ( ::map::GroundProperties)(::map::GroundLibrary_obj::propsLibrary->get(tileType)) )->objId;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GroundLibrary_obj,getIdFromType,return )

 ::openfl::display::BitmapData GroundLibrary_obj::getBitmapData(int tileType,::hx::Null< int >  __o_id){
            		int id = __o_id.Default(0);
            	HX_STACKFRAME(&_hx_pos_0df3556b348cfb72_44_getBitmapData)
HXDLIN(  44)		return ( ( ::objects::TextureData)(::map::GroundLibrary_obj::typeToTextureData->get(tileType)) )->getTexture(id);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GroundLibrary_obj,getBitmapData,return )

 ::Dynamic GroundLibrary_obj::getColor(int groundType){
            	HX_STACKFRAME(&_hx_pos_0df3556b348cfb72_47_getColor)
HXLINE(  48)		if (!(::map::GroundLibrary_obj::tileTypeColor->exists(groundType))) {
HXLINE(  49)			 ::haxe::ds::IntMap _hx_tmp = ::map::GroundLibrary_obj::tileTypeColor;
HXDLIN(  49)			_hx_tmp->set(groundType,::util::BitmapUtil_obj::mostCommonColor(::map::GroundLibrary_obj::getBitmapData(groundType,null())));
            		}
HXLINE(  51)		return ::map::GroundLibrary_obj::tileTypeColor->get(groundType);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GroundLibrary_obj,getColor,return )


GroundLibrary_obj::GroundLibrary_obj()
{
}

bool GroundLibrary_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"idToType") ) { outValue = ( idToType ); return true; }
		if (HX_FIELD_EQ(inName,"getColor") ) { outValue = getColor_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"xmlLibrary") ) { outValue = ( xmlLibrary ); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"propsLibrary") ) { outValue = ( propsLibrary ); return true; }
		if (HX_FIELD_EQ(inName,"defaultProps") ) { outValue = ( defaultProps ); return true; }
		if (HX_FIELD_EQ(inName,"parseFromXML") ) { outValue = parseFromXML_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"tileTypeColor") ) { outValue = ( tileTypeColor ); return true; }
		if (HX_FIELD_EQ(inName,"getIdFromType") ) { outValue = getIdFromType_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { outValue = getBitmapData_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"typeToTextureData") ) { outValue = ( typeToTextureData ); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"typeToAnimationsData") ) { outValue = ( typeToAnimationsData ); return true; }
	}
	return false;
}

bool GroundLibrary_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"idToType") ) { idToType=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"xmlLibrary") ) { xmlLibrary=ioValue.Cast<  ::haxe::ds::IntMap >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"propsLibrary") ) { propsLibrary=ioValue.Cast<  ::haxe::ds::IntMap >(); return true; }
		if (HX_FIELD_EQ(inName,"defaultProps") ) { defaultProps=ioValue.Cast<  ::map::GroundProperties >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"tileTypeColor") ) { tileTypeColor=ioValue.Cast<  ::haxe::ds::IntMap >(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"typeToTextureData") ) { typeToTextureData=ioValue.Cast<  ::haxe::ds::IntMap >(); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"typeToAnimationsData") ) { typeToAnimationsData=ioValue.Cast<  ::haxe::ds::IntMap >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GroundLibrary_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo GroundLibrary_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(void *) &GroundLibrary_obj::propsLibrary,HX_("propsLibrary",6b,35,1e,8f)},
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(void *) &GroundLibrary_obj::xmlLibrary,HX_("xmlLibrary",e4,59,bb,21)},
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(void *) &GroundLibrary_obj::typeToTextureData,HX_("typeToTextureData",d0,03,f5,ba)},
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(void *) &GroundLibrary_obj::typeToAnimationsData,HX_("typeToAnimationsData",6e,38,38,ff)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &GroundLibrary_obj::idToType,HX_("idToType",10,04,6a,6b)},
	{::hx::fsObject /*  ::map::GroundProperties */ ,(void *) &GroundLibrary_obj::defaultProps,HX_("defaultProps",ef,22,eb,7d)},
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(void *) &GroundLibrary_obj::tileTypeColor,HX_("tileTypeColor",3b,0b,fb,7e)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void GroundLibrary_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GroundLibrary_obj::propsLibrary,"propsLibrary");
	HX_MARK_MEMBER_NAME(GroundLibrary_obj::xmlLibrary,"xmlLibrary");
	HX_MARK_MEMBER_NAME(GroundLibrary_obj::typeToTextureData,"typeToTextureData");
	HX_MARK_MEMBER_NAME(GroundLibrary_obj::typeToAnimationsData,"typeToAnimationsData");
	HX_MARK_MEMBER_NAME(GroundLibrary_obj::idToType,"idToType");
	HX_MARK_MEMBER_NAME(GroundLibrary_obj::defaultProps,"defaultProps");
	HX_MARK_MEMBER_NAME(GroundLibrary_obj::tileTypeColor,"tileTypeColor");
};

#ifdef HXCPP_VISIT_ALLOCS
static void GroundLibrary_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GroundLibrary_obj::propsLibrary,"propsLibrary");
	HX_VISIT_MEMBER_NAME(GroundLibrary_obj::xmlLibrary,"xmlLibrary");
	HX_VISIT_MEMBER_NAME(GroundLibrary_obj::typeToTextureData,"typeToTextureData");
	HX_VISIT_MEMBER_NAME(GroundLibrary_obj::typeToAnimationsData,"typeToAnimationsData");
	HX_VISIT_MEMBER_NAME(GroundLibrary_obj::idToType,"idToType");
	HX_VISIT_MEMBER_NAME(GroundLibrary_obj::defaultProps,"defaultProps");
	HX_VISIT_MEMBER_NAME(GroundLibrary_obj::tileTypeColor,"tileTypeColor");
};

#endif

::hx::Class GroundLibrary_obj::__mClass;

static ::String GroundLibrary_obj_sStaticFields[] = {
	HX_("propsLibrary",6b,35,1e,8f),
	HX_("xmlLibrary",e4,59,bb,21),
	HX_("typeToTextureData",d0,03,f5,ba),
	HX_("typeToAnimationsData",6e,38,38,ff),
	HX_("idToType",10,04,6a,6b),
	HX_("defaultProps",ef,22,eb,7d),
	HX_("tileTypeColor",3b,0b,fb,7e),
	HX_("parseFromXML",9a,76,e0,b1),
	HX_("getIdFromType",75,08,d1,25),
	HX_("getBitmapData",ef,11,33,90),
	HX_("getColor",ed,80,33,aa),
	::String(null())
};

void GroundLibrary_obj::__register()
{
	GroundLibrary_obj _hx_dummy;
	GroundLibrary_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("map.GroundLibrary",c2,c9,96,ce);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GroundLibrary_obj::__GetStatic;
	__mClass->mSetStaticField = &GroundLibrary_obj::__SetStatic;
	__mClass->mMarkFunc = GroundLibrary_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(GroundLibrary_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< GroundLibrary_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = GroundLibrary_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GroundLibrary_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GroundLibrary_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void GroundLibrary_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_0df3556b348cfb72_13_boot)
HXDLIN(  13)		propsLibrary =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_0df3556b348cfb72_14_boot)
HXDLIN(  14)		xmlLibrary =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_0df3556b348cfb72_15_boot)
HXDLIN(  15)		typeToTextureData =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_0df3556b348cfb72_16_boot)
HXDLIN(  16)		typeToAnimationsData =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_0df3556b348cfb72_17_boot)
HXDLIN(  17)		idToType =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_0df3556b348cfb72_19_boot)
HXDLIN(  19)		tileTypeColor =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
            	}
}

} // end namespace map
