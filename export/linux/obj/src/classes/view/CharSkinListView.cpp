// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_classes_model_CharacterClass
#include <classes/model/CharacterClass.h>
#endif
#ifndef INCLUDED_classes_model_CharacterSkins
#include <classes/model/CharacterSkins.h>
#endif
#ifndef INCLUDED_classes_model_ClassModel
#include <classes/model/ClassModel.h>
#endif
#ifndef INCLUDED_classes_view_CharSkinListItem
#include <classes/view/CharSkinListItem.h>
#endif
#ifndef INCLUDED_classes_view_CharSkinListItemFactory
#include <classes/view/CharSkinListItemFactory.h>
#endif
#ifndef INCLUDED_classes_view_CharSkinListView
#include <classes/view/CharSkinListView.h>
#endif
#ifndef INCLUDED_lib_ui_api_Size
#include <lib/ui/api/Size.h>
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
#ifndef INCLUDED_ui_VerticalScrollingList
#include <ui/VerticalScrollingList.h>
#endif
#ifndef INCLUDED_util_Signal
#include <util/Signal.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_25cf5c951c45e013_18_new,"classes.view.CharSkinListView","new",0x1849d269,"classes.view.CharSkinListView.new","classes/view/CharSkinListView.hx",18,0x450e0cc7)
HX_LOCAL_STACK_FRAME(_hx_pos_25cf5c951c45e013_25_onAdded,"classes.view.CharSkinListView","onAdded",0xf93badaa,"classes.view.CharSkinListView.onAdded","classes/view/CharSkinListView.hx",25,0x450e0cc7)
HX_LOCAL_STACK_FRAME(_hx_pos_25cf5c951c45e013_33_onRemoved,"classes.view.CharSkinListView","onRemoved",0xe04f870a,"classes.view.CharSkinListView.onRemoved","classes/view/CharSkinListView.hx",33,0x450e0cc7)
HX_LOCAL_STACK_FRAME(_hx_pos_25cf5c951c45e013_40_setSkins,"classes.view.CharSkinListView","setSkins",0x288bfdab,"classes.view.CharSkinListView.setSkins","classes/view/CharSkinListView.hx",40,0x450e0cc7)
HX_LOCAL_STACK_FRAME(_hx_pos_25cf5c951c45e013_43_setItems,"classes.view.CharSkinListView","setItems",0x6c7a1255,"classes.view.CharSkinListView.setItems","classes/view/CharSkinListView.hx",43,0x450e0cc7)
HX_LOCAL_STACK_FRAME(_hx_pos_25cf5c951c45e013_56_makeList,"classes.view.CharSkinListView","makeList",0xda8a0ec3,"classes.view.CharSkinListView.makeList","classes/view/CharSkinListView.hx",56,0x450e0cc7)
HX_LOCAL_STACK_FRAME(_hx_pos_25cf5c951c45e013_65_onScrollStateChanged,"classes.view.CharSkinListView","onScrollStateChanged",0x59f79766,"classes.view.CharSkinListView.onScrollStateChanged","classes/view/CharSkinListView.hx",65,0x450e0cc7)
namespace classes{
namespace view{

void CharSkinListView_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_25cf5c951c45e013_18_new)
HXLINE(  19)		super::__construct();
HXLINE(  21)		this->list = this->makeList();
HXLINE(  22)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null(),null(),null());
            	}

Dynamic CharSkinListView_obj::__CreateEmpty() { return new CharSkinListView_obj; }

void *CharSkinListView_obj::_hx_vtable = 0;

Dynamic CharSkinListView_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CharSkinListView_obj > _hx_result = new CharSkinListView_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CharSkinListView_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x680724a1) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x680724a1;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void CharSkinListView_obj::onAdded( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_25cf5c951c45e013_25_onAdded)
HXLINE(  26)		this->removeEventListener(HX_("addedToStage",63,22,55,0c),this->onAdded_dyn(),null());
HXLINE(  27)		this->addEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null(),null(),null());
HXLINE(  29)		::Global_obj::classModel->selected->on(this->setSkins_dyn());
HXLINE(  30)		this->setSkins(::Global_obj::classModel->getSelected());
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinListView_obj,onAdded,(void))

void CharSkinListView_obj::onRemoved( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_25cf5c951c45e013_33_onRemoved)
HXLINE(  34)		this->removeEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemoved_dyn(),null());
HXLINE(  36)		::Global_obj::classModel->selected->off(this->setSkins_dyn());
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinListView_obj,onRemoved,(void))

void CharSkinListView_obj::setSkins( ::classes::model::CharacterClass charClass){
            	HX_STACKFRAME(&_hx_pos_25cf5c951c45e013_40_setSkins)
HXDLIN(  40)		this->setItems(::classes::view::CharSkinListItemFactory_obj::make(charClass->skins));
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinListView_obj,setSkins,(void))

