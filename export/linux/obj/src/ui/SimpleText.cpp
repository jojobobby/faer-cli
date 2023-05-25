// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_lime_text_Font
#include <lime/text/Font.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
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
#ifndef INCLUDED_openfl_text_Font
#include <openfl/text/Font.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_text_TextFormat
#include <openfl/text/TextFormat.h>
#endif
#ifndef INCLUDED_openfl_text_TextLineMetrics
#include <openfl/text/TextLineMetrics.h>
#endif
#ifndef INCLUDED_openfl_utils_Assets
#include <openfl/utils/Assets.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_46ad524dea92b8e4_12_new,"ui.SimpleText","new",0xd4952b6b,"ui.SimpleText.new","ui/SimpleText.hx",12,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_64_setSize,"ui.SimpleText","setSize",0x66cb1e0e,"ui.SimpleText.setSize","ui/SimpleText.hx",64,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_71_setColor,"ui.SimpleText","setColor",0x58729776,"ui.SimpleText.setColor","ui/SimpleText.hx",71,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_78_setBold,"ui.SimpleText","setBold",0x5b92fed2,"ui.SimpleText.setBold","ui/SimpleText.hx",78,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_85_setItalic,"ui.SimpleText","setItalic",0x4baf597d,"ui.SimpleText.setItalic","ui/SimpleText.hx",85,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_92_setAlignment,"ui.SimpleText","setAlignment",0xe5fc0e76,"ui.SimpleText.setAlignment","ui/SimpleText.hx",92,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_99_setText,"ui.SimpleText","setText",0x677149fa,"ui.SimpleText.setText","ui/SimpleText.hx",99,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_104_setHtmlText,"ui.SimpleText","setHtmlText",0x9e8cc785,"ui.SimpleText.setHtmlText","ui/SimpleText.hx",104,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_109_updateMetrics,"ui.SimpleText","updateMetrics",0xa172be05,"ui.SimpleText.updateMetrics","ui/SimpleText.hx",109,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_130_useTextDimensions,"ui.SimpleText","useTextDimensions",0xc797904c,"ui.SimpleText.useTextDimensions","ui/SimpleText.hx",130,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_135_applyFormat,"ui.SimpleText","applyFormat",0x977d2d50,"ui.SimpleText.applyFormat","ui/SimpleText.hx",135,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_141_onChange,"ui.SimpleText","onChange",0x97014504,"ui.SimpleText.onChange","ui/SimpleText.hx",141,0x70f9bdc4)
HX_LOCAL_STACK_FRAME(_hx_pos_46ad524dea92b8e4_14_boot,"ui.SimpleText","boot",0x2609d2c7,"ui.SimpleText.boot","ui/SimpleText.hx",14,0x70f9bdc4)
namespace ui{

void SimpleText_obj::__construct(int textSize,::hx::Null< int >  __o_color,::hx::Null< bool >  __o_settable,::hx::Null< int >  __o_widthParam,::hx::Null< int >  __o_heightParam,::hx::Null< bool >  __o_isLink){
            		int color = __o_color.Default(16777215);
            		bool settable = __o_settable.Default(false);
            		int widthParam = __o_widthParam.Default(0);
            		int heightParam = __o_heightParam.Default(0);
            		bool isLink = __o_isLink.Default(false);
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_12_new)
HXLINE(  19)		this->actualHeight = 0;
HXLINE(  18)		this->actualWidth = 0;
HXLINE(  17)		this->inputHeight = 0;
HXLINE(  16)		this->inputWidth = 0;
HXLINE(  22)		super::__construct();
HXLINE(  24)		if (!(::ui::SimpleText_obj::fontRegistered)) {
HXLINE(  25)			::ui::SimpleText_obj::font = ::openfl::utils::Assets_obj::getFont(HX_("assets/fonts/Ubuntu-Medium.ttf",3c,06,a6,3e),null());
HXLINE(  26)			::openfl::text::Font_obj::registerFont(::ui::SimpleText_obj::font);
HXLINE(  27)			::openfl::text::Font_obj::registerFont(::openfl::utils::Assets_obj::getFont(HX_("assets/fonts/Ubuntu-MediumItalic.ttf",4c,dc,77,1c),null()));
HXLINE(  28)			::openfl::text::Font_obj::registerFont(::openfl::utils::Assets_obj::getFont(HX_("assets/fonts/Ubuntu-Bold.ttf",8c,19,d8,4b),null()));
HXLINE(  29)			::openfl::text::Font_obj::registerFont(::openfl::utils::Assets_obj::getFont(HX_("assets/fonts/Ubuntu-BoldItalic.ttf",9c,4b,af,31),null()));
HXLINE(  30)			::ui::SimpleText_obj::fontRegistered = true;
            		}
HXLINE(  33)		this->inputWidth = widthParam;
HXLINE(  34)		if ((this->inputWidth != 0)) {
HXLINE(  35)			this->set_width(( (Float)(widthParam) ));
            		}
HXLINE(  37)		this->inputHeight = heightParam;
HXLINE(  38)		if ((this->inputHeight != 0)) {
HXLINE(  39)			this->set_height(( (Float)(heightParam) ));
            		}
HXLINE(  41)		 ::openfl::text::TextFormat format = this->get_defaultTextFormat();
HXLINE(  42)		format->font = ::ui::SimpleText_obj::font->name;
HXLINE(  43)		format->bold = false;
HXLINE(  44)		format->size = textSize;
HXLINE(  45)		format->color = color;
HXLINE(  46)		this->set_embedFonts(true);
HXLINE(  47)		this->set_defaultTextFormat(format);
HXLINE(  48)		if (settable) {
HXLINE(  49)			this->set_selectable(true);
HXLINE(  50)			this->mouseEnabled = true;
HXLINE(  51)			this->set_type(1);
HXLINE(  52)			this->set_border(true);
HXLINE(  53)			this->set_borderColor(color);
HXLINE(  54)			this->addEventListener(HX_("change",70,91,72,b7),this->onChange_dyn(),null(),null(),null());
            		}
            		else {
HXLINE(  56)			this->set_selectable(false);
HXLINE(  57)			this->mouseEnabled = false;
            		}
HXLINE(  60)		if (isLink) {
HXLINE(  61)			this->mouseEnabled = true;
            		}
            	}

