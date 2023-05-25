// Generated by Haxe 4.3.0+731dcd7
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED__Xml_XmlType_Impl_
#include <_Xml/XmlType_Impl_.h>
#endif
#ifndef INCLUDED_appengine_SavedCharacter
#include <appengine/SavedCharacter.h>
#endif
#ifndef INCLUDED_appengine_SavedCharactersList
#include <appengine/SavedCharactersList.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_servers_LatLong
#include <servers/LatLong.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f56609b605db29ab_6_new,"appengine.SavedCharactersList","new",0xae95e116,"appengine.SavedCharactersList.new","appengine/SavedCharactersList.hx",6,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_45_toString,"appengine.SavedCharactersList","toString",0x15a66c36,"appengine.SavedCharactersList.toString","appengine/SavedCharactersList.hx",45,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_48_getCharById,"appengine.SavedCharactersList","getCharById",0x8fe920f4,"appengine.SavedCharactersList.getCharById","appengine/SavedCharactersList.hx",48,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_58_availableCharSlots,"appengine.SavedCharactersList","availableCharSlots",0x03069b00,"appengine.SavedCharactersList.availableCharSlots","appengine/SavedCharactersList.hx",58,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_62_hasAvailableCharSlot,"appengine.SavedCharactersList","hasAvailableCharSlot",0x20b070ad,"appengine.SavedCharactersList.hasAvailableCharSlot","appengine/SavedCharactersList.hx",62,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_65_parseUserData,"appengine.SavedCharactersList","parseUserData",0xa3ee1d9e,"appengine.SavedCharactersList.parseUserData","appengine/SavedCharactersList.hx",65,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_78_parseGuildData,"appengine.SavedCharactersList","parseGuildData",0x4f67a9d4,"appengine.SavedCharactersList.parseGuildData","appengine/SavedCharactersList.hx",78,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_86_parseCharacterData,"appengine.SavedCharactersList","parseCharacterData",0xe7056e4a,"appengine.SavedCharactersList.parseCharacterData","appengine/SavedCharactersList.hx",86,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_98_parseGeoPositioningData,"appengine.SavedCharactersList","parseGeoPositioningData",0x6e68dddb,"appengine.SavedCharactersList.parseGeoPositioningData","appengine/SavedCharactersList.hx",98,0xee0a1bdb)
HX_LOCAL_STACK_FRAME(_hx_pos_f56609b605db29ab_8_boot,"appengine.SavedCharactersList","boot",0x0ca812bc,"appengine.SavedCharactersList.boot","appengine/SavedCharactersList.hx",8,0xee0a1bdb)
namespace appengine{

void SavedCharactersList_obj::__construct( ::Xml data){
            	HX_STACKFRAME(&_hx_pos_f56609b605db29ab_6_new)
HXLINE(  23)		this->isAdmin = false;
HXLINE(  22)		this->name = null();
HXLINE(  21)		this->guildRank = 0;
HXLINE(  20)		this->guildName = HX_("",00,00,00,00);
HXLINE(  19)		this->nextCharSlotCurrency = 0;
HXLINE(  18)		this->nextCharSlotPrice = 0;
HXLINE(  17)		this->crowns = 0;
HXLINE(  16)		this->gold = 0;
HXLINE(  15)		this->gems = 0;
HXLINE(  13)		this->numChars = 0;
HXLINE(  12)		this->maxNumChars = 0;
HXLINE(  11)		this->nextCharId = 0;
HXLINE(  10)		this->accountId = 0;
HXLINE(  30)		this->savedChars = ::Array_obj< ::Dynamic>::__new();
HXLINE(  31)		super::__construct(HX_("SAVED_CHARS_LIST",78,84,35,79),null(),null());
HXLINE(  32)		this->charsXML = data;
HXLINE(  33)		 ::Xml accountXML = ( ( ::Xml)(data->elementsNamed(HX_("Account",8d,24,ab,6e))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  34)		this->parseUserData(accountXML);
HXLINE(  35)		this->parseGuildData(accountXML);
HXLINE(  36)		this->parseCharacterData();
HXLINE(  37)		this->parseGeoPositioningData();
            	}

Dynamic SavedCharactersList_obj::__CreateEmpty() { return new SavedCharactersList_obj; }

void *SavedCharactersList_obj::_hx_vtable = 0;

Dynamic SavedCharactersList_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SavedCharactersList_obj > _hx_result = new SavedCharactersList_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool SavedCharactersList_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x08ec4c31) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x08ec4c31;
	} else {
		return inClassId==(int)0x3e4d32ec;
	}
}

