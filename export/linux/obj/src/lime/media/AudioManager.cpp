// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_media_AudioContext
#include <lime/media/AudioContext.h>
#endif
#ifndef INCLUDED_lime_media_AudioManager
#include <lime/media/AudioManager.h>
#endif
#ifndef INCLUDED_lime_media_OpenALAudioContext
#include <lime/media/OpenALAudioContext.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_b537b97081e2aab9_24_init,"lime.media.AudioManager","init",0x83630824,"lime.media.AudioManager.init","lime/media/AudioManager.hx",24,0x63af6ea2)
HX_LOCAL_STACK_FRAME(_hx_pos_b537b97081e2aab9_59_resume,"lime.media.AudioManager","resume",0xd988a3c1,"lime.media.AudioManager.resume","lime/media/AudioManager.hx",59,0x63af6ea2)
HX_LOCAL_STACK_FRAME(_hx_pos_b537b97081e2aab9_75_shutdown,"lime.media.AudioManager","shutdown",0xb121e3aa,"lime.media.AudioManager.shutdown","lime/media/AudioManager.hx",75,0x63af6ea2)
HX_LOCAL_STACK_FRAME(_hx_pos_b537b97081e2aab9_102_suspend,"lime.media.AudioManager","suspend",0x09fdc6e8,"lime.media.AudioManager.suspend","lime/media/AudioManager.hx",102,0x63af6ea2)
namespace lime{
namespace media{

void AudioManager_obj::__construct() { }

Dynamic AudioManager_obj::__CreateEmpty() { return new AudioManager_obj; }

void *AudioManager_obj::_hx_vtable = 0;

Dynamic AudioManager_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< AudioManager_obj > _hx_result = new AudioManager_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool AudioManager_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4a977a62;
}

