#include <string.h>
#include <unistd.h>

int main(void) {
    // these will all replace the current process
    // uncomment whichever one you want to see

    // execl("/usr/bin/seq", "seq", "5", (char*) NULL);

    char* env[2];
    env[0] = strdup("LIMIT=3");
    env[1] = NULL;
    execle("/usr/bin/seq", "seq", "$LIMIT", (char*) NULL, env);
}
