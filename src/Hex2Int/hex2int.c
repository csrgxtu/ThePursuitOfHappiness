#include <stdio.h>
#include <ctype.h>

void upperCase(char *pt, int length) {
  int i;
  for (i = 0; i < length; i++) {
    pt[i] = toupper(pt[i]);
  }
  return;
}

int main(void) {
  char hexArr[] = "1a2";
   
  upperCase(hexArr, 3);  
  printf("%s\n", hexArr); 
    
  return 0;
}
