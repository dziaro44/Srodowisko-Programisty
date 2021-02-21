#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	char *argv1[100];
	char *argv2[100];
	int a, b;
	a = strtol(argv[1], NULL, 10);
	b = strtol(argv[a+2], NULL, 10);
	for(int i=0;i<a;i++) {
		argv1[i] = argv[i+2];
	}
	argv1[a] = NULL;
	for(int i=0;i<b;i++) {
		argv2[i] = argv[i+3+a];
	}
	argv2[b] = NULL;
	int p[2];
	pipe(p);
	
	if(fork() == 0) {
		close(0); 
		dup2(p[1],1);
		close(p[0]);
		execvp(argv1[0], argv1);
	}
	close(p[1]);

	if(fork() == 0) {
		dup2(p[0],0);
		close(p[1]);
		execvp(argv2[0], argv2);
	}
	close(p[0]);

	wait(NULL);
	wait(NULL);
}
