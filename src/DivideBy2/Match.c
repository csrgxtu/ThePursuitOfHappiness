#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./a.out int\n");
    exit(1);
  }
  
  printf("%d\n", 21 % 2);
  return 0;
}
