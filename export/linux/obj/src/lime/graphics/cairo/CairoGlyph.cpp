// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_cairo_CairoGlyph
#include <lime/graphics/cairo/CairoGlyph.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_294e16b65fbd220a_15_new,"lime.graphics.cairo.CairoGlyph","new",0x55c88ba6,"lime.graphics.cairo.CairoGlyph.new","lime/graphics/cairo/CairoGlyph.hx",15,0x7c7a7209)
namespace lime{
namespace graphics{
namespace cairo{

void CairoGlyph_obj::__construct(int index,::hx::Null< Float >  __o_x,::hx::Null< Float >  __o_y){
            		Float x = __o_x.Default(0);
            		Float y = __o_y.Default(0);
            	HX_STACKFRAME(&_hx_pos_294e16b65fbd220a_15_new)
HXLINE(  16)		this->index = index;
HXLINE(  17)		this->x = x;
HXLINE(  18)		this->y = y;
            	}

Dynamic CairoGlyph_obj::__CreateEmpty() { return new CairoGlyph_obj; }

void *CairoGlyph_obj::_hx_vtable = 0;

Dynamic CairoGlyph_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CairoGlyph_obj > _hx_result = new CairoGlyph_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool CairoGlyph_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1ff20744;
}


CairoGlyph_obj::CairoGlyph_obj()
{
}

::hx::Val CairoGlyph_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return ::hx::Val( x ); }
		if (HX_FIELD_EQ(inName,"y") ) { return ::hx::Val( y ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { return ::hx::Val( index ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CairoGlyph_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CairoGlyph_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("index",12,9b,14,be));
	outFields->push(HX_("x",78,00,00,00));
	outFields->push(HX_("y",79,00,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CairoGlyph_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(CairoGlyph_obj,index),HX_("index",12,9b,14,be)},
	{::hx::fsFloat,(int)offsetof(CairoGlyph_obj,x),HX_("x",78,00,00,00)},
	{::hx::fsFloat,(int)offsetof(CairoGlyph_obj,y),HX_("y",79,00,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CairoGlyph_obj_sStaticStorageInfo = 0;
#endif

static ::String CairoGlyph_obj_sMemberFields[] = {
	HX_("index",12,9b,14,be),
	HX_("x",78,00,00,00),
	HX_("y",79,00,00,00),
	::String(null()) };

::hx::Class CairoGlyph_obj::__mClass;

void CairoGlyph_obj::__register()
{
	CairoGlyph_obj _hx_dummy;
	CairoGlyph_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.cairo.CairoGlyph",b4,80,ac,82);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CairoGlyph_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CairoGlyph_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CairoGlyph_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CairoGlyph_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace cairo
