/// @file usl string lib header file
/// @author Mauro Baladés <> https://github.com/mauro-balades/ultimate-string-library 

#include <stdlib.h>
#include <stddef.h>

#ifndef __USL_H__
#define __USL_H__

/// @brief The usl string type.
/// @note The usl string contains the size/length of the
///       string in the first and second byte.
/// @warning The usl string lib does not support null terminated
///          strings (it ignores the null character).
/// @see usl_new To create a new usl string.
typedef char* usl;

/// @brief It creates a new usl string. The differenece
///        between a usl and a normal string is that
///        a usl string is a string that does not contain
///        a null character unlike a normal string.
/// @note The usl string contains the size/length of the
///       string in the first and second byte.
/// @param size The size of the usl string.
/// @return A new usl string.
/// @warning The usl string lib does not support null terminated
///          strings (it ignores the null character).
/// @see usl_as_str To convert a usl string to a normal C string.
/// @example
///   usl s = usl_new(10);
///   usl_free(s);
usl usl_new(size_t size);

/// @brief It creates a new usl string from a normal C string.
/// @param str The normal C string.
/// @return A new usl string.
/// @warning The usl string lib will remove the null character
///          from the normal C string.
/// @see usl_as_str To convert a usl string to a normal C string.
/// @example
///   usl s = usl_from("Hello World!");
///   usl_free(s);
usl usl_from(const char* str);

/// @brief It frees the usl string.
/// @param usl The usl string to be freed.
void usl_free(usl);

/// @brief It returns the length of the usl string.
/// @param usl The usl string.
/// @return The length of the usl string.
int usl_len(usl);

/// @brief It returns the character at the specified index.
/// @param usl The usl string.
/// @param index The index of the character.
/// @return The character at the specified index.
char usl_char_at(usl, int);

/// @brief It returns the substring of the usl string.
/// @param usl The usl string.
/// @param start The starting index of the substring.
/// @param end The ending index of the substring.
/// @return The substring of the usl string.
usl usl_substring(usl, int, int);

/// @brief It returns the index of the first occurence of the
///        specified character in the usl string.
/// @param usl The usl string.
/// @param ch The character to be searched.
/// @return The index of the first occurence of the specified
///         character in the usl string.
int usl_index_of(usl, char);

/// @brief It returns the index of the last occurence of the
///        specified character in the usl string.
/// @param usl The usl string.
/// @param ch The character to be searched.
/// @return The index of the last occurence of the specified
///         character in the usl string.
int usl_last_index_of(usl, char);

/// @brief It returns the usl string as a normal C string.
/// @param usl The usl string.
/// @return The usl string as a normal C string.
/// @warning The usl string lib does not support null terminated
///          strings (it ignores the null character).
/// @see usl_new To create a new usl string.
/// @example
///   usl s = usl_new();
///   char* str = usl_as_str(s);
///   free(str);
///   usl_free(s);
char* usl_as_str(usl);

#endif // __USL_H__
