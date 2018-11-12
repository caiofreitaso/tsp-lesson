#ifndef __OPTIMIZER_H__
#define __OPTIMIZER_H__

#include "objective-function.h"
#include "validate.h"
#include <time.h>

typedef struct {
  Solution path;
  int value;
  clock_t clocks_used;
  float seconds;
} OptimizerOutput;
typedef void (*optimizer_method)(OptimizerOutput*, OptimizerOutput*, Matrix, int, int);

void OptimizerOutput_init(OptimizerOutput* this, int size);

void update_best(OptimizerOutput* this, OptimizerOutput target, Matrix distance, int size);
OptimizerOutput optimizer(Matrix distance, int size, optimizer_method method);

#endif
