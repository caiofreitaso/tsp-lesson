#include "../include/tsp.h"
#include <stdio.h>
#include <assert.h>

const int SIZE = 10;

int main() {
  Solution a,b;
  Matrix distances;

  Solution_init(&a, SIZE);
  printf("Solution initialized\n");

  int i;
  for (i = 0; i < SIZE; i++) a[i] = 2;
  printf("Solution assigned\n");

  Solution_copy(&b, a, SIZE);
  printf("Solution copied\n");

  int all = 1;
  for (i = 0; i < SIZE; i++)
    if (b[i] != 2) {
      all = 0;
      break;
    }
  assert(all == 1);
  printf("Copy verified\n");

  Matrix_init(&distances, SIZE);
  printf("Matrix initialized\n");

  int j;
  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
      distances[i][j] = 2;
  printf("Matrix assigned\n");

  return 0;
}
