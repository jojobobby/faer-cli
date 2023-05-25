// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_lib_ui_api_Layout
#include <lib/ui/api/Layout.h>
#endif
#ifndef INCLUDED_lib_ui_api_Size
#include <lib/ui/api/Size.h>
#endif
#ifndef INCLUDED_lib_ui_impl_LayoutList
#include <lib/ui/impl/LayoutList.h>
#endif
#ifndef INCLUDED_lib_ui_impl_NullLayout
#include <lib/ui/impl/NullLayout.h>
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
#ifndef INCLUDED_openfl_display_Shape
#include <openfl/display/Shape.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif
#ifndef INCLUDED_util_EmptySignal
#include <util/EmptySignal.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_12_new,"lib.ui.impl.LayoutList","new",0x972d97f7,"lib.ui.impl.LayoutList.new","lib/ui/impl/LayoutList.hx",12,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_39_setLayout,"lib.ui.impl.LayoutList","setLayout",0x2e7236c3,"lib.ui.impl.LayoutList.setLayout","lib/ui/impl/LayoutList.hx",39,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_45_getSize,"lib.ui.impl.LayoutList","getSize",0x45212f8e,"lib.ui.impl.LayoutList.getSize","lib/ui/impl/LayoutList.hx",45,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_48_setSize,"lib.ui.impl.LayoutList","setSize",0x3822c09a,"lib.ui.impl.LayoutList.setSize","lib/ui/impl/LayoutList.hx",48,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_53_getSizeOfItems,"lib.ui.impl.LayoutList","getSizeOfItems",0x00ae8d7b,"lib.ui.impl.LayoutList.getSizeOfItems","lib/ui/impl/LayoutList.hx",53,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_68_setItems,"lib.ui.impl.LayoutList","setItems",0x2b796a07,"lib.ui.impl.LayoutList.setItems","lib/ui/impl/LayoutList.hx",68,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_80_setOffset,"lib.ui.impl.LayoutList","setOffset",0x35f91fac,"lib.ui.impl.LayoutList.setOffset","lib/ui/impl/LayoutList.hx",80,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_90_updateLayout,"lib.ui.impl.LayoutList","updateLayout",0xed9e631c,"lib.ui.impl.LayoutList.updateLayout","lib/ui/impl/LayoutList.hx",90,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_93_applySizeToMask,"lib.ui.impl.LayoutList","applySizeToMask",0xc18774cd,"lib.ui.impl.LayoutList.applySizeToMask","lib/ui/impl/LayoutList.hx",93,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_102_clearList,"lib.ui.impl.LayoutList","clearList",0x31861762,"lib.ui.impl.LayoutList.clearList","lib/ui/impl/LayoutList.hx",102,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_112_addItemsToListAndContainer,"lib.ui.impl.LayoutList","addItemsToListAndContainer",0x5be5a1cb,"lib.ui.impl.LayoutList.addItemsToListAndContainer","lib/ui/impl/LayoutList.hx",112,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_116_addToListAndContainer,"lib.ui.impl.LayoutList","addToListAndContainer",0xdd8f185b,"lib.ui.impl.LayoutList.addToListAndContainer","lib/ui/impl/LayoutList.hx",116,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_13_boot,"lib.ui.impl.LayoutList","boot",0xa8d060bb,"lib.ui.impl.LayoutList.boot","lib/ui/impl/LayoutList.hx",13,0xceb88558)
HX_LOCAL_STACK_FRAME(_hx_pos_6bb4e3b0206ed3ce_14_boot,"lib.ui.impl.LayoutList","boot",0xa8d060bb,"lib.ui.impl.LayoutList.boot","lib/ui/impl/LayoutList.hx",14,0xceb88558)
namespace lib{
namespace ui{
namespace impl{

void LayoutList_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_12_new)
HXLINE(  24)		this->offset = 0;
HXLINE(  20)		this->containerMask =  ::openfl::display::Shape_obj::__alloc( HX_CTX );
HXLINE(  19)		this->container =  ::openfl::display::Sprite_obj::__alloc( HX_CTX );
HXLINE(  18)		this->list = ::Array_obj< ::Dynamic>::__new();
HXLINE(  16)		this->itemsChanged =  ::util::EmptySignal_obj::__alloc( HX_CTX );
HXLINE(  27)		super::__construct();
HXLINE(  29)		this->layout = ::lib::ui::impl::LayoutList_obj::NULL_LAYOUT;
HXLINE(  30)		this->size = ::lib::ui::impl::LayoutList_obj::ZERO_SIZE;
HXLINE(  31)		this->addChild(this->container);
HXLINE(  32)		this->addChild(this->containerMask);
            	}

Dynamic LayoutList_obj::__CreateEmpty() { return new LayoutList_obj; }

void *LayoutList_obj::_hx_vtable = 0;

Dynamic LayoutList_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< LayoutList_obj > _hx_result = new LayoutList_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool LayoutList_obj::_hx_isInstanceOf(int inClassId) {
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
		if (inClassId<=(int)0x66978f39) {
			return inClassId==(int)0x4af7dd8e || inClassId==(int)0x66978f39;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void LayoutList_obj::setLayout(::Dynamic layout){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_39_setLayout)
HXLINE(  40)		::Dynamic _hx_tmp;
HXDLIN(  40)		if (::hx::IsNotNull( layout )) {
HXLINE(  40)			_hx_tmp = layout;
            		}
            		else {
HXLINE(  40)			_hx_tmp = ::lib::ui::impl::LayoutList_obj::NULL_LAYOUT;
            		}
HXDLIN(  40)		this->layout = _hx_tmp;
HXLINE(  41)		::lib::ui::api::Layout_obj::layout(layout,this->list,-(this->offset));
            	}


HX_DEFINE_DYNAMIC_FUNC1(LayoutList_obj,setLayout,(void))

 ::lib::ui::api::Size LayoutList_obj::getSize(){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_45_getSize)
HXDLIN(  45)		return this->size;
            	}


HX_DEFINE_DYNAMIC_FUNC0(LayoutList_obj,getSize,return )

void LayoutList_obj::setSize( ::lib::ui::api::Size size){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_48_setSize)
HXLINE(  49)		 ::lib::ui::api::Size _hx_tmp;
HXDLIN(  49)		if (::hx::IsNotNull( size )) {
HXLINE(  49)			_hx_tmp = size;
            		}
            		else {
HXLINE(  49)			_hx_tmp = ::lib::ui::impl::LayoutList_obj::ZERO_SIZE;
            		}
HXDLIN(  49)		this->size = _hx_tmp;
HXLINE(  50)		this->applySizeToMask();
            	}


