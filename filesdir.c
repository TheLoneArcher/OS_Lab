#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY, 644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, "Hello, World!\n", 14);
    close(fd);
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }
    struct dirent *entry;
    printf("Listing files in the current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
