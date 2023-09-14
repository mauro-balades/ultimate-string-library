
#include "usl.h"
#include <stdlib.h>

char* usl_as_str(usl str) {
    // we store the length of the string in *(size_t*)str
    // so we need to add sizeof(size_t) to the pointer
    return (char*)(str + USL_PADDING_SIZE);
}