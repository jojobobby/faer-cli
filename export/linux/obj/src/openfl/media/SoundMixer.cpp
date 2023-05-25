// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_media_SoundChannel
#include <openfl/media/SoundChannel.h>
#endif
#ifndef INCLUDED_openfl_media_SoundMixer
#include <openfl/media/SoundMixer.h>
#endif
#ifndef INCLUDED_openfl_media_SoundTransform
#include <openfl/media/SoundTransform.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_1587d256662a54fa_181___registerSoundChannel,"openfl.media.SoundMixer","__registerSoundChannel",0x60ebf103,"openfl.media.SoundMixer.__registerSoundChannel","openfl/media/SoundMixer.hx",181,0x17e3a43a)
HX_LOCAL_STACK_FRAME(_hx_pos_1587d256662a54fa_186___unregisterSoundChannel,"openfl.media.SoundMixer","__unregisterSoundChannel",0xb1bc24dc,"openfl.media.SoundMixer.__unregisterSoundChannel","openfl/media/SoundMixer.hx",186,0x17e3a43a)
HX_LOCAL_STACK_FRAME(_hx_pos_1587d256662a54fa_51_boot,"openfl.media.SoundMixer","boot",0x83c4785e,"openfl.media.SoundMixer.boot","openfl/media/SoundMixer.hx",51,0x17e3a43a)
HX_LOCAL_STACK_FRAME(_hx_pos_1587d256662a54fa_52_boot,"openfl.media.SoundMixer","boot",0x83c4785e,"openfl.media.SoundMixer.boot","openfl/media/SoundMixer.hx",52,0x17e3a43a)
namespace openfl{
namespace media{

void SoundMixer_obj::__construct() { }

Dynamic SoundMixer_obj::__CreateEmpty() { return new SoundMixer_obj; }

void *SoundMixer_obj::_hx_vtable = 0;

Dynamic SoundMixer_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SoundMixer_obj > _hx_result = new SoundMixer_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool SoundMixer_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x24ff9a8a;
}

::Array< ::Dynamic> SoundMixer_obj::_hx___soundChannels;

 ::openfl::media::SoundTransform SoundMixer_obj::_hx___soundTransform;

void SoundMixer_obj::_hx___registerSoundChannel( ::openfl::media::SoundChannel soundChannel){
            	HX_STACKFRAME(&_hx_pos_1587d256662a54fa_181___registerSoundChannel)
HXDLIN( 181)		::openfl::media::SoundMixer_obj::_hx___soundChannels->push(soundChannel);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundMixer_obj,_hx___registerSoundChannel,(void))

void SoundMixer_obj::_hx___unregisterSoundChannel( ::openfl::media::SoundChannel soundChannel){
            	HX_STACKFRAME(&_hx_pos_1587d256662a54fa_186___unregisterSoundChannel)
HXDLIN( 186)		::openfl::media::SoundMixer_obj::_hx___soundChannels->remove(soundChannel);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundMixer_obj,_hx___unregisterSoundChannel,(void))


SoundMixer_obj::SoundMixer_obj()
{
}

bool SoundMixer_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"__soundChannels") ) { outValue = ( _hx___soundChannels ); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__soundTransform") ) { outValue = ( _hx___soundTransform ); return true; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"__registerSoundChannel") ) { outValue = _hx___registerSoundChannel_dyn(); return true; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"__unregisterSoundChannel") ) { outValue = _hx___unregisterSoundChannel_dyn(); return true; }
	}
	return false;
}

bool SoundMixer_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"__soundChannels") ) { _hx___soundChannels=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__soundTransform") ) { _hx___soundTransform=ioValue.Cast<  ::openfl::media::SoundTransform >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *SoundMixer_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo SoundMixer_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &SoundMixer_obj::_hx___soundChannels,HX_("__soundChannels",1f,13,bf,8f)},
	{::hx::fsObject /*  ::openfl::media::SoundTransform */ ,(void *) &SoundMixer_obj::_hx___soundTransform,HX_("__soundTransform",bd,79,1e,57)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void SoundMixer_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundMixer_obj::_hx___soundChannels,"__soundChannels");
	HX_MARK_MEMBER_NAME(SoundMixer_obj::_hx___soundTransform,"__soundTransform");
};

#ifdef HXCPP_VISIT_ALLOCS
static void SoundMixer_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SoundMixer_obj::_hx___soundChannels,"__soundChannels");
	HX_VISIT_MEMBER_NAME(SoundMixer_obj::_hx___soundTransform,"__soundTransform");
};

#endif

::hx::Class SoundMixer_obj::__mClass;

static ::String SoundMixer_obj_sStaticFields[] = {
	HX_("__soundChannels",1f,13,bf,8f),
	HX_("__soundTransform",bd,79,1e,57),
	HX_("__registerSoundChannel",d7,81,b6,fe),
	HX_("__unregisterSoundChannel",b0,92,eb,43),
	::String(null())
};

void SoundMixer_obj::__register()
{
	SoundMixer_obj _hx_dummy;
	SoundMixer_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.media.SoundMixer",c2,db,a7,15);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SoundMixer_obj::__GetStatic;
	__mClass->mSetStaticField = &SoundMixer_obj::__SetStatic;
	__mClass->mMarkFunc = SoundMixer_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(SoundMixer_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< SoundMixer_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = SoundMixer_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SoundMixer_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SoundMixer_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void SoundMixer_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_1587d256662a54fa_51_boot)
HXDLIN(  51)		_hx___soundChannels = ::Array_obj< ::Dynamic>::__new();
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_1587d256662a54fa_52_boot)
HXDLIN(  52)		_hx___soundTransform =  ::openfl::media::SoundTransform_obj::__alloc( HX_CTX ,null(),null());
            	}
}

} // end namespace openfl
} // end namespace media
