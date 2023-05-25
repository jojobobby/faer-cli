// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_game_model_GameInitData
#define INCLUDED_game_model_GameInitData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(game,model,GameInitData)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(openfl,utils,ByteArrayData)
HX_DECLARE_CLASS2(openfl,utils,IDataInput)
HX_DECLARE_CLASS2(openfl,utils,IDataOutput)

namespace game{
namespace model{


class HXCPP_CLASS_ATTRIBUTES GameInitData_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GameInitData_obj OBJ_;
		GameInitData_obj();

	public:
		enum { _hx_ClassId = 0x2051af1f };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="game.model.GameInitData")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"game.model.GameInitData"); }
		static ::hx::ObjectPtr< GameInitData_obj > __new();
		static ::hx::ObjectPtr< GameInitData_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GameInitData_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GameInitData",8c,c3,1d,4a); }

		int gameId;
		bool createCharacter;
		int charId;
		 ::openfl::utils::ByteArrayData fmMap;
};

} // end namespace game
} // end namespace model

#endif /* INCLUDED_game_model_GameInitData */ 