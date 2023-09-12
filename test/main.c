#include "../src/usl.h"

int main() {
    usl usl = usl_from("Hello, World!");
    printf("%s\n", usl_len(usl));
    usl_free(usl);
    return 0;
}