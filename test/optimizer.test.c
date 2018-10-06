#include "../include/optimizer.h"
#include <stdio.h>
#include <assert.h>

const int SIZE = 4;

int main() {
  Solution a;
  Solution_init(&a, SIZE);

  Matrix distance;
  Matrix_init(&distance, SIZE);
  distance[0][0] = distance[1][1] = distance[2][2] = distance[3][3];
  distance[0][1] = distance[1][0] = 1;
  distance[0][2] = distance[2][0] = 2;
  distance[0][3] = distance[3][0] = 4;
  distance[1][2] = distance[2][1] = 8;
  distance[1][3] = distance[3][1] = 16;
  distance[2][3] = distance[3][2] = 32;

  Solution b;
  Solution_init(&b, SIZE);
  int value = 45;
  int i, valid;

  printf("Update Best\n");
  for (i = 0; i < SIZE; i++) a[i] = i;
  b[0] = 0; b[1] = 2; b[2] = 1; b[3] = 3;
  update_best(&a, &value, b, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a[i] == b[i];
  assert(valid == 1);
  printf("  Changed to the best (with value) OK\n");

  for (i = 0; i < SIZE; i++) a[i] = 0;
  b[0] = 0; b[1] = 2; b[2] = 1; b[3] = 3;
  value = 0;
  update_best(&a, &value, b, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a[i] == b[i];
  assert(valid == 1);
  printf("  Changed to the best (no value) OK\n");

  for (i = 0; i < SIZE; i++) a[i] = i;
  Solution previous;
  Solution_copy(&previous, a, SIZE);
  value = 10;
  update_best(&b, &value, a, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a[i] == previous[i];
  assert(valid == 1);
  printf("  Did not change to the worst OK\n");

 return 0;
}
