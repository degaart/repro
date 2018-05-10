#define _GNU_SOURCE

#include "reprolib.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* str_encode_hex2(const void* buffer, size_t len, bool lcase)
{
    size_t strbuffer_len = (len * 2) + 1;
    char* strbuffer = malloc(strbuffer_len);
    if(!strbuffer)
        return NULL;
    
    const uint8_t* bytebuffer = (uint8_t*)buffer;
    const uint8_t* end = bytebuffer + len;
    char* p = strbuffer;
    const char* fmt = lcase ? "%02x" : "%02X";
    for(const uint8_t* byte = bytebuffer; byte < end; byte++) {
        sprintf(p, fmt, *byte);
        p+=2;
    }
    *p = '\0';
    return strbuffer;
}
