//metadoc FloatToBytesConverterMethod copyright Tonika, 2018
//metadoc FloatToBytesConverterMethod license MIT

#ifndef IOFLOATTOSEQCONVERTERMETHOD_DEFINED
#define IOFLOATTOSEQCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoFloatToBytesConverterMethod;

IoFloatToBytesConverterMethod *IoFloatToBytesConverterMethod_proto(void *state);
IoFloatToBytesConverterMethod *IoFloatToBytesConverterMethod_rawClone(IoFloatToBytesConverterMethod *self);
IoFloatToBytesConverterMethod *IoFloatToBytesConverterMethod_new(void *state);
void IoFloatToBytesConverterMethod_free(IoFloatToBytesConverterMethod *self);

IoObject *IoFloatToBytesConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
