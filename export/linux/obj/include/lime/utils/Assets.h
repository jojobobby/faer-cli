// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_lime_utils_Assets
#define INCLUDED_lime_utils_Assets

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(lime,app,Future)
HX_DECLARE_CLASS2(lime,app,_Event_Void_Void)
HX_DECLARE_CLASS2(lime,graphics,Image)
HX_DECLARE_CLASS2(lime,media,AudioBuffer)
HX_DECLARE_CLASS2(lime,text,Font)
HX_DECLARE_CLASS2(lime,utils,AssetCache)
HX_DECLARE_CLASS2(lime,utils,AssetLibrary)
HX_DECLARE_CLASS2(lime,utils,Assets)

namespace lime{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES Assets_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Assets_obj OBJ_;
		Assets_obj();

	public:
		enum { _hx_ClassId = 0x4d8112bb };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lime.utils.Assets")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lime.utils.Assets"); }

		inline static ::hx::ObjectPtr< Assets_obj > __new() {
			::hx::ObjectPtr< Assets_obj > __this = new Assets_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Assets_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Assets_obj *__this = (Assets_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Assets_obj), false, "lime.utils.Assets"));
			*(void **)__this = Assets_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Assets_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Assets",a3,bc,97,80); }

		static void __boot();
		static  ::lime::utils::AssetCache cache;
		static  ::lime::app::_Event_Void_Void onChange;
		static  ::haxe::ds::StringMap bundlePaths;
		static  ::haxe::ds::StringMap libraries;
		static  ::haxe::ds::StringMap libraryPaths;
		static  ::Dynamic getAsset(::String id,::String type,bool useCache);
		static ::Dynamic getAsset_dyn();

		static  ::lime::media::AudioBuffer getAudioBuffer(::String id,::hx::Null< bool >  useCache);
		static ::Dynamic getAudioBuffer_dyn();

		static  ::haxe::io::Bytes getBytes(::String id);
		static ::Dynamic getBytes_dyn();

		static  ::lime::text::Font getFont(::String id,::hx::Null< bool >  useCache);
		static ::Dynamic getFont_dyn();

		static  ::lime::graphics::Image getImage(::String id,::hx::Null< bool >  useCache);
		static ::Dynamic getImage_dyn();

		static  ::lime::utils::AssetLibrary getLibrary(::String name);
		static ::Dynamic getLibrary_dyn();

		static ::String getText(::String id);
		static ::Dynamic getText_dyn();

		static bool isLocal(::String id,::String type,::hx::Null< bool >  useCache);
		static ::Dynamic isLocal_dyn();

		static bool isValidAudio( ::lime::media::AudioBuffer buffer);
		static ::Dynamic isValidAudio_dyn();

		static bool isValidImage( ::lime::graphics::Image image);
		static ::Dynamic isValidImage_dyn();

		static  ::lime::app::Future loadLibrary(::String id);
		static ::Dynamic loadLibrary_dyn();

		static ::String _hx___cacheBreak(::String path);
		static ::Dynamic _hx___cacheBreak_dyn();

		static ::String _hx___libraryNotFound(::String name);
		static ::Dynamic _hx___libraryNotFound_dyn();

};

} // end namespace lime
} // end namespace utils

#endif /* INCLUDED_lime_utils_Assets */ 
