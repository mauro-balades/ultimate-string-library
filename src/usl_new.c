
#include "usl.h"
#include <stdlib.h>

usl usl_new(size_t size) {
    // we allocate 4 extra bytes for the size of the usl
    usl usl = malloc(size + USL_SIZE);
    if (usl == NULL)
        return NULL;
    return usl;
}
