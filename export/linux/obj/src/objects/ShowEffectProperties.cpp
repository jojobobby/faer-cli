// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED__Xml_XmlType_Impl_
#include <_Xml/XmlType_Impl_.h>
#endif
#ifndef INCLUDED_objects_ShowEffectProperties
#include <objects/ShowEffectProperties.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_5eb0bf1a2ec9dcfe_185_new,"objects.ShowEffectProperties","new",0xa5d8156d,"objects.ShowEffectProperties.new","objects/ObjectProperties.hx",185,0xfce94251)
namespace objects{

void ShowEffectProperties_obj::__construct( ::Xml showEffXML){
            	HX_STACKFRAME(&_hx_pos_5eb0bf1a2ec9dcfe_185_new)
HXLINE( 189)		this->color = 0;
HXLINE( 188)		this->cooldown = 0;
HXLINE( 187)		this->radius = 0;
HXLINE( 186)		this->effType = HX_("",00,00,00,00);
HXLINE( 192)		bool _hx_tmp;
HXDLIN( 192)		if ((showEffXML->nodeType != ::Xml_obj::Document)) {
HXLINE( 192)			_hx_tmp = (showEffXML->nodeType != ::Xml_obj::Element);
            		}
            		else {
HXLINE( 192)			_hx_tmp = false;
            		}
HXDLIN( 192)		if (_hx_tmp) {
HXLINE( 192)			HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(showEffXML->nodeType)));
            		}
HXDLIN( 192)		 ::Xml _this = showEffXML->children->__get(0).StaticCast<  ::Xml >();
HXDLIN( 192)		bool _hx_tmp1;
HXDLIN( 192)		if ((_this->nodeType != ::Xml_obj::Document)) {
HXLINE( 192)			_hx_tmp1 = (_this->nodeType == ::Xml_obj::Element);
            		}
            		else {
HXLINE( 192)			_hx_tmp1 = true;
            		}
HXDLIN( 192)		if (_hx_tmp1) {
HXLINE( 192)			HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this->nodeType)));
            		}
HXDLIN( 192)		this->effType = _this->nodeValue;
HXLINE( 193)		this->radius = ( (int)(::Std_obj::parseInt(showEffXML->get(HX_("radius",52,d0,f6,b0)))) );
HXLINE( 194)		this->cooldown = ( (int)(::Std_obj::parseInt(showEffXML->get(HX_("cooldown",ab,4b,a2,f9)))) );
HXLINE( 195)		this->color = ( (int)(::Std_obj::parseInt(showEffXML->get(HX_("color",63,71,5c,4a)))) );
            	}

Dynamic ShowEffectProperties_obj::__CreateEmpty() { return new ShowEffectProperties_obj; }

void *ShowEffectProperties_obj::_hx_vtable = 0;

Dynamic ShowEffectProperties_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ShowEffectProperties_obj > _hx_result = new ShowEffectProperties_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool ShowEffectProperties_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7fd6d555;
}


::hx::ObjectPtr< ShowEffectProperties_obj > ShowEffectProperties_obj::__new( ::Xml showEffXML) {
	::hx::ObjectPtr< ShowEffectProperties_obj > __this = new ShowEffectProperties_obj();
	__this->__construct(showEffXML);
	return __this;
}

::hx::ObjectPtr< ShowEffectProperties_obj > ShowEffectProperties_obj::__alloc(::hx::Ctx *_hx_ctx, ::Xml showEffXML) {
	ShowEffectProperties_obj *__this = (ShowEffectProperties_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ShowEffectProperties_obj), true, "objects.ShowEffectProperties"));
	*(void **)__this = ShowEffectProperties_obj::_hx_vtable;
	__this->__construct(showEffXML);
	return __this;
}

ShowEffectProperties_obj::ShowEffectProperties_obj()
{
}

void ShowEffectProperties_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ShowEffectProperties);
	HX_MARK_MEMBER_NAME(effType,"effType");
	HX_MARK_MEMBER_NAME(radius,"radius");
	HX_MARK_MEMBER_NAME(cooldown,"cooldown");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_END_CLASS();
}

void ShowEffectProperties_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(effType,"effType");
	HX_VISIT_MEMBER_NAME(radius,"radius");
	HX_VISIT_MEMBER_NAME(cooldown,"cooldown");
	HX_VISIT_MEMBER_NAME(color,"color");
}

::hx::Val ShowEffectProperties_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return ::hx::Val( color ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return ::hx::Val( radius ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"effType") ) { return ::hx::Val( effType ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cooldown") ) { return ::hx::Val( cooldown ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ShowEffectProperties_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"effType") ) { effType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cooldown") ) { cooldown=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ShowEffectProperties_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("effType",3f,f2,1f,23));
	outFields->push(HX_("radius",52,d0,f6,b0));
	outFields->push(HX_("cooldown",ab,4b,a2,f9));
	outFields->push(HX_("color",63,71,5c,4a));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ShowEffectProperties_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(ShowEffectProperties_obj,effType),HX_("effType",3f,f2,1f,23)},
	{::hx::fsInt,(int)offsetof(ShowEffectProperties_obj,radius),HX_("radius",52,d0,f6,b0)},
	{::hx::fsInt,(int)offsetof(ShowEffectProperties_obj,cooldown),HX_("cooldown",ab,4b,a2,f9)},
	{::hx::fsInt,(int)offsetof(ShowEffectProperties_obj,color),HX_("color",63,71,5c,4a)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ShowEffectProperties_obj_sStaticStorageInfo = 0;
#endif

static ::String ShowEffectProperties_obj_sMemberFields[] = {
	HX_("effType",3f,f2,1f,23),
	HX_("radius",52,d0,f6,b0),
	HX_("cooldown",ab,4b,a2,f9),
	HX_("color",63,71,5c,4a),
	::String(null()) };

::hx::Class ShowEffectProperties_obj::__mClass;

void ShowEffectProperties_obj::__register()
{
	ShowEffectProperties_obj _hx_dummy;
	ShowEffectProperties_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("objects.ShowEffectProperties",fb,da,93,e1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ShowEffectProperties_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ShowEffectProperties_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ShowEffectProperties_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ShowEffectProperties_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace objects
