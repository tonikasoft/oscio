//metadoc NetBytesToLongConverterMethod copyright Tonika, 2018
//metadoc NetBytesToLongConverterMethod license MIT
//metadoc NetBytesToLongConverterMethod category API
//metadoc NetBytesToLongConverterMethod description Converts netbytes to long.

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

#include "osc_t.h"
#include "IoState.h"
#include "IoSeq.h"
#include "IoNumber.h"

#include "IoNetBytesToLongConverterMethod.h"

static const char *protoId = "NetBytesToLongConverterMethod";

// Io's API
IoTag *IoNetBytesToLongConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoNetBytesToLongConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoNetBytesToLongConverterMethod_rawClone);

    return tag;
}

IoNetBytesToLongConverterMethod *IoNetBytesToLongConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoNetBytesToLongConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoNetBytesToLongConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoNetBytesToLongConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("h"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(8));

    return self;
}

IoNetBytesToLongConverterMethod *IoNetBytesToLongConverterMethod_rawClone(IoNetBytesToLongConverterMethod *proto) {
    IoNetBytesToLongConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoNetBytesToLongConverterMethod *IoNetBytesToLongConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoNetBytesToLongConverterMethod_free(IoNetBytesToLongConverterMethod *self) { }

//doc NetBytesToLongConverterMethod convert(value)
IoObject *IoNetBytesToLongConverterMethod_convert(IoNetBytesToLongConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc64_t converter;
    char *value = IoMessage_locals_cStringArgAt_(m, locals, 0);
    converter.u = ntohll(*(uint64_t*)value);

    return IONUMBER(converter.l);
}
