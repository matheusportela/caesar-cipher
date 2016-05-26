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
    switch (identify_char(c)) {
        case LOWER:
            return shift_char_lower(c, shift);
        case UPPER:
            return shift_char_upper(c, shift);
        case NUM:
            return shift_char_num(c, shift);
        default:
            return ' ';
    }
}

enum char_type identify_char(char c) {
    if (c >= 'a' && c <= 'z')
        return LOWER;
    else if (c >= 'A' && c <= 'Z')
        return UPPER;
    else if (c >= '0' && c <= '9')
        return NUM;
    return UNDEFINED;
}

char shift_char_lower(char c, int shift) {
    return shift_generic_char(c, shift, 'a', 26);
}

char shift_char_upper(char c, int shift) {
    return shift_generic_char(c, shift, 'A', 26);
}

char shift_char_num(char c, int shift) {
    return shift_generic_char(c, shift, '0', 10);
}

char shift_generic_char(char c, int shift, char base, char length) {
    /* Character index starting from 'a' */
    int pos = c - base;

    /* Number of shifts for the current character */
    int delta  = (pos + shift) % length;

    /* When character is at the beginning of the alphabet, such as 'a' and shift
     * is negative, delta becomes a negative number which generates characters
     * out-of-bounds instead of rotating to the end of the alphabet. This must
     * be corrected.
     */
    if (delta < 0)
        delta += length;

    return(base + delta);
}