Dynamic SimpleText_obj::__CreateEmpty() { return new SimpleText_obj; }

void *SimpleText_obj::_hx_vtable = 0;

Dynamic SimpleText_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SimpleText_obj > _hx_result = new SimpleText_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return _hx_result;
}

bool SimpleText_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x22af5d83) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x22af5d83;
		}
	} else {
		return inClassId==(int)0x6b353933 || inClassId==(int)0x7f0de750;
	}
}

 ::ui::SimpleText SimpleText_obj::setSize(int size){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_64_setSize)
HXLINE(  65)		 ::openfl::text::TextFormat format = this->get_defaultTextFormat();
HXLINE(  66)		format->size = size;
HXLINE(  67)		this->applyFormat(format);
HXLINE(  68)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,setSize,return )

 ::ui::SimpleText SimpleText_obj::setColor(int color){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_71_setColor)
HXLINE(  72)		 ::openfl::text::TextFormat format = this->get_defaultTextFormat();
HXLINE(  73)		format->color = color;
HXLINE(  74)		this->applyFormat(format);
HXLINE(  75)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,setColor,return )

 ::ui::SimpleText SimpleText_obj::setBold(bool bold){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_78_setBold)
HXLINE(  79)		 ::openfl::text::TextFormat format = this->get_defaultTextFormat();
HXLINE(  80)		format->bold = bold;
HXLINE(  81)		this->applyFormat(format);
HXLINE(  82)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,setBold,return )

 ::ui::SimpleText SimpleText_obj::setItalic(bool italic){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_85_setItalic)
HXLINE(  86)		 ::openfl::text::TextFormat format = this->get_defaultTextFormat();
HXLINE(  87)		format->italic = italic;
HXLINE(  88)		this->applyFormat(format);
HXLINE(  89)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,setItalic,return )

 ::ui::SimpleText SimpleText_obj::setAlignment( ::Dynamic alignment){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_92_setAlignment)
HXLINE(  93)		 ::openfl::text::TextFormat format = this->get_defaultTextFormat();
HXLINE(  94)		format->align = alignment;
HXLINE(  95)		this->applyFormat(format);
HXLINE(  96)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,setAlignment,return )

 ::ui::SimpleText SimpleText_obj::setText(::String text){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_99_setText)
HXLINE( 100)		this->set_text(text);
HXLINE( 101)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,setText,return )

 ::ui::SimpleText SimpleText_obj::setHtmlText(::String text){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_104_setHtmlText)
HXLINE( 105)		this->set_htmlText(text);
HXLINE( 106)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,setHtmlText,return )

 ::ui::SimpleText SimpleText_obj::updateMetrics(){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_109_updateMetrics)
