#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
 
int actual = 1;
int parent;
int n;

void forking() {
	if(2*actual <= n) {
		if(fork() == 0) {
			actual = 2*actual;
			forking();
			sleep(10000);
			exit(0);
		}
		else {
			if(2*actual+1 <= n) {
				if(fork() == 0) {
					actual = 2*actual+1;
					forking();
					sleep(10000);
				}
			}
		}
	}
}

int main() {
	
	scanf("%d", &n);
	parent = getpid();
	
	char snum[10];
	char cmd[50];
	sprintf(snum, "%d", parent);
	cmd[0] = 0;
	strcat(cmd, "pstree -p ");
	strcat(cmd, snum);
	
	forking();
	sleep(1);
	system(cmd);
}
