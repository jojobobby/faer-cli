// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_panels_GuildInvitePanel
#define INCLUDED_ui_panels_GuildInvitePanel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_ui_panels_Panel
#include <ui/panels/Panel.h>
#endif
HX_DECLARE_CLASS1(game,GameSprite)
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
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS2(openfl,utils,Timer)
HX_DECLARE_CLASS1(ui,SimpleText)
HX_DECLARE_CLASS1(ui,TextButton)
HX_DECLARE_CLASS2(ui,panels,GuildInvitePanel)
HX_DECLARE_CLASS2(ui,panels,Panel)

namespace ui{
namespace panels{


class HXCPP_CLASS_ATTRIBUTES GuildInvitePanel_obj : public  ::ui::panels::Panel_obj
{
	public:
		typedef  ::ui::panels::Panel_obj super;
		typedef GuildInvitePanel_obj OBJ_;
		GuildInvitePanel_obj();

	public:
		enum { _hx_ClassId = 0x1903514f };

		void __construct( ::game::GameSprite gs,::String name,::String guildName);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.panels.GuildInvitePanel")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.panels.GuildInvitePanel"); }
		static ::hx::ObjectPtr< GuildInvitePanel_obj > __new( ::game::GameSprite gs,::String name,::String guildName);
		static ::hx::ObjectPtr< GuildInvitePanel_obj > __alloc(::hx::Ctx *_hx_ctx, ::game::GameSprite gs,::String name,::String guildName);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GuildInvitePanel_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GuildInvitePanel",a8,d9,16,e5); }

		::String playerName;
		 ::ui::SimpleText title;
		::String guildName;
		 ::ui::SimpleText guildNameText;
		 ::ui::TextButton rejectButton;
		 ::ui::TextButton acceptButton;
		 ::openfl::utils::Timer timer;
		void onTimer( ::openfl::events::TimerEvent event);
		::Dynamic onTimer_dyn();

		void onRejectClick( ::openfl::events::MouseEvent event);
		::Dynamic onRejectClick_dyn();

		void onAcceptClick( ::openfl::events::MouseEvent event);
		::Dynamic onAcceptClick_dyn();

};

} // end namespace ui
} // end namespace panels

#endif /* INCLUDED_ui_panels_GuildInvitePanel */ 
