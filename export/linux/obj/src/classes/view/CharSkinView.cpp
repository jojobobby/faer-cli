// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_classes_view_CharSkinListView
#include <classes/view/CharSkinListView.h>
#endif
#ifndef INCLUDED_classes_view_CharSkinView
#include <classes/view/CharSkinView.h>
#endif
#ifndef INCLUDED_classes_view_ClassDetailView
#include <classes/view/ClassDetailView.h>
#endif
#ifndef INCLUDED_core_Layers
#include <core/Layers.h>
#endif
#ifndef INCLUDED_core_PlayerModel
#include <core/PlayerModel.h>
#endif
#ifndef INCLUDED_core_ScreensView
#include <core/ScreensView.h>
#endif
#ifndef INCLUDED_game_GameSprite
#include <game/GameSprite.h>
#endif
#ifndef INCLUDED_game_model_GameInitData
#include <game/model/GameInitData.h>
#endif
#ifndef INCLUDED_game_view_CurrencyDisplay
#include <game/view/CurrencyDisplay.h>
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
#ifndef INCLUDED_openfl_display_Shape
#include <openfl/display/Shape.h>
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
#ifndef INCLUDED_screens_AccountScreen
#include <screens/AccountScreen.h>
#endif
#ifndef INCLUDED_screens_NewCharacterScreen
#include <screens/NewCharacterScreen.h>
#endif
#ifndef INCLUDED_screens_TitleMenuOption
#include <screens/TitleMenuOption.h>
#endif
#ifndef INCLUDED_ui_view_ScreenBase
#include <ui/view/ScreenBase.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_e94d00e4384e6d73_21_new,"classes.view.CharSkinView","new",0x2b6cd1eb,"classes.view.CharSkinView.new","classes/view/CharSkinView.hx",21,0xc564a385)
HX_LOCAL_STACK_FRAME(_hx_pos_e94d00e4384e6d73_71_onAdded,"classes.view.CharSkinView","onAdded",0x4d61962c,"classes.view.CharSkinView.onAdded","classes/view/CharSkinView.hx",71,0xc564a385)
HX_LOCAL_STACK_FRAME(_hx_pos_e94d00e4384e6d73_76_onRemoved,"classes.view.CharSkinView","onRemoved",0xf822140c,"classes.view.CharSkinView.onRemoved","classes/view/CharSkinView.hx",76,0xc564a385)
HX_LOCAL_STACK_FRAME(_hx_pos_e94d00e4384e6d73_97_setPlayButtonEnabled,"classes.view.CharSkinView","setPlayButtonEnabled",0xcbe6c62e,"classes.view.CharSkinView.setPlayButtonEnabled","classes/view/CharSkinView.hx",97,0xc564a385)
HX_LOCAL_STACK_FRAME(_hx_pos_e94d00e4384e6d73_84_onBack,"classes.view.CharSkinView","onBack",0xf3392a3b,"classes.view.CharSkinView.onBack","classes/view/CharSkinView.hx",84,0xc564a385)
HX_LOCAL_STACK_FRAME(_hx_pos_e94d00e4384e6d73_87_onPlay,"classes.view.CharSkinView","onPlay",0xfc827e08,"classes.view.CharSkinView.onPlay","classes/view/CharSkinView.hx",87,0xc564a385)
namespace classes{
namespace view{

void CharSkinView_obj::__construct( ::Xml _playerXML){
            	HX_GC_STACKFRAME(&_hx_pos_e94d00e4384e6d73_21_new)
HXLINE(  22)		super::__construct();
HXLINE(  24)		::classes::view::CharSkinView_obj::playerXML = _playerXML;
HXLINE(  26)		this->addChild( ::ui::view::ScreenBase_obj::__alloc( HX_CTX ));
HXLINE(  27)		this->addChild( ::screens::AccountScreen_obj::__alloc( HX_CTX ));
HXLINE(  29)		 ::openfl::display::Shape shape =  ::openfl::display::Shape_obj::__alloc( HX_CTX );
HXLINE(  30)		shape->get_graphics()->clear();
HXLINE(  31)		shape->get_graphics()->lineStyle(2,5526612,null(),null(),null(),null(),null(),null());
HXLINE(  32)		shape->get_graphics()->moveTo(( (Float)(0) ),( (Float)(105) ));
HXLINE(  33)		shape->get_graphics()->lineTo(( (Float)(800) ),( (Float)(105) ));
HXLINE(  34)		shape->get_graphics()->moveTo(( (Float)(346) ),( (Float)(105) ));
HXLINE(  35)		shape->get_graphics()->lineTo(( (Float)(346) ),( (Float)(526) ));
HXLINE(  36)		this->addChild(shape);
HXLINE(  38)		 ::game::view::CurrencyDisplay display =  ::game::view::CurrencyDisplay_obj::__alloc( HX_CTX ,HX_("rtl",6a,e6,56,00),null());
HXLINE(  39)		display->set_x(( (Float)((::Main_obj::stageWidth - 5)) ));
HXLINE(  40)		display->set_y(( (Float)(25) ));
HXLINE(  41)		this->addChild(display);
HXLINE(  43)		this->playBtn =  ::screens::TitleMenuOption_obj::__alloc( HX_CTX ,HX_("play",f4,2d,5a,4a),36,false);
HXLINE(  44)		 ::screens::TitleMenuOption _hx_tmp = this->playBtn;
HXDLIN(  44)		_hx_tmp->set_x((( (Float)(400) ) - (this->playBtn->get_width() / ( (Float)(2) ))));
HXLINE(  45)		this->playBtn->set_y(( (Float)(520) ));
HXLINE(  46)		this->addChild(this->playBtn);
HXLINE(  47)		bool hasSlot = ::Global_obj::playerModel->hasAvailableCharSlot();
HXLINE(  48)		this->setPlayButtonEnabled(hasSlot);
HXLINE(  49)		if (hasSlot) {
HXLINE(  50)			this->playBtn->addEventListener(HX_("click",48,7c,5e,48),::classes::view::CharSkinView_obj::onPlay_dyn(),null(),null(),null());
            		}
HXLINE(  52)		this->backBtn =  ::screens::TitleMenuOption_obj::__alloc( HX_CTX ,HX_("back",27,da,10,41),22,false);
HXLINE(  53)		this->backBtn->set_x(( (Float)(30) ));
HXLINE(  54)		this->backBtn->set_y(( (Float)(534) ));
HXLINE(  55)		this->addChild(this->backBtn);
HXLINE(  56)		this->backBtn->addEventListener(HX_("click",48,7c,5e,48),::classes::view::CharSkinView_obj::onBack_dyn(),null(),null(),null());
HXLINE(  58)		 ::classes::view::CharSkinListView skinView =  ::classes::view::CharSkinListView_obj::__alloc( HX_CTX );
HXLINE(  59)		skinView->set_x(( (Float)(351) ));
HXLINE(  60)		skinView->set_y(( (Float)(110) ));
HXLINE(  61)		this->addChild(skinView);
HXLINE(  63)		 ::classes::view::ClassDetailView classView =  ::classes::view::ClassDetailView_obj::__alloc( HX_CTX );
HXLINE(  64)		classView->set_x(( (Float)(5) ));
HXLINE(  65)		classView->set_y(( (Float)(110) ));
HXLINE(  66)		this->addChild(classView);
HXLINE(  68)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null(),null(),null());
            	}

Dynamic CharSkinView_obj::__CreateEmpty() { return new CharSkinView_obj; }

void *CharSkinView_obj::_hx_vtable = 0;

Dynamic CharSkinView_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CharSkinView_obj > _hx_result = new CharSkinView_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool CharSkinView_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0fa4c293) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x0fa4c293;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void CharSkinView_obj::onAdded( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_e94d00e4384e6d73_71_onAdded)
HXLINE(  72)		this->removeEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null());
HXLINE(  73)		this->addEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinView_obj,onAdded,(void))

