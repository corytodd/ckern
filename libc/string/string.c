#include "string.h"



int memcmp(const void *__s1, const void *__s2, size_t __n) {

	// must cast the void* into someting we can index
	const unsigned char *s1 = (const unsigned char*) __s1;
	const unsigned char *s2 = (const unsigned char*) __s2;

	for ( size_t i = 0; i < __n; i++ ) {
		if ( s1[i] < s2[i] )
			return -1;
		else if ( s2[i] < s1[i] )
			return 1;
	}
	return 0;
}

void* memcpy(void *__restrict __to, const void *__restrict __src, size_t __n) {

	unsigned char *to = (unsigned char*) __to;
	const unsigned char *src = (const unsigned char*) __src;

	while(__n-- > 0)
		*to++ = *src++;

	return __to;

}


void* memmove(void* __dst, const void* __src, size_t __n) {

	unsigned char* dst = (unsigned char*) __dst;
	const unsigned char* src = (const unsigned char*) __src;

	if ( dst < src )
		for ( size_t i = 0; i < __n; i++ )
			dst[i] = src[i];
	else
		for ( size_t i = __n; i != 0; i-- )
			dst[i-1] = src[i-1];

	return __dst;

}

void* memset(void* __dst, int c, size_t __n) {

	unsigned char* dst = (unsigned char*) __dst;

	while(__n-- > 0)
		*dst++ = (unsigned char)c;

	return __dst;

}

size_t strlen(const char* __str) {

	size_t c = 0;
	while(__str[c]) { c++; }
	return c;

}
