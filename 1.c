#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int i;
    pid_t child;

    for(i=0; i<5; i++){
        child = fork();

        if(child == -1){
            perror("fork");
            return 1;
        }else if(child == 0){
            switch(i){
                case 0:
                    printf("Addition of numbers %d\n",getpid());
                    break;
                case 1:
                    printf("Substraction of numbers %d\n",getpid());
                    break;
                case 2:
                    printf("Multiplication of number %d\n",getpid());
                    break;
                case 3:
                    printf("Division of number %d\n",getpid());
                    break;
                case 4:
                    printf("Modulus of number %d\n",getpid());
                    break;;
                default:
                    break;
            }

            return 0;
        }

    }

    for(i=0; i<5; i++){
        wait(NULL);
    }

    return 0;
}

