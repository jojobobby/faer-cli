// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_lime__internal_backend_native_NativeCFFI
#include <lime/_internal/backend/native/NativeCFFI.h>
#endif
#ifndef INCLUDED_lime_graphics_cairo_Cairo
#include <lime/graphics/cairo/Cairo.h>
#endif
#ifndef INCLUDED_lime_graphics_cairo_CairoGlyph
#include <lime/graphics/cairo/CairoGlyph.h>
#endif
#ifndef INCLUDED_lime_math_Matrix3
#include <lime/math/Matrix3.h>
#endif
#ifndef INCLUDED_lime_math_Vector2
#include <lime/math/Vector2.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_47_new,"lime.graphics.cairo.Cairo","new",0x5bfa2aca,"lime.graphics.cairo.Cairo.new","lime/graphics/cairo/Cairo.hx",47,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_58_arc,"lime.graphics.cairo.Cairo","arc",0x5bf058bc,"lime.graphics.cairo.Cairo.arc","lime/graphics/cairo/Cairo.hx",58,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_72_clip,"lime.graphics.cairo.Cairo","clip",0x17ab3126,"lime.graphics.cairo.Cairo.clip","lime/graphics/cairo/Cairo.hx",72,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_93_closePath,"lime.graphics.cairo.Cairo","closePath",0x73e96b67,"lime.graphics.cairo.Cairo.closePath","lime/graphics/cairo/Cairo.hx",93,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_107_curveTo,"lime.graphics.cairo.Cairo","curveTo",0x0ddd3774,"lime.graphics.cairo.Cairo.curveTo","lime/graphics/cairo/Cairo.hx",107,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_114_fill,"lime.graphics.cairo.Cairo","fill",0x19a490d9,"lime.graphics.cairo.Cairo.fill","lime/graphics/cairo/Cairo.hx",114,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_128_fillPreserve,"lime.graphics.cairo.Cairo","fillPreserve",0x37e2b9c5,"lime.graphics.cairo.Cairo.fillPreserve","lime/graphics/cairo/Cairo.hx",128,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_144_identityMatrix,"lime.graphics.cairo.Cairo","identityMatrix",0xb1e7bbf5,"lime.graphics.cairo.Cairo.identityMatrix","lime/graphics/cairo/Cairo.hx",144,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_160_inFill,"lime.graphics.cairo.Cairo","inFill",0x338030de,"lime.graphics.cairo.Cairo.inFill","lime/graphics/cairo/Cairo.hx",160,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_169_inStroke,"lime.graphics.cairo.Cairo","inStroke",0xc49aa2d3,"lime.graphics.cairo.Cairo.inStroke","lime/graphics/cairo/Cairo.hx",169,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_178_lineTo,"lime.graphics.cairo.Cairo","lineTo",0x9ffeca65,"lime.graphics.cairo.Cairo.lineTo","lime/graphics/cairo/Cairo.hx",178,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_199_moveTo,"lime.graphics.cairo.Cairo","moveTo",0x800b56c2,"lime.graphics.cairo.Cairo.moveTo","lime/graphics/cairo/Cairo.hx",199,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_206_newPath,"lime.graphics.cairo.Cairo","newPath",0x3973698f,"lime.graphics.cairo.Cairo.newPath","lime/graphics/cairo/Cairo.hx",206,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_213_paint,"lime.graphics.cairo.Cairo","paint",0x13100088,"lime.graphics.cairo.Cairo.paint","lime/graphics/cairo/Cairo.hx",213,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_220_paintWithAlpha,"lime.graphics.cairo.Cairo","paintWithAlpha",0x79d699d0,"lime.graphics.cairo.Cairo.paintWithAlpha","lime/graphics/cairo/Cairo.hx",220,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_257_recreate,"lime.graphics.cairo.Cairo","recreate",0x8765b845,"lime.graphics.cairo.Cairo.recreate","lime/graphics/cairo/Cairo.hx",257,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_264_rectangle,"lime.graphics.cairo.Cairo","rectangle",0x7945da19,"lime.graphics.cairo.Cairo.rectangle","lime/graphics/cairo/Cairo.hx",264,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_292_resetClip,"lime.graphics.cairo.Cairo","resetClip",0xe7777e29,"lime.graphics.cairo.Cairo.resetClip","lime/graphics/cairo/Cairo.hx",292,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_299_restore,"lime.graphics.cairo.Cairo","restore",0xaa053eb8,"lime.graphics.cairo.Cairo.restore","lime/graphics/cairo/Cairo.hx",299,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_313_save,"lime.graphics.cairo.Cairo","save",0x22364d93,"lime.graphics.cairo.Cairo.save","lime/graphics/cairo/Cairo.hx",313,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_327_setFontSize,"lime.graphics.cairo.Cairo","setFontSize",0xa7b85c5c,"lime.graphics.cairo.Cairo.setFontSize","lime/graphics/cairo/Cairo.hx",327,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_332_setOperator,"lime.graphics.cairo.Cairo","setOperator",0x1d59b9d0,"lime.graphics.cairo.Cairo.setOperator","lime/graphics/cairo/Cairo.hx",332,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_343_setSourceRGB,"lime.graphics.cairo.Cairo","setSourceRGB",0x59e04946,"lime.graphics.cairo.Cairo.setSourceRGB","lime/graphics/cairo/Cairo.hx",343,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_357_setSourceSurface,"lime.graphics.cairo.Cairo","setSourceSurface",0xcd3700e6,"lime.graphics.cairo.Cairo.setSourceSurface","lime/graphics/cairo/Cairo.hx",357,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_370_showGlyphs,"lime.graphics.cairo.Cairo","showGlyphs",0x87e9c4fa,"lime.graphics.cairo.Cairo.showGlyphs","lime/graphics/cairo/Cairo.hx",370,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_400_stroke,"lime.graphics.cairo.Cairo","stroke",0xc493378e,"lime.graphics.cairo.Cairo.stroke","lime/graphics/cairo/Cairo.hx",400,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_414_strokePreserve,"lime.graphics.cairo.Cairo","strokePreserve",0x2f969d7a,"lime.graphics.cairo.Cairo.strokePreserve","lime/graphics/cairo/Cairo.hx",414,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_428_transform,"lime.graphics.cairo.Cairo","transform",0xa55c3356,"lime.graphics.cairo.Cairo.transform","lime/graphics/cairo/Cairo.hx",428,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_435_translate,"lime.graphics.cairo.Cairo","translate",0xa948dd38,"lime.graphics.cairo.Cairo.translate","lime/graphics/cairo/Cairo.hx",435,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_443_get_antialias,"lime.graphics.cairo.Cairo","get_antialias",0x6c40ed6f,"lime.graphics.cairo.Cairo.get_antialias","lime/graphics/cairo/Cairo.hx",443,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_450_set_antialias,"lime.graphics.cairo.Cairo","set_antialias",0xb146cf7b,"lime.graphics.cairo.Cairo.set_antialias","lime/graphics/cairo/Cairo.hx",450,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_459_get_currentPoint,"lime.graphics.cairo.Cairo","get_currentPoint",0x71e87136,"lime.graphics.cairo.Cairo.get_currentPoint","lime/graphics/cairo/Cairo.hx",459,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_526_set_fillRule,"lime.graphics.cairo.Cairo","set_fillRule",0x036c50f2,"lime.graphics.cairo.Cairo.set_fillRule","lime/graphics/cairo/Cairo.hx",526,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_544_set_fontFace,"lime.graphics.cairo.Cairo","set_fontFace",0x5cdab1df,"lime.graphics.cairo.Cairo.set_fontFace","lime/graphics/cairo/Cairo.hx",544,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_562_set_fontOptions,"lime.graphics.cairo.Cairo","set_fontOptions",0x7bf56b5c,"lime.graphics.cairo.Cairo.set_fontOptions","lime/graphics/cairo/Cairo.hx",562,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_582_get_hasCurrentPoint,"lime.graphics.cairo.Cairo","get_hasCurrentPoint",0x7885e152,"lime.graphics.cairo.Cairo.get_hasCurrentPoint","lime/graphics/cairo/Cairo.hx",582,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_598_set_lineCap,"lime.graphics.cairo.Cairo","set_lineCap",0x587dc00b,"lime.graphics.cairo.Cairo.set_lineCap","lime/graphics/cairo/Cairo.hx",598,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_616_set_lineJoin,"lime.graphics.cairo.Cairo","set_lineJoin",0x1a3561d1,"lime.graphics.cairo.Cairo.set_lineJoin","lime/graphics/cairo/Cairo.hx",616,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_634_set_lineWidth,"lime.graphics.cairo.Cairo","set_lineWidth",0x4cbab23f,"lime.graphics.cairo.Cairo.set_lineWidth","lime/graphics/cairo/Cairo.hx",634,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_657_set_matrix,"lime.graphics.cairo.Cairo","set_matrix",0x1fe96b54,"lime.graphics.cairo.Cairo.set_matrix","lime/graphics/cairo/Cairo.hx",657,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_680_set_miterLimit,"lime.graphics.cairo.Cairo","set_miterLimit",0x0a671789,"lime.graphics.cairo.Cairo.set_miterLimit","lime/graphics/cairo/Cairo.hx",680,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_718_set_source,"lime.graphics.cairo.Cairo","set_source",0x9652e5ee,"lime.graphics.cairo.Cairo.set_source","lime/graphics/cairo/Cairo.hx",718,0x0918a4c7)
HX_LOCAL_STACK_FRAME(_hx_pos_cd8fe9e91aca1c90_729_get_target,"lime.graphics.cairo.Cairo","get_target",0xe79089f0,"lime.graphics.cairo.Cairo.get_target","lime/graphics/cairo/Cairo.hx",729,0x0918a4c7)
namespace lime{
namespace graphics{
namespace cairo{

void Cairo_obj::__construct( ::Dynamic surface){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_47_new)
HXDLIN(  47)		if (::hx::IsNotNull( surface )) {
HXLINE(  50)			this->handle = ( ( ::Dynamic)(::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_create(::hx::DynamicPtr(surface))) );
            		}
            	}

Dynamic Cairo_obj::__CreateEmpty() { return new Cairo_obj; }

void *Cairo_obj::_hx_vtable = 0;

Dynamic Cairo_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Cairo_obj > _hx_result = new Cairo_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Cairo_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0bd6c148;
}

void Cairo_obj::arc(Float xc,Float yc,Float radius,Float angle1,Float angle2){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_58_arc)
HXDLIN(  58)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_arc(::hx::DynamicPtr(this->handle),xc,yc,radius,angle1,angle2);
            	}


