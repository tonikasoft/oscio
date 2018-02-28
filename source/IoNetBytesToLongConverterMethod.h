//metadoc NetBytesToLongConverterMethod copyright Tonika, 2018
//metadoc NetBytesToLongConverterMethod license MIT

#ifndef IONETBYTESTOLONGCONVERTERMETHOD_DEFINED
#define IONETBYTESTOLONGCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoNetBytesToLongConverterMethod;

IoNetBytesToLongConverterMethod *IoNetBytesToLongConverterMethod_proto(void *state);
IoNetBytesToLongConverterMethod *IoNetBytesToLongConverterMethod_rawClone(IoNetBytesToLongConverterMethod *self);
IoNetBytesToLongConverterMethod *IoNetBytesToLongConverterMethod_new(void *state);
void IoNetBytesToLongConverterMethod_free(IoNetBytesToLongConverterMethod *self);

IoObject *IoNetBytesToLongConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
