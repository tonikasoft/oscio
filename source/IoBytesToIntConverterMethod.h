//metadoc BytesToIntConverterMethod copyright Tonika, 2018
//metadoc BytesToIntConverterMethod license MIT

#ifndef IOSEQTOINTCONVERTERMETHOD_DEFINED
#define IOSEQTOINTCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoBytesToIntConverterMethod;

IoBytesToIntConverterMethod *IoBytesToIntConverterMethod_proto(void *state);
IoBytesToIntConverterMethod *IoBytesToIntConverterMethod_rawClone(IoBytesToIntConverterMethod *self);
IoBytesToIntConverterMethod *IoBytesToIntConverterMethod_new(void *state);
void IoBytesToIntConverterMethod_free(IoBytesToIntConverterMethod *self);

IoObject *IoBytesToIntConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
