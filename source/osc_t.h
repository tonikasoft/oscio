#ifndef OSC_T
#define OSC_T 1
#include <stdint.h>

typedef union {
    int32_t i;
    float f;
    uint32_t u;
    char b[4];
} osc32_t;

#endif
