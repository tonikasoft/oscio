//metadoc LongToNetBytesConverterMethod copyright Tonika, 2018
//metadoc LongToNetBytesConverterMethod license MIT
//metadoc LongToNetBytesConverterMethod category API
//metadoc LongToNetBytesConverterMethod description Converts long to netbytes.

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

#include "IoLongToNetBytesConverterMethod.h"

static const char *protoId = "LongToNetBytesConverterMethod";

// Io's API
IoTag *IoLongToNetBytesConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoLongToNetBytesConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoLongToNetBytesConverterMethod_rawClone);

    return tag;
}

IoLongToNetBytesConverterMethod *IoLongToNetBytesConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoLongToNetBytesConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoLongToNetBytesConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoLongToNetBytesConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("h"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(8));

    return self;
}

IoLongToNetBytesConverterMethod *IoLongToNetBytesConverterMethod_rawClone(IoLongToNetBytesConverterMethod *proto) {
    IoLongToNetBytesConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoLongToNetBytesConverterMethod *IoLongToNetBytesConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoLongToNetBytesConverterMethod_free(IoLongToNetBytesConverterMethod *self) { }

//doc LongToNetBytesConverterMethod convert(value)
IoObject *IoLongToNetBytesConverterMethod_convert(IoLongToNetBytesConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc64_t converter;
    converter.l = (int64_t) IoMessage_locals_floatArgAt_(m, locals, 0);
    converter.u = htonll(converter.u);

    return IoSeq_newWithData_length_(IOSTATE, converter.b, 8);
}
