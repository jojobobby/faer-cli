// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_openfl_display_GraphicsStroke
#define INCLUDED_openfl_display_GraphicsStroke

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_IGraphicsStroke
#include <openfl/display/IGraphicsStroke.h>
#endif
#ifndef INCLUDED_openfl_display_IGraphicsData
#include <openfl/display/IGraphicsData.h>
#endif
HX_DECLARE_CLASS2(openfl,display,GraphicsStroke)
HX_DECLARE_CLASS2(openfl,display,IGraphicsData)
HX_DECLARE_CLASS2(openfl,display,IGraphicsFill)
HX_DECLARE_CLASS2(openfl,display,IGraphicsStroke)

namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES GraphicsStroke_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GraphicsStroke_obj OBJ_;
		GraphicsStroke_obj();

	public:
		enum { _hx_ClassId = 0x13109a49 };

		void __construct( ::Dynamic thickness,::hx::Null< bool >  __o_pixelHinting, ::Dynamic __o_scaleMode, ::Dynamic __o_caps, ::Dynamic __o_joints,::hx::Null< Float >  __o_miterLimit,::Dynamic fill);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl.display.GraphicsStroke")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"openfl.display.GraphicsStroke"); }
		static ::hx::ObjectPtr< GraphicsStroke_obj > __new( ::Dynamic thickness,::hx::Null< bool >  __o_pixelHinting, ::Dynamic __o_scaleMode, ::Dynamic __o_caps, ::Dynamic __o_joints,::hx::Null< Float >  __o_miterLimit,::Dynamic fill);
		static ::hx::ObjectPtr< GraphicsStroke_obj > __alloc(::hx::Ctx *_hx_ctx, ::Dynamic thickness,::hx::Null< bool >  __o_pixelHinting, ::Dynamic __o_scaleMode, ::Dynamic __o_caps, ::Dynamic __o_joints,::hx::Null< Float >  __o_miterLimit,::Dynamic fill);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GraphicsStroke_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		void *_hx_getInterface(int inHash);
		::String __ToString() const { return HX_("GraphicsStroke",03,df,55,0e); }

		 ::Dynamic caps;
		::Dynamic fill;
		 ::Dynamic joints;
		Float miterLimit;
		bool pixelHinting;
		 ::Dynamic scaleMode;
		Float thickness;
		int _hx___graphicsDataType;
};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_GraphicsStroke */ 