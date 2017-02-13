#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int log22(int value) {
  if (value == 1) {
    return 0;
  } else {
    return 1 + log22(value >> 1);
  }
}

int main(void) {
  int Num = 74;
  
  if (Num&(Num-1)) {
    printf("no\n");
  } else {
    printf("yes: %d\n", log22(Num));
  }  

  return 0;
}
