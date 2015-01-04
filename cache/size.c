#include <stdio.h>

int main() {
  printf("sizeof char %d\n",  (int)sizeof(char));  // 1 byte  = 8 bits
  printf("sizeof short %d\n", (int)sizeof(short)); // 2 bytes = 16 bits
  printf("sizeof int %d\n",   (int)sizeof(int));   // 4 bytes = 32 bits
  printf("sizeof long %d\n",  (int)sizeof(long));  // 8 bytes = 64 bits
  printf("sizeof long long %d\n",  (int)sizeof(long long));  // 8 bytes = 64 bits
  return(0);
}
