
#include "usl.h"
#include <stdlib.h>

char* usl_as_str(usl str) {
    char* result = malloc(usl_len(str) + 1);
    if (result == NULL)
        return NULL;
    for (int i = 0; i < usl_len(str); i++) {
        result[i] = str[i + USL_SIZE];
    }
    result[usl_len(str)] = '\0';
    return result;
}