//metadoc IntToBytesConverterMethod copyright Tonika, 2018
//metadoc IntToBytesConverterMethod license MIT

#ifndef IOINTTOSEQCONVERTERMETHOD_DEFINED
#define IOINTTOSEQCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoIntToBytesConverterMethod;

IoIntToBytesConverterMethod *IoIntToBytesConverterMethod_proto(void *state);
IoIntToBytesConverterMethod *IoIntToBytesConverterMethod_rawClone(IoIntToBytesConverterMethod *self);
IoIntToBytesConverterMethod *IoIntToBytesConverterMethod_new(void *state);
void IoIntToBytesConverterMethod_free(IoIntToBytesConverterMethod *self);

IoObject *IoIntToBytesConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
