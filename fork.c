#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork Command Failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("Child Process: %d\n", getpid());
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);
        perror("Error: execvp Failed");
        exit(1);
    } else if (pid > 0) {
        printf("Parent Process, PID: %d\n", getpid());
        int status;
        wait(&status);
        printf("Parent Process, PID: %d, Child Process terminated with status: %d\n", getpid(), status);
    }
    return 0;
}
