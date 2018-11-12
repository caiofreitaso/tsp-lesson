#ifndef __OPTIMIZER_H__
#define __OPTIMIZER_H__

#include "objective-function.h"
#include "validate.h"
#include <time.h>

typedef struct {
  Solution best;
  int best_value;
  clock_t clocks_used;
  float seconds;
} OptimizerOutput;

typedef void (*optimizer_method)(OptimizerOutput*, Solution*, Matrix, int, int);

void update_best(OptimizerOutput* this, Solution target, Matrix distance, int size);
OptimizerOutput optimizer(Matrix distance, int size, optimizer_method method);

#endif
