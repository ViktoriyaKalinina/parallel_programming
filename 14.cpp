#include <omp.h>
#include <stdio.h>

#define N 210

int main () {
    int sum = 0;
    int i;

    #pragma omp parallel for num_threads(3) private(i) reduction(+:sum)
    for ( i = 1; i <= 2*N; i++) {
        if (i % 2 != 0 ) {
            sum = sum + i;
        }
    }
    printf("max is %d\n", sum);
}
