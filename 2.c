#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t child;
    char login[50], password[50];

    child = vfork();

    if(child == -1){
        perror("fork");
        return 1;
    }
    else if(child == 0){
        printf("\nChild process - Enter Login Name: ");
        scanf("%s",login);
        printf("\nChild process - login name : %s",login);

        _exit(0);
    }
    else{
        printf("\nparent process - Enter password: ");
        scanf("%s",password);
        printf("\nparent prcess - Password: %s",password);

        wait(NULL);
    }

    return 0;
}