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
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_DropShadowFilter
#include <openfl/filters/DropShadowFilter.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_TextInputField
#include <ui/TextInputField.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_93951840217e57d8_17_new,"ui.TextInputField","new",0xe2d6e0c9,"ui.TextInputField.new","ui/TextInputField.hx",17,0x5bbaf9a6)
HX_LOCAL_STACK_FRAME(_hx_pos_93951840217e57d8_48_text,"ui.TextInputField","text",0x9d251824,"ui.TextInputField.text","ui/TextInputField.hx",48,0x5bbaf9a6)
HX_LOCAL_STACK_FRAME(_hx_pos_93951840217e57d8_51_setError,"ui.TextInputField","setError",0x553a07bd,"ui.TextInputField.setError","ui/TextInputField.hx",51,0x5bbaf9a6)
HX_LOCAL_STACK_FRAME(_hx_pos_93951840217e57d8_57_onInputChange,"ui.TextInputField","onInputChange",0x15c197e4,"ui.TextInputField.onInputChange","ui/TextInputField.hx",57,0x5bbaf9a6)
namespace ui{

void TextInputField_obj::__construct(::String name,bool isPassword,::String error){
            	HX_GC_STACKFRAME(&_hx_pos_93951840217e57d8_17_new)
HXLINE(  18)		super::__construct();
HXLINE(  20)		this->nameText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,18,11776947,false,0,0,null());
HXLINE(  21)		this->nameText->setBold(true);
HXLINE(  22)		this->nameText->set_text(name);
HXLINE(  23)		this->nameText->updateMetrics();
HXLINE(  24)		 ::ui::SimpleText _hx_tmp = this->nameText;
HXDLIN(  24)		_hx_tmp->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,null(),null(),null(),null(),null(),null(),null(),null())));
HXLINE(  25)		this->addChild(this->nameText);
HXLINE(  26)		this->inputText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,20,11776947,true,238,30,null());
HXLINE(  27)		this->inputText->set_y(( (Float)(30) ));
HXLINE(  28)		this->inputText->set_x(( (Float)(6) ));
HXLINE(  29)		this->inputText->set_border(false);
HXLINE(  30)		this->inputText->set_displayAsPassword(isPassword);
HXLINE(  31)		this->inputText->updateMetrics();
HXLINE(  32)		this->addChild(this->inputText);
HXLINE(  33)		this->get_graphics()->lineStyle(2,4539717,1,false,2,1,2,null());
HXLINE(  34)		this->get_graphics()->beginFill(3355443,1);
HXLINE(  35)		 ::openfl::display::Graphics _hx_tmp1 = this->get_graphics();
HXDLIN(  35)		_hx_tmp1->drawRect(( (Float)(0) ),this->inputText->get_y(),( (Float)(238) ),( (Float)(30) ));
HXLINE(  36)		this->get_graphics()->endFill();
HXLINE(  37)		this->get_graphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
HXLINE(  38)		this->inputText->addEventListener(HX_("change",70,91,72,b7),this->onInputChange_dyn(),null(),null(),null());
HXLINE(  39)		this->errorText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,12,16549442,false,0,0,null());
HXLINE(  40)		 ::ui::SimpleText _hx_tmp2 = this->errorText;
HXDLIN(  40)		_hx_tmp2->set_y((this->inputText->get_y() + 32));
HXLINE(  41)		this->errorText->set_text(error);
HXLINE(  42)		this->errorText->updateMetrics();
HXLINE(  43)		 ::ui::SimpleText _hx_tmp3 = this->errorText;
HXDLIN(  43)		_hx_tmp3->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,null(),null(),null(),null(),null(),null(),null(),null())));
HXLINE(  44)		this->addChild(this->errorText);
            	}

Dynamic TextInputField_obj::__CreateEmpty() { return new TextInputField_obj; }

void *TextInputField_obj::_hx_vtable = 0;