HX_DEFINE_DYNAMIC_FUNC5(Cairo_obj,arc,(void))

void Cairo_obj::clip(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_72_clip)
HXDLIN(  72)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_clip(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,clip,(void))

void Cairo_obj::closePath(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_93_closePath)
HXDLIN(  93)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_close_path(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,closePath,(void))

void Cairo_obj::curveTo(Float x1,Float y1,Float x2,Float y2,Float x3,Float y3){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_107_curveTo)
HXDLIN( 107)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_curve_to(::hx::DynamicPtr(this->handle),x1,y1,x2,y2,x3,y3);
            	}


HX_DEFINE_DYNAMIC_FUNC6(Cairo_obj,curveTo,(void))

void Cairo_obj::fill(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_114_fill)
HXDLIN( 114)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_fill(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,fill,(void))

void Cairo_obj::fillPreserve(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_128_fillPreserve)
HXDLIN( 128)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_fill_preserve(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,fillPreserve,(void))

void Cairo_obj::identityMatrix(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_144_identityMatrix)
HXDLIN( 144)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_identity_matrix(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,identityMatrix,(void))

bool Cairo_obj::inFill(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_160_inFill)
HXDLIN( 160)		return ::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_in_fill(::hx::DynamicPtr(this->handle),x,y);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Cairo_obj,inFill,return )

