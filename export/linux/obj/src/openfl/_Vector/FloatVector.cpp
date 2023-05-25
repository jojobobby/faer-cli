// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_openfl__Vector_FloatVector
#include <openfl/_Vector/FloatVector.h>
#endif
#ifndef INCLUDED_openfl__Vector_IVector
#include <openfl/_Vector/IVector.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_055b1e986ae1a23a_977_new,"openfl._Vector.FloatVector","new",0x7ccdf307,"openfl._Vector.FloatVector.new","openfl/Vector.hx",977,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1000_concat,"openfl._Vector.FloatVector","concat",0xbb39c8cd,"openfl._Vector.FloatVector.concat","openfl/Vector.hx",1000,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1021_copy,"openfl._Vector.FloatVector","copy",0xb028eb2e,"openfl._Vector.FloatVector.copy","openfl/Vector.hx",1021,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1031_get,"openfl._Vector.FloatVector","get",0x7cc8a33d,"openfl._Vector.FloatVector.get","openfl/Vector.hx",1031,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1049_insertAt,"openfl._Vector.FloatVector","insertAt",0xb3435c85,"openfl._Vector.FloatVector.insertAt","openfl/Vector.hx",1049,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1092_push,"openfl._Vector.FloatVector","push",0xb8c54153,"openfl._Vector.FloatVector.push","openfl/Vector.hx",1092,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1120_set,"openfl._Vector.FloatVector","set",0x7cd1be49,"openfl._Vector.FloatVector.set","openfl/Vector.hx",1120,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1155_splice,"openfl._Vector.FloatVector","splice",0xb3084535,"openfl._Vector.FloatVector.splice","openfl/Vector.hx",1155,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1161_toJSON,"openfl._Vector.FloatVector","toJSON",0x6f7308dc,"openfl._Vector.FloatVector.toJSON","openfl/Vector.hx",1161,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1180_get_length,"openfl._Vector.FloatVector","get_length",0xf96594e8,"openfl._Vector.FloatVector.get_length","openfl/Vector.hx",1180,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_1184_set_length,"openfl._Vector.FloatVector","set_length",0xfce3335c,"openfl._Vector.FloatVector.set_length","openfl/Vector.hx",1184,0x4a01873c)
HX_LOCAL_STACK_FRAME(_hx_pos_055b1e986ae1a23a_967_boot,"openfl._Vector.FloatVector","boot",0xaf7fb3ab,"openfl._Vector.FloatVector.boot","openfl/Vector.hx",967,0x4a01873c)
namespace openfl{
namespace _Vector{

void FloatVector_obj::__construct(::hx::Null< int >  __o_length,::hx::Null< bool >  __o_fixed,::cpp::VirtualArray array,::hx::Null< bool >  __o_forceCopy){
            		int length = __o_length.Default(0);
            		bool fixed = __o_fixed.Default(false);
            		bool forceCopy = __o_forceCopy.Default(false);
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_977_new)
HXLINE( 978)		if (forceCopy) {
HXLINE( 980)			this->_hx___array = ::Array_obj< Float >::__new();
HXLINE( 981)			if (::hx::IsNotNull( array )) {
HXLINE( 981)				int _g = 0;
HXDLIN( 981)				int _g1 = array->get_length();
HXDLIN( 981)				while((_g < _g1)){
HXLINE( 981)					_g = (_g + 1);
HXDLIN( 981)					int i = (_g - 1);
HXLINE( 982)					this->_hx___array[i] = ( (Float)(array->__get(i)) );
            				}
            			}
            		}
            		else {
HXLINE( 986)			if (::hx::IsNull( array )) {
HXLINE( 986)				array = ::Array_obj< Float >::__new();
            			}
HXLINE( 987)			this->_hx___array = array;
            		}
HXLINE( 990)		if ((length > 0)) {
HXLINE( 992)			this->set_length(length);
            		}
HXLINE( 995)		this->fixed = fixed;
            	}

Dynamic FloatVector_obj::__CreateEmpty() { return new FloatVector_obj; }

void *FloatVector_obj::_hx_vtable = 0;

Dynamic FloatVector_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FloatVector_obj > _hx_result = new FloatVector_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool FloatVector_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x2f9ab9ed;
}

static ::openfl::_Vector::IVector_obj _hx_openfl__Vector_FloatVector__hx_openfl__Vector_IVector= {
};

void *FloatVector_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0x45e7caba: return &_hx_openfl__Vector_FloatVector__hx_openfl__Vector_IVector;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

::Dynamic FloatVector_obj::concat(::Dynamic a){
            	HX_GC_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1000_concat)
