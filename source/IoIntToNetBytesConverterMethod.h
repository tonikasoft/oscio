//metadoc IntToNetBytesConverterMethod copyright Tonika, 2018
//metadoc IntToNetBytesConverterMethod license MIT

#ifndef IOINTTOSEQCONVERTERMETHOD_DEFINED
#define IOINTTOSEQCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoIntToNetBytesConverterMethod;

IoIntToNetBytesConverterMethod *IoIntToNetBytesConverterMethod_proto(void *state);
IoIntToNetBytesConverterMethod *IoIntToNetBytesConverterMethod_rawClone(IoIntToNetBytesConverterMethod *self);
IoIntToNetBytesConverterMethod *IoIntToNetBytesConverterMethod_new(void *state);
void IoIntToNetBytesConverterMethod_free(IoIntToNetBytesConverterMethod *self);

IoObject *IoIntToNetBytesConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