Dynamic TextInputField_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< TextInputField_obj > _hx_result = new TextInputField_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool TextInputField_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x6930ef51) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x6930ef51;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

::String TextInputField_obj::text(){
            	HX_STACKFRAME(&_hx_pos_93951840217e57d8_48_text)
HXDLIN(  48)		return this->inputText->get_text();
            	}


HX_DEFINE_DYNAMIC_FUNC0(TextInputField_obj,text,return )

void TextInputField_obj::setError(::String error){
            	HX_STACKFRAME(&_hx_pos_93951840217e57d8_51_setError)
HXLINE(  52)		this->errorText->set_text(error);
HXLINE(  53)		this->errorText->updateMetrics();
            	}


HX_DEFINE_DYNAMIC_FUNC1(TextInputField_obj,setError,(void))

void TextInputField_obj::onInputChange( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_93951840217e57d8_57_onInputChange)
HXDLIN(  57)		this->setError(HX_("",00,00,00,00));
            	}


HX_DEFINE_DYNAMIC_FUNC1(TextInputField_obj,onInputChange,(void))


::hx::ObjectPtr< TextInputField_obj > TextInputField_obj::__new(::String name,bool isPassword,::String error) {
	::hx::ObjectPtr< TextInputField_obj > __this = new TextInputField_obj();
	__this->__construct(name,isPassword,error);
	return __this;
}

::hx::ObjectPtr< TextInputField_obj > TextInputField_obj::__alloc(::hx::Ctx *_hx_ctx,::String name,bool isPassword,::String error) {
	TextInputField_obj *__this = (TextInputField_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TextInputField_obj), true, "ui.TextInputField"));
	*(void **)__this = TextInputField_obj::_hx_vtable;
	__this->__construct(name,isPassword,error);
	return __this;
}

TextInputField_obj::TextInputField_obj()
{
}

void TextInputField_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextInputField);
	HX_MARK_MEMBER_NAME(nameText,"nameText");
	HX_MARK_MEMBER_NAME(inputText,"inputText");
	HX_MARK_MEMBER_NAME(errorText,"errorText");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextInputField_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nameText,"nameText");
	HX_VISIT_MEMBER_NAME(inputText,"inputText");
	HX_VISIT_MEMBER_NAME(errorText,"errorText");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val TextInputField_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return ::hx::Val( text_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nameText") ) { return ::hx::Val( nameText ); }
		if (HX_FIELD_EQ(inName,"setError") ) { return ::hx::Val( setError_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"inputText") ) { return ::hx::Val( inputText ); }
		if (HX_FIELD_EQ(inName,"errorText") ) { return ::hx::Val( errorText ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onInputChange") ) { return ::hx::Val( onInputChange_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val TextInputField_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"nameText") ) { nameText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"inputText") ) { inputText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"errorText") ) { errorText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextInputField_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("nameText",98,ec,80,49));
	outFields->push(HX_("inputText",d7,89,24,14));
	outFields->push(HX_("errorText",95,48,62,73));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo TextInputField_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(TextInputField_obj,nameText),HX_("nameText",98,ec,80,49)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(TextInputField_obj,inputText),HX_("inputText",d7,89,24,14)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(TextInputField_obj,errorText),HX_("errorText",95,48,62,73)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *TextInputField_obj_sStaticStorageInfo = 0;
#endif

static ::String TextInputField_obj_sMemberFields[] = {
	HX_("nameText",98,ec,80,49),
	HX_("inputText",d7,89,24,14),
	HX_("errorText",95,48,62,73),
	HX_("text",ad,cc,f9,4c),
	HX_("setError",c6,34,5e,81),
	HX_("onInputChange",3b,8a,90,0f),
	::String(null()) };

::hx::Class TextInputField_obj::__mClass;

void TextInputField_obj::__register()
{
	TextInputField_obj _hx_dummy;
	TextInputField_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.TextInputField",57,c8,3a,63);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(TextInputField_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< TextInputField_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = TextInputField_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = TextInputField_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui