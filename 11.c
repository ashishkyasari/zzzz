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
    int ala;

    printf("\nEnter alarm time: ");
    scanf("%d",&ala);

    signal(SIGALRM,alarm_handler);

    alarm(ala);

    printf("\nAlarm set for %d sec",ala);

    while(!alarm_exp){

    }

    printf("\nProgram exited");
}