// Attempt to rewrite challS.s in C
#include <stdio.h>
#include <stdlib.h>

int func1(int w0, int w1) {
  if(w0 <= w1) {
    return w1;
  }
  else {
    return w0;
  }
}

int main(int argc, char *argv[]) {
  int arg1, arg2;
  arg1 = atoi(argv[1]);
  arg2 = atoi(argv[2]);
  int res = func1(arg1, arg2);
  printf("Result: %ld\n", res);
  return 0;
}
