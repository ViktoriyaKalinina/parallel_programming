#include <omp.h>
#include <iostream>
#include <stdio.h>

int main(void) {
	const int a = 1;
	const int b = 1;
	
	#pragma omp parallel private(a)
		printf ("Thread number: %d   a: %d",omp_get_thread_num(), a);
	}
}