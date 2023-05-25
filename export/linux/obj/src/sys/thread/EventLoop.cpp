// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_MainLoop
#include <haxe/MainLoop.h>
#endif
#ifndef INCLUDED_sys_thread_EventLoop
#include <sys/thread/EventLoop.h>
#endif
#ifndef INCLUDED_sys_thread_Lock
#include <sys/thread/Lock.h>
#endif
#ifndef INCLUDED_sys_thread_Mutex
#include <sys/thread/Mutex.h>
#endif
#ifndef INCLUDED_sys_thread_NextEventTime
#include <sys/thread/NextEventTime.h>
#endif
#ifndef INCLUDED_sys_thread__EventLoop_RegularEvent
#include <sys/thread/_EventLoop/RegularEvent.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_56373b3f7ae9a4f3_24_new,"sys.thread.EventLoop","new",0xafe12fcd,"sys.thread.EventLoop.new","/home/a/haxe/haxe/std/sys/thread/EventLoop.hx",24,0x6f36e668)
HX_LOCAL_STACK_FRAME(_hx_pos_56373b3f7ae9a4f3_146_progress,"sys.thread.EventLoop","progress",0xd3ab8d20,"sys.thread.EventLoop.progress","/home/a/haxe/haxe/std/sys/thread/EventLoop.hx",146,0x6f36e668)
HX_LOCAL_STACK_FRAME(_hx_pos_56373b3f7ae9a4f3_179_loop,"sys.thread.EventLoop","loop",0x33ddc657,"sys.thread.EventLoop.loop","/home/a/haxe/haxe/std/sys/thread/EventLoop.hx",179,0x6f36e668)
namespace sys{
namespace thread{

void EventLoop_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_56373b3f7ae9a4f3_24_new)
HXLINE(  29)		this->promisedEventsCount = 0;
HXLINE(  28)		this->waitLock =  ::sys::thread::Lock_obj::__alloc( HX_CTX );
HXLINE(  27)		this->oneTimeEventsIdx = 0;
HXLINE(  26)		this->oneTimeEvents = ::Array_obj< ::Dynamic>::__new();
HXLINE(  25)		this->mutex =  ::sys::thread::Mutex_obj::__alloc( HX_CTX );
HXLINE(  35)		this->isMainThread = !(::sys::thread::EventLoop_obj::CREATED);
HXLINE(  36)		::sys::thread::EventLoop_obj::CREATED = true;
            	}

Dynamic EventLoop_obj::__CreateEmpty() { return new EventLoop_obj; }

void *EventLoop_obj::_hx_vtable = 0;

Dynamic EventLoop_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< EventLoop_obj > _hx_result = new EventLoop_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool EventLoop_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6a581147;
}

 ::sys::thread::NextEventTime EventLoop_obj::progress(){
            	HX_STACKFRAME(&_hx_pos_56373b3f7ae9a4f3_146_progress)
HXDLIN( 146)		Float now = ::Sys_obj::time();
HXDLIN( 146)		::Array< ::Dynamic> regularsToRun = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 146)		int eventsToRunIdx = 0;
HXDLIN( 146)		Float nextEventAt = ( (Float)(-1) );
HXDLIN( 146)		this->mutex->acquire();
HXDLIN( 146)		while(this->waitLock->wait(((Float)0.0))){
            		}
HXDLIN( 146)		 ::sys::thread::_EventLoop::RegularEvent current = this->regularEvents;
HXDLIN( 146)		while(::hx::IsNotNull( current )){
HXDLIN( 146)			if ((current->nextRunTime <= now)) {
HXDLIN( 146)				eventsToRunIdx = (eventsToRunIdx + 1);
HXDLIN( 146)				regularsToRun[(eventsToRunIdx - 1)] = current;
HXDLIN( 146)				 ::sys::thread::_EventLoop::RegularEvent current1 = current;
HXDLIN( 146)				current1->nextRunTime = (current1->nextRunTime + current->interval);
HXLINE( 220)				nextEventAt = ( (Float)(-2) );
            			}
            			else {
HXDLIN( 146)				bool _hx_tmp;
HXDLIN( 146)				if ((nextEventAt != -1)) {
HXDLIN( 146)					_hx_tmp = (current->nextRunTime < nextEventAt);
            				}
            				else {
HXDLIN( 146)					_hx_tmp = true;
            				}
HXDLIN( 146)				if (_hx_tmp) {
HXLINE( 222)					nextEventAt = current->nextRunTime;
            				}
            			}
HXLINE( 224)			current = current->next;
            		}
