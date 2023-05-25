// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_account_view_FormField
#include <account/view/FormField.h>
#endif
#ifndef INCLUDED_account_view_LabeledField
#include <account/view/LabeledField.h>
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
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_DropShadowFilter
#include <openfl/filters/DropShadowFilter.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_ui_ClickableText
#include <ui/ClickableText.h>
#endif
#ifndef INCLUDED_ui_Frame
#include <ui/Frame.h>
#endif
#ifndef INCLUDED_ui_SimpleText
#include <ui/SimpleText.h>
#endif
#ifndef INCLUDED_ui_TextInputField
#include <ui/TextInputField.h>
#endif
#ifndef INCLUDED_util_GraphicsUtil
#include <util/GraphicsUtil.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_18_new,"ui.Frame","new",0x384eb4e5,"ui.Frame.new","ui/Frame.hx",18,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_75_addLabeledField,"ui.Frame","addLabeledField",0xf98bd02d,"ui.Frame.addLabeledField","ui/Frame.hx",75,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_82_addTextInputField,"ui.Frame","addTextInputField",0xabcd28a3,"ui.Frame.addTextInputField","ui/Frame.hx",82,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_90_addNavigationText,"ui.Frame","addNavigationText",0xb64aaba7,"ui.Frame.addNavigationText","ui/Frame.hx",90,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_98_addComponent,"ui.Frame","addComponent",0x40e0f537,"ui.Frame.addComponent","ui/Frame.hx",98,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_137_addSpace,"ui.Frame","addSpace",0x24454c40,"ui.Frame.addSpace","ui/Frame.hx",137,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_140_disable,"ui.Frame","disable",0x5ee074ed,"ui.Frame.disable","ui/Frame.hx",140,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_150_enable,"ui.Frame","enable",0x855cab1e,"ui.Frame.enable","ui/Frame.hx",150,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_160_draw,"ui.Frame","draw",0x05fd3bdf,"ui.Frame.draw","ui/Frame.hx",160,0x750f972c)
static const int _hx_array_data_30775e73_11[] = {
	(int)1,(int)1,(int)0,(int)0,
};
static const int _hx_array_data_30775e73_12[] = {
	(int)1,(int)1,(int)1,(int)1,
};
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_171_onAddedToStage,"ui.Frame","onAddedToStage",0x12a011bd,"ui.Frame.onAddedToStage","ui/Frame.hx",171,0x750f972c)
HX_LOCAL_STACK_FRAME(_hx_pos_e90d7f3a74fa6ab3_179_onRemovedFromStage,"ui.Frame","onRemovedFromStage",0x4474c58e,"ui.Frame.onRemovedFromStage","ui/Frame.hx",179,0x750f972c)
namespace ui{

void Frame_obj::__construct(::String title,::String leftButton,::String rightButton,::hx::Null< int >  __o_w){
            		int w = __o_w.Default(288);
            	HX_GC_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_18_new)
HXLINE(  32)		this->path2 =  ::openfl::display::GraphicsPath_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  31)		this->path1 =  ::openfl::display::GraphicsPath_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  29)		this->outlineFill =  ::openfl::display::GraphicsSolidFill_obj::__alloc( HX_CTX ,16777215,1);
HXLINE(  28)		this->backgroundFill =  ::openfl::display::GraphicsSolidFill_obj::__alloc( HX_CTX ,3552822,1);
HXLINE(  27)		this->titleFill =  ::openfl::display::GraphicsSolidFill_obj::__alloc( HX_CTX ,5066061,1);
HXLINE(  25)		this->h = 100;
HXLINE(  24)		this->w = 288;
HXLINE(  36)		super::__construct();
HXLINE(  38)		this->lineStyle =  ::openfl::display::GraphicsStroke_obj::__alloc( HX_CTX ,1,false,2,0,2,3,this->outlineFill);
HXLINE(  39)		this->graphicsData =  ::openfl::_Vector::ObjectVector_obj::__alloc( HX_CTX ,0,false,::Array_obj< ::Dynamic>::__new(9)->init(0,this->backgroundFill)->init(1,this->path2)->init(2,::util::GraphicsUtil_obj::END_FILL)->init(3,this->titleFill)->init(4,this->path1)->init(5,::util::GraphicsUtil_obj::END_FILL)->init(6,this->lineStyle)->init(7,this->path2)->init(8,::util::GraphicsUtil_obj::END_STROKE),true);
HXLINE(  50)		this->textInputFields = ::Array_obj< ::Dynamic>::__new();
HXLINE(  51)		this->navigationLinks = ::Array_obj< ::Dynamic>::__new();
HXLINE(  52)		this->w = w;
HXLINE(  53)		this->titleText =  ::ui::SimpleText_obj::__alloc( HX_CTX ,12,11776947,false,0,0,null());
HXLINE(  54)		this->titleText->set_text(title);
HXLINE(  55)		this->titleText->updateMetrics();
HXLINE(  56)		 ::ui::SimpleText _hx_tmp = this->titleText;
HXDLIN(  56)		_hx_tmp->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,null(),null(),null(),null(),null(),null(),null(),null())));
HXLINE(  57)		this->titleText->set_x(( (Float)(5) ));
HXLINE(  58)		 ::ui::SimpleText _hx_tmp1 = this->titleText;
HXDLIN(  58)		_hx_tmp1->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,((Float)0.5),12,12,null(),null(),null(),null(),null())));
HXLINE(  59)		this->addChild(this->titleText);
HXLINE(  60)		this->leftButton =  ::ui::ClickableText_obj::__alloc( HX_CTX ,18,true,leftButton);
HXLINE(  61)		if ((leftButton != HX_("",00,00,00,00))) {
HXLINE(  62)			this->leftButton->set_buttonMode(true);
HXLINE(  63)			this->leftButton->set_x(( (Float)(109) ));
HXLINE(  64)			this->addChild(this->leftButton);
            		}
