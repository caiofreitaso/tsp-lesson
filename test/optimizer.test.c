#include "../include/optimizer.h"
#include <stdio.h>
#include <assert.h>

const int SIZE = 4;

int main() {
  OptimizerOutput a;
  OptimizerOutput_init(&a, SIZE);

  Matrix distance;
  Matrix_init(&distance, SIZE);
  distance[0][0] = distance[1][1] = distance[2][2] = distance[3][3];
  distance[0][1] = distance[1][0] = 1;
  distance[0][2] = distance[2][0] = 2;
  distance[0][3] = distance[3][0] = 4;
  distance[1][2] = distance[2][1] = 8;
  distance[1][3] = distance[3][1] = 16;
  distance[2][3] = distance[3][2] = 32;

  OptimizerOutput b;
  OptimizerOutput_init(&b, SIZE);
  int i, valid;

  printf("Update Best\n");
  a.value = 45;
  for (i = 0; i < SIZE; i++) a.path[i] = i;
  b.path[0] = 0; b.path[1] = 2; b.path[2] = 1; b.path[3] = 3;
  update_best(&a, b, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a.path[i] == b.path[i];
  assert(valid == 1);
  printf("  Changed to the best (with value) OK\n");

  a.value = 0;
  for (i = 0; i < SIZE; i++) a.path[i] = 0;
  b.path[0] = 0; b.path[1] = 2; b.path[2] = 1; b.path[3] = 3;
  update_best(&a, b, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a.path[i] == b.path[i];
  assert(valid == 1);
  printf("  Changed to the best (no value) OK\n");

  for (i = 0; i < SIZE; i++) a.path[i] = i;
  Solution previous;
  Solution_copy(&previous, a.path, SIZE);
  a.value = 10;
  update_best(&b, a, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a.path[i] == previous[i];
  assert(valid == 1);
  printf("  Did not change to the worst OK\n");

 return 0;
}
