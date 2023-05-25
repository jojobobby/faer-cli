// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_objects_GameObject
#define INCLUDED_objects_GameObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS1(map,Map)
HX_DECLARE_CLASS1(map,Square)
HX_DECLARE_CLASS1(objects,GameObject)
HX_DECLARE_CLASS1(objects,ObjectProperties)
HX_DECLARE_CLASS1(objects,Projectile)
HX_DECLARE_CLASS1(objects,TextureData)
HX_DECLARE_CLASS2(objects,animation,Animations)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,geom,Point)
HX_DECLARE_CLASS2(openfl,geom,Vector3D)
HX_DECLARE_CLASS2(openfl,text,TextField)
HX_DECLARE_CLASS1(ui,SimpleText)
HX_DECLARE_CLASS1(util,AnimatedChar)

namespace objects{


class HXCPP_CLASS_ATTRIBUTES GameObject_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GameObject_obj OBJ_;
		GameObject_obj();

	public:
		enum { _hx_ClassId = 0x0cff6b45 };

		void __construct( ::Xml objectXML,::String objClass);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="objects.GameObject")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"objects.GameObject"); }
		static ::hx::ObjectPtr< GameObject_obj > __new( ::Xml objectXML,::String objClass);
		static ::hx::ObjectPtr< GameObject_obj > __alloc(::hx::Ctx *_hx_ctx, ::Xml objectXML,::String objClass);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GameObject_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GameObject",71,6c,66,4e); }

		static int physicalDamage(int dmg,int def,int cond);
		static ::Dynamic physicalDamage_dyn();

		static int magicDamage(int dmg,int res,int cond);
		static ::Dynamic magicDamage_dyn();

		static int trueDamage(int dmg,int cond);
		static ::Dynamic trueDamage_dyn();

		 ::map::Map map;
		 ::map::Square curSquare;
		int objectId;
		float mapX;
		float mapY;
		float mapZ;
		float screenX;
		float screenYNoZ;
		float hBase;
		 ::objects::ObjectProperties props;
		::String name;
		float facing;
		bool flying;
		bool floatFlip;
		int lastFloatUpdate;
		float attackAngle;
		int attackStart;
		 ::util::AnimatedChar animatedChar;
		float uValue;
		float vValue;
		float topUValue;
		float topVValue;
		float width;
		float height;
		float maskUValue;
		float maskVValue;
		float maskWidth;
		float maskHeight;
		::Array< ::Dynamic> randomTextureData;
		 ::objects::animation::Animations animations;
		bool dead;
		int maxHP;
		int hp;
		float size;
		int defense;
		int resistance;
		::Array< int > slotTypes;
		::Array< int > equipment;
		int condition;
		int objectType;
		float sinkLevel;
		float flashStartTime;
		float flashPeriodMs;
		float flashRepeats;
		float flashColor;
		float glowColor;
		 ::ui::SimpleText nameText;
		 ::openfl::display::BitmapData nameTex;
		 ::openfl::display::BitmapData enterTex;
		 ::openfl::display::BitmapData enterKeyTex;
		int ownerId;
		::String objClass;
		 ::openfl::display::BitmapData portrait;
		int myLastTickId;
		 ::openfl::geom::Point posAtTick;
		 ::openfl::geom::Point tickPosition;
		int lastTickUpdateTime;
		 ::openfl::geom::Vector3D moveVec;
		signed char nextBulletId;
		float sizeMult;
		int floatTimeOffset;
		unsigned int mapColor;
		::Array< unsigned int > bloodColors;
		void dispose();
		::Dynamic dispose_dyn();

		virtual bool addTo( ::map::Map map,float x,float y);

		virtual void removeFromMap();
		::Dynamic removeFromMap_dyn();

		virtual bool update(int time,short dt);
		::Dynamic update_dyn();

		void setObjectId(int objId);
		::Dynamic setObjectId_dyn();

		void setAltTexture(int altTextureId);
		::Dynamic setAltTexture_dyn();

		void playSound(int id);
		::Dynamic playSound_dyn();

		unsigned int getColor();
		::Dynamic getColor_dyn();

		Float distTo(float x,float y);
		::Dynamic distTo_dyn();

		virtual bool moveTo(float x,float y);
		::Dynamic moveTo_dyn();

		void onGoto(float x,float y,int time);
		::Dynamic onGoto_dyn();

		void onTickPos(float x,float y,int tickTime,int tickId);
		::Dynamic onTickPos_dyn();

		virtual void damage(int origType,int damageAmount,::Array< int > effects,bool kill, ::objects::Projectile proj,::hx::Null< unsigned int >  textColor);
		::Dynamic damage_dyn();

		void setAttack(int containerType,float attackAngle);
		::Dynamic setAttack_dyn();

};

} // end namespace objects

#endif /* INCLUDED_objects_GameObject */ 