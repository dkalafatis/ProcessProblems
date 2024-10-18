#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;
    int num1 = 3, num2 = 4; // The two numbers to sum

    pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        int sum = num1 + num2;
        // Exit with the sum as the exit code (0-255)
        exit(sum);
    } else {
        // Parent process
        wait(&status); // Wait for child to finish
        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            printf("Child process terminated with exit code: %d\n", exit_code);
            printf("The sum of %d and %d is: %d\n", num1, num2, exit_code);
        } else {
            printf("Child process did not terminate normally.\n");
        }
    }

    return 0;
}
