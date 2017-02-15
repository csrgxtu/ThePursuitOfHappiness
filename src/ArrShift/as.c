#include <stdio.h>

int reverse(int *a, int b, int c) {
  for (; b < c; b++, c--) {
    int temp = a[c];
    a[c] = a[b];
    a[b] = temp;
  }

  return 0;
}

int main(void) {
  int arr[3] = {1, 2, 3};
  int shift = 2;

  // reverse(arr, 0, 4);
  // reverse(A, A + N - k);
  // reverse(A + N - k, A + N);
  // reverse(A, A + N);
  reverse(arr, 0, 3 - shift - 1);
  reverse(arr, 3 - shift, 3 - 1);
  reverse(arr, 0, 3 - 1);

  int i;
  for (i = 0; i < 3; i++) {
    printf("%d\n", arr[i]);
  }

  return 0;
}
