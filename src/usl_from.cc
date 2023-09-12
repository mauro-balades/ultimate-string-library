
#include "usl.h"
#include <string.h>
#include <stdlib.h>

usl usl_from(const char *str) {
    size_t len = strlen(str);
    usl result = (usl)usl_new(len);
    memcpy(result, str, len);
    return result;
}
