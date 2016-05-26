/**
 * Caesar cipher algorithm implementation for didactic purposes.
 * Author: Matheus Vieira Portela
 * GitHub: https://github.com/matheusportela/
 *
 * Caesar cipher applies one of the most basic cryptographic algorithms created.
 * It starts by selecting an integer, followed by rotating each individual
 * character by the defined amount.
 *
 * Examples:
 * "abcdef" -> 1 -> "bcdefg"
 * "abcdef" -> 3 -> "defghi"
 * "vwxyz" -> 1 -> "wxyza"
 */

#ifndef CAESAR_H_
#define CAESAR_H_

#include <string.h>

/*
 * Character family is an interval between two characters where a character can
 * be shifted.
 */
struct char_family {
    char begin;
    char end;
};

/* All possible character families.
 */
static struct char_family CHAR_FAMILIES[] = {
    { .begin = 'a', .end = 'z' },
    { .begin = 'A', .end = 'Z' },
    { .begin = '0', .end = '9' }
};

/* Apply Caesar cipher algorithm to `src`, a null-terminated string, storing the
 * output in `dst`, another previously allocated null-terminated string,
 * shifting characters by `shift` positions.
 */
void caesar(char* dst, char* src, int shift);

/* Shift a single character `c` by `shift` positions with rotation to avoid
 * out-of-bounds characters.
 */
char shift_char(char c, int shift);

/* Identifies whether a given character `c` belongs to a given character
 * family.
 */
int is_from_family(char c, struct char_family family);

/* Shift a single character `c` by `shift` positions with rotation to avoid
 * out-of-bounds characters. `base` defines the first possible character and
 * `len` the number of the characters for the given type.
 */
char shift_generic_char(char c, int shift, char base, char length);

#endif /* CAESAR_H_ */
