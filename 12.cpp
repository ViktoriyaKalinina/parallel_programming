#include <omp.h>
#include <stdio.h>

#define N 30

int main (int argc, char *argv[]) {
  omp_set_num_threads(8);
  int f = 1;
  int thread_num;
  #pragma omp parallel private(f) shared(thread_num)
  {
    f = 1;
    thread_num = omp_get_num_threads();
    while(f == 1) {
      if (omp_get_thread_num() + 1 >= thread_num) {
     printf("Hello, I'm thread number %d\n", omp_get_thread_num());
        f = 0;
        thread_num--;
      }
    }
  }
  return 0;
}