::String SavedCharactersList_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_f56609b605db29ab_45_toString)
HXDLIN(  45)		return (((((HX_("[",5b,00,00,00) + HX_(" numChars: ",3d,27,68,1b)) + this->numChars) + HX_(" maxNumChars: ",c1,6e,b6,50)) + this->maxNumChars) + HX_(" ]",3d,1c,00,00));
            	}


 ::appengine::SavedCharacter SavedCharactersList_obj::getCharById(int id){
            	HX_STACKFRAME(&_hx_pos_f56609b605db29ab_48_getCharById)
HXLINE(  50)		{
HXLINE(  50)			int _g = 0;
HXDLIN(  50)			::Array< ::Dynamic> _g1 = this->savedChars;
HXDLIN(  50)			while((_g < _g1->length)){
HXLINE(  50)				 ::appengine::SavedCharacter savedChar = _g1->__get(_g).StaticCast<  ::appengine::SavedCharacter >();
HXDLIN(  50)				_g = (_g + 1);
HXLINE(  51)				if (::hx::IsEq( savedChar->charId(),id )) {
HXLINE(  52)					return savedChar;
            				}
            			}
            		}
HXLINE(  54)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(SavedCharactersList_obj,getCharById,return )

int SavedCharactersList_obj::availableCharSlots(){
            	HX_STACKFRAME(&_hx_pos_f56609b605db29ab_58_availableCharSlots)
HXDLIN(  58)		return (this->maxNumChars - this->numChars);
            	}


HX_DEFINE_DYNAMIC_FUNC0(SavedCharactersList_obj,availableCharSlots,return )

bool SavedCharactersList_obj::hasAvailableCharSlot(){
            	HX_STACKFRAME(&_hx_pos_f56609b605db29ab_62_hasAvailableCharSlot)
HXDLIN(  62)		return (this->numChars < this->maxNumChars);
            	}


HX_DEFINE_DYNAMIC_FUNC0(SavedCharactersList_obj,hasAvailableCharSlot,return )

void SavedCharactersList_obj::parseUserData( ::Xml accountXML){
            	HX_STACKFRAME(&_hx_pos_f56609b605db29ab_65_parseUserData)
HXLINE(  66)		 ::Xml _this = ( ( ::Xml)(accountXML->elementsNamed(HX_("AccountId",c8,61,27,cb))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  66)		bool _hx_tmp;
HXDLIN(  66)		if ((_this->nodeType != ::Xml_obj::Document)) {
HXLINE(  66)			_hx_tmp = (_this->nodeType != ::Xml_obj::Element);
            		}
            		else {
HXLINE(  66)			_hx_tmp = false;
            		}
HXDLIN(  66)		if (_hx_tmp) {
HXLINE(  66)			HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this->nodeType)));
            		}
HXDLIN(  66)		 ::Xml _this1 = _this->children->__get(0).StaticCast<  ::Xml >();
HXDLIN(  66)		bool _hx_tmp1;
HXDLIN(  66)		if ((_this1->nodeType != ::Xml_obj::Document)) {
HXLINE(  66)			_hx_tmp1 = (_this1->nodeType == ::Xml_obj::Element);
            		}
            		else {
HXLINE(  66)			_hx_tmp1 = true;
            		}
HXDLIN(  66)		if (_hx_tmp1) {
HXLINE(  66)			HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this1->nodeType)));
            		}
