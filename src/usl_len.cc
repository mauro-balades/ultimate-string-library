
#include "usl.h"
#include <string.h>
#include <stdlib.h>

int usl_len(usl str) {
    // we store the length of the string in the first 16 bits of the first
    // byte of the string
    return (int16_t*)((void*)str);
}
