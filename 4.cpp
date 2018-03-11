#include <omp.h>
#include <iostream>
#include <stdio.h>

int main(void) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, -4, 9, 2};
	int b[10] = {10, 9, 8, 7, 6, 5, 48, 3, 2, 1};

    int max = 0;
	int min = 0;
	
    #pragma omp parallel sections num_threads(2)
	{
		#pragma omp section
		{
			for (int i = 0; i < 10; i++) {
				if (min > a[i]) { min = a[i]; }
			}
		}
		
        #pragma omp section
		{
			for (int i = 0; i < 10; i++) {
				if (max < b[i]) { max = b[i]; }
			}
		}
    }
    
    printf("max: %d, min: %d\n", max, min);
}
