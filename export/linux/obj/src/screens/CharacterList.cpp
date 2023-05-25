// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
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
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_screens_CharacterList
#include <screens/CharacterList.h>
#endif
#ifndef INCLUDED_screens_charrects_CharacterRectList
#include <screens/charrects/CharacterRectList.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_bb9407af180fdfcc_13_new,"screens.CharacterList","new",0x2e100a52,"screens.CharacterList.new","screens/CharacterList.hx",13,0xbb68f75f)
HX_LOCAL_STACK_FRAME(_hx_pos_bb9407af180fdfcc_32_setPos,"screens.CharacterList","setPos",0xcc4ff460,"screens.CharacterList.setPos","screens/CharacterList.hx",32,0xbb68f75f)
namespace screens{

void CharacterList_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_bb9407af180fdfcc_13_new)
HXLINE(  14)		super::__construct();
HXLINE(  16)		 ::openfl::display::Shape shape = null();
HXLINE(  17)		 ::openfl::display::Graphics g = null();
HXLINE(  18)		this->charRectList =  ::screens::charrects::CharacterRectList_obj::__alloc( HX_CTX );
HXLINE(  19)		this->addChild(this->charRectList);
HXLINE(  20)		Float _hx_tmp = this->get_height();
HXDLIN(  20)		if ((_hx_tmp > (::Main_obj::stageHeight - 120))) {
HXLINE(  21)			shape =  ::openfl::display::Shape_obj::__alloc( HX_CTX );
HXLINE(  22)			g = shape->get_graphics();
HXLINE(  23)			g->beginFill(0,null());
HXLINE(  24)			g->drawRect(( (Float)(0) ),( (Float)(0) ),( (Float)(760) ),( (Float)((::Main_obj::stageHeight - 120)) ));
HXLINE(  25)			g->endFill();
HXLINE(  26)			this->addChild(shape);
HXLINE(  27)			this->set_mask(shape);
            		}
            	}

Dynamic CharacterList_obj::__CreateEmpty() { return new CharacterList_obj; }

void *CharacterList_obj::_hx_vtable = 0;

Dynamic CharacterList_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CharacterList_obj > _hx_result = new CharacterList_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CharacterList_obj::_hx_isInstanceOf(int inClassId) {
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
			return inClassId==(int)0x7938ad44;
		}
	}
}

void CharacterList_obj::setPos(Float pos){
            	HX_STACKFRAME(&_hx_pos_bb9407af180fdfcc_32_setPos)
HXDLIN(  32)		this->charRectList->set_y(pos);
            	}


HX_DEFINE_DYNAMIC_FUNC1(CharacterList_obj,setPos,(void))


::hx::ObjectPtr< CharacterList_obj > CharacterList_obj::__new() {
	::hx::ObjectPtr< CharacterList_obj > __this = new CharacterList_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CharacterList_obj > CharacterList_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CharacterList_obj *__this = (CharacterList_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CharacterList_obj), true, "screens.CharacterList"));
	*(void **)__this = CharacterList_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CharacterList_obj::CharacterList_obj()
{
}

void CharacterList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharacterList);
	HX_MARK_MEMBER_NAME(charRectList,"charRectList");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CharacterList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(charRectList,"charRectList");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val CharacterList_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"setPos") ) { return ::hx::Val( setPos_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"charRectList") ) { return ::hx::Val( charRectList ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CharacterList_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"charRectList") ) { charRectList=inValue.Cast<  ::screens::charrects::CharacterRectList >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CharacterList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("charRectList",98,d8,97,df));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CharacterList_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::screens::charrects::CharacterRectList */ ,(int)offsetof(CharacterList_obj,charRectList),HX_("charRectList",98,d8,97,df)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CharacterList_obj_sStaticStorageInfo = 0;
#endif

static ::String CharacterList_obj_sMemberFields[] = {
	HX_("charRectList",98,d8,97,df),
	HX_("setPos",12,eb,6c,6f),
	::String(null()) };

::hx::Class CharacterList_obj::__mClass;

void CharacterList_obj::__register()
{
	CharacterList_obj _hx_dummy;
	CharacterList_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("screens.CharacterList",60,39,cc,1b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CharacterList_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CharacterList_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CharacterList_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CharacterList_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace screens
