/// @file usl string lib header file
/// @author Mauro Baladés <> https://github.com/mauro-balades/ultimate-string-library 

#include <stdlib.h>
#include <stddef.h>

#ifndef __USL_H__
#define __USL_H__

#define USL_SIZE 4

#ifdef __cplusplus
extern "C" {
#endif

/// @brief The usl string type.
/// @note The usl string contains the size/length of the
///       string in the first to fourth bytes.
/// @warning The usl string lib does not support null terminated
///          strings (it ignores the null character).
/// @see usl_new To create a new usl string.
typedef char* usl;

/// @brief It creates a new usl string. The differenece
///        between a usl and a normal string is that
///        a usl string is a string that does not contain
///        a null character unlike a normal string.
/// @note The usl string contains the size/length of the
///       string in the first to fourth bytes.
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
int usl_len(usl str);

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

/// @brief It returns the index of the first occurence of the
///        specified character in the usl string.
/// @param str The usl string.
/// @param ch The character to be searched.
/// @return The index of the first occurence of the specified
///         character in the usl string.
int usl_index_of(usl str, char ch);

/// @brief It returns the index of the last occurence of the
///        specified character in the usl string.
/// @param str The usl string.
/// @param ch The character to be searched.
/// @return The index of the last occurence of the specified
///         character in the usl string.
int usl_lindex_of(usl str, char ch);

/// @brief It returns the usl string as a normal C string.
/// @param str The usl string.
/// @return The usl string as a normal C string.
/// @warning The usl string lib does not support null terminated
///          strings (it ignores the null character).
/// @see usl_new To create a new usl string.
/// @example
///   usl s = usl_new();
///   char* str = usl_as_str(s);
///   free(str);
///   usl_free(s);
char* usl_as_str(usl str);

/// @brief Private function to set the size of the usl string.
/// @param str The usl string.
/// @param size The size of the usl string.
void _usl_set_size(usl str, size_t size);

#ifdef __cplusplus
}
#endif

#endif // __USL_H__
