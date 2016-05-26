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
    char base;
    int length;

    /* Number of char families accepted by the system */
    int num_families = sizeof(CHAR_FAMILIES)/sizeof(struct char_family);

    for (int i = 0; i < num_families; i++) {
        if (is_from_family(c, CHAR_FAMILIES[i])) {
            base = CHAR_FAMILIES[i].begin;

            /* Length must include the end character. Hence, sum 1. */
            length = CHAR_FAMILIES[i].end - CHAR_FAMILIES[i].begin + 1;
            return shift_generic_char(c, shift, base, length);
        }
    }

    return ' ';
}

int is_from_family(char c, struct char_family family) {
    return (c >= family.begin && c <= family.end);
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
