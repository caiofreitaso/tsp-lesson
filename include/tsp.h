#ifndef __TSP_H__
#define __TSP_H__

#include <stdlib.h>
#include <string.h>

typedef int* Solution;
typedef int** Matrix;

void Matrix_init(Matrix* this, int size);
void Solution_init(Solution* this, int size);
void Solution_copy(Solution* this, Solution origin, int size);
void Solution_free(Solution this);
void Matrix_free(Matrix this, int size);

#endif
