#include <omp.h>
#include <iostream>
#include <stdio.h>

int main (){
	int this_thread = omp_get_thread_num(), num_threads = omp_get_num_threads();
	#pragma omp parallel if(num_threads > 1)
	{	
		#pragma omp parallel num_threads(3)
			printf ("Number of threads - %d, Threads number - %d, Hello world!\n", omp_get_num_threads(), omp_get_thread_num());

  	#pragma omp parallel num_threads(1)
    	printf ("Number of threads - %d, Threads number - %d, Hello world!", omp_get_num_threads(), omp_get_thread_num());
	}
}