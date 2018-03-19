#include <omp.h>
#include<stdio.h>

#define M 10

int main () {
float A[M][M], b[M], c[M];
int i, j, rank;
int total;

for (i=0; i < M; i++) {
  for (j=0; j < M; j++)
    A[i][j] = (j+1) * 1.0;
  b[i] = 1.0 * (i+1);
  c[i] = 0.0;
 }

printf("Вывод значений матрицы A и вектора b на экран: \n");

for (i=0; i < M; i++){
  printf("  A[%d]= ",i);
  for (j=0; j < M; j++)
    printf("%.1f ",A[i][j]);
  printf("  b[%d]= %.1f\n",i,b[i]);
  }

#pragma omp parallel shared(A,b,c,total) private(rank,i)
  {
  rank = omp_get_thread_num();

#pragma omp for private(j)
  for (i=0; i < M; i++)
    {
    for (j=0; j < M; j++)
      c[i] += (A[i][j] * b[j]);

    #pragma omp critical
      {
      printf(" rank= %d i= %d c[%f]\n", rank,i,c[i]);
      }
    }
  }
}
