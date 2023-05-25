#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

void handle_signal(int signum){
    printf("Received signal %d",signum);
}

int main(){

    pid_t child;

    child = fork();

    if(child<0){
        perror("fork");
        return 1;
    }else if(child == 0){
        printf("\nChild process: %d",getpid());

        sleep(3);

        signal(SIGUSR1,handle_signal);

        printf("\nWaiting for signal from parent ");
        while(1){

        }
    }else{

        printf("\nParent process pid: %d",getpid());

        sleep(1);

        printf("\nSending signal SIGUSR1 to child process (pid: %d)",child);

        kill(child,SIGUSR1);

        sleep(2);

        printf("\nTerminated child process");

        kill(child,SIGTERM);
    }


    return 0;

}