// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_ui_options_Options
#define INCLUDED_ui_options_Options

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
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
HX_DECLARE_CLASS2(openfl,events,KeyboardEvent)
HX_DECLARE_CLASS2(openfl,events,MouseEvent)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS1(screens,TitleMenuOption)
HX_DECLARE_CLASS1(ui,SimpleText)
HX_DECLARE_CLASS2(ui,options,Options)
HX_DECLARE_CLASS2(ui,options,OptionsTabTitle)

namespace ui{
namespace options{


class HXCPP_CLASS_ATTRIBUTES Options_obj : public  ::openfl::display::Sprite_obj
{
	public:
		typedef  ::openfl::display::Sprite_obj super;
		typedef Options_obj OBJ_;
		Options_obj();

	public:
		enum { _hx_ClassId = 0x7dbac234 };

		void __construct( ::game::GameSprite gs);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ui.options.Options")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ui.options.Options"); }
		static ::hx::ObjectPtr< Options_obj > __new( ::game::GameSprite gs);
		static ::hx::ObjectPtr< Options_obj > __alloc(::hx::Ctx *_hx_ctx, ::game::GameSprite gs);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Options_obj();

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
		::String __ToString() const { return HX_("Options",3e,5b,4f,ad); }

		static void __boot();
		static ::Array< ::String > TABS;
		static void onPlayMusicChange();
		static ::Dynamic onPlayMusicChange_dyn();

		static void onPlaySoundEffectsChange();
		static ::Dynamic onPlaySoundEffectsChange_dyn();

		static void onKeyUp( ::openfl::events::KeyboardEvent event);
		static ::Dynamic onKeyUp_dyn();

		 ::game::GameSprite gs;
		 ::ui::SimpleText title;
		 ::screens::TitleMenuOption continueButton;
		 ::screens::TitleMenuOption resetToDefaultsButton;
		 ::screens::TitleMenuOption homeButton;
		::Array< ::Dynamic> tabs;
		 ::ui::options::OptionsTabTitle selected;
		::Array< ::Dynamic> options;
		int optionIndex;
		void setSelected( ::ui::options::OptionsTabTitle tab);
		::Dynamic setSelected_dyn();

		void close();
		::Dynamic close_dyn();

		void removeOptions();
		::Dynamic removeOptions_dyn();

		void addControlsOptions();
		::Dynamic addControlsOptions_dyn();

		void addHotKeysOptions();
		::Dynamic addHotKeysOptions_dyn();

		void addChatOptions();
		::Dynamic addChatOptions_dyn();

		void addGraphicsOptions();
		::Dynamic addGraphicsOptions_dyn();

		void addSoundOptions();
		::Dynamic addSoundOptions_dyn();

		void addOption( ::openfl::display::Sprite option);
		::Dynamic addOption_dyn();

		void refresh();
		::Dynamic refresh_dyn();

		void onContinueClick( ::openfl::events::MouseEvent event);
		::Dynamic onContinueClick_dyn();

		void onResetToDefaultsClick( ::openfl::events::MouseEvent event);
		::Dynamic onResetToDefaultsClick_dyn();

		void onHomeClick( ::openfl::events::MouseEvent event);
		::Dynamic onHomeClick_dyn();

		void onTabClick( ::openfl::events::MouseEvent event);
		::Dynamic onTabClick_dyn();

		void onAddedToStage( ::openfl::events::Event event);
		::Dynamic onAddedToStage_dyn();

		void onRemovedFromStage( ::openfl::events::Event event);
		::Dynamic onRemovedFromStage_dyn();

		void onKeyDown( ::openfl::events::KeyboardEvent event);
		::Dynamic onKeyDown_dyn();

		void onChange( ::openfl::events::Event event);
		::Dynamic onChange_dyn();

};

} // end namespace ui
} // end namespace options

#endif /* INCLUDED_ui_options_Options */ 