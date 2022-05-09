#include <stdio.h>
#include <stdlib.h>

int func1(long int arg) {
  long int a = 0, b = 0;  
  while(b< arg) {
    a += 3;
    b++;
  }

  return a;
}

int main(int argc, char *argv[]) {
  long int input = atoi(argv[1]);
  long int ret = func1(input);

  printf("Result: %ld\n", ret);

  return 0;
}
