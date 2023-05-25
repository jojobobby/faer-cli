// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_core_Layers
#include <core/Layers.h>
#endif
#ifndef INCLUDED_mapeditor_Element
#include <mapeditor/Element.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_Graphics
#include <openfl/display/Graphics.h>
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
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_MouseEvent
#include <openfl/events/MouseEvent.h>
#endif
#ifndef INCLUDED_ui_tooltip_ToolTip
#include <ui/tooltip/ToolTip.h>
#endif
#ifndef INCLUDED_ui_tooltip_TooltipsView
#include <ui/tooltip/TooltipsView.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_8_new,"mapeditor.Element","new",0xca121ae9,"mapeditor.Element.new","mapeditor/Element.hx",8,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_26_setSelected,"mapeditor.Element","setSelected",0x45176fa6,"mapeditor.Element.setSelected","mapeditor/Element.hx",26,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_31_onAddedToStage,"mapeditor.Element","onAddedToStage",0xee682239,"mapeditor.Element.onAddedToStage","mapeditor/Element.hx",31,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_36_onRemovedFromStage,"mapeditor.Element","onRemovedFromStage",0x7334c40a,"mapeditor.Element.onRemovedFromStage","mapeditor/Element.hx",36,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_41_onMouseOver,"mapeditor.Element","onMouseOver",0x7b99a883,"mapeditor.Element.onMouseOver","mapeditor/Element.hx",41,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_47_onRollOut,"mapeditor.Element","onRollOut",0x564b08fb,"mapeditor.Element.onRollOut","mapeditor/Element.hx",47,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_53_setToolTip,"mapeditor.Element","setToolTip",0xf85191f8,"mapeditor.Element.setToolTip","mapeditor/Element.hx",53,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_59_removeTooltip,"mapeditor.Element","removeTooltip",0x288d38e8,"mapeditor.Element.removeTooltip","mapeditor/Element.hx",59,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_63_getToolTip,"mapeditor.Element","getToolTip",0xf4d3f384,"mapeditor.Element.getToolTip","mapeditor/Element.hx",63,0xa436dfe8)
HX_LOCAL_STACK_FRAME(_hx_pos_83d8ff0b67ebba4a_66_draw,"mapeditor.Element","draw",0xff33195b,"mapeditor.Element.draw","mapeditor/Element.hx",66,0xa436dfe8)
namespace mapeditor{

void Element_obj::__construct(int type){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_8_new)
HXLINE(  17)		this->mouseOver = false;
HXLINE(  16)		this->selected = false;
HXLINE(  20)		super::__construct();
HXLINE(  21)		this->type = type;
HXLINE(  22)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAddedToStage_dyn(),null(),null(),null());
HXLINE(  23)		this->addEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemovedFromStage_dyn(),null(),null(),null());
            	}

Dynamic Element_obj::__CreateEmpty() { return new Element_obj; }

void *Element_obj::_hx_vtable = 0;

Dynamic Element_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Element_obj > _hx_result = new Element_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Element_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1f4df417) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x1f4df417;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x3ed04433 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void Element_obj::setSelected(bool selected){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_26_setSelected)
HXLINE(  27)		this->selected = selected;
HXLINE(  28)		this->draw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,setSelected,(void))

void Element_obj::onAddedToStage( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_31_onAddedToStage)
HXLINE(  32)		this->addEventListener(HX_("mouseOver",19,4a,0d,f6),this->onMouseOver_dyn(),null(),null(),null());
HXLINE(  33)		this->addEventListener(HX_("rollOut",11,f9,11,5d),this->onRollOut_dyn(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,onAddedToStage,(void))

void Element_obj::onRemovedFromStage( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_36_onRemovedFromStage)
HXLINE(  37)		this->removeEventListener(HX_("mouseOver",19,4a,0d,f6),this->onMouseOver_dyn(),null());
HXLINE(  38)		this->removeEventListener(HX_("rollOut",11,f9,11,5d),this->onRollOut_dyn(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,onRemovedFromStage,(void))

void Element_obj::onMouseOver( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_41_onMouseOver)
HXLINE(  42)		this->mouseOver = true;
HXLINE(  43)		this->draw();
HXLINE(  44)		this->setToolTip(this->getToolTip());
            	}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,onMouseOver,(void))

void Element_obj::onRollOut( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_47_onRollOut)
HXLINE(  48)		this->mouseOver = false;
HXLINE(  49)		this->draw();
HXLINE(  50)		this->removeTooltip();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,onRollOut,(void))

void Element_obj::setToolTip( ::ui::tooltip::ToolTip newToolTip){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_53_setToolTip)
HXLINE(  54)		this->removeTooltip();
HXLINE(  55)		::Global_obj::layers->tooltips->show(newToolTip);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,setToolTip,(void))

