#include <omp.h>
#include<stdio.h>
#include <time.h>

#define M 10
#define N 5

int main (int argc, char *argv[]) {
float A[M][N], b[M], c[M];
int i, j, rank;
int total;
clock_t start, end;
start = clock();

for (i=0; i < M; i++) {
  for (j=0; j < N; j++)
    A[i][j] = (j+1) * 1.0;
  b[i] = 1.0 * (i+1);
  c[i] = 0.0;
 }

printf("Значения матрицы A и вектора b: \n");

for (i=0; i < M; i++){
  printf("  A[%d]= ",i);
  for (j=0; j < N; j++)
    printf("%.1f ",A[i][j]);
  printf("  b[%d]= %.1f\n",i,b[i]);
  }
end = clock();
printf("%.10lf\n", ( end - start) );

start = clock();
#pragma omp parallel shared(A,b,c,total) private(rank,i)
  {
  rank = omp_get_thread_num();

#pragma omp for private(j)
  for (i=0; i < M; i++)
    {
    for (j=0; j < N; j++)
      c[i] += (A[i][j] * b[j]);

    #pragma omp critical
      {
      printf("Thread = %d Cycle number i = %d Vector c[%f]\n", rank,i,c[i]);
      }
    }
  }
  end = clock();
  printf("%.10lf\n", (end - start));
}
