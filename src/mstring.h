#pragma once

#include <string.h>

#include "managed.h"

typedef char *
#if defined(MC_PREFIX_STRING)
    PREFIX(string);
#   define string PREFIX(string)
#else
    string;
#endif


/**
 * @brief Creates a managed string.
 * @param str Base string to copy.
 * @param len Length of the string.
 * @return Managed pointer to the new string.
 */
static inline string mstr(const string str, int len)
{
    //+1 for the null term
    string s = PREFIX(managed_alloc)(len + 1, sizeof(char));
    let mdata = PREFIX(metadataof)(s);

    strncpy(s, str, len);

    return s;
}

///**
// * @copydoc mstr(const string, int)
// */
//overloadable static inline string mstr(const string str)
//{
//    return mstr(str, strlen(str));
//}

/**
 * @brief Concatenates a string onto a managed string.
 * @param dst Destination
 * @param src Source
 * @param len Length of the source.
 * @return Managed pointer to the new string.
 * @remarks This function does not function as base @c strncat. Instead of writing through the buffer of @c dst, this function
 * allocates a new object, and returns it.
 */
static inline string PREFIX(mstrcat)(string dst, string src, int len)
{
    let dst_mdata = PREFIX(metadataof)(dst);
    let oldlen = dst_mdata->count;
    string new = PREFIX(realloc_managed)(dst, oldlen + len + 1);
    //Already logged
    if (new == NULL)
        return NULL;

    //-1 because new has a NULL terminator
    strncpy(new + oldlen - 1, src, len);

    return new;
}

///**
// * @copydoc mstrcat(string, string, int)
// */
//overloadable static inline string mstrcat(string dst, string src)
//{
//    let dst_mdata = PREFIX(metadataof)(dst),
//        src_mdata = PREFIX(metadataof)(src);
//
//    if (dst_mdata == NULL) {
//        return NULL;
//    }
//
//    return mstrcat(dst, src, src_mdata == NULL ? strlen(src) : src_mdata->count);
//}

/**
 * @brief Copies the @c src string to the @c dst string
 * @param dst
 * @param src
 * @param len
 * @return
 */
static inline string mstrcpy(string dst, string src, int len)
{
    string new = PREFIX(realloc_managed)(dst, len);
    //Already logged
    if (new == NULL)
        return NULL;

    memcpy(new, src, len);

    return new;
}

#if defined(MC_PREFIX_STRING)
#   undef string
#endif
