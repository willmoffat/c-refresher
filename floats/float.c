#include <stdio.h>
#include <stdint.h>

// assumes little endian
void p(float *ptr) {
  unsigned char *b = (unsigned char *)ptr;
  unsigned char byte;
  int i, j;
  size_t size = 4;

  printf("\nfloat=%f\n", *ptr);
  for (i = size - 1; i >= 0; i--) {
    byte = b[i];
    printf("   %x", byte >> 4);
    printf("    %x ", byte & 0xf);
  }
  puts("");
  for (i = size - 1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      byte = b[i] & (1 << j);
      byte >>= j;
      printf("%d", byte);
      if (j == 4) {
        printf(" ");
      }
    }
    printf(" ");
  }
  puts("");
}

int main() {
  printf("sizeof(float)=%d\n", (int)sizeof(float));

  float a,b,c;
  a = 1.0f;
  b = 0.5f;
  c = 2.0f;

  p(&a);
  p(&b);
  p(&c);

  return 0;
}
