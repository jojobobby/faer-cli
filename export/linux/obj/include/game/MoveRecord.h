// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_game_MoveRecord
#define INCLUDED_game_MoveRecord

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_78b2c84ad3c94c34_7_new)
HX_DECLARE_CLASS1(game,MoveRecord)

namespace game{


class HXCPP_CLASS_ATTRIBUTES MoveRecord_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef MoveRecord_obj OBJ_;
		MoveRecord_obj();

	public:
		enum { _hx_ClassId = 0x32e6e114 };

		void __construct(int time,float x,float y);
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="game.MoveRecord")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"game.MoveRecord"); }

		inline static ::hx::ObjectPtr< MoveRecord_obj > __new(int time,float x,float y) {
			::hx::ObjectPtr< MoveRecord_obj > __this = new MoveRecord_obj();
			__this->__construct(time,x,y);
			return __this;
		}

		inline static ::hx::ObjectPtr< MoveRecord_obj > __alloc(::hx::Ctx *_hx_ctx,int time,float x,float y) {
			MoveRecord_obj *__this = (MoveRecord_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(MoveRecord_obj), false, "game.MoveRecord"));
			*(void **)__this = MoveRecord_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_78b2c84ad3c94c34_7_new)
HXDLIN(   7)		( ( ::game::MoveRecord)(__this) )->time = time;
HXDLIN(   7)		( ( ::game::MoveRecord)(__this) )->x = x;
HXDLIN(   7)		( ( ::game::MoveRecord)(__this) )->y = y;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~MoveRecord_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("MoveRecord",a2,f4,cb,44); }

		int time;
		float x;
		float y;
};

} // end namespace game

#endif /* INCLUDED_game_MoveRecord */ 