HXDLIN(  66)		this->accountId = ( (int)(::Std_obj::parseInt(_this1->nodeValue)) );
HXLINE(  67)		 ::Xml _this2 = ( ( ::Xml)(accountXML->elementsNamed(HX_("Name",6b,9e,d8,33))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  67)		bool _hx_tmp2;
HXDLIN(  67)		if ((_this2->nodeType != ::Xml_obj::Document)) {
HXLINE(  67)			_hx_tmp2 = (_this2->nodeType != ::Xml_obj::Element);
            		}
            		else {
HXLINE(  67)			_hx_tmp2 = false;
            		}
HXDLIN(  67)		if (_hx_tmp2) {
HXLINE(  67)			HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this2->nodeType)));
            		}
HXDLIN(  67)		 ::Xml _this3 = _this2->children->__get(0).StaticCast<  ::Xml >();
HXDLIN(  67)		bool _hx_tmp3;
HXDLIN(  67)		if ((_this3->nodeType != ::Xml_obj::Document)) {
HXLINE(  67)			_hx_tmp3 = (_this3->nodeType == ::Xml_obj::Element);
            		}
            		else {
HXLINE(  67)			_hx_tmp3 = true;
            		}
HXDLIN(  67)		if (_hx_tmp3) {
HXLINE(  67)			HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this3->nodeType)));
            		}
HXDLIN(  67)		this->name = _this3->nodeValue;
HXLINE(  68)		this->isAdmin = ( (bool)(accountXML->elementsNamed(HX_("Admin",6f,1c,78,af))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) );
            	}


HX_DEFINE_DYNAMIC_FUNC1(SavedCharactersList_obj,parseUserData,(void))

void SavedCharactersList_obj::parseGuildData( ::Xml accountXML){
            	HX_STACKFRAME(&_hx_pos_f56609b605db29ab_78_parseGuildData)
HXDLIN(  78)		bool _hx_tmp;
HXDLIN(  78)		bool _hx_tmp1;
HXDLIN(  78)		if (( (bool)(accountXML->elementsNamed(HX_("Guild",93,31,19,2f))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXDLIN(  78)			_hx_tmp1 = ( (bool)(( ( ::Xml)(accountXML->elementsNamed(HX_("Guild",93,31,19,2f))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) )->elementsNamed(HX_("Name",6b,9e,d8,33))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) );
            		}
            		else {
HXDLIN(  78)			_hx_tmp1 = false;
            		}
HXDLIN(  78)		if (_hx_tmp1) {
HXLINE(  80)			 ::Xml _this = ( ( ::Xml)(( ( ::Xml)(accountXML->elementsNamed(HX_("Guild",93,31,19,2f))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) )->elementsNamed(HX_("Name",6b,9e,d8,33))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  80)			bool _hx_tmp2;
HXDLIN(  80)			if ((_this->nodeType != ::Xml_obj::Document)) {
HXLINE(  80)				_hx_tmp2 = (_this->nodeType != ::Xml_obj::Element);
            			}
            			else {
HXLINE(  80)				_hx_tmp2 = false;
            			}
HXDLIN(  80)			if (_hx_tmp2) {
HXLINE(  80)				HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this->nodeType)));
            			}
HXLINE(  78)			_hx_tmp = ::hx::IsNotNull( _this->children->__get(0).StaticCast<  ::Xml >() );
            		}
            		else {
HXDLIN(  78)			_hx_tmp = false;
            		}
HXDLIN(  78)		if (_hx_tmp) {
HXLINE(  81)			 ::Xml _this1 = ( ( ::Xml)(( ( ::Xml)(accountXML->elementsNamed(HX_("Guild",93,31,19,2f))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) )->elementsNamed(HX_("Name",6b,9e,d8,33))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  81)			bool _hx_tmp3;
HXDLIN(  81)			if ((_this1->nodeType != ::Xml_obj::Document)) {
HXLINE(  81)				_hx_tmp3 = (_this1->nodeType != ::Xml_obj::Element);
            			}
            			else {
HXLINE(  81)				_hx_tmp3 = false;
            			}
HXDLIN(  81)			if (_hx_tmp3) {
HXLINE(  81)				HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this1->nodeType)));
            			}
