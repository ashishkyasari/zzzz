#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        printf("This is the child process. PID: %d\n", getpid());
        exit(123); // Child process exits with status 123
    } else {
        // Parent process
        printf("This is the parent process. PID: %d\n", getpid());
        printf("Waiting for child process (PID: %d) to complete...\n", child_pid);
        wait(&status); // Wait for the child process to complete

        if (WIFEXITED(status)) {
            // Child process terminated normally
            int exit_status = WEXITSTATUS(status);
            printf("Child process completed with exit status: %d\n", exit_status);
        } else if (WIFSIGNALED(status)) {
            // Child process terminated by a signal
            int signal_number = WTERMSIG(status);
            printf("Child process terminated by signal: %d\n", signal_number);
        }
    }

    return 0;
}
