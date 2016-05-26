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
 * Apply Caesar cipher algorithm to `src`, a null-terminated string, storing the
 * output in `dst`, another previously allocated null-terminated string,
 * shifting characters by `shift` positions.
 */
void caesar(char* dst, char* src, int shift);

/*
 * Shift a single lowercase character `c` by `shift` positions. Rotation applies
 * since characters shifted off the alphabet - greater than 'z' - return to 'a'.
 */
char shift_char(char c, int shift);

#endif /* CAESAR_H_ */
