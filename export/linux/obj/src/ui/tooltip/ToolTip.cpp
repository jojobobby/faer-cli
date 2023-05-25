// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
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
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
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
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_DropShadowFilter
#include <openfl/filters/DropShadowFilter.h>
#endif
#ifndef INCLUDED_ui_tooltip_ToolTip
#include <ui/tooltip/ToolTip.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_16c0182a2efa7978_9_new,"ui.tooltip.ToolTip","new",0x3d884030,"ui.tooltip.ToolTip.new","ui/tooltip/ToolTip.hx",9,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_36_attachToTarget,"ui.tooltip.ToolTip","attachToTarget",0x28032241,"ui.tooltip.ToolTip.attachToTarget","ui/tooltip/ToolTip.hx",36,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_43_detachFromTarget,"ui.tooltip.ToolTip","detachFromTarget",0xa91a4dbe,"ui.tooltip.ToolTip.detachFromTarget","ui/tooltip/ToolTip.hx",43,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_50_draw,"ui.tooltip.ToolTip","draw",0x931d9234,"ui.tooltip.ToolTip.draw","ui/tooltip/ToolTip.hx",50,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_60_position,"ui.tooltip.ToolTip","position",0xf88eded9,"ui.tooltip.ToolTip.position","ui/tooltip/ToolTip.hx",60,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_82_onLeaveTarget,"ui.tooltip.ToolTip","onLeaveTarget",0x77bfa099,"ui.tooltip.ToolTip.onLeaveTarget","ui/tooltip/ToolTip.hx",82,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_85_onAddedToStage,"ui.tooltip.ToolTip","onAddedToStage",0xc9a18452,"ui.tooltip.ToolTip.onAddedToStage","ui/tooltip/ToolTip.hx",85,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_94_onRemovedFromStage,"ui.tooltip.ToolTip","onRemovedFromStage",0x88cba6a3,"ui.tooltip.ToolTip.onRemovedFromStage","ui/tooltip/ToolTip.hx",94,0x706254c2)
HX_LOCAL_STACK_FRAME(_hx_pos_16c0182a2efa7978_99_onEnterFrame,"ui.tooltip.ToolTip","onEnterFrame",0xdd5abc24,"ui.tooltip.ToolTip.onEnterFrame","ui/tooltip/ToolTip.hx",99,0x706254c2)
namespace ui{
namespace tooltip{

void ToolTip_obj::__construct(int background,Float backgroundAlpha,int outline,Float outlineAlpha,::hx::Null< bool >  __o_followMouse){
            		bool followMouse = __o_followMouse.Default(true);
            	HX_GC_STACKFRAME(&_hx_pos_16c0182a2efa7978_9_new)
HXLINE(  17)		this->followMouse = false;
HXLINE(  16)		this->outlineAlpha = ((Float)0.0);
HXLINE(  15)		this->outline = 0;
HXLINE(  14)		this->backgroundAlpha = ((Float)0.0);
HXLINE(  13)		this->background = 0;
HXLINE(  11)		this->contentHeight = 0;
HXLINE(  10)		this->contentWidth = 0;
HXLINE(  21)		super::__construct();
HXLINE(  23)		this->background = background;
HXLINE(  24)		this->backgroundAlpha = backgroundAlpha;
HXLINE(  25)		this->outline = outline;
HXLINE(  26)		this->outlineAlpha = outlineAlpha;
HXLINE(  27)		this->followMouse = followMouse;
HXLINE(  28)		this->mouseEnabled = false;
HXLINE(  29)		this->mouseChildren = false;
HXLINE(  30)		this->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,16,16,null(),null(),null(),null(),null())));
HXLINE(  31)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAddedToStage_dyn(),null(),null(),null());
HXLINE(  32)		this->addEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemovedFromStage_dyn(),null(),null(),null());
            	}

Dynamic ToolTip_obj::__CreateEmpty() { return new ToolTip_obj; }

void *ToolTip_obj::_hx_vtable = 0;

Dynamic ToolTip_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ToolTip_obj > _hx_result = new ToolTip_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return _hx_result;
}

