#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "assign5.h"

void printChildInfo(int childNum) {
    printf("Child Process %d, PID: %ld, PPID: %ld\n", 
           childNum, (long)getpid(), (long)getppid());
}

int main() {
    pid_t pid;
    int i;

    for (i = 1; i <= 5; i++) {
        pid = fork();

        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }
        else if (pid == 0) {
            printChildInfo(i);
            exit(0);
        }
    }

    for (i = 0; i < 5; i++) {
        wait(NULL);
    }

    return 0;
}
