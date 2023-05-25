// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_util_AssetLibrary
#include <util/AssetLibrary.h>
#endif
#ifndef INCLUDED_util_ConditionEffect
#include <util/ConditionEffect.h>
#endif
#ifndef INCLUDED_util_Rect
#include <util/Rect.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_32983b5d7b00c369_11_new,"util.ConditionEffect","new",0xeccf66f2,"util.ConditionEffect.new","util/ConditionEffect.hx",11,0x3d3750ff)
HX_LOCAL_STACK_FRAME(_hx_pos_32983b5d7b00c369_66_initRects,"util.ConditionEffect","initRects",0x47dc1db1,"util.ConditionEffect.initRects","util/ConditionEffect.hx",66,0x3d3750ff)
HX_LOCAL_STACK_FRAME(_hx_pos_32983b5d7b00c369_82_getConditionEffectFromName,"util.ConditionEffect","getConditionEffectFromName",0x90127d39,"util.ConditionEffect.getConditionEffectFromName","util/ConditionEffect.hx",82,0x3d3750ff)
HX_LOCAL_STACK_FRAME(_hx_pos_32983b5d7b00c369_41_boot,"util.ConditionEffect","boot",0x40c3ad60,"util.ConditionEffect.boot","util/ConditionEffect.hx",41,0x3d3750ff)
HX_LOCAL_STACK_FRAME(_hx_pos_32983b5d7b00c369_59_boot,"util.ConditionEffect","boot",0x40c3ad60,"util.ConditionEffect.boot","util/ConditionEffect.hx",59,0x3d3750ff)
namespace util{

void ConditionEffect_obj::__construct(::String name){
            	HX_STACKFRAME(&_hx_pos_32983b5d7b00c369_11_new)
HXLINE(  61)		this->name = HX_("",00,00,00,00);
HXLINE(  93)		this->name = name;
            	}

Dynamic ConditionEffect_obj::__CreateEmpty() { return new ConditionEffect_obj; }

void *ConditionEffect_obj::_hx_vtable = 0;

Dynamic ConditionEffect_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ConditionEffect_obj > _hx_result = new ConditionEffect_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool ConditionEffect_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0fa726aa;
}

::Array< ::Dynamic> ConditionEffect_obj::effects;

::Array< ::Dynamic> ConditionEffect_obj::effectRects;

 ::haxe::ds::StringMap ConditionEffect_obj::conditionEffectFromName;

void ConditionEffect_obj::initRects(){
            	HX_STACKFRAME(&_hx_pos_32983b5d7b00c369_66_initRects)
HXLINE(  68)		 ::util::Rect _hx_tmp = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),5);
HXLINE(  69)		 ::util::Rect _hx_tmp1 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),7);
HXLINE(  70)		 ::util::Rect _hx_tmp2 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),10);
HXLINE(  71)		 ::util::Rect _hx_tmp3 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),6);
HXLINE(  72)		 ::util::Rect _hx_tmp4 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),2);
HXLINE(  73)		 ::util::Rect _hx_tmp5 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),1);
HXLINE(  74)		 ::util::Rect _hx_tmp6 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),4);
HXLINE(  75)		 ::util::Rect _hx_tmp7 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),11);
HXLINE(  76)		 ::util::Rect _hx_tmp8 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),3);
HXLINE(  77)		 ::util::Rect _hx_tmp9 = ::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),0);
HXLINE(  66)		::util::ConditionEffect_obj::effectRects = ::Array_obj< ::Dynamic>::__new(12)->init(0,null())->init(1,_hx_tmp)->init(2,_hx_tmp1)->init(3,_hx_tmp2)->init(4,_hx_tmp3)->init(5,_hx_tmp4)->init(6,_hx_tmp5)->init(7,_hx_tmp6)->init(8,_hx_tmp7)->init(9,_hx_tmp8)->init(10,_hx_tmp9)->init(11,::util::AssetLibrary_obj::getRectFromSet(HX_("conditions",78,7e,38,b1),9));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ConditionEffect_obj,initRects,(void))

 ::Dynamic ConditionEffect_obj::getConditionEffectFromName(::String name){
            	HX_GC_STACKFRAME(&_hx_pos_32983b5d7b00c369_82_getConditionEffectFromName)
HXLINE(  83)		if (::hx::IsNull( ::util::ConditionEffect_obj::conditionEffectFromName )) {
HXLINE(  84)			::util::ConditionEffect_obj::conditionEffectFromName =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  85)			{
HXLINE(  85)				int _g = 0;
HXDLIN(  85)				int _g1 = ::util::ConditionEffect_obj::effects->length;
HXDLIN(  85)				while((_g < _g1)){
HXLINE(  85)					_g = (_g + 1);
HXDLIN(  85)					int ce = (_g - 1);
HXLINE(  86)					::util::ConditionEffect_obj::conditionEffectFromName->set(::util::ConditionEffect_obj::effects->__get(ce).StaticCast<  ::util::ConditionEffect >()->name,ce);
            				}
            			}
            		}