HXLINE(  66)		this->rightButton =  ::ui::ClickableText_obj::__alloc( HX_CTX ,18,true,rightButton);
HXLINE(  67)		this->rightButton->set_buttonMode(true);
HXLINE(  68)		 ::ui::ClickableText _hx_tmp2 = this->rightButton;
HXDLIN(  68)		int _hx_tmp3 = this->w;
HXDLIN(  68)		_hx_tmp2->set_x(((( (Float)(_hx_tmp3) ) - this->rightButton->get_width()) - ( (Float)(26) )));
HXLINE(  69)		this->addChild(this->rightButton);
HXLINE(  70)		this->set_filters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::DropShadowFilter_obj::__alloc( HX_CTX ,0,0,0,((Float)0.5),12,12,null(),null(),null(),null(),null())));
HXLINE(  71)		this->addEventListener(HX_("addedToStage",63,22,55,0c),this->onAddedToStage_dyn(),null(),null(),null());
HXLINE(  72)		this->addEventListener(HX_("removedFromStage",34,21,76,ba),this->onRemovedFromStage_dyn(),null(),null(),null());
            	}

Dynamic Frame_obj::__CreateEmpty() { return new Frame_obj; }

void *Frame_obj::_hx_vtable = 0;

Dynamic Frame_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Frame_obj > _hx_result = new Frame_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool Frame_obj::_hx_isInstanceOf(int inClassId) {
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
			return inClassId==(int)0x3517a2f1 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void Frame_obj::addLabeledField( ::account::view::LabeledField labeledField){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_75_addLabeledField)
HXLINE(  76)		this->addChild(labeledField);
HXLINE(  77)		labeledField->set_y(( (Float)((this->h - 60)) ));
HXLINE(  78)		labeledField->set_x(( (Float)(17) ));
HXLINE(  79)		int _hx_tmp = this->h;
HXDLIN(  79)		this->h = (_hx_tmp + ::Std_obj::_hx_int(( (Float)(labeledField->getHeight()) )));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Frame_obj,addLabeledField,(void))

