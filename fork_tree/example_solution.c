#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int parent_pid;
int n;

void fork_tree(int current_node) {
    if (2 * current_node <= n) { // Left child
        pid_t pid_left = fork();
        if (pid_left == 0) {
            fork_tree(2 * current_node);
            sleep(10); // Simulation of child process work
            exit(0);
        }
    }

    if (2 * current_node + 1 <= n) { // Right child
        pid_t pid_right = fork();
        if (pid_right == 0) {
            fork_tree(2 * current_node + 1);
            sleep(10); // Simulation of child process work
            exit(0);
        }
    }
}

int main() {
    // Read number of processes
    scanf("%d", &n);

    // Get parent process ID
    parent_pid = getpid();

    // Prepare command to display process tree
    char snum[10];
    char cmd[50];
    snprintf(snum, sizeof(snum), "%d", parent_pid);
    snprintf(cmd, sizeof(cmd), "pstree -p %s", snum);

    // Start tree creation from the root (1st node)
    fork_tree(1);

    // Sleep to allow all child processes to be created
    sleep(1);

    // Display the process tree using pstree command
    system(cmd);

    return 0;
}
