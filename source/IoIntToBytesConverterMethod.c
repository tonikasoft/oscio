//metadoc IntToBytesConverterMethod copyright Tonika, 2018
//metadoc IntToBytesConverterMethod license MIT
//metadoc IntToBytesConverterMethod category API
//metadoc IntToBytesConverterMethod description Converts integer to binary `Sequence`.

#include <string.h>
#if _WIN32
#include <winsock2.h>
#define tosc_strncpy(_dst, _src, _len) strncpy_s(_dst, _len, _src, _TRUNCATE)
#else
#include <netinet/in.h>
#define tosc_strncpy(_dst, _src, _len) strncpy(_dst, _src, _len)
#endif
#if __unix__ && !__APPLE__
#include <endian.h>
#define htonll(x) htobe64(x)
#define ntohll(x) be64toh(x)
#endif

#include "IoState.h"
#include "IoSeq.h"
#include "IoNumber.h"

#include "IoIntToBytesConverterMethod.h"

static const char *protoId = "IntToBytesConverterMethod";

// Io's API
IoTag *IoIntToBytesConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoIntToBytesConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoIntToBytesConverterMethod_rawClone);

    return tag;
}

IoIntToBytesConverterMethod *IoIntToBytesConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoIntToBytesConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoIntToBytesConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoIntToBytesConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("i"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(4));

    return self;
}

IoIntToBytesConverterMethod *IoIntToBytesConverterMethod_rawClone(IoIntToBytesConverterMethod *proto) {
    IoIntToBytesConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoIntToBytesConverterMethod *IoIntToBytesConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoIntToBytesConverterMethod_free(IoIntToBytesConverterMethod *self) { }

//doc IntToBytesConverterMethod convert(value)
IoObject *IoIntToBytesConverterMethod_convert(IoIntToBytesConverterMethod *self, IoObject *locals, IoMessage *m) { 
    const uint32_t value = (uint32_t) IoMessage_locals_intArgAt_(m, locals, 0);
    char bytes[4];
    *((uint32_t *) bytes) = htonl((uint32_t) value);
    return IoSeq_newWithCString_(IOSTATE, bytes);
}

