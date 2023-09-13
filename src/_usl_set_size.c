
#include "usl.h"
#include <stdlib.h>

void _usl_set_size(usl usl, size_t size) {
    usl[0] = size & 0xFF;
    usl[1] = (size >> 8) & 0xFF;
    usl[2] = (size >> 16) & 0xFF;
    usl[3] = (size >> 24) & 0xFF;
}
