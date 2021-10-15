#include <omp.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "fort.hpp"

float **init(int n)
{
  float **matr = new float *[n];
  for (int i = 0; i < n; i++)
  {
    matr[i] = new float[n];
  }
  return matr;
}

void clear(float **matr, int n)
{
  for (int i = 0; i < n; i++)
  {
    delete[] matr[i];
  }
  delete[] matr;
}

void fill(float **matr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matr[i][j] = i + j;
    }
  }
}

double func(float **matr, int NMAX, int LIMIT)
{
  int i, j;
  float sum;
  double start_time, end_time;
  start_time = omp_get_wtime();
#pragma omp parallel shared(matr) if (NMAX > LIMIT)
  {
#pragma omp for private(i, j, sum)
    for (i = 0; i < NMAX; i++)
    {
      sum = 0;
      for (j = 0; j < NMAX; j++)
        sum += matr[i][j];
    }
  }
  end_time = omp_get_wtime();
  return (end_time - start_time) * 1000;
}

void funcWrapper(int NSTART, int NMAX, int NSTEP)
{
  std::cout << "Elapsed time (ms)" << std::endl;
  fort::char_table table;
  table << std::fixed << std::setprecision(4);
  table << fort::header << "N \\ N > LIMIT"
        << "false"
        << "true";
  table << fort::endr;

  for (int n = NSTART; n <= NMAX; n += NSTEP)
  {
    float **matr = init(n);
    fill(matr, n);
    double t1 = func(matr, n, n + 1); //  n < limit
    double t2 = func(matr, n, n - 1); // n > limit
    table << n << t1 << t2 << fort::endr;
  }
  std::cout << table.to_string() << std::endl;
}

int main(int argc, char **argv)
{
  funcWrapper(1000, 10000, 1000);
  return 0;
}
