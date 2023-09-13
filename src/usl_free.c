
#include <stdlib.h>
#include "usl.h"

void usl_free(usl usl) {
    if (usl == NULL)
        return;
    free(usl);
}
