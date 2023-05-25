// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_geom_Point
#include <openfl/geom/Point.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif
#ifndef INCLUDED_util_BinPacker
#include <util/BinPacker.h>
#endif
#ifndef INCLUDED_util_BitmapUtil
#include <util/BitmapUtil.h>
#endif
#ifndef INCLUDED_util_ImageSet
#include <util/ImageSet.h>
#endif
#ifndef INCLUDED_util_Rect
#include <util/Rect.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_66b6ceb1d1b40be2_8_new,"util.ImageSet","new",0x916d5785,"util.ImageSet.new","util/ImageSet.hx",8,0x7f3e2d2a)
HX_LOCAL_STACK_FRAME(_hx_pos_66b6ceb1d1b40be2_26_addFromBitmapData,"util.ImageSet","addFromBitmapData",0x9a3583a9,"util.ImageSet.addFromBitmapData","util/ImageSet.hx",26,0x7f3e2d2a)
namespace util{

void ImageSet_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_66b6ceb1d1b40be2_8_new)
HXLINE(  11)		this->allowsAtlas = true;
HXLINE(  14)		this->images = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  15)		this->rects = ::Array_obj< ::Dynamic>::__new(0);
            	}

Dynamic ImageSet_obj::__CreateEmpty() { return new ImageSet_obj; }

void *ImageSet_obj::_hx_vtable = 0;

Dynamic ImageSet_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ImageSet_obj > _hx_result = new ImageSet_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool ImageSet_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x222980b9;
}

void ImageSet_obj::addFromBitmapData( ::openfl::display::BitmapData bitmapData,int width,int height,::hx::Null< bool >  __o_ignoreAtlas,::hx::Null< bool >  __o_animChar){
            		bool ignoreAtlas = __o_ignoreAtlas.Default(false);
            		bool animChar = __o_animChar.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_66b6ceb1d1b40be2_26_addFromBitmapData)
