//Написать программу, в которой определить две параллельные области, выполнение которых
//зависит от условного оператора #pragma omp parallel if(...), если заданное значение числа
//нитей больше 1, параллельная область выполняется, иначе не выполняется. Число нитей
//перед первой областью задать равным 3, перед второй – равным 1. Внутри параллельных
//областей определить количество нитей и номер каждой нити, результат выдать на экран.
//Убедиться в правильности работы программы.
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