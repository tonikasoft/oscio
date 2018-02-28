//metadoc DoubleToNetBytesConverterMethod copyright Tonika, 2018
//metadoc DoubleToNetBytesConverterMethod license MIT

#ifndef IODOUBLETONETBYTESCONVERTERMETHOD_DEFINED
#define IODOUBLETONETBYTESCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoDoubleToNetBytesConverterMethod;

IoDoubleToNetBytesConverterMethod *IoDoubleToNetBytesConverterMethod_proto(void *state);
IoDoubleToNetBytesConverterMethod *IoDoubleToNetBytesConverterMethod_rawClone(IoDoubleToNetBytesConverterMethod *self);
IoDoubleToNetBytesConverterMethod *IoDoubleToNetBytesConverterMethod_new(void *state);
void IoDoubleToNetBytesConverterMethod_free(IoDoubleToNetBytesConverterMethod *self);

IoObject *IoDoubleToNetBytesConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
