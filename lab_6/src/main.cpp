#include <iostream>
#include <omp.h>
#include <cstring>

int *init(int n)
{
  int *arr = new int[n];
  return arr;
}

void clear(int *arr)
{
  delete[] arr;
}

void fill(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 10;
  }
}

void func(int *A, int *B, int N, bool needParallel = true)
{
  double start_time, end_time;
  unsigned long long int product = 1;
  start_time = omp_get_wtime();

#pragma omp parallel shared(A, B, N) if (needParallel)
  {
#pragma omp for reduction(* \
                          : product)
    for (int i = 0; i < N; i++)
    {
      int sum = A[i] + B[i];
      if (sum != 0)
      {
        product *= sum;
      }
    }
  }
  end_time = omp_get_wtime();
  printf("N: %2d; Paralled: %d; Product: %8d; Elapsed time (ms): %.4f\n", N, needParallel, product, (end_time - start_time) * 1000);
}

void funcLock(int *A, int *B, int N, bool needParallel = true)
{
  double start_time, end_time;
  unsigned long long int product = 1;
  omp_lock_t lock;
  omp_init_lock(&lock);
  start_time = omp_get_wtime();
#pragma omp parallel shared(A, B, N) if (needParallel)
  {
#pragma omp for
    for (int i = 0; i < N; i++)
    {

      int sum = A[i] + B[i];
      if (sum != 0)
      {
        omp_set_lock(&lock);
        product *= sum;
        omp_unset_lock(&lock);
      }
    }
  }
  end_time = omp_get_wtime();
  omp_destroy_lock(&lock);
  printf("With lock; N: %2d; Paralled: %d; Product: %8d; Elapsed time (ms): %.4f\n", N, needParallel, product, (end_time - start_time) * 1000);
}

void funcBarrier(int *A, int *B, int N, bool needParallel = true)
{
  double start_time, end_time;
  unsigned long long int product = 1;
  start_time = omp_get_wtime();

  int max_threads = omp_get_max_threads();
  int *a = new int[max_threads];
  for (int i = 0; i < max_threads; i++)
  {
    a[i] = 1;
  }

  int idx;

#pragma omp parallel shared(A, B, N) if (needParallel)
  {
#pragma omp for private(idx)
    for (int i = 0; i < N; i++)
    {
      idx = omp_get_thread_num();
      int sum = A[i] + B[i];
      if (sum != 0)
      {
        a[idx] *= sum;
      }
    }
#pragma omp single nowait
    for (int i = 0; i < max_threads; i++)
    {
      product *= a[i];
    }
  }
  end_time = omp_get_wtime();
  printf("With barrier; N: %2d; Paralled: %d; Product: %8d; Elapsed time (ms): %.4f\n", N, needParallel, product, (end_time - start_time) * 1000);
}

int main(int argc, char **argv)
{
  srand(time(NULL));
  int N;
  if (argc != 2)
  {
    printf("You must give one command line arguments (N) (eg: ./bin/main 100)\n");
    return -1;
  }
  N = std::stoi(argv[1]);

  int *a, *b;
  a = init(N);
  fill(a, N);
  b = init(N);
  fill(b, N);
  func(a, b, N);
  func(a, b, N, false);
  funcLock(a, b, N);
  funcLock(a, b, N, false);
  funcBarrier(a, b, N);
  funcBarrier(a, b, N, false);
  clear(a);
  clear(b);
  return 0;
}
