//metadoc NetBytesToDoubleConverterMethod copyright Tonika, 2018
//metadoc NetBytesToDoubleConverterMethod license MIT
//metadoc NetBytesToDoubleConverterMethod category API
//metadoc NetBytesToDoubleConverterMethod description Converts netbytes to double.

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

#include "IoNetBytesToDoubleConverterMethod.h"

static const char *protoId = "NetBytesToDoubleConverterMethod";

// Io's API
IoTag *IoNetBytesToDoubleConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoNetBytesToDoubleConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoNetBytesToDoubleConverterMethod_rawClone);

    return tag;
}

IoNetBytesToDoubleConverterMethod *IoNetBytesToDoubleConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoNetBytesToDoubleConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoNetBytesToDoubleConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoNetBytesToDoubleConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("d"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(8));

    return self;
}

IoNetBytesToDoubleConverterMethod *IoNetBytesToDoubleConverterMethod_rawClone(IoNetBytesToDoubleConverterMethod *proto) {
    IoNetBytesToDoubleConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoNetBytesToDoubleConverterMethod *IoNetBytesToDoubleConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoNetBytesToDoubleConverterMethod_free(IoNetBytesToDoubleConverterMethod *self) { }

//doc NetBytesToDoubleConverterMethod convert(value)
IoObject *IoNetBytesToDoubleConverterMethod_convert(IoNetBytesToDoubleConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc64_t converter;
    char *value = IoMessage_locals_cStringArgAt_(m, locals, 0);
    converter.u = ntohll(*(uint64_t*)value);

    return IONUMBER(converter.d);
}
