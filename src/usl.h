/// @file usl string lib header file
/// @author Mauro Baladés <> https://github.com/mauro-balades/ultimate-string-library 

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#ifndef _USL_H_
#define _USL_H_

#if !defined(USL_PADDING_SIZE) || !defined(USL_PADDING_TYPE)
#define USL_PADDING_SIZE 2
#define USL_PADDING_TYPE uint8_t
#endif

#ifdef __cplusplus
extern "C" {
#endif

/// @brief The usl string type.
/// @note The usl string contains the size/length of the
///       string in the string it's self bytes.
/// @see usl_new To create a new usl string.
typedef uint8_t* usl;

/// @brief It creates a new usl string. The differenece
///        between a usl and a normal string is that
///        a usl string is a string that does not contain
///        a null character unlike a normal string.
/// @note The usl string contains the size/length of the
///       string in the string it's self bytes.
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
/// @param str The usl string to be freed.
void usl_free(usl str);

/// @brief It returns the length of the usl string.
/// @param str The usl string.
/// @return The length of the usl string.
size_t usl_len(usl str);

/// @brief It returns the character at the specified index.
/// @param str The usl string.
/// @param index The index of the character.
/// @note If the index is out of bounds, it will return
///       the null character (aka NULL or '\0').
/// @return The character at the specified index.
char usl_at(usl str, size_t index);

/// @brief It returns the substring of the usl string.
/// @param str The usl string.
/// @param start The starting index of the substring.
/// @param end The ending index of the substring.
/// @note If the start index is out of bounds, it will return
///       the null character (aka NULL or '\0').
/// @return The substring of the usl string.
usl usl_substring(usl str, size_t start, size_t end);

/// @brief It returns the usl string as a normal C string.
/// @param str The usl string.
/// @return The usl string as a normal C string.
/// @warning The usl string lib does not support null terminated
///          strings (it ignores the null character).
/// @see usl_new To create a new usl string.
/// @note NULL may be returned if `malloc` fails.
/// @example
///   usl s = usl_new();
///   char* str = usl_as_str(s);
///   free(str);
///   usl_free(s);
char* usl_as_str(usl str);

/// @brief It concatenates two usl strings.
/// @param str1 The first usl string.
/// @param str2 The second usl string.
/// @return The concatenated usl string.
/// @warning The usl string lib does not support null terminated
///          strings (it ignores the null character).
/// @see usl_new To create a new usl string.
/// @note NULL may be returned if `malloc` fails.
/// @example
///   usl s1 = usl_from("Hello");
///   usl s2 = usl_from(" World!");
///   usl s3 = usl_concat(s1, s2);
usl usl_concat(usl str1, usl str2);

/// @brief Private function to set the size of the usl string.
/// @param str The usl string.
/// @param size The size of the usl string.
void _usl_set_size(usl str, size_t size);

#ifdef __cplusplus
}
#endif

#endif // _USL_H_
