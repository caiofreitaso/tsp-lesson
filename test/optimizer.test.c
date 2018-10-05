#include "../include/optimizer.h"
#include <stdio.h>
#include <assert.h>

const int SIZE = 4;

int main() {
  Solution a;
  Solution_init(&a, SIZE);

  printf("Base Construction\n");
  base_construction(&a, SIZE, 0);
  int i, valid = 1;
  for (i = 0; i < SIZE; i++)
    if (a[i] != 0) {
      valid = 0;
      break;
    }
  assert(valid == 1);
  printf("  0 OK\n");

  base_construction(&a, SIZE, pow(SIZE,SIZE)-1);
  valid = 1;
  for (i = 0; i < SIZE; i++)
    if (a[i] != SIZE-1) {
      valid = 0;
      break;
    }
  assert(valid == 1);
  printf("  Max number OK\n");

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

  for (i = 0; i < SIZE; i++) a[i] = i;
  b[0] = 0; b[1] = 2; b[2] = 1; b[3] = 3;

  printf("Update Best\n");
  update_best(&a, b, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a[i] == b[i];
  assert(valid == 1);
  printf("  Changed to the best OK\n");

  for (i = 0; i < SIZE; i++) a[i] = i;
  Solution previous;
  Solution_copy(&previous, a, SIZE);
  update_best(&b, a, distance, SIZE);
  valid = 1;
  for (i = 0; i < SIZE; i++) valid &= a[i] == previous[i];
  assert(valid == 1);
  printf("  Did not change to the worst OK\n");

 return 0;
}
