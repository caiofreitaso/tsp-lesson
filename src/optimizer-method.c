#include "../include/optimizer-method.h"

int is_valid(Solution this, int size) {
  return is_cycle(this,size) && only_valid_elements(this,size);
}

void branch(Solution* best, int* best_value, Solution* current, Matrix distance, int size, int i, int value) {
  (*current)[i] = value;
  recursive(best, best_value, current, distance, size, i+1);
}

void leaf(Solution* best, int* best_value, Solution* current, Matrix distance, int size) {
  if (is_valid(*current, size)) {
    update_best(best, best_value, *current, distance, size);
  }
}

void recursive(Solution* best, int* best_value, Solution* current, Matrix distance, int size, int i) {
  if (i < size - 1) {
    int j;
    for (j = 0; j < size; j++) {
      branch(best, best_value, current, distance, size, i, j);
    }
  } else {
    leaf(best, best_value, current, distance, size);
  }
}
