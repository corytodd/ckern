#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * The memcmp() function compares the first n bytes (each interpreted as
 *        unsigned char) of the memory areas s1 and s2
 *  
 * The memcmp() function returns an integer less than, equal to, or
 *     greater than zero if the first n bytes of s1 is found, 
 *     respectively, to be less than, to match, or be greater than the 
 *     first n bytes of s2.
 *
 *     For a nonzero return value, the sign is determined by the sign of
 *     the difference between the first pair of bytes (interpreted as
 *     unsigned char) that differ in s1 and s2.
 *
 *     If n is zero, the return value is zero.
 */
int memcmp(const void*, const void*, size_t);


/**
 * The memcpy() function copies n bytes from memory area src to memory
 *     area dest.  The memory areas must not overlap.  Use memmove(3) if 
 * 	   the memory areas do overlap.
 * 
 * The memcpy() function returns a pointer to dest. 
 */
void* memcpy(void* __restrict, const void* __restrict, size_t);

/**
 * The memmove() function copies n bytes from memory area src to memory
 *     area dest.  The memory areas may overlap: copying takes place as
 *     though the bytes in src are first copied into a temporary array 
 *     that does not overlap src or dest, and the bytes are then copied 
 *     from the temporary array to dest.
 * 
 * The memmove() function returns a pointer to dest. 
 */ 
void* memmove(void*, const void*, size_t);


/**
 *  The memset() function fills the first n bytes of the memory area
 *      pointed to by s with the constant byte c.
 * 
 * The memset() function returns a pointer to the memory area s.
 */ 
void* memset(void*, int, size_t);

/**
 * The strlen() function calculates the length of the string pointed to
 *    by s, excluding the terminating null byte ('\0').
 * 
 * The strlen() function returns the number of characters in the string
 *    pointed to by s.
 */ 
size_t strlen(const char*);

#ifdef __cplusplus
}
#endif

#endif
