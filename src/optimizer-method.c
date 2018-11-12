#include "../include/optimizer-method.h"

int is_valid(Solution this, int size) {
  return is_cycle(this, size) && only_valid_elements(this, size);
}

void branch(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size, int i) {
  int j;
  for (j = 0; j < size; j++) {
    current->path[i] = j;
    recursive(best, current, distance, size, i+1);
  }
}

void leaf(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size) {
  if (is_valid(current->path, size)) {
    update_best(best, *current, distance, size);
  }
}

void recursive(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size, int i) {
  if (i < size) {
    branch(best, current, distance, size, i);
  } else {
    leaf(best, current, distance, size);
  }
}
