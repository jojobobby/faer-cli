// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_objects_animation_AnimationData
#define INCLUDED_objects_animation_AnimationData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(objects,animation,AnimationData)
HX_DECLARE_CLASS2(objects,animation,FrameData)

namespace objects{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES AnimationData_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef AnimationData_obj OBJ_;
		AnimationData_obj();

	public:
		enum { _hx_ClassId = 0x38c84dda };

		void __construct( ::Xml xml);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="objects.animation.AnimationData")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"objects.animation.AnimationData"); }
		static ::hx::ObjectPtr< AnimationData_obj > __new( ::Xml xml);
		static ::hx::ObjectPtr< AnimationData_obj > __alloc(::hx::Ctx *_hx_ctx, ::Xml xml);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~AnimationData_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("AnimationData",2e,93,9f,7c); }

		Float prob;
		int period;
		int periodJitter;
		bool sync;
		::Array< ::Dynamic> frames;
		int getLastRun(int time);
		::Dynamic getLastRun_dyn();

		int getNextRun(int time);
		::Dynamic getNextRun_dyn();

		int getPeriod();
		::Dynamic getPeriod_dyn();

};

} // end namespace objects
} // end namespace animation

#endif /* INCLUDED_objects_animation_AnimationData */ 
