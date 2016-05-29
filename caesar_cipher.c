/**
 * Caesar cipher via command-line interface.
 */

#include <stdlib.h>
#include <stdio.h>

#include "caesar.h"

void parse_args(int argc, char** argv);
void print_help();
void run_caesar(char* input, int shift);

int main(int argc, char** argv) {
    parse_args(argc, argv);
    return 0;
}

void parse_args(int argc, char** argv) {
    if (argc == 1) {
        printf("\"shift\" and \"text\" arguments are missing\n");
        goto error;
    } else if (argc == 2) {
        printf("\"text\" argument is missing\n");
        goto error;
    } else if (argc > 3) {
        printf("Too many arguments\n");
        goto error;
    }

    int shift;
    int result = sscanf(argv[1], "%d", &shift);

    if (result != 1) {
        printf("\"shift\" argument must be an integer\n");
        goto error;
    }

    char* input = argv[2];

    if (strlen(input) < 1) {
        printf("\"input\" must have at least one character\n");
        goto error;
    }

    run_caesar(input, shift);
    return;

error:
    print_help();
}

void print_help() {
    printf("Usage: caesar_cipher shift text\n");
}

void run_caesar(char* input, int shift) {
    char* output = malloc(strlen(input) * sizeof(char));
    caesar(output, input, shift);
    printf("%s\n", output);
    free(output);
}
