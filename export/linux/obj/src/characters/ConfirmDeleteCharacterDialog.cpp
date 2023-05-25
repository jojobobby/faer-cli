// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_appengine_SavedCharacter
#include <appengine/SavedCharacter.h>
#endif
#ifndef INCLUDED_characters_CharacterModel
#include <characters/CharacterModel.h>
#endif
#ifndef INCLUDED_characters_ConfirmDeleteCharacterDialog
#include <characters/ConfirmDeleteCharacterDialog.h>
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
#ifndef INCLUDED_ui_dialogs_Dialog
#include <ui/dialogs/Dialog.h>
#endif
#ifndef INCLUDED_ui_dialogs_DialogsView
#include <ui/dialogs/DialogsView.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_c962766c7f2d33c4_14_new,"characters.ConfirmDeleteCharacterDialog","new",0x970dc09c,"characters.ConfirmDeleteCharacterDialog.new","characters/ConfirmDeleteCharacterDialog.hx",14,0x560cdd73)
HX_LOCAL_STACK_FRAME(_hx_pos_c962766c7f2d33c4_19_onAdded,"characters.ConfirmDeleteCharacterDialog","onAdded",0x50fe315d,"characters.ConfirmDeleteCharacterDialog.onAdded","characters/ConfirmDeleteCharacterDialog.hx",19,0x560cdd73)
HX_LOCAL_STACK_FRAME(_hx_pos_c962766c7f2d33c4_26_setText,"characters.ConfirmDeleteCharacterDialog","setText",0xb0facbab,"characters.ConfirmDeleteCharacterDialog.setText","characters/ConfirmDeleteCharacterDialog.hx",26,0x560cdd73)
HX_LOCAL_STACK_FRAME(_hx_pos_c962766c7f2d33c4_35_onCancel,"characters.ConfirmDeleteCharacterDialog","onCancel",0xa68a9a3d,"characters.ConfirmDeleteCharacterDialog.onCancel","characters/ConfirmDeleteCharacterDialog.hx",35,0x560cdd73)
HX_LOCAL_STACK_FRAME(_hx_pos_c962766c7f2d33c4_39_onDelete,"characters.ConfirmDeleteCharacterDialog","onDelete",0x592f6cee,"characters.ConfirmDeleteCharacterDialog.onDelete","characters/ConfirmDeleteCharacterDialog.hx",39,0x560cdd73)
namespace characters{

void ConfirmDeleteCharacterDialog_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_c962766c7f2d33c4_14_new)
HXLINE(  15)		super::__construct();
HXLINE(  16)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null(),null(),null());
            	}

Dynamic ConfirmDeleteCharacterDialog_obj::__CreateEmpty() { return new ConfirmDeleteCharacterDialog_obj; }

void *ConfirmDeleteCharacterDialog_obj::_hx_vtable = 0;

Dynamic ConfirmDeleteCharacterDialog_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ConfirmDeleteCharacterDialog_obj > _hx_result = new ConfirmDeleteCharacterDialog_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool ConfirmDeleteCharacterDialog_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x6b353933) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x6b353933;
		} else {
			return inClassId==(int)0x7a5bd010;
		}
	}
}

void ConfirmDeleteCharacterDialog_obj::onAdded( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_c962766c7f2d33c4_19_onAdded)
HXLINE(  20)		this->removeEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null());
HXLINE(  22)		 ::appengine::SavedCharacter character = ::Global_obj::charModel->getSelected();
HXLINE(  23)		::String _hx_tmp = character->name();
HXDLIN(  23)		this->setText(_hx_tmp,character->displayId());
            	}


HX_DEFINE_DYNAMIC_FUNC1(ConfirmDeleteCharacterDialog_obj,onAdded,(void))

