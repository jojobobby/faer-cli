// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_openfl_display_GraphicsPath
#define INCLUDED_openfl_display_GraphicsPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl_display_IGraphicsPath
#include <openfl/display/IGraphicsPath.h>
#endif
#ifndef INCLUDED_openfl_display_IGraphicsData
#include <openfl/display/IGraphicsData.h>
#endif
HX_DECLARE_CLASS2(openfl,_Vector,FloatVector)
HX_DECLARE_CLASS2(openfl,_Vector,IVector)
HX_DECLARE_CLASS2(openfl,_Vector,IntVector)
HX_DECLARE_CLASS2(openfl,display,GraphicsPath)
HX_DECLARE_CLASS2(openfl,display,IGraphicsData)
HX_DECLARE_CLASS2(openfl,display,IGraphicsPath)

namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES GraphicsPath_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GraphicsPath_obj OBJ_;
		GraphicsPath_obj();

	public:
		enum { _hx_ClassId = 0x2ea33da2 };

		void __construct( ::openfl::_Vector::IntVector commands, ::openfl::_Vector::FloatVector data, ::Dynamic __o_winding);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl.display.GraphicsPath")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"openfl.display.GraphicsPath"); }
		static ::hx::ObjectPtr< GraphicsPath_obj > __new( ::openfl::_Vector::IntVector commands, ::openfl::_Vector::FloatVector data, ::Dynamic __o_winding);
		static ::hx::ObjectPtr< GraphicsPath_obj > __alloc(::hx::Ctx *_hx_ctx, ::openfl::_Vector::IntVector commands, ::openfl::_Vector::FloatVector data, ::Dynamic __o_winding);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GraphicsPath_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		void *_hx_getInterface(int inHash);
		::String __ToString() const { return HX_("GraphicsPath",30,18,59,11); }

		 ::openfl::_Vector::IntVector commands;
		 ::openfl::_Vector::FloatVector data;
		 ::Dynamic winding;
		int _hx___graphicsDataType;
		void lineTo(Float x,Float y);
		::Dynamic lineTo_dyn();

		void moveTo(Float x,Float y);
		::Dynamic moveTo_dyn();

};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_GraphicsPath */ 
