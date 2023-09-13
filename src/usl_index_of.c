
#include "usl.h"
#include <stdlib.h>

size_t usl_index_of(usl str, char ch) {
    int len = usl_len(str);
    for (int i = 0; i < len; i++) {
        if (str[i + USL_SIZE] == ch)
            return i;
    }
    return -1;
}
