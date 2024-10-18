#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    
    pid1 = fork();  // Create first child process

    if (pid1 < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    }
    else if (pid1 == 0) {
        // Inside first child process (child1)
        pid2 = fork();  // Create second child process (child2)

        if (pid2 < 0) {
            // Fork failed
            perror("fork");
            exit(1);
        }
        else if (pid2 == 0) {
            // Inside second child process (child2)
            // Display current path
            execlp("pwd", "pwd", (char *)NULL);
            perror("execlp");
            exit(1);
        }
        else {
            // Back in first child process (child1)
            // Wait for child2 to finish
            wait(NULL);
            // Display current date
            execlp("date", "date", (char *)NULL);
            perror("execlp");
            exit(1);
        }
    }
    else {
        // Back in parent process
        // Wait for child1 to finish
        wait(NULL);
    }

    return 0;
}
