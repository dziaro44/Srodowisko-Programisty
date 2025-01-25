#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int a = strtol(argv[1], NULL, 10);
    int b = strtol(argv[a+2], NULL, 10);

    // Prepare arguments for the first and second commands
    char *argv1[100], *argv2[100];
    for (int i = 0; i < a; i++) {
        argv1[i] = argv[i + 2];
    }
    argv1[a] = NULL;

    for (int i = 0; i < b; i++) {
        argv2[i] = argv[i + 3 + a];
    }
    argv2[b] = NULL;

    // Create the pipe
    int p[2];
    pipe(p);

    // First child process
    if (fork() == 0) {
        close(p[0]);
        dup2(p[1], STDOUT_FILENO);
        close(p[1]);
        execvp(argv1[0], argv1);
        _exit(1);
    }

    // Second child process
    if (fork() == 0) {
        close(p[1]);
        dup2(p[0], STDIN_FILENO);
        close(p[0]);
        execvp(argv2[0], argv2);
        _exit(1);
    }

    // Close pipe in parent process as it's no longer needed
    close(p[0]);
    close(p[1]);

    // Wait for both child processes to finish
    wait(NULL);
    wait(NULL);

    return 0;
}
