//Hermmy Wang
//704978214

//Homework#3
#include <stdio.h>
#define D 10
void transpose(int *dst, int* src, int dim)
{
    int i, j, bi, bj;
    int block = /* block size */ 16;
#pragma omp parallel for num_threads(20) firstprivate(block, dim) private(j, bi, bj)
    for (i = 0; i < dim; i+=block)
        for (j = 0; j < dim; j+=block)
            for (bi = i; bi < i + block && bi < dim; bi++)
                for (bj = j; bj < j + block && bj < dim; bj++)
                    dst[bi*dim + bj] = src[bj*dim + bi];
}

int main()
{
  int a[D*D];
  int b[D*D];
  int i, j;
  for (i = 0; i < D; i++){
    for (j = 0; j < D; j++){
      a[i*D+j] = i*D+j + 100;
    }
  }
  transpose(b, a, D);
  for (i = 0; i < D*D; i++){
    printf("%d  ", b[i]);
  }
}

