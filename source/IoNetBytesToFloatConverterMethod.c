//metadoc NetBytesToFloatConverterMethod copyright Tonika, 2018
//metadoc NetBytesToFloatConverterMethod license MIT
//metadoc NetBytesToFloatConverterMethod category API
//metadoc NetBytesToFloatConverterMethod description Converts netbytes to float.

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

#include "IoNetBytesToFloatConverterMethod.h"

static const char *protoId = "NetBytesToFloatConverterMethod";

// Io's API
IoTag *IoNetBytesToFloatConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoNetBytesToFloatConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoNetBytesToFloatConverterMethod_rawClone);

    return tag;
}

IoNetBytesToFloatConverterMethod *IoNetBytesToFloatConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoNetBytesToFloatConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoNetBytesToFloatConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoNetBytesToFloatConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("f"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(4));

    return self;
}

IoNetBytesToFloatConverterMethod *IoNetBytesToFloatConverterMethod_rawClone(IoNetBytesToFloatConverterMethod *proto) {
    IoNetBytesToFloatConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoNetBytesToFloatConverterMethod *IoNetBytesToFloatConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoNetBytesToFloatConverterMethod_free(IoNetBytesToFloatConverterMethod *self) { }

//doc NetBytesToFloatConverterMethod convert(value)
IoObject *IoNetBytesToFloatConverterMethod_convert(IoNetBytesToFloatConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc32_t converter;
    char *value = IoMessage_locals_cStringArgAt_(m, locals, 0);
    converter.u = ntohl(*(uint32_t*)value);

    return IONUMBER(converter.f);
}
