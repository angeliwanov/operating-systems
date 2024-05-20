#include <stdlib.h>
#include <stdio.h>

int main() {
  int *ptr = (int *) malloc(10*sizeof(int));
  ptr[1] = 1;
  printf("%d\n", ptr[1]);
  return 0;
}