HXLINE( 110)		 ::openfl::text::TextLineMetrics textMetrics = null();
HXLINE( 111)		int textWidth = 0;
HXLINE( 112)		int textHeight = 0;
HXLINE( 113)		this->actualWidth = 0;
HXLINE( 114)		this->actualHeight = 0;
HXLINE( 115)		{
HXLINE( 115)			int _g = 0;
HXDLIN( 115)			int _g1 = this->get_numLines();
HXDLIN( 115)			while((_g < _g1)){
HXLINE( 115)				_g = (_g + 1);
HXLINE( 116)				textMetrics = this->getLineMetrics((_g - 1));
HXLINE( 117)				textWidth = ::Std_obj::_hx_int((textMetrics->width + 4));
HXLINE( 118)				textHeight = ::Std_obj::_hx_int((textMetrics->height + 4));
HXLINE( 119)				if ((textWidth > this->actualWidth)) {
HXLINE( 120)					this->actualWidth = textWidth;
            				}
HXLINE( 122)				this->actualHeight = (this->actualHeight + textHeight);
            			}
            		}
HXLINE( 125)		Float _hx_tmp;
HXDLIN( 125)		if ((this->inputWidth == 0)) {
HXLINE( 125)			_hx_tmp = ( (Float)((this->actualWidth + 1)) );
            		}
            		else {
HXLINE( 125)			_hx_tmp = ( (Float)(this->inputWidth) );
            		}
HXDLIN( 125)		this->set_width(_hx_tmp);
HXLINE( 126)		Float _hx_tmp1;
HXDLIN( 126)		if ((this->inputHeight == 0)) {
HXLINE( 126)			_hx_tmp1 = ( (Float)((this->actualHeight + 1)) );
            		}
            		else {
HXLINE( 126)			_hx_tmp1 = ( (Float)(this->inputHeight) );
            		}
HXDLIN( 126)		this->set_height(_hx_tmp1);
HXLINE( 127)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC0(SimpleText_obj,updateMetrics,return )

void SimpleText_obj::useTextDimensions(){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_130_useTextDimensions)
HXLINE( 131)		Float _hx_tmp;
HXDLIN( 131)		if ((this->inputWidth == 0)) {
HXLINE( 131)			_hx_tmp = (this->get_textWidth() + 4);
            		}
            		else {
HXLINE( 131)			_hx_tmp = ( (Float)(this->inputWidth) );
            		}
HXDLIN( 131)		this->set_width(_hx_tmp);
HXLINE( 132)		Float _hx_tmp1;
HXDLIN( 132)		if ((this->inputHeight == 0)) {
HXLINE( 132)			_hx_tmp1 = (this->get_textHeight() + 16);
            		}
            		else {
HXLINE( 132)			_hx_tmp1 = ( (Float)(this->inputHeight) );
            		}
HXDLIN( 132)		this->set_height(_hx_tmp1);
            	}


HX_DEFINE_DYNAMIC_FUNC0(SimpleText_obj,useTextDimensions,(void))

void SimpleText_obj::applyFormat( ::openfl::text::TextFormat format){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_135_applyFormat)
HXLINE( 136)		this->setTextFormat(format,null(),null());
HXLINE( 137)		this->set_defaultTextFormat(format);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,applyFormat,(void))

void SimpleText_obj::onChange( ::openfl::events::Event _){
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_141_onChange)
HXDLIN( 141)		this->updateMetrics();
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleText_obj,onChange,(void))

 ::openfl::text::Font SimpleText_obj::font;

bool SimpleText_obj::fontRegistered;


::hx::ObjectPtr< SimpleText_obj > SimpleText_obj::__new(int textSize,::hx::Null< int >  __o_color,::hx::Null< bool >  __o_settable,::hx::Null< int >  __o_widthParam,::hx::Null< int >  __o_heightParam,::hx::Null< bool >  __o_isLink) {
	::hx::ObjectPtr< SimpleText_obj > __this = new SimpleText_obj();
	__this->__construct(textSize,__o_color,__o_settable,__o_widthParam,__o_heightParam,__o_isLink);
	return __this;
}

::hx::ObjectPtr< SimpleText_obj > SimpleText_obj::__alloc(::hx::Ctx *_hx_ctx,int textSize,::hx::Null< int >  __o_color,::hx::Null< bool >  __o_settable,::hx::Null< int >  __o_widthParam,::hx::Null< int >  __o_heightParam,::hx::Null< bool >  __o_isLink) {
	SimpleText_obj *__this = (SimpleText_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SimpleText_obj), true, "ui.SimpleText"));
	*(void **)__this = SimpleText_obj::_hx_vtable;
	__this->__construct(textSize,__o_color,__o_settable,__o_widthParam,__o_heightParam,__o_isLink);
	return __this;
}

SimpleText_obj::SimpleText_obj()
{
}

