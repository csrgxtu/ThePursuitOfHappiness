#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

int isSwap(char *str, int start, int end) {
  for (; start < end; start++) {
    if (str[start] == str[end]) {
      return 1;
    }
  }
  return 0;
}

void allRange(char *str, int start, int length) {
  if (start == length - 1) {
    printf("%s\n", str);
  } else {
    int i;
    for (i = start; i <= length - 1; i++) {
      if (!isSwap(str, start, i)) {
        swap(&str[start], &str[i]);
        allRange(str, start + 1, length);
        swap(&str[start], &str[i]);
      }
    }
  }
}

void permutation(char *str) {
  if (str == NULL) {
    return;
  }
  allRange(str, 0, strlen(str));
}

int main() {
  char str[] = "abb";
  permutation(str);
  return 0;
}
