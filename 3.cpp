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
		a -= omp_get_thread_num();
		b -= omp_get_thread_num();
    	printf ("Number of threads one - %d , in the first area: a = %d , b = %d  \n", omp_get_thread_num(), a, b);
	}
}

// 3. Написать программу, в которой 
// объявить и присвоить начальные значения целочисленным переменным: a и b,

// определить две параллельные области, первая – с числом нитей 2, вторая – с числом нитей 4. 

// Для первой области переменные a и b объявить защищенными, с режимом доступа private и firstprivate 
// соответственно, внутри области определить номер нити 
// и выполнить увеличение значения переменных на эту величину. 
// Выдать на экран значения переменных до входа в параллельную область, 
// внутри параллельной области и после выхода из параллельной области. 
// Для второй области переменную a объявить общей, переменную b объявить защищенной, 
// с режимом доступа private, определить номер нити и выполнить уменьшение значения переменных 
// на эту величину. 
// Выдать на экран значения переменных до входа в параллельную область, внутри параллельной области и
// после выхода из параллельной области.
