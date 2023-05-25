package util;

#if cpp
typedef Int8 = cpp.Int8;
#else
typedef Int8 = Int;
#end

#if cpp
typedef Int16 = cpp.Int16;
#else
typedef Int16 = Int;
#end

#if cpp
typedef Int32 = cpp.Int32;
#else
typedef Int32 = Int;
#end

#if cpp
typedef Int64 = cpp.Int64;
#else
typedef Int64 = haxe.Int64;
#end

#if cpp
typedef UInt8 = cpp.UInt8;
#elseif hl
typedef UInt8 = hl.UI8;
#else
typedef UInt8 = UInt;
#end

#if cpp
typedef UInt16 = cpp.UInt16;
#elseif hl
typedef UInt16 = hl.UI16;
#else
typedef UInt16 = UInt;
#end

#if cpp
typedef UInt32 = cpp.UInt32;
#else
typedef UInt32 = UInt;
#end

#if cpp
typedef Float32 = cpp.Float32;
#elseif hl
typedef Float32 = hl.F32;
#else
typedef Float32 = Float;
#end

#if cpp
typedef Float64 = cpp.Float64;
#elseif hl
typedef Float64 = hl.F64;
#else
typedef Float64 = Float;
#end