
#include "usl.h"
#include <stdlib.h>

usl usl_concat(usl str1, usl str2) {
    // we store the size of the string in the first sizeof(size_t) bytes
    size_t len1 = usl_len(str1);
    size_t len2 = usl_len(str2);
    usl result = (usl)usl_new(len1 + len2);
    if (result == NULL)
        return NULL;
    // we set the size of the result
    _usl_set_size(result, len1 + len2);
    // we copy the first string into the result
    for (size_t i = 0; i < len1; i++) {
        result[i + USL_PADDING_SIZE] = str1[i + USL_PADDING_SIZE];
    }
    // we copy the second string into the result
    for (size_t i = 0; i < len2; i++) {
        result[i + USL_PADDING_SIZE + len1] = str2[i + USL_PADDING_SIZE];
    }
    return result;
}
