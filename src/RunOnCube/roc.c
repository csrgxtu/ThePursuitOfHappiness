#include <stdio.h>

int roc(int m, int n) {
  if (m == 0 && n == 0) {
    return 0;
  }
  if (m == 1 && n == 0) {
    return 1;
  }
  if (m == 0 && n == 1) {
    return 1;
  }
  if (m == 0) {
    return roc(m, n - 1);
  }
  if (n == 0) {
    return roc(m - 1, n);
  }
  return roc(m - 1, n) + roc(m, n - 1);
}

int main(void) {
  printf("%d\n", roc(8, 8)); 
  return 0;
}
