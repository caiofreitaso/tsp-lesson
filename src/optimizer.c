#include "../include/optimizer.h"

void OptimizerOutput_init(OptimizerOutput* this, int size) {
  this->clocks_used = clock();
  this->value = 0;
  Solution_init(&this->path, size);
}

void OptimizerOutput_finish(OptimizerOutput* this) {
  this->clocks_used = clock() - this->clocks_used;
  this->seconds = ((float)this->clocks_used)/CLOCKS_PER_SEC;
}

void update_best(OptimizerOutput* this, OptimizerOutput target, Matrix distance, int size) {
  target.value = objective_function(distance, target.path, size);

  if (this->value == 0 || target.value < this->value) {
    free(this->path);
    Solution_copy(&this->path, target.path, size);
    this->value = target.value;
  }
}

OptimizerOutput optimizer(Matrix distance, int size, optimizer_method method) {
  OptimizerOutput result;
  OptimizerOutput_init(&result, size);

  {
    OptimizerOutput current;
    OptimizerOutput_init(&current, size);

    method(&result, &current, distance, size, 0);

    free(current.path);
  }

  OptimizerOutput_finish(&result);
  return result;
}