HXDLIN(1000)		if (::hx::IsNull( a )) {
HXLINE(1002)			return  ::openfl::_Vector::FloatVector_obj::__alloc( HX_CTX ,0,false,this->_hx___array->copy(),null());
            		}
            		else {
HXLINE(1006)			 ::openfl::_Vector::FloatVector other = ( ( ::openfl::_Vector::FloatVector)(a) );
HXLINE(1008)			if ((other->_hx___array->length > 0)) {
HXLINE(1010)				return  ::openfl::_Vector::FloatVector_obj::__alloc( HX_CTX ,0,false,this->_hx___array->concat(other->_hx___array),null());
            			}
            			else {
HXLINE(1014)				return  ::openfl::_Vector::FloatVector_obj::__alloc( HX_CTX ,0,false,this->_hx___array->copy(),null());
            			}
            		}
HXLINE(1000)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(FloatVector_obj,concat,return )

::Dynamic FloatVector_obj::copy(){
            	HX_GC_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1021_copy)
HXDLIN(1021)		bool _hx_tmp = this->fixed;
HXDLIN(1021)		return  ::openfl::_Vector::FloatVector_obj::__alloc( HX_CTX ,0,_hx_tmp,this->_hx___array->copy(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(FloatVector_obj,copy,return )

Float FloatVector_obj::get(int index){
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1031_get)
HXDLIN(1031)		return this->_hx___array->__get(index);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FloatVector_obj,get,return )

void FloatVector_obj::insertAt(int index,Float element){
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1049_insertAt)
HXDLIN(1049)		bool _hx_tmp;
HXDLIN(1049)		if (this->fixed) {
HXDLIN(1049)			_hx_tmp = (index < this->_hx___array->length);
            		}
            		else {
HXDLIN(1049)			_hx_tmp = true;
            		}
HXDLIN(1049)		if (_hx_tmp) {
HXLINE(1051)			this->_hx___array->insert(index,element);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(FloatVector_obj,insertAt,(void))

int FloatVector_obj::push(Float x){
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1092_push)
HXDLIN(1092)		if (!(this->fixed)) {
HXLINE(1094)			return this->_hx___array->push(x);
            		}
            		else {
HXLINE(1098)			return this->_hx___array->length;
            		}
HXLINE(1092)		return 0;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FloatVector_obj,push,return )

Float FloatVector_obj::set(int index,Float value){
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1120_set)
HXDLIN(1120)		bool _hx_tmp;
HXDLIN(1120)		if (this->fixed) {
HXDLIN(1120)			_hx_tmp = (index < this->_hx___array->length);
            		}
            		else {
HXDLIN(1120)			_hx_tmp = true;
            		}
HXDLIN(1120)		if (_hx_tmp) {
HXLINE(1122)			return (this->_hx___array[index] = value);
            		}
            		else {
HXLINE(1126)			return value;
            		}
HXLINE(1120)		return ((Float)0.);
            	}


HX_DEFINE_DYNAMIC_FUNC2(FloatVector_obj,set,return )

::Dynamic FloatVector_obj::splice(int pos,int len){
            	HX_GC_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1155_splice)
HXDLIN(1155)		return  ::openfl::_Vector::FloatVector_obj::__alloc( HX_CTX ,0,false,this->_hx___array->splice(pos,len),null());
            	}


HX_DEFINE_DYNAMIC_FUNC2(FloatVector_obj,splice,return )

 ::Dynamic FloatVector_obj::toJSON(){
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1161_toJSON)
HXDLIN(1161)		return this->_hx___array;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FloatVector_obj,toJSON,return )

int FloatVector_obj::get_length(){
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1180_get_length)
HXDLIN(1180)		return this->_hx___array->length;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FloatVector_obj,get_length,return )

int FloatVector_obj::set_length(int value){
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_1184_set_length)
HXLINE(1185)		bool _hx_tmp;
HXDLIN(1185)		if ((value != this->_hx___array->length)) {
HXLINE(1185)			_hx_tmp = !(this->fixed);
            		}
            		else {
HXLINE(1185)			_hx_tmp = false;
            		}
HXDLIN(1185)		if (_hx_tmp) {
HXLINE(1188)			if ((value > this->_hx___array->length)) {
HXLINE(1190)				_hx_array_set_size_exact(this->_hx___array,value);
            			}
            			else {
HXLINE(1194)				this->_hx___array->removeRange(value,this->_hx___array->length);
            			}
            		}
HXLINE(1217)		return this->_hx___array->length;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FloatVector_obj,set_length,return )


::hx::ObjectPtr< FloatVector_obj > FloatVector_obj::__new(::hx::Null< int >  __o_length,::hx::Null< bool >  __o_fixed,::cpp::VirtualArray array,::hx::Null< bool >  __o_forceCopy) {
	::hx::ObjectPtr< FloatVector_obj > __this = new FloatVector_obj();
	__this->__construct(__o_length,__o_fixed,array,__o_forceCopy);
	return __this;
}

