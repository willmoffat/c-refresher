#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

// TODO(wdm) Read about PLT.
// https://www.technovelty.org/linux/plt-and-got-the-key-to-code-sharing-and-dynamic-libraries.html

#define ADDR (void *)0x500000 // Defined in linkerscript.

// TODO(wdm) Signal handler to trap core dumps.

void loadFile(char *filename, void *addr) {
  printf("Info: Loading '%s' at mem location %p\n", filename, addr);
  FILE *f = fopen(filename, "rb");
  if (f == NULL) {
    fprintf(stderr, "Can't open file\n");
    exit(1);
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  printf("Info: Len 0x%lX\n", fsize);
  fread(addr, fsize, 1, f);
  fclose(f);
  printf("Info: Loaded\n");
}

void call(void (*p)()) {
  printf("Info: calling %p\n", p);
  printf("===\n");
  p();
  printf("===\n");
}

time_t mtime(char *filename) {
  struct stat sb;
  if (stat(filename, &sb) == -1) {
    perror("stat");
    exit(-1);
  }
  return sb.st_mtime;
}

void waitForModification(char *filename) {
  static time_t lastMod = 0;
  while (1) {
    time_t modified = mtime(filename);
    if (modified != lastMod) {
      lastMod = modified;
      putchar('\n');
      return;
    }
    fputc('.', stderr);
    sleep(1);
  }
}

int main() {
  char *swappableFile = "swappable.bin";

  printf("Info: Start\n");

  while (1) {
    waitForModification(swappableFile);
    loadFile(swappableFile, ADDR);
    call(ADDR);
  }

  return 0;
}
