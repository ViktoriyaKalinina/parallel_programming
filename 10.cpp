#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 30
#define D 9

int main () {
    int a[N];
    int count = 0;

    #pragma omp parallel for shared(count)
    for (int i = 0; i < N; i++) {
        a[i] = rand() % N;
        if (a[i] % D == 0) {
            #pragma omp atomic
            count++;
        }
        printf(" %d \n", a[i]);
    }
    printf("count is %d\n", count);
}
