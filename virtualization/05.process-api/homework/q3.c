#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello\n");
    exit(0);
  } else {
    sleep(1);
    //int wc = wait(NULL);
    printf("goodbye\n");
  }
  return 0;

}
