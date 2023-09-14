
#include "usl.h"
#include <string.h>
#include <stdlib.h>

size_t usl_len(usl str) {
    return *(USL_PADDING_TYPE*)str;
}
