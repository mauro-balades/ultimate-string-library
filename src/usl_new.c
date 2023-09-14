
#include "usl.h"
#include <stdlib.h>

usl usl_new(size_t size) {
    // we allocate the size inside *(size_t*)usl
    // so that we can use it in usl_len
    usl result = (usl)malloc(size + USL_PADDING_SIZE + 1);
    if (result == NULL)
        return NULL;
    *(USL_PADDING_TYPE*)result = size;
    return result;
}
