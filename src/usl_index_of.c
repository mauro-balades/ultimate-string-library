
#include "usl.h"
#include <stdlib.h>

size_t usl_index_of(usl str, char ch) {
    int len = usl_len(str);
    for (int i = 0; i < len; i++) {
        if (usl_at(str, i) == ch)
            return i;
    }
    return -1;
}