 ::lime::media::AudioContext AudioManager_obj::context;

void AudioManager_obj::init( ::lime::media::AudioContext context){
            	HX_GC_STACKFRAME(&_hx_pos_b537b97081e2aab9_24_init)
HXDLIN(  24)		if (::hx::IsNull( ::lime::media::AudioManager_obj::context )) {
HXLINE(  26)			if (::hx::IsNull( context )) {
HXLINE(  28)				::lime::media::AudioManager_obj::context =  ::lime::media::AudioContext_obj::__alloc( HX_CTX ,null());
HXLINE(  29)				context = ::lime::media::AudioManager_obj::context;
HXLINE(  32)				if ((context->type == HX_("openal",35,5f,94,21))) {
HXLINE(  34)					 ::lime::media::OpenALAudioContext alc = context->openal;
HXLINE(  37)					 ::Dynamic ctx = alc->createContext(alc->openDevice(null()),null());
HXLINE(  38)					alc->makeContextCurrent(ctx);
HXLINE(  39)					alc->processContext(ctx);
            				}
            			}
HXLINE(  44)			::lime::media::AudioManager_obj::context = context;
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AudioManager_obj,init,(void))

void AudioManager_obj::resume(){
            	HX_STACKFRAME(&_hx_pos_b537b97081e2aab9_59_resume)
HXDLIN(  59)		bool _hx_tmp;
HXDLIN(  59)		if (::hx::IsNotNull( ::lime::media::AudioManager_obj::context )) {
HXDLIN(  59)			_hx_tmp = (::lime::media::AudioManager_obj::context->type == HX_("openal",35,5f,94,21));
            		}
            		else {
HXDLIN(  59)			_hx_tmp = false;
            		}
HXDLIN(  59)		if (_hx_tmp) {
HXLINE(  61)			 ::lime::media::OpenALAudioContext alc = ::lime::media::AudioManager_obj::context->openal;
HXLINE(  62)			 ::Dynamic currentContext = alc->getCurrentContext();
HXLINE(  64)			if (::hx::IsNotNull( currentContext )) {
HXLINE(  67)				alc->resumeDevice(alc->getContextsDevice(currentContext));
HXLINE(  68)				alc->processContext(currentContext);
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AudioManager_obj,resume,(void))

void AudioManager_obj::shutdown(){
            	HX_STACKFRAME(&_hx_pos_b537b97081e2aab9_75_shutdown)
HXLINE(  77)		bool _hx_tmp;
HXDLIN(  77)		if (::hx::IsNotNull( ::lime::media::AudioManager_obj::context )) {
HXLINE(  77)			_hx_tmp = (::lime::media::AudioManager_obj::context->type == HX_("openal",35,5f,94,21));
            		}
            		else {
HXLINE(  77)			_hx_tmp = false;
            		}
HXDLIN(  77)		if (_hx_tmp) {
HXLINE(  79)			 ::lime::media::OpenALAudioContext alc = ::lime::media::AudioManager_obj::context->openal;
HXLINE(  80)			 ::Dynamic currentContext = alc->getCurrentContext();
HXLINE(  82)			if (::hx::IsNotNull( currentContext )) {
HXLINE(  84)				 ::Dynamic device = alc->getContextsDevice(currentContext);
HXLINE(  85)				alc->makeContextCurrent(null());
HXLINE(  86)				alc->destroyContext(currentContext);
HXLINE(  88)				if (::hx::IsNotNull( device )) {
HXLINE(  90)					alc->closeDevice(device);
            				}
            			}
            		}
HXLINE(  96)		::lime::media::AudioManager_obj::context = null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AudioManager_obj,shutdown,(void))

void AudioManager_obj::suspend(){
            	HX_STACKFRAME(&_hx_pos_b537b97081e2aab9_102_suspend)
HXDLIN( 102)		bool _hx_tmp;
HXDLIN( 102)		if (::hx::IsNotNull( ::lime::media::AudioManager_obj::context )) {
HXDLIN( 102)			_hx_tmp = (::lime::media::AudioManager_obj::context->type == HX_("openal",35,5f,94,21));
            		}
            		else {
HXDLIN( 102)			_hx_tmp = false;
            		}
HXDLIN( 102)		if (_hx_tmp) {
HXLINE( 104)			 ::lime::media::OpenALAudioContext alc = ::lime::media::AudioManager_obj::context->openal;
HXLINE( 105)			 ::Dynamic currentContext = alc->getCurrentContext();
HXLINE( 107)			if (::hx::IsNotNull( currentContext )) {
HXLINE( 109)				alc->suspendContext(currentContext);
HXLINE( 110)				 ::Dynamic device = alc->getContextsDevice(currentContext);
HXLINE( 112)				if (::hx::IsNotNull( device )) {
HXLINE( 114)					alc->pauseDevice(device);
            				}
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AudioManager_obj,suspend,(void))


AudioManager_obj::AudioManager_obj()
{
}

bool AudioManager_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { outValue = init_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resume") ) { outValue = resume_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"context") ) { outValue = ( context ); return true; }
		if (HX_FIELD_EQ(inName,"suspend") ) { outValue = suspend_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shutdown") ) { outValue = shutdown_dyn(); return true; }
	}
	return false;
}

bool AudioManager_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"context") ) { context=ioValue.Cast<  ::lime::media::AudioContext >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *AudioManager_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo AudioManager_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::lime::media::AudioContext */ ,(void *) &AudioManager_obj::context,HX_("context",ef,95,77,19)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void AudioManager_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AudioManager_obj::context,"context");
};

#ifdef HXCPP_VISIT_ALLOCS
static void AudioManager_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AudioManager_obj::context,"context");
};

#endif

::hx::Class AudioManager_obj::__mClass;

static ::String AudioManager_obj_sStaticFields[] = {
	HX_("context",ef,95,77,19),
	HX_("init",10,3b,bb,45),
	HX_("resume",ad,69,84,08),
	HX_("shutdown",96,fc,0b,6b),
	HX_("suspend",7c,2f,4f,f7),
	::String(null())
};

void AudioManager_obj::__register()
{
	AudioManager_obj _hx_dummy;
	AudioManager_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.media.AudioManager",da,ab,e7,29);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &AudioManager_obj::__GetStatic;
	__mClass->mSetStaticField = &AudioManager_obj::__SetStatic;
	__mClass->mMarkFunc = AudioManager_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(AudioManager_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< AudioManager_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = AudioManager_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = AudioManager_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = AudioManager_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace media
