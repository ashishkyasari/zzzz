#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int alarm_exp = 0;

void alarm_handler(int signum){
    alarm_exp = -1;
}

int main(){

    int input;

    signal(SIGALRM,alarm_handler);

    alarm(5);

    printf("\nEnter input within 5s: ");
    scanf("%d",&input);

    if(alarm_exp){
        printf("\nTime limit excceded: Input ignored");
    }else{
        printf("\nINput revecived: %d",input);
    }


    return 0;
}