::hx::Val SimpleText_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"setSize") ) { return ::hx::Val( setSize_dyn() ); }
		if (HX_FIELD_EQ(inName,"setBold") ) { return ::hx::Val( setBold_dyn() ); }
		if (HX_FIELD_EQ(inName,"setText") ) { return ::hx::Val( setText_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setColor") ) { return ::hx::Val( setColor_dyn() ); }
		if (HX_FIELD_EQ(inName,"onChange") ) { return ::hx::Val( onChange_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setItalic") ) { return ::hx::Val( setItalic_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"inputWidth") ) { return ::hx::Val( inputWidth ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"inputHeight") ) { return ::hx::Val( inputHeight ); }
		if (HX_FIELD_EQ(inName,"actualWidth") ) { return ::hx::Val( actualWidth ); }
		if (HX_FIELD_EQ(inName,"setHtmlText") ) { return ::hx::Val( setHtmlText_dyn() ); }
		if (HX_FIELD_EQ(inName,"applyFormat") ) { return ::hx::Val( applyFormat_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"actualHeight") ) { return ::hx::Val( actualHeight ); }
		if (HX_FIELD_EQ(inName,"setAlignment") ) { return ::hx::Val( setAlignment_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"updateMetrics") ) { return ::hx::Val( updateMetrics_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"useTextDimensions") ) { return ::hx::Val( useTextDimensions_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool SimpleText_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { outValue = ( font ); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"fontRegistered") ) { outValue = ( fontRegistered ); return true; }
	}
	return false;
}

::hx::Val SimpleText_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"inputWidth") ) { inputWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"inputHeight") ) { inputHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"actualWidth") ) { actualWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"actualHeight") ) { actualHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool SimpleText_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { font=ioValue.Cast<  ::openfl::text::Font >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"fontRegistered") ) { fontRegistered=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

void SimpleText_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("inputWidth",9c,7d,9d,48));
	outFields->push(HX_("inputHeight",91,e3,7f,f7));
	outFields->push(HX_("actualWidth",98,d8,41,38));
	outFields->push(HX_("actualHeight",15,25,ab,b7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo SimpleText_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(SimpleText_obj,inputWidth),HX_("inputWidth",9c,7d,9d,48)},
	{::hx::fsInt,(int)offsetof(SimpleText_obj,inputHeight),HX_("inputHeight",91,e3,7f,f7)},
	{::hx::fsInt,(int)offsetof(SimpleText_obj,actualWidth),HX_("actualWidth",98,d8,41,38)},
	{::hx::fsInt,(int)offsetof(SimpleText_obj,actualHeight),HX_("actualHeight",15,25,ab,b7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo SimpleText_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::text::Font */ ,(void *) &SimpleText_obj::font,HX_("font",cf,5d,c0,43)},
	{::hx::fsBool,(void *) &SimpleText_obj::fontRegistered,HX_("fontRegistered",31,f8,e0,5f)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String SimpleText_obj_sMemberFields[] = {
	HX_("inputWidth",9c,7d,9d,48),
	HX_("inputHeight",91,e3,7f,f7),
	HX_("actualWidth",98,d8,41,38),
	HX_("actualHeight",15,25,ab,b7),
	HX_("setSize",83,e1,d7,11),
	HX_("setColor",61,da,90,58),
	HX_("setBold",47,c2,9f,06),
	HX_("setItalic",32,a4,0b,66),
	HX_("setAlignment",e1,a2,8d,0e),
	HX_("setText",6f,0d,7e,12),
	HX_("setHtmlText",7a,e9,98,40),
	HX_("updateMetrics",3a,07,43,f8),
	HX_("useTextDimensions",01,18,fd,8a),
	HX_("applyFormat",45,4f,89,39),
	HX_("onChange",ef,87,1f,97),
	::String(null()) };

static void SimpleText_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SimpleText_obj::font,"font");
	HX_MARK_MEMBER_NAME(SimpleText_obj::fontRegistered,"fontRegistered");
};

#ifdef HXCPP_VISIT_ALLOCS
static void SimpleText_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleText_obj::font,"font");
	HX_VISIT_MEMBER_NAME(SimpleText_obj::fontRegistered,"fontRegistered");
};

#endif

::hx::Class SimpleText_obj::__mClass;

static ::String SimpleText_obj_sStaticFields[] = {
	HX_("font",cf,5d,c0,43),
	HX_("fontRegistered",31,f8,e0,5f),
	::String(null())
};

void SimpleText_obj::__register()
{
	SimpleText_obj _hx_dummy;
	SimpleText_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.SimpleText",f9,99,52,f7);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SimpleText_obj::__GetStatic;
	__mClass->mSetStaticField = &SimpleText_obj::__SetStatic;
	__mClass->mMarkFunc = SimpleText_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(SimpleText_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(SimpleText_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< SimpleText_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = SimpleText_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SimpleText_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SimpleText_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void SimpleText_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_46ad524dea92b8e4_14_boot)
HXDLIN(  14)		fontRegistered = false;
            	}
}

} // end namespace ui