::hx::ObjectPtr< FloatVector_obj > FloatVector_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< int >  __o_length,::hx::Null< bool >  __o_fixed,::cpp::VirtualArray array,::hx::Null< bool >  __o_forceCopy) {
	FloatVector_obj *__this = (FloatVector_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FloatVector_obj), true, "openfl._Vector.FloatVector"));
	*(void **)__this = FloatVector_obj::_hx_vtable;
	__this->__construct(__o_length,__o_fixed,array,__o_forceCopy);
	return __this;
}

FloatVector_obj::FloatVector_obj()
{
}

void FloatVector_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatVector);
	HX_MARK_MEMBER_NAME(fixed,"fixed");
	HX_MARK_MEMBER_NAME(_hx___array,"__array");
	HX_MARK_MEMBER_NAME(_hx___tempIndex,"__tempIndex");
	HX_MARK_END_CLASS();
}

void FloatVector_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fixed,"fixed");
	HX_VISIT_MEMBER_NAME(_hx___array,"__array");
	HX_VISIT_MEMBER_NAME(_hx___tempIndex,"__tempIndex");
}

::hx::Val FloatVector_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return ::hx::Val( get_dyn() ); }
		if (HX_FIELD_EQ(inName,"set") ) { return ::hx::Val( set_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return ::hx::Val( copy_dyn() ); }
		if (HX_FIELD_EQ(inName,"push") ) { return ::hx::Val( push_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"fixed") ) { return ::hx::Val( fixed ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_length() ); }
		if (HX_FIELD_EQ(inName,"concat") ) { return ::hx::Val( concat_dyn() ); }
		if (HX_FIELD_EQ(inName,"splice") ) { return ::hx::Val( splice_dyn() ); }
		if (HX_FIELD_EQ(inName,"toJSON") ) { return ::hx::Val( toJSON_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__array") ) { return ::hx::Val( _hx___array ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"insertAt") ) { return ::hx::Val( insertAt_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return ::hx::Val( get_length_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_length") ) { return ::hx::Val( set_length_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__tempIndex") ) { return ::hx::Val( _hx___tempIndex ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FloatVector_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"fixed") ) { fixed=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_length(inValue.Cast< int >()) ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__array") ) { _hx___array=inValue.Cast< ::Array< Float > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__tempIndex") ) { _hx___tempIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatVector_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("fixed",74,f9,a1,00));
	outFields->push(HX_("length",e6,94,07,9f));
	outFields->push(HX_("__array",79,c6,ed,8f));
	outFields->push(HX_("__tempIndex",3e,e8,54,22));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FloatVector_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(FloatVector_obj,fixed),HX_("fixed",74,f9,a1,00)},
	{::hx::fsObject /* ::Array< Float > */ ,(int)offsetof(FloatVector_obj,_hx___array),HX_("__array",79,c6,ed,8f)},
	{::hx::fsInt,(int)offsetof(FloatVector_obj,_hx___tempIndex),HX_("__tempIndex",3e,e8,54,22)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *FloatVector_obj_sStaticStorageInfo = 0;
#endif

static ::String FloatVector_obj_sMemberFields[] = {
	HX_("fixed",74,f9,a1,00),
	HX_("__array",79,c6,ed,8f),
	HX_("__tempIndex",3e,e8,54,22),
	HX_("concat",14,09,d0,c7),
	HX_("copy",b5,bb,c4,41),
	HX_("get",96,80,4e,00),
	HX_("insertAt",8c,7c,1f,c2),
	HX_("push",da,11,61,4a),
	HX_("set",a2,9b,57,00),
	HX_("splice",7c,85,9e,bf),
	HX_("toJSON",23,49,09,7c),
	HX_("get_length",af,04,8f,8f),
	HX_("set_length",23,a3,0c,93),
	::String(null()) };

::hx::Class FloatVector_obj::__mClass;

void FloatVector_obj::__register()
{
	FloatVector_obj _hx_dummy;
	FloatVector_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl._Vector.FloatVector",95,63,f0,2f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FloatVector_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FloatVector_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FloatVector_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FloatVector_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void FloatVector_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_055b1e986ae1a23a_967_boot)
HXDLIN( 967)		__mClass->__meta__ =  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("fields",79,8e,8e,80), ::Dynamic(::hx::Anon_obj::Create(2)
            				->setFixed(0,HX_("_",5f,00,00,00), ::Dynamic(::hx::Anon_obj::Create(1)
            					->setFixed(0,HX_("SuppressWarnings",0c,d3,d2,00),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("checkstyle:Dynamic",ce,ea,47,3c)))))
            				->setFixed(1,HX_("toJSON",23,49,09,7c), ::Dynamic(::hx::Anon_obj::Create(1)
            					->setFixed(0,HX_("SuppressWarnings",0c,d3,d2,00),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("checkstyle:Dynamic",ce,ea,47,3c)))))))
            			->setFixed(1,HX_("obj",f7,8f,54,00), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("SuppressWarnings",0c,d3,d2,00),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("checkstyle:FieldDocComment",70,56,1b,20))))));
            	}
}

} // end namespace openfl
} // end namespace _Vector
