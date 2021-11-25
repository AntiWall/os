#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void fork_fun();
void exec_fun();
int main() {
    fork_fun();
    exec_fun();
    return 0;
}

void fork_fun() {
    int pid = fork();
    if (pid > 0) {
        printf ("parent: child = %d\n", pid);
        pid = wait((int *) 0);
    printf ("child %d is done\n", pid);
    } else if (pid == 0) {
        printf ("child exiting\n");
        exit(0);
    } else {
        printf ("fork error\n");
    }
}

void exec_fun(){
    char *argv[3];
    argv[0] = "echo";
    argv[1] = "hello";
    argv[2] = 0;
    execv("/bin/echo", argv);
    printf("exec error\n");
}