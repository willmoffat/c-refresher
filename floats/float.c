#include <stdio.h>
#include <stdint.h>

// assumes little endian
void print_value(void *ptr, size_t size) {
  unsigned char *b = (unsigned char *)ptr;
  unsigned char byte;
  int i, j;
  /*
  for (i = size - 1; i >= 0; i--) {
    byte = b[i];
    printf("   %x", byte >> 4);
    printf("    %x ", byte & 0xf);
  }
  puts("");
  */
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
  putchar('\n');
}

// Print a float.
void p(float *ptr) {
  if (*ptr == 0) {
    putchar('\n');
  } else {
    printf("float=%10f  ", *ptr);
    print_value(ptr, sizeof(*ptr));
  }
}

#define ArrayCount(array) (sizeof(array)/sizeof(array[0]))

int main() {
  printf("sizeof(float)=%d\n", (int)sizeof(float));

  float a[] = {1.0f, -1.0f, 0, 0.5f, -0.5f, 0, 1,2,3,0};
  int i;
  for (i=0; i<ArrayCount(a); i++) {
    p(a+i);
  }

  return 0;
}