bool ToolTip_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0c89e854) {
		if (inClassId<=(int)0x0637743c) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0637743c;
			}
		} else {
			return inClassId==(int)0x0c89e854;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void ToolTip_obj::attachToTarget( ::openfl::display::DisplayObject dObj){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_36_attachToTarget)
HXDLIN(  36)		if (::hx::IsNotNull( dObj )) {
HXLINE(  37)			this->targetObj = dObj;
HXLINE(  38)			this->targetObj->addEventListener(HX_("rollOut",11,f9,11,5d),this->onLeaveTarget_dyn(),null(),null(),null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ToolTip_obj,attachToTarget,(void))

void ToolTip_obj::detachFromTarget(){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_43_detachFromTarget)
HXDLIN(  43)		if (::hx::IsNotNull( this->targetObj )) {
HXLINE(  44)			this->targetObj->removeEventListener(HX_("rollOut",11,f9,11,5d),this->onLeaveTarget_dyn(),null());
HXLINE(  45)			{
HXLINE(  45)				 ::openfl::display::DisplayObjectContainer tmp = this->parent;
HXDLIN(  45)				if (::hx::IsNotNull( tmp )) {
HXLINE(  45)					tmp->removeChild(::hx::ObjectPtr<OBJ_>(this));
            				}
            			}
HXLINE(  46)			this->targetObj = null();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(ToolTip_obj,detachFromTarget,(void))

void ToolTip_obj::draw(){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_50_draw)
HXLINE(  51)		this->contentWidth = ::Std_obj::_hx_int(this->get_width());
HXLINE(  52)		this->contentHeight = ::Std_obj::_hx_int(this->get_height());
HXLINE(  54)		this->get_graphics()->clear();
HXLINE(  55)		this->get_graphics()->lineStyle(2,this->outline,this->outlineAlpha,null(),null(),null(),null(),null());
HXLINE(  56)		this->get_graphics()->beginFill(this->background,this->backgroundAlpha);
HXLINE(  57)		 ::openfl::display::Graphics _hx_tmp = this->get_graphics();
HXDLIN(  57)		_hx_tmp->drawRect(( (Float)(-4) ),( (Float)(-4) ),( (Float)((this->contentWidth + 12)) ),( (Float)((this->contentHeight + 12)) ));
            	}


HX_DEFINE_DYNAMIC_FUNC0(ToolTip_obj,draw,(void))

void ToolTip_obj::position(){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_60_position)
HXLINE(  61)		if (::hx::IsNull( ::Main_obj::primaryStage )) {
HXLINE(  62)			return;
            		}
HXLINE(  64)		Float _hx_tmp = ::Main_obj::primaryStage->get_mouseX();
HXDLIN(  64)		if ((_hx_tmp < (( (Float)(::Main_obj::stageWidth) ) / ( (Float)(2) )))) {
HXLINE(  65)			this->set_x((::Main_obj::primaryStage->get_mouseX() + 12));
            		}
            		else {
HXLINE(  67)			Float _hx_tmp1 = ::Main_obj::primaryStage->get_mouseX();
HXDLIN(  67)			this->set_x(((_hx_tmp1 - this->get_width()) - ( (Float)(1) )));
            		}
HXLINE(  69)		if ((this->get_x() < 12)) {
HXLINE(  70)			this->set_x(( (Float)(12) ));
            		}
HXLINE(  72)		Float _hx_tmp2 = ::Main_obj::primaryStage->get_mouseY();
HXDLIN(  72)		if ((_hx_tmp2 < (( (Float)(::Main_obj::stageHeight) ) / ( (Float)(3) )))) {
HXLINE(  73)			this->set_y((::Main_obj::primaryStage->get_mouseY() + 12));
            		}
            		else {
HXLINE(  75)			Float _hx_tmp3 = ::Main_obj::primaryStage->get_mouseY();
HXDLIN(  75)			this->set_y(((_hx_tmp3 - this->get_height()) - ( (Float)(1) )));
            		}
HXLINE(  77)		if ((this->get_y() < 12)) {
HXLINE(  78)			this->set_y(( (Float)(12) ));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(ToolTip_obj,position,(void))

void ToolTip_obj::onLeaveTarget( ::openfl::events::MouseEvent e){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_82_onLeaveTarget)
HXDLIN(  82)		this->detachFromTarget();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ToolTip_obj,onLeaveTarget,(void))

void ToolTip_obj::onAddedToStage( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_85_onAddedToStage)
HXLINE(  86)		this->draw();
HXLINE(  87)		if (this->followMouse) {
HXLINE(  88)			this->position();
HXLINE(  89)			this->addEventListener(HX_("enterFrame",f5,03,50,02),this->onEnterFrame_dyn(),null(),null(),null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ToolTip_obj,onAddedToStage,(void))

void ToolTip_obj::onRemovedFromStage( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_94_onRemovedFromStage)
HXDLIN(  94)		if (this->followMouse) {
HXLINE(  95)			this->removeEventListener(HX_("enterFrame",f5,03,50,02),this->onEnterFrame_dyn(),null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ToolTip_obj,onRemovedFromStage,(void))

void ToolTip_obj::onEnterFrame( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_16c0182a2efa7978_99_onEnterFrame)
HXDLIN(  99)		this->position();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ToolTip_obj,onEnterFrame,(void))


::hx::ObjectPtr< ToolTip_obj > ToolTip_obj::__new(int background,Float backgroundAlpha,int outline,Float outlineAlpha,::hx::Null< bool >  __o_followMouse) {
	::hx::ObjectPtr< ToolTip_obj > __this = new ToolTip_obj();
	__this->__construct(background,backgroundAlpha,outline,outlineAlpha,__o_followMouse);
	return __this;
}

::hx::ObjectPtr< ToolTip_obj > ToolTip_obj::__alloc(::hx::Ctx *_hx_ctx,int background,Float backgroundAlpha,int outline,Float outlineAlpha,::hx::Null< bool >  __o_followMouse) {
	ToolTip_obj *__this = (ToolTip_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ToolTip_obj), true, "ui.tooltip.ToolTip"));
	*(void **)__this = ToolTip_obj::_hx_vtable;
	__this->__construct(background,backgroundAlpha,outline,outlineAlpha,__o_followMouse);
	return __this;
}

ToolTip_obj::ToolTip_obj()
{
}

void ToolTip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ToolTip);
	HX_MARK_MEMBER_NAME(contentWidth,"contentWidth");
	HX_MARK_MEMBER_NAME(contentHeight,"contentHeight");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(backgroundAlpha,"backgroundAlpha");
	HX_MARK_MEMBER_NAME(outline,"outline");
	HX_MARK_MEMBER_NAME(outlineAlpha,"outlineAlpha");
	HX_MARK_MEMBER_NAME(followMouse,"followMouse");
	HX_MARK_MEMBER_NAME(targetObj,"targetObj");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ToolTip_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(contentWidth,"contentWidth");
	HX_VISIT_MEMBER_NAME(contentHeight,"contentHeight");
	HX_VISIT_MEMBER_NAME(background,"background");
	HX_VISIT_MEMBER_NAME(backgroundAlpha,"backgroundAlpha");
	HX_VISIT_MEMBER_NAME(outline,"outline");
	HX_VISIT_MEMBER_NAME(outlineAlpha,"outlineAlpha");
	HX_VISIT_MEMBER_NAME(followMouse,"followMouse");
	HX_VISIT_MEMBER_NAME(targetObj,"targetObj");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val ToolTip_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return ::hx::Val( draw_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"outline") ) { return ::hx::Val( outline ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return ::hx::Val( position_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"targetObj") ) { return ::hx::Val( targetObj ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return ::hx::Val( background ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"followMouse") ) { return ::hx::Val( followMouse ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"contentWidth") ) { return ::hx::Val( contentWidth ); }
		if (HX_FIELD_EQ(inName,"outlineAlpha") ) { return ::hx::Val( outlineAlpha ); }
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return ::hx::Val( onEnterFrame_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"contentHeight") ) { return ::hx::Val( contentHeight ); }
		if (HX_FIELD_EQ(inName,"onLeaveTarget") ) { return ::hx::Val( onLeaveTarget_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"attachToTarget") ) { return ::hx::Val( attachToTarget_dyn() ); }
		if (HX_FIELD_EQ(inName,"onAddedToStage") ) { return ::hx::Val( onAddedToStage_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundAlpha") ) { return ::hx::Val( backgroundAlpha ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"detachFromTarget") ) { return ::hx::Val( detachFromTarget_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onRemovedFromStage") ) { return ::hx::Val( onRemovedFromStage_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ToolTip_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"outline") ) { outline=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"targetObj") ) { targetObj=inValue.Cast<  ::openfl::display::DisplayObject >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"followMouse") ) { followMouse=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"contentWidth") ) { contentWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineAlpha") ) { outlineAlpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"contentHeight") ) { contentHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundAlpha") ) { backgroundAlpha=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ToolTip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("contentWidth",0d,0a,f1,b0));
	outFields->push(HX_("contentHeight",00,3a,47,d8));
	outFields->push(HX_("background",ee,93,1d,26));
	outFields->push(HX_("backgroundAlpha",90,84,81,e4));
	outFields->push(HX_("outline",82,17,be,e1));
	outFields->push(HX_("outlineAlpha",7c,88,f7,f1));
	outFields->push(HX_("followMouse",f4,1a,e2,13));
	outFields->push(HX_("targetObj",26,7d,33,69));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ToolTip_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(ToolTip_obj,contentWidth),HX_("contentWidth",0d,0a,f1,b0)},
	{::hx::fsInt,(int)offsetof(ToolTip_obj,contentHeight),HX_("contentHeight",00,3a,47,d8)},
	{::hx::fsInt,(int)offsetof(ToolTip_obj,background),HX_("background",ee,93,1d,26)},
	{::hx::fsFloat,(int)offsetof(ToolTip_obj,backgroundAlpha),HX_("backgroundAlpha",90,84,81,e4)},
	{::hx::fsInt,(int)offsetof(ToolTip_obj,outline),HX_("outline",82,17,be,e1)},
	{::hx::fsFloat,(int)offsetof(ToolTip_obj,outlineAlpha),HX_("outlineAlpha",7c,88,f7,f1)},
	{::hx::fsBool,(int)offsetof(ToolTip_obj,followMouse),HX_("followMouse",f4,1a,e2,13)},
	{::hx::fsObject /*  ::openfl::display::DisplayObject */ ,(int)offsetof(ToolTip_obj,targetObj),HX_("targetObj",26,7d,33,69)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ToolTip_obj_sStaticStorageInfo = 0;
#endif

static ::String ToolTip_obj_sMemberFields[] = {
	HX_("contentWidth",0d,0a,f1,b0),
	HX_("contentHeight",00,3a,47,d8),
	HX_("background",ee,93,1d,26),
	HX_("backgroundAlpha",90,84,81,e4),
	HX_("outline",82,17,be,e1),
	HX_("outlineAlpha",7c,88,f7,f1),
	HX_("followMouse",f4,1a,e2,13),
	HX_("targetObj",26,7d,33,69),
	HX_("attachToTarget",11,20,a6,94),
	HX_("detachFromTarget",8e,5f,d4,c2),
	HX_("draw",04,2c,70,42),
	HX_("position",a9,a0,fa,ca),
	HX_("onLeaveTarget",c9,4c,53,0c),
	HX_("onAddedToStage",22,82,44,36),
	HX_("onRemovedFromStage",73,cc,89,12),
	HX_("onEnterFrame",f4,a5,93,da),
	::String(null()) };

::hx::Class ToolTip_obj::__mClass;

void ToolTip_obj::__register()
{
	ToolTip_obj _hx_dummy;
	ToolTip_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.tooltip.ToolTip",3e,a8,80,da);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ToolTip_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ToolTip_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ToolTip_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ToolTip_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace tooltip