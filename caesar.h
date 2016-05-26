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

enum char_type { LOWER, UPPER, UNDEFINED };

/* Apply Caesar cipher algorithm to `src`, a null-terminated string, storing the
 * output in `dst`, another previously allocated null-terminated string,
 * shifting characters by `shift` positions.
 */
void caesar(char* dst, char* src, int shift);

/* Shift a single character `c` by `shift` positions with rotation to avoid
 * out-of-bounds characters.
 */
char shift_char(char c, int shift);

/* Identify the type of the given character, such as lowercase and uppercase.
 */
enum char_type identify_char(char c);

/* Shifts a lowercase character.
 */
char shift_char_lower(char c, int shift);

/* Shifts an uppercase character.
 */
char shift_char_upper(char c, int shift);

/* Shift a single character `c` by `shift` positions with rotation to avoid
 * out-of-bounds characters. `base` defines the first possible character.
 */
char shift_char_with_base(char c, int shift, char base);

#endif /* CAESAR_H_ */
