#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int rc = fork();
    if (rc == 0) {
        printf("hello\n");
        kill(rc, SIGCONT);
    } else {
        printf("goodbye\n");
    }
    return 0;
}
