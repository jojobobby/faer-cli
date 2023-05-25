// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_mapeditor_EditTilePropertiesFrame
#include <mapeditor/EditTilePropertiesFrame.h>
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
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_ui_ClickableText
#include <ui/ClickableText.h>
#endif
#ifndef INCLUDED_ui_Frame
#include <ui/Frame.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_TextInputField
#include <ui/TextInputField.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_d43263b9299e4cfd_11_new,"mapeditor.EditTilePropertiesFrame","new",0x76abe4ef,"mapeditor.EditTilePropertiesFrame.new","mapeditor/EditTilePropertiesFrame.hx",11,0x27a90aa2)
HX_LOCAL_STACK_FRAME(_hx_pos_d43263b9299e4cfd_23_onCancel,"mapeditor.EditTilePropertiesFrame","onCancel",0x72c8e90a,"mapeditor.EditTilePropertiesFrame.onCancel","mapeditor/EditTilePropertiesFrame.hx",23,0x27a90aa2)
HX_LOCAL_STACK_FRAME(_hx_pos_d43263b9299e4cfd_27_onDone,"mapeditor.EditTilePropertiesFrame","onDone",0x8c69e812,"mapeditor.EditTilePropertiesFrame.onDone","mapeditor/EditTilePropertiesFrame.hx",27,0x27a90aa2)
namespace mapeditor{

void EditTilePropertiesFrame_obj::__construct(::String oldName){
            	HX_GC_STACKFRAME(&_hx_pos_d43263b9299e4cfd_11_new)
HXLINE(  12)		super::__construct(HX_("Tile properties",85,33,3f,96),HX_("Cancel",9a,61,c8,ec),HX_("Save",5d,b7,26,37),288);
HXLINE(  13)		this->objectName =  ::ui::TextInputField_obj::__alloc( HX_CTX ,HX_("Object Name",4c,73,df,60),false,HX_("",00,00,00,00));
HXLINE(  14)		if (::hx::IsNotNull( oldName )) {
HXLINE(  15)			this->objectName->inputText->set_text(oldName);
            		}
HXLINE(  17)		this->addTextInputField(this->objectName);
HXLINE(  18)		this->leftButton->addEventListener(HX_("click",48,7c,5e,48),this->onCancel_dyn(),null(),null(),null());
HXLINE(  19)		this->rightButton->addEventListener(HX_("click",48,7c,5e,48),this->onDone_dyn(),null(),null(),null());
            	}

Dynamic EditTilePropertiesFrame_obj::__CreateEmpty() { return new EditTilePropertiesFrame_obj; }

void *EditTilePropertiesFrame_obj::_hx_vtable = 0;

Dynamic EditTilePropertiesFrame_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< EditTilePropertiesFrame_obj > _hx_result = new EditTilePropertiesFrame_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool EditTilePropertiesFrame_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x323b7001) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x323b7001;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x3517a2f1 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void EditTilePropertiesFrame_obj::onCancel( ::openfl::events::MouseEvent event){
            	HX_GC_STACKFRAME(&_hx_pos_d43263b9299e4cfd_23_onCancel)
HXDLIN(  23)		this->dispatchEvent( ::openfl::events::Event_obj::__alloc( HX_CTX ,HX_("cancel",7a,ed,33,b8),null(),null()));
            	}


HX_DEFINE_DYNAMIC_FUNC1(EditTilePropertiesFrame_obj,onCancel,(void))

void EditTilePropertiesFrame_obj::onDone( ::openfl::events::MouseEvent event){
            	HX_GC_STACKFRAME(&_hx_pos_d43263b9299e4cfd_27_onDone)
HXDLIN(  27)		this->dispatchEvent( ::openfl::events::Event_obj::__alloc( HX_CTX ,HX_("complete",b9,00,c8,7f),null(),null()));
            	}


HX_DEFINE_DYNAMIC_FUNC1(EditTilePropertiesFrame_obj,onDone,(void))


::hx::ObjectPtr< EditTilePropertiesFrame_obj > EditTilePropertiesFrame_obj::__new(::String oldName) {
	::hx::ObjectPtr< EditTilePropertiesFrame_obj > __this = new EditTilePropertiesFrame_obj();
	__this->__construct(oldName);
	return __this;
}

::hx::ObjectPtr< EditTilePropertiesFrame_obj > EditTilePropertiesFrame_obj::__alloc(::hx::Ctx *_hx_ctx,::String oldName) {
	EditTilePropertiesFrame_obj *__this = (EditTilePropertiesFrame_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(EditTilePropertiesFrame_obj), true, "mapeditor.EditTilePropertiesFrame"));
	*(void **)__this = EditTilePropertiesFrame_obj::_hx_vtable;
	__this->__construct(oldName);
	return __this;
}

EditTilePropertiesFrame_obj::EditTilePropertiesFrame_obj()
{
}

void EditTilePropertiesFrame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EditTilePropertiesFrame);
	HX_MARK_MEMBER_NAME(objectName,"objectName");
	 ::ui::Frame_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EditTilePropertiesFrame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(objectName,"objectName");
	 ::ui::Frame_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val EditTilePropertiesFrame_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onDone") ) { return ::hx::Val( onDone_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onCancel") ) { return ::hx::Val( onCancel_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"objectName") ) { return ::hx::Val( objectName ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val EditTilePropertiesFrame_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"objectName") ) { objectName=inValue.Cast<  ::ui::TextInputField >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EditTilePropertiesFrame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("objectName",aa,e8,37,cb));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo EditTilePropertiesFrame_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::TextInputField */ ,(int)offsetof(EditTilePropertiesFrame_obj,objectName),HX_("objectName",aa,e8,37,cb)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *EditTilePropertiesFrame_obj_sStaticStorageInfo = 0;
#endif

static ::String EditTilePropertiesFrame_obj_sMemberFields[] = {
	HX_("objectName",aa,e8,37,cb),
	HX_("onCancel",f9,e3,e0,97),
	HX_("onDone",41,f9,f7,e4),
	::String(null()) };

::hx::Class EditTilePropertiesFrame_obj::__mClass;

void EditTilePropertiesFrame_obj::__register()
{
	EditTilePropertiesFrame_obj _hx_dummy;
	EditTilePropertiesFrame_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("mapeditor.EditTilePropertiesFrame",7d,41,a5,9c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(EditTilePropertiesFrame_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< EditTilePropertiesFrame_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = EditTilePropertiesFrame_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = EditTilePropertiesFrame_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mapeditor
