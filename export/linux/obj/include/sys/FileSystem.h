// Generated by Haxe 4.3.0+731dcd7
#ifndef INCLUDED_sys_FileSystem
#define INCLUDED_sys_FileSystem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(sys,FileSystem)

namespace sys{


class HXCPP_CLASS_ATTRIBUTES FileSystem_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef FileSystem_obj OBJ_;
		FileSystem_obj();

	public:
		enum { _hx_ClassId = 0x2378c654 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="sys.FileSystem")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"sys.FileSystem"); }

		inline static ::hx::ObjectPtr< FileSystem_obj > __new() {
			::hx::ObjectPtr< FileSystem_obj > __this = new FileSystem_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< FileSystem_obj > __alloc(::hx::Ctx *_hx_ctx) {
			FileSystem_obj *__this = (FileSystem_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FileSystem_obj), false, "sys.FileSystem"));
			*(void **)__this = FileSystem_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FileSystem_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("FileSystem",ab,e2,17,ca); }

		static bool exists(::String path);
		static ::Dynamic exists_dyn();

		static  ::Dynamic stat(::String path);
		static ::Dynamic stat_dyn();

		static bool isDirectory(::String path);
		static ::Dynamic isDirectory_dyn();

};

} // end namespace sys

#endif /* INCLUDED_sys_FileSystem */ 
