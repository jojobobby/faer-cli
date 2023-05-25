// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_openfl__Vector_FloatVector
#include <openfl/_Vector/FloatVector.h>
#endif
#ifndef INCLUDED_openfl__Vector_IVector
#include <openfl/_Vector/IVector.h>
#endif
#ifndef INCLUDED_openfl__Vector_IntVector
#include <openfl/_Vector/IntVector.h>
#endif
#ifndef INCLUDED_openfl__Vector_ObjectVector
#include <openfl/_Vector/ObjectVector.h>
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
#ifndef INCLUDED_openfl_display_GraphicsEndFill
#include <openfl/display/GraphicsEndFill.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsPath
#include <openfl/display/GraphicsPath.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsSolidFill
#include <openfl/display/GraphicsSolidFill.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsStroke
#include <openfl/display/GraphicsStroke.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_IGraphicsData
#include <openfl/display/IGraphicsData.h>
#endif
#ifndef INCLUDED_openfl_display_IGraphicsFill
#include <openfl/display/IGraphicsFill.h>
#endif
#ifndef INCLUDED_openfl_display_IGraphicsPath
#include <openfl/display/IGraphicsPath.h>
#endif
#ifndef INCLUDED_openfl_display_IGraphicsStroke
#include <openfl/display/IGraphicsStroke.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Shape
#include <openfl/display/Shape.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
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
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_TextButton
#include <ui/TextButton.h>
#endif
#ifndef INCLUDED_ui_dialogs_Dialog
#include <ui/dialogs/Dialog.h>
#endif
#ifndef INCLUDED_util_GraphicsUtil
#include <util/GraphicsUtil.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_79a5e9d3dbb4a6af_22_new,"ui.dialogs.Dialog","new",0x9c8d4497,"ui.dialogs.Dialog.new","ui/dialogs/Dialog.hx",22,0x2ced0177)
HX_LOCAL_STACK_FRAME(_hx_pos_79a5e9d3dbb4a6af_66_initText,"ui.dialogs.Dialog","initText",0x2a53e046,"ui.dialogs.Dialog.initText","ui/dialogs/Dialog.hx",66,0x2ced0177)
HX_LOCAL_STACK_FRAME(_hx_pos_79a5e9d3dbb4a6af_78_draw,"ui.dialogs.Dialog","draw",0x587c67ed,"ui.dialogs.Dialog.draw","ui/dialogs/Dialog.hx",78,0x2ced0177)
static const int _hx_array_data_9023ad25_3[] = {
	(int)1,(int)1,(int)1,(int)1,
};
HX_LOCAL_STACK_FRAME(_hx_pos_79a5e9d3dbb4a6af_112_initTitleText,"ui.dialogs.Dialog","initTitleText",0xe17ffc2c,"ui.dialogs.Dialog.initTitleText","ui/dialogs/Dialog.hx",112,0x2ced0177)
HX_LOCAL_STACK_FRAME(_hx_pos_79a5e9d3dbb4a6af_121_onAddedToStage,"ui.dialogs.Dialog","onAddedToStage",0x60781b4b,"ui.dialogs.Dialog.onAddedToStage","ui/dialogs/Dialog.hx",121,0x2ced0177)
HX_LOCAL_STACK_FRAME(_hx_pos_79a5e9d3dbb4a6af_127_onButton1Click,"ui.dialogs.Dialog","onButton1Click",0x3a54f6b1,"ui.dialogs.Dialog.onButton1Click","ui/dialogs/Dialog.hx",127,0x2ced0177)
HX_LOCAL_STACK_FRAME(_hx_pos_79a5e9d3dbb4a6af_131_onButton2Click,"ui.dialogs.Dialog","onButton2Click",0xa0b05310,"ui.dialogs.Dialog.onButton2Click","ui/dialogs/Dialog.hx",131,0x2ced0177)
namespace ui{
namespace dialogs{

void Dialog_obj::__construct(::String text,::String title,::String button1,::String button2){
            	HX_GC_STACKFRAME(&_hx_pos_79a5e9d3dbb4a6af_22_new)
HXLINE(  39)		this->backgroundFill =  ::openfl::display::GraphicsSolidFill_obj::__alloc( HX_CTX ,3552822,1);
HXLINE(  37)		this->outlineFill =  ::openfl::display::GraphicsSolidFill_obj::__alloc( HX_CTX ,16777215,1);
HXLINE(  36)		this->path =  ::openfl::display::GraphicsPath_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  34)		this->offsetY = ((Float)0.0);
HXLINE(  33)		this->offsetX = ((Float)0.0);
HXLINE(  32)		this->button2 = null();
HXLINE(  31)		this->button1 = null();
HXLINE(  30)		this->titleText = null();
HXLINE(  43)		super::__construct();
HXLINE(  45)		this->lineStyle =  ::openfl::display::GraphicsStroke_obj::__alloc( HX_CTX ,1,false,2,0,2,3,this->outlineFill);
HXLINE(  46)		this->graphicsData =  ::openfl::_Vector::ObjectVector_obj::__alloc( HX_CTX ,0,false,::Array_obj< ::Dynamic>::__new(5)->init(0,this->lineStyle)->init(1,this->backgroundFill)->init(2,this->path)->init(3,::util::GraphicsUtil_obj::END_FILL)->init(4,::util::GraphicsUtil_obj::END_STROKE),true);
HXLINE(  47)		this->box =  ::openfl::display::Sprite_obj::__alloc( HX_CTX );
HXLINE(  48)		this->initText(text);
HXLINE(  49)		this->initTitleText(title);
HXLINE(  50)		if (::hx::IsNotNull( button1 )) {
HXLINE(  51)			this->button1 =  ::ui::TextButton_obj::__alloc( HX_CTX ,16,button1,120);
HXLINE(  52)			this->button1->addEventListener(HX_("click",48,7c,5e,48),this->onButton1Click_dyn(),null(),null(),null());
            		}
HXLINE(  54)		if (::hx::IsNotNull( button2 )) {
HXLINE(  55)			this->button2 =  ::ui::TextButton_obj::__alloc( HX_CTX ,16,button2,120);
HXLINE(  56)			this->button2->addEventListener(HX_("click",48,7c,5e,48),this->onButton2Click_dyn(),null(),null(),null());
            		}
HXLINE(  58)		this->draw();
HXLINE(  59)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAddedToStage_dyn(),null(),null(),null());
            	}

