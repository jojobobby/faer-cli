// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

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
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
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
#ifndef INCLUDED_openfl_events_MouseEvent
#include <openfl/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_DropShadowFilter
#include <openfl/filters/DropShadowFilter.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_screens_ServerBox
#include <screens/ServerBox.h>
#endif
#ifndef INCLUDED_servers_Server
#include <servers/Server.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_ee070671dcde5335_9_new,"screens.ServerBox","new",0x293658b3,"screens.ServerBox.new","screens/ServerBox.hx",9,0x617cfb9e)
HX_LOCAL_STACK_FRAME(_hx_pos_ee070671dcde5335_58_setSelected,"screens.ServerBox","setSelected",0x60bd8770,"screens.ServerBox.setSelected","screens/ServerBox.hx",58,0x617cfb9e)
HX_LOCAL_STACK_FRAME(_hx_pos_ee070671dcde5335_63_draw,"screens.ServerBox","draw",0xdfc4ec51,"screens.ServerBox.draw","screens/ServerBox.hx",63,0x617cfb9e)
HX_LOCAL_STACK_FRAME(_hx_pos_ee070671dcde5335_75_onMouseOver,"screens.ServerBox","onMouseOver",0x973fc04d,"screens.ServerBox.onMouseOver","screens/ServerBox.hx",75,0x617cfb9e)
HX_LOCAL_STACK_FRAME(_hx_pos_ee070671dcde5335_80_onRollOut,"screens.ServerBox","onRollOut",0x15aaba45,"screens.ServerBox.onRollOut","screens/ServerBox.hx",80,0x617cfb9e)
namespace screens{

void ServerBox_obj::__construct( ::servers::Server server){
            	HX_GC_STACKFRAME(&_hx_pos_ee070671dcde5335_9_new)
HXLINE(  18)		this->over = false;
HXLINE(  17)		this->selected = false;
HXLINE(  13)		this->value = HX_("",00,00,00,00);
HXLINE(  21)		super::__construct();
HXLINE(  23)		int color = 0;
HXLINE(  24)		::String text = null();
HXLINE(  25)		::String _hx_tmp;
HXDLIN(  25)		if (::hx::IsNull( server )) {
HXLINE(  25)			_hx_tmp = null();
            		}
            		else {
HXLINE(  25)			_hx_tmp = server->name;
            		}
HXDLIN(  25)		this->value = _hx_tmp;
HXLINE(  26)		this->nameText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,18,16777215,false,0,0,null());
HXLINE(  27)		this->nameText->setBold(true);
HXLINE(  28)		::String _hx_tmp1;
HXDLIN(  28)		if (::hx::IsNull( server )) {
HXLINE(  28)			_hx_tmp1 = HX_("Best Server",3f,6a,81,99);
            		}
            		else {
HXLINE(  28)			_hx_tmp1 = server->name;
            		}
HXDLIN(  28)		this->nameText->set_text(_hx_tmp1);
HXLINE(  29)		this->nameText->updateMetrics();
HXLINE(  30)		 ::ui::SimpleText _hx_tmp2 = this->nameText;
HXDLIN(  30)		_hx_tmp2->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,8,8,null(),null(),null(),null(),null())));
HXLINE(  31)		this->nameText->set_x(( (Float)(18) ));
HXLINE(  32)		 ::ui::SimpleText _hx_tmp3 = this->nameText;
HXDLIN(  32)		_hx_tmp3->set_y((((Float)26.) - (this->nameText->get_height() / ( (Float)(2) ))));
HXLINE(  33)		this->addChild(this->nameText);
HXLINE(  34)		if (::hx::IsNotNull( server )) {
HXLINE(  35)			color = 65280;
HXLINE(  36)			text = HX_("Normal",47,e6,fd,64);
HXLINE(  37)			if (server->isFull()) {
HXLINE(  38)				color = 16711680;
HXLINE(  39)				text = HX_("Full",af,15,9e,2e);
            			}
            			else {
HXLINE(  40)				if (server->isCrowded()) {
HXLINE(  41)					color = 16549442;
HXLINE(  42)					text = HX_("Crowded",6c,38,3c,af);
            				}
            			}
HXLINE(  44)			this->statusText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,18,color,false,0,0,null());
HXLINE(  45)			this->statusText->setBold(true);
HXLINE(  46)			this->statusText->set_text(text);
HXLINE(  47)			this->statusText->updateMetrics();
HXLINE(  48)			 ::ui::SimpleText _hx_tmp4 = this->statusText;
HXDLIN(  48)			_hx_tmp4->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,8,8,null(),null(),null(),null(),null())));
HXLINE(  49)			 ::ui::SimpleText _hx_tmp5 = this->statusText;
HXDLIN(  49)			_hx_tmp5->set_x((((Float)192.) + (((Float)96.) - (this->statusText->get_width() / ( (Float)(2) )))));
HXLINE(  50)			 ::ui::SimpleText _hx_tmp6 = this->statusText;
HXDLIN(  50)			_hx_tmp6->set_y((((Float)26.) - (this->nameText->get_height() / ( (Float)(2) ))));
HXLINE(  51)			this->addChild(this->statusText);
            		}
HXLINE(  53)		this->draw();
HXLINE(  54)		this->addEventListener(HX_("mouseOver",19,4a,0d,f6),this->onMouseOver_dyn(),null(),null(),null());
HXLINE(  55)		this->addEventListener(HX_("rollOut",11,f9,11,5d),this->onRollOut_dyn(),null(),null(),null());
            	}

Dynamic ServerBox_obj::__CreateEmpty() { return new ServerBox_obj; }

