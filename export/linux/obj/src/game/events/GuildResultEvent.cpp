// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_game_events_GuildResultEvent
#include <game/events/GuildResultEvent.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_6f4649fdf05dbd0d_5_new,"game.events.GuildResultEvent","new",0xde051615,"game.events.GuildResultEvent.new","game/events/GuildResultEvent.hx",5,0x97b364db)
HX_LOCAL_STACK_FRAME(_hx_pos_6f4649fdf05dbd0d_18_toString,"game.events.GuildResultEvent","toString",0x179bbad7,"game.events.GuildResultEvent.toString","game/events/GuildResultEvent.hx",18,0x97b364db)
namespace game{
namespace events{

void GuildResultEvent_obj::__construct(bool success,::String errorText){
            	HX_STACKFRAME(&_hx_pos_6f4649fdf05dbd0d_5_new)
HXLINE(   9)		this->errorText = HX_("",00,00,00,00);
HXLINE(   8)		this->success = false;
HXLINE(  12)		super::__construct(HX_("GUILDRESULTEVENT",4a,c3,b4,c4),null(),null());
HXLINE(  13)		this->success = success;
HXLINE(  14)		this->errorText = errorText;
            	}

Dynamic GuildResultEvent_obj::__CreateEmpty() { return new GuildResultEvent_obj; }

void *GuildResultEvent_obj::_hx_vtable = 0;

Dynamic GuildResultEvent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GuildResultEvent_obj > _hx_result = new GuildResultEvent_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool GuildResultEvent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x08ec4c31) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x08ec4c31;
	} else {
		return inClassId==(int)0x18345335;
	}
}

::String GuildResultEvent_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_6f4649fdf05dbd0d_18_toString)
HXDLIN(  18)		return this->formatToString(HX_("GUILDRESULTEVENT",4a,c3,b4,c4),HX_("success",c3,25,4e,b8),HX_("errorText",95,48,62,73),null(),null(),null());
            	}



::hx::ObjectPtr< GuildResultEvent_obj > GuildResultEvent_obj::__new(bool success,::String errorText) {
	::hx::ObjectPtr< GuildResultEvent_obj > __this = new GuildResultEvent_obj();
	__this->__construct(success,errorText);
	return __this;
}

::hx::ObjectPtr< GuildResultEvent_obj > GuildResultEvent_obj::__alloc(::hx::Ctx *_hx_ctx,bool success,::String errorText) {
	GuildResultEvent_obj *__this = (GuildResultEvent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GuildResultEvent_obj), true, "game.events.GuildResultEvent"));
	*(void **)__this = GuildResultEvent_obj::_hx_vtable;
	__this->__construct(success,errorText);
	return __this;
}

GuildResultEvent_obj::GuildResultEvent_obj()
{
}

void GuildResultEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GuildResultEvent);
	HX_MARK_MEMBER_NAME(success,"success");
	HX_MARK_MEMBER_NAME(errorText,"errorText");
	 ::openfl::events::Event_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GuildResultEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(success,"success");
	HX_VISIT_MEMBER_NAME(errorText,"errorText");
	 ::openfl::events::Event_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val GuildResultEvent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"success") ) { return ::hx::Val( success ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"errorText") ) { return ::hx::Val( errorText ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val GuildResultEvent_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"success") ) { success=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"errorText") ) { errorText=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GuildResultEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("success",c3,25,4e,b8));
	outFields->push(HX_("errorText",95,48,62,73));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo GuildResultEvent_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(GuildResultEvent_obj,success),HX_("success",c3,25,4e,b8)},
	{::hx::fsString,(int)offsetof(GuildResultEvent_obj,errorText),HX_("errorText",95,48,62,73)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *GuildResultEvent_obj_sStaticStorageInfo = 0;
#endif

static ::String GuildResultEvent_obj_sMemberFields[] = {
	HX_("success",c3,25,4e,b8),
	HX_("errorText",95,48,62,73),
	HX_("toString",ac,d0,6e,38),
	::String(null()) };

::hx::Class GuildResultEvent_obj::__mClass;

void GuildResultEvent_obj::__register()
{
	GuildResultEvent_obj _hx_dummy;
	GuildResultEvent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("game.events.GuildResultEvent",a3,67,b9,4e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(GuildResultEvent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< GuildResultEvent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GuildResultEvent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GuildResultEvent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace game
} // end namespace events