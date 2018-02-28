//metadoc LongToNetBytesConverterMethod copyright Tonika, 2018
//metadoc LongToNetBytesConverterMethod license MIT

#ifndef IOLONGTONETBYTESCONVERTERMETHOD_DEFINED
#define IOLONGTONETBYTESCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoLongToNetBytesConverterMethod;

IoLongToNetBytesConverterMethod *IoLongToNetBytesConverterMethod_proto(void *state);
IoLongToNetBytesConverterMethod *IoLongToNetBytesConverterMethod_rawClone(IoLongToNetBytesConverterMethod *self);
IoLongToNetBytesConverterMethod *IoLongToNetBytesConverterMethod_new(void *state);
void IoLongToNetBytesConverterMethod_free(IoLongToNetBytesConverterMethod *self);

IoObject *IoLongToNetBytesConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