void *ServerBox_obj::_hx_vtable = 0;

Dynamic ServerBox_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ServerBox_obj > _hx_result = new ServerBox_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool ServerBox_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x4ed53525) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x4ed53525;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void ServerBox_obj::setSelected(bool selected){
            	HX_STACKFRAME(&_hx_pos_ee070671dcde5335_58_setSelected)
HXLINE(  59)		this->selected = selected;
HXLINE(  60)		this->draw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ServerBox_obj,setSelected,(void))

void ServerBox_obj::draw(){
            	HX_STACKFRAME(&_hx_pos_ee070671dcde5335_63_draw)
HXLINE(  64)		this->get_graphics()->clear();
HXLINE(  65)		if (this->selected) {
HXLINE(  66)			this->get_graphics()->lineStyle(2,16777103,null(),null(),null(),null(),null(),null());
            		}
HXLINE(  68)		int _hx_tmp;
HXDLIN(  68)		if (this->over) {
HXLINE(  68)			_hx_tmp = 7039851;
            		}
            		else {
HXLINE(  68)			_hx_tmp = 6052956;
            		}
HXDLIN(  68)		this->get_graphics()->beginFill(_hx_tmp,1);
HXLINE(  69)		this->get_graphics()->drawRect(( (Float)(0) ),( (Float)(0) ),( (Float)(384) ),( (Float)(52) ));
HXLINE(  70)		if (this->selected) {
HXLINE(  71)			this->get_graphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(ServerBox_obj,draw,(void))

void ServerBox_obj::onMouseOver( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_ee070671dcde5335_75_onMouseOver)
HXLINE(  76)		this->over = true;
HXLINE(  77)		this->draw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ServerBox_obj,onMouseOver,(void))

void ServerBox_obj::onRollOut( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_ee070671dcde5335_80_onRollOut)
HXLINE(  81)		this->over = false;
HXLINE(  82)		this->draw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ServerBox_obj,onRollOut,(void))


::hx::ObjectPtr< ServerBox_obj > ServerBox_obj::__new( ::servers::Server server) {
	::hx::ObjectPtr< ServerBox_obj > __this = new ServerBox_obj();
	__this->__construct(server);
	return __this;
}

::hx::ObjectPtr< ServerBox_obj > ServerBox_obj::__alloc(::hx::Ctx *_hx_ctx, ::servers::Server server) {
	ServerBox_obj *__this = (ServerBox_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ServerBox_obj), true, "screens.ServerBox"));
	*(void **)__this = ServerBox_obj::_hx_vtable;
	__this->__construct(server);
	return __this;
}

ServerBox_obj::ServerBox_obj()
{
}

void ServerBox_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ServerBox);
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(nameText,"nameText");
	HX_MARK_MEMBER_NAME(statusText,"statusText");
	HX_MARK_MEMBER_NAME(selected,"selected");
	HX_MARK_MEMBER_NAME(over,"over");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ServerBox_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(nameText,"nameText");
	HX_VISIT_MEMBER_NAME(statusText,"statusText");
	HX_VISIT_MEMBER_NAME(selected,"selected");
	HX_VISIT_MEMBER_NAME(over,"over");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val ServerBox_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"over") ) { return ::hx::Val( over ); }
		if (HX_FIELD_EQ(inName,"draw") ) { return ::hx::Val( draw_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return ::hx::Val( value ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nameText") ) { return ::hx::Val( nameText ); }
		if (HX_FIELD_EQ(inName,"selected") ) { return ::hx::Val( selected ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onRollOut") ) { return ::hx::Val( onRollOut_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"statusText") ) { return ::hx::Val( statusText ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setSelected") ) { return ::hx::Val( setSelected_dyn() ); }
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return ::hx::Val( onMouseOver_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ServerBox_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"over") ) { over=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nameText") ) { nameText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"selected") ) { selected=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"statusText") ) { statusText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ServerBox_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("value",71,7f,b8,31));
	outFields->push(HX_("nameText",98,ec,80,49));
	outFields->push(HX_("statusText",ff,60,57,b1));
	outFields->push(HX_("selected",5b,2a,6d,b1));
	outFields->push(HX_("over",54,91,b8,49));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ServerBox_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(ServerBox_obj,value),HX_("value",71,7f,b8,31)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(ServerBox_obj,nameText),HX_("nameText",98,ec,80,49)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(ServerBox_obj,statusText),HX_("statusText",ff,60,57,b1)},
	{::hx::fsBool,(int)offsetof(ServerBox_obj,selected),HX_("selected",5b,2a,6d,b1)},
	{::hx::fsBool,(int)offsetof(ServerBox_obj,over),HX_("over",54,91,b8,49)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ServerBox_obj_sStaticStorageInfo = 0;
#endif

static ::String ServerBox_obj_sMemberFields[] = {
	HX_("value",71,7f,b8,31),
	HX_("nameText",98,ec,80,49),
	HX_("statusText",ff,60,57,b1),
	HX_("selected",5b,2a,6d,b1),
	HX_("over",54,91,b8,49),
	HX_("setSelected",1d,f4,cd,e1),
	HX_("draw",04,2c,70,42),
	HX_("onMouseOver",fa,2c,50,18),
	HX_("onRollOut",b2,b1,bc,34),
	::String(null()) };

::hx::Class ServerBox_obj::__mClass;

void ServerBox_obj::__register()
{
	ServerBox_obj _hx_dummy;
	ServerBox_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("screens.ServerBox",41,83,f1,52);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ServerBox_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ServerBox_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ServerBox_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ServerBox_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace screens
