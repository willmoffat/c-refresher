// Load file per character
uint8_t *m = (uint8_t *)mem;
int c;
while ((c = fgetc(f)) != EOF) {
  *m++ = c;
}

// Unprotect section.
printf("Info: mmap\n");
{
  void *mem;
  mem = mmap(ADDR, LEN, PROT_READ | PROT_WRITE | PROT_EXEC,
             MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
  if (mem == MAP_FAILED) {
    perror("mmap failed");
    return -1;
  }
  // dump(ADDR, 0x10); // All zeros as expected.
}

void dump(uint8_t *p, size_t len) {
  int i;
  printf("Address: %p = ", p);
  for (i = 0; i < len; i++) {
    printf("%02X ", *p);
    p++;
  }
  printf("\n\n");
}
