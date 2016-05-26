#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "caesar.h"

#define DEBUG 1

void test_caesar(char* input, char* expected, int shift) {
    char result[strlen(expected)];
    caesar(result, input, shift);

    if (DEBUG) {
        printf("-------------------\n");
        printf("Shift: %d\n", shift);
        printf("Input: %s\n", input);
        printf("Expected: %s\n", expected);
        printf("Result: %s\n", result);
        printf("-------------------\n");
    }

    assert(strcmp(result, expected) == 0);
}

int main() {
    /* Lowercase with positive shifts */
    test_caesar("abcdef", "abcdef", 0);
    test_caesar("abcdef", "bcdefg", 1);
    test_caesar("abcdef", "cdefgh", 2);
    test_caesar("abcdef", "abcdef", 26);
    test_caesar("abcdef", "bcdefg", 27);
    test_caesar("vwxyz", "wxyza", 1);

    /* Empty inputs */
    test_caesar("", "", 0);
    test_caesar("", "", 1);

    /* Lowercase with negative shifts */
    test_caesar("bcdefg", "abcdef", -1);
    test_caesar("cdefgh", "abcdef", -2);
    test_caesar("abcdef", "zabcde", -1);

    /* Uppercase with positive shifts */
    test_caesar("ABCDEF", "ABCDEF", 0);

    printf("Caesar cipher passed all tests\n");
    return(0);
}
