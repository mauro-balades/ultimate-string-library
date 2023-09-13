
#include "usl.h"
#include <string.h>
#include <stdlib.h>

int usl_len(usl str) {
    // we store the length of the string in the first 4 bytes
    return str[0] | (str[1] << 8) | (str[2] << 16) | (str[3] << 24);
}
