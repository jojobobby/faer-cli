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
#ifndef INCLUDED_mapeditor_GroundTypeToolTip
#include <mapeditor/GroundTypeToolTip.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_DropShadowFilter
#include <openfl/filters/DropShadowFilter.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_tooltip_ToolTip
#include <ui/tooltip/ToolTip.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_8b1574905401ee8d_15_new,"mapeditor.GroundTypeToolTip","new",0xa2b6c8ef,"mapeditor.GroundTypeToolTip.new","mapeditor/GroundTypeToolTip.hx",15,0x89a54fe2)
namespace mapeditor{

void GroundTypeToolTip_obj::__construct( ::Xml groundXML){
            	HX_GC_STACKFRAME(&_hx_pos_8b1574905401ee8d_15_new)
HXLINE(  16)		super::__construct(3552822,1,10197915,1,true);
HXLINE(  17)		this->titleText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,16,16777215,false,176,0,null());
HXLINE(  18)		this->titleText->setBold(true);
HXLINE(  19)		this->titleText->set_wordWrap(true);
HXLINE(  20)		 ::ui::SimpleText _hx_tmp = this->titleText;
HXDLIN(  20)		::String tmp = groundXML->get(HX_("id",db,5b,00,00));
HXDLIN(  20)		::String _hx_tmp1;
HXDLIN(  20)		if (::hx::IsNotNull( tmp )) {
HXLINE(  20)			_hx_tmp1 = tmp;
            		}
            		else {
HXLINE(  20)			_hx_tmp1 = HX_("",00,00,00,00);
            		}
HXDLIN(  20)		_hx_tmp->set_text(_hx_tmp1);
HXLINE(  21)		this->titleText->useTextDimensions();
HXLINE(  22)		 ::ui::SimpleText _hx_tmp2 = this->titleText;
HXDLIN(  22)		_hx_tmp2->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,((Float)0.5),12,12,null(),null(),null(),null(),null())));
HXLINE(  23)		this->titleText->set_x(( (Float)(0) ));
HXLINE(  24)		this->titleText->set_y(( (Float)(0) ));
HXLINE(  25)		this->addChild(this->titleText);
HXLINE(  26)		::String desc = HX_("",00,00,00,00);
HXLINE(  27)		if (( (bool)(groundXML->elementsNamed(HX_("Speed",67,07,97,14))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  28)			float desc1;
HXDLIN(  28)			if (( (bool)(groundXML->elementsNamed(HX_("Speed",67,07,97,14))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  28)				 ::Xml _this = ( ( ::Xml)(groundXML->elementsNamed(HX_("Speed",67,07,97,14))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  28)				bool desc2;
HXDLIN(  28)				if ((_this->nodeType != ::Xml_obj::Document)) {
HXLINE(  28)					desc2 = (_this->nodeType != ::Xml_obj::Element);
            				}
            				else {
HXLINE(  28)					desc2 = false;
            				}
HXDLIN(  28)				if (desc2) {
HXLINE(  28)					HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this->nodeType)));
            				}
HXDLIN(  28)				 ::Xml _this1 = _this->children->__get(0).StaticCast<  ::Xml >();
HXDLIN(  28)				bool desc3;
HXDLIN(  28)				if ((_this1->nodeType != ::Xml_obj::Document)) {
HXLINE(  28)					desc3 = (_this1->nodeType == ::Xml_obj::Element);
            				}
            				else {
HXLINE(  28)					desc3 = true;
            				}
HXDLIN(  28)				if (desc3) {
HXLINE(  28)					HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this1->nodeType)));
            				}
HXDLIN(  28)				desc1 = ( (float)(::Std_obj::parseFloat(_this1->nodeValue)) );
            			}
            			else {
HXLINE(  28)				desc1 = ( (float)(0) );
            			}
HXDLIN(  28)			desc = (HX_("",00,00,00,00) + ((HX_("Speed: ",cd,21,f5,ad) + ::Std_obj::string(desc1)) + HX_("\n",0a,00,00,00)));
            		}
            		else {
HXLINE(  30)			desc = HX_("Speed: 1.00\n",60,0a,2b,ad);
            		}
