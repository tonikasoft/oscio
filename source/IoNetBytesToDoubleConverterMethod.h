//metadoc NetBytesToDoubleConverterMethod copyright Tonika, 2018
//metadoc NetBytesToDoubleConverterMethod license MIT

#ifndef IONETBYTESTODOUBLECONVERTERMETHOD_DEFINED
#define IONETBYTESTODOUBLECONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoNetBytesToDoubleConverterMethod;

IoNetBytesToDoubleConverterMethod *IoNetBytesToDoubleConverterMethod_proto(void *state);
IoNetBytesToDoubleConverterMethod *IoNetBytesToDoubleConverterMethod_rawClone(IoNetBytesToDoubleConverterMethod *self);
IoNetBytesToDoubleConverterMethod *IoNetBytesToDoubleConverterMethod_new(void *state);
void IoNetBytesToDoubleConverterMethod_free(IoNetBytesToDoubleConverterMethod *self);

IoObject *IoNetBytesToDoubleConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
