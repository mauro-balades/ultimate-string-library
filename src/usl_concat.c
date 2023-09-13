
#include "usl.h"
#include <stdlib.h>

usl usl_concat(usl str1, usl str2) {
    size_t len1 = usl_len(str1);
    size_t len2 = usl_len(str2);
    size_t new_len = len1 + len2;
    usl new_str = usl_new(new_len);
    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < len1; i++)
        new_str[i + USL_SIZE] = str1[i + USL_SIZE];
    for (int i = 0; i < len2; i++)
        new_str[i + len1 + USL_SIZE] = str2[i + USL_SIZE];
    _usl_set_size(new_str, new_len);
    return new_str;
}
