
#include "usl.h"
#include <stdlib.h>

usl usl_new(size_t size) {
    // we allocate 2 extra bytes for the size of the usl
    usl usl = malloc(size + 2);
    usl[0] = size;
    usl[1] = 0;
    return usl + 2; // we return the pointer to the first element of the usl
}