bool Cairo_obj::inStroke(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_169_inStroke)
HXDLIN( 169)		return ::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_in_stroke(::hx::DynamicPtr(this->handle),x,y);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Cairo_obj,inStroke,return )

void Cairo_obj::lineTo(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_178_lineTo)
HXDLIN( 178)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_line_to(::hx::DynamicPtr(this->handle),x,y);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Cairo_obj,lineTo,(void))

void Cairo_obj::moveTo(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_199_moveTo)
HXDLIN( 199)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_move_to(::hx::DynamicPtr(this->handle),x,y);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Cairo_obj,moveTo,(void))

void Cairo_obj::newPath(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_206_newPath)
HXDLIN( 206)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_new_path(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,newPath,(void))

void Cairo_obj::paint(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_213_paint)
HXDLIN( 213)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_paint(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,paint,(void))

void Cairo_obj::paintWithAlpha(Float alpha){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_220_paintWithAlpha)
HXDLIN( 220)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_paint_with_alpha(::hx::DynamicPtr(this->handle),alpha);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,paintWithAlpha,(void))

void Cairo_obj::recreate( ::Dynamic surface){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_257_recreate)
HXDLIN( 257)		this->handle = ( ( ::Dynamic)(::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_create(::hx::DynamicPtr(surface))) );
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,recreate,(void))

