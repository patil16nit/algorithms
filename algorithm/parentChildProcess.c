#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    int pid;
    pid = fork();

    if (pid < 0) {
        printf("\n error ");
    } else if(pid ==0) {
        printf("\n Hello I am the child process ");
        printf("\n My pid is %d ",getpid());
    } else {
        printf("\n Hello I am the parent process ");
        printf("\n My actual pid is %d \n ",getpid());
    }
    return 0;
}
