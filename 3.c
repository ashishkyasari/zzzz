#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t child;

    if(child == -1){
        perror("fork");
        return 1;
    }else if(child == 0){
        char *appname = "/usr/bin/google-chrome";
        char *arg[] = {appname,NULL};
        execvp(appname,arg);

        perror("execvp");
        return 1;
    }else{
        wait(NULL);
    }

    return 0;
}