HX_DEFINE_DYNAMIC_FUNC1(LayoutList_obj,setSize,(void))

 ::lib::ui::api::Size LayoutList_obj::getSizeOfItems(){
            	HX_GC_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_53_getSizeOfItems)
HXLINE(  54)		 ::openfl::geom::Rectangle rect = this->container->getRect(this->container);
HXLINE(  55)		int _hx_tmp = ::Std_obj::_hx_int(rect->width);
HXDLIN(  55)		return  ::lib::ui::api::Size_obj::__alloc( HX_CTX ,_hx_tmp,::Std_obj::_hx_int(rect->height));
            	}


HX_DEFINE_DYNAMIC_FUNC0(LayoutList_obj,getSizeOfItems,return )

void LayoutList_obj::setItems(::Array< ::Dynamic> items){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_68_setItems)
HXLINE(  69)		this->clearList();
HXLINE(  70)		this->addItemsToListAndContainer(items);
HXLINE(  71)		this->offset = 0;
HXLINE(  72)		this->updateLayout();
HXLINE(  73)		this->itemsChanged->emit();
            	}


HX_DEFINE_DYNAMIC_FUNC1(LayoutList_obj,setItems,(void))

void LayoutList_obj::setOffset(int value){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_80_setOffset)
HXLINE(  81)		this->offset = value;
HXLINE(  82)		this->updateLayout();
            	}


HX_DEFINE_DYNAMIC_FUNC1(LayoutList_obj,setOffset,(void))

void LayoutList_obj::updateLayout(){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_90_updateLayout)
HXDLIN(  90)		::lib::ui::api::Layout_obj::layout(this->layout,this->list,-(this->offset));
            	}


HX_DEFINE_DYNAMIC_FUNC0(LayoutList_obj,updateLayout,(void))

void LayoutList_obj::applySizeToMask(){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_93_applySizeToMask)
HXLINE(  94)		 ::openfl::display::Graphics g = this->containerMask->get_graphics();
HXLINE(  95)		g->clear();
HXLINE(  96)		g->beginFill(10027263,null());
HXLINE(  97)		g->drawRect(( (Float)(0) ),( (Float)(0) ),( (Float)(this->size->width) ),( (Float)(this->size->height) ));
HXLINE(  98)		g->endFill();
HXLINE(  99)		this->container->set_mask(this->containerMask);
            	}


HX_DEFINE_DYNAMIC_FUNC0(LayoutList_obj,applySizeToMask,(void))

void LayoutList_obj::clearList(){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_102_clearList)
HXLINE( 103)		int i = this->list->length;
HXLINE( 104)		while(true){
HXLINE( 104)			i = (i - 1);
HXDLIN( 104)			if (!(((i + 1) > 0))) {
HXLINE( 104)				goto _hx_goto_9;
            			}
HXLINE( 105)			this->container->removeChild(this->list->__get(i).StaticCast<  ::openfl::display::DisplayObject >());
            		}
            		_hx_goto_9:;
