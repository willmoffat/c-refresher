#include <stdio.h>
#include <dlfcn.h>   // For dlopen(), dlclose(), dlsym()
#include <unistd.h>  // For sleep()
#include "func.h"

int run_test_func() {
  void *lib_handle;
  int (*test_func)(int);
  char *error;

  lib_handle = dlopen("./libfunc.so", RTLD_LAZY);
  if (!lib_handle) {
    fprintf(stderr, "%s\n", dlerror());
    return(1);
  }

  test_func = dlsym(lib_handle, "test_func");
  error = dlerror();
  if (error) {
    fprintf(stderr, "%s\n", error);
    return(1);
  }

  int y = (*test_func)(3);
  printf("Result of test_func = %d\n", y);
  
  dlclose(lib_handle);
  return(0);
}

int main(void) {
  while (1) {
    if (run_test_func() != 0) {
      return(1);
    }
    sleep(1);
  }
  return(0);
}
