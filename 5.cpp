#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 30

int main() {

    int d[6][8];
    for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			d[i][j] = rand() % N;
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

    #pragma omp parallel sections
	{
        #pragma omp section
		{
			int elements = 0;
			int sum = 0;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					sum += d[i][j];
					elements++;
				}
			}
			printf("average is %.2f from %d thread\n", sum * 1.0 / elements, omp_get_thread_num());
		}
    
    #pragma omp section
		{
			int max = N + 1;
			int min = -1;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					if (min > d[i][j]) {
						min = d[i][j];
					}
					if (max < d[i][j]) {
						max = d[i][j];
					}
				}
			}
			printf("max: %d and min: %d from %d thread\n", max, min, omp_get_thread_num());
		}
    }
}