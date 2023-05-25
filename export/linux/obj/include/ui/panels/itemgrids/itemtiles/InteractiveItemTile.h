// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_InteractiveItemTile
#define INCLUDED_ui_panels_itemgrids_itemtiles_InteractiveItemTile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_panels_itemgrids_itemtiles_ItemTile
#include <ui/panels/itemgrids/itemtiles/ItemTile.h>
#endif
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,MouseEvent)
HX_DECLARE_CLASS2(openfl,events,TimerEvent)
HX_DECLARE_CLASS2(openfl,geom,Point)
HX_DECLARE_CLASS2(openfl,utils,Timer)
HX_DECLARE_CLASS2(ui,panels,Panel)
HX_DECLARE_CLASS3(ui,panels,itemgrids,ItemGrid)
HX_DECLARE_CLASS4(ui,panels,itemgrids,itemtiles,InteractiveItemTile)
HX_DECLARE_CLASS4(ui,panels,itemgrids,itemtiles,ItemTile)

namespace ui{
namespace panels{
namespace itemgrids{
namespace itemtiles{


class HXCPP_CLASS_ATTRIBUTES InteractiveItemTile_obj : public  ::ui::panels::itemgrids::itemtiles::ItemTile_obj
{
	public:
		typedef  ::ui::panels::itemgrids::itemtiles::ItemTile_obj super;
		typedef InteractiveItemTile_obj OBJ_;
		InteractiveItemTile_obj();

	public:
		enum { _hx_ClassId = 0x779643f0 };

		void __construct(int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.panels.itemgrids.itemtiles.InteractiveItemTile")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.panels.itemgrids.itemtiles.InteractiveItemTile"); }
		static ::hx::ObjectPtr< InteractiveItemTile_obj > __new(int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive);
		static ::hx::ObjectPtr< InteractiveItemTile_obj > __alloc(::hx::Ctx *_hx_ctx,int id, ::ui::panels::itemgrids::ItemGrid parentGrid,bool isInteractive);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~InteractiveItemTile_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("InteractiveItemTile",c3,65,85,5e); }

		 ::openfl::utils::Timer doubleClickTimer;
		 ::openfl::geom::Point dragStart;
		bool pendingSecondClick;
		bool isDragging;
		void setInteractive(bool isInteractive);
		::Dynamic setInteractive_dyn();

		 ::openfl::display::DisplayObject getDropTarget();
		::Dynamic getDropTarget_dyn();

		virtual void beginDragCallback();
		::Dynamic beginDragCallback_dyn();

		virtual void endDragCallback();
		::Dynamic endDragCallback_dyn();

		void setPendingDoubleClick(bool isPending);
		::Dynamic setPendingDoubleClick_dyn();

		void onMouseOut( ::openfl::events::MouseEvent e);
		::Dynamic onMouseOut_dyn();

		void onMouseUp( ::openfl::events::MouseEvent e);
		::Dynamic onMouseUp_dyn();

		void onMouseDown( ::openfl::events::MouseEvent e);
		::Dynamic onMouseDown_dyn();

		void beginDragCheck( ::openfl::events::MouseEvent e);
		::Dynamic beginDragCheck_dyn();

		void cancelDragCheck( ::openfl::events::MouseEvent e);
		::Dynamic cancelDragCheck_dyn();

		void onMouseMoveCheckDrag( ::openfl::events::MouseEvent e);
		::Dynamic onMouseMoveCheckDrag_dyn();

		void onDoubleClickTimerComplete( ::openfl::events::TimerEvent e);
		::Dynamic onDoubleClickTimerComplete_dyn();

		void beginDrag( ::openfl::events::MouseEvent e);
		::Dynamic beginDrag_dyn();

		void endDrag( ::openfl::events::MouseEvent e);
		::Dynamic endDrag_dyn();

		void onRemovedFromStage( ::openfl::events::Event e);
		::Dynamic onRemovedFromStage_dyn();

};

} // end namespace ui
} // end namespace panels
} // end namespace itemgrids
} // end namespace itemtiles

#endif /* INCLUDED_ui_panels_itemgrids_itemtiles_InteractiveItemTile */ 