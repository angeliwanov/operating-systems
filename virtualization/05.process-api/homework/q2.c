#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
  int fd = open("q2-output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed");
    exit(1);
  } else if (rc == 0) {
    char buf1[] = "child is writing...\n";
    write(fd, buf1, sizeof(buf1) - 1);
    printf("child pid:%d\n", (int) getpid());
  } else {
    wait(NULL);
    char buf2[] = "parent is writing...\n";
    write(fd, buf2, sizeof(buf2) - 1);
    printf("parent of %d pid:%d\n", rc, (int) getpid());
  }
  return 0;
}
