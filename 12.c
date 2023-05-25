#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<pwd.h>
#include<time.h>


void filestat(const char *filename){
    struct stat file_stat;
    int status = stat(filename,&file_stat);

    if(status==0){
        printf("\nFile name: %s",filename);
        
        printf("\nFile uid: %u",file_stat.st_uid);

        printf("\nFile gid: %u",file_stat.st_gid);

        printf("\nFile size %lld",file_stat.st_size);

        printf("\nLast modified time: %s",file_stat.st_mtime);

        printf("\nLast access time: %s",file_stat.st_atime);

        printf("\nLast status change time: %s",file_stat.st_ctime);

    }else{
        printf("\nFailed to retrive file status.....");
    }
}

int main(){
    char filename[100];
    printf("\nEnter file name: ");
    scanf("%s",filename);

    filestat(filename);

    // struct stat file_stat;

    // int status = stat(filename,&file_stat);

    // if(status == 0){
    //     printf("\nFile static for %s",filename);
    //     printf("\nFile type: ");

    //     if(S_ISREG(file_stat.st_mode))
    //         printf("\nRegular file");
    //     else if(S_ISCHR(file_stat.st_mode))
    //         printf("\nCharacter Device");
    //     else if(S_ISDIR(file_stat.st_mode))
    //         printf("\nFile directory");
    //     else if(S_ISBLK(file_stat.st_mode)){
    //         printf("\nBlock device");
    //     }
    //     else if(S_ISFIFO(file_stat.st_mode)){
    //         printf("\nFIFO (name pipe)");
    //     }else if(S_ISLNK(file_stat.st_mode)){
    //         printf("\nSymbolic link");
    //     }
    //     else if(S_ISSOCK(file_stat.st_mode)){
    //         printf("\nSocket");
    //     }
    //     else{
    //         printf("\nUnknown");
    //     }

    //     printf("\nFile access permission (FAP): %o\n",file_stat.st_mode & 0777);
    // }else
    //     printf("\nFailed to retrive file stat for %s",filename);

    return 0;

}