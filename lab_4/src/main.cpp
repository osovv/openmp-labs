#include <iostream>
#include <omp.h>

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

#pragma omp parallel shared(A, B, N, product) if (needParallel)
  {
#pragma omp for
    for (int i = 0; i < N; i++)
    {
      int sum = A[i] + B[i];
      if (sum != 0)
      {
#pragma omp critical
        product *= sum;
      }
    }
  }
  end_time = omp_get_wtime();
  printf("N: %2d; Paralled: %d; Product: %8d; Elapsed time (ms): %.4f\n", N, needParallel, product, (end_time - start_time) * 1000);
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
  clear(a);
  clear(b);
  return 0;
}
