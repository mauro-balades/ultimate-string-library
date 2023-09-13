
#include <stdlib.h>
#include <stddef.h>
#include "usl.h"

char usl_at(usl str, size_t index) {
    size_t length = usl_len(str);
    if (index >= length) // we go back to the beginning of the string
        return NULL;
    // we add 4 to the index because the first 4 bytes are the length
    // example:
    // usl = "hello"
    // ---------------
    //  | h e l l o |
    // ---------------
    //  | 5 0 0 0 0 |
    // ---------------
    return ((char*)((void*)str+4))[index];
}
