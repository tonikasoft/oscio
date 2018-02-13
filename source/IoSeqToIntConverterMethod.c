//metadoc SeqToIntConverterMethod copyright Tonika, 2018
//metadoc SeqToIntConverterMethod license MIT
//metadoc SeqToIntConverterMethod category API
//metadoc SeqToIntConverterMethod description Converts binary `Sequence` to integer.

#include "IoState.h"
#include "IoSeq.h"
#include "IoNumber.h"

#include "IoSeqToIntConverterMethod.h"

static const char *protoId = "SeqToIntConverterMethod";

// Io's API
IoTag *IoSeqToIntConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoSeqToIntConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoSeqToIntConverterMethod_rawClone);

    return tag;
}

IoSeqToIntConverterMethod *IoSeqToIntConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoSeqToIntConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoSeqToIntConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoSeqToIntConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("i"));

    return self;
}

IoSeqToIntConverterMethod *IoSeqToIntConverterMethod_rawClone(IoSeqToIntConverterMethod *proto) {
    IoSeqToIntConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoSeqToIntConverterMethod *IoSeqToIntConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoSeqToIntConverterMethod_free(IoSeqToIntConverterMethod *self) {}

//doc SeqToIntConverterMethod convert(value)
IoObject *IoSeqToIntConverterMethod_convert(IoSeqToIntConverterMethod *self, IoObject *locals, IoMessage *m) { 
    char *value = IoMessage_locals_cStringArgAt_(m, locals, 0);
    int output;
    memcpy(&output, value, 4);
    return IONUMBER(output);
}