HXLINE(  32)		if (( (bool)(groundXML->elementsNamed(HX_("NoWalk",0a,12,1c,53))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  33)			desc = (desc + HX_("Unwalkable\n",ee,59,63,92));
            		}
HXLINE(  35)		if (( (bool)(groundXML->elementsNamed(HX_("Push",fa,3d,3a,35))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  36)			desc = (desc + HX_("Push\n",d0,fc,bb,5d));
            		}
HXLINE(  38)		if (( (bool)(groundXML->elementsNamed(HX_("Sink",73,c2,2c,37))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  39)			desc = (desc + HX_("Sink\n",37,62,fd,0f));
            		}
HXLINE(  41)		if (( (bool)(groundXML->elementsNamed(HX_("Sinking",4f,14,0c,14))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  42)			desc = (desc + HX_("Sinking\n",db,b0,85,76));
            		}
HXLINE(  44)		if (( (bool)(groundXML->elementsNamed(HX_("Animate",81,02,9e,47))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXLINE(  45)			desc = (desc + HX_("Animated\n",e7,bb,04,ed));
            		}
HXLINE(  47)		this->descText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,14,11776947,false,180,0,null());
HXLINE(  48)		this->descText->set_wordWrap(true);
HXLINE(  49)		this->descText->set_text(desc);
HXLINE(  50)		this->descText->useTextDimensions();
HXLINE(  51)		 ::ui::SimpleText _hx_tmp3 = this->descText;
HXDLIN(  51)		_hx_tmp3->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,((Float)0.5),12,12,null(),null(),null(),null(),null())));
HXLINE(  52)		this->descText->set_x(( (Float)(0) ));
HXLINE(  53)		 ::ui::SimpleText _hx_tmp4 = this->descText;
HXDLIN(  53)		_hx_tmp4->set_y((this->titleText->get_height() + 2));
HXLINE(  54)		this->addChild(this->descText);
            	}

Dynamic GroundTypeToolTip_obj::__CreateEmpty() { return new GroundTypeToolTip_obj; }

void *GroundTypeToolTip_obj::_hx_vtable = 0;

Dynamic GroundTypeToolTip_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GroundTypeToolTip_obj > _hx_result = new GroundTypeToolTip_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool GroundTypeToolTip_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1ee4699d) {
		if (inClassId<=(int)0x0637743c) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0637743c;
			}
		} else {
			return inClassId==(int)0x0c89e854 || inClassId==(int)0x1ee4699d;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}


::hx::ObjectPtr< GroundTypeToolTip_obj > GroundTypeToolTip_obj::__new( ::Xml groundXML) {
	::hx::ObjectPtr< GroundTypeToolTip_obj > __this = new GroundTypeToolTip_obj();
	__this->__construct(groundXML);
	return __this;
}

::hx::ObjectPtr< GroundTypeToolTip_obj > GroundTypeToolTip_obj::__alloc(::hx::Ctx *_hx_ctx, ::Xml groundXML) {
	GroundTypeToolTip_obj *__this = (GroundTypeToolTip_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GroundTypeToolTip_obj), true, "mapeditor.GroundTypeToolTip"));
	*(void **)__this = GroundTypeToolTip_obj::_hx_vtable;
	__this->__construct(groundXML);
	return __this;
}

GroundTypeToolTip_obj::GroundTypeToolTip_obj()
{
}

void GroundTypeToolTip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GroundTypeToolTip);
	HX_MARK_MEMBER_NAME(titleText,"titleText");
	HX_MARK_MEMBER_NAME(descText,"descText");
	 ::ui::tooltip::ToolTip_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GroundTypeToolTip_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(titleText,"titleText");
	HX_VISIT_MEMBER_NAME(descText,"descText");
	 ::ui::tooltip::ToolTip_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val GroundTypeToolTip_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"descText") ) { return ::hx::Val( descText ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { return ::hx::Val( titleText ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val GroundTypeToolTip_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"descText") ) { descText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { titleText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GroundTypeToolTip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("titleText",65,ba,a4,70));
	outFields->push(HX_("descText",9e,53,35,f3));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo GroundTypeToolTip_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(GroundTypeToolTip_obj,titleText),HX_("titleText",65,ba,a4,70)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(GroundTypeToolTip_obj,descText),HX_("descText",9e,53,35,f3)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *GroundTypeToolTip_obj_sStaticStorageInfo = 0;
#endif

static ::String GroundTypeToolTip_obj_sMemberFields[] = {
	HX_("titleText",65,ba,a4,70),
	HX_("descText",9e,53,35,f3),
	::String(null()) };

::hx::Class GroundTypeToolTip_obj::__mClass;

void GroundTypeToolTip_obj::__register()
{
	GroundTypeToolTip_obj _hx_dummy;
	GroundTypeToolTip_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("mapeditor.GroundTypeToolTip",7d,25,6e,e8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(GroundTypeToolTip_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< GroundTypeToolTip_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GroundTypeToolTip_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GroundTypeToolTip_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mapeditor