HXDLIN(  81)			 ::Xml _this2 = _this1->children->__get(0).StaticCast<  ::Xml >();
HXDLIN(  81)			bool _hx_tmp4;
HXDLIN(  81)			if ((_this2->nodeType != ::Xml_obj::Document)) {
HXLINE(  81)				_hx_tmp4 = (_this2->nodeType == ::Xml_obj::Element);
            			}
            			else {
HXLINE(  81)				_hx_tmp4 = true;
            			}
HXDLIN(  81)			if (_hx_tmp4) {
HXLINE(  81)				HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this2->nodeType)));
            			}
HXDLIN(  81)			this->guildName = _this2->nodeValue;
HXLINE(  82)			 ::Xml _this3 = ( ( ::Xml)(( ( ::Xml)(accountXML->elementsNamed(HX_("Guild",93,31,19,2f))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) )->elementsNamed(HX_("Rank",cc,79,7d,36))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  82)			bool _hx_tmp5;
HXDLIN(  82)			if ((_this3->nodeType != ::Xml_obj::Document)) {
HXLINE(  82)				_hx_tmp5 = (_this3->nodeType != ::Xml_obj::Element);
            			}
            			else {
HXLINE(  82)				_hx_tmp5 = false;
            			}
HXDLIN(  82)			if (_hx_tmp5) {
HXLINE(  82)				HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this3->nodeType)));
            			}
HXDLIN(  82)			 ::Xml _this4 = _this3->children->__get(0).StaticCast<  ::Xml >();
HXDLIN(  82)			bool _hx_tmp6;
HXDLIN(  82)			if ((_this4->nodeType != ::Xml_obj::Document)) {
HXLINE(  82)				_hx_tmp6 = (_this4->nodeType == ::Xml_obj::Element);
            			}
            			else {
HXLINE(  82)				_hx_tmp6 = true;
            			}
HXDLIN(  82)			if (_hx_tmp6) {
HXLINE(  82)				HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this4->nodeType)));
            			}
HXDLIN(  82)			this->guildRank = ( (int)(::Std_obj::parseInt(_this4->nodeValue)) );
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(SavedCharactersList_obj,parseGuildData,(void))

