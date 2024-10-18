#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    /* Parent process creates the first child process */
    pid1 = fork();

    if (pid1 < 0) {
        /* Fork failed */
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        /* First child process */
        printf("Child1 process: PID=%d, Parent PID=%d\n", getpid(), getppid());

        /* First child creates the second child process */
        pid2 = fork();

        if (pid2 < 0) {
            /* Fork failed */
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid2 == 0) {
            /* Second child process */
            printf("Child2 process: PID=%d, Parent PID=%d\n", getpid(), getppid());
            /* Perform some task if needed */
            exit(EXIT_SUCCESS);
        } else {
            /* First child waits for the second child to terminate */
            waitpid(pid2, NULL, 0);
            exit(EXIT_SUCCESS);
        }
    } else {
        /* Parent process */
        printf("Parent process: PID=%d, Child1 PID=%d\n", getpid(), pid1);

        /* Parent waits for the first child to terminate */
        waitpid(pid1, NULL, 0);
        printf("Parent process: Child processes have terminated.\n");
        exit(EXIT_SUCCESS);
    }
}
