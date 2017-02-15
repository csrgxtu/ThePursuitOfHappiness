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
  int arr[5] = {1, 2, 3, 4, 5};
  int shift = 1;

  // reverse(arr, 0, 4);
  // reverse(A, A + N - k);
  // reverse(A + N - k, A + N);
  // reverse(A, A + N);
  reverse(arr, 0, 5 - shift - 1);
  reverse(arr, 5 - shift, 5 - 1);
  reverse(arr, 0, 5 - 1);

  int i;
  for (i = 0; i < 5; i++) {
    printf("%d\n", arr[i]);
  }

  return 0;
}
