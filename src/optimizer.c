#include "../include/optimizer.h"

void OptimizerOutput_init(OptimizerOutput* this, int size) {
  this->clocks_used = clock();
  this->best_value = 0;
  Solution_init(&this->best, size);
}

void OptimizerOutput_finish(OptimizerOutput* this) {
  this->clocks_used = clock() - this->clocks_used;
  this->seconds = ((float)this->clocks_used)/CLOCKS_PER_SEC;
}

void update_best(OptimizerOutput* this, Solution target, Matrix distance, int size) {
  int target_value = objective_function(distance, target, size);

  if (this->best_value == 0 || target_value < this->best_value) {
    free(this->best);
    Solution_copy(&this->best, target, size);
    this->best_value = target_value;
  }
}

OptimizerOutput optimizer(Matrix distance, int size, optimizer_method method) {
  OptimizerOutput result;
  OptimizerOutput_init(&result, size);

  {
    Solution current;
    Solution_init(&current, size);

    method(&result, &current, distance, size, 0);

    free(current);
  }

  OptimizerOutput_finish(&result);
  return result;
}