Dynamic Dialog_obj::__CreateEmpty() { return new Dialog_obj; }

void *Dialog_obj::_hx_vtable = 0;

Dynamic Dialog_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Dialog_obj > _hx_result = new Dialog_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool Dialog_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x46543c1b || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void Dialog_obj::initText(::String text){
            	HX_GC_STACKFRAME(&_hx_pos_79a5e9d3dbb4a6af_66_initText)
HXLINE(  67)		this->textText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,14,11776947,false,260,0,null());
HXLINE(  68)		this->textText->set_x(( (Float)(20) ));
HXLINE(  69)		this->textText->set_multiline(true);
HXLINE(  70)		this->textText->set_wordWrap(true);
HXLINE(  71)		this->textText->set_htmlText(((HX_("<p align=\"center\">",cf,04,3d,e9) + text) + HX_("</p>",01,d9,cc,27)));
HXLINE(  72)		this->textText->set_autoSize(0);
HXLINE(  73)		this->textText->mouseEnabled = true;
HXLINE(  74)		this->textText->updateMetrics();
HXLINE(  75)		 ::ui::SimpleText _hx_tmp = this->textText;
HXDLIN(  75)		_hx_tmp->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,6,6,1,null(),null(),null(),null())));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Dialog_obj,initText,(void))

