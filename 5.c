#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t child;

    child = fork();

    if(child==-1){
        perror("fork");
        return 1;
    }else if(child==0){
        printf("\nThis is the child process: %d",getpid());
        sleep(3);
        exit(0);

    }else{
        printf("\nThe parent process is runing: %d",getpid());
        printf("\nWaiting for child process {pid: %d} to complete ...",child);
        wait(0);
        printf("\nChild process Completed");
    }

    return 0;
}