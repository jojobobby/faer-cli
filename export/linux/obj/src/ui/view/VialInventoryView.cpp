// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

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
#ifndef INCLUDED_ui_view_VialInventoryView
#include <ui/view/VialInventoryView.h>
#endif
#ifndef INCLUDED_ui_view_VialSlotView
#include <ui/view/VialSlotView.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_d4f70f89e48fe194_15_new,"ui.view.VialInventoryView","new",0x0b406ec6,"ui.view.VialInventoryView.new","ui/view/VialInventoryView.hx",15,0xf005d7ca)
HX_LOCAL_STACK_FRAME(_hx_pos_d4f70f89e48fe194_6_boot,"ui.view.VialInventoryView","boot",0xc5397f0c,"ui.view.VialInventoryView.boot","ui/view/VialInventoryView.hx",6,0xf005d7ca)
static const int _hx_array_data_736c53d4_2[] = {
	(int)1,(int)0,(int)0,(int)1,
};
HX_LOCAL_STACK_FRAME(_hx_pos_d4f70f89e48fe194_7_boot,"ui.view.VialInventoryView","boot",0xc5397f0c,"ui.view.VialInventoryView.boot","ui/view/VialInventoryView.hx",7,0xf005d7ca)
static const int _hx_array_data_736c53d4_4[] = {
	(int)0,(int)1,(int)1,(int)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_d4f70f89e48fe194_8_boot,"ui.view.VialInventoryView","boot",0xc5397f0c,"ui.view.VialInventoryView.boot","ui/view/VialInventoryView.hx",8,0xf005d7ca)
static const int _hx_array_data_736c53d4_6[] = {
	(int)1,(int)1,(int)1,(int)1,
};
namespace ui{
namespace view{

void VialInventoryView_obj::__construct(bool noMP){
            	HX_GC_STACKFRAME(&_hx_pos_d4f70f89e48fe194_15_new)
HXLINE(  16)		super::__construct();
HXLINE(  18)		::Array< int > _hx_tmp;
HXDLIN(  18)		if (noMP) {
HXLINE(  18)			_hx_tmp = ::ui::view::VialInventoryView_obj::SINGLE_BUTTON_CUTS;
            		}
            		else {
HXLINE(  18)			_hx_tmp = ::ui::view::VialInventoryView_obj::LEFT_BUTTON_CUTS;
            		}
HXDLIN(  18)		this->leftSlot =  ::ui::view::VialSlotView_obj::__alloc( HX_CTX ,_hx_tmp,0,noMP);
HXLINE(  19)		this->leftSlot->set_cacheAsBitmap(true);
HXLINE(  20)		this->addChild(this->leftSlot);
HXLINE(  22)		if (noMP) {
HXLINE(  23)			return;
            		}
HXLINE(  25)		this->rightSlot =  ::ui::view::VialSlotView_obj::__alloc( HX_CTX ,::ui::view::VialInventoryView_obj::RIGHT_BUTTON_CUTS,1,false);
HXLINE(  26)		this->rightSlot->set_cacheAsBitmap(true);
HXLINE(  27)		this->rightSlot->set_x(( (Float)(42) ));
HXLINE(  28)		this->addChild(this->rightSlot);
            	}

Dynamic VialInventoryView_obj::__CreateEmpty() { return new VialInventoryView_obj; }

void *VialInventoryView_obj::_hx_vtable = 0;

Dynamic VialInventoryView_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< VialInventoryView_obj > _hx_result = new VialInventoryView_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool VialInventoryView_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0c89e854) {
		if (inClassId<=(int)0x0752cd5a) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0752cd5a;
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

::Array< int > VialInventoryView_obj::LEFT_BUTTON_CUTS;

::Array< int > VialInventoryView_obj::RIGHT_BUTTON_CUTS;

::Array< int > VialInventoryView_obj::SINGLE_BUTTON_CUTS;


::hx::ObjectPtr< VialInventoryView_obj > VialInventoryView_obj::__new(bool noMP) {
	::hx::ObjectPtr< VialInventoryView_obj > __this = new VialInventoryView_obj();
	__this->__construct(noMP);
	return __this;
}

::hx::ObjectPtr< VialInventoryView_obj > VialInventoryView_obj::__alloc(::hx::Ctx *_hx_ctx,bool noMP) {
	VialInventoryView_obj *__this = (VialInventoryView_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(VialInventoryView_obj), true, "ui.view.VialInventoryView"));
	*(void **)__this = VialInventoryView_obj::_hx_vtable;
	__this->__construct(noMP);
	return __this;
}

VialInventoryView_obj::VialInventoryView_obj()
{
}

void VialInventoryView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VialInventoryView);
	HX_MARK_MEMBER_NAME(leftSlot,"leftSlot");
	HX_MARK_MEMBER_NAME(rightSlot,"rightSlot");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void VialInventoryView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(leftSlot,"leftSlot");
	HX_VISIT_MEMBER_NAME(rightSlot,"rightSlot");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val VialInventoryView_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"leftSlot") ) { return ::hx::Val( leftSlot ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightSlot") ) { return ::hx::Val( rightSlot ); }
	}
	return super::__Field(inName,inCallProp);
}

