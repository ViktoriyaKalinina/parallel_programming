#include <omp.h>
#include <stdio.h>

#define N 30
#define D 7

int main () {
    int a[N];
    int max = 0;

#pragma omp parallel for num_threads(3) shared(max)
    for (int i = 0; i < N; i++) {
        a[i] = rand() % N;
        #pragma omp critical
          if (a[i] % D == 0 && max < a[i])
            max = a[i];
        printf(" %d \n", a[i]);
    }
    printf("max is %d\n", max);
}
