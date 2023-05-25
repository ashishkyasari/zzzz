#include<stdio.h>


int main(){

    int size;
    printf("Enter size: ");
    scanf("%d",&size);

    int tsize = size*2-1;

    for(int i=1; i<=size; i++){
        int spaces = (tsize - (2*i -1))/2;

        int stars = (2*i-1);

        for(int j=1; j<=spaces; j++){
            printf(" ");
        }

        for(int j=1; j<=stars; j++){
            printf("*");
        }

        printf("\n");
    }
}