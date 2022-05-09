#include <stdio.h>
#include <stdlib.h>

int func(int arg1) {
  int a=68, b=2, c=3;
  int d = a << b;
  d = d / c;
  return d - arg1;
}

int main(int argc, char* argv[]) {
  int in = atoi(argv[1]);
  printf("%d\n", func(in));
}