void Cairo_obj::rectangle(Float x,Float y,Float width,Float height){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_264_rectangle)
HXDLIN( 264)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_rectangle(::hx::DynamicPtr(this->handle),x,y,width,height);
            	}


HX_DEFINE_DYNAMIC_FUNC4(Cairo_obj,rectangle,(void))

void Cairo_obj::resetClip(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_292_resetClip)
HXDLIN( 292)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_reset_clip(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,resetClip,(void))

void Cairo_obj::restore(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_299_restore)
HXDLIN( 299)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_restore(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,restore,(void))

void Cairo_obj::save(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_313_save)
HXDLIN( 313)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_save(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,save,(void))

void Cairo_obj::setFontSize(Float size){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_327_setFontSize)
HXDLIN( 327)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_font_size(::hx::DynamicPtr(this->handle),size);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,setFontSize,(void))

int Cairo_obj::setOperator(int value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_332_setOperator)
HXLINE( 334)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_operator(::hx::DynamicPtr(this->handle),value);
HXLINE( 337)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,setOperator,return )

void Cairo_obj::setSourceRGB(Float r,Float g,Float b){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_343_setSourceRGB)
HXDLIN( 343)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_source_rgb(::hx::DynamicPtr(this->handle),r,g,b);
            	}


HX_DEFINE_DYNAMIC_FUNC3(Cairo_obj,setSourceRGB,(void))

void Cairo_obj::setSourceSurface( ::Dynamic surface,Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_357_setSourceSurface)
HXDLIN( 357)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_source_surface(::hx::DynamicPtr(this->handle),::hx::DynamicPtr(surface),x,y);
            	}


HX_DEFINE_DYNAMIC_FUNC3(Cairo_obj,setSourceSurface,(void))

void Cairo_obj::showGlyphs(::Array< ::Dynamic> glyphs){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_370_showGlyphs)
HXDLIN( 370)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_show_glyphs(::hx::DynamicPtr(this->handle),::hx::DynamicPtr(glyphs));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,showGlyphs,(void))

void Cairo_obj::stroke(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_400_stroke)
HXDLIN( 400)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_stroke(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,stroke,(void))

void Cairo_obj::strokePreserve(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_414_strokePreserve)
HXDLIN( 414)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_stroke_preserve(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,strokePreserve,(void))

void Cairo_obj::transform( ::lime::math::Matrix3 matrix){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_428_transform)
HXDLIN( 428)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_transform(::hx::DynamicPtr(this->handle),::hx::DynamicPtr(matrix));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,transform,(void))

void Cairo_obj::translate(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_435_translate)
HXDLIN( 435)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_translate(::hx::DynamicPtr(this->handle),x,y);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Cairo_obj,translate,(void))

