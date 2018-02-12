//metadoc IntToSeqConverterMethod copyright Tonika, 2018
//metadoc IntToSeqConverterMethod license MIT

#ifndef IOINTTOSEQCONVERTERMETHOD_DEFINED
#define IOINTTOSEQCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoIntToSeqConverterMethod;

IoIntToSeqConverterMethod *IoIntToSeqConverterMethod_proto(void *state);
IoIntToSeqConverterMethod *IoIntToSeqConverterMethod_rawClone(IoIntToSeqConverterMethod *self);
IoIntToSeqConverterMethod *IoIntToSeqConverterMethod_new(void *state);
void IoIntToSeqConverterMethod_free(IoIntToSeqConverterMethod *self);

IoObject *IoIntToSeqConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
