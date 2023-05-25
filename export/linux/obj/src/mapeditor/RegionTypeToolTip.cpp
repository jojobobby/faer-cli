// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_mapeditor_RegionTypeToolTip
#include <mapeditor/RegionTypeToolTip.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_12b4eddcc97ba4d4_14_new,"mapeditor.RegionTypeToolTip","new",0xd7b56d22,"mapeditor.RegionTypeToolTip.new","mapeditor/RegionTypeToolTip.hx",14,0x90c5730f)
namespace mapeditor{

void RegionTypeToolTip_obj::__construct( ::Xml regionXML){
            	HX_GC_STACKFRAME(&_hx_pos_12b4eddcc97ba4d4_14_new)
HXLINE(  15)		super::__construct(3552822,1,10197915,1,true);
HXLINE(  16)		this->titleText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,16,16777215,false,176,0,null());
HXLINE(  17)		this->titleText->setBold(true);
HXLINE(  18)		this->titleText->set_wordWrap(true);
HXLINE(  19)		 ::ui::SimpleText _hx_tmp = this->titleText;
HXDLIN(  19)		::String tmp = regionXML->get(HX_("id",db,5b,00,00));
HXDLIN(  19)		::String _hx_tmp1;
HXDLIN(  19)		if (::hx::IsNotNull( tmp )) {
HXLINE(  19)			_hx_tmp1 = tmp;
            		}
            		else {
HXLINE(  19)			_hx_tmp1 = HX_("",00,00,00,00);
            		}
HXDLIN(  19)		_hx_tmp->set_text(_hx_tmp1);
HXLINE(  20)		this->titleText->useTextDimensions();
HXLINE(  21)		 ::ui::SimpleText _hx_tmp2 = this->titleText;
HXDLIN(  21)		_hx_tmp2->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,((Float)0.5),12,12,null(),null(),null(),null(),null())));
HXLINE(  22)		this->titleText->set_x(( (Float)(0) ));
HXLINE(  23)		this->titleText->set_y(( (Float)(0) ));
HXLINE(  24)		this->addChild(this->titleText);
            	}

Dynamic RegionTypeToolTip_obj::__CreateEmpty() { return new RegionTypeToolTip_obj; }

void *RegionTypeToolTip_obj::_hx_vtable = 0;

Dynamic RegionTypeToolTip_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< RegionTypeToolTip_obj > _hx_result = new RegionTypeToolTip_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool RegionTypeToolTip_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1f4df417) {
		if (inClassId<=(int)0x0637743c) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0637743c;
			}
		} else {
			return inClassId==(int)0x0c89e854 || inClassId==(int)0x1f4df417;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x263d867c || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}


::hx::ObjectPtr< RegionTypeToolTip_obj > RegionTypeToolTip_obj::__new( ::Xml regionXML) {
	::hx::ObjectPtr< RegionTypeToolTip_obj > __this = new RegionTypeToolTip_obj();
	__this->__construct(regionXML);
	return __this;
}

::hx::ObjectPtr< RegionTypeToolTip_obj > RegionTypeToolTip_obj::__alloc(::hx::Ctx *_hx_ctx, ::Xml regionXML) {
	RegionTypeToolTip_obj *__this = (RegionTypeToolTip_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(RegionTypeToolTip_obj), true, "mapeditor.RegionTypeToolTip"));
	*(void **)__this = RegionTypeToolTip_obj::_hx_vtable;
	__this->__construct(regionXML);
	return __this;
}

RegionTypeToolTip_obj::RegionTypeToolTip_obj()
{
}

void RegionTypeToolTip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RegionTypeToolTip);
	HX_MARK_MEMBER_NAME(titleText,"titleText");
	 ::ui::tooltip::ToolTip_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RegionTypeToolTip_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(titleText,"titleText");
	 ::ui::tooltip::ToolTip_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val RegionTypeToolTip_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { return ::hx::Val( titleText ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val RegionTypeToolTip_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { titleText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RegionTypeToolTip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("titleText",65,ba,a4,70));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo RegionTypeToolTip_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(RegionTypeToolTip_obj,titleText),HX_("titleText",65,ba,a4,70)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *RegionTypeToolTip_obj_sStaticStorageInfo = 0;
#endif

static ::String RegionTypeToolTip_obj_sMemberFields[] = {
	HX_("titleText",65,ba,a4,70),
	::String(null()) };

::hx::Class RegionTypeToolTip_obj::__mClass;

void RegionTypeToolTip_obj::__register()
{
	RegionTypeToolTip_obj _hx_dummy;
	RegionTypeToolTip_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("mapeditor.RegionTypeToolTip",30,f4,b3,7a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(RegionTypeToolTip_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< RegionTypeToolTip_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = RegionTypeToolTip_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = RegionTypeToolTip_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mapeditor
