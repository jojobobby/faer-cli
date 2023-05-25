// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_openfl__Vector_FunctionVector
#include <openfl/_Vector/FunctionVector.h>
#endif
#ifndef INCLUDED_openfl__Vector_IVector
#include <openfl/_Vector/IVector.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f37013fa3e7b7067_1236_new,"openfl._Vector.FunctionVector","new",0x9bdddf17,"openfl._Vector.FunctionVector.new","openfl/Vector.hx",1236,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_f37013fa3e7b7067_1418_toJSON,"openfl._Vector.FunctionVector","toJSON",0xecb206cc,"openfl._Vector.FunctionVector.toJSON","openfl/Vector.hx",1418,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_f37013fa3e7b7067_1441_set_length,"openfl._Vector.FunctionVector","set_length",0x820fe94c,"openfl._Vector.FunctionVector.set_length","openfl/Vector.hx",1441,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_f37013fa3e7b7067_1227_boot,"openfl._Vector.FunctionVector","boot",0xbe5e559b,"openfl._Vector.FunctionVector.boot","openfl/Vector.hx",1227,0x4a01873c)
namespace openfl{
namespace _Vector{

void FunctionVector_obj::__construct(::hx::Null< int >  __o_length,::hx::Null< bool >  __o_fixed,::cpp::VirtualArray array){
            		int length = __o_length.Default(0);
            		bool fixed = __o_fixed.Default(false);
            	HX_STACKFRAME(&_hx_pos_f37013fa3e7b7067_1236_new)
HXLINE(1237)		if (::hx::IsNull( array )) {
HXLINE(1237)			array = ::cpp::VirtualArray_obj::__new();
            		}
HXLINE(1238)		this->_hx___array = array;
HXLINE(1240)		if ((length > 0)) {
HXLINE(1242)			this->set_length(length);
            		}
HXLINE(1245)		this->fixed = fixed;
            	}

Dynamic FunctionVector_obj::__CreateEmpty() { return new FunctionVector_obj; }

void *FunctionVector_obj::_hx_vtable = 0;

Dynamic FunctionVector_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FunctionVector_obj > _hx_result = new FunctionVector_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool FunctionVector_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x088f384d;
}

static ::openfl::_Vector::IVector_obj _hx_openfl__Vector_FunctionVector__hx_openfl__Vector_IVector= {
};

void *FunctionVector_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0x45e7caba: return &_hx_openfl__Vector_FunctionVector__hx_openfl__Vector_IVector;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

 ::Dynamic FunctionVector_obj::toJSON(){
            	HX_STACKFRAME(&_hx_pos_f37013fa3e7b7067_1418_toJSON)
HXDLIN(1418)		return this->_hx___array;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FunctionVector_obj,toJSON,return )

int FunctionVector_obj::set_length(int value){
            	HX_STACKFRAME(&_hx_pos_f37013fa3e7b7067_1441_set_length)
HXLINE(1442)		if (!(this->fixed)) {
HXLINE(1445)			_hx_array_set_size_exact(this->_hx___array,value);
            		}
HXLINE(1467)		return this->_hx___array->get_length();
            	}


HX_DEFINE_DYNAMIC_FUNC1(FunctionVector_obj,set_length,return )


::hx::ObjectPtr< FunctionVector_obj > FunctionVector_obj::__new(::hx::Null< int >  __o_length,::hx::Null< bool >  __o_fixed,::cpp::VirtualArray array) {
	::hx::ObjectPtr< FunctionVector_obj > __this = new FunctionVector_obj();
	__this->__construct(__o_length,__o_fixed,array);
	return __this;
}

::hx::ObjectPtr< FunctionVector_obj > FunctionVector_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< int >  __o_length,::hx::Null< bool >  __o_fixed,::cpp::VirtualArray array) {
	FunctionVector_obj *__this = (FunctionVector_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FunctionVector_obj), true, "openfl._Vector.FunctionVector"));
	*(void **)__this = FunctionVector_obj::_hx_vtable;
	__this->__construct(__o_length,__o_fixed,array);
	return __this;
}

FunctionVector_obj::FunctionVector_obj()
{
}

void FunctionVector_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FunctionVector);
	HX_MARK_MEMBER_NAME(fixed,"fixed");
	HX_MARK_MEMBER_NAME(_hx___array,"__array");
	HX_MARK_MEMBER_NAME(_hx___tempIndex,"__tempIndex");
	HX_MARK_END_CLASS();
}

void FunctionVector_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fixed,"fixed");
	HX_VISIT_MEMBER_NAME(_hx___array,"__array");
	HX_VISIT_MEMBER_NAME(_hx___tempIndex,"__tempIndex");
}

::hx::Val FunctionVector_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"fixed") ) { return ::hx::Val( fixed ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"toJSON") ) { return ::hx::Val( toJSON_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__array") ) { return ::hx::Val( _hx___array ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_length") ) { return ::hx::Val( set_length_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__tempIndex") ) { return ::hx::Val( _hx___tempIndex ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FunctionVector_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"fixed") ) { fixed=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__array") ) { _hx___array=inValue.Cast< ::cpp::VirtualArray >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__tempIndex") ) { _hx___tempIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FunctionVector_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("fixed",74,f9,a1,00));
	outFields->push(HX_("__array",79,c6,ed,8f));
	outFields->push(HX_("__tempIndex",3e,e8,54,22));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FunctionVector_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(FunctionVector_obj,fixed),HX_("fixed",74,f9,a1,00)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(int)offsetof(FunctionVector_obj,_hx___array),HX_("__array",79,c6,ed,8f)},
	{::hx::fsInt,(int)offsetof(FunctionVector_obj,_hx___tempIndex),HX_("__tempIndex",3e,e8,54,22)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *FunctionVector_obj_sStaticStorageInfo = 0;
#endif

static ::String FunctionVector_obj_sMemberFields[] = {
	HX_("fixed",74,f9,a1,00),
	HX_("__array",79,c6,ed,8f),
	HX_("__tempIndex",3e,e8,54,22),
	HX_("toJSON",23,49,09,7c),
	HX_("set_length",23,a3,0c,93),
	::String(null()) };

::hx::Class FunctionVector_obj::__mClass;

void FunctionVector_obj::__register()
{
	FunctionVector_obj _hx_dummy;
	FunctionVector_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl._Vector.FunctionVector",a5,07,75,4f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FunctionVector_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FunctionVector_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FunctionVector_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FunctionVector_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void FunctionVector_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_f37013fa3e7b7067_1227_boot)
HXDLIN(1227)		__mClass->__meta__ =  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("fields",79,8e,8e,80), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("toJSON",23,49,09,7c), ::Dynamic(::hx::Anon_obj::Create(1)
            					->setFixed(0,HX_("SuppressWarnings",0c,d3,d2,00),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("checkstyle:Dynamic",ce,ea,47,3c)))))))
            			->setFixed(1,HX_("obj",f7,8f,54,00), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("SuppressWarnings",0c,d3,d2,00),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("checkstyle:FieldDocComment",70,56,1b,20))))));
            	}
}

} // end namespace openfl
} // end namespace _Vector