//metadoc FloatToNetBytesConverterMethod copyright Tonika, 2018
//metadoc FloatToNetBytesConverterMethod license MIT
//metadoc FloatToNetBytesConverterMethod category API
//metadoc FloatToNetBytesConverterMethod description Converts float to binary `Sequence`.

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

#include "IoFloatToNetBytesConverterMethod.h"

static const char *protoId = "FloatToNetBytesConverterMethod";

// Io's API
IoTag *IoFloatToNetBytesConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoFloatToNetBytesConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoFloatToNetBytesConverterMethod_rawClone);

    return tag;
}

IoFloatToNetBytesConverterMethod *IoFloatToNetBytesConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoFloatToNetBytesConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoFloatToNetBytesConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoFloatToNetBytesConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("f"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(8));

    return self;
}

IoFloatToNetBytesConverterMethod *IoFloatToNetBytesConverterMethod_rawClone(IoFloatToNetBytesConverterMethod *proto) {
    IoFloatToNetBytesConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoFloatToNetBytesConverterMethod *IoFloatToNetBytesConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoFloatToNetBytesConverterMethod_free(IoFloatToNetBytesConverterMethod *self) { }

//doc FloatToNetBytesConverterMethod convert(value)
IoObject *IoFloatToNetBytesConverterMethod_convert(IoFloatToNetBytesConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc32_t converter;
    converter.f = IoMessage_locals_floatArgAt_(m, locals, 0);
    converter.u = htonl(converter.u);

    return IoSeq_newWithData_length_(IOSTATE, converter.b, 4);
}