void Frame_obj::addTextInputField( ::ui::TextInputField textInputField){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_82_addTextInputField)
HXLINE(  83)		this->textInputFields->push(textInputField);
HXLINE(  84)		this->addChild(textInputField);
HXLINE(  85)		textInputField->set_y(( (Float)((this->h - 60)) ));
HXLINE(  86)		textInputField->set_x(( (Float)(17) ));
HXLINE(  87)		this->h = (this->h + 88);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Frame_obj,addTextInputField,(void))

void Frame_obj::addNavigationText( ::ui::ClickableText navigationLink){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_90_addNavigationText)
HXLINE(  91)		this->navigationLinks->push(navigationLink);
HXLINE(  92)		this->addChild(navigationLink);
HXLINE(  93)		navigationLink->set_y(( (Float)((this->h - 66)) ));
HXLINE(  94)		navigationLink->set_x(( (Float)(17) ));
HXLINE(  95)		this->h = (this->h + 20);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Frame_obj,addNavigationText,(void))

void Frame_obj::addComponent( ::openfl::display::DisplayObject component,::hx::Null< int >  __o_offsetX){
            		int offsetX = __o_offsetX.Default(8);
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_98_addComponent)
HXLINE(  99)		this->addChild(component);
HXLINE( 100)		component->set_y(( (Float)((this->h - 66)) ));
HXLINE( 101)		component->set_x(( (Float)(offsetX) ));
HXLINE( 102)		int _hx_tmp = this->h;
HXDLIN( 102)		this->h = ::Std_obj::_hx_int((_hx_tmp + component->get_height()));
            	}


HX_DEFINE_DYNAMIC_FUNC2(Frame_obj,addComponent,(void))

void Frame_obj::addSpace(int space){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_137_addSpace)
HXDLIN( 137)		this->h = (this->h + space);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Frame_obj,addSpace,(void))

void Frame_obj::disable(){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_140_disable)
HXLINE( 141)		this->mouseEnabled = false;
HXLINE( 142)		this->mouseChildren = false;
HXLINE( 143)		{
HXLINE( 143)			int _g = 0;
HXDLIN( 143)			::Array< ::Dynamic> _g1 = this->navigationLinks;
HXDLIN( 143)			while((_g < _g1->length)){
HXLINE( 143)				 ::ui::ClickableText navigationLink = _g1->__get(_g).StaticCast<  ::ui::ClickableText >();
HXDLIN( 143)				_g = (_g + 1);
HXLINE( 144)				navigationLink->setDefaultColor(11776947);
            			}
            		}
HXLINE( 146)		this->leftButton->setDefaultColor(11776947);
HXLINE( 147)		this->rightButton->setDefaultColor(11776947);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Frame_obj,disable,(void))

void Frame_obj::enable(){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_150_enable)
HXLINE( 151)		this->mouseEnabled = true;
HXLINE( 152)		this->mouseChildren = true;
HXLINE( 153)		{
HXLINE( 153)			int _g = 0;
HXDLIN( 153)			::Array< ::Dynamic> _g1 = this->navigationLinks;
HXDLIN( 153)			while((_g < _g1->length)){
HXLINE( 153)				 ::ui::ClickableText navigationLink = _g1->__get(_g).StaticCast<  ::ui::ClickableText >();
HXDLIN( 153)				_g = (_g + 1);
HXLINE( 154)				navigationLink->setDefaultColor(16777215);
            			}
            		}
HXLINE( 156)		this->leftButton->setDefaultColor(16777215);
HXLINE( 157)		this->rightButton->setDefaultColor(16777215);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Frame_obj,enable,(void))

void Frame_obj::draw(){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_160_draw)
HXLINE( 161)		this->get_graphics()->clear();
HXLINE( 162)		::util::GraphicsUtil_obj::clearPath(this->path1);
HXLINE( 163)		::util::GraphicsUtil_obj::drawCutEdgeRect(-6,-6,this->w,32,4,::Array_obj< int >::fromData( _hx_array_data_30775e73_11,4),this->path1);
HXLINE( 164)		::util::GraphicsUtil_obj::clearPath(this->path2);
HXLINE( 165)		::util::GraphicsUtil_obj::drawCutEdgeRect(-6,-6,this->w,this->h,4,::Array_obj< int >::fromData( _hx_array_data_30775e73_12,4),this->path2);
HXLINE( 166)		this->leftButton->set_y(( (Float)((this->h - 52)) ));
HXLINE( 167)		this->rightButton->set_y(( (Float)((this->h - 52)) ));
HXLINE( 168)		this->get_graphics()->drawGraphicsData(this->graphicsData);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Frame_obj,draw,(void))

