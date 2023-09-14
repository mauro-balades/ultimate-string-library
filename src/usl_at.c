
#include <stdlib.h>
#include <stddef.h>
#include "usl.h"

char usl_at(usl str, size_t index) {
    // we store the length of the string in *(size_t*)str
    // so we need to add sizeof(size_t) to the pointer
    if (index >= usl_len(str))
        return '\0';
    
    // we return the character at the given index
    return usl_as_str(str)[index];
}
