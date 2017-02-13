#include <stdio.h>

int main(void) {
  int raw[6] = {8, 4, 7, 1, 16, 27};
  
  int i;  
  int j; 
  int swap; 
  for (i = 0; i < sizeof(raw)/sizeof(int); i++) {
    for (j = 0; j < sizeof(raw)/sizeof(int) - i; j++) {
      if (raw[j] > raw[j + 1]) {
        //swap(current, next);
        swap = raw[j];
        raw[j] = raw[j + 1];
        raw[j + 1] = swap;
      }
    }
  }

  for (i = 0; i < sizeof(raw)/sizeof(int); i++) {
    printf("%d\t", raw[i]);
  }
  printf("\n");

  return 0;
}
