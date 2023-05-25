// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

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
#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_ItemTileSprite
#include <ui/panels/itemgrids/itemtiles/ItemTileSprite.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_c45a406143c4c451_10_new,"ui.panels.itemgrids.itemtiles.InventoryTile","new",0x630b8a07,"ui.panels.itemgrids.itemtiles.InventoryTile.new","ui/panels/itemgrids/itemtiles/InventoryTile.hx",10,0x2ef4e4ab)
HX_LOCAL_STACK_FRAME(_hx_pos_c45a406143c4c451_13_setItemSprite,"ui.panels.itemgrids.itemtiles.InventoryTile","setItemSprite",0xad2cd421,"ui.panels.itemgrids.itemtiles.InventoryTile.setItemSprite","ui/panels/itemgrids/itemtiles/InventoryTile.hx",13,0x2ef4e4ab)
namespace ui{
namespace panels{
namespace itemgrids{
namespace itemtiles{

void InventoryTile_obj::__construct(int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive){
            	HX_STACKFRAME(&_hx_pos_c45a406143c4c451_10_new)
HXDLIN(  10)		super::__construct(id,parentGrid,isInteractive);
            	}

Dynamic InventoryTile_obj::__CreateEmpty() { return new InventoryTile_obj; }

void *InventoryTile_obj::_hx_vtable = 0;

Dynamic InventoryTile_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< InventoryTile_obj > _hx_result = new InventoryTile_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool InventoryTile_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x4af7dd8e) {
		if (inClassId<=(int)0x0c89e854) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x0c89e854;
			}
		} else {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		}
	} else {
		if (inClassId<=(int)0x6b353933) {
			if (inClassId<=(int)0x65ba405c) {
				return inClassId==(int)0x65b8ceab || inClassId==(int)0x65ba405c;
			} else {
				return inClassId==(int)0x6b353933;
			}
		} else {
			return inClassId==(int)0x779643f0;
		}
	}
}

void InventoryTile_obj::setItemSprite( ::ui::panels::itemgrids::itemtiles::ItemTileSprite newItemSprite){
            	HX_STACKFRAME(&_hx_pos_c45a406143c4c451_13_setItemSprite)
HXLINE(  14)		this->super::setItemSprite(newItemSprite);
HXLINE(  15)		newItemSprite->setDim(false);
            	}



::hx::ObjectPtr< InventoryTile_obj > InventoryTile_obj::__new(int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive) {
	::hx::ObjectPtr< InventoryTile_obj > __this = new InventoryTile_obj();
	__this->__construct(id,parentGrid,isInteractive);
	return __this;
}

::hx::ObjectPtr< InventoryTile_obj > InventoryTile_obj::__alloc(::hx::Ctx *_hx_ctx,int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive) {
	InventoryTile_obj *__this = (InventoryTile_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(InventoryTile_obj), true, "ui.panels.itemgrids.itemtiles.InventoryTile"));
	*(void **)__this = InventoryTile_obj::_hx_vtable;
	__this->__construct(id,parentGrid,isInteractive);
	return __this;
}

InventoryTile_obj::InventoryTile_obj()
{
}

::hx::Val InventoryTile_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"setItemSprite") ) { return ::hx::Val( setItemSprite_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *InventoryTile_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *InventoryTile_obj_sStaticStorageInfo = 0;
#endif

static ::String InventoryTile_obj_sMemberFields[] = {
	HX_("setItemSprite",ba,e3,1b,53),
	::String(null()) };

::hx::Class InventoryTile_obj::__mClass;

void InventoryTile_obj::__register()
{
	InventoryTile_obj _hx_dummy;
	InventoryTile_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ui.panels.itemgrids.itemtiles.InventoryTile",95,7a,d6,f3);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(InventoryTile_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< InventoryTile_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = InventoryTile_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = InventoryTile_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace ui
} // end namespace panels
} // end namespace itemgrids
} // end namespace itemtiles
