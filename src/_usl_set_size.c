
#include "usl.h"
#include <stdlib.h>

void _usl_set_size(usl usl, size_t size) {
    *(USL_PADDING_TYPE*)usl = size;
}