void Element_obj::removeTooltip(){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_59_removeTooltip)
HXDLIN(  59)		::Global_obj::layers->tooltips->hide();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,removeTooltip,(void))

 ::ui::tooltip::ToolTip Element_obj::getToolTip(){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_63_getToolTip)
HXDLIN(  63)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,getToolTip,return )

void Element_obj::draw(){
            	HX_STACKFRAME(&_hx_pos_83d8ff0b67ebba4a_66_draw)
HXLINE(  67)		this->get_graphics()->clear();
HXLINE(  69)		if (this->selected) {
HXLINE(  70)			this->get_graphics()->lineStyle(1,16777215,null(),null(),null(),null(),null(),null());
            		}
HXLINE(  74)		int _hx_tmp;
HXDLIN(  74)		if (this->mouseOver) {
HXLINE(  74)			_hx_tmp = 5658198;
            		}
            		else {
HXLINE(  74)			_hx_tmp = 3552822;
            		}
HXDLIN(  74)		this->get_graphics()->beginFill(_hx_tmp,1);
HXLINE(  75)		this->get_graphics()->drawRect(( (Float)(2) ),( (Float)(2) ),( (Float)(46) ),( (Float)(46) ));
HXLINE(  76)		if (this->selected) {
HXLINE(  77)			this->get_graphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
            		}
HXLINE(  79)		this->get_graphics()->endFill();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,draw,(void))


::hx::ObjectPtr< Element_obj > Element_obj::__new(int type) {
	::hx::ObjectPtr< Element_obj > __this = new Element_obj();
	__this->__construct(type);
	return __this;
}

::hx::ObjectPtr< Element_obj > Element_obj::__alloc(::hx::Ctx *_hx_ctx,int type) {
	Element_obj *__this = (Element_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Element_obj), true, "mapeditor.Element"));
	*(void **)__this = Element_obj::_hx_vtable;
	__this->__construct(type);
	return __this;
}

Element_obj::Element_obj()
{
}

::hx::Val Element_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return ::hx::Val( type ); }
		if (HX_FIELD_EQ(inName,"draw") ) { return ::hx::Val( draw_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selected") ) { return ::hx::Val( selected ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseOver") ) { return ::hx::Val( mouseOver ); }
		if (HX_FIELD_EQ(inName,"onRollOut") ) { return ::hx::Val( onRollOut_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setToolTip") ) { return ::hx::Val( setToolTip_dyn() ); }
		if (HX_FIELD_EQ(inName,"getToolTip") ) { return ::hx::Val( getToolTip_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setSelected") ) { return ::hx::Val( setSelected_dyn() ); }
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return ::hx::Val( onMouseOver_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"removeTooltip") ) { return ::hx::Val( removeTooltip_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onAddedToStage") ) { return ::hx::Val( onAddedToStage_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onRemovedFromStage") ) { return ::hx::Val( onRemovedFromStage_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Element_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selected") ) { selected=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseOver") ) { mouseOver=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Element_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("type",ba,f2,08,4d));
	outFields->push(HX_("selected",5b,2a,6d,b1));
	outFields->push(HX_("mouseOver",19,4a,0d,f6));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Element_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(Element_obj,type),HX_("type",ba,f2,08,4d)},
	{::hx::fsBool,(int)offsetof(Element_obj,selected),HX_("selected",5b,2a,6d,b1)},
	{::hx::fsBool,(int)offsetof(Element_obj,mouseOver),HX_("mouseOver",19,4a,0d,f6)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Element_obj_sStaticStorageInfo = 0;
#endif

static ::String Element_obj_sMemberFields[] = {
	HX_("type",ba,f2,08,4d),
	HX_("selected",5b,2a,6d,b1),
	HX_("mouseOver",19,4a,0d,f6),
	HX_("setSelected",1d,f4,cd,e1),
	HX_("onAddedToStage",22,82,44,36),
	HX_("onRemovedFromStage",73,cc,89,12),
	HX_("onMouseOver",fa,2c,50,18),
	HX_("onRollOut",b2,b1,bc,34),
	HX_("setToolTip",61,89,53,bd),
	HX_("removeTooltip",1f,09,47,43),
	HX_("getToolTip",ed,ea,d5,b9),
	HX_("draw",04,2c,70,42),
	::String(null()) };

::hx::Class Element_obj::__mClass;

void Element_obj::__register()
{
	Element_obj _hx_dummy;
	Element_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("mapeditor.Element",77,72,86,3d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Element_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Element_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Element_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Element_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mapeditor