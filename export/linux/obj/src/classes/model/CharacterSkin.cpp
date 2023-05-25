// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_assets_CharacterTemplate
#include <assets/CharacterTemplate.h>
#endif
#ifndef INCLUDED_classes_model_CharacterSkin
#include <classes/model/CharacterSkin.h>
#endif
#ifndef INCLUDED_classes_model_CharacterSkinState
#include <classes/model/CharacterSkinState.h>
#endif
#ifndef INCLUDED_util_Signal
#include <util/Signal.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_324d3b7edda4436a_6_new,"classes.model.CharacterSkin","new",0x0584e6cb,"classes.model.CharacterSkin.new","classes/model/CharacterSkin.hx",6,0xe679d5c7)
HX_LOCAL_STACK_FRAME(_hx_pos_324d3b7edda4436a_21_getIsSelected,"classes.model.CharacterSkin","getIsSelected",0x4f2e02c6,"classes.model.CharacterSkin.getIsSelected","classes/model/CharacterSkin.hx",21,0xe679d5c7)
HX_LOCAL_STACK_FRAME(_hx_pos_324d3b7edda4436a_25_setIsSelected,"classes.model.CharacterSkin","setIsSelected",0x9433e4d2,"classes.model.CharacterSkin.setIsSelected","classes/model/CharacterSkin.hx",25,0xe679d5c7)
HX_LOCAL_STACK_FRAME(_hx_pos_324d3b7edda4436a_32_getState,"classes.model.CharacterSkin","getState",0x0f314b50,"classes.model.CharacterSkin.getState","classes/model/CharacterSkin.hx",32,0xe679d5c7)
HX_LOCAL_STACK_FRAME(_hx_pos_324d3b7edda4436a_36_setState,"classes.model.CharacterSkin","setState",0xbd8ea4c4,"classes.model.CharacterSkin.setState","classes/model/CharacterSkin.hx",36,0xe679d5c7)
namespace classes{
namespace model{

void CharacterSkin_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_324d3b7edda4436a_6_new)
HXLINE(  14)		this->isSelected = false;
HXLINE(  11)		this->cost = 0;
HXLINE(   9)		this->name = HX_("",00,00,00,00);
HXLINE(   8)		this->id = 0;
HXLINE(   7)		this->changed =  ::util::Signal_obj::__alloc( HX_CTX );
HXLINE(  17)		this->state = ::classes::model::CharacterSkinState_obj::_hx_NULL;
            	}

Dynamic CharacterSkin_obj::__CreateEmpty() { return new CharacterSkin_obj; }

void *CharacterSkin_obj::_hx_vtable = 0;

Dynamic CharacterSkin_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CharacterSkin_obj > _hx_result = new CharacterSkin_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CharacterSkin_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1efd1183;
}

bool CharacterSkin_obj::getIsSelected(){
            	HX_STACKFRAME(&_hx_pos_324d3b7edda4436a_21_getIsSelected)
HXDLIN(  21)		return this->isSelected;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CharacterSkin_obj,getIsSelected,return )

void CharacterSkin_obj::setIsSelected(bool value){
            	HX_STACKFRAME(&_hx_pos_324d3b7edda4436a_25_setIsSelected)
HXDLIN(  25)		if ((this->isSelected != value)) {
HXLINE(  26)			this->isSelected = value;
HXLINE(  27)			this->changed->emit(::hx::ObjectPtr<OBJ_>(this));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharacterSkin_obj,setIsSelected,(void))

 ::classes::model::CharacterSkinState CharacterSkin_obj::getState(){
            	HX_STACKFRAME(&_hx_pos_324d3b7edda4436a_32_getState)
HXDLIN(  32)		return this->state;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CharacterSkin_obj,getState,return )

void CharacterSkin_obj::setState( ::classes::model::CharacterSkinState value){
            	HX_STACKFRAME(&_hx_pos_324d3b7edda4436a_36_setState)
HXDLIN(  36)		if (::hx::IsInstanceNotEq( this->state,value )) {
HXLINE(  37)			this->state = value;
HXLINE(  38)			this->changed->emit(::hx::ObjectPtr<OBJ_>(this));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharacterSkin_obj,setState,(void))


::hx::ObjectPtr< CharacterSkin_obj > CharacterSkin_obj::__new() {
	::hx::ObjectPtr< CharacterSkin_obj > __this = new CharacterSkin_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CharacterSkin_obj > CharacterSkin_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CharacterSkin_obj *__this = (CharacterSkin_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CharacterSkin_obj), true, "classes.model.CharacterSkin"));
	*(void **)__this = CharacterSkin_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CharacterSkin_obj::CharacterSkin_obj()
{
}

void CharacterSkin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharacterSkin);
	HX_MARK_MEMBER_NAME(changed,"changed");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(_hx_template,"template");
	HX_MARK_MEMBER_NAME(cost,"cost");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(isSelected,"isSelected");
	HX_MARK_END_CLASS();
}