HXLINE( 146)		this->mutex->release();
HXDLIN( 146)		int _g = 0;
HXDLIN( 146)		int _g1 = eventsToRunIdx;
HXDLIN( 146)		while((_g < _g1)){
HXDLIN( 146)			_g = (_g + 1);
HXDLIN( 146)			int i = (_g - 1);
HXDLIN( 146)			if (!(regularsToRun->__get(i).StaticCast<  ::sys::thread::_EventLoop::RegularEvent >()->cancelled)) {
HXDLIN( 146)				regularsToRun->__get(i).StaticCast<  ::sys::thread::_EventLoop::RegularEvent >()->run();
            			}
HXDLIN( 146)			regularsToRun[i] = null();
            		}
HXLINE( 234)		eventsToRunIdx = 0;
HXLINE( 146)		::Array< ::Dynamic> oneTimersToRun = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 146)		this->mutex->acquire();
HXDLIN( 146)		::Array< ::Dynamic> _this = this->oneTimeEvents;
HXDLIN( 146)		int _g_current = 0;
HXDLIN( 146)		while((_g_current < _this->length)){
HXDLIN( 146)			 ::Dynamic _g_value = _this->__get(_g_current);
HXDLIN( 146)			_g_current = (_g_current + 1);
HXDLIN( 146)			if (::hx::IsNull( _g_value )) {
HXDLIN( 146)				goto _hx_goto_4;
            			}
            			else {
HXDLIN( 146)				eventsToRunIdx = (eventsToRunIdx + 1);
HXDLIN( 146)				oneTimersToRun[(eventsToRunIdx - 1)] = _g_value;
HXDLIN( 146)				this->oneTimeEvents[(_g_current - 1)] = null();
            			}
            		}
            		_hx_goto_4:;
HXDLIN( 146)		this->oneTimeEventsIdx = 0;
HXDLIN( 146)		bool hasPromisedEvents = (this->promisedEventsCount > 0);
HXDLIN( 146)		this->mutex->release();
HXDLIN( 146)		int _g2 = 0;
HXDLIN( 146)		int _g3 = eventsToRunIdx;
HXDLIN( 146)		while((_g2 < _g3)){
HXDLIN( 146)			_g2 = (_g2 + 1);
HXDLIN( 146)			int i1 = (_g2 - 1);
HXDLIN( 146)			oneTimersToRun->__get(i1)();
HXDLIN( 146)			oneTimersToRun[i1] = null();
            		}
HXDLIN( 146)		if (this->isMainThread) {
HXDLIN( 146)			Float next = ::haxe::MainLoop_obj::tick();
HXDLIN( 146)			if (::haxe::MainLoop_obj::hasEvents()) {
HXDLIN( 146)				eventsToRunIdx = (eventsToRunIdx + 1);
HXDLIN( 146)				if ((nextEventAt > next)) {
HXLINE( 264)					nextEventAt = next;
            				}
            			}
            		}
HXLINE( 146)		if ((eventsToRunIdx > 0)) {
HXLINE( 270)			nextEventAt = ( (Float)(-2) );
            		}
HXLINE( 146)		Float _g_nextEventAt = nextEventAt;
HXDLIN( 146)		Float _hx_switch_0 = _g_nextEventAt;
            		if (  (_hx_switch_0==( (Float)(-2) )) ){
HXLINE( 147)			return ::sys::thread::NextEventTime_obj::Now_dyn();
HXDLIN( 147)			goto _hx_goto_6;
            		}
            		if (  (_hx_switch_0==( (Float)(-1) )) ){
HXDLIN( 146)			if (hasPromisedEvents) {
HXLINE( 149)				return ::sys::thread::NextEventTime_obj::AnyTime(null());
            			}
            			else {
HXLINE( 148)				return ::sys::thread::NextEventTime_obj::Never_dyn();
            			}
HXLINE( 146)			goto _hx_goto_6;
            		}
            		/* default */{
HXDLIN( 146)			if (hasPromisedEvents) {
HXLINE( 150)				return ::sys::thread::NextEventTime_obj::AnyTime(_g_nextEventAt);
            			}
            			else {
HXLINE( 151)				return ::sys::thread::NextEventTime_obj::At(_g_nextEventAt);
            			}
            		}
            		_hx_goto_6:;
