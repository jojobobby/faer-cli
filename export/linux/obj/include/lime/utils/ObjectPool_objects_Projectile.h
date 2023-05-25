// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_lime_utils_ObjectPool_objects_Projectile
#define INCLUDED_lime_utils_ObjectPool_objects_Projectile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,List)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
HX_DECLARE_CLASS2(lime,utils,ObjectPool_objects_Projectile)
HX_DECLARE_CLASS1(objects,GameObject)
HX_DECLARE_CLASS1(objects,Projectile)

namespace lime{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES ObjectPool_objects_Projectile_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ObjectPool_objects_Projectile_obj OBJ_;
		ObjectPool_objects_Projectile_obj();

	public:
		enum { _hx_ClassId = 0x0f011160 };

		void __construct( ::Dynamic create, ::Dynamic clean, ::Dynamic size);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="lime.utils.ObjectPool_objects_Projectile")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"lime.utils.ObjectPool_objects_Projectile"); }
		static ::hx::ObjectPtr< ObjectPool_objects_Projectile_obj > __new( ::Dynamic create, ::Dynamic clean, ::Dynamic size);
		static ::hx::ObjectPtr< ObjectPool_objects_Projectile_obj > __alloc(::hx::Ctx *_hx_ctx, ::Dynamic create, ::Dynamic clean, ::Dynamic size);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		static void __alloc_dynamic_functions(::hx::Ctx *_hx_alloc,ObjectPool_objects_Projectile_obj *_hx_obj);
		//~ObjectPool_objects_Projectile_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ObjectPool_objects_Projectile",78,a4,ca,c5); }

		int activeObjects;
		int inactiveObjects;
		 ::objects::Projectile _hx___inactiveObject0;
		 ::objects::Projectile _hx___inactiveObject1;
		 ::haxe::ds::List _hx___inactiveObjectList;
		 ::haxe::ds::ObjectMap _hx___pool;
		 ::Dynamic _hx___size;
		::Dynamic clean;
		inline ::Dynamic &clean_dyn() {return clean; }

		::Dynamic create;
		inline ::Dynamic &create_dyn() {return create; }

		 ::objects::Projectile get();
		::Dynamic get_dyn();

		void release( ::objects::Projectile object);
		::Dynamic release_dyn();

		void _hx___removeInactive(int count);
		::Dynamic _hx___removeInactive_dyn();

		 ::Dynamic set_size( ::Dynamic value);
		::Dynamic set_size_dyn();

};

} // end namespace lime
} // end namespace utils

#endif /* INCLUDED_lime_utils_ObjectPool_objects_Projectile */ 