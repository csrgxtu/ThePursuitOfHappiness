#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *p = (char *)malloc(1 * sizeof(char));
  *p = 'a';
  printf("%d\n", *p);
  //free(p);
  delete(p);

  char b = 'b';
  printf("%s\n", &b);
  return 0;
}