void Dialog_obj::draw(){
            	HX_GC_STACKFRAME(&_hx_pos_79a5e9d3dbb4a6af_78_draw)
HXLINE(  79)		int by = 0;
HXLINE(  80)		if (::hx::IsNotNull( this->titleText )) {
HXLINE(  81)			this->titleText->set_y(( (Float)(2) ));
HXLINE(  82)			this->box->addChild(this->titleText);
HXLINE(  83)			 ::ui::SimpleText _hx_tmp = this->textText;
HXDLIN(  83)			_hx_tmp->set_y((this->box->get_height() + 8));
            		}
            		else {
HXLINE(  85)			this->textText->set_y(( (Float)(4) ));
            		}
HXLINE(  87)		this->box->addChild(this->textText);
HXLINE(  88)		if (::hx::IsNotNull( this->button1 )) {
HXLINE(  89)			by = ::Std_obj::_hx_int((this->box->get_height() + 16));
HXLINE(  90)			this->box->addChild(this->button1);
HXLINE(  91)			this->button1->set_y(( (Float)(by) ));
HXLINE(  92)			if (::hx::IsNull( this->button2 )) {
HXLINE(  93)				 ::ui::TextButton _hx_tmp1 = this->button1;
HXDLIN(  93)				_hx_tmp1->set_x((((Float)150.) - (this->button1->get_width() / ( (Float)(2) ))));
            			}
            			else {
HXLINE(  95)				 ::ui::TextButton _hx_tmp2 = this->button1;
HXDLIN(  95)				_hx_tmp2->set_x((((Float)75.) - (this->button1->get_width() / ( (Float)(2) ))));
HXLINE(  96)				this->box->addChild(this->button2);
HXLINE(  97)				 ::ui::TextButton _hx_tmp3 = this->button2;
HXDLIN(  97)				_hx_tmp3->set_x((((Float)225.) - (this->button2->get_width() / ( (Float)(2) ))));
HXLINE(  98)				this->button2->set_y(( (Float)(by) ));
            			}
            		}
HXLINE( 101)		::util::GraphicsUtil_obj::clearPath(this->path);
HXLINE( 102)		int _hx_tmp4 = ::Std_obj::_hx_int((this->box->get_height() + 10));
HXDLIN( 102)		::util::GraphicsUtil_obj::drawCutEdgeRect(0,0,300,_hx_tmp4,4,::Array_obj< int >::fromData( _hx_array_data_9023ad25_3,4),this->path);
HXLINE( 103)		this->rect =  ::openfl::display::Shape_obj::__alloc( HX_CTX );
HXLINE( 104)		 ::openfl::display::Graphics g = this->rect->get_graphics();
HXLINE( 105)		g->drawGraphicsData(this->graphicsData);
HXLINE( 106)		this->box->addChildAt(this->rect,0);
HXLINE( 107)		 ::openfl::display::Sprite _hx_tmp5 = this->box;
HXDLIN( 107)		_hx_tmp5->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,16,16,1,null(),null(),null(),null())));
HXLINE( 108)		this->addChild(this->box);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Dialog_obj,draw,(void))

void Dialog_obj::initTitleText(::String title){
            	HX_GC_STACKFRAME(&_hx_pos_79a5e9d3dbb4a6af_112_initTitleText)
HXDLIN( 112)		if (::hx::IsNotNull( title )) {
HXLINE( 113)			this->titleText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,18,5746018,false,300,0,null());
HXLINE( 114)			this->titleText->setBold(true);
HXLINE( 115)			this->titleText->set_htmlText(((HX_("<p align=\"center\">",cf,04,3d,e9) + title) + HX_("</p>",01,d9,cc,27)));
HXLINE( 116)			this->titleText->updateMetrics();
HXLINE( 117)			 ::ui::SimpleText _hx_tmp = this->titleText;
HXDLIN( 117)			_hx_tmp->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,1,8,8,1,null(),null(),null(),null())));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Dialog_obj,initTitleText,(void))

void Dialog_obj::onAddedToStage( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_79a5e9d3dbb4a6af_121_onAddedToStage)
HXLINE( 122)		 ::openfl::display::Sprite _hx_tmp = this->box;
HXDLIN( 122)		Float _hx_tmp1 = (this->offsetX + (( (Float)(this->stage->stageWidth) ) / ( (Float)(2) )));
HXDLIN( 122)		_hx_tmp->set_x((_hx_tmp1 - (this->box->get_width() / ( (Float)(2) ))));
HXLINE( 123)		 ::openfl::display::Sprite _hx_tmp2 = this->box;
HXDLIN( 123)		Float _hx_tmp3 = (this->offsetY + (( (Float)(this->stage->stageHeight) ) / ( (Float)(2) )));
HXDLIN( 123)		_hx_tmp2->set_y((_hx_tmp3 - (this->box->get_height() / ( (Float)(2) ))));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Dialog_obj,onAddedToStage,(void))

void Dialog_obj::onButton1Click( ::openfl::events::MouseEvent event){
            	HX_GC_STACKFRAME(&_hx_pos_79a5e9d3dbb4a6af_127_onButton1Click)
HXDLIN( 127)		this->dispatchEvent( ::openfl::events::Event_obj::__alloc( HX_CTX ,HX_("DIALOG_BUTTON1",48,38,81,e9),null(),null()));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Dialog_obj,onButton1Click,(void))

void Dialog_obj::onButton2Click( ::openfl::events::Event event){
            	HX_GC_STACKFRAME(&_hx_pos_79a5e9d3dbb4a6af_131_onButton2Click)
HXDLIN( 131)		this->dispatchEvent( ::openfl::events::Event_obj::__alloc( HX_CTX ,HX_("DIALOG_BUTTON2",49,38,81,e9),null(),null()));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Dialog_obj,onButton2Click,(void))


::hx::ObjectPtr< Dialog_obj > Dialog_obj::__new(::String text,::String title,::String button1,::String button2) {
	::hx::ObjectPtr< Dialog_obj > __this = new Dialog_obj();
	__this->__construct(text,title,button1,button2);
	return __this;
}

