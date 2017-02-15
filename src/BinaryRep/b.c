#include <stdio.h>
#include <math.h>
#include <string.h>

long decimalToBinary(long n, char *pt, int length) {
  int remainder;
  long binary = 0, i = 1, j = length - 1;

  while(n != 0) {
    remainder = n % 2;
    n = n/2;
    binary = binary + (remainder * i);
    // printf("%ld\n", binary);
    if (remainder == 0) {
      pt[j] = '0';
    } else {
      pt[j] = '1';
    }
    j--;
    i = i * 10;
  }

  return binary;
}

// long binaryToDecimal(long n) {
//   int remainder;
//   long decimal = 0, i=0;
//   while(n != 0) {
//       remainder = n%10;
//       n = n/10;
//       decimal = decimal + (remainder*pow(2,i));
//       ++i;
//   }
//   return decimal;
// }

void binaryToDecimal(char *pt, int length) {
  long decimal = 0;

  int i;
  for (i = 0; i < length; i++) {
    if (pt[i] == '0') {
      continue;
    } else {
      decimal = decimal + (1 * pow(2, length - i - 1));
    }
  }

  printf("%ld\n", decimal);
  return;
}

// 搜索001,替换为011
void searchAndReplace(char *pt, int length) {
  if (strstr(pt, "1")) {
    pt = strstr(pt, "1");
  } else {
    return;
  }

  while (1) {
    char *pm;
    pm = strstr(pt, "001");
    if (pm != NULL) {
      strncpy(pm, "011", 3);
      pt = pm;
    } else {
      break;
    }
  }
}

int replace(int num)
{
    unsigned int mode3bit = 7;
    unsigned int mode1bit = 1;
    int shift = 0;
    int result = 0;
    while (shift < 32)
    {
        while (shift < 32 && (num & (mode3bit<<shift)) != (1<<shift))
        {
            result += (num & (mode1bit<<shift));
            shift++;
        }
        if (shift >= 32)
        {
            break;
        }
        else if (32 - shift < 3)  //高位不足3位
        {
            result += (num & (mode3bit<<shift));
            break;
        }
        result += (3<<shift);
        shift += 3;

    }
    return result;
}

int main(void) {
  long decimal = 9;
  char pool[32] = "0000000000000000000000000000000";
  int i = 0;

  decimalToBinary(decimal, pool, 32);
  for (i = 0; i < 32; i++) {
    printf("%c", pool[i]);
  }
  printf("\n");

  // printf("%ld\n", sizeof(pool)); 32
  binaryToDecimal(pool, 32);
  searchAndReplace(pool, 32);
  for (i = 0; i < 32; i++) {
    printf("%c", pool[i]);
  }
  printf("\n");
  binaryToDecimal(pool, 32);

  printf("%d\n", replace(9));

  return 0;
}
