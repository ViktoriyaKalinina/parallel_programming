#include <omp.h>
#include <string.h>
#include <stdio.h>

#define A 10
#define B 20

int main () {
    int a[B];
  for ( int i = 0; i < B ; i++) {
        a[i] = 0;
  }
  int i;
  #pragma omp parallel for private(i) shared(a)
    for ( i = A; i <=  B; i++) {
    int isPrime = 1;
    #pragma omp parallel for num_threads(3) shared(isPrime)
      for ( int j = 2; j <= i/2; j++) {
        if (i % j == 0 ) {
          isPrime = 0;
        }
      }
      if (isPrime == 1 ) {
       a[i] = i;
      }
    }
    for (int i = 0; i < B; i++) {
        printf(" %d \n", a[i]);
    }
}
