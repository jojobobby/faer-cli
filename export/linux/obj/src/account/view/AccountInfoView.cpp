// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_account_Account
#include <account/Account.h>
#endif
#ifndef INCLUDED_account_view_AccountInfoView
#include <account/view/AccountInfoView.h>
#endif
#ifndef INCLUDED_account_view_LoginDialog
#include <account/view/LoginDialog.h>
#endif
#ifndef INCLUDED_account_view_RegisterDialog
#include <account/view/RegisterDialog.h>
#endif
#ifndef INCLUDED_classes_model_CharacterClass
#include <classes/model/CharacterClass.h>
#endif
#ifndef INCLUDED_classes_model_CharacterSkin
#include <classes/model/CharacterSkin.h>
#endif
#ifndef INCLUDED_classes_model_CharacterSkinState
#include <classes/model/CharacterSkinState.h>
#endif
#ifndef INCLUDED_classes_model_CharacterSkins
#include <classes/model/CharacterSkins.h>
#endif
#ifndef INCLUDED_classes_model_ClassModel
#include <classes/model/ClassModel.h>
#endif
#ifndef INCLUDED_core_Layers
#include <core/Layers.h>
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
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_screens_TitleMenuOption
#include <screens/TitleMenuOption.h>
#endif
#ifndef INCLUDED_ui_Frame
#include <ui/Frame.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_dialogs_DialogsView
#include <ui/dialogs/DialogsView.h>
#endif
#ifndef INCLUDED_util_EmptySignal
#include <util/EmptySignal.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_56cb93581016549a_17_new,"account.view.AccountInfoView","new",0xb05239ea,"account.view.AccountInfoView.new","account/view/AccountInfoView.hx",17,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_49_onAdded,"account.view.AccountInfoView","onAdded",0xc1b469ab,"account.view.AccountInfoView.onAdded","account/view/AccountInfoView.hx",49,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_57_onRemoved,"account.view.AccountInfoView","onRemoved",0x4570054b,"account.view.AccountInfoView.onRemoved","account/view/AccountInfoView.hx",57,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_65_updateLogin,"account.view.AccountInfoView","updateLogin",0xf6be462a,"account.view.AccountInfoView.updateLogin","account/view/AccountInfoView.hx",65,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_73_onLoginToggle,"account.view.AccountInfoView","onLoginToggle",0xa34e1908,"account.view.AccountInfoView.onLoginToggle","account/view/AccountInfoView.hx",73,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_99_setInfo,"account.view.AccountInfoView","setInfo",0x1a726fba,"account.view.AccountInfoView.setInfo","account/view/AccountInfoView.hx",99,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_105_updateUI,"account.view.AccountInfoView","updateUI",0xb55ee6d3,"account.view.AccountInfoView.updateUI","account/view/AccountInfoView.hx",105,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_114_removeUIElements,"account.view.AccountInfoView","removeUIElements",0xd1e1b225,"account.view.AccountInfoView.removeUIElements","account/view/AccountInfoView.hx",114,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_118_showUIForRegisteredAccount,"account.view.AccountInfoView","showUIForRegisteredAccount",0xde7db4e9,"account.view.AccountInfoView.showUIForRegisteredAccount","account/view/AccountInfoView.hx",118,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_125_showUIForGuestAccount,"account.view.AccountInfoView","showUIForGuestAccount",0xdc513bd7,"account.view.AccountInfoView.showUIForGuestAccount","account/view/AccountInfoView.hx",125,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_132_addAndAlignHorizontally,"account.view.AccountInfoView","addAndAlignHorizontally",0x7dc6754a,"account.view.AccountInfoView.addAndAlignHorizontally","account/view/AccountInfoView.hx",132,0x854ee526)
HX_LOCAL_STACK_FRAME(_hx_pos_56cb93581016549a_69_onRegister,"account.view.AccountInfoView","onRegister",0xa018b658,"account.view.AccountInfoView.onRegister","account/view/AccountInfoView.hx",69,0x854ee526)
namespace account{
namespace view{

void AccountInfoView_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_56cb93581016549a_17_new)
HXLINE(  26)		this->isRegistered = false;
HXLINE(  25)		this->userName = HX_("",00,00,00,00);
HXLINE(  33)		super::__construct();
HXLINE(  35)		this->accountText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,18,11776947,false,0,0,null());
HXLINE(  36)		 ::ui::SimpleText _hx_tmp = this->accountText;
HXDLIN(  36)		_hx_tmp->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,4,4,null(),null(),null(),null(),null())));
HXLINE(  37)		this->loginButton =  ::screens::TitleMenuOption_obj::__alloc( HX_CTX ,HX_("log in",01,fa,32,5c),18,false);
HXLINE(  38)		this->loginButton->addEventListener(HX_("click",48,7c,5e,48),this->onLoginToggle_dyn(),null(),null(),null());
HXLINE(  39)		this->registerButton =  ::screens::TitleMenuOption_obj::__alloc( HX_CTX ,HX_("register",63,a6,9f,d0),18,false);
HXLINE(  40)		this->registerButton->addEventListener(HX_("click",48,7c,5e,48),::account::view::AccountInfoView_obj::onRegister_dyn(),null(),null(),null());
HXLINE(  41)		this->dividerText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,18,11776947,false,0,0,null());
HXLINE(  42)		 ::ui::SimpleText _hx_tmp1 = this->dividerText;
HXDLIN(  42)		_hx_tmp1->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,4,4,null(),null(),null(),null(),null())));
HXLINE(  43)		this->dividerText->set_text(HX_(" - ",73,6f,18,00));
HXLINE(  44)		this->dividerText->updateMetrics();
HXLINE(  46)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null(),null(),null());
            	}

