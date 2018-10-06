#ifndef __OPTIMIZER_METHOD_H__
#define __OPTIMIZER_METHOD_H__

#include "optimizer.h"

int is_valid(Solution this, int size) {
  return is_cycle(this,size) && only_valid_elements(this,size);
}

void recursive(Solution* best, int* best_value, Solution* current, Matrix distance, int size, int i) {
  if (i < size - 1) {
    int j;
    for (j = 0; j < size; j++) {
      (*current)[i] = j;
      recursive(best, best_value, current, distance, size, i+1);
    }
  } else {
    if (is_valid(*current, size)) {
      update_best(best, best_value, *current, distance, size);
    }
  }
}

#endif