HXLINE( 146)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(EventLoop_obj,progress,return )

void EventLoop_obj::loop(){
            	HX_STACKFRAME(&_hx_pos_56373b3f7ae9a4f3_179_loop)
HXLINE( 180)		::Array< ::Dynamic> recycleRegular = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 181)		::Array< ::Dynamic> recycleOneTimers = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 182)		while(true){
HXLINE( 183)			Float now = ::Sys_obj::time();
HXDLIN( 183)			int eventsToRunIdx = 0;
HXDLIN( 183)			Float nextEventAt = ( (Float)(-1) );
HXDLIN( 183)			this->mutex->acquire();
HXDLIN( 183)			while(this->waitLock->wait(((Float)0.0))){
            			}
HXLINE( 183)			 ::sys::thread::_EventLoop::RegularEvent current = this->regularEvents;
HXDLIN( 183)			while(::hx::IsNotNull( current )){
HXLINE( 183)				if ((current->nextRunTime <= now)) {
HXLINE( 183)					eventsToRunIdx = (eventsToRunIdx + 1);
HXDLIN( 183)					recycleRegular[(eventsToRunIdx - 1)] = current;
HXDLIN( 183)					 ::sys::thread::_EventLoop::RegularEvent current1 = current;
HXDLIN( 183)					current1->nextRunTime = (current1->nextRunTime + current->interval);
HXLINE( 220)					nextEventAt = ( (Float)(-2) );
            				}
            				else {
HXLINE( 183)					bool _hx_tmp;
HXDLIN( 183)					if ((nextEventAt != -1)) {
HXLINE( 183)						_hx_tmp = (current->nextRunTime < nextEventAt);
            					}
            					else {
HXLINE( 183)						_hx_tmp = true;
            					}
HXDLIN( 183)					if (_hx_tmp) {
HXLINE( 222)						nextEventAt = current->nextRunTime;
            					}
            				}
HXLINE( 224)				current = current->next;
            			}
HXLINE( 183)			this->mutex->release();
HXDLIN( 183)			int _g = 0;
HXDLIN( 183)			int _g1 = eventsToRunIdx;
HXDLIN( 183)			while((_g < _g1)){
HXLINE( 183)				_g = (_g + 1);
HXDLIN( 183)				int i = (_g - 1);
HXDLIN( 183)				if (!(recycleRegular->__get(i).StaticCast<  ::sys::thread::_EventLoop::RegularEvent >()->cancelled)) {
HXLINE( 183)					recycleRegular->__get(i).StaticCast<  ::sys::thread::_EventLoop::RegularEvent >()->run();
            				}
HXDLIN( 183)				recycleRegular[i] = null();
            			}
HXLINE( 234)			eventsToRunIdx = 0;
HXLINE( 183)			this->mutex->acquire();
HXDLIN( 183)			::Array< ::Dynamic> _this = this->oneTimeEvents;
HXDLIN( 183)			int _g_current = 0;
HXDLIN( 183)			while((_g_current < _this->length)){
HXLINE( 183)				 ::Dynamic _g_value = _this->__get(_g_current);
HXDLIN( 183)				_g_current = (_g_current + 1);
HXDLIN( 183)				if (::hx::IsNull( _g_value )) {
HXLINE( 183)					goto _hx_goto_12;
            				}
            				else {
HXLINE( 183)					eventsToRunIdx = (eventsToRunIdx + 1);
HXDLIN( 183)					recycleOneTimers[(eventsToRunIdx - 1)] = _g_value;
HXDLIN( 183)					this->oneTimeEvents[(_g_current - 1)] = null();
            				}
            			}
            			_hx_goto_12:;
HXDLIN( 183)			this->oneTimeEventsIdx = 0;
HXDLIN( 183)			bool hasPromisedEvents = (this->promisedEventsCount > 0);
HXDLIN( 183)			this->mutex->release();
HXDLIN( 183)			int _g2 = 0;
HXDLIN( 183)			int _g3 = eventsToRunIdx;
HXDLIN( 183)			while((_g2 < _g3)){
HXLINE( 183)				_g2 = (_g2 + 1);
HXDLIN( 183)				int i1 = (_g2 - 1);
HXDLIN( 183)				recycleOneTimers->__get(i1)();
HXDLIN( 183)				recycleOneTimers[i1] = null();
            			}
HXDLIN( 183)			if (this->isMainThread) {
HXLINE( 183)				Float next = ::haxe::MainLoop_obj::tick();
HXDLIN( 183)				if (::haxe::MainLoop_obj::hasEvents()) {
HXLINE( 183)					eventsToRunIdx = (eventsToRunIdx + 1);
HXDLIN( 183)					if ((nextEventAt > next)) {
HXLINE( 264)						nextEventAt = next;
            					}
            				}
            			}
HXLINE( 183)			if ((eventsToRunIdx > 0)) {
HXLINE( 270)				nextEventAt = ( (Float)(-2) );
            			}
HXLINE( 183)			Float r_nextEventAt = nextEventAt;
HXLINE( 184)			Float _hx_switch_0 = r_nextEventAt;
            			if (  (_hx_switch_0==( (Float)(-2) )) ){
HXLINE( 185)				goto _hx_goto_14;
            			}
            			if (  (_hx_switch_0==( (Float)(-1) )) ){
HXLINE( 184)				if (hasPromisedEvents) {
HXLINE( 189)					this->waitLock->wait(null());
            				}
            				else {
HXLINE( 187)					goto _hx_goto_8;
            				}
HXLINE( 184)				goto _hx_goto_14;
            			}
            			/* default */{
HXLINE( 191)				Float timeout = (r_nextEventAt - ::Sys_obj::time());
HXLINE( 192)				this->waitLock->wait(::Math_obj::max(( (Float)(0) ),timeout));
            			}
            			_hx_goto_14:;
            		}
            		_hx_goto_8:;
            	}


