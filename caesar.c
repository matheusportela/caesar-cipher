#include "caesar.h"

void caesar(char* dst, char* src, int shift) {
    for (int i = 0; i < strlen(src); i++) {
        dst[i] = shift_char(src[i], shift);
    }

    /* Ensure trailing null character since `dst` may not have been initialized
     * yet.
     */
    dst[i] = '\0';
}

char shift_char(char c, int shift) {
    /* Character index starting from 'a' */
    int pos = c - 'a';

    /* Number of shifts for the current character */
    int delta  = pos + shift;

    if (delta < 0)
        delta += 26;
    else
        delta %= 26;

    return('a' + delta);
}
