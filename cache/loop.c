// #include <time.h>
// #include <stdio.h>

#define SIZE (32*1024*1024)
#ifndef SKIP
#error "Must define SKIP"
#endif


// TODO(wdm): Why couldn't I put this inside the test function?
int array[SIZE];

void dotest() {
  int i;
  for (i=0; i<SIZE; i += SKIP) {
    array[i] *= 3;
  }
}

int main(void) {
  // clock_t t0, dt;
  // t0 = clock();
  dotest();
  // dt = clock() - t0;
  // int msec = dt * 1000 / CLOCKS_PER_SEC;
  // printf("\n\nTiming: %d ms\n", msec);
  return 0;
}
