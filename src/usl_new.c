
#include "usl.h"
#include <stdlib.h>

usl usl_new(size_t size) {
    void *ptr = malloc(size);
    return (char*)ptr;
}
