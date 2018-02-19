//metadoc NetBytesToIntConverterMethod copyright Tonika, 2018
//metadoc NetBytesToIntConverterMethod license MIT

#ifndef IOSEQTOINTCONVERTERMETHOD_DEFINED
#define IOSEQTOINTCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoNetBytesToIntConverterMethod;

IoNetBytesToIntConverterMethod *IoNetBytesToIntConverterMethod_proto(void *state);
IoNetBytesToIntConverterMethod *IoNetBytesToIntConverterMethod_rawClone(IoNetBytesToIntConverterMethod *self);
IoNetBytesToIntConverterMethod *IoNetBytesToIntConverterMethod_new(void *state);
void IoNetBytesToIntConverterMethod_free(IoNetBytesToIntConverterMethod *self);

IoObject *IoNetBytesToIntConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