HXLINE(  89)		return ::util::ConditionEffect_obj::conditionEffectFromName->get(name);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ConditionEffect_obj,getConditionEffectFromName,return )


ConditionEffect_obj::ConditionEffect_obj()
{
}

void ConditionEffect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ConditionEffect);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_END_CLASS();
}

void ConditionEffect_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
}

::hx::Val ConditionEffect_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return ::hx::Val( name ); }
	}
	return super::__Field(inName,inCallProp);
}

bool ConditionEffect_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"effects") ) { outValue = ( effects ); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initRects") ) { outValue = initRects_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"effectRects") ) { outValue = ( effectRects ); return true; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"conditionEffectFromName") ) { outValue = ( conditionEffectFromName ); return true; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getConditionEffectFromName") ) { outValue = getConditionEffectFromName_dyn(); return true; }
	}
	return false;
}

::hx::Val ConditionEffect_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool ConditionEffect_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"effects") ) { effects=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"effectRects") ) { effectRects=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"conditionEffectFromName") ) { conditionEffectFromName=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
	}
	return false;
}

void ConditionEffect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("name",4b,72,ff,48));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ConditionEffect_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(ConditionEffect_obj,name),HX_("name",4b,72,ff,48)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo ConditionEffect_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &ConditionEffect_obj::effects,HX_("effects",c2,e4,4b,2e)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &ConditionEffect_obj::effectRects,HX_("effectRects",7e,5a,9f,02)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &ConditionEffect_obj::conditionEffectFromName,HX_("conditionEffectFromName",81,c7,4f,c8)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String ConditionEffect_obj_sMemberFields[] = {
	HX_("name",4b,72,ff,48),
	::String(null()) };

static void ConditionEffect_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConditionEffect_obj::effects,"effects");
	HX_MARK_MEMBER_NAME(ConditionEffect_obj::effectRects,"effectRects");
	HX_MARK_MEMBER_NAME(ConditionEffect_obj::conditionEffectFromName,"conditionEffectFromName");
};

#ifdef HXCPP_VISIT_ALLOCS
static void ConditionEffect_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConditionEffect_obj::effects,"effects");
	HX_VISIT_MEMBER_NAME(ConditionEffect_obj::effectRects,"effectRects");
	HX_VISIT_MEMBER_NAME(ConditionEffect_obj::conditionEffectFromName,"conditionEffectFromName");
};

#endif

::hx::Class ConditionEffect_obj::__mClass;

static ::String ConditionEffect_obj_sStaticFields[] = {
	HX_("effects",c2,e4,4b,2e),
	HX_("effectRects",7e,5a,9f,02),
	HX_("conditionEffectFromName",81,c7,4f,c8),
	HX_("initRects",9f,4d,4e,02),
	HX_("getConditionEffectFromName",8b,81,23,67),
	::String(null())
};

void ConditionEffect_obj::__register()
{
	ConditionEffect_obj _hx_dummy;
	ConditionEffect_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("util.ConditionEffect",00,c6,38,7b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &ConditionEffect_obj::__GetStatic;
	__mClass->mSetStaticField = &ConditionEffect_obj::__SetStatic;
	__mClass->mMarkFunc = ConditionEffect_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(ConditionEffect_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ConditionEffect_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ConditionEffect_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = ConditionEffect_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ConditionEffect_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ConditionEffect_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void ConditionEffect_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_32983b5d7b00c369_41_boot)
HXDLIN(  41)		effects = ::Array_obj< ::Dynamic>::__new(13)->init(0, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Nothing",ed,c3,b0,1c)))->init(1, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Dead",c4,7a,3f,2d)))->init(2, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Weak",98,88,ce,39)))->init(3, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Slowed",c0,ec,9e,a8)))->init(4, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Sick",de,b8,2c,37)))->init(5, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Speedy",32,73,8f,ef)))->init(6, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Bleeding",c8,f0,fc,15)))->init(7, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Healing",9a,34,a6,35)))->init(8, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Damaging",8c,ef,31,a6)))->init(9, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Invulnerable",0d,c3,73,6f)))->init(10, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Armored",7e,0c,05,30)))->init(11, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Armor Broken",16,fe,19,67)))->init(12, ::util::ConditionEffect_obj::__alloc( HX_CTX ,HX_("Hidden",8a,73,2a,81)));
            	}
{
            	HX_STACKFRAME(&_hx_pos_32983b5d7b00c369_59_boot)
HXDLIN(  59)		conditionEffectFromName = null();
            	}
}

} // end namespace util