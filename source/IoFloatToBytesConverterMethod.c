//metadoc FloatToBytesConverterMethod copyright Tonika, 2018
//metadoc FloatToBytesConverterMethod license MIT
//metadoc FloatToBytesConverterMethod category API
//metadoc FloatToBytesConverterMethod description Converts float to binary `Sequence`.

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

#include "IoFloatToBytesConverterMethod.h"

static const char *protoId = "FloatToBytesConverterMethod";

// Io's API
IoTag *IoFloatToBytesConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoFloatToBytesConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoFloatToBytesConverterMethod_rawClone);

    return tag;
}

IoFloatToBytesConverterMethod *IoFloatToBytesConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoFloatToBytesConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoFloatToBytesConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoFloatToBytesConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("f"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(8));

    return self;
}

IoFloatToBytesConverterMethod *IoFloatToBytesConverterMethod_rawClone(IoFloatToBytesConverterMethod *proto) {
    IoFloatToBytesConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoFloatToBytesConverterMethod *IoFloatToBytesConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoFloatToBytesConverterMethod_free(IoFloatToBytesConverterMethod *self) { }

//doc FloatToBytesConverterMethod convert(value)
IoObject *IoFloatToBytesConverterMethod_convert(IoFloatToBytesConverterMethod *self, IoObject *locals, IoMessage *m) { 
    const float value = IoMessage_locals_floatArgAt_(m, locals, 0);
    const char bytes[8];
    *((uint32_t *) (bytes)) = htonl(*((uint32_t *) &value));
    return IoSeq_newWithCString_(IOSTATE, bytes);
}