HX_DEFINE_DYNAMIC_FUNC0(EventLoop_obj,loop,(void))

bool EventLoop_obj::CREATED;


::hx::ObjectPtr< EventLoop_obj > EventLoop_obj::__new() {
	::hx::ObjectPtr< EventLoop_obj > __this = new EventLoop_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< EventLoop_obj > EventLoop_obj::__alloc(::hx::Ctx *_hx_ctx) {
	EventLoop_obj *__this = (EventLoop_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(EventLoop_obj), true, "sys.thread.EventLoop"));
	*(void **)__this = EventLoop_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

EventLoop_obj::EventLoop_obj()
{
}

void EventLoop_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventLoop);
	HX_MARK_MEMBER_NAME(mutex,"mutex");
	HX_MARK_MEMBER_NAME(oneTimeEvents,"oneTimeEvents");
	HX_MARK_MEMBER_NAME(oneTimeEventsIdx,"oneTimeEventsIdx");
	HX_MARK_MEMBER_NAME(waitLock,"waitLock");
	HX_MARK_MEMBER_NAME(promisedEventsCount,"promisedEventsCount");
	HX_MARK_MEMBER_NAME(regularEvents,"regularEvents");
	HX_MARK_MEMBER_NAME(isMainThread,"isMainThread");
	HX_MARK_END_CLASS();
}

void EventLoop_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mutex,"mutex");
	HX_VISIT_MEMBER_NAME(oneTimeEvents,"oneTimeEvents");
	HX_VISIT_MEMBER_NAME(oneTimeEventsIdx,"oneTimeEventsIdx");
	HX_VISIT_MEMBER_NAME(waitLock,"waitLock");
	HX_VISIT_MEMBER_NAME(promisedEventsCount,"promisedEventsCount");
	HX_VISIT_MEMBER_NAME(regularEvents,"regularEvents");
	HX_VISIT_MEMBER_NAME(isMainThread,"isMainThread");
}

::hx::Val EventLoop_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"loop") ) { return ::hx::Val( loop_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mutex") ) { return ::hx::Val( mutex ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"waitLock") ) { return ::hx::Val( waitLock ); }
		if (HX_FIELD_EQ(inName,"progress") ) { return ::hx::Val( progress_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isMainThread") ) { return ::hx::Val( isMainThread ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"oneTimeEvents") ) { return ::hx::Val( oneTimeEvents ); }
		if (HX_FIELD_EQ(inName,"regularEvents") ) { return ::hx::Val( regularEvents ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"oneTimeEventsIdx") ) { return ::hx::Val( oneTimeEventsIdx ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"promisedEventsCount") ) { return ::hx::Val( promisedEventsCount ); }
	}
	return super::__Field(inName,inCallProp);
}

bool EventLoop_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"CREATED") ) { outValue = ( CREATED ); return true; }
	}
	return false;
}