void SavedCharactersList_obj::parseCharacterData(){
            	HX_GC_STACKFRAME(&_hx_pos_f56609b605db29ab_86_parseCharacterData)
HXLINE(  87)		this->nextCharId = ( (int)(::Std_obj::parseInt(this->charsXML->get(HX_("nextCharId",a4,31,a7,6c)))) );
HXLINE(  88)		this->maxNumChars = ( (int)(::Std_obj::parseInt(this->charsXML->get(HX_("maxNumChars",7b,bb,89,78)))) );
HXLINE(  89)		{
HXLINE(  89)			 ::Dynamic charXML = this->charsXML->elementsNamed(HX_("Char",f6,8a,98,2c));
HXDLIN(  89)			while(( (bool)(charXML->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  89)				 ::Xml charXML1 = ( ( ::Xml)(charXML->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  90)				this->savedChars->push( ::appengine::SavedCharacter_obj::__alloc( HX_CTX ,charXML1,this->name));
HXLINE(  91)				this->numChars++;
            			}
            		}
HXLINE(  94)		this->savedChars->sort(::appengine::SavedCharacter_obj::compare_dyn());
            	}


HX_DEFINE_DYNAMIC_FUNC0(SavedCharactersList_obj,parseCharacterData,(void))

void SavedCharactersList_obj::parseGeoPositioningData(){
            	HX_GC_STACKFRAME(&_hx_pos_f56609b605db29ab_98_parseGeoPositioningData)
HXDLIN(  98)		bool _hx_tmp;
HXDLIN(  98)		if (( (bool)(this->charsXML->elementsNamed(HX_("Lat",3f,00,3a,00))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )) {
HXDLIN(  98)			_hx_tmp = ( (bool)(this->charsXML->elementsNamed(HX_("Long",9c,d1,90,32))->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) );
            		}
            		else {
HXDLIN(  98)			_hx_tmp = false;
            		}
HXDLIN(  98)		if (_hx_tmp) {
HXLINE(  99)			 ::Xml _this = ( ( ::Xml)(this->charsXML->elementsNamed(HX_("Lat",3f,00,3a,00))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  99)			bool _hx_tmp1;
HXDLIN(  99)			if ((_this->nodeType != ::Xml_obj::Document)) {
HXLINE(  99)				_hx_tmp1 = (_this->nodeType != ::Xml_obj::Element);
            			}
            			else {
HXLINE(  99)				_hx_tmp1 = false;
            			}
HXDLIN(  99)			if (_hx_tmp1) {
HXLINE(  99)				HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this->nodeType)));
            			}
HXDLIN(  99)			 ::Xml _this1 = _this->children->__get(0).StaticCast<  ::Xml >();
HXDLIN(  99)			bool _hx_tmp2;
HXDLIN(  99)			if ((_this1->nodeType != ::Xml_obj::Document)) {
HXLINE(  99)				_hx_tmp2 = (_this1->nodeType == ::Xml_obj::Element);
            			}
            			else {
HXLINE(  99)				_hx_tmp2 = true;
            			}
HXDLIN(  99)			if (_hx_tmp2) {
HXLINE(  99)				HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this1->nodeType)));
            			}
HXDLIN(  99)			Float _hx_tmp3 = ::Std_obj::parseFloat(_this1->nodeValue);
HXLINE( 100)			 ::Xml _this2 = ( ( ::Xml)(this->charsXML->elementsNamed(HX_("Long",9c,d1,90,32))->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 100)			bool _hx_tmp4;
HXDLIN( 100)			if ((_this2->nodeType != ::Xml_obj::Document)) {
HXLINE( 100)				_hx_tmp4 = (_this2->nodeType != ::Xml_obj::Element);
            			}
            			else {
HXLINE( 100)				_hx_tmp4 = false;
            			}
HXDLIN( 100)			if (_hx_tmp4) {
HXLINE( 100)				HX_STACK_DO_THROW((HX_("Bad node type, expected Element or Document but found ",a0,d6,ba,79) + ::_Xml::XmlType_Impl__obj::toString(_this2->nodeType)));
            			}
HXDLIN( 100)			 ::Xml _this3 = _this2->children->__get(0).StaticCast<  ::Xml >();
HXDLIN( 100)			bool _hx_tmp5;
HXDLIN( 100)			if ((_this3->nodeType != ::Xml_obj::Document)) {
HXLINE( 100)				_hx_tmp5 = (_this3->nodeType == ::Xml_obj::Element);
            			}
            			else {
HXLINE( 100)				_hx_tmp5 = true;
            			}
HXDLIN( 100)			if (_hx_tmp5) {
HXLINE( 100)				HX_STACK_DO_THROW((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(_this3->nodeType)));
            			}
HXLINE(  99)			this->myPos =  ::servers::LatLong_obj::__alloc( HX_CTX ,_hx_tmp3,::Std_obj::parseFloat(_this3->nodeValue));
            		}
            		else {
HXLINE( 102)			this->myPos = ::appengine::SavedCharactersList_obj::DEFAULT_LATLONG;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(SavedCharactersList_obj,parseGeoPositioningData,(void))

 ::servers::LatLong SavedCharactersList_obj::DEFAULT_LATLONG;


::hx::ObjectPtr< SavedCharactersList_obj > SavedCharactersList_obj::__new( ::Xml data) {
	::hx::ObjectPtr< SavedCharactersList_obj > __this = new SavedCharactersList_obj();
	__this->__construct(data);
	return __this;
}

::hx::ObjectPtr< SavedCharactersList_obj > SavedCharactersList_obj::__alloc(::hx::Ctx *_hx_ctx, ::Xml data) {
	SavedCharactersList_obj *__this = (SavedCharactersList_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SavedCharactersList_obj), true, "appengine.SavedCharactersList"));
	*(void **)__this = SavedCharactersList_obj::_hx_vtable;
	__this->__construct(data);
	return __this;
}

