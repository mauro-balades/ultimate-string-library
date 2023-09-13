
#include "usl.h"
#include <stdlib.h>

usl usl_substring(usl str, size_t start, size_t end) {
    // note: first 4 bytes are the length and should
    // not be included when creating a substring
    size_t length = usl_len(str);
    if (start >= length || end > length || start > end)
        return NULL;
    usl result = (usl)usl_new(end-start);
    if (result == NULL)
        return NULL;
    memcpy(result+USL_SIZE, str+USL_SIZE+start, end-start);
    _usl_set_size(result, end-start);
    return result;
}