HXLINE( 107)		this->list->removeRange(0,this->list->length);
            	}


HX_DEFINE_DYNAMIC_FUNC0(LayoutList_obj,clearList,(void))

void LayoutList_obj::addItemsToListAndContainer(::Array< ::Dynamic> items){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_112_addItemsToListAndContainer)
HXDLIN( 112)		int _g = 0;
HXDLIN( 112)		while((_g < items->length)){
HXDLIN( 112)			 ::openfl::display::DisplayObject item = items->__get(_g).StaticCast<  ::openfl::display::DisplayObject >();
HXDLIN( 112)			_g = (_g + 1);
HXLINE( 113)			this->addToListAndContainer(item);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(LayoutList_obj,addItemsToListAndContainer,(void))

void LayoutList_obj::addToListAndContainer( ::openfl::display::DisplayObject item){
            	HX_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_116_addToListAndContainer)
HXLINE( 117)		this->list->push(item);
HXLINE( 118)		this->container->addChild(item);
            	}


HX_DEFINE_DYNAMIC_FUNC1(LayoutList_obj,addToListAndContainer,(void))

 ::lib::ui::impl::NullLayout LayoutList_obj::NULL_LAYOUT;

 ::lib::ui::api::Size LayoutList_obj::ZERO_SIZE;


::hx::ObjectPtr< LayoutList_obj > LayoutList_obj::__new() {
	::hx::ObjectPtr< LayoutList_obj > __this = new LayoutList_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< LayoutList_obj > LayoutList_obj::__alloc(::hx::Ctx *_hx_ctx) {
	LayoutList_obj *__this = (LayoutList_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(LayoutList_obj), true, "lib.ui.impl.LayoutList"));
	*(void **)__this = LayoutList_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

LayoutList_obj::LayoutList_obj()
{
}

void LayoutList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LayoutList);
	HX_MARK_MEMBER_NAME(itemsChanged,"itemsChanged");
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_MEMBER_NAME(container,"container");
	HX_MARK_MEMBER_NAME(containerMask,"containerMask");
	HX_MARK_MEMBER_NAME(layout,"layout");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(offset,"offset");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LayoutList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(itemsChanged,"itemsChanged");
	HX_VISIT_MEMBER_NAME(list,"list");
	HX_VISIT_MEMBER_NAME(container,"container");
	HX_VISIT_MEMBER_NAME(containerMask,"containerMask");
	HX_VISIT_MEMBER_NAME(layout,"layout");
	HX_VISIT_MEMBER_NAME(size,"size");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val LayoutList_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return ::hx::Val( list ); }
		if (HX_FIELD_EQ(inName,"size") ) { return ::hx::Val( size ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { return ::hx::Val( layout ); }
		if (HX_FIELD_EQ(inName,"offset") ) { return ::hx::Val( offset ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getSize") ) { return ::hx::Val( getSize_dyn() ); }
		if (HX_FIELD_EQ(inName,"setSize") ) { return ::hx::Val( setSize_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setItems") ) { return ::hx::Val( setItems_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { return ::hx::Val( container ); }
		if (HX_FIELD_EQ(inName,"setLayout") ) { return ::hx::Val( setLayout_dyn() ); }
		if (HX_FIELD_EQ(inName,"setOffset") ) { return ::hx::Val( setOffset_dyn() ); }
		if (HX_FIELD_EQ(inName,"clearList") ) { return ::hx::Val( clearList_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"itemsChanged") ) { return ::hx::Val( itemsChanged ); }
		if (HX_FIELD_EQ(inName,"updateLayout") ) { return ::hx::Val( updateLayout_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"containerMask") ) { return ::hx::Val( containerMask ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getSizeOfItems") ) { return ::hx::Val( getSizeOfItems_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"applySizeToMask") ) { return ::hx::Val( applySizeToMask_dyn() ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"addToListAndContainer") ) { return ::hx::Val( addToListAndContainer_dyn() ); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"addItemsToListAndContainer") ) { return ::hx::Val( addItemsToListAndContainer_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool LayoutList_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"ZERO_SIZE") ) { outValue = ( ZERO_SIZE ); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"NULL_LAYOUT") ) { outValue = ( NULL_LAYOUT ); return true; }
	}
	return false;
}

::hx::Val LayoutList_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast<  ::lib::ui::api::Size >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { layout=inValue.Cast< ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { container=inValue.Cast<  ::openfl::display::Sprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"itemsChanged") ) { itemsChanged=inValue.Cast<  ::util::EmptySignal >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"containerMask") ) { containerMask=inValue.Cast<  ::openfl::display::Shape >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool LayoutList_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"ZERO_SIZE") ) { ZERO_SIZE=ioValue.Cast<  ::lib::ui::api::Size >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"NULL_LAYOUT") ) { NULL_LAYOUT=ioValue.Cast<  ::lib::ui::impl::NullLayout >(); return true; }
	}
	return false;
}

void LayoutList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("itemsChanged",d4,ac,3e,56));
	outFields->push(HX_("list",5e,1c,b3,47));
	outFields->push(HX_("container",41,75,73,bf));
	outFields->push(HX_("containerMask",cd,16,0d,77));
	outFields->push(HX_("layout",aa,ae,b8,58));
	outFields->push(HX_("size",c1,a0,53,4c));
	outFields->push(HX_("offset",93,97,3f,60));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo LayoutList_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::util::EmptySignal */ ,(int)offsetof(LayoutList_obj,itemsChanged),HX_("itemsChanged",d4,ac,3e,56)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(LayoutList_obj,list),HX_("list",5e,1c,b3,47)},
	{::hx::fsObject /*  ::openfl::display::Sprite */ ,(int)offsetof(LayoutList_obj,container),HX_("container",41,75,73,bf)},
	{::hx::fsObject /*  ::openfl::display::Shape */ ,(int)offsetof(LayoutList_obj,containerMask),HX_("containerMask",cd,16,0d,77)},
	{::hx::fsObject /* ::Dynamic */ ,(int)offsetof(LayoutList_obj,layout),HX_("layout",aa,ae,b8,58)},
	{::hx::fsObject /*  ::lib::ui::api::Size */ ,(int)offsetof(LayoutList_obj,size),HX_("size",c1,a0,53,4c)},
	{::hx::fsInt,(int)offsetof(LayoutList_obj,offset),HX_("offset",93,97,3f,60)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo LayoutList_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::lib::ui::impl::NullLayout */ ,(void *) &LayoutList_obj::NULL_LAYOUT,HX_("NULL_LAYOUT",a2,f4,d5,30)},
	{::hx::fsObject /*  ::lib::ui::api::Size */ ,(void *) &LayoutList_obj::ZERO_SIZE,HX_("ZERO_SIZE",78,bc,ae,65)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String LayoutList_obj_sMemberFields[] = {
	HX_("itemsChanged",d4,ac,3e,56),
	HX_("list",5e,1c,b3,47),
	HX_("container",41,75,73,bf),
	HX_("containerMask",cd,16,0d,77),
	HX_("layout",aa,ae,b8,58),
	HX_("size",c1,a0,53,4c),
	HX_("offset",93,97,3f,60),
	HX_("setLayout",ec,23,60,b8),
	HX_("getSize",77,50,d6,1e),
	HX_("setSize",83,e1,d7,11),
	HX_("getSizeOfItems",b2,4b,c7,54),
	HX_("setItems",fe,14,41,d0),
	HX_("setOffset",d5,0c,e7,bf),
	HX_("updateLayout",93,55,7c,58),
	HX_("applySizeToMask",b6,26,15,03),
	HX_("clearList",8b,04,74,bb),
	HX_("addItemsToListAndContainer",82,56,7e,4d),
	HX_("addToListAndContainer",04,9f,00,77),
	::String(null()) };

static void LayoutList_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LayoutList_obj::NULL_LAYOUT,"NULL_LAYOUT");
	HX_MARK_MEMBER_NAME(LayoutList_obj::ZERO_SIZE,"ZERO_SIZE");
};

