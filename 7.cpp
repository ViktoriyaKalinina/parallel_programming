#include <omp.h>
#include <stdio.h>

#define N 12

int main() {
    int a[N], b[N], c[N];

    #pragma omp parallel num_threads(3)
        
    #pragma omp for schedule(static)
	for (int i = 0; i < N; i++) {
		a[i] = i + 4;
		b[i] = i + 3;
		printf("thread: %d, total: %d \n", omp_get_thread_num(), omp_get_num_threads());
	}

    for (int i = 0; i < N; i++) {
	    printf("%d ", a[i]);
	} printf("\n");

	for (int i = 0; i < N; i++) {
		printf("%d ", b[i]);
	} printf("\n");

	#pragma omp parallel num_threads(3)

	#pragma parallel omp for schedule(dynamic, 2)
		for (int i = 0; i < N; i++) {
		c[i] = a[i] + b[i];
        
		printf("thread: %d, total: %d \n", omp_get_thread_num(), omp_get_num_threads());
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", c[i]);
	}
}
