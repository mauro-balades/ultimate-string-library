
#include "usl.h"
#include <string.h>
#include <stdlib.h>

usl usl_from(const char *str) {
    size_t len = strlen(str);
    usl result = (usl)usl_new(len);
    // we need to add the length to the first 4 bytes of the usl
    // so that we can use it in usl_len
    result[0] = len & 0xFF;
    result[1] = (len >> 8) & 0xFF;
    result[2] = (len >> 16) & 0xFF;
    result[3] = (len >> 24) & 0xFF;
    memcpy(result+4, str, len);
    return result;
}
