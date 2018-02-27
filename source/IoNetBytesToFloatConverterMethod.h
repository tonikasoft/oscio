//metadoc NetBytesToFloatConverterMethod copyright Tonika, 2018
//metadoc NetBytesToFloatConverterMethod license MIT

#ifndef IONETBYTESTOFLOATCONVERTERMETHOD_DEFINED
#define IONETBYTESTOFLOATCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoNetBytesToFloatConverterMethod;

IoNetBytesToFloatConverterMethod *IoNetBytesToFloatConverterMethod_proto(void *state);
IoNetBytesToFloatConverterMethod *IoNetBytesToFloatConverterMethod_rawClone(IoNetBytesToFloatConverterMethod *self);
IoNetBytesToFloatConverterMethod *IoNetBytesToFloatConverterMethod_new(void *state);
void IoNetBytesToFloatConverterMethod_free(IoNetBytesToFloatConverterMethod *self);

IoObject *IoNetBytesToFloatConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
