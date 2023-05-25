// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_openfl_display_DisplayObjectRenderer
#include <openfl/display/DisplayObjectRenderer.h>
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
#ifndef INCLUDED_openfl_events_RenderEvent
#include <openfl/events/RenderEvent.h>
#endif
#ifndef INCLUDED_openfl_geom_ColorTransform
#include <openfl/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_6a559adcb74b53ca_154_new,"openfl.events.RenderEvent","new",0x8fc9357f,"openfl.events.RenderEvent.new","openfl/events/RenderEvent.hx",154,0xf57c28f1)
HX_LOCAL_STACK_FRAME(_hx_pos_6a559adcb74b53ca_176_toString,"openfl.events.RenderEvent","toString",0xf15b7b2d,"openfl.events.RenderEvent.toString","openfl/events/RenderEvent.hx",176,0xf57c28f1)
static const ::String _hx_array_data_d18b0a0d_2[] = {
	HX_("type",ba,f2,08,4d),HX_("bubbles",67,bb,56,61),HX_("cancelable",14,a0,79,c4),
};
namespace openfl{
namespace events{

void RenderEvent_obj::__construct(::String type,::hx::Null< bool >  __o_bubbles,::hx::Null< bool >  __o_cancelable, ::openfl::geom::Matrix objectMatrix, ::openfl::geom::ColorTransform objectColorTransform,::hx::Null< bool >  __o_allowSmoothing){
            		bool bubbles = __o_bubbles.Default(false);
            		bool cancelable = __o_cancelable.Default(false);
            		bool allowSmoothing = __o_allowSmoothing.Default(true);
            	HX_STACKFRAME(&_hx_pos_6a559adcb74b53ca_154_new)
HXLINE( 155)		super::__construct(type,bubbles,cancelable);
HXLINE( 157)		this->objectMatrix = objectMatrix;
HXLINE( 158)		this->objectColorTransform = objectColorTransform;
HXLINE( 159)		this->allowSmoothing = allowSmoothing;
            	}

Dynamic RenderEvent_obj::__CreateEmpty() { return new RenderEvent_obj; }

void *RenderEvent_obj::_hx_vtable = 0;

Dynamic RenderEvent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< RenderEvent_obj > _hx_result = new RenderEvent_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return _hx_result;
}

bool RenderEvent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x08ec4c31) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x08ec4c31;
	} else {
		return inClassId==(int)0x19d7ad57;
	}
}

::String RenderEvent_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_6a559adcb74b53ca_176_toString)
HXDLIN( 176)		return this->_hx___formatToString(HX_("RenderEvent",c4,8c,a8,25),::Array_obj< ::String >::fromData( _hx_array_data_d18b0a0d_2,3));
            	}



::hx::ObjectPtr< RenderEvent_obj > RenderEvent_obj::__new(::String type,::hx::Null< bool >  __o_bubbles,::hx::Null< bool >  __o_cancelable, ::openfl::geom::Matrix objectMatrix, ::openfl::geom::ColorTransform objectColorTransform,::hx::Null< bool >  __o_allowSmoothing) {
	::hx::ObjectPtr< RenderEvent_obj > __this = new RenderEvent_obj();
	__this->__construct(type,__o_bubbles,__o_cancelable,objectMatrix,objectColorTransform,__o_allowSmoothing);
	return __this;
}

::hx::ObjectPtr< RenderEvent_obj > RenderEvent_obj::__alloc(::hx::Ctx *_hx_ctx,::String type,::hx::Null< bool >  __o_bubbles,::hx::Null< bool >  __o_cancelable, ::openfl::geom::Matrix objectMatrix, ::openfl::geom::ColorTransform objectColorTransform,::hx::Null< bool >  __o_allowSmoothing) {
	RenderEvent_obj *__this = (RenderEvent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(RenderEvent_obj), true, "openfl.events.RenderEvent"));
	*(void **)__this = RenderEvent_obj::_hx_vtable;
	__this->__construct(type,__o_bubbles,__o_cancelable,objectMatrix,objectColorTransform,__o_allowSmoothing);
	return __this;
}

RenderEvent_obj::RenderEvent_obj()
{
}

void RenderEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RenderEvent);
	HX_MARK_MEMBER_NAME(allowSmoothing,"allowSmoothing");
	HX_MARK_MEMBER_NAME(objectColorTransform,"objectColorTransform");
	HX_MARK_MEMBER_NAME(objectMatrix,"objectMatrix");
	HX_MARK_MEMBER_NAME(renderer,"renderer");
	 ::openfl::events::Event_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RenderEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(allowSmoothing,"allowSmoothing");
	HX_VISIT_MEMBER_NAME(objectColorTransform,"objectColorTransform");
	HX_VISIT_MEMBER_NAME(objectMatrix,"objectMatrix");
	HX_VISIT_MEMBER_NAME(renderer,"renderer");
	 ::openfl::events::Event_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val RenderEvent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"renderer") ) { return ::hx::Val( renderer ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"objectMatrix") ) { return ::hx::Val( objectMatrix ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"allowSmoothing") ) { return ::hx::Val( allowSmoothing ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"objectColorTransform") ) { return ::hx::Val( objectColorTransform ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val RenderEvent_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"renderer") ) { renderer=inValue.Cast<  ::openfl::display::DisplayObjectRenderer >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"objectMatrix") ) { objectMatrix=inValue.Cast<  ::openfl::geom::Matrix >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"allowSmoothing") ) { allowSmoothing=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"objectColorTransform") ) { objectColorTransform=inValue.Cast<  ::openfl::geom::ColorTransform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RenderEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("allowSmoothing",ab,b7,66,68));
	outFields->push(HX_("objectColorTransform",a8,9a,71,7d));
	outFields->push(HX_("objectMatrix",60,42,d2,95));
	outFields->push(HX_("renderer",43,c5,db,b2));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo RenderEvent_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(RenderEvent_obj,allowSmoothing),HX_("allowSmoothing",ab,b7,66,68)},
	{::hx::fsObject /*  ::openfl::geom::ColorTransform */ ,(int)offsetof(RenderEvent_obj,objectColorTransform),HX_("objectColorTransform",a8,9a,71,7d)},
	{::hx::fsObject /*  ::openfl::geom::Matrix */ ,(int)offsetof(RenderEvent_obj,objectMatrix),HX_("objectMatrix",60,42,d2,95)},
	{::hx::fsObject /*  ::openfl::display::DisplayObjectRenderer */ ,(int)offsetof(RenderEvent_obj,renderer),HX_("renderer",43,c5,db,b2)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *RenderEvent_obj_sStaticStorageInfo = 0;
#endif

static ::String RenderEvent_obj_sMemberFields[] = {
	HX_("allowSmoothing",ab,b7,66,68),
	HX_("objectColorTransform",a8,9a,71,7d),
	HX_("objectMatrix",60,42,d2,95),
	HX_("renderer",43,c5,db,b2),
	HX_("toString",ac,d0,6e,38),
	::String(null()) };

::hx::Class RenderEvent_obj::__mClass;

void RenderEvent_obj::__register()
{
	RenderEvent_obj _hx_dummy;
	RenderEvent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.events.RenderEvent",0d,0a,8b,d1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(RenderEvent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< RenderEvent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = RenderEvent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = RenderEvent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace events