bool VialInventoryView_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"LEFT_BUTTON_CUTS") ) { outValue = ( LEFT_BUTTON_CUTS ); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"RIGHT_BUTTON_CUTS") ) { outValue = ( RIGHT_BUTTON_CUTS ); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"SINGLE_BUTTON_CUTS") ) { outValue = ( SINGLE_BUTTON_CUTS ); return true; }
	}
	return false;
}

::hx::Val VialInventoryView_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"leftSlot") ) { leftSlot=inValue.Cast<  ::ui::view::VialSlotView >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightSlot") ) { rightSlot=inValue.Cast<  ::ui::view::VialSlotView >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool VialInventoryView_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"LEFT_BUTTON_CUTS") ) { LEFT_BUTTON_CUTS=ioValue.Cast< ::Array< int > >(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"RIGHT_BUTTON_CUTS") ) { RIGHT_BUTTON_CUTS=ioValue.Cast< ::Array< int > >(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"SINGLE_BUTTON_CUTS") ) { SINGLE_BUTTON_CUTS=ioValue.Cast< ::Array< int > >(); return true; }
	}
	return false;
}

void VialInventoryView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("leftSlot",a5,21,51,53));
	outFields->push(HX_("rightSlot",fa,33,1c,b7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo VialInventoryView_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::view::VialSlotView */ ,(int)offsetof(VialInventoryView_obj,leftSlot),HX_("leftSlot",a5,21,51,53)},
	{::hx::fsObject /*  ::ui::view::VialSlotView */ ,(int)offsetof(VialInventoryView_obj,rightSlot),HX_("rightSlot",fa,33,1c,b7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo VialInventoryView_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /* ::Array< int > */ ,(void *) &VialInventoryView_obj::LEFT_BUTTON_CUTS,HX_("LEFT_BUTTON_CUTS",e6,41,1c,c1)},
	{::hx::fsObject /* ::Array< int > */ ,(void *) &VialInventoryView_obj::RIGHT_BUTTON_CUTS,HX_("RIGHT_BUTTON_CUTS",1b,f1,f6,0c)},
	{::hx::fsObject /* ::Array< int > */ ,(void *) &VialInventoryView_obj::SINGLE_BUTTON_CUTS,HX_("SINGLE_BUTTON_CUTS",e7,c1,29,41)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String VialInventoryView_obj_sMemberFields[] = {
	HX_("leftSlot",a5,21,51,53),
	HX_("rightSlot",fa,33,1c,b7),
	::String(null()) };

static void VialInventoryView_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VialInventoryView_obj::LEFT_BUTTON_CUTS,"LEFT_BUTTON_CUTS");
	HX_MARK_MEMBER_NAME(VialInventoryView_obj::RIGHT_BUTTON_CUTS,"RIGHT_BUTTON_CUTS");
	HX_MARK_MEMBER_NAME(VialInventoryView_obj::SINGLE_BUTTON_CUTS,"SINGLE_BUTTON_CUTS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void VialInventoryView_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VialInventoryView_obj::LEFT_BUTTON_CUTS,"LEFT_BUTTON_CUTS");
	HX_VISIT_MEMBER_NAME(VialInventoryView_obj::RIGHT_BUTTON_CUTS,"RIGHT_BUTTON_CUTS");
	HX_VISIT_MEMBER_NAME(VialInventoryView_obj::SINGLE_BUTTON_CUTS,"SINGLE_BUTTON_CUTS");
};

#endif

::hx::Class VialInventoryView_obj::__mClass;

static ::String VialInventoryView_obj_sStaticFields[] = {
	HX_("LEFT_BUTTON_CUTS",e6,41,1c,c1),
	HX_("RIGHT_BUTTON_CUTS",1b,f1,f6,0c),
	HX_("SINGLE_BUTTON_CUTS",e7,c1,29,41),
	::String(null())
};

void VialInventoryView_obj::__register()
{
	VialInventoryView_obj _hx_dummy;
	VialInventoryView_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.view.VialInventoryView",d4,53,6c,73);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &VialInventoryView_obj::__GetStatic;
	__mClass->mSetStaticField = &VialInventoryView_obj::__SetStatic;
	__mClass->mMarkFunc = VialInventoryView_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(VialInventoryView_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(VialInventoryView_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< VialInventoryView_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = VialInventoryView_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = VialInventoryView_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = VialInventoryView_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void VialInventoryView_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_d4f70f89e48fe194_6_boot)
HXDLIN(   6)		LEFT_BUTTON_CUTS = ::Array_obj< int >::fromData( _hx_array_data_736c53d4_2,4);
            	}
{
            	HX_STACKFRAME(&_hx_pos_d4f70f89e48fe194_7_boot)
HXDLIN(   7)		RIGHT_BUTTON_CUTS = ::Array_obj< int >::fromData( _hx_array_data_736c53d4_4,4);
            	}
{
            	HX_STACKFRAME(&_hx_pos_d4f70f89e48fe194_8_boot)
HXDLIN(   8)		SINGLE_BUTTON_CUTS = ::Array_obj< int >::fromData( _hx_array_data_736c53d4_6,4);
            	}
}

} // end namespace ui
} // end namespace view
