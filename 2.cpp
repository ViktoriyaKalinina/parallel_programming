#include <omp.h>
#include <stdio.h>


int main (){
{
	omp_set_dynamic(0);
	omp_set_num_threads(3);
	int thread_number;
  int threads;
#pragma omp parallel private(threads, thread_number)
	{
		threads = omp_get_num_threads();
		thread_number = omp_get_thread_num();
	#pragma omp parallel if (threads > 1)
		{
			printf("Number of Threads - %d\n", thread_number);
			printf("Thread - %d\n", threads);
		}
	}
	omp_set_num_threads(1);
#pragma omp parallel private(threads, thread_number)
	{
		int threads = omp_get_num_threads();
		int thread_number = omp_get_thread_num();
	#pragma omp parallel if (threads > 1)
		{
			printf("Number of Threads - %d\n", thread_number);
			printf("Thread - %d\n", threads);
		}
	}
  }
}