void CharacterSkin_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(changed,"changed");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(_hx_template,"template");
	HX_VISIT_MEMBER_NAME(cost,"cost");
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(isSelected,"isSelected");
}

::hx::Val CharacterSkin_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return ::hx::Val( id ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return ::hx::Val( name ); }
		if (HX_FIELD_EQ(inName,"cost") ) { return ::hx::Val( cost ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return ::hx::Val( state ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"changed") ) { return ::hx::Val( changed ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"template") ) { return ::hx::Val( _hx_template ); }
		if (HX_FIELD_EQ(inName,"getState") ) { return ::hx::Val( getState_dyn() ); }
		if (HX_FIELD_EQ(inName,"setState") ) { return ::hx::Val( setState_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isSelected") ) { return ::hx::Val( isSelected ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getIsSelected") ) { return ::hx::Val( getIsSelected_dyn() ); }
		if (HX_FIELD_EQ(inName,"setIsSelected") ) { return ::hx::Val( setIsSelected_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CharacterSkin_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cost") ) { cost=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast<  ::classes::model::CharacterSkinState >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"changed") ) { changed=inValue.Cast<  ::util::Signal >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"template") ) { _hx_template=inValue.Cast<  ::assets::CharacterTemplate >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isSelected") ) { isSelected=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CharacterSkin_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("changed",f4,b0,cc,cc));
	outFields->push(HX_("id",db,5b,00,00));
	outFields->push(HX_("name",4b,72,ff,48));
	outFields->push(HX_("template",3a,e8,47,ac));
	outFields->push(HX_("cost",4d,be,c4,41));
	outFields->push(HX_("state",11,76,0b,84));
	outFields->push(HX_("isSelected",65,3c,1c,2c));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CharacterSkin_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::util::Signal */ ,(int)offsetof(CharacterSkin_obj,changed),HX_("changed",f4,b0,cc,cc)},
	{::hx::fsInt,(int)offsetof(CharacterSkin_obj,id),HX_("id",db,5b,00,00)},
	{::hx::fsString,(int)offsetof(CharacterSkin_obj,name),HX_("name",4b,72,ff,48)},
	{::hx::fsObject /*  ::assets::CharacterTemplate */ ,(int)offsetof(CharacterSkin_obj,_hx_template),HX_("template",3a,e8,47,ac)},
	{::hx::fsInt,(int)offsetof(CharacterSkin_obj,cost),HX_("cost",4d,be,c4,41)},
	{::hx::fsObject /*  ::classes::model::CharacterSkinState */ ,(int)offsetof(CharacterSkin_obj,state),HX_("state",11,76,0b,84)},
	{::hx::fsBool,(int)offsetof(CharacterSkin_obj,isSelected),HX_("isSelected",65,3c,1c,2c)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CharacterSkin_obj_sStaticStorageInfo = 0;
#endif

static ::String CharacterSkin_obj_sMemberFields[] = {
	HX_("changed",f4,b0,cc,cc),
	HX_("id",db,5b,00,00),
	HX_("name",4b,72,ff,48),
	HX_("template",3a,e8,47,ac),
	HX_("cost",4d,be,c4,41),
	HX_("state",11,76,0b,84),
	HX_("isSelected",65,3c,1c,2c),
	HX_("getIsSelected",9b,98,8e,88),
	HX_("setIsSelected",a7,7a,94,cd),
	HX_("getState",9b,85,e2,e3),
	HX_("setState",0f,df,3f,92),
	::String(null()) };

::hx::Class CharacterSkin_obj::__mClass;

void CharacterSkin_obj::__register()
{
	CharacterSkin_obj _hx_dummy;
	CharacterSkin_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("classes.model.CharacterSkin",59,25,29,0c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CharacterSkin_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CharacterSkin_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CharacterSkin_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CharacterSkin_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace classes
} // end namespace model