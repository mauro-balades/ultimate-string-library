
#include "usl.h"
#include <string.h>
#include <stdlib.h>

usl usl_from(const char *str) {
    size_t len = strlen(str);
    usl result = (usl)usl_new(len);
    // we need to add the length to the first 4 bytes of the usl
    // so that we can use it in usl_len
    _usl_set_size(result, len);
    for (size_t i = 0; i < len; i++) {
        result[i + USL_PADDING_SIZE] = str[i];
    }
    return result;
}
