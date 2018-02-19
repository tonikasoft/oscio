//metadoc IntToNetBytesConverterMethod copyright Tonika, 2018
//metadoc IntToNetBytesConverterMethod license MIT
//metadoc IntToNetBytesConverterMethod category API
//metadoc IntToNetBytesConverterMethod description Converts 32-bit integer to network ordered bytes buffer.

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

#include "IoIntToNetBytesConverterMethod.h"

static const char *protoId = "IntToNetBytesConverterMethod";

// Io's API
IoTag *IoIntToNetBytesConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoIntToNetBytesConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoIntToNetBytesConverterMethod_rawClone);

    return tag;
}

IoIntToNetBytesConverterMethod *IoIntToNetBytesConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoIntToNetBytesConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoIntToNetBytesConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoIntToNetBytesConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("i"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(4));

    return self;
}

IoIntToNetBytesConverterMethod *IoIntToNetBytesConverterMethod_rawClone(IoIntToNetBytesConverterMethod *proto) {
    IoIntToNetBytesConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoIntToNetBytesConverterMethod *IoIntToNetBytesConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoIntToNetBytesConverterMethod_free(IoIntToNetBytesConverterMethod *self) { }

//doc IntToNetBytesConverterMethod convert(value)
IoObject *IoIntToNetBytesConverterMethod_convert(IoIntToNetBytesConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc32_t converter;
    converter.i = (int32_t) IoMessage_locals_intArgAt_(m, locals, 0);
    converter.u = htonl(converter.u);

    return IoSeq_newWithData_length_(IOSTATE, converter.b, 4);
}