void CharSkinView_obj::onRemoved( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_e94d00e4384e6d73_76_onRemoved)
HXLINE(  77)		this->removeEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null());
HXLINE(  78)		if (this->playBtn->active) {
HXLINE(  79)			this->playBtn->removeEventListener(HX_("click",48,7c,5e,48),::classes::view::CharSkinView_obj::onPlay_dyn(),null());
            		}
HXLINE(  80)		this->backBtn->removeEventListener(HX_("click",48,7c,5e,48),::classes::view::CharSkinView_obj::onBack_dyn(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinView_obj,onRemoved,(void))

void CharSkinView_obj::setPlayButtonEnabled(bool activate){
            	HX_STACKFRAME(&_hx_pos_e94d00e4384e6d73_97_setPlayButtonEnabled)
HXDLIN(  97)		if (!(activate)) {
HXLINE(  98)			this->playBtn->deactivate();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinView_obj,setPlayButtonEnabled,(void))

 ::Xml CharSkinView_obj::playerXML;

void CharSkinView_obj::onBack( ::openfl::events::MouseEvent _){
            	HX_GC_STACKFRAME(&_hx_pos_e94d00e4384e6d73_84_onBack)
HXDLIN(  84)		 ::core::ScreensView _hx_tmp = ::Global_obj::layers->screens;
HXDLIN(  84)		_hx_tmp->setScreen( ::screens::NewCharacterScreen_obj::__alloc( HX_CTX ));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CharSkinView_obj,onBack,(void))

void CharSkinView_obj::onPlay( ::openfl::events::MouseEvent _){
            	HX_GC_STACKFRAME(&_hx_pos_e94d00e4384e6d73_87_onPlay)
HXLINE(  88)		 ::game::model::GameInitData game =  ::game::model::GameInitData_obj::__alloc( HX_CTX );
HXLINE(  89)		game->createCharacter = true;
HXLINE(  90)		game->charId = ::Global_obj::playerModel->getNextCharId();
HXLINE(  91)		game->gameId = -2;
HXLINE(  93)		::Global_obj::playGame(game);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CharSkinView_obj,onPlay,(void))


::hx::ObjectPtr< CharSkinView_obj > CharSkinView_obj::__new( ::Xml _playerXML) {
	::hx::ObjectPtr< CharSkinView_obj > __this = new CharSkinView_obj();
	__this->__construct(_playerXML);
	return __this;
}

::hx::ObjectPtr< CharSkinView_obj > CharSkinView_obj::__alloc(::hx::Ctx *_hx_ctx, ::Xml _playerXML) {
	CharSkinView_obj *__this = (CharSkinView_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CharSkinView_obj), true, "classes.view.CharSkinView"));
	*(void **)__this = CharSkinView_obj::_hx_vtable;
	__this->__construct(_playerXML);
	return __this;
}