void ConfirmDeleteCharacterDialog_obj::setText(::String name,::String displayId){
            	HX_GC_STACKFRAME(&_hx_pos_c962766c7f2d33c4_26_setText)
HXLINE(  28)		 ::ui::dialogs::Dialog dialog =  ::ui::dialogs::Dialog_obj::__alloc( HX_CTX ,::StringTools_obj::replace(::StringTools_obj::replace(HX_("Are you really sure you want to delete {NAME} the {DISPLAYID}?",40,46,36,6d),HX_("{NAME}",77,29,58,42),name),HX_("{DISPLAYID}",9b,2b,c3,ba),displayId),HX_("Verify Deletion",95,74,82,b8),HX_("Cancel",9a,61,c8,ec),HX_("Delete",4b,34,6d,9f));
HXLINE(  29)		dialog->addEventListener(HX_("DIALOG_BUTTON1",48,38,81,e9),this->onCancel_dyn(),null(),null(),null());
HXLINE(  30)		dialog->addEventListener(HX_("DIALOG_BUTTON2",49,38,81,e9),this->onDelete_dyn(),null(),null(),null());
HXLINE(  31)		this->addChild(dialog);
            	}


HX_DEFINE_DYNAMIC_FUNC2(ConfirmDeleteCharacterDialog_obj,setText,(void))

void ConfirmDeleteCharacterDialog_obj::onCancel( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_c962766c7f2d33c4_35_onCancel)
HXDLIN(  35)		::Global_obj::layers->dialogs->closeDialogs();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ConfirmDeleteCharacterDialog_obj,onCancel,(void))

void ConfirmDeleteCharacterDialog_obj::onDelete( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_c962766c7f2d33c4_39_onDelete)
HXDLIN(  39)		::Global_obj::deleteChar();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ConfirmDeleteCharacterDialog_obj,onDelete,(void))


::hx::ObjectPtr< ConfirmDeleteCharacterDialog_obj > ConfirmDeleteCharacterDialog_obj::__new() {
	::hx::ObjectPtr< ConfirmDeleteCharacterDialog_obj > __this = new ConfirmDeleteCharacterDialog_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< ConfirmDeleteCharacterDialog_obj > ConfirmDeleteCharacterDialog_obj::__alloc(::hx::Ctx *_hx_ctx) {
	ConfirmDeleteCharacterDialog_obj *__this = (ConfirmDeleteCharacterDialog_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ConfirmDeleteCharacterDialog_obj), true, "characters.ConfirmDeleteCharacterDialog"));
	*(void **)__this = ConfirmDeleteCharacterDialog_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

ConfirmDeleteCharacterDialog_obj::ConfirmDeleteCharacterDialog_obj()
{
}

::hx::Val ConfirmDeleteCharacterDialog_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onAdded") ) { return ::hx::Val( onAdded_dyn() ); }
		if (HX_FIELD_EQ(inName,"setText") ) { return ::hx::Val( setText_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onCancel") ) { return ::hx::Val( onCancel_dyn() ); }
		if (HX_FIELD_EQ(inName,"onDelete") ) { return ::hx::Val( onDelete_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *ConfirmDeleteCharacterDialog_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *ConfirmDeleteCharacterDialog_obj_sStaticStorageInfo = 0;
#endif

static ::String ConfirmDeleteCharacterDialog_obj_sMemberFields[] = {
	HX_("onAdded",21,73,81,b2),
	HX_("setText",6f,0d,7e,12),
	HX_("onCancel",f9,e3,e0,97),
	HX_("onDelete",aa,b6,85,4a),
	::String(null()) };

::hx::Class ConfirmDeleteCharacterDialog_obj::__mClass;

void ConfirmDeleteCharacterDialog_obj::__register()
{
	ConfirmDeleteCharacterDialog_obj _hx_dummy;
	ConfirmDeleteCharacterDialog_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("characters.ConfirmDeleteCharacterDialog",aa,82,ca,d1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ConfirmDeleteCharacterDialog_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ConfirmDeleteCharacterDialog_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ConfirmDeleteCharacterDialog_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ConfirmDeleteCharacterDialog_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace characters