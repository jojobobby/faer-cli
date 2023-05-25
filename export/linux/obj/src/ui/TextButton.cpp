// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
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
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_TextButton
#include <ui/TextButton.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0e9b098b7f58afb0_7_new,"ui.TextButton","new",0x82454feb,"ui.TextButton.new","ui/TextButton.hx",7,0x3177a944)
HX_LOCAL_STACK_FRAME(_hx_pos_0e9b098b7f58afb0_47_draw,"ui.TextButton","draw",0x73ce4619,"ui.TextButton.draw","ui/TextButton.hx",47,0x3177a944)
HX_LOCAL_STACK_FRAME(_hx_pos_0e9b098b7f58afb0_53_onMouseOver,"ui.TextButton","onMouseOver",0xbf6caf85,"ui.TextButton.onMouseOver","ui/TextButton.hx",53,0x3177a944)
HX_LOCAL_STACK_FRAME(_hx_pos_0e9b098b7f58afb0_58_onRollOut,"ui.TextButton","onRollOut",0xfb7eeb7d,"ui.TextButton.onRollOut","ui/TextButton.hx",58,0x3177a944)
namespace ui{

void TextButton_obj::__construct(int size,::String text,::hx::Null< int >  __o_bWidth){
            		int bWidth = __o_bWidth.Default(0);
            	HX_GC_STACKFRAME(&_hx_pos_0e9b098b7f58afb0_7_new)
HXLINE(  13)		this->color = 16777215;
HXLINE(   9)		this->w = 0;
HXLINE(  16)		super::__construct();
HXLINE(  18)		this->text =  ::ui::SimpleText_obj::__alloc( HX_CTX ,size,3552822,false,0,0,null());
HXLINE(  19)		this->text->setBold(true);
HXLINE(  20)		this->text->set_text(text);
HXLINE(  21)		this->text->updateMetrics();
HXLINE(  22)		this->addChild(this->text);
HXLINE(  23)		int _hx_tmp;
HXDLIN(  23)		if ((bWidth != 0)) {
HXLINE(  23)			_hx_tmp = bWidth;
            		}
            		else {
HXLINE(  23)			_hx_tmp = ::Std_obj::_hx_int((this->text->get_width() + 12));
            		}
HXDLIN(  23)		this->w = _hx_tmp;
HXLINE(  24)		this->draw();
HXLINE(  25)		 ::ui::SimpleText _hx_tmp1 = this->text;
HXDLIN(  25)		Float _hx_tmp2 = (( (Float)(this->w) ) / ( (Float)(2) ));
HXDLIN(  25)		_hx_tmp1->set_x(((_hx_tmp2 - (this->text->get_textWidth() / ( (Float)(2) ))) - ( (Float)(2) )));
HXLINE(  26)		this->text->set_y(( (Float)(1) ));
HXLINE(  27)		this->addEventListener(HX_("mouseOver",19,4a,0d,f6),this->onMouseOver_dyn(),null(),null(),null());
HXLINE(  28)		this->addEventListener(HX_("rollOut",11,f9,11,5d),this->onRollOut_dyn(),null(),null(),null());
            	}

Dynamic TextButton_obj::__CreateEmpty() { return new TextButton_obj; }

void *TextButton_obj::_hx_vtable = 0;

Dynamic TextButton_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< TextButton_obj > _hx_result = new TextButton_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool TextButton_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0c89e854) {
		if (inClassId<=(int)0x0c15399f) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c15399f;
			}
		} else {
			return inClassId==(int)0x0c89e854;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void TextButton_obj::draw(){
            	HX_STACKFRAME(&_hx_pos_0e9b098b7f58afb0_47_draw)
HXLINE(  48)		this->get_graphics()->clear();
HXLINE(  49)		this->get_graphics()->beginFill(this->color,1);
HXLINE(  50)		 ::openfl::display::Graphics _hx_tmp = this->get_graphics();
HXDLIN(  50)		int _hx_tmp1 = this->w;
HXDLIN(  50)		_hx_tmp->drawRect(( (Float)(0) ),( (Float)(0) ),( (Float)(_hx_tmp1) ),( (Float)(::Std_obj::_hx_int((this->text->get_textHeight() + 8))) ));
            	}


HX_DEFINE_DYNAMIC_FUNC0(TextButton_obj,draw,(void))

void TextButton_obj::onMouseOver( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_0e9b098b7f58afb0_53_onMouseOver)
HXLINE(  54)		this->color = 16768133;
HXLINE(  55)		this->draw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(TextButton_obj,onMouseOver,(void))

void TextButton_obj::onRollOut( ::openfl::events::MouseEvent event){
            	HX_STACKFRAME(&_hx_pos_0e9b098b7f58afb0_58_onRollOut)
HXLINE(  59)		this->color = 16777215;
HXLINE(  60)		this->draw();
            	}


HX_DEFINE_DYNAMIC_FUNC1(TextButton_obj,onRollOut,(void))


::hx::ObjectPtr< TextButton_obj > TextButton_obj::__new(int size,::String text,::hx::Null< int >  __o_bWidth) {
	::hx::ObjectPtr< TextButton_obj > __this = new TextButton_obj();
	__this->__construct(size,text,__o_bWidth);
	return __this;
}

::hx::ObjectPtr< TextButton_obj > TextButton_obj::__alloc(::hx::Ctx *_hx_ctx,int size,::String text,::hx::Null< int >  __o_bWidth) {
	TextButton_obj *__this = (TextButton_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TextButton_obj), true, "ui.TextButton"));
	*(void **)__this = TextButton_obj::_hx_vtable;
	__this->__construct(size,text,__o_bWidth);
	return __this;
}

TextButton_obj::TextButton_obj()
{
}

void TextButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextButton);
	HX_MARK_MEMBER_NAME(text,"text");
	HX_MARK_MEMBER_NAME(w,"w");
	HX_MARK_MEMBER_NAME(color,"color");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextButton_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(text,"text");
	HX_VISIT_MEMBER_NAME(w,"w");
	HX_VISIT_MEMBER_NAME(color,"color");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val TextButton_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { return ::hx::Val( w ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return ::hx::Val( text ); }
		if (HX_FIELD_EQ(inName,"draw") ) { return ::hx::Val( draw_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return ::hx::Val( color ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onRollOut") ) { return ::hx::Val( onRollOut_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return ::hx::Val( onMouseOver_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val TextButton_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { text=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextButton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("text",ad,cc,f9,4c));
	outFields->push(HX_("w",77,00,00,00));
	outFields->push(HX_("color",63,71,5c,4a));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo TextButton_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(TextButton_obj,text),HX_("text",ad,cc,f9,4c)},
	{::hx::fsInt,(int)offsetof(TextButton_obj,w),HX_("w",77,00,00,00)},
	{::hx::fsInt,(int)offsetof(TextButton_obj,color),HX_("color",63,71,5c,4a)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *TextButton_obj_sStaticStorageInfo = 0;
#endif

static ::String TextButton_obj_sMemberFields[] = {
	HX_("text",ad,cc,f9,4c),
	HX_("w",77,00,00,00),
	HX_("color",63,71,5c,4a),
	HX_("draw",04,2c,70,42),
	HX_("onMouseOver",fa,2c,50,18),
	HX_("onRollOut",b2,b1,bc,34),
	::String(null()) };

::hx::Class TextButton_obj::__mClass;

void TextButton_obj::__register()
{
	TextButton_obj _hx_dummy;
	TextButton_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.TextButton",79,7e,f6,07);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(TextButton_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< TextButton_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = TextButton_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = TextButton_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