CharSkinView_obj::CharSkinView_obj()
{
}

void CharSkinView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharSkinView);
	HX_MARK_MEMBER_NAME(playBtn,"playBtn");
	HX_MARK_MEMBER_NAME(backBtn,"backBtn");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CharSkinView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(playBtn,"playBtn");
	HX_VISIT_MEMBER_NAME(backBtn,"backBtn");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val CharSkinView_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"playBtn") ) { return ::hx::Val( playBtn ); }
		if (HX_FIELD_EQ(inName,"backBtn") ) { return ::hx::Val( backBtn ); }
		if (HX_FIELD_EQ(inName,"onAdded") ) { return ::hx::Val( onAdded_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onRemoved") ) { return ::hx::Val( onRemoved_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"setPlayButtonEnabled") ) { return ::hx::Val( setPlayButtonEnabled_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool CharSkinView_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onBack") ) { outValue = onBack_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"onPlay") ) { outValue = onPlay_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"playerXML") ) { outValue = ( playerXML ); return true; }
	}
	return false;
}

::hx::Val CharSkinView_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"playBtn") ) { playBtn=inValue.Cast<  ::screens::TitleMenuOption >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backBtn") ) { backBtn=inValue.Cast<  ::screens::TitleMenuOption >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool CharSkinView_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"playerXML") ) { playerXML=ioValue.Cast<  ::Xml >(); return true; }
	}
	return false;
}

void CharSkinView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("playBtn",c8,7c,fa,89));
	outFields->push(HX_("backBtn",75,32,6d,fb));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CharSkinView_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::screens::TitleMenuOption */ ,(int)offsetof(CharSkinView_obj,playBtn),HX_("playBtn",c8,7c,fa,89)},
	{::hx::fsObject /*  ::screens::TitleMenuOption */ ,(int)offsetof(CharSkinView_obj,backBtn),HX_("backBtn",75,32,6d,fb)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo CharSkinView_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::Xml */ ,(void *) &CharSkinView_obj::playerXML,HX_("playerXML",f6,b0,cc,00)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String CharSkinView_obj_sMemberFields[] = {
	HX_("playBtn",c8,7c,fa,89),
	HX_("backBtn",75,32,6d,fb),
	HX_("onAdded",21,73,81,b2),
	HX_("onRemoved",41,d8,aa,ca),
	HX_("setPlayButtonEnabled",19,34,ee,a2),
	::String(null()) };

static void CharSkinView_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CharSkinView_obj::playerXML,"playerXML");
};

#ifdef HXCPP_VISIT_ALLOCS
static void CharSkinView_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CharSkinView_obj::playerXML,"playerXML");
};

#endif

::hx::Class CharSkinView_obj::__mClass;

static ::String CharSkinView_obj_sStaticFields[] = {
	HX_("playerXML",f6,b0,cc,00),
	HX_("onBack",e6,e2,9a,e3),
	HX_("onPlay",b3,36,e4,ec),
	::String(null())
};

void CharSkinView_obj::__register()
{
	CharSkinView_obj _hx_dummy;
	CharSkinView_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("classes.view.CharSkinView",79,00,b5,62);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &CharSkinView_obj::__GetStatic;
	__mClass->mSetStaticField = &CharSkinView_obj::__SetStatic;
	__mClass->mMarkFunc = CharSkinView_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(CharSkinView_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CharSkinView_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CharSkinView_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = CharSkinView_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CharSkinView_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CharSkinView_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace classes
} // end namespace view