#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    // create temporary file
    execlp("touch", "touch", "/tmp/nums.txt", (char*) NULL);

    close(STDOUT_FILENO);
    int fd = open("/tmp/nums.txt", O_WRONLY);

    int pid = fork();
    if (pid == 0) {
        printf("child %d\n", 100);
    } else {
        printf("parent %d\n", 42);
    }
}
