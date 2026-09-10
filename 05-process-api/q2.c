#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd = open("/tmp/nums.txt", O_WRONLY);
    int pid = fork();
    if (pid == 0) {
        write(fd, "child", 6);
    } else {
        write(fd, "parent", 7);
    }
}
