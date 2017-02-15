#include <stdio.h>
#include <ctype.h>
#include <math.h>

void upperCase(char *pt, int length) {
  int i;
  for (i = 0; i < length; i++) {
    pt[i] = toupper(pt[i]);
  }
  return;
}

int char2int(char c) {
  int res = 0;
  switch(c) {
    case 'A':
      res = 10;
      break;
    case 'B':
      res = 11;
      break;
    case 'C':
      res = 12;
      break;
    case 'D':
      res = 13;
      break;
    case 'E':
      res = 14;
      break;
    case 'F':
      res = 15;
      break;
    default:
      res = 0;
  }
  
  return res;
}

long h2i(char *pt, int length) {
  long res = 0;
  
  // check 0x or 0X
  // check validation

  // do the math
  int i;
  for (i = 0; i < length; i++) {
    if (pt[i] >= '0' && pt[i] <= '9') {
      long base = pow(16, length - i - 1);
      res = res + ((pt[i] - '0') * base);
    } else {
      long base = pow(16, length - i - 1);
      res = res + char2int(pt[i]) * base;
    }
  }
  return res;
}

int main(void) {
  char hexArr[] = "100";
   
  upperCase(hexArr, 3);  
  printf("%s\n", hexArr); 
  
  printf("%ld\n", h2i(hexArr, 3));
 
  return 0;
}
