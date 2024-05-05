#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
  int rc, status;
  rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("child with id:%d\n", (int) getpid());
    close(STDOUT_FILENO);
    printf("child %d\n", (int) getpid());
  } else {
    int wc = waitpid(rc, &status, WUNTRACED);
    printf("parent with id:%d waited for %d to exit\n", (int)getpid(), wc);
  }
  return 0;
}
