#include <omp.h>
#include <iostream>
#include <stdio.h>

int main(void) {
	int a = 1, b = 1;
	printf("before parallel a = %d b = %d\n", a, b);

	#pragma omp parallel
	{	
		#pragma omp parallel num_threads(2) private(a) firstprivate(b)
		a = 0;
		a += omp_get_thread_num();
		b += omp_get_thread_num();
		
		printf ("Number of threads one - %d , in the first area: a = %d , b = %d  \n", omp_get_thread_num(), a, b);
  		
		#pragma omp parallel num_threads(4) shared(a) private(b)
		b = 0;
		#pragma omp atomic
		a -= omp_get_thread_num();
		b -= omp_get_thread_num();
    	printf ("Number of threads one - %d , in the first area: a = %d , b = %d  \n", omp_get_thread_num(), a, b);
	}
	
	printf("after parallel a = %d b = %d\n", a, b);
}
