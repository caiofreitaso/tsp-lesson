#include "../include/objective-function.h"
#include <stdio.h>
#include <assert.h>

const int SIZE = 5;
Matrix distances;

int main() {
  Matrix_init(&distances, SIZE);

  //0 1 2 3 4
  //1 0 4 3 2
  //2 4 0 1 3
  //3 3 1 0 3
  //4 2 3 3 0

  distances[0][0] = 0; distances[1][0] = 1; distances[2][0] = 2; distances[3][0] = 3; distances[4][0] = 4;
  distances[0][1] = 1; distances[1][1] = 0; distances[2][1] = 4; distances[3][1] = 3; distances[4][1] = 2;
  distances[0][2] = 2; distances[1][2] = 4; distances[2][2] = 0; distances[3][2] = 1; distances[4][2] = 3;
  distances[0][3] = 3; distances[1][3] = 3; distances[2][3] = 1; distances[3][3] = 0; distances[4][3] = 3;
  distances[0][4] = 4; distances[1][4] = 2; distances[2][4] = 3; distances[3][4] = 3; distances[4][4] = 0;

  int presentation[] = { 0, 1, 4, 2, 3 };
  int value = objective_function(distances, presentation, SIZE);

  printf("%d\n",value);

  assert(value == 10);

  return 0;
}
