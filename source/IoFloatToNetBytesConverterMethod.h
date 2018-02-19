//metadoc FloatToNetBytesConverterMethod copyright Tonika, 2018
//metadoc FloatToNetBytesConverterMethod license MIT

#ifndef IOFLOATTOSEQCONVERTERMETHOD_DEFINED
#define IOFLOATTOSEQCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoFloatToNetBytesConverterMethod;

IoFloatToNetBytesConverterMethod *IoFloatToNetBytesConverterMethod_proto(void *state);
IoFloatToNetBytesConverterMethod *IoFloatToNetBytesConverterMethod_rawClone(IoFloatToNetBytesConverterMethod *self);
IoFloatToNetBytesConverterMethod *IoFloatToNetBytesConverterMethod_new(void *state);
void IoFloatToNetBytesConverterMethod_free(IoFloatToNetBytesConverterMethod *self);

IoObject *IoFloatToNetBytesConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