void CharSkinListView_obj::setItems(::Array< ::Dynamic> items){
            	HX_STACKFRAME(&_hx_pos_25cf5c951c45e013_43_setItems)
HXLINE(  44)		this->items = items;
HXLINE(  45)		::Array< ::Dynamic> doItems = ::Array_obj< ::Dynamic>::__new();
HXLINE(  46)		{
HXLINE(  46)			int _g = 0;
HXDLIN(  46)			while((_g < items->length)){
HXLINE(  46)				 ::classes::view::CharSkinListItem item = items->__get(_g).StaticCast<  ::classes::view::CharSkinListItem >();
HXDLIN(  46)				_g = (_g + 1);
HXLINE(  47)				doItems->push(( ( ::openfl::display::DisplayObject)(item) ));
            			}
            		}
HXLINE(  48)		this->list->setItems(doItems);
HXLINE(  49)		this->onScrollStateChanged(this->list->isScrollbarVisible());
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinListView_obj,setItems,(void))

 ::ui::VerticalScrollingList CharSkinListView_obj::makeList(){
            	HX_GC_STACKFRAME(&_hx_pos_25cf5c951c45e013_56_makeList)
HXLINE(  57)		 ::ui::VerticalScrollingList list =  ::ui::VerticalScrollingList_obj::__alloc( HX_CTX );
HXLINE(  58)		list->setSize( ::lib::ui::api::Size_obj::__alloc( HX_CTX ,442,400));
HXLINE(  59)		list->scrollStateChanged->on(this->onScrollStateChanged_dyn());
HXLINE(  60)		list->setPadding(5);
HXLINE(  61)		this->addChild(list);
HXLINE(  62)		return list;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CharSkinListView_obj,makeList,return )

void CharSkinListView_obj::onScrollStateChanged(bool isVisible){
            	HX_STACKFRAME(&_hx_pos_25cf5c951c45e013_65_onScrollStateChanged)
HXLINE(  67)		int width = 420;
HXLINE(  68)		if (!(isVisible)) {
HXLINE(  69)			width = 442;
            		}
HXLINE(  71)		{
HXLINE(  71)			int _g = 0;
HXDLIN(  71)			::Array< ::Dynamic> _g1 = this->items;
HXDLIN(  71)			while((_g < _g1->length)){
HXLINE(  71)				 ::classes::view::CharSkinListItem item = _g1->__get(_g).StaticCast<  ::classes::view::CharSkinListItem >();
HXDLIN(  71)				_g = (_g + 1);
HXLINE(  72)				item->set_width(( (Float)(width) ));
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharSkinListView_obj,onScrollStateChanged,(void))


::hx::ObjectPtr< CharSkinListView_obj > CharSkinListView_obj::__new() {
	::hx::ObjectPtr< CharSkinListView_obj > __this = new CharSkinListView_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CharSkinListView_obj > CharSkinListView_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CharSkinListView_obj *__this = (CharSkinListView_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CharSkinListView_obj), true, "classes.view.CharSkinListView"));
	*(void **)__this = CharSkinListView_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CharSkinListView_obj::CharSkinListView_obj()
{
}

void CharSkinListView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharSkinListView);
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_MEMBER_NAME(items,"items");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CharSkinListView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(list,"list");
	HX_VISIT_MEMBER_NAME(items,"items");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val CharSkinListView_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return ::hx::Val( list ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"items") ) { return ::hx::Val( items ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onAdded") ) { return ::hx::Val( onAdded_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setSkins") ) { return ::hx::Val( setSkins_dyn() ); }
		if (HX_FIELD_EQ(inName,"setItems") ) { return ::hx::Val( setItems_dyn() ); }
		if (HX_FIELD_EQ(inName,"makeList") ) { return ::hx::Val( makeList_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onRemoved") ) { return ::hx::Val( onRemoved_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"onScrollStateChanged") ) { return ::hx::Val( onScrollStateChanged_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CharSkinListView_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast<  ::ui::VerticalScrollingList >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"items") ) { items=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CharSkinListView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("list",5e,1c,b3,47));
	outFields->push(HX_("items",00,ac,0c,c2));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CharSkinListView_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::VerticalScrollingList */ ,(int)offsetof(CharSkinListView_obj,list),HX_("list",5e,1c,b3,47)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(CharSkinListView_obj,items),HX_("items",00,ac,0c,c2)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CharSkinListView_obj_sStaticStorageInfo = 0;
#endif

static ::String CharSkinListView_obj_sMemberFields[] = {
	HX_("list",5e,1c,b3,47),
	HX_("items",00,ac,0c,c2),
	HX_("onAdded",21,73,81,b2),
	HX_("onRemoved",41,d8,aa,ca),
	HX_("setSkins",54,00,53,8c),
	HX_("setItems",fe,14,41,d0),
	HX_("makeList",6c,11,51,3e),
	HX_("onScrollStateChanged",8f,73,4c,59),
	::String(null()) };

::hx::Class CharSkinListView_obj::__mClass;

void CharSkinListView_obj::__register()
{
	CharSkinListView_obj _hx_dummy;
	CharSkinListView_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("classes.view.CharSkinListView",f7,69,ac,e8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CharSkinListView_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CharSkinListView_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CharSkinListView_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CharSkinListView_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace classes
} // end namespace view
