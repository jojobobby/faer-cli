// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_lime_graphics_opengl_ext_OES_texture_3D
#define INCLUDED_lime_graphics_opengl_ext_OES_texture_3D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_973c90bb42c6d3fb_4_new)
HX_DECLARE_CLASS4(lime,graphics,opengl,ext,OES_texture_3D)

namespace lime{
namespace graphics{
namespace opengl{
namespace ext{


class HXCPP_CLASS_ATTRIBUTES OES_texture_3D_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef OES_texture_3D_obj OBJ_;
		OES_texture_3D_obj();

	public:
		enum { _hx_ClassId = 0x31140d25 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lime.graphics.opengl.ext.OES_texture_3D")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lime.graphics.opengl.ext.OES_texture_3D"); }

		inline static ::hx::ObjectPtr< OES_texture_3D_obj > __new() {
			::hx::ObjectPtr< OES_texture_3D_obj > __this = new OES_texture_3D_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< OES_texture_3D_obj > __alloc(::hx::Ctx *_hx_ctx) {
			OES_texture_3D_obj *__this = (OES_texture_3D_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(OES_texture_3D_obj), false, "lime.graphics.opengl.ext.OES_texture_3D"));
			*(void **)__this = OES_texture_3D_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_973c90bb42c6d3fb_4_new)
HXLINE(  11)		( ( ::lime::graphics::opengl::ext::OES_texture_3D)(__this) )->FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_OES = 36052;
HXLINE(  10)		( ( ::lime::graphics::opengl::ext::OES_texture_3D)(__this) )->SAMPLER_3D_OES = 35679;
HXLINE(   9)		( ( ::lime::graphics::opengl::ext::OES_texture_3D)(__this) )->MAX_3D_TEXTURE_SIZE_OES = 32883;
HXLINE(   8)		( ( ::lime::graphics::opengl::ext::OES_texture_3D)(__this) )->TEXTURE_BINDING_3D_OES = 32874;
HXLINE(   7)		( ( ::lime::graphics::opengl::ext::OES_texture_3D)(__this) )->TEXTURE_3D_OES = 32879;
HXLINE(   6)		( ( ::lime::graphics::opengl::ext::OES_texture_3D)(__this) )->TEXTURE_WRAP_R_OES = 32882;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~OES_texture_3D_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("OES_texture_3D",97,1a,cf,b4); }

		int TEXTURE_WRAP_R_OES;
		int TEXTURE_3D_OES;
		int TEXTURE_BINDING_3D_OES;
		int MAX_3D_TEXTURE_SIZE_OES;
		int SAMPLER_3D_OES;
		int FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_OES;
};

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext

#endif /* INCLUDED_lime_graphics_opengl_ext_OES_texture_3D */ 
