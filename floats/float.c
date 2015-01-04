#include <stdio.h>
#include <stdint.h>


//assumes little endian
void p(float *ptr)
{
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;
  size_t size = 4;

  printf("\nfloat=%f\n",*ptr);
  for (i=size-1;i>=0;i--)
    {
      byte = b[i];
      printf("   %x", byte >> 4);
      printf("    %x ", byte & 0xf);
    }
  puts("");
  for (i=size-1;i>=0;i--)
    {
      for (j=7;j>=0;j--)
        {
	  byte = b[i] & (1<<j);
	  byte >>= j;
	  printf("%d", byte);
	  if (j==4) {printf(" "); }
        }
      printf(" ");
    }
  puts("");
}

int main() {
  printf("sizeof(float) %d\n", (int)sizeof(float));

  float f;

  f = 1; p(&f);
  f = 2; p(&f);
  f = 0.5; p(&f);
  //  f = 2; p(&f);
  // f = 4; p(&f);

  return 0;
}
