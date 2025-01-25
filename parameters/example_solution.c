#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR_CODE -1

#define IS_GCD(x) (strcmp(x, "--gcd") == 0 || strcmp(x, "-d") == 0)
#define IS_LCM(x) (strcmp(x, "--lcm") == 0 || strcmp(x, "-m") == 0)
#define IS_HELP(x) (strcmp(x, "--help") == 0 || strcmp(x, "-h") == 0)
#define IS_QUIET(x) (strcmp(x, "--quiet") == 0 || strcmp(x, "-q") == 0)

#define FLAG_GCD (1 << 0)
#define FLAG_LCM (1 << 1)
#define FLAG_QUIET (1 << 3)

#define IN_GCD_MODE(x) ((x & FLAG_GCD) > 0)
#define IN_LCM_MODE(x) ((x & FLAG_LCM) > 0)
#define IN_QUIET_MODE(x) ((x & FLAG_QUIET) > 0)

#define HELP_MSG "Usage: [OPTION]... [Integer1] [Integer2]\n"
#define SWAP(a, b) { int tmp = a; a = b; b = tmp; }

int GCD(int a, int b) {
    if (b > a) SWAP(a, b);
    while (b != 0) {
        a = a % b;
        SWAP(a, b);
    }
    return a;
}

void parse_flags(int argc, char *argv[], int *flags) {
    for (int i = 1; i < argc; i++) {
        if (IS_HELP(argv[i])) {
            printf("%s", HELP_MSG);
            exit(0);
        }
        if (IS_GCD(argv[i])) *flags |= FLAG_GCD;
        else if (IS_LCM(argv[i])) *flags |= FLAG_LCM;
        else if (IS_QUIET(argv[i])) *flags |= FLAG_QUIET;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        if (!IN_QUIET_MODE(0)) {
            printf("ERROR\n");
        }
        return ERROR_CODE;
    }

    int flags = 0;
    parse_flags(argc, argv, &flags);

    if (IN_GCD_MODE(flags) && IN_LCM_MODE(flags)) {
        if (!IN_QUIET_MODE(flags)) {
            printf("ERROR\n");
        }
        return ERROR_CODE;
    }

    char *endptr;
    long conv = strtol(argv[argc - 2], &endptr, 10);
    int first = (int)conv;
    conv = strtol(argv[argc - 1], &endptr, 10);
    int second = (int)conv;

    if (conv == 0 || first == 0 || second == 0) {
        if (!IN_QUIET_MODE(flags)) {
            printf("ERROR\n");
        }
        return ERROR_CODE;
    }

    int result = GCD(first, second);
    if (IN_LCM_MODE(flags)) {
        result = first / result;
        result *= second;
    }

    printf("%d\n", result);
    return 0;
}
