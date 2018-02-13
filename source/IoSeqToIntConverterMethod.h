//metadoc SeqToIntConverterMethod copyright Tonika, 2018
//metadoc SeqToIntConverterMethod license MIT

#ifndef IOSEQTOINTCONVERTERMETHOD_DEFINED
#define IOSEQTOINTCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoSeqToIntConverterMethod;

IoSeqToIntConverterMethod *IoSeqToIntConverterMethod_proto(void *state);
IoSeqToIntConverterMethod *IoSeqToIntConverterMethod_rawClone(IoSeqToIntConverterMethod *self);
IoSeqToIntConverterMethod *IoSeqToIntConverterMethod_new(void *state);
void IoSeqToIntConverterMethod_free(IoSeqToIntConverterMethod *self);

IoObject *IoSeqToIntConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