SavedCharactersList_obj::SavedCharactersList_obj()
{
}

void SavedCharactersList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SavedCharactersList);
	HX_MARK_MEMBER_NAME(accountId,"accountId");
	HX_MARK_MEMBER_NAME(nextCharId,"nextCharId");
	HX_MARK_MEMBER_NAME(maxNumChars,"maxNumChars");
	HX_MARK_MEMBER_NAME(numChars,"numChars");
	HX_MARK_MEMBER_NAME(savedChars,"savedChars");
	HX_MARK_MEMBER_NAME(gems,"gems");
	HX_MARK_MEMBER_NAME(gold,"gold");
	HX_MARK_MEMBER_NAME(crowns,"crowns");
	HX_MARK_MEMBER_NAME(nextCharSlotPrice,"nextCharSlotPrice");
	HX_MARK_MEMBER_NAME(nextCharSlotCurrency,"nextCharSlotCurrency");
	HX_MARK_MEMBER_NAME(guildName,"guildName");
	HX_MARK_MEMBER_NAME(guildRank,"guildRank");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(isAdmin,"isAdmin");
	HX_MARK_MEMBER_NAME(myPos,"myPos");
	HX_MARK_MEMBER_NAME(charsXML,"charsXML");
	 ::openfl::events::Event_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SavedCharactersList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accountId,"accountId");
	HX_VISIT_MEMBER_NAME(nextCharId,"nextCharId");
	HX_VISIT_MEMBER_NAME(maxNumChars,"maxNumChars");
	HX_VISIT_MEMBER_NAME(numChars,"numChars");
	HX_VISIT_MEMBER_NAME(savedChars,"savedChars");
	HX_VISIT_MEMBER_NAME(gems,"gems");
	HX_VISIT_MEMBER_NAME(gold,"gold");
	HX_VISIT_MEMBER_NAME(crowns,"crowns");
	HX_VISIT_MEMBER_NAME(nextCharSlotPrice,"nextCharSlotPrice");
	HX_VISIT_MEMBER_NAME(nextCharSlotCurrency,"nextCharSlotCurrency");
	HX_VISIT_MEMBER_NAME(guildName,"guildName");
	HX_VISIT_MEMBER_NAME(guildRank,"guildRank");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(isAdmin,"isAdmin");
	HX_VISIT_MEMBER_NAME(myPos,"myPos");
	HX_VISIT_MEMBER_NAME(charsXML,"charsXML");
	 ::openfl::events::Event_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val SavedCharactersList_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"gems") ) { return ::hx::Val( gems ); }
		if (HX_FIELD_EQ(inName,"gold") ) { return ::hx::Val( gold ); }
		if (HX_FIELD_EQ(inName,"name") ) { return ::hx::Val( name ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"myPos") ) { return ::hx::Val( myPos ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"crowns") ) { return ::hx::Val( crowns ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isAdmin") ) { return ::hx::Val( isAdmin ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"numChars") ) { return ::hx::Val( numChars ); }
		if (HX_FIELD_EQ(inName,"charsXML") ) { return ::hx::Val( charsXML ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"accountId") ) { return ::hx::Val( accountId ); }
		if (HX_FIELD_EQ(inName,"guildName") ) { return ::hx::Val( guildName ); }
		if (HX_FIELD_EQ(inName,"guildRank") ) { return ::hx::Val( guildRank ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nextCharId") ) { return ::hx::Val( nextCharId ); }
		if (HX_FIELD_EQ(inName,"savedChars") ) { return ::hx::Val( savedChars ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxNumChars") ) { return ::hx::Val( maxNumChars ); }
		if (HX_FIELD_EQ(inName,"getCharById") ) { return ::hx::Val( getCharById_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"parseUserData") ) { return ::hx::Val( parseUserData_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"parseGuildData") ) { return ::hx::Val( parseGuildData_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nextCharSlotPrice") ) { return ::hx::Val( nextCharSlotPrice ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"availableCharSlots") ) { return ::hx::Val( availableCharSlots_dyn() ); }
		if (HX_FIELD_EQ(inName,"parseCharacterData") ) { return ::hx::Val( parseCharacterData_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nextCharSlotCurrency") ) { return ::hx::Val( nextCharSlotCurrency ); }
		if (HX_FIELD_EQ(inName,"hasAvailableCharSlot") ) { return ::hx::Val( hasAvailableCharSlot_dyn() ); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"parseGeoPositioningData") ) { return ::hx::Val( parseGeoPositioningData_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool SavedCharactersList_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"DEFAULT_LATLONG") ) { outValue = ( DEFAULT_LATLONG ); return true; }
	}
	return false;
}

::hx::Val SavedCharactersList_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"gems") ) { gems=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gold") ) { gold=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"myPos") ) { myPos=inValue.Cast<  ::servers::LatLong >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"crowns") ) { crowns=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isAdmin") ) { isAdmin=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"numChars") ) { numChars=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"charsXML") ) { charsXML=inValue.Cast<  ::Xml >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"accountId") ) { accountId=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"guildName") ) { guildName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"guildRank") ) { guildRank=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nextCharId") ) { nextCharId=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"savedChars") ) { savedChars=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxNumChars") ) { maxNumChars=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nextCharSlotPrice") ) { nextCharSlotPrice=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nextCharSlotCurrency") ) { nextCharSlotCurrency=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool SavedCharactersList_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"DEFAULT_LATLONG") ) { DEFAULT_LATLONG=ioValue.Cast<  ::servers::LatLong >(); return true; }
	}
	return false;
}

