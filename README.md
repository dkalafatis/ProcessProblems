# Set of solved process management problems in the Unix/Linux operating system

1: Creates a child process, which in turn creates another child process. The program displays the process IDs (PIDs) of each process and ensures that the original parent process waits for the child processes to terminate before concluding execution.

2: Creates a new child process which then creates another child process. The first child process displays the current date, while the second child process displays the current path. 

3: creates a child process using fork(). The child process calculates the sum of two numbers and exits with that sum as the exit code. The parent process waits for the child to terminate using wait(), checks the termination code with WIFEXITED() and WEXITSTATUS(), and then outputs the result accordingly.

### Dependencies

* C and Linux/Unix Operating System.
