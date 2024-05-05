#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char* argv[]){
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if ( rc == 0) {
    int wp = wait(NULL);
    printf("child pid:%d wp:%d\n", (int) getpid(), wp);
    char *myargs[3];
    myargs[0] = strdup("ls");
    myargs[1] = strdup("-l");
    myargs[2] = NULL;
    //execl("/bin/ls", "ls", "-l", (char*) 0);
    //execv("/bin/ls", myargs);
    //execle("/bin/ls", "ls", "-l", (char*) 0, NULL);
    //execve("/bin/ls", myargs, NULL);
    //execlp("ls", "ls", "-l", (char*) 0);
    execvp("ls", myargs);
  } else {
    int wc = wait(NULL);
    printf("parent %d\n", wc);
  }
  return 0;
}
