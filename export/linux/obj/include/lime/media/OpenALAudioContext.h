// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_lime_media_OpenALAudioContext
#define INCLUDED_lime_media_OpenALAudioContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(lime,media,OpenALAudioContext)

namespace lime{
namespace media{


class HXCPP_CLASS_ATTRIBUTES OpenALAudioContext_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef OpenALAudioContext_obj OBJ_;
		OpenALAudioContext_obj();

	public:
		enum { _hx_ClassId = 0x1531d04d };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lime.media.OpenALAudioContext")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lime.media.OpenALAudioContext"); }
		static ::hx::ObjectPtr< OpenALAudioContext_obj > __new();
		static ::hx::ObjectPtr< OpenALAudioContext_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~OpenALAudioContext_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("OpenALAudioContext",ae,da,cd,a1); }

		bool closeDevice( ::Dynamic device);
		::Dynamic closeDevice_dyn();

		 ::Dynamic createContext( ::Dynamic device,::Array< int > attrlist);
		::Dynamic createContext_dyn();

		void destroyContext( ::Dynamic context);
		::Dynamic destroyContext_dyn();

		 ::Dynamic getContextsDevice( ::Dynamic context);
		::Dynamic getContextsDevice_dyn();

		 ::Dynamic getCurrentContext();
		::Dynamic getCurrentContext_dyn();

		bool makeContextCurrent( ::Dynamic context);
		::Dynamic makeContextCurrent_dyn();

		 ::Dynamic openDevice(::String deviceName);
		::Dynamic openDevice_dyn();

		void pauseDevice( ::Dynamic device);
		::Dynamic pauseDevice_dyn();

		void processContext( ::Dynamic context);
		::Dynamic processContext_dyn();

		void resumeDevice( ::Dynamic device);
		::Dynamic resumeDevice_dyn();

		void suspendContext( ::Dynamic context);
		::Dynamic suspendContext_dyn();

};

} // end namespace lime
} // end namespace media

#endif /* INCLUDED_lime_media_OpenALAudioContext */ 
