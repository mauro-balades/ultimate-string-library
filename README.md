# ultimate-string-library
The ultimate string library for C where it's purpose is to eliminate the use of null terminators but allow C stdlib interactivity

# How to use

```c
#include "usl.h"

int main() {
    usl str = usl_from("Hello, World!");
    usl str2 = usl_from("Hello, World!");
    usl str3 = usl_concat(str, str2);
    printf("%s\n", usl_as_str(str3));
    usl_free(str);
    usl_free(str2);
    usl_free(str3);
}
```

# How to install

```c
include(FetchContent)
FetchContent_Declare(usl
  URL https://github.com/mauro-balades/ultimate-string-library.git
)

FetchContent_MakeAvailable(usl)
target_link_libraries(${PROJECT_NAME} PRIVATE usl)
```

# How does it work?

The library uses a tipical `char*` but it also stores the length of the string in the first 4 bytes of the pointer.

### Why?

I wanted to make a string library that was easy to use and didn't require the use of null terminators. I also wanted to make it so that it was easy to convert to a `char*` so that it could be used with the C stdlib. 

The C stdlib kinda... *sucks* when it comes to strings. It's not very safe and it's very easy to make mistakes. I wanted to make a library that was easy to use and didn't require the use of null terminators. I also wanted to make it so that it was easy to convert to a `char*` so that it could be used with the C stdlib.

here's an example of the string representation:

```c
[4 bytes] [n bytes]
[length] [string]
```

```c
"Hello"
[5 bytes] [5 bytes]
[0x05] [Hello]

        H E L L O
--------------
0 0 0 5 H E L L O
```