::hx::ObjectPtr< Dialog_obj > Dialog_obj::__alloc(::hx::Ctx *_hx_ctx,::String text,::String title,::String button1,::String button2) {
	Dialog_obj *__this = (Dialog_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Dialog_obj), true, "ui.dialogs.Dialog"));
	*(void **)__this = Dialog_obj::_hx_vtable;
	__this->__construct(text,title,button1,button2);
	return __this;
}

Dialog_obj::Dialog_obj()
{
}

void Dialog_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Dialog);
	HX_MARK_MEMBER_NAME(box,"box");
	HX_MARK_MEMBER_NAME(rect,"rect");
	HX_MARK_MEMBER_NAME(textText,"textText");
	HX_MARK_MEMBER_NAME(titleText,"titleText");
	HX_MARK_MEMBER_NAME(button1,"button1");
	HX_MARK_MEMBER_NAME(button2,"button2");
	HX_MARK_MEMBER_NAME(offsetX,"offsetX");
	HX_MARK_MEMBER_NAME(offsetY,"offsetY");
	HX_MARK_MEMBER_NAME(path,"path");
	HX_MARK_MEMBER_NAME(outlineFill,"outlineFill");
	HX_MARK_MEMBER_NAME(lineStyle,"lineStyle");
	HX_MARK_MEMBER_NAME(backgroundFill,"backgroundFill");
	HX_MARK_MEMBER_NAME(graphicsData,"graphicsData");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Dialog_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(box,"box");
	HX_VISIT_MEMBER_NAME(rect,"rect");
	HX_VISIT_MEMBER_NAME(textText,"textText");
	HX_VISIT_MEMBER_NAME(titleText,"titleText");
	HX_VISIT_MEMBER_NAME(button1,"button1");
	HX_VISIT_MEMBER_NAME(button2,"button2");
	HX_VISIT_MEMBER_NAME(offsetX,"offsetX");
	HX_VISIT_MEMBER_NAME(offsetY,"offsetY");
	HX_VISIT_MEMBER_NAME(path,"path");
	HX_VISIT_MEMBER_NAME(outlineFill,"outlineFill");
	HX_VISIT_MEMBER_NAME(lineStyle,"lineStyle");
	HX_VISIT_MEMBER_NAME(backgroundFill,"backgroundFill");
	HX_VISIT_MEMBER_NAME(graphicsData,"graphicsData");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Dialog_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"box") ) { return ::hx::Val( box ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { return ::hx::Val( rect ); }
		if (HX_FIELD_EQ(inName,"path") ) { return ::hx::Val( path ); }
		if (HX_FIELD_EQ(inName,"draw") ) { return ::hx::Val( draw_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"button1") ) { return ::hx::Val( button1 ); }
		if (HX_FIELD_EQ(inName,"button2") ) { return ::hx::Val( button2 ); }
		if (HX_FIELD_EQ(inName,"offsetX") ) { return ::hx::Val( offsetX ); }
		if (HX_FIELD_EQ(inName,"offsetY") ) { return ::hx::Val( offsetY ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"textText") ) { return ::hx::Val( textText ); }
		if (HX_FIELD_EQ(inName,"initText") ) { return ::hx::Val( initText_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { return ::hx::Val( titleText ); }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return ::hx::Val( lineStyle ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"outlineFill") ) { return ::hx::Val( outlineFill ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"graphicsData") ) { return ::hx::Val( graphicsData ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"initTitleText") ) { return ::hx::Val( initTitleText_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"backgroundFill") ) { return ::hx::Val( backgroundFill ); }
		if (HX_FIELD_EQ(inName,"onAddedToStage") ) { return ::hx::Val( onAddedToStage_dyn() ); }
		if (HX_FIELD_EQ(inName,"onButton1Click") ) { return ::hx::Val( onButton1Click_dyn() ); }
		if (HX_FIELD_EQ(inName,"onButton2Click") ) { return ::hx::Val( onButton2Click_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Dialog_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"box") ) { box=inValue.Cast<  ::openfl::display::Sprite >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { rect=inValue.Cast<  ::openfl::display::Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"path") ) { path=inValue.Cast<  ::openfl::display::GraphicsPath >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"button1") ) { button1=inValue.Cast<  ::ui::TextButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"button2") ) { button2=inValue.Cast<  ::ui::TextButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetX") ) { offsetX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetY") ) { offsetY=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"textText") ) { textText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { titleText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { lineStyle=inValue.Cast<  ::openfl::display::GraphicsStroke >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"outlineFill") ) { outlineFill=inValue.Cast<  ::openfl::display::GraphicsSolidFill >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"graphicsData") ) { graphicsData=inValue.Cast<  ::openfl::_Vector::ObjectVector >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"backgroundFill") ) { backgroundFill=inValue.Cast<  ::openfl::display::GraphicsSolidFill >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Dialog_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("box",0b,be,4a,00));
	outFields->push(HX_("rect",24,4d,a7,4b));
	outFields->push(HX_("textText",fa,1f,f5,4f));
	outFields->push(HX_("titleText",65,ba,a4,70));
	outFields->push(HX_("button1",ff,51,75,ca));
	outFields->push(HX_("button2",00,52,75,ca));
	outFields->push(HX_("offsetX",65,09,65,d7));
	outFields->push(HX_("offsetY",66,09,65,d7));
	outFields->push(HX_("path",a5,e5,51,4a));
	outFields->push(HX_("outlineFill",25,fb,c1,d8));
	outFields->push(HX_("lineStyle",9d,a8,18,cb));
	outFields->push(HX_("backgroundFill",91,1d,d6,17));
	outFields->push(HX_("graphicsData",95,3c,58,41));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Dialog_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::display::Sprite */ ,(int)offsetof(Dialog_obj,box),HX_("box",0b,be,4a,00)},
	{::hx::fsObject /*  ::openfl::display::Shape */ ,(int)offsetof(Dialog_obj,rect),HX_("rect",24,4d,a7,4b)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(Dialog_obj,textText),HX_("textText",fa,1f,f5,4f)},
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(Dialog_obj,titleText),HX_("titleText",65,ba,a4,70)},
	{::hx::fsObject /*  ::ui::TextButton */ ,(int)offsetof(Dialog_obj,button1),HX_("button1",ff,51,75,ca)},
	{::hx::fsObject /*  ::ui::TextButton */ ,(int)offsetof(Dialog_obj,button2),HX_("button2",00,52,75,ca)},
	{::hx::fsFloat,(int)offsetof(Dialog_obj,offsetX),HX_("offsetX",65,09,65,d7)},
	{::hx::fsFloat,(int)offsetof(Dialog_obj,offsetY),HX_("offsetY",66,09,65,d7)},
	{::hx::fsObject /*  ::openfl::display::GraphicsPath */ ,(int)offsetof(Dialog_obj,path),HX_("path",a5,e5,51,4a)},
	{::hx::fsObject /*  ::openfl::display::GraphicsSolidFill */ ,(int)offsetof(Dialog_obj,outlineFill),HX_("outlineFill",25,fb,c1,d8)},
	{::hx::fsObject /*  ::openfl::display::GraphicsStroke */ ,(int)offsetof(Dialog_obj,lineStyle),HX_("lineStyle",9d,a8,18,cb)},
	{::hx::fsObject /*  ::openfl::display::GraphicsSolidFill */ ,(int)offsetof(Dialog_obj,backgroundFill),HX_("backgroundFill",91,1d,d6,17)},
	{::hx::fsObject /*  ::openfl::_Vector::ObjectVector */ ,(int)offsetof(Dialog_obj,graphicsData),HX_("graphicsData",95,3c,58,41)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Dialog_obj_sStaticStorageInfo = 0;
#endif

static ::String Dialog_obj_sMemberFields[] = {
	HX_("box",0b,be,4a,00),
	HX_("rect",24,4d,a7,4b),
	HX_("textText",fa,1f,f5,4f),
	HX_("titleText",65,ba,a4,70),
	HX_("button1",ff,51,75,ca),
	HX_("button2",00,52,75,ca),
	HX_("offsetX",65,09,65,d7),
	HX_("offsetY",66,09,65,d7),
	HX_("path",a5,e5,51,4a),
	HX_("outlineFill",25,fb,c1,d8),
	HX_("lineStyle",9d,a8,18,cb),
	HX_("backgroundFill",91,1d,d6,17),
	HX_("graphicsData",95,3c,58,41),
	HX_("initText",dd,fb,b0,51),
	HX_("draw",04,2c,70,42),
	HX_("initTitleText",35,7d,a4,eb),
	HX_("onAddedToStage",22,82,44,36),
	HX_("onButton1Click",88,5d,21,10),
	HX_("onButton2Click",e7,b9,7c,76),
	::String(null()) };

::hx::Class Dialog_obj::__mClass;

void Dialog_obj::__register()
{
	Dialog_obj _hx_dummy;
	Dialog_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.dialogs.Dialog",25,ad,23,90);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Dialog_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Dialog_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Dialog_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Dialog_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace dialogs
