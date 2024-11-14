#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int var = 0;

int main(){
    pid_t pid;

    pid = fork();
    if (pid < 0) {

        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // copy-on-write
        var += 10;
        printf("var from child process: %d\n", var);
    }
    else{
        sleep(2);
        var += 1;
        printf("var from parent process: %d\n", var);
    }
    return 0;
}
