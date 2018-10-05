#ifndef __OPTIMIZER_H__
#define __OPTIMIZER_H__

#include "objective-function.h"
#include "validate.h"
#include <math.h>

void update_best(Solution* this, Solution target, Matrix distance, int size) {
  int current_value = objective_function(distance, *this, size);
  int target_value = objective_function(distance, target, size);

  if (target_value < current_value) {
    free(*this);
    Solution_copy(this, target, size);
  }
}

// The array for this problem has N elements.
// Each of those elements has a value in the range { 0, N - 1 }.
// This can be seen as a number in base N.
// e.g.
//   A 10-element array could be any number from
//   0 to 9,999,999,999.

void base_construction(Solution* this, int size, int current) {
  int i;
  for (i = 0; i < size; i++) {
    (*this)[i] = current % size;
    current /= size;
  }
}

Solution optimizer(Matrix distance, int size) {
  Solution current, best;

  Solution_init(&current, size);
  Solution_init(&best, size);

  int i, max_number = pow(size, size);
  for (i = 0; i < max_number; i++) {
    base_construction(&current, size, i);
    if (is_cycle(current, size) && only_valid_elements(current, size)) {
      update_best(&best, current, distance, size);
    }
  }

  return best;
}

#endif