int Cairo_obj::get_antialias(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_443_get_antialias)
HXDLIN( 443)		return ::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_get_antialias(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,get_antialias,return )

int Cairo_obj::set_antialias(int value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_450_set_antialias)
HXLINE( 452)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_antialias(::hx::DynamicPtr(this->handle),value);
HXLINE( 455)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_antialias,return )

 ::lime::math::Vector2 Cairo_obj::get_currentPoint(){
            	HX_GC_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_459_get_currentPoint)
HXLINE( 464)		 ::Dynamic vec = ( ( ::Dynamic)(::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_get_current_point(::hx::DynamicPtr(this->handle))) );
HXLINE( 465)		return  ::lime::math::Vector2_obj::__alloc( HX_CTX ,vec->__Field(HX_("x",78,00,00,00),::hx::paccDynamic),vec->__Field(HX_("y",79,00,00,00),::hx::paccDynamic));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,get_currentPoint,return )

int Cairo_obj::set_fillRule(int value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_526_set_fillRule)
HXLINE( 528)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_fill_rule(::hx::DynamicPtr(this->handle),value);
HXLINE( 531)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_fillRule,return )

 ::Dynamic Cairo_obj::set_fontFace( ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_544_set_fontFace)
HXLINE( 546)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_font_face(::hx::DynamicPtr(this->handle),::hx::DynamicPtr(value));
HXLINE( 549)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_fontFace,return )

 ::Dynamic Cairo_obj::set_fontOptions( ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_562_set_fontOptions)
HXLINE( 564)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_font_options(::hx::DynamicPtr(this->handle),::hx::DynamicPtr(value));
HXLINE( 567)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_fontOptions,return )

bool Cairo_obj::get_hasCurrentPoint(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_582_get_hasCurrentPoint)
HXDLIN( 582)		return ::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_has_current_point(::hx::DynamicPtr(this->handle));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,get_hasCurrentPoint,return )

int Cairo_obj::set_lineCap(int value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_598_set_lineCap)
HXLINE( 600)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_line_cap(::hx::DynamicPtr(this->handle),value);
HXLINE( 603)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_lineCap,return )

int Cairo_obj::set_lineJoin(int value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_616_set_lineJoin)
HXLINE( 618)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_line_join(::hx::DynamicPtr(this->handle),value);
HXLINE( 621)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_lineJoin,return )

Float Cairo_obj::set_lineWidth(Float value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_634_set_lineWidth)
HXLINE( 636)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_line_width(::hx::DynamicPtr(this->handle),value);
HXLINE( 639)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_lineWidth,return )

 ::lime::math::Matrix3 Cairo_obj::set_matrix( ::lime::math::Matrix3 value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_657_set_matrix)
HXLINE( 662)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_matrix(::hx::DynamicPtr(this->handle),value->a,value->b,value->c,value->d,value->tx,value->ty);
HXLINE( 667)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_matrix,return )

Float Cairo_obj::set_miterLimit(Float value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_680_set_miterLimit)
HXLINE( 682)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_miter_limit(::hx::DynamicPtr(this->handle),value);
HXLINE( 685)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_miterLimit,return )

 ::Dynamic Cairo_obj::set_source( ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_718_set_source)
HXLINE( 720)		::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_set_source(::hx::DynamicPtr(this->handle),::hx::DynamicPtr(value));
HXLINE( 723)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Cairo_obj,set_source,return )

 ::Dynamic Cairo_obj::get_target(){
            	HX_STACKFRAME(&_hx_pos_cd8fe9e91aca1c90_729_get_target)
HXDLIN( 729)		return ( ( ::Dynamic)(::lime::_internal::backend::native::NativeCFFI_obj::lime_cairo_get_target(::hx::DynamicPtr(this->handle))) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Cairo_obj,get_target,return )


::hx::ObjectPtr< Cairo_obj > Cairo_obj::__new( ::Dynamic surface) {
	::hx::ObjectPtr< Cairo_obj > __this = new Cairo_obj();
	__this->__construct(surface);
	return __this;
}

::hx::ObjectPtr< Cairo_obj > Cairo_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic surface) {
	Cairo_obj *__this = (Cairo_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Cairo_obj), true, "lime.graphics.cairo.Cairo"));
	*(void **)__this = Cairo_obj::_hx_vtable;
	__this->__construct(surface);
	return __this;
}

