#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void print_file_stat(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Failed to retrieve file statistics");
        close(fd);
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long)file_stat.st_size);
    printf("Owner UID: %u\n", file_stat.st_uid);
    printf("Group GID: %u\n", file_stat.st_gid);
    printf("Permissions: %o\n", file_stat.st_mode & 0777);

    // File type
    if (S_ISREG(file_stat.st_mode)) {
        printf("File Type: Regular File\n");
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("File Type: Directory\n");
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("File Type: Symbolic Link\n");
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("File Type: FIFO/Named Pipe\n");
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("File Type: Block Special File\n");
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("File Type: Character Special File\n");
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("File Type: Socket\n");
    } else {
        printf("File Type: Unknown\n");
    }

    close(fd);
}

int main() {
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    print_file_stat(filename);

    return 0;
}
