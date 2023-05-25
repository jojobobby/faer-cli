// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_openfl_errors_Error
#include <openfl/errors/Error.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_7c7ee06d9b3544d2_56_new,"openfl.errors.Error","new",0xefad98b5,"openfl.errors.Error.new","openfl/errors/Error.hx",56,0x5096467b)
HX_LOCAL_STACK_FRAME(_hx_pos_7c7ee06d9b3544d2_116_toString,"openfl.errors.Error","toString",0x62f5b437,"openfl.errors.Error.toString","openfl/errors/Error.hx",116,0x5096467b)
namespace openfl{
namespace errors{

void Error_obj::__construct(::String __o_message,::hx::Null< int >  __o_id){
            		::String message = __o_message;
            		if (::hx::IsNull(__o_message)) message = HX_("",00,00,00,00);
            		int id = __o_id.Default(0);
            	HX_STACKFRAME(&_hx_pos_7c7ee06d9b3544d2_56_new)
HXDLIN(  56)		{
HXLINE(  58)			super::__construct(message,null(),null());
HXLINE(  63)			this->errorID = id;
HXLINE(  64)			this->name = HX_("Error",a8,3b,57,06);
            		}
HXLINE(  56)		{
HXDLIN(  56)			this->_hx___skipStack++;
            		}
            	}

Dynamic Error_obj::__CreateEmpty() { return new Error_obj; }

void *Error_obj::_hx_vtable = 0;

Dynamic Error_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Error_obj > _hx_result = new Error_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Error_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x3495c9c5) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x3495c9c5;
	} else {
		return inClassId==(int)0x677ddc49;
	}
}

::String Error_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_7c7ee06d9b3544d2_116_toString)
HXDLIN( 116)		if (::hx::IsNotNull( this->get_message() )) {
HXLINE( 118)			return this->get_message();
            		}
            		else {
HXLINE( 122)			return HX_("Error",a8,3b,57,06);
            		}
HXLINE( 116)		return null();
            	}



::hx::ObjectPtr< Error_obj > Error_obj::__new(::String __o_message,::hx::Null< int >  __o_id) {
	::hx::ObjectPtr< Error_obj > __this = new Error_obj();
	__this->__construct(__o_message,__o_id);
	return __this;
}

::hx::ObjectPtr< Error_obj > Error_obj::__alloc(::hx::Ctx *_hx_ctx,::String __o_message,::hx::Null< int >  __o_id) {
	Error_obj *__this = (Error_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Error_obj), true, "openfl.errors.Error"));
	*(void **)__this = Error_obj::_hx_vtable;
	__this->__construct(__o_message,__o_id);
	return __this;
}

Error_obj::Error_obj()
{
}

void Error_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Error);
	HX_MARK_MEMBER_NAME(errorID,"errorID");
	HX_MARK_MEMBER_NAME(name,"name");
	 ::haxe::Exception_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Error_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(errorID,"errorID");
	HX_VISIT_MEMBER_NAME(name,"name");
	 ::haxe::Exception_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Error_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return ::hx::Val( name ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"errorID") ) { return ::hx::Val( errorID ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Error_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"errorID") ) { errorID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Error_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("errorID",a3,8d,0a,ea));
	outFields->push(HX_("name",4b,72,ff,48));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Error_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(Error_obj,errorID),HX_("errorID",a3,8d,0a,ea)},
	{::hx::fsString,(int)offsetof(Error_obj,name),HX_("name",4b,72,ff,48)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Error_obj_sStaticStorageInfo = 0;
#endif

static ::String Error_obj_sMemberFields[] = {
	HX_("errorID",a3,8d,0a,ea),
	HX_("name",4b,72,ff,48),
	HX_("toString",ac,d0,6e,38),
	::String(null()) };

::hx::Class Error_obj::__mClass;

void Error_obj::__register()
{
	Error_obj _hx_dummy;
	Error_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.errors.Error",43,1a,04,80);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Error_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Error_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Error_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Error_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace errors
