// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_objects_GameObject
#include <objects/GameObject.h>
#endif
#ifndef INCLUDED_objects_Player
#include <objects/Player.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
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
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_ui_panels_Panel
#include <ui/panels/Panel.h>
#endif
#ifndef INCLUDED_ui_panels_itemgrids_InventoryGrid
#include <ui/panels/itemgrids/InventoryGrid.h>
#endif
#ifndef INCLUDED_ui_panels_itemgrids_ItemGrid
#include <ui/panels/itemgrids/ItemGrid.h>
#endif
#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_InteractiveItemTile
#include <ui/panels/itemgrids/itemtiles/InteractiveItemTile.h>
#endif
#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_InventoryTile
#include <ui/panels/itemgrids/itemtiles/InventoryTile.h>
#endif
#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_ItemTile
#include <ui/panels/itemgrids/itemtiles/ItemTile.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_c09d712257901bdb_8_new,"ui.panels.itemgrids.InventoryGrid","new",0xeec6aebb,"ui.panels.itemgrids.InventoryGrid.new","ui/panels/itemgrids/InventoryGrid.hx",8,0x23ab2d36)
HX_LOCAL_STACK_FRAME(_hx_pos_c09d712257901bdb_26_setItems,"ui.panels.itemgrids.InventoryGrid","setItems",0xe1234cc3,"ui.panels.itemgrids.InventoryGrid.setItems","ui/panels/itemgrids/InventoryGrid.hx",26,0x23ab2d36)
namespace ui{
namespace panels{
namespace itemgrids{

void InventoryGrid_obj::__construct( ::objects::GameObject gridOwner, ::objects::Player currentPlayer,::hx::Null< int >  __o_itemIndexOffset,::hx::Null< bool >  __o_isBackpack,::hx::Null< bool >  __o_disableBgDraw){
            		int itemIndexOffset = __o_itemIndexOffset.Default(0);
            		bool isBackpack = __o_isBackpack.Default(false);
            		bool disableBgDraw = __o_disableBgDraw.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_c09d712257901bdb_8_new)
HXLINE(  12)		this->isBackpack = false;
HXLINE(  15)		 ::ui::panels::itemgrids::itemtiles::InventoryTile tile = null();
HXLINE(  16)		super::__construct(gridOwner,currentPlayer,itemIndexOffset,disableBgDraw);
HXLINE(  17)		this->tiles = ::Array_obj< ::Dynamic>::__new();
HXLINE(  18)		this->isBackpack = isBackpack;
HXLINE(  19)		{
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,this->indexOffset,::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,0);
HXLINE(  22)				this->tiles[0] = tile;
            			}
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,(1 + this->indexOffset),::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,1);
HXLINE(  22)				this->tiles[1] = tile;
            			}
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,(2 + this->indexOffset),::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,2);
HXLINE(  22)				this->tiles[2] = tile;
            			}
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,(3 + this->indexOffset),::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,3);
HXLINE(  22)				this->tiles[3] = tile;
            			}
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,(4 + this->indexOffset),::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,4);
HXLINE(  22)				this->tiles[4] = tile;
            			}
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,(5 + this->indexOffset),::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,5);
HXLINE(  22)				this->tiles[5] = tile;
            			}
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,(6 + this->indexOffset),::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,6);
HXLINE(  22)				this->tiles[6] = tile;
            			}
HXLINE(  19)			{
HXLINE(  20)				tile =  ::ui::panels::itemgrids::itemtiles::InventoryTile_obj::__alloc( HX_CTX ,(7 + this->indexOffset),::hx::ObjectPtr<OBJ_>(this),this->interactive);
HXLINE(  21)				this->addToGrid(tile,1,7);
HXLINE(  22)				this->tiles[7] = tile;
            			}
            		}
            	}

Dynamic InventoryGrid_obj::__CreateEmpty() { return new InventoryGrid_obj; }

void *InventoryGrid_obj::_hx_vtable = 0;

Dynamic InventoryGrid_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< InventoryGrid_obj > _hx_result = new InventoryGrid_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return _hx_result;
}

bool InventoryGrid_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1f4df417) {
		if (inClassId<=(int)0x0bf625e0) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0bf625e0;
			}
		} else {
			return inClassId==(int)0x0c89e854 || inClassId==(int)0x1f4df417;
		}
	} else {
		if (inClassId<=(int)0x6b353933) {
			if (inClassId<=(int)0x4af7dd8e) {
				return inClassId==(int)0x414162f3 || inClassId==(int)0x4af7dd8e;
			} else {
				return inClassId==(int)0x6b353933;
			}
		} else {
			return inClassId==(int)0x7fae8619;
		}
	}
}

