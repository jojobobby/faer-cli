// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_panels_itemgrids_ContainerGrid
#define INCLUDED_ui_panels_itemgrids_ContainerGrid

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_panels_itemgrids_ItemGrid
#include <ui/panels/itemgrids/ItemGrid.h>
#endif
HX_DECLARE_CLASS1(objects,GameObject)
HX_DECLARE_CLASS1(objects,Player)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(ui,panels,Panel)
HX_DECLARE_CLASS3(ui,panels,itemgrids,ContainerGrid)
HX_DECLARE_CLASS3(ui,panels,itemgrids,ItemGrid)
HX_DECLARE_CLASS4(ui,panels,itemgrids,itemtiles,InteractiveItemTile)
HX_DECLARE_CLASS4(ui,panels,itemgrids,itemtiles,ItemTile)

namespace ui{
namespace panels{
namespace itemgrids{


class HXCPP_CLASS_ATTRIBUTES ContainerGrid_obj : public  ::ui::panels::itemgrids::ItemGrid_obj
{
	public:
		typedef  ::ui::panels::itemgrids::ItemGrid_obj super;
		typedef ContainerGrid_obj OBJ_;
		ContainerGrid_obj();

	public:
		enum { _hx_ClassId = 0x2ebe3150 };

		void __construct( ::objects::GameObject gridOwner, ::objects::Player currentPlayer,::hx::Null< bool >  __o_disableBgDraw);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.panels.itemgrids.ContainerGrid")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.panels.itemgrids.ContainerGrid"); }
		static ::hx::ObjectPtr< ContainerGrid_obj > __new( ::objects::GameObject gridOwner, ::objects::Player currentPlayer,::hx::Null< bool >  __o_disableBgDraw);
		static ::hx::ObjectPtr< ContainerGrid_obj > __alloc(::hx::Ctx *_hx_ctx, ::objects::GameObject gridOwner, ::objects::Player currentPlayer,::hx::Null< bool >  __o_disableBgDraw);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ContainerGrid_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ContainerGrid",87,fc,12,bb); }

		::Array< ::Dynamic> tiles;
		void setItems(::Array< int > items,::hx::Null< int >  itemIndexOffset);

};

} // end namespace ui
} // end namespace panels
} // end namespace itemgrids

#endif /* INCLUDED_ui_panels_itemgrids_ContainerGrid */ 
