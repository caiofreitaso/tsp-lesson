#include "../include/tsp.h"

void Matrix_init(Matrix* this, int size) {
  int i;

  *this = (Matrix) malloc(size * sizeof(int*));

  for (i = 0; i < size; i++) {
    Solution_init(&(*this)[i], size);
  }
}

void Solution_init(Solution* this, int size) {
  *this = (Solution) calloc(size, sizeof(int));
}

void Solution_copy(Solution* this, Solution origin, int size) {
  Solution_init(this, size);
  memcpy(*this, origin, size * sizeof(int));
}