void Frame_obj::onAddedToStage( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_171_onAddedToStage)
HXLINE( 172)		this->draw();
HXLINE( 173)		this->set_x(((( (Float)(this->stage->stageWidth) ) / ( (Float)(2) )) - (( (Float)((this->w - 6)) ) / ( (Float)(2) ))));
HXLINE( 174)		Float _hx_tmp = (( (Float)(this->stage->stageHeight) ) / ( (Float)(2) ));
HXDLIN( 174)		this->set_y((_hx_tmp - (this->get_height() / ( (Float)(2) ))));
HXLINE( 175)		if ((this->textInputFields->length > 0)) {
HXLINE( 176)			this->stage->set_focus(this->textInputFields->__get(0).StaticCast<  ::ui::TextInputField >()->inputText);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Frame_obj,onAddedToStage,(void))

void Frame_obj::onRemovedFromStage( ::openfl::events::Event event){
            	HX_STACKFRAME(&_hx_pos_e90d7f3a74fa6ab3_179_onRemovedFromStage)
            	}


HX_DEFINE_DYNAMIC_FUNC1(Frame_obj,onRemovedFromStage,(void))


::hx::ObjectPtr< Frame_obj > Frame_obj::__new(::String title,::String leftButton,::String rightButton,::hx::Null< int >  __o_w) {
	::hx::ObjectPtr< Frame_obj > __this = new Frame_obj();
	__this->__construct(title,leftButton,rightButton,__o_w);
	return __this;
}

::hx::ObjectPtr< Frame_obj > Frame_obj::__alloc(::hx::Ctx *_hx_ctx,::String title,::String leftButton,::String rightButton,::hx::Null< int >  __o_w) {
	Frame_obj *__this = (Frame_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Frame_obj), true, "ui.Frame"));
	*(void **)__this = Frame_obj::_hx_vtable;
	__this->__construct(title,leftButton,rightButton,__o_w);
	return __this;
}

Frame_obj::Frame_obj()
{
}

