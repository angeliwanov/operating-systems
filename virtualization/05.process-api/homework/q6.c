#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char* argv[]){
  int wstatus;
  int rc = fork();
  printf("new rc: %d\n", rc);
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if ( rc == 0) {
    printf("child pid:%d\n", (int) getpid());
  } else {
    int wc = waitpid(rc, &wstatus, WUNTRACED);
    printf("parent %d\n", wc);
  }
  return 0;
}
