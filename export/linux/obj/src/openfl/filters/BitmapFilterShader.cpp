// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_display_Shader
#include <openfl/display/Shader.h>
#endif
#ifndef INCLUDED_openfl_display_ShaderInput_openfl_display_BitmapData
#include <openfl/display/ShaderInput_openfl_display_BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_ShaderParameter_Float
#include <openfl/display/ShaderParameter_Float.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilterShader
#include <openfl/filters/BitmapFilterShader.h>
#endif
#ifndef INCLUDED_openfl_utils_ByteArrayData
#include <openfl/utils/ByteArrayData.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataInput
#include <openfl/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl_utils_IDataOutput
#include <openfl/utils/IDataOutput.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_064cc14bbb4441a0_54_new,"openfl.filters.BitmapFilterShader","new",0xcb76b60f,"openfl.filters.BitmapFilterShader.new","openfl/filters/BitmapFilterShader.hx",54,0x7f5a8bff)
namespace openfl{
namespace filters{

void BitmapFilterShader_obj::__construct( ::openfl::utils::ByteArrayData code){
            	HX_STACKFRAME(&_hx_pos_064cc14bbb4441a0_54_new)
HXLINE( 182)		if (::hx::IsNull( this->_hx___glFragmentSource )) {
HXLINE( 184)			this->_hx___glFragmentSource = HX_("varying vec2 openfl_TextureCoordv;\n\n\t\tuniform sampler2D openfl_Texture;\n\t\tuniform vec2 openfl_TextureSize;\n\n\t\tvoid main(void) {\n\n\t\t\tgl_FragColor = texture2D (openfl_Texture, openfl_TextureCoordv);\n\n\t\t}",58,83,67,fa);
            		}
HXLINE( 174)		if (::hx::IsNull( this->_hx___glVertexSource )) {
HXLINE( 176)			this->_hx___glVertexSource = HX_("attribute vec4 openfl_Position;\n\t\tattribute vec2 openfl_TextureCoord;\n\n\t\tvarying vec2 openfl_TextureCoordv;\n\n\t\tuniform mat4 openfl_Matrix;\n\t\tuniform vec2 openfl_TextureSize;\n\n\t\tvoid main(void) {\n\n\t\t\topenfl_TextureCoordv = openfl_TextureCoord;\n\n\t\tgl_Position = openfl_Matrix * openfl_Position;\n\n\t\t}",80,8f,c4,dd);
            		}
HXLINE(  55)		super::__construct(code);
HXLINE(  10)		this->_hx___isGenerated = true;
HXDLIN(  10)		this->_hx___initGL();
            	}

Dynamic BitmapFilterShader_obj::__CreateEmpty() { return new BitmapFilterShader_obj; }

void *BitmapFilterShader_obj::_hx_vtable = 0;

Dynamic BitmapFilterShader_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BitmapFilterShader_obj > _hx_result = new BitmapFilterShader_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool BitmapFilterShader_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x253b4db3) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x253b4db3;
	} else {
		return inClassId==(int)0x78d8d737;
	}
}


::hx::ObjectPtr< BitmapFilterShader_obj > BitmapFilterShader_obj::__new( ::openfl::utils::ByteArrayData code) {
	::hx::ObjectPtr< BitmapFilterShader_obj > __this = new BitmapFilterShader_obj();
	__this->__construct(code);
	return __this;
}

::hx::ObjectPtr< BitmapFilterShader_obj > BitmapFilterShader_obj::__alloc(::hx::Ctx *_hx_ctx, ::openfl::utils::ByteArrayData code) {
	BitmapFilterShader_obj *__this = (BitmapFilterShader_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BitmapFilterShader_obj), true, "openfl.filters.BitmapFilterShader"));
	*(void **)__this = BitmapFilterShader_obj::_hx_vtable;
	__this->__construct(code);
	return __this;
}

BitmapFilterShader_obj::BitmapFilterShader_obj()
{
}

