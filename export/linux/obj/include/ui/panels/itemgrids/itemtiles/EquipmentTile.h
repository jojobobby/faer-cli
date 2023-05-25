// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_EquipmentTile
#define INCLUDED_ui_panels_itemgrids_itemtiles_EquipmentTile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_InteractiveItemTile
#include <ui/panels/itemgrids/itemtiles/InteractiveItemTile.h>
#endif
HX_DECLARE_CLASS1(objects,GameObject)
HX_DECLARE_CLASS1(objects,Player)
HX_DECLARE_CLASS2(openfl,display,Bitmap)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,filters,BitmapFilter)
HX_DECLARE_CLASS2(openfl,filters,ColorMatrixFilter)
HX_DECLARE_CLASS2(ui,panels,Panel)
HX_DECLARE_CLASS3(ui,panels,itemgrids,ItemGrid)
HX_DECLARE_CLASS4(ui,panels,itemgrids,itemtiles,EquipmentTile)
HX_DECLARE_CLASS4(ui,panels,itemgrids,itemtiles,InteractiveItemTile)
HX_DECLARE_CLASS4(ui,panels,itemgrids,itemtiles,ItemTile)

namespace ui{
namespace panels{
namespace itemgrids{
namespace itemtiles{


class HXCPP_CLASS_ATTRIBUTES EquipmentTile_obj : public  ::ui::panels::itemgrids::itemtiles::InteractiveItemTile_obj
{
	public:
		typedef  ::ui::panels::itemgrids::itemtiles::InteractiveItemTile_obj super;
		typedef EquipmentTile_obj OBJ_;
		EquipmentTile_obj();

	public:
		enum { _hx_ClassId = 0x46e88c79 };

		void __construct(int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.panels.itemgrids.itemtiles.EquipmentTile")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.panels.itemgrids.itemtiles.EquipmentTile"); }
		static ::hx::ObjectPtr< EquipmentTile_obj > __new(int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive);
		static ::hx::ObjectPtr< EquipmentTile_obj > __alloc(::hx::Ctx *_hx_ctx,int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~EquipmentTile_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("EquipmentTile",7c,ba,36,a0); }

		static void __boot();
		static  ::openfl::filters::ColorMatrixFilter greyColorFilter;
		 ::openfl::display::Bitmap backgroundDetail;
		int slotType;
		int minManaUsage;
		int minHealthUsage;
		bool canHoldItem(int itemType);

		bool setItem(int itemId);

		void beginDragCallback();

		void endDragCallback();

		void setType(int slotType);
		::Dynamic setType_dyn();

		void updateDim( ::objects::Player player);
		::Dynamic updateDim_dyn();

		void updateMinMana();
		::Dynamic updateMinMana_dyn();

};

} // end namespace ui
} // end namespace panels
} // end namespace itemgrids
} // end namespace itemtiles

#endif /* INCLUDED_ui_panels_itemgrids_itemtiles_EquipmentTile */ 
