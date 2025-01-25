# Pipe Task Description

You need to write a program that creates two child processes and establishes a pipe between them. The program will execute the programs specified as arguments from the command line (using `argc` and `argv`). The second child process should inherit the standard output from the main process. The behavior can be observed in the following examples:

### Example Usage:

1. **First Example:**
   ```bash
   ./prog 1 ps 1 sort
   ```
   Output:
   ```
   PID TTY          TIME CMD
   54361 pts/1    00:00:00 bash
   54388 pts/1    00:00:00 prog
   54389 pts/1    00:00:00 ps
   54390 pts/1    00:00:00 sort
   ```

2. **Second Example:**
   ```bash
   ./prog 2 ls -la 1 cat
   ```
   Output:
   ```
   total 36
   drwxrwxr-x 2 dude dude  4096 Feb 21 21:49 .
   drwxrwxr-x 6 dude dude  4096 Feb 21 20:21 ..
   -rwxrwxr-x 1 dude dude 17008 Feb 21 21:49 prog
   -rw-rw-r-- 1 dude dude   559 Feb 21 21:49 prog.c
   -rw-rw-r-- 1 dude dude  2632 Feb 21 21:49 prog.o
   ```

3. **Third Example:**
   ```bash
   ./prog 2 ls -la 1 wc
   ```
   Output:
   ```
   6  47  283
   ```

### Explanation:

For example, in `./prog 2 ls -la 1 wc`, the number `2` refers to the number of words in the first program (command) to execute, and `1` refers to the second program with one word. In the case above, the first command is `ls -la` (two words), and the second command is `wc` (one word). The program creates two child processes, connects them via a pipe, and each process runs one of the commands.

### Required Functions:
Your program must use the following functions:
- `pipe()` from `unistd.h`: to create the pipe.
- `fork()` from `unistd.h`: to create child processes.
- `close()` from `unistd.h`: to close unused file descriptors.
- `dup()` or `dup2()` from `unistd.h`: to redirect the pipe to standard input/output in the child processes.
- `execvp()` from `unistd.h`: to execute the specified programs.
- `wait()` or `waitpid()` from `sys/wait.h`: to wait for the child processes to finish.