HXLINE(  27)		this->allowsAtlas = !(ignoreAtlas);
HXLINE(  29)		int maxX = ::Std_obj::_hx_int((( (Float)(bitmapData->width) ) / ( (Float)(width) )));
HXDLIN(  29)		int maxY = ::Std_obj::_hx_int((( (Float)(bitmapData->height) ) / ( (Float)(height) )));
HXLINE(  32)		bool mirrored = false;
HXLINE(  33)		{
HXLINE(  33)			int _g = 0;
HXDLIN(  33)			while((_g < maxY)){
HXLINE(  33)				_g = (_g + 1);
HXDLIN(  33)				int y = (_g - 1);
HXLINE(  34)				{
HXLINE(  34)					int _g1 = 0;
HXDLIN(  34)					while((_g1 < maxX)){
HXLINE(  34)						_g1 = (_g1 + 1);
HXDLIN(  34)						int x = (_g1 - 1);
HXLINE(  35)						bool _hx_tmp;
HXDLIN(  35)						if (animChar) {
HXLINE(  35)							_hx_tmp = (x == 5);
            						}
            						else {
HXLINE(  35)							_hx_tmp = false;
            						}
HXDLIN(  35)						if (_hx_tmp) {
HXLINE(  36)							if (!(mirrored)) {
HXLINE(  37)								{
HXLINE(  37)									int _g2 = 0;
HXDLIN(  37)									while((_g2 < 5)){
HXLINE(  37)										_g2 = (_g2 + 1);
HXDLIN(  37)										int i = (_g2 - 1);
HXLINE(  38)										int w;
HXDLIN(  38)										if ((i == 4)) {
HXLINE(  38)											w = (width * 2);
            										}
            										else {
HXLINE(  38)											w = width;
            										}
HXLINE(  39)										 ::openfl::display::BitmapData tex = ::util::BitmapUtil_obj::mirror(this->images->__get(i).StaticCast<  ::openfl::display::BitmapData >(),null());
HXLINE(  40)										this->images->push(tex);
HXLINE(  42)										if (!(ignoreAtlas)) {
HXLINE(  43)											 ::util::Rect rect = ::Main_obj::atlasPacker->insert(( (float)((w + 4)) ),( (float)((height + 4)) ));
HXLINE(  44)											this->rects->push(rect);
HXLINE(  45)											::Main_obj::tempAtlas->copyPixels(tex, ::openfl::geom::Rectangle_obj::__alloc( HX_CTX ,0,0,rect->width,rect->height), ::openfl::geom::Point_obj::__alloc( HX_CTX ,(rect->x + 2),(rect->y + 2)),null(),null(),null());
            										}
            										else {
HXLINE(  48)											this->rects->push( ::util::Rect_obj::__alloc( HX_CTX ,4096,4096,8,8));
            										}
            									}
            								}
HXLINE(  51)								mirrored = true;
            							}
HXLINE(  54)							continue;
            						}
HXLINE(  57)						int w1;
HXDLIN(  57)						bool w2;
HXDLIN(  57)						if (animChar) {
HXLINE(  57)							w2 = (x == 4);
            						}
            						else {
HXLINE(  57)							w2 = false;
            						}
HXDLIN(  57)						if (w2) {
HXLINE(  57)							w1 = (width * 2);
            						}
            						else {
HXLINE(  57)							w1 = width;
            						}
HXLINE(  58)						 ::openfl::display::BitmapData tex1 = ::util::BitmapUtil_obj::cropToBitmapData(bitmapData,(x * width),(y * height),w1,height);
HXLINE(  59)						this->images->push(tex1);
HXLINE(  61)						if (!(ignoreAtlas)) {
HXLINE(  62)							 ::util::Rect rect1 = ::Main_obj::atlasPacker->insert(( (float)((w1 + 4)) ),( (float)((height + 4)) ));
HXLINE(  63)							this->rects->push(rect1);
HXLINE(  64)							::Main_obj::tempAtlas->copyPixels(tex1, ::openfl::geom::Rectangle_obj::__alloc( HX_CTX ,0,0,rect1->width,rect1->height), ::openfl::geom::Point_obj::__alloc( HX_CTX ,(rect1->x + 2),(rect1->y + 2)),null(),null(),null());
            						}
            						else {
HXLINE(  66)							this->rects->push( ::util::Rect_obj::__alloc( HX_CTX ,4096,4096,8,8));
            						}
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC5(ImageSet_obj,addFromBitmapData,(void))


::hx::ObjectPtr< ImageSet_obj > ImageSet_obj::__new() {
	::hx::ObjectPtr< ImageSet_obj > __this = new ImageSet_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< ImageSet_obj > ImageSet_obj::__alloc(::hx::Ctx *_hx_ctx) {
	ImageSet_obj *__this = (ImageSet_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ImageSet_obj), true, "util.ImageSet"));
	*(void **)__this = ImageSet_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

ImageSet_obj::ImageSet_obj()
{
}

void ImageSet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ImageSet);
	HX_MARK_MEMBER_NAME(images,"images");
	HX_MARK_MEMBER_NAME(rects,"rects");
	HX_MARK_MEMBER_NAME(allowsAtlas,"allowsAtlas");
	HX_MARK_END_CLASS();
}

void ImageSet_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(images,"images");
	HX_VISIT_MEMBER_NAME(rects,"rects");
	HX_VISIT_MEMBER_NAME(allowsAtlas,"allowsAtlas");
}

::hx::Val ImageSet_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"rects") ) { return ::hx::Val( rects ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"images") ) { return ::hx::Val( images ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"allowsAtlas") ) { return ::hx::Val( allowsAtlas ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"addFromBitmapData") ) { return ::hx::Val( addFromBitmapData_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ImageSet_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"rects") ) { rects=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"images") ) { images=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"allowsAtlas") ) { allowsAtlas=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ImageSet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("images",b8,50,92,fe));
	outFields->push(HX_("rects",cf,32,bc,e6));
	outFields->push(HX_("allowsAtlas",21,6d,f8,c7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ImageSet_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(ImageSet_obj,images),HX_("images",b8,50,92,fe)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(ImageSet_obj,rects),HX_("rects",cf,32,bc,e6)},
	{::hx::fsBool,(int)offsetof(ImageSet_obj,allowsAtlas),HX_("allowsAtlas",21,6d,f8,c7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ImageSet_obj_sStaticStorageInfo = 0;
#endif

static ::String ImageSet_obj_sMemberFields[] = {
	HX_("images",b8,50,92,fe),
	HX_("rects",cf,32,bc,e6),
	HX_("allowsAtlas",21,6d,f8,c7),
	HX_("addFromBitmapData",c4,a5,bf,75),
	::String(null()) };

::hx::Class ImageSet_obj::__mClass;

void ImageSet_obj::__register()
{
	ImageSet_obj _hx_dummy;
	ImageSet_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("util.ImageSet",13,31,a8,eb);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ImageSet_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ImageSet_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ImageSet_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ImageSet_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace util
