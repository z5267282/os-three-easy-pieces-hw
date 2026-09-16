#include <stdio.h>
#include <unistd.h>

int main(void) {
  int x = 42;
  int rc = fork();

  // child
  if (rc == 0) {
    x = 100;
    printf("value in the child: %d\n", x);
  }
  // parent
  else {
    printf("value in the parent: %d\n", x);
  }

  return 0;
}
