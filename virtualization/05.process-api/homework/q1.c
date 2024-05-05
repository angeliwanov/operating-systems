#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("parent (pid:%d)\n", (int) getpid());
  int x = 100;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("child (pid:%d)\n", (int) getpid());
    printf("child x:%d\n", x);
    x = 101;
    printf("child x:%d\n", x);
  } else {
    wait(NULL);
    printf("parent of %d (pid:%d)\n", rc, (int) getpid());
    printf("parent x:%d\n", x);
    x = 102;
    printf("parent x:%d\n", x);
  }
}