void BitmapFilterShader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapFilterShader);
	HX_MARK_MEMBER_NAME(openfl_Position,"openfl_Position");
	HX_MARK_MEMBER_NAME(openfl_TextureCoord,"openfl_TextureCoord");
	HX_MARK_MEMBER_NAME(openfl_Matrix,"openfl_Matrix");
	HX_MARK_MEMBER_NAME(openfl_TextureSize,"openfl_TextureSize");
	HX_MARK_MEMBER_NAME(openfl_Texture,"openfl_Texture");
	 ::openfl::display::Shader_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BitmapFilterShader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(openfl_Position,"openfl_Position");
	HX_VISIT_MEMBER_NAME(openfl_TextureCoord,"openfl_TextureCoord");
	HX_VISIT_MEMBER_NAME(openfl_Matrix,"openfl_Matrix");
	HX_VISIT_MEMBER_NAME(openfl_TextureSize,"openfl_TextureSize");
	HX_VISIT_MEMBER_NAME(openfl_Texture,"openfl_Texture");
	 ::openfl::display::Shader_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val BitmapFilterShader_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"openfl_Matrix") ) { return ::hx::Val( openfl_Matrix ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"openfl_Texture") ) { return ::hx::Val( openfl_Texture ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"openfl_Position") ) { return ::hx::Val( openfl_Position ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"openfl_TextureSize") ) { return ::hx::Val( openfl_TextureSize ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"openfl_TextureCoord") ) { return ::hx::Val( openfl_TextureCoord ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val BitmapFilterShader_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"openfl_Matrix") ) { openfl_Matrix=inValue.Cast<  ::openfl::display::ShaderParameter_Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"openfl_Texture") ) { openfl_Texture=inValue.Cast<  ::openfl::display::ShaderInput_openfl_display_BitmapData >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"openfl_Position") ) { openfl_Position=inValue.Cast<  ::openfl::display::ShaderParameter_Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"openfl_TextureSize") ) { openfl_TextureSize=inValue.Cast<  ::openfl::display::ShaderParameter_Float >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"openfl_TextureCoord") ) { openfl_TextureCoord=inValue.Cast<  ::openfl::display::ShaderParameter_Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapFilterShader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("openfl_Position",98,fe,6c,ee));
	outFields->push(HX_("openfl_TextureCoord",49,e9,27,e8));
	outFields->push(HX_("openfl_Matrix",70,ea,41,06));
	outFields->push(HX_("openfl_TextureSize",ad,60,72,29));
	outFields->push(HX_("openfl_Texture",cc,bd,e4,7e));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo BitmapFilterShader_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Float */ ,(int)offsetof(BitmapFilterShader_obj,openfl_Position),HX_("openfl_Position",98,fe,6c,ee)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Float */ ,(int)offsetof(BitmapFilterShader_obj,openfl_TextureCoord),HX_("openfl_TextureCoord",49,e9,27,e8)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Float */ ,(int)offsetof(BitmapFilterShader_obj,openfl_Matrix),HX_("openfl_Matrix",70,ea,41,06)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Float */ ,(int)offsetof(BitmapFilterShader_obj,openfl_TextureSize),HX_("openfl_TextureSize",ad,60,72,29)},
	{::hx::fsObject /*  ::openfl::display::ShaderInput_openfl_display_BitmapData */ ,(int)offsetof(BitmapFilterShader_obj,openfl_Texture),HX_("openfl_Texture",cc,bd,e4,7e)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *BitmapFilterShader_obj_sStaticStorageInfo = 0;
#endif

static ::String BitmapFilterShader_obj_sMemberFields[] = {
	HX_("openfl_Position",98,fe,6c,ee),
	HX_("openfl_TextureCoord",49,e9,27,e8),
	HX_("openfl_Matrix",70,ea,41,06),
	HX_("openfl_TextureSize",ad,60,72,29),
	HX_("openfl_Texture",cc,bd,e4,7e),
	::String(null()) };

::hx::Class BitmapFilterShader_obj::__mClass;

void BitmapFilterShader_obj::__register()
{
	BitmapFilterShader_obj _hx_dummy;
	BitmapFilterShader_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.filters.BitmapFilterShader",9d,02,29,31);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(BitmapFilterShader_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< BitmapFilterShader_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BitmapFilterShader_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BitmapFilterShader_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace filters