::hx::Val EventLoop_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mutex") ) { mutex=inValue.Cast<  ::sys::thread::Mutex >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"waitLock") ) { waitLock=inValue.Cast<  ::sys::thread::Lock >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isMainThread") ) { isMainThread=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"oneTimeEvents") ) { oneTimeEvents=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"regularEvents") ) { regularEvents=inValue.Cast<  ::sys::thread::_EventLoop::RegularEvent >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"oneTimeEventsIdx") ) { oneTimeEventsIdx=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"promisedEventsCount") ) { promisedEventsCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool EventLoop_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"CREATED") ) { CREATED=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

void EventLoop_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("mutex",7f,8f,5b,10));
	outFields->push(HX_("oneTimeEvents",0c,71,5c,81));
	outFields->push(HX_("oneTimeEventsIdx",91,7a,66,79));
	outFields->push(HX_("waitLock",00,01,9a,50));
	outFields->push(HX_("promisedEventsCount",0d,bf,c2,9b));
	outFields->push(HX_("regularEvents",95,42,47,b5));
	outFields->push(HX_("isMainThread",6d,c0,84,b6));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo EventLoop_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::sys::thread::Mutex */ ,(int)offsetof(EventLoop_obj,mutex),HX_("mutex",7f,8f,5b,10)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(EventLoop_obj,oneTimeEvents),HX_("oneTimeEvents",0c,71,5c,81)},
	{::hx::fsInt,(int)offsetof(EventLoop_obj,oneTimeEventsIdx),HX_("oneTimeEventsIdx",91,7a,66,79)},
	{::hx::fsObject /*  ::sys::thread::Lock */ ,(int)offsetof(EventLoop_obj,waitLock),HX_("waitLock",00,01,9a,50)},
	{::hx::fsInt,(int)offsetof(EventLoop_obj,promisedEventsCount),HX_("promisedEventsCount",0d,bf,c2,9b)},
	{::hx::fsObject /*  ::sys::thread::_EventLoop::RegularEvent */ ,(int)offsetof(EventLoop_obj,regularEvents),HX_("regularEvents",95,42,47,b5)},
	{::hx::fsBool,(int)offsetof(EventLoop_obj,isMainThread),HX_("isMainThread",6d,c0,84,b6)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo EventLoop_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &EventLoop_obj::CREATED,HX_("CREATED",c8,89,3e,91)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String EventLoop_obj_sMemberFields[] = {
	HX_("mutex",7f,8f,5b,10),
	HX_("oneTimeEvents",0c,71,5c,81),
	HX_("oneTimeEventsIdx",91,7a,66,79),
	HX_("waitLock",00,01,9a,50),
	HX_("promisedEventsCount",0d,bf,c2,9b),
	HX_("regularEvents",95,42,47,b5),
	HX_("isMainThread",6d,c0,84,b6),
	HX_("progress",ad,f7,2a,86),
	HX_("loop",64,a6,b7,47),
	::String(null()) };

static void EventLoop_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventLoop_obj::CREATED,"CREATED");
};

#ifdef HXCPP_VISIT_ALLOCS
static void EventLoop_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventLoop_obj::CREATED,"CREATED");
};

#endif

::hx::Class EventLoop_obj::__mClass;

static ::String EventLoop_obj_sStaticFields[] = {
	HX_("CREATED",c8,89,3e,91),
	::String(null())
};

void EventLoop_obj::__register()
{
	EventLoop_obj _hx_dummy;
	EventLoop_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("sys.thread.EventLoop",5b,45,a8,91);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &EventLoop_obj::__GetStatic;
	__mClass->mSetStaticField = &EventLoop_obj::__SetStatic;
	__mClass->mMarkFunc = EventLoop_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(EventLoop_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(EventLoop_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< EventLoop_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = EventLoop_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = EventLoop_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = EventLoop_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace sys
} // end namespace thread
