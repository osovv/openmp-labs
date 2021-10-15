#include <omp.h>
#include <iostream>
#include <iomanip>
#include <string>

int **init(int m, int n)
{
  int **matr = new int *[m];
  for (int i = 0; i < m; i++)
  {
    matr[i] = new int[n];
  }
  return matr;
}

void clear(int **matr, int m)
{
  for (int i = 0; i < m; i++)
    delete[] matr[i];
  delete[] matr;
}
void fill(int **matr, int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matr[i][j] = rand() % 100;
    }
  }
}

void print(int **matrix, int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << std::setw(3) << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int count_sevens(int number)
{
  int count = 0, digit;
  while (number)
  {
    digit = number % 10;
    if (digit == 7)
    {
      count += 1;
    }
    number /= 10;
  }
  return count;
}

int func(int **matrix, int m, int n, int threads_num, bool needPrint = false)
{
  int total = 0, sevens_number;
  double start_time = 0, end_time = 0;
  int *arr = new int[m];
  start_time = omp_get_wtime();
#pragma omp parallel shared(matrix, m, n, total, arr) num_threads(threads_num)
  {
#pragma omp for private(sevens_number)
    for (int i = 0; i < m; i++)
    {
      sevens_number = 0;
      for (int j = 0; j < n; j++)
      {
        for (int k = 0; k < n; k++)
        {
          sevens_number += count_sevens(matrix[i][j] + matrix[i][k]);
        }
      }
      total += sevens_number;
      arr[i] = sevens_number;
    }
  }
  end_time = omp_get_wtime();
  printf("M: %2d; N: %2d; Threads: %2d, Total: %8d; Elapsed time (ms): %.2f\n", m, n, threads_num, total, (end_time - start_time) * 1000);
  if (needPrint)
  {

    for (int i = 0; i < m; i++)
    {
      printf("Row: %2d Sevens count: %2d\n", i, arr[i]);
    }
  }

  delete arr;
  return total;
}

int main(int argc, char **argv)
{
  int M, N;

  srand(time(NULL));
  if (argc != 3)
  {
    printf("You must give two command line arguments (M first, N second) (eg: ./bin/main 100 100)\n");
    return -1;
  }
  M = std::stoi(argv[1]);
  N = std::stoi(argv[2]);

  int **matr = init(M, N);
  fill(matr, M, N);

  func(matr, M, N, 1);
  func(matr, M, N, 8);
  return 0;
}
