#include <omp.h>
#include <stdio.h>

int main() {

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    int b[10] = {1, 5, 5, 7, 2, 0, 3, 1, 3, 1};

    float sum_a = 0.0;
    float sum_b = 0.0; 

    float average_a = 0.0;
    float average_b = 0.0; 

	#pragma omp parallel for reduction(+: sum_a) reduction(+: sum_b)
	for (int i = 0; i < 10; i++) {
		sum_a += a[i];
		sum_b += b[i];
	}

    average_a = sum_a/10;
    average_b = sum_b/10;

    printf ("sum_a: %f, sum_b: %f \n", sum_a, sum_b);
    printf ("average a: %f, average b: %f \n", average_a, average_b);
}
