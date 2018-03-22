#include <omp.h>
#include <math.h>
#include <stdio.h>

#define N 30

int main () {
  int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
  int x = 0;
  int i;

#pragma omp parallel for num_threads(3) shared(a) private(i) reduction(+:x)
  for (i = 0; i < N; i++) {
      x = x + a[i]*(pow (2, i));
    printf(" %d \n", a[i]);
  }
  printf("Number is %d\n", x);
}
