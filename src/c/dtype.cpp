#include <occa/c/types.hpp>
#include <occa/c/dtype.h>

OCCA_START_EXTERN_C

//-----[ Methods ]----------------------
OCCA_LFUNC occaDtype OCCA_RFUNC occaCreateDtype(const char *name,
                                                const int bytes) {
  return occa::c::newOccaType(
    *(new occa::dtype_t(name, bytes))
  );
}

OCCA_LFUNC occaDtype OCCA_RFUNC occaCreateDtypeTuple(occaDtype dtype,
                                                     const int size) {
  return occa::c::newOccaType(
    *(new occa::dtype_t(
        occa::dtype_t::tuple(occa::c::dtype(dtype), size)
      ))
  );
}

OCCA_LFUNC const char* OCCA_RFUNC occaDtypeName(occaDtype dtype) {
  return occa::c::dtype(dtype).name().c_str();
}

OCCA_LFUNC int OCCA_RFUNC occaDtypeBytes(occaDtype dtype) {
  return occa::c::dtype(dtype).bytes();
}

OCCA_LFUNC void OCCA_RFUNC occaDtypeRegisterType(occaDtype dtype) {
  occa::c::dtype(dtype).registerType();
}

OCCA_LFUNC bool OCCA_RFUNC occaDtypeIsRegistered(occaDtype dtype) {
  return occa::c::dtype(dtype).isRegistered();
}

OCCA_LFUNC void OCCA_RFUNC occaDtypeAddField(occaDtype dtype,
                                             const char *field,
                                             occaDtype fieldType) {
  occa::dtype_t &dtype_ = occa::c::dtype(dtype);
  dtype_.addField(field,
                  occa::c::dtype(fieldType));
}

OCCA_LFUNC bool OCCA_RFUNC occaDtypesAreEqual(occaDtype a,
                                              occaDtype b) {
  return (occa::c::dtype(a) == occa::c::dtype(b));
}

OCCA_LFUNC bool OCCA_RFUNC occaDtypesMatch(occaDtype a,
                                           occaDtype b) {
  return occa::c::dtype(a).matches(occa::c::dtype(b));
}

OCCA_LFUNC occaDtype OCCA_RFUNC occaDtypeFromJson(occaJson json) {
  return occa::c::newOccaType(
    *(new occa::dtype_t(
        occa::dtype_t::fromJson(occa::c::json(json))
      ))
  );
}
OCCA_LFUNC occaDtype OCCA_RFUNC occaDtypeFromJsonString(const char *str) {
  return occa::c::newOccaType(
    *(new occa::dtype_t(
        occa::dtype_t::fromJson(std::string(str))
      ))
  );
}

OCCA_LFUNC occaJson OCCA_RFUNC occaDtypeToJson(occaDtype dtype) {
  occa::dtype_t &dtype_ = occa::c::dtype(dtype);
  return occa::c::newOccaType(
    *(new occa::json(dtype_.toJson())),
    true
  );
}
//======================================

//-----[ Builtins ]---------------------
const occaDtype occaDtypeNone = occa::c::newOccaType(occa::dtype::none);

const occaDtype occaDtypeVoid = occa::c::newOccaType(occa::dtype::void_);
const occaDtype occaDtypeByte = occa::c::newOccaType(occa::dtype::byte);

const occaDtype occaDtypeBool   = occa::c::newOccaType(occa::dtype::bool_);
const occaDtype occaDtypeChar   = occa::c::newOccaType(occa::dtype::char_);
const occaDtype occaDtypeShort  = occa::c::newOccaType(occa::dtype::short_);
const occaDtype occaDtypeInt    = occa::c::newOccaType(occa::dtype::int_);
const occaDtype occaDtypeLong   = occa::c::newOccaType(occa::dtype::long_);
const occaDtype occaDtypeFloat  = occa::c::newOccaType(occa::dtype::float_);
const occaDtype occaDtypeDouble = occa::c::newOccaType(occa::dtype::double_);

