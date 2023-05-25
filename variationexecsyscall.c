#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    char *args[] = {"ls","-l",NULL};

    execl("/bin/ls","ls","-l",NULL);

    execle("/bin/ls","ls","-l",NULL);

    execlp("ls","ls","-l",NULL);

    execv("/bin/ls",args);

    execvp("ls",args);

    fprintf(stderr,"exec() failed \n");
    exit(1);

    return 0;
}