// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_util_BloodComposition
#include <util/BloodComposition.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_a576dec3489a4687_8_getBloodComposition,"util.BloodComposition","getBloodComposition",0x827cc1f4,"util.BloodComposition.getBloodComposition","util/BloodComposition.hx",8,0x2abe4281)
HX_LOCAL_STACK_FRAME(_hx_pos_a576dec3489a4687_24_getColors,"util.BloodComposition","getColors",0x9871ea54,"util.BloodComposition.getColors","util/BloodComposition.hx",24,0x2abe4281)
HX_LOCAL_STACK_FRAME(_hx_pos_a576dec3489a4687_34_buildColors,"util.BloodComposition","buildColors",0x6f7c7e6c,"util.BloodComposition.buildColors","util/BloodComposition.hx",34,0x2abe4281)
HX_LOCAL_STACK_FRAME(_hx_pos_a576dec3489a4687_6_boot,"util.BloodComposition","boot",0xc0689f84,"util.BloodComposition.boot","util/BloodComposition.hx",6,0x2abe4281)
namespace util{

void BloodComposition_obj::__construct() { }

Dynamic BloodComposition_obj::__CreateEmpty() { return new BloodComposition_obj; }

void *BloodComposition_obj::_hx_vtable = 0;

Dynamic BloodComposition_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BloodComposition_obj > _hx_result = new BloodComposition_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool BloodComposition_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x02a73a72;
}

 ::haxe::ds::ObjectMap BloodComposition_obj::imageDict;

::Array< unsigned int > BloodComposition_obj::getBloodComposition(int id, ::openfl::display::BitmapData image,Float bloodProb,int bloodColor){
            	HX_STACKFRAME(&_hx_pos_a576dec3489a4687_8_getBloodComposition)
HXLINE(   9)		::Array< unsigned int > comp = ::Array_obj< unsigned int >::__new();
HXLINE(  10)		if (::hx::IsNull( image )) {
HXLINE(  11)			return comp;
            		}
HXLINE(  13)		::Array< int > colors = ::util::BloodComposition_obj::getColors(image);
HXLINE(  14)		{
HXLINE(  14)			int _g = 0;
HXDLIN(  14)			int _g1 = colors->length;
HXDLIN(  14)			while((_g < _g1)){
HXLINE(  14)				_g = (_g + 1);
HXLINE(  15)				if ((::Math_obj::random() < bloodProb)) {
HXLINE(  16)					comp->push(bloodColor);
            				}
            				else {
HXLINE(  18)					comp->push(colors->__get(::Math_obj::round((( (Float)(colors->length) ) * ::Math_obj::random()))));
            				}
            			}
            		}
HXLINE(  21)		return comp;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(BloodComposition_obj,getBloodComposition,return )

::Array< int > BloodComposition_obj::getColors( ::openfl::display::BitmapData image){
            	HX_STACKFRAME(&_hx_pos_a576dec3489a4687_24_getColors)
HXLINE(  25)		::Array< int > colors = ( (::Array< int >)(::util::BloodComposition_obj::imageDict->get(image)) );
HXLINE(  26)		if (::hx::IsNull( colors )) {
HXLINE(  27)			colors = ::util::BloodComposition_obj::buildColors(image);
HXLINE(  28)			::util::BloodComposition_obj::imageDict->set(image,colors);
            		}
HXLINE(  31)		return colors;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BloodComposition_obj,getColors,return )

::Array< int > BloodComposition_obj::buildColors( ::openfl::display::BitmapData image){
            	HX_STACKFRAME(&_hx_pos_a576dec3489a4687_34_buildColors)
HXLINE(  35)		int color = 0;
HXLINE(  36)		::Array< int > colors = ::Array_obj< int >::__new();
HXLINE(  37)		{
HXLINE(  37)			int _g = 0;
HXDLIN(  37)			int _g1 = image->width;
HXDLIN(  37)			while((_g < _g1)){
HXLINE(  37)				_g = (_g + 1);
HXDLIN(  37)				int x = (_g - 1);
HXLINE(  38)				{
HXLINE(  38)					int _g2 = 0;
HXDLIN(  38)					int _g3 = image->height;
HXDLIN(  38)					while((_g2 < _g3)){
HXLINE(  38)						_g2 = (_g2 + 1);
HXLINE(  39)						color = image->getPixel32(x,(_g2 - 1));
HXLINE(  40)						if (((color & -16777216) != 0)) {
HXLINE(  41)							colors->push(color);
            						}
            					}
            				}
            			}
            		}
HXLINE(  44)		return colors;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BloodComposition_obj,buildColors,return )


BloodComposition_obj::BloodComposition_obj()
{
}

bool BloodComposition_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"imageDict") ) { outValue = ( imageDict ); return true; }
		if (HX_FIELD_EQ(inName,"getColors") ) { outValue = getColors_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"buildColors") ) { outValue = buildColors_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getBloodComposition") ) { outValue = getBloodComposition_dyn(); return true; }
	}
	return false;
}

bool BloodComposition_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"imageDict") ) { imageDict=ioValue.Cast<  ::haxe::ds::ObjectMap >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *BloodComposition_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo BloodComposition_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::ObjectMap */ ,(void *) &BloodComposition_obj::imageDict,HX_("imageDict",71,ee,9d,24)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void BloodComposition_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BloodComposition_obj::imageDict,"imageDict");
};

#ifdef HXCPP_VISIT_ALLOCS
static void BloodComposition_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BloodComposition_obj::imageDict,"imageDict");
};

#endif

::hx::Class BloodComposition_obj::__mClass;

static ::String BloodComposition_obj_sStaticFields[] = {
	HX_("imageDict",71,ee,9d,24),
	HX_("getBloodComposition",06,51,66,e1),
	HX_("getColors",e6,4e,dd,42),
	HX_("buildColors",7e,ab,f7,16),
	::String(null())
};

void BloodComposition_obj::__register()
{
	BloodComposition_obj _hx_dummy;
	BloodComposition_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("util.BloodComposition",5c,06,81,b6);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &BloodComposition_obj::__GetStatic;
	__mClass->mSetStaticField = &BloodComposition_obj::__SetStatic;
	__mClass->mMarkFunc = BloodComposition_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(BloodComposition_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< BloodComposition_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = BloodComposition_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BloodComposition_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BloodComposition_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void BloodComposition_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_a576dec3489a4687_6_boot)
HXDLIN(   6)		imageDict =  ::haxe::ds::ObjectMap_obj::__alloc( HX_CTX );
            	}
}

} // end namespace util
