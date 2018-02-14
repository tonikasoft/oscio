//metadoc BytesToIntConverterMethod copyright Tonika, 2018
//metadoc BytesToIntConverterMethod license MIT
//metadoc BytesToIntConverterMethod category API
//metadoc BytesToIntConverterMethod description Converts binary `Sequence` to integer.

#include "IoState.h"
#include "IoSeq.h"
#include "IoNumber.h"

#include "IoBytesToIntConverterMethod.h"

static const char *protoId = "BytesToIntConverterMethod";

// Io's API
IoTag *IoBytesToIntConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoBytesToIntConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoBytesToIntConverterMethod_rawClone);

    return tag;
}

IoBytesToIntConverterMethod *IoBytesToIntConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoBytesToIntConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoBytesToIntConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoBytesToIntConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("i"));

    return self;
}

IoBytesToIntConverterMethod *IoBytesToIntConverterMethod_rawClone(IoBytesToIntConverterMethod *proto) {
    IoBytesToIntConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoBytesToIntConverterMethod *IoBytesToIntConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoBytesToIntConverterMethod_free(IoBytesToIntConverterMethod *self) {}

//doc BytesToIntConverterMethod convert(value)
IoObject *IoBytesToIntConverterMethod_convert(IoBytesToIntConverterMethod *self, IoObject *locals, IoMessage *m) { 
    char *value = IoMessage_locals_cStringArgAt_(m, locals, 0);
    const int32_t output = (int32_t) ntohl(*((uint32_t *) value));
    return IONUMBER(output);
}

