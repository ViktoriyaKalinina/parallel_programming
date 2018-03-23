#include <omp.h>
#include<stdio.h>
#include <time.h>

#define R 30

int main (int argc, char *argv[]) {

  int n = 6;
  int m = 8;

  int d[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = rand() % R;
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");

  int max = 0;
  int min = 0;

  int count = 0;
#pragma omp parallel num_threads(3) reduction (+: count)
  for (int i = 0; i < n; i++) {
#pragma omp for
    for (int j = 0; j < m; j++) {
      count++;

  #pragma omp critical
      if (min > d[i][j])
        min = d[i][j];
  #pragma omp critical
      if (max < d[i][j])
        max = d[i][j];
    }
  }
  printf("count: %d, max value is %d, min value is %d\n", count, max, min);  
}
