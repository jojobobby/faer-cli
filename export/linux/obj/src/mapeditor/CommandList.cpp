// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_mapeditor_Command
#include <mapeditor/Command.h>
#endif
#ifndef INCLUDED_mapeditor_CommandList
#include <mapeditor/CommandList.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_65c3a1e25c81346c_6_new,"mapeditor.CommandList","new",0xc98dab76,"mapeditor.CommandList.new","mapeditor/CommandList.hx",6,0x5ec8947b)
HX_LOCAL_STACK_FRAME(_hx_pos_65c3a1e25c81346c_10_empty,"mapeditor.CommandList","empty",0x5f918723,"mapeditor.CommandList.empty","mapeditor/CommandList.hx",10,0x5ec8947b)
HX_LOCAL_STACK_FRAME(_hx_pos_65c3a1e25c81346c_14_addCommand,"mapeditor.CommandList","addCommand",0xbad4f0d4,"mapeditor.CommandList.addCommand","mapeditor/CommandList.hx",14,0x5ec8947b)
HX_LOCAL_STACK_FRAME(_hx_pos_65c3a1e25c81346c_18_execute,"mapeditor.CommandList","execute",0x91a1284b,"mapeditor.CommandList.execute","mapeditor/CommandList.hx",18,0x5ec8947b)
HX_LOCAL_STACK_FRAME(_hx_pos_65c3a1e25c81346c_23_unexecute,"mapeditor.CommandList","unexecute",0x31776092,"mapeditor.CommandList.unexecute","mapeditor/CommandList.hx",23,0x5ec8947b)
namespace mapeditor{

void CommandList_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_65c3a1e25c81346c_6_new)
HXDLIN(   6)		this->list = ::Array_obj< ::Dynamic>::__new();
            	}

Dynamic CommandList_obj::__CreateEmpty() { return new CommandList_obj; }

void *CommandList_obj::_hx_vtable = 0;

Dynamic CommandList_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CommandList_obj > _hx_result = new CommandList_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CommandList_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x36ffe4a4;
}

bool CommandList_obj::empty(){
            	HX_STACKFRAME(&_hx_pos_65c3a1e25c81346c_10_empty)
HXDLIN(  10)		return (this->list->length == 0);
            	}


HX_DEFINE_DYNAMIC_FUNC0(CommandList_obj,empty,return )

void CommandList_obj::addCommand( ::mapeditor::Command command){
            	HX_STACKFRAME(&_hx_pos_65c3a1e25c81346c_14_addCommand)
HXDLIN(  14)		this->list->push(command);
            	}


HX_DEFINE_DYNAMIC_FUNC1(CommandList_obj,addCommand,(void))

void CommandList_obj::execute(){
            	HX_STACKFRAME(&_hx_pos_65c3a1e25c81346c_18_execute)
HXDLIN(  18)		int _g = 0;
HXDLIN(  18)		::Array< ::Dynamic> _g1 = this->list;
HXDLIN(  18)		while((_g < _g1->length)){
HXDLIN(  18)			 ::mapeditor::Command command = _g1->__get(_g).StaticCast<  ::mapeditor::Command >();
HXDLIN(  18)			_g = (_g + 1);
HXLINE(  19)			command->execute();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(CommandList_obj,execute,(void))

void CommandList_obj::unexecute(){
            	HX_STACKFRAME(&_hx_pos_65c3a1e25c81346c_23_unexecute)
HXDLIN(  23)		int _g = 0;
HXDLIN(  23)		::Array< ::Dynamic> _g1 = this->list;
HXDLIN(  23)		while((_g < _g1->length)){
HXDLIN(  23)			 ::mapeditor::Command command = _g1->__get(_g).StaticCast<  ::mapeditor::Command >();
HXDLIN(  23)			_g = (_g + 1);
HXLINE(  24)			command->unexecute();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(CommandList_obj,unexecute,(void))


::hx::ObjectPtr< CommandList_obj > CommandList_obj::__new() {
	::hx::ObjectPtr< CommandList_obj > __this = new CommandList_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CommandList_obj > CommandList_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CommandList_obj *__this = (CommandList_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CommandList_obj), true, "mapeditor.CommandList"));
	*(void **)__this = CommandList_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CommandList_obj::CommandList_obj()
{
}

void CommandList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CommandList);
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_END_CLASS();
}

void CommandList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(list,"list");
}

::hx::Val CommandList_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return ::hx::Val( list ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"empty") ) { return ::hx::Val( empty_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"execute") ) { return ::hx::Val( execute_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"unexecute") ) { return ::hx::Val( unexecute_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addCommand") ) { return ::hx::Val( addCommand_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CommandList_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CommandList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("list",5e,1c,b3,47));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CommandList_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(CommandList_obj,list),HX_("list",5e,1c,b3,47)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CommandList_obj_sStaticStorageInfo = 0;
#endif

static ::String CommandList_obj_sMemberFields[] = {
	HX_("list",5e,1c,b3,47),
	HX_("empty",8d,3a,da,6f),
	HX_("addCommand",2a,9d,f7,e8),
	HX_("execute",35,0a,0d,cc),
	HX_("unexecute",fc,10,0f,c8),
	::String(null()) };

::hx::Class CommandList_obj::__mClass;

void CommandList_obj::__register()
{
	CommandList_obj _hx_dummy;
	CommandList_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("mapeditor.CommandList",84,78,d1,d7);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CommandList_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CommandList_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CommandList_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CommandList_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mapeditor