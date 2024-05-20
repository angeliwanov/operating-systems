#include <stdlib.h>
#include <stdio.h>

int main() {

  int* data = (int*) malloc(100 * sizeof(int));
  data[1] = 1;
  free(data[2]);
  
  exit(0);
}