void InventoryGrid_obj::setItems(::Array< int > items,::hx::Null< int >  __o_itemIndexOffset){
            		int itemIndexOffset = __o_itemIndexOffset.Default(0);
            	HX_STACKFRAME(&_hx_pos_c09d712257901bdb_26_setItems)
HXLINE(  27)		int numItems = 0;
HXLINE(  28)		if (::hx::IsNotNull( items )) {
HXLINE(  29)			numItems = items->length;
HXLINE(  30)			{
HXLINE(  31)				if ((this->indexOffset < numItems)) {
HXLINE(  32)					this->tiles->__get(0).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get(this->indexOffset));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(0).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
HXLINE(  31)				if (((1 + this->indexOffset) < numItems)) {
HXLINE(  32)					this->tiles->__get(1).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get((1 + this->indexOffset)));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(1).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
HXLINE(  31)				if (((2 + this->indexOffset) < numItems)) {
HXLINE(  32)					this->tiles->__get(2).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get((2 + this->indexOffset)));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(2).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
HXLINE(  31)				if (((3 + this->indexOffset) < numItems)) {
HXLINE(  32)					this->tiles->__get(3).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get((3 + this->indexOffset)));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(3).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
HXLINE(  31)				if (((4 + this->indexOffset) < numItems)) {
HXLINE(  32)					this->tiles->__get(4).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get((4 + this->indexOffset)));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(4).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
HXLINE(  31)				if (((5 + this->indexOffset) < numItems)) {
HXLINE(  32)					this->tiles->__get(5).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get((5 + this->indexOffset)));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(5).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
HXLINE(  31)				if (((6 + this->indexOffset) < numItems)) {
HXLINE(  32)					this->tiles->__get(6).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get((6 + this->indexOffset)));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(6).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
HXLINE(  31)				if (((7 + this->indexOffset) < numItems)) {
HXLINE(  32)					this->tiles->__get(7).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(items->__get((7 + this->indexOffset)));
            				}
            				else {
HXLINE(  34)					this->tiles->__get(7).StaticCast<  ::ui::panels::itemgrids::itemtiles::InventoryTile >()->setItem(-1);
            				}
            			}
            		}
            	}



::hx::ObjectPtr< InventoryGrid_obj > InventoryGrid_obj::__new( ::objects::GameObject gridOwner, ::objects::Player currentPlayer,::hx::Null< int >  __o_itemIndexOffset,::hx::Null< bool >  __o_isBackpack,::hx::Null< bool >  __o_disableBgDraw) {
	::hx::ObjectPtr< InventoryGrid_obj > __this = new InventoryGrid_obj();
	__this->__construct(gridOwner,currentPlayer,__o_itemIndexOffset,__o_isBackpack,__o_disableBgDraw);
	return __this;
}

::hx::ObjectPtr< InventoryGrid_obj > InventoryGrid_obj::__alloc(::hx::Ctx *_hx_ctx, ::objects::GameObject gridOwner, ::objects::Player currentPlayer,::hx::Null< int >  __o_itemIndexOffset,::hx::Null< bool >  __o_isBackpack,::hx::Null< bool >  __o_disableBgDraw) {
	InventoryGrid_obj *__this = (InventoryGrid_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(InventoryGrid_obj), true, "ui.panels.itemgrids.InventoryGrid"));
	*(void **)__this = InventoryGrid_obj::_hx_vtable;
	__this->__construct(gridOwner,currentPlayer,__o_itemIndexOffset,__o_isBackpack,__o_disableBgDraw);
	return __this;
}

InventoryGrid_obj::InventoryGrid_obj()
{
}

void InventoryGrid_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InventoryGrid);
	HX_MARK_MEMBER_NAME(tiles,"tiles");
	HX_MARK_MEMBER_NAME(isBackpack,"isBackpack");
	 ::ui::panels::itemgrids::ItemGrid_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InventoryGrid_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tiles,"tiles");
	HX_VISIT_MEMBER_NAME(isBackpack,"isBackpack");
	 ::ui::panels::itemgrids::ItemGrid_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val InventoryGrid_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"tiles") ) { return ::hx::Val( tiles ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setItems") ) { return ::hx::Val( setItems_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isBackpack") ) { return ::hx::Val( isBackpack ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val InventoryGrid_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"tiles") ) { tiles=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isBackpack") ) { isBackpack=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InventoryGrid_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("tiles",85,fd,34,10));
	outFields->push(HX_("isBackpack",8a,62,27,9d));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo InventoryGrid_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(InventoryGrid_obj,tiles),HX_("tiles",85,fd,34,10)},
	{::hx::fsBool,(int)offsetof(InventoryGrid_obj,isBackpack),HX_("isBackpack",8a,62,27,9d)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *InventoryGrid_obj_sStaticStorageInfo = 0;
#endif

static ::String InventoryGrid_obj_sMemberFields[] = {
	HX_("tiles",85,fd,34,10),
	HX_("isBackpack",8a,62,27,9d),
	HX_("setItems",fe,14,41,d0),
	::String(null()) };

::hx::Class InventoryGrid_obj::__mClass;

void InventoryGrid_obj::__register()
{
	InventoryGrid_obj _hx_dummy;
	InventoryGrid_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.panels.itemgrids.InventoryGrid",49,35,0c,15);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(InventoryGrid_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< InventoryGrid_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = InventoryGrid_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = InventoryGrid_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace panels
} // end namespace itemgrids