Cairo_obj::Cairo_obj()
{
}

void Cairo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Cairo);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(handle,"handle");
	HX_MARK_END_CLASS();
}

void Cairo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(handle,"handle");
}

::hx::Val Cairo_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"arc") ) { return ::hx::Val( arc_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"clip") ) { return ::hx::Val( clip_dyn() ); }
		if (HX_FIELD_EQ(inName,"fill") ) { return ::hx::Val( fill_dyn() ); }
		if (HX_FIELD_EQ(inName,"save") ) { return ::hx::Val( save_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"paint") ) { return ::hx::Val( paint_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return ::hx::Val( inCallProp == ::hx::paccAlways ? get_target() : target ); }
		if (HX_FIELD_EQ(inName,"handle") ) { return ::hx::Val( handle ); }
		if (HX_FIELD_EQ(inName,"inFill") ) { return ::hx::Val( inFill_dyn() ); }
		if (HX_FIELD_EQ(inName,"lineTo") ) { return ::hx::Val( lineTo_dyn() ); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return ::hx::Val( moveTo_dyn() ); }
		if (HX_FIELD_EQ(inName,"stroke") ) { return ::hx::Val( stroke_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"curveTo") ) { return ::hx::Val( curveTo_dyn() ); }
		if (HX_FIELD_EQ(inName,"newPath") ) { return ::hx::Val( newPath_dyn() ); }
		if (HX_FIELD_EQ(inName,"restore") ) { return ::hx::Val( restore_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"inStroke") ) { return ::hx::Val( inStroke_dyn() ); }
		if (HX_FIELD_EQ(inName,"recreate") ) { return ::hx::Val( recreate_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"antialias") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_antialias() ); }
		if (HX_FIELD_EQ(inName,"closePath") ) { return ::hx::Val( closePath_dyn() ); }
		if (HX_FIELD_EQ(inName,"rectangle") ) { return ::hx::Val( rectangle_dyn() ); }
		if (HX_FIELD_EQ(inName,"resetClip") ) { return ::hx::Val( resetClip_dyn() ); }
		if (HX_FIELD_EQ(inName,"transform") ) { return ::hx::Val( transform_dyn() ); }
		if (HX_FIELD_EQ(inName,"translate") ) { return ::hx::Val( translate_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"showGlyphs") ) { return ::hx::Val( showGlyphs_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_matrix") ) { return ::hx::Val( set_matrix_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_source") ) { return ::hx::Val( set_source_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_target") ) { return ::hx::Val( get_target_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setFontSize") ) { return ::hx::Val( setFontSize_dyn() ); }
		if (HX_FIELD_EQ(inName,"setOperator") ) { return ::hx::Val( setOperator_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_lineCap") ) { return ::hx::Val( set_lineCap_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentPoint") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_currentPoint() ); }
		if (HX_FIELD_EQ(inName,"fillPreserve") ) { return ::hx::Val( fillPreserve_dyn() ); }
		if (HX_FIELD_EQ(inName,"setSourceRGB") ) { return ::hx::Val( setSourceRGB_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_fillRule") ) { return ::hx::Val( set_fillRule_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_fontFace") ) { return ::hx::Val( set_fontFace_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_lineJoin") ) { return ::hx::Val( set_lineJoin_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_antialias") ) { return ::hx::Val( get_antialias_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_antialias") ) { return ::hx::Val( set_antialias_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_lineWidth") ) { return ::hx::Val( set_lineWidth_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"identityMatrix") ) { return ::hx::Val( identityMatrix_dyn() ); }
		if (HX_FIELD_EQ(inName,"paintWithAlpha") ) { return ::hx::Val( paintWithAlpha_dyn() ); }
		if (HX_FIELD_EQ(inName,"strokePreserve") ) { return ::hx::Val( strokePreserve_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_miterLimit") ) { return ::hx::Val( set_miterLimit_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"hasCurrentPoint") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_hasCurrentPoint() ); }
		if (HX_FIELD_EQ(inName,"set_fontOptions") ) { return ::hx::Val( set_fontOptions_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setSourceSurface") ) { return ::hx::Val( setSourceSurface_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_currentPoint") ) { return ::hx::Val( get_currentPoint_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_hasCurrentPoint") ) { return ::hx::Val( get_hasCurrentPoint_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Cairo_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast<  ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"handle") ) { handle=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"antialias") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_antialias(inValue.Cast< int >()) ); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Cairo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("antialias",ae,d6,e9,75));
	outFields->push(HX_("currentPoint",57,99,9b,0d));
	outFields->push(HX_("hasCurrentPoint",d1,c3,0b,75));
	outFields->push(HX_("target",51,f3,ec,86));
	outFields->push(HX_("handle",a8,83,fd,b7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Cairo_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Cairo_obj,target),HX_("target",51,f3,ec,86)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Cairo_obj,handle),HX_("handle",a8,83,fd,b7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Cairo_obj_sStaticStorageInfo = 0;
#endif

static ::String Cairo_obj_sMemberFields[] = {
	HX_("target",51,f3,ec,86),
	HX_("handle",a8,83,fd,b7),
	HX_("arc",52,fe,49,00),
	HX_("clip",d0,6e,c2,41),
	HX_("closePath",7d,65,20,14),
	HX_("curveTo",0a,60,88,ce),
	HX_("fill",83,ce,bb,43),
	HX_("fillPreserve",6f,b1,4e,6b),
	HX_("identityMatrix",1f,72,00,92),
	HX_("inFill",08,ad,21,80),
	HX_("inStroke",7d,fd,b2,99),
	HX_("lineTo",8f,46,a0,ec),
	HX_("moveTo",ec,d2,ac,cc),
	HX_("newPath",25,92,1e,fa),
	HX_("paint",9e,b7,4e,bd),
	HX_("paintWithAlpha",fa,4f,ef,59),
	HX_("recreate",ef,12,7e,5c),
	HX_("rectangle",2f,d4,7c,19),
	HX_("resetClip",3f,78,ae,87),
	HX_("restore",4e,67,b0,6a),
	HX_("save",3d,8b,4d,4c),
	HX_("setFontSize",f2,87,32,ff),
	HX_("setOperator",66,e5,d3,74),
	HX_("setSourceRGB",f0,40,4c,8d),
	HX_("setSourceSurface",90,15,89,6d),
	HX_("showGlyphs",24,9e,cd,17),
	HX_("stroke",b8,b3,34,11),
	HX_("strokePreserve",a4,53,af,0f),
	HX_("transform",6c,2d,93,45),
	HX_("translate",4e,d7,7f,49),
	HX_("get_antialias",85,aa,4d,37),
	HX_("set_antialias",91,8c,53,7c),
	HX_("get_currentPoint",e0,85,3a,12),
	HX_("set_fillRule",9c,48,d8,36),
	HX_("set_fontFace",89,a9,46,90),
	HX_("set_fontOptions",f2,19,7c,b1),
	HX_("get_hasCurrentPoint",e8,92,16,00),
	HX_("set_lineCap",a1,eb,f7,af),
	HX_("set_lineJoin",7b,59,a1,4d),
	HX_("set_lineWidth",55,6f,c7,17),
	HX_("set_matrix",7e,44,cd,af),
	HX_("set_miterLimit",b3,cd,7f,ea),
	HX_("set_source",18,bf,36,26),
	HX_("get_target",1a,63,74,77),
	::String(null()) };

::hx::Class Cairo_obj::__mClass;

void Cairo_obj::__register()
{
	Cairo_obj _hx_dummy;
	Cairo_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.cairo.Cairo",d8,bd,0e,04);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Cairo_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Cairo_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Cairo_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Cairo_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace cairo