void SavedCharactersList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("accountId",e8,81,54,29));
	outFields->push(HX_("nextCharId",a4,31,a7,6c));
	outFields->push(HX_("maxNumChars",7b,bb,89,78));
	outFields->push(HX_("numChars",b7,b0,c3,02));
	outFields->push(HX_("savedChars",d6,38,b6,e8));
	outFields->push(HX_("gems",04,fd,61,44));
	outFields->push(HX_("gold",a0,92,69,44));
	outFields->push(HX_("crowns",9c,35,bc,82));
	outFields->push(HX_("nextCharSlotPrice",02,cd,50,9e));
	outFields->push(HX_("nextCharSlotCurrency",78,1a,7d,87));
	outFields->push(HX_("guildName",9e,b5,f2,07));
	outFields->push(HX_("guildRank",ff,90,97,0a));
	outFields->push(HX_("name",4b,72,ff,48));
	outFields->push(HX_("isAdmin",45,50,d0,b8));
	outFields->push(HX_("myPos",88,21,e5,12));
	outFields->push(HX_("charsXML",fa,14,cd,bb));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo SavedCharactersList_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,accountId),HX_("accountId",e8,81,54,29)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,nextCharId),HX_("nextCharId",a4,31,a7,6c)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,maxNumChars),HX_("maxNumChars",7b,bb,89,78)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,numChars),HX_("numChars",b7,b0,c3,02)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(SavedCharactersList_obj,savedChars),HX_("savedChars",d6,38,b6,e8)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,gems),HX_("gems",04,fd,61,44)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,gold),HX_("gold",a0,92,69,44)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,crowns),HX_("crowns",9c,35,bc,82)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,nextCharSlotPrice),HX_("nextCharSlotPrice",02,cd,50,9e)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,nextCharSlotCurrency),HX_("nextCharSlotCurrency",78,1a,7d,87)},
	{::hx::fsString,(int)offsetof(SavedCharactersList_obj,guildName),HX_("guildName",9e,b5,f2,07)},
	{::hx::fsInt,(int)offsetof(SavedCharactersList_obj,guildRank),HX_("guildRank",ff,90,97,0a)},
	{::hx::fsString,(int)offsetof(SavedCharactersList_obj,name),HX_("name",4b,72,ff,48)},
	{::hx::fsBool,(int)offsetof(SavedCharactersList_obj,isAdmin),HX_("isAdmin",45,50,d0,b8)},
	{::hx::fsObject /*  ::servers::LatLong */ ,(int)offsetof(SavedCharactersList_obj,myPos),HX_("myPos",88,21,e5,12)},
	{::hx::fsObject /*  ::Xml */ ,(int)offsetof(SavedCharactersList_obj,charsXML),HX_("charsXML",fa,14,cd,bb)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo SavedCharactersList_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::servers::LatLong */ ,(void *) &SavedCharactersList_obj::DEFAULT_LATLONG,HX_("DEFAULT_LATLONG",5d,ec,61,06)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String SavedCharactersList_obj_sMemberFields[] = {
	HX_("accountId",e8,81,54,29),
	HX_("nextCharId",a4,31,a7,6c),
	HX_("maxNumChars",7b,bb,89,78),
	HX_("numChars",b7,b0,c3,02),
	HX_("savedChars",d6,38,b6,e8),
	HX_("gems",04,fd,61,44),
	HX_("gold",a0,92,69,44),
	HX_("crowns",9c,35,bc,82),
	HX_("nextCharSlotPrice",02,cd,50,9e),
	HX_("nextCharSlotCurrency",78,1a,7d,87),
	HX_("guildName",9e,b5,f2,07),
	HX_("guildRank",ff,90,97,0a),
	HX_("name",4b,72,ff,48),
	HX_("isAdmin",45,50,d0,b8),
	HX_("myPos",88,21,e5,12),
	HX_("charsXML",fa,14,cd,bb),
	HX_("toString",ac,d0,6e,38),
	HX_("getCharById",3e,6a,76,c1),
	HX_("availableCharSlots",f6,6e,39,b8),
	HX_("hasAvailableCharSlot",23,ae,38,a7),
	HX_("parseUserData",68,cd,57,4a),
	HX_("parseGuildData",ca,ca,77,45),
	HX_("parseCharacterData",40,42,38,9c),
	HX_("parseGeoPositioningData",25,ee,e3,4c),
	::String(null()) };

static void SavedCharactersList_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SavedCharactersList_obj::DEFAULT_LATLONG,"DEFAULT_LATLONG");
};

#ifdef HXCPP_VISIT_ALLOCS
static void SavedCharactersList_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SavedCharactersList_obj::DEFAULT_LATLONG,"DEFAULT_LATLONG");
};

#endif

::hx::Class SavedCharactersList_obj::__mClass;

static ::String SavedCharactersList_obj_sStaticFields[] = {
	HX_("DEFAULT_LATLONG",5d,ec,61,06),
	::String(null())
};

void SavedCharactersList_obj::__register()
{
	SavedCharactersList_obj _hx_dummy;
	SavedCharactersList_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("appengine.SavedCharactersList",24,5e,e6,3f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SavedCharactersList_obj::__GetStatic;
	__mClass->mSetStaticField = &SavedCharactersList_obj::__SetStatic;
	__mClass->mMarkFunc = SavedCharactersList_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(SavedCharactersList_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(SavedCharactersList_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< SavedCharactersList_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = SavedCharactersList_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SavedCharactersList_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SavedCharactersList_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void SavedCharactersList_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_f56609b605db29ab_8_boot)
HXDLIN(   8)		DEFAULT_LATLONG =  ::servers::LatLong_obj::__alloc( HX_CTX ,((Float)37.4436),((Float)-122.412));
            	}
}

} // end namespace appengine