const occaDtype occaDtypeInt8    = occa::c::newOccaType(occa::dtype::int8);
const occaDtype occaDtypeUint8   = occa::c::newOccaType(occa::dtype::uint8);
const occaDtype occaDtypeInt16   = occa::c::newOccaType(occa::dtype::int16);
const occaDtype occaDtypeUint16  = occa::c::newOccaType(occa::dtype::uint16);
const occaDtype occaDtypeInt32   = occa::c::newOccaType(occa::dtype::int32);
const occaDtype occaDtypeUint32  = occa::c::newOccaType(occa::dtype::uint32);
const occaDtype occaDtypeInt64   = occa::c::newOccaType(occa::dtype::int64);
const occaDtype occaDtypeUint64  = occa::c::newOccaType(occa::dtype::uint64);

// OKL Primitives
const occaDtype occaDtypeUchar2 = occa::c::newOccaType(occa::dtype::uchar2);
const occaDtype occaDtypeUchar3 = occa::c::newOccaType(occa::dtype::uchar3);
const occaDtype occaDtypeUchar4 = occa::c::newOccaType(occa::dtype::uchar4);

const occaDtype occaDtypeChar2 = occa::c::newOccaType(occa::dtype::char2);
const occaDtype occaDtypeChar3 = occa::c::newOccaType(occa::dtype::char3);
const occaDtype occaDtypeChar4 = occa::c::newOccaType(occa::dtype::char4);

const occaDtype occaDtypeUshort2 = occa::c::newOccaType(occa::dtype::ushort2);
const occaDtype occaDtypeUshort3 = occa::c::newOccaType(occa::dtype::ushort3);
const occaDtype occaDtypeUshort4 = occa::c::newOccaType(occa::dtype::ushort4);

const occaDtype occaDtypeShort2 = occa::c::newOccaType(occa::dtype::short2);
const occaDtype occaDtypeShort3 = occa::c::newOccaType(occa::dtype::short3);
const occaDtype occaDtypeShort4 = occa::c::newOccaType(occa::dtype::short4);

const occaDtype occaDtypeUint2 = occa::c::newOccaType(occa::dtype::uint2);
const occaDtype occaDtypeUint3 = occa::c::newOccaType(occa::dtype::uint3);
const occaDtype occaDtypeUint4 = occa::c::newOccaType(occa::dtype::uint4);

const occaDtype occaDtypeInt2 = occa::c::newOccaType(occa::dtype::int2);
const occaDtype occaDtypeInt3 = occa::c::newOccaType(occa::dtype::int3);
const occaDtype occaDtypeInt4 = occa::c::newOccaType(occa::dtype::int4);

const occaDtype occaDtypeUlong2 = occa::c::newOccaType(occa::dtype::ulong2);
const occaDtype occaDtypeUlong3 = occa::c::newOccaType(occa::dtype::ulong3);
const occaDtype occaDtypeUlong4 = occa::c::newOccaType(occa::dtype::ulong4);

const occaDtype occaDtypeLong2 = occa::c::newOccaType(occa::dtype::long2);
const occaDtype occaDtypeLong3 = occa::c::newOccaType(occa::dtype::long3);
const occaDtype occaDtypeLong4 = occa::c::newOccaType(occa::dtype::long4);

const occaDtype occaDtypeFloat2 = occa::c::newOccaType(occa::dtype::float2);
const occaDtype occaDtypeFloat3 = occa::c::newOccaType(occa::dtype::float3);
const occaDtype occaDtypeFloat4 = occa::c::newOccaType(occa::dtype::float4);

const occaDtype occaDtypeDouble2 = occa::c::newOccaType(occa::dtype::double2);
const occaDtype occaDtypeDouble3 = occa::c::newOccaType(occa::dtype::double3);
const occaDtype occaDtypeDouble4 = occa::c::newOccaType(occa::dtype::double4);
//======================================

OCCA_END_EXTERN_C