Dynamic AccountInfoView_obj::__CreateEmpty() { return new AccountInfoView_obj; }

void *AccountInfoView_obj::_hx_vtable = 0;

Dynamic AccountInfoView_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< AccountInfoView_obj > _hx_result = new AccountInfoView_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool AccountInfoView_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x52704efa) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x52704efa;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void AccountInfoView_obj::onAdded( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_49_onAdded)
HXLINE(  50)		this->removeEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null());
HXLINE(  51)		this->addEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null(),null(),null());
HXLINE(  53)		this->setInfo(::account::Account_obj::userName,(::account::Account_obj::password != HX_("",00,00,00,00)));
HXLINE(  54)		::Global_obj::updateAccount->once(this->updateLogin_dyn());
            	}


HX_DEFINE_DYNAMIC_FUNC1(AccountInfoView_obj,onAdded,(void))

void AccountInfoView_obj::onRemoved( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_57_onRemoved)
HXLINE(  58)		this->removeEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null());
HXLINE(  60)		this->loginButton->removeEventListener(HX_("click",48,7c,5e,48),this->onLoginToggle_dyn(),null());
HXLINE(  61)		this->registerButton->removeEventListener(HX_("click",48,7c,5e,48),::account::view::AccountInfoView_obj::onRegister_dyn(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(AccountInfoView_obj,onRemoved,(void))

void AccountInfoView_obj::updateLogin(){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_65_updateLogin)
HXDLIN(  65)		this->setInfo(::account::Account_obj::userName,(::account::Account_obj::password != HX_("",00,00,00,00)));
            	}


HX_DEFINE_DYNAMIC_FUNC0(AccountInfoView_obj,updateLogin,(void))

void AccountInfoView_obj::onLoginToggle( ::openfl::events::MouseEvent _){
            	HX_GC_STACKFRAME(&_hx_pos_56cb93581016549a_73_onLoginToggle)
HXDLIN(  73)		if ((::account::Account_obj::password != HX_("",00,00,00,00))) {
HXLINE(  74)			::account::Account_obj::clear();
HXLINE(  78)			int count = ::Global_obj::classModel->getCount();
HXLINE(  79)			 ::classes::model::CharacterClass charClass;
HXLINE(  80)			{
HXLINE(  80)				int _g = 0;
HXDLIN(  80)				while((_g < count)){
HXLINE(  80)					_g = (_g + 1);
HXLINE(  81)					charClass = ::Global_obj::classModel->getClassAtIndex((_g - 1));
HXLINE(  83)					charClass->setIsSelected((charClass->id == 782));
HXLINE(  84)					 ::classes::model::CharacterSkin skin = null();
HXLINE(  85)					 ::classes::model::CharacterSkin defaultSkin = charClass->skins->getDefaultSkin();
HXLINE(  86)					int skinCount = charClass->skins->getCount();
HXLINE(  87)					{
HXLINE(  87)						int _g1 = 0;
HXDLIN(  87)						while((_g1 < skinCount)){
HXLINE(  87)							_g1 = (_g1 + 1);
HXDLIN(  87)							int j = (_g1 - 1);
HXLINE(  88)							skin = charClass->skins->getSkinAt(j);
HXLINE(  89)							if (::hx::IsInstanceNotEq( skin,defaultSkin )) {
HXLINE(  90)								charClass->skins->getSkinAt(j)->setState(::classes::model::CharacterSkinState_obj::LOCKED);
            							}
            						}
            					}
            				}
            			}
HXLINE(  94)			this->setInfo(HX_("",00,00,00,00),false);
            		}
            		else {
HXLINE(  96)			 ::ui::dialogs::DialogsView _hx_tmp = ::Global_obj::layers->dialogs;
HXDLIN(  96)			_hx_tmp->openDialog( ::account::view::LoginDialog_obj::__alloc( HX_CTX ));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(AccountInfoView_obj,onLoginToggle,(void))

void AccountInfoView_obj::setInfo(::String userName,bool isRegistered){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_99_setInfo)
HXLINE( 100)		this->userName = userName;
HXLINE( 101)		this->isRegistered = isRegistered;
HXLINE( 102)		this->updateUI();
            	}


HX_DEFINE_DYNAMIC_FUNC2(AccountInfoView_obj,setInfo,(void))

void AccountInfoView_obj::updateUI(){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_105_updateUI)
HXLINE( 106)		this->removeUIElements();
HXLINE( 107)		if (this->isRegistered) {
HXLINE( 108)			this->showUIForRegisteredAccount();
            		}
            		else {
HXLINE( 110)			this->showUIForGuestAccount();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(AccountInfoView_obj,updateUI,(void))

void AccountInfoView_obj::removeUIElements(){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_114_removeUIElements)
HXDLIN( 114)		while((this->get_numChildren() > 0)){
HXLINE( 115)			this->removeChildAt(0);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(AccountInfoView_obj,removeUIElements,(void))

void AccountInfoView_obj::showUIForRegisteredAccount(){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_118_showUIForRegisteredAccount)
HXLINE( 119)		 ::ui::SimpleText _hx_tmp = this->accountText;
HXDLIN( 119)		_hx_tmp->set_text(::StringTools_obj::replace(HX_("logged in as {userName} - ",96,db,4e,e0),HX_("{userName}",ac,d5,1e,a4),this->userName));
HXLINE( 120)		this->accountText->updateMetrics();
HXLINE( 121)		this->loginButton->setText(HX_("log out",f2,5a,6c,50));
HXLINE( 122)		this->addAndAlignHorizontally(::Array_obj< ::Dynamic>::__new(2)->init(0,this->accountText)->init(1,this->loginButton));
            	}


HX_DEFINE_DYNAMIC_FUNC0(AccountInfoView_obj,showUIForRegisteredAccount,(void))

void AccountInfoView_obj::showUIForGuestAccount(){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_125_showUIForGuestAccount)
HXLINE( 126)		this->accountText->set_text(HX_("guest account - ",2e,c5,43,46));
HXLINE( 127)		this->accountText->updateMetrics();
HXLINE( 128)		this->loginButton->setText(HX_("log in",01,fa,32,5c));
HXLINE( 129)		this->addAndAlignHorizontally(::Array_obj< ::Dynamic>::__new(4)->init(0,this->accountText)->init(1,this->registerButton)->init(2,this->dividerText)->init(3,this->loginButton));
            	}


HX_DEFINE_DYNAMIC_FUNC0(AccountInfoView_obj,showUIForGuestAccount,(void))

void AccountInfoView_obj::addAndAlignHorizontally(::Array< ::Dynamic> uiElements){
            	HX_STACKFRAME(&_hx_pos_56cb93581016549a_132_addAndAlignHorizontally)
HXLINE( 133)		Float x = ((Float)0.0);
HXLINE( 134)		int i = uiElements->length;
HXLINE( 135)		while(true){
HXLINE( 135)			i = (i - 1);
HXDLIN( 135)			if (!(((i + 1) > 0))) {
HXLINE( 135)				goto _hx_goto_13;
            			}
HXLINE( 136)			 ::openfl::display::DisplayObject ui = uiElements->__get(i).StaticCast<  ::openfl::display::DisplayObject >();
HXLINE( 137)			x = (x - ui->get_width());
HXLINE( 138)			ui->set_x(x);
HXLINE( 139)			this->addChild(ui);
            		}
            		_hx_goto_13:;
            	}


HX_DEFINE_DYNAMIC_FUNC1(AccountInfoView_obj,addAndAlignHorizontally,(void))

void AccountInfoView_obj::onRegister( ::openfl::events::MouseEvent _){
            	HX_GC_STACKFRAME(&_hx_pos_56cb93581016549a_69_onRegister)
HXDLIN(  69)		 ::ui::dialogs::DialogsView _hx_tmp = ::Global_obj::layers->dialogs;
HXDLIN(  69)		_hx_tmp->openDialog( ::account::view::RegisterDialog_obj::__alloc( HX_CTX ));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AccountInfoView_obj,onRegister,(void))


::hx::ObjectPtr< AccountInfoView_obj > AccountInfoView_obj::__new() {
	::hx::ObjectPtr< AccountInfoView_obj > __this = new AccountInfoView_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< AccountInfoView_obj > AccountInfoView_obj::__alloc(::hx::Ctx *_hx_ctx) {
	AccountInfoView_obj *__this = (AccountInfoView_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(AccountInfoView_obj), true, "account.view.AccountInfoView"));
	*(void **)__this = AccountInfoView_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

AccountInfoView_obj::AccountInfoView_obj()
{
}

void AccountInfoView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AccountInfoView);
	HX_MARK_MEMBER_NAME(userName,"userName");
	HX_MARK_MEMBER_NAME(isRegistered,"isRegistered");
	HX_MARK_MEMBER_NAME(accountText,"accountText");
	HX_MARK_MEMBER_NAME(registerButton,"registerButton");
	HX_MARK_MEMBER_NAME(dividerText,"dividerText");
	HX_MARK_MEMBER_NAME(loginButton,"loginButton");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AccountInfoView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(userName,"userName");
	HX_VISIT_MEMBER_NAME(isRegistered,"isRegistered");
	HX_VISIT_MEMBER_NAME(accountText,"accountText");
	HX_VISIT_MEMBER_NAME(registerButton,"registerButton");
	HX_VISIT_MEMBER_NAME(dividerText,"dividerText");
	HX_VISIT_MEMBER_NAME(loginButton,"loginButton");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val AccountInfoView_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onAdded") ) { return ::hx::Val( onAdded_dyn() ); }
		if (HX_FIELD_EQ(inName,"setInfo") ) { return ::hx::Val( setInfo_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userName") ) { return ::hx::Val( userName ); }
		if (HX_FIELD_EQ(inName,"updateUI") ) { return ::hx::Val( updateUI_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onRemoved") ) { return ::hx::Val( onRemoved_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"accountText") ) { return ::hx::Val( accountText ); }
		if (HX_FIELD_EQ(inName,"dividerText") ) { return ::hx::Val( dividerText ); }
		if (HX_FIELD_EQ(inName,"loginButton") ) { return ::hx::Val( loginButton ); }
		if (HX_FIELD_EQ(inName,"updateLogin") ) { return ::hx::Val( updateLogin_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isRegistered") ) { return ::hx::Val( isRegistered ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onLoginToggle") ) { return ::hx::Val( onLoginToggle_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"registerButton") ) { return ::hx::Val( registerButton ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeUIElements") ) { return ::hx::Val( removeUIElements_dyn() ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"showUIForGuestAccount") ) { return ::hx::Val( showUIForGuestAccount_dyn() ); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"addAndAlignHorizontally") ) { return ::hx::Val( addAndAlignHorizontally_dyn() ); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"showUIForRegisteredAccount") ) { return ::hx::Val( showUIForRegisteredAccount_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool AccountInfoView_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"onRegister") ) { outValue = onRegister_dyn(); return true; }
	}
	return false;
}

::hx::Val AccountInfoView_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"userName") ) { userName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"accountText") ) { accountText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dividerText") ) { dividerText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loginButton") ) { loginButton=inValue.Cast<  ::screens::TitleMenuOption >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isRegistered") ) { isRegistered=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"registerButton") ) { registerButton=inValue.Cast<  ::screens::TitleMenuOption >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AccountInfoView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("userName",36,b2,c4,0b));
	outFields->push(HX_("isRegistered",0c,c6,bf,c6));
	outFields->push(HX_("accountText",fa,4f,2d,90));
	outFields->push(HX_("registerButton",b5,e8,21,a0));
	outFields->push(HX_("dividerText",26,34,53,62));
	outFields->push(HX_("loginButton",3b,24,9f,ff));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo AccountInfoView_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(AccountInfoView_obj,userName),HX_("userName",36,b2,c4,0b)},
	{::hx::fsBool,(int)offsetof(AccountInfoView_obj,isRegistered),HX_("isRegistered",0c,c6,bf,c6)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(AccountInfoView_obj,accountText),HX_("accountText",fa,4f,2d,90)},
	{::hx::fsObject /*  ::screens::TitleMenuOption */ ,(int)offsetof(AccountInfoView_obj,registerButton),HX_("registerButton",b5,e8,21,a0)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(AccountInfoView_obj,dividerText),HX_("dividerText",26,34,53,62)},
	{::hx::fsObject /*  ::screens::TitleMenuOption */ ,(int)offsetof(AccountInfoView_obj,loginButton),HX_("loginButton",3b,24,9f,ff)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *AccountInfoView_obj_sStaticStorageInfo = 0;
#endif

static ::String AccountInfoView_obj_sMemberFields[] = {
	HX_("userName",36,b2,c4,0b),
	HX_("isRegistered",0c,c6,bf,c6),
	HX_("accountText",fa,4f,2d,90),
	HX_("registerButton",b5,e8,21,a0),
	HX_("dividerText",26,34,53,62),
	HX_("loginButton",3b,24,9f,ff),
	HX_("onAdded",21,73,81,b2),
	HX_("onRemoved",41,d8,aa,ca),
	HX_("updateLogin",a0,42,8c,5e),
	HX_("onLoginToggle",fe,9e,ec,17),
	HX_("setInfo",30,79,3f,0b),
	HX_("updateUI",9d,24,fa,77),
	HX_("removeUIElements",ef,c9,fe,1f),
	HX_("showUIForRegisteredAccount",33,2d,fe,7d),
	HX_("showUIForGuestAccount",cd,a7,77,3e),
	HX_("addAndAlignHorizontally",c0,4a,58,87),
	::String(null()) };

::hx::Class AccountInfoView_obj::__mClass;

static ::String AccountInfoView_obj_sStaticFields[] = {
	HX_("onRegister",a2,7a,56,ae),
	::String(null())
};

void AccountInfoView_obj::__register()
{
	AccountInfoView_obj _hx_dummy;
	AccountInfoView_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("account.view.AccountInfoView",f8,bc,28,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &AccountInfoView_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(AccountInfoView_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(AccountInfoView_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< AccountInfoView_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = AccountInfoView_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = AccountInfoView_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace account
} // end namespace view
