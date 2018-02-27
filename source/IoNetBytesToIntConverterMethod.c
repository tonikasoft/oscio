//metadoc NetBytesToIntConverterMethod copyright Tonika, 2018
//metadoc NetBytesToIntConverterMethod license MIT
//metadoc NetBytesToIntConverterMethod category API
//metadoc NetBytesToIntConverterMethod description Converts network ordered bytes buffer to 32-bit integer.

#include <stdint.h>
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

#include "IoNetBytesToIntConverterMethod.h"

static const char *protoId = "NetBytesToIntConverterMethod";

// Io's API
IoTag *IoNetBytesToIntConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoNetBytesToIntConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoNetBytesToIntConverterMethod_rawClone);

    return tag;
}

IoNetBytesToIntConverterMethod *IoNetBytesToIntConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoNetBytesToIntConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoNetBytesToIntConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoNetBytesToIntConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("i"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(4));

    return self;
}

IoNetBytesToIntConverterMethod *IoNetBytesToIntConverterMethod_rawClone(IoNetBytesToIntConverterMethod *proto) {
    IoNetBytesToIntConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoNetBytesToIntConverterMethod *IoNetBytesToIntConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoNetBytesToIntConverterMethod_free(IoNetBytesToIntConverterMethod *self) {}

//doc NetBytesToIntConverterMethod convert(value)
IoObject *IoNetBytesToIntConverterMethod_convert(IoNetBytesToIntConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc32_t converter;
    char *value = IoMessage_locals_seqArgAt_(m, locals, 0);
    converter.u = ntohl(*(uint32_t*)value);

    return IONUMBER(converter.i);
}
