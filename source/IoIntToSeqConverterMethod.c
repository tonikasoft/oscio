//metadoc IntToSeqConverterMethod copyright Tonika, 2018
//metadoc IntToSeqConverterMethod license MIT
//metadoc IntToSeqConverterMethod category API
//metadoc IntToSeqConverterMethod description Converts integer to `Sequence`.

#include "IoState.h"
#include "IoSeq.h"

#include "IoIntToSeqConverterMethod.h"

static const char *protoId = "IntToSeqConverterMethod";

IoTag *IoIntToSeqConverterMethod_newTag(void *state) {
	IoTag *tag = IoTag_newWithName_(protoId);

	IoTag_state_(tag, state);

	IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoIntToSeqConverterMethod_free);

	IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoIntToSeqConverterMethod_rawClone);

	return tag;
}

IoIntToSeqConverterMethod *IoIntToSeqConverterMethod_proto(void *state) {
	IoObject *self = IoObject_new(state);
	IoObject_tag_(self, IoIntToSeqConverterMethod_newTag(state));
	
	IoState_registerProtoWithFunc_(state, self, IoIntToSeqConverterMethod_proto);
	
	{
		IoMethodTable methodTable[] = {
		{"convert", IoIntToSeqConverterMethod_convert},
		{NULL, NULL},
		};
		
		IoObject_addMethodTable_(self, methodTable);
	}
    
    IoObject_setSlot_to_(self, IOSYMBOL("inputTypeTag"), IOSYMBOL("i"));

    return self;
}

IoIntToSeqConverterMethod *IoIntToSeqConverterMethod_rawClone(IoIntToSeqConverterMethod *proto) {
	IoIntToSeqConverterMethod *self = IoObject_rawClonePrimitive(proto);
	return self;
}

IoIntToSeqConverterMethod *IoIntToSeqConverterMethod_new(void *state) {
	IoObject *proto = IoState_protoWithId_(state, protoId);
	return IOCLONE(proto);
}

void IoIntToSeqConverterMethod_free(IoIntToSeqConverterMethod *self) {}

//doc IntToSeqConverterMethod convert(value)
IoObject *IoIntToSeqConverterMethod_convert(IoIntToSeqConverterMethod *self, IoObject *locals, IoMessage *m) { 
    int value = IoMessage_locals_intArgAt_(m, locals, 0);
    char bytes[4];
    memcpy(bytes, &value, 4);
	return IoSeq_newWithCString_(IOSTATE, bytes);
}
