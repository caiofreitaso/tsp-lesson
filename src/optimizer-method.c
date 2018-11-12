#include "../include/optimizer-method.h"

int is_valid(Solution this, int size) {
  return is_cycle(this,size) && only_valid_elements(this,size);
}

void branch(OptimizerOutput* best, Solution* current, Matrix distance, int size, int i) {
  int j;
  for (j = 0; j < size; j++) {
    (*current)[i] = j;
    recursive(best, current, distance, size, i+1);
  }
}

void leaf(OptimizerOutput* best, Solution* current, Matrix distance, int size) {
  if (is_valid(*current, size)) {
    update_best(best, *current, distance, size);
  }
}

void recursive(OptimizerOutput* best, Solution* current, Matrix distance, int size, int i) {
  if (i < size - 1) {
    branch(best, current, distance, size, i);
  } else {
    leaf(best, current, distance, size);
  }
}