void Frame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Frame);
	HX_MARK_MEMBER_NAME(titleText,"titleText");
	HX_MARK_MEMBER_NAME(leftButton,"leftButton");
	HX_MARK_MEMBER_NAME(rightButton,"rightButton");
	HX_MARK_MEMBER_NAME(textInputFields,"textInputFields");
	HX_MARK_MEMBER_NAME(navigationLinks,"navigationLinks");
	HX_MARK_MEMBER_NAME(w,"w");
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_MEMBER_NAME(titleFill,"titleFill");
	HX_MARK_MEMBER_NAME(backgroundFill,"backgroundFill");
	HX_MARK_MEMBER_NAME(outlineFill,"outlineFill");
	HX_MARK_MEMBER_NAME(lineStyle,"lineStyle");
	HX_MARK_MEMBER_NAME(path1,"path1");
	HX_MARK_MEMBER_NAME(path2,"path2");
	HX_MARK_MEMBER_NAME(graphicsData,"graphicsData");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Frame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(titleText,"titleText");
	HX_VISIT_MEMBER_NAME(leftButton,"leftButton");
	HX_VISIT_MEMBER_NAME(rightButton,"rightButton");
	HX_VISIT_MEMBER_NAME(textInputFields,"textInputFields");
	HX_VISIT_MEMBER_NAME(navigationLinks,"navigationLinks");
	HX_VISIT_MEMBER_NAME(w,"w");
	HX_VISIT_MEMBER_NAME(h,"h");
	HX_VISIT_MEMBER_NAME(titleFill,"titleFill");
	HX_VISIT_MEMBER_NAME(backgroundFill,"backgroundFill");
	HX_VISIT_MEMBER_NAME(outlineFill,"outlineFill");
	HX_VISIT_MEMBER_NAME(lineStyle,"lineStyle");
	HX_VISIT_MEMBER_NAME(path1,"path1");
	HX_VISIT_MEMBER_NAME(path2,"path2");
	HX_VISIT_MEMBER_NAME(graphicsData,"graphicsData");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Frame_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { return ::hx::Val( w ); }
		if (HX_FIELD_EQ(inName,"h") ) { return ::hx::Val( h ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return ::hx::Val( draw_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"path1") ) { return ::hx::Val( path1 ); }
		if (HX_FIELD_EQ(inName,"path2") ) { return ::hx::Val( path2 ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"enable") ) { return ::hx::Val( enable_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"disable") ) { return ::hx::Val( disable_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addSpace") ) { return ::hx::Val( addSpace_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { return ::hx::Val( titleText ); }
		if (HX_FIELD_EQ(inName,"titleFill") ) { return ::hx::Val( titleFill ); }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return ::hx::Val( lineStyle ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"leftButton") ) { return ::hx::Val( leftButton ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rightButton") ) { return ::hx::Val( rightButton ); }
		if (HX_FIELD_EQ(inName,"outlineFill") ) { return ::hx::Val( outlineFill ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"graphicsData") ) { return ::hx::Val( graphicsData ); }
		if (HX_FIELD_EQ(inName,"addComponent") ) { return ::hx::Val( addComponent_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"backgroundFill") ) { return ::hx::Val( backgroundFill ); }
		if (HX_FIELD_EQ(inName,"onAddedToStage") ) { return ::hx::Val( onAddedToStage_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"textInputFields") ) { return ::hx::Val( textInputFields ); }
		if (HX_FIELD_EQ(inName,"navigationLinks") ) { return ::hx::Val( navigationLinks ); }
		if (HX_FIELD_EQ(inName,"addLabeledField") ) { return ::hx::Val( addLabeledField_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"addTextInputField") ) { return ::hx::Val( addTextInputField_dyn() ); }
		if (HX_FIELD_EQ(inName,"addNavigationText") ) { return ::hx::Val( addNavigationText_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onRemovedFromStage") ) { return ::hx::Val( onRemovedFromStage_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Frame_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"path1") ) { path1=inValue.Cast<  ::openfl::display::GraphicsPath >(); return inValue; }
		if (HX_FIELD_EQ(inName,"path2") ) { path2=inValue.Cast<  ::openfl::display::GraphicsPath >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"titleText") ) { titleText=inValue.Cast<  ::ui::SimpleText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"titleFill") ) { titleFill=inValue.Cast<  ::openfl::display::GraphicsSolidFill >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { lineStyle=inValue.Cast<  ::openfl::display::GraphicsStroke >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"leftButton") ) { leftButton=inValue.Cast<  ::ui::ClickableText >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rightButton") ) { rightButton=inValue.Cast<  ::ui::ClickableText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineFill") ) { outlineFill=inValue.Cast<  ::openfl::display::GraphicsSolidFill >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"graphicsData") ) { graphicsData=inValue.Cast<  ::openfl::_Vector::ObjectVector >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"backgroundFill") ) { backgroundFill=inValue.Cast<  ::openfl::display::GraphicsSolidFill >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"textInputFields") ) { textInputFields=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"navigationLinks") ) { navigationLinks=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Frame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("titleText",65,ba,a4,70));
	outFields->push(HX_("leftButton",59,1d,f1,08));
	outFields->push(HX_("rightButton",ee,2e,65,43));
	outFields->push(HX_("textInputFields",76,ca,53,27));
	outFields->push(HX_("navigationLinks",05,83,11,b2));
	outFields->push(HX_("w",77,00,00,00));
	outFields->push(HX_("h",68,00,00,00));
	outFields->push(HX_("titleFill",3b,bc,66,67));
	outFields->push(HX_("backgroundFill",91,1d,d6,17));
	outFields->push(HX_("outlineFill",25,fb,c1,d8));
	outFields->push(HX_("lineStyle",9d,a8,18,cb));
	outFields->push(HX_("path1",ec,0a,57,bd));
	outFields->push(HX_("path2",ed,0a,57,bd));
	outFields->push(HX_("graphicsData",95,3c,58,41));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Frame_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ui::SimpleText */ ,(int)offsetof(Frame_obj,titleText),HX_("titleText",65,ba,a4,70)},
	{::hx::fsObject /*  ::ui::ClickableText */ ,(int)offsetof(Frame_obj,leftButton),HX_("leftButton",59,1d,f1,08)},
	{::hx::fsObject /*  ::ui::ClickableText */ ,(int)offsetof(Frame_obj,rightButton),HX_("rightButton",ee,2e,65,43)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Frame_obj,textInputFields),HX_("textInputFields",76,ca,53,27)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Frame_obj,navigationLinks),HX_("navigationLinks",05,83,11,b2)},
	{::hx::fsInt,(int)offsetof(Frame_obj,w),HX_("w",77,00,00,00)},
	{::hx::fsInt,(int)offsetof(Frame_obj,h),HX_("h",68,00,00,00)},
	{::hx::fsObject /*  ::openfl::display::GraphicsSolidFill */ ,(int)offsetof(Frame_obj,titleFill),HX_("titleFill",3b,bc,66,67)},
	{::hx::fsObject /*  ::openfl::display::GraphicsSolidFill */ ,(int)offsetof(Frame_obj,backgroundFill),HX_("backgroundFill",91,1d,d6,17)},
	{::hx::fsObject /*  ::openfl::display::GraphicsSolidFill */ ,(int)offsetof(Frame_obj,outlineFill),HX_("outlineFill",25,fb,c1,d8)},
	{::hx::fsObject /*  ::openfl::display::GraphicsStroke */ ,(int)offsetof(Frame_obj,lineStyle),HX_("lineStyle",9d,a8,18,cb)},
	{::hx::fsObject /*  ::openfl::display::GraphicsPath */ ,(int)offsetof(Frame_obj,path1),HX_("path1",ec,0a,57,bd)},
	{::hx::fsObject /*  ::openfl::display::GraphicsPath */ ,(int)offsetof(Frame_obj,path2),HX_("path2",ed,0a,57,bd)},
	{::hx::fsObject /*  ::openfl::_Vector::ObjectVector */ ,(int)offsetof(Frame_obj,graphicsData),HX_("graphicsData",95,3c,58,41)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Frame_obj_sStaticStorageInfo = 0;
#endif

static ::String Frame_obj_sMemberFields[] = {
	HX_("titleText",65,ba,a4,70),
	HX_("leftButton",59,1d,f1,08),
	HX_("rightButton",ee,2e,65,43),
	HX_("textInputFields",76,ca,53,27),
	HX_("navigationLinks",05,83,11,b2),
	HX_("w",77,00,00,00),
	HX_("h",68,00,00,00),
	HX_("titleFill",3b,bc,66,67),
	HX_("backgroundFill",91,1d,d6,17),
	HX_("outlineFill",25,fb,c1,d8),
	HX_("lineStyle",9d,a8,18,cb),
	HX_("path1",ec,0a,57,bd),
	HX_("path2",ed,0a,57,bd),
	HX_("graphicsData",95,3c,58,41),
	HX_("addLabeledField",28,b8,c9,05),
	HX_("addTextInputField",5e,45,51,b1),
	HX_("addNavigationText",62,c8,ce,bb),
	HX_("addComponent",5c,12,a8,0e),
	HX_("addSpace",e5,b2,c3,fa),
	HX_("disable",e8,69,58,b1),
	HX_("enable",83,ae,87,f8),
	HX_("draw",04,2c,70,42),
	HX_("onAddedToStage",22,82,44,36),
	HX_("onRemovedFromStage",73,cc,89,12),
	::String(null()) };

::hx::Class Frame_obj::__mClass;

void Frame_obj::__register()
{
	Frame_obj _hx_dummy;
	Frame_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.Frame",73,5e,77,30);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Frame_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Frame_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Frame_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Frame_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
