// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_openfl_media_SoundLoaderContext
#define INCLUDED_openfl_media_SoundLoaderContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,media,SoundLoaderContext)

namespace openfl{
namespace media{


class HXCPP_CLASS_ATTRIBUTES SoundLoaderContext_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef SoundLoaderContext_obj OBJ_;
		SoundLoaderContext_obj();

	public:
		enum { _hx_ClassId = 0x08c82281 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="openfl.media.SoundLoaderContext")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"openfl.media.SoundLoaderContext"); }

		inline static ::hx::ObjectPtr< SoundLoaderContext_obj > __new() {
			::hx::ObjectPtr< SoundLoaderContext_obj > __this = new SoundLoaderContext_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< SoundLoaderContext_obj > __alloc(::hx::Ctx *_hx_ctx) {
			SoundLoaderContext_obj *__this = (SoundLoaderContext_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SoundLoaderContext_obj), false, "openfl.media.SoundLoaderContext"));
			*(void **)__this = SoundLoaderContext_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~SoundLoaderContext_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("SoundLoaderContext",ed,bf,f5,97); }

};

} // end namespace openfl
} // end namespace media

#endif /* INCLUDED_openfl_media_SoundLoaderContext */ 