#ifdef HXCPP_VISIT_ALLOCS
static void LayoutList_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LayoutList_obj::NULL_LAYOUT,"NULL_LAYOUT");
	HX_VISIT_MEMBER_NAME(LayoutList_obj::ZERO_SIZE,"ZERO_SIZE");
};

#endif

::hx::Class LayoutList_obj::__mClass;

static ::String LayoutList_obj_sStaticFields[] = {
	HX_("NULL_LAYOUT",a2,f4,d5,30),
	HX_("ZERO_SIZE",78,bc,ae,65),
	::String(null())
};

void LayoutList_obj::__register()
{
	LayoutList_obj _hx_dummy;
	LayoutList_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lib.ui.impl.LayoutList",85,d0,7e,74);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &LayoutList_obj::__GetStatic;
	__mClass->mSetStaticField = &LayoutList_obj::__SetStatic;
	__mClass->mMarkFunc = LayoutList_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(LayoutList_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(LayoutList_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< LayoutList_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = LayoutList_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = LayoutList_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = LayoutList_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void LayoutList_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_13_boot)
HXDLIN(  13)		NULL_LAYOUT =  ::lib::ui::impl::NullLayout_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_6bb4e3b0206ed3ce_14_boot)
HXDLIN(  14)		ZERO_SIZE =  ::lib::ui::api::Size_obj::__alloc( HX_CTX ,0,0);
            	}
}

} // end namespace lib
} // end namespace ui
} // end namespace impl
