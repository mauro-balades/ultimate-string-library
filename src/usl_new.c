
#include "usl.h"
#include <stdlib.h>

void *usl_new(size_t size) {
    void *ptr = malloc(size);
    return ptr;
}
