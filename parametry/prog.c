#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR_CODE -1

#define IS_GCD(x) (strcmp(x, "--gcd") == 0 || strcmp(x, "-d") == 0)
#define IS_LCM(x) (strcmp(x, "--lcm") == 0 || strcmp(x, "-m") == 0)

#define IS_HELP(x) (strcmp(x, "--help") == 0 || strcmp(x, "-h") == 0)
#define IS_QUIET(x) (strcmp(x, "--quiet") == 0 || strcmp(x, "-q") == 0)

#define FLAG_GCD (1 << 0) // 1
#define FLAG_LCM (1 << 1) // 2
#define FLAG_QUIET (1 << 3) // 8

#define IN_GCD_MODE(x) ((x & FLAG_GCD) > 0)
#define IN_LCM_MODE(x) ((x & FLAG_LCM) > 0)
#define IN_QUIET_MODE(x) ((x & FLAG_QUIET) > 0)

#define HELP_MSG "Usage: [OPTION]... [Integer1] [Integer2]\n"
	
#define swap(a,b) {tmp=a;a=b;b=tmp;}
	
int GCD(int a, int b) {
	int tmp;
	if (b>a)
		swap(a,b);
	while(b!=0) {
		a = a%b;
		swap(a,b);
	}
	return a;
}

int main(int argc, char *argv[]) {
	int flags = 0;
	
	for(int i=1;i<argc;i++) {
		if(IS_HELP(argv[i])) {
			printf("%s", HELP_MSG);
			return 0;
		}
		else if(IS_GCD(argv[i])) flags |= FLAG_GCD;
		else if(IS_LCM(argv[i])) flags |= FLAG_LCM;
		else if(IS_QUIET(argv[i])) flags |= FLAG_QUIET;
	}
	
	if(argc < 3) {
		if(!IN_QUIET_MODE(flags))
			printf("ERROR\n"); //"ERROR"
		return ERROR_CODE;
	}
	
	if(IN_GCD_MODE(flags) && IN_LCM_MODE(flags)) {
		if(!IN_QUIET_MODE(flags))
			printf("ERROR\n"); //"ERROR"
		return ERROR_CODE;
	}
	
	char *p;
	int first, second;
	long conv;
	
	conv = strtol(argv[argc-2], &p, 10);
	/*
	if (*p != '\0' || conv > INT_MAX || conv <= 0) {
		if(!IN_QUIET_MODE(flags))
			printf("ERROR\n"); //"ERROR"
		return ERROR_CODE;
	}
	*/
	first = conv;
	
	conv = strtol(argv[argc-1], &p, 10);
	/*
	if (*p != '\0' || conv > INT_MAX || conv <= 0) {
		if(!IN_QUIET_MODE(flags))
			printf("ERROR\n"); //"ERROR"
		return ERROR_CODE;
	}
	*/
	second = conv;
	
	int result = GCD(first, second);
	if(IN_LCM_MODE(flags)) {
		result = first/result;
		result *= second;
	}
	
	printf("%d\n", result);